#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patricia.h"

void Pat_Initialize(PatNode_Pointer* tree){
	*tree = (PatNode_Pointer) malloc(sizeof(PatNode));
	(*tree)->nodetype = Internal;
	(*tree)->External_Node.Internal_Node.pos_differ_key = -1;
	(*tree)->External_Node.Internal_Node.left = NULL;
}

int Pat_NodeType(PatNode_Pointer tree){
	return (tree->nodetype == External);
}

void Pat_NewNode(PatNode_Pointer* tree, PatNode_Pointer* output_tree, String key, LL_Pointer* list, String internal_key, int* flag){
	int pos_differ_key = 0;
	PatNode_Pointer internal, external;

	*flag = 0;

	/*Finds the character in which the words differ*/
	while(key[pos_differ_key] == internal_key[pos_differ_key]) {
		pos_differ_key++;
	}

	/*Allocates space for the new nodes*/
	external = (PatNode_Pointer)malloc(sizeof(PatNode));
	internal = (PatNode_Pointer)malloc(sizeof(PatNode));

	/*New External node initialization*/
	external->nodetype = External;
	external->External_Node.data.key = (String)malloc( (strlen(key)+1)*sizeof(char) );
	strcpy(external->External_Node.data.key, key);
	(*tree)->External_Node.data.invertedindex = *list;

	/*New Internal node initialization*/
	internal->nodetype = Internal;
	internal->External_Node.Internal_Node.pos_differ_key = pos_differ_key+1;	//Adjust the differing index

	/*Puts the smallest of the compared chars(input and internal) in the internal node
	 * if the smallest character is taken from the internal key, the external key should be on the right
 	 * if the smallest character is taken from the input key, the external key should be on the left
	*/

 	if(key[pos_differ_key] < (*tree)->External_Node.data.key[pos_differ_key]) {
		internal->External_Node.Internal_Node.comparison_char = key[pos_differ_key];
		internal->External_Node.Internal_Node.left = external;
	}else{
		internal->External_Node.Internal_Node.comparison_char = (*tree)->External_Node.data.key[pos_differ_key];
		internal->External_Node.Internal_Node.right = external;

	}

	*output_tree = internal;
}

void Pat_IInsert(PatNode_Pointer* tree, PatNode_Pointer* output_tree, String key, LL_Pointer* list, int* sum, int* flag, int* overflow){
	/*First node initialization to the left of the first (NULL) node*/
	if(*tree == NULL){
		*flag = 1;
		*tree = (PatNode_Pointer) malloc(sizeof(PatNode));
		(*tree)->nodetype = External;
		(*tree)->External_Node.data.key = (String) malloc( (strlen(key)+1)*sizeof(char));
		strcpy((*tree)->External_Node.data.key, key);
		(*tree)->External_Node.data.invertedindex = *list;
		return;
	}

	/* If the node is external, compares the string to the input one.
	 * if they are the same returns. Else, calls the function Pat_NewNode
	 */
	if(Pat_NodeType(*tree)){
		if(!strcmp(key, (*tree)->External_Node.data.key)){
			*flag = 1;
		}else{
			Pat_NewNode(tree, output_tree, key, list, (*tree)->External_Node.data.key, flag);
		}
		return;
	}

	/* From this point forward, the node is known to be internal,
	 * therefore it should be decided which side(left or right)
	 * the input string should be redirected to.
	 */

	if((*tree)->External_Node.Internal_Node.pos_differ_key == -1){
		Pat_IInsert(&(*tree)->External_Node.Internal_Node.left, output_tree, key, list, sum, flag, overflow);

		if(*flag){
			return;
		}

		*flag = 1;

		if(key[(*output_tree)->External_Node.Internal_Node.pos_differ_key-1] > (*output_tree)->External_Node.Internal_Node.comparison_char) {
			(*output_tree)->External_Node.Internal_Node.left = (*tree)->External_Node.Internal_Node.left;
		}else {
			(*output_tree)->External_Node.Internal_Node.right = (*tree)->External_Node.Internal_Node.left;
		}

		if(Pat_NodeType((*tree)->External_Node.Internal_Node.left) == Internal){
			(*tree)->External_Node.Internal_Node.left->External_Node.Internal_Node.pos_differ_key -= (*output_tree)->External_Node.Internal_Node.pos_differ_key;
		}

		(*tree)->External_Node.Internal_Node.left = *output_tree;
		return;
	}

	*sum += (*tree)->External_Node.Internal_Node.pos_differ_key;

	/*Short word control*/
	if(*sum > strlen(key)){
		*overflow = 1;
	}

	/*IF the word is too short, walks on the trie until an external node is found, after that,
	 * it is compared to the input string and it returns with a new internal node containing
	 * the differing position and the smallest differing character.
	 */
	if(*overflow){
		Pat_IInsert(&(*tree)->External_Node.Internal_Node.left, output_tree, key, list, sum, flag, overflow);
		if(*sum < (*output_tree)->External_Node.Internal_Node.pos_differ_key && *flag == 0){
			*flag = 1;

			if(key[(*output_tree)->External_Node.Internal_Node.pos_differ_key-1] > (*output_tree)->External_Node.Internal_Node.comparison_char) {
				(*output_tree)->External_Node.Internal_Node.left = (*tree)->External_Node.Internal_Node.left;
			}else {
				(*output_tree)->External_Node.Internal_Node.right = (*tree)->External_Node.Internal_Node.left;
			}

			(*output_tree)->External_Node.Internal_Node.pos_differ_key -= *sum;
			if(Pat_NodeType((*tree)->External_Node.Internal_Node.left) == Internal){
				(*tree)->External_Node.Internal_Node.left->External_Node.Internal_Node.pos_differ_key -= (*output_tree)->External_Node.Internal_Node.pos_differ_key;
			}
			(*tree)->External_Node.Internal_Node.left = *output_tree;
		}else{
			*sum -= (*tree)->External_Node.Internal_Node.pos_differ_key;

		}
		/* ELSE the word is compared to the trie's node, if the key is bigger than the node,
		 * it goes to the right, otherwise, it goes to the left
		 */
	}else{
		if(key[*sum-1] > (*tree)->External_Node.Internal_Node.comparison_char){
			Pat_IInsert(&(*tree)->External_Node.Internal_Node.right, output_tree, key, list, sum, flag, overflow);

			if(*flag){
				return;
			}

			/* if the current char of the internal node is in a position of higher index, the function should
			 * go back one recursion level.
			 * Sum goes back to its original value in the previous node, this is done by removing the current
			 * internal node comparison index from the sum, which was previously added to it.
			 */
			if(*sum > (*output_tree)->External_Node.Internal_Node.pos_differ_key){
				*sum -= (*tree)->External_Node.Internal_Node.pos_differ_key;
				return;
			}

			/*Insertion point*/

			*flag = 1;

			/* Compares the input char's character in the position which it has differed with
			 * the comparison string.
			 * If the key character has a higher value, it means that the internal char is
			 * from the comparison word, which should be on the left.
			 */
			if(key[(*output_tree)->External_Node.Internal_Node.pos_differ_key-1] > (*output_tree)->External_Node.Internal_Node.comparison_char) {
				(*output_tree)->External_Node.Internal_Node.left = (*tree)->External_Node.Internal_Node.right;
			}else {
				(*output_tree)->External_Node.Internal_Node.right = (*tree)->External_Node.Internal_Node.right;
			}

			/*From the new node is subtracted the current node value, and the previous
			 * value gets subtracted by this result.
			 */
			(*output_tree)->External_Node.Internal_Node.pos_differ_key -= *sum;
			if(Pat_NodeType((*tree)->External_Node.Internal_Node.right) == Internal){
				(*tree)->External_Node.Internal_Node.right->External_Node.Internal_Node.pos_differ_key -= (*output_tree)->External_Node.Internal_Node.pos_differ_key;
			}

			(*tree)->External_Node.Internal_Node.right = *output_tree;

			return;
		}

		Pat_IInsert(&(*tree)->External_Node.Internal_Node.left, output_tree, key, list, sum, flag, overflow);
		if(*flag){
			return;
		}

		if(*sum > (*output_tree)->External_Node.Internal_Node.pos_differ_key){
			*sum -= (*tree)->External_Node.Internal_Node.pos_differ_key;
			return;
		}

		*flag = 1;

		if(key[(*output_tree)->External_Node.Internal_Node.pos_differ_key-1] > (*output_tree)->External_Node.Internal_Node.comparison_char) {
			(*output_tree)->External_Node.Internal_Node.left = (*tree)->External_Node.Internal_Node.left;
		}else {
			(*output_tree)->External_Node.Internal_Node.right = (*tree)->External_Node.Internal_Node.left;
		}

		(*output_tree)->External_Node.Internal_Node.pos_differ_key -= *sum;
		if(Pat_NodeType((*tree)->External_Node.Internal_Node.left) == Internal){
			(*tree)->External_Node.Internal_Node.left->External_Node.Internal_Node.pos_differ_key -= (*output_tree)->External_Node.Internal_Node.pos_differ_key;
		}

		(*tree)->External_Node.Internal_Node.left = *output_tree;
	}
}

void Pat_Insert(PatNode_Pointer* tree, String key, LL_Pointer* list){
	int flag = 0, sum = 0, overflow = 0;
	PatNode_Pointer output;

	Pat_IInsert(tree, &output, key, list, &sum, &flag, &overflow);
}

void Pat_SSearch(PatNode_Pointer tree, String key, int* sum, int *flag, PatNode_Pointer* output){

	/*Unitiliazed tree*/
	if(tree == NULL){
		*flag = -1;
		return;
	}

	/*First node bypass*/
	if(tree->External_Node.Internal_Node.pos_differ_key == -1){
		Pat_SSearch(tree->External_Node.Internal_Node.left, key, sum, flag, output);
		return;
	}

	/* Node type detection
	 * If the node is external, compares the key.
	 * If the no is internal, recursively calls the function.
	 */
	if(Pat_NodeType(tree)){
		if(!strcmp(key, tree->External_Node.data.key)){
			*flag = 1;
			*output = tree;
		}else{
			*flag = 0;
		}
	}else {
		*sum  += tree->External_Node.Internal_Node.pos_differ_key;

		if (key[*sum-1] > tree->External_Node.Internal_Node.comparison_char) {
//			printf("Passing in node %d %c right\n", tree->External_Node.Internal_Node.pos_differ_key, tree->External_Node.Internal_Node.comparison_char); //Path Right
			Pat_SSearch(tree->External_Node.Internal_Node.right, key, sum, flag, output);
		} else {
//			printf("Passing in node %d %c left\n", tree->External_Node.Internal_Node.pos_differ_key, tree->External_Node.Internal_Node.comparison_char); //Path Right
			Pat_SSearch(tree->External_Node.Internal_Node.left, key, sum, flag, output);
		}
	}
}

void Pat_Search(PatNode_Pointer tree, String key, PatNode_Pointer* output){
	int sum = 0, flag = 0;
	Pat_SSearch(tree, key, &sum, &flag, output);
}

void Pat_Print(PatNode_Pointer tree){
	if(Pat_NodeType(tree)){
		printf("%s\n", tree->External_Node.data.key);
		return;
	}
	Pat_Print(tree->External_Node.Internal_Node.left);
	if(tree->External_Node.Internal_Node.pos_differ_key != -1){
		Pat_Print(tree->External_Node.Internal_Node.right);
	}
}

void Pat_FPrint(PatNode_Pointer tree, FILE** output){
	if(Pat_NodeType(tree)){
		fprintf(*output, "%s ", tree->External_Node.data.key);
		return;
	}
	Pat_FPrint(tree->External_Node.Internal_Node.left, output);
	if(tree->External_Node.Internal_Node.pos_differ_key != -1){
		Pat_FPrint(tree->External_Node.Internal_Node.right, output);
	}
}