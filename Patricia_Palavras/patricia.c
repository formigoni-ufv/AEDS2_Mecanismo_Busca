#include <stdio.h>
#include <stdlib.h>
#include "patricia.h"
#include "string.h"
#include "auxprocedures.h"
#define ASCIIOFFSET 48
//TODO Nodo e cumulativo, implementar este parametro nas funcoes
//TODO NOTES: TST para autocomplete, patricia para pesquisa

void Pat_Initialize(PatNode_Pointer* tree){
	*tree = (PatNode_Pointer) malloc(sizeof(PatNode));
	(*tree)->nodetype = Internal;
	(*tree)->External_Node.Internal_Node.pos_differ_key = 0;
	(*tree)->External_Node.Internal_Node.left = NULL;

}

int Pat_NodeType(PatNode_Pointer tree){
	return (tree->nodetype == External);
}

void Pat_NewNode(PatNode_Pointer* tree, PatNode_Pointer* output_tree, data key, data internal_key, int* flag){
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

	/*External node initialization*/
	external->nodetype = External;
	external->External_Node.key = (data)malloc( (strlen(key)+1)*sizeof(char) );
	strcpy(external->External_Node.key, key);

	/*Internal node initialization*/
	internal->nodetype = Internal;
	internal->External_Node.Internal_Node.pos_differ_key = pos_differ_key+1;	//Adjust the differing index

	//Puts the smallest of the compared chars(input and internal) in the internal node
	//if the smallest character is taken from the internal key, the external key should be on the right
 	//if the smallest character is taken from the input key, the external key should be on the left
 	if(key[pos_differ_key] < (*tree)->External_Node.key[pos_differ_key]) {
		internal->External_Node.Internal_Node.comparison_char = key[pos_differ_key];
		internal->External_Node.Internal_Node.left = external;
	}else{
		internal->External_Node.Internal_Node.comparison_char = (*tree)->External_Node.key[pos_differ_key];
		internal->External_Node.Internal_Node.right = external;

	}

	*output_tree = internal;
}

void Pat_IInsert(PatNode_Pointer* tree, PatNode_Pointer* output_tree, data key, int* sum, int* flag){

	if(*tree == NULL){
		*flag = 1;
		*tree = (PatNode_Pointer) malloc(sizeof(PatNode));
		(*tree)->nodetype = External;
		(*tree)->External_Node.key = (data) malloc( (strlen(key)+1)*sizeof(char));
		strcpy((*tree)->External_Node.key, key);
		return;
	}

	/* if the node is external, the input string is compared with
	 * the current external node string, if the are equal the function
	 * returns with a flag of 1, therefore finishing the insertion process.
	 */
	if(Pat_NodeType(*tree)){

		if(!strcmp(key, (*tree)->External_Node.key)){
			*flag = 1;
		}else{
			Pat_NewNode(tree, output_tree, key, (*tree)->External_Node.key, flag);
		}

		return;
	}

	/*From this point forward, the node is known to be internal,
	 * therefore it should be decided which side(left or right)
	 * the input string should be directed to.
	 */

	*sum += (*tree)->External_Node.Internal_Node.pos_differ_key;


	if((*tree)->External_Node.Internal_Node.pos_differ_key == 0){
		Pat_IInsert(&(*tree)->External_Node.Internal_Node.left, output_tree, key, sum, flag);

		if(*flag){
			return;
		}

		*flag = 1;
		if(key[(*output_tree)->External_Node.Internal_Node.pos_differ_key-1] > (*output_tree)->External_Node.Internal_Node.comparison_char) {
			(*output_tree)->External_Node.Internal_Node.left = (*tree)->External_Node.Internal_Node.left;
		}else {
			(*output_tree)->External_Node.Internal_Node.right = (*tree)->External_Node.Internal_Node.left;
		}

		(*tree)->External_Node.Internal_Node.left = *output_tree;

		return;
	}

	if(key[*sum-1] > (*tree)->External_Node.Internal_Node.comparison_char){
		Pat_IInsert(&(*tree)->External_Node.Internal_Node.right, output_tree, key, sum, flag);

		if(*flag){
			return;
		}
		/*If the differing character is in a position larger than the current internal node,
		 * the differing node position should be decreased by the differing position of the
		 * new external node.
		 */

		if((*tree)->External_Node.Internal_Node.pos_differ_key == 1){
			return;
		}else if((*tree)->External_Node.Internal_Node.pos_differ_key > (*output_tree)->External_Node.Internal_Node.pos_differ_key){
			(*tree)->External_Node.Internal_Node.pos_differ_key -= (*output_tree)->External_Node.Internal_Node.pos_differ_key;
			return;
		}

		*flag = 1;

		/* Compares a char of the key with the char of the internal node
		 * if the key char is "bigger", it means that
		 */
		if(key[(*output_tree)->External_Node.Internal_Node.pos_differ_key-1] > (*output_tree)->External_Node.Internal_Node.comparison_char) {
			(*output_tree)->External_Node.Internal_Node.left = (*tree)->External_Node.Internal_Node.right;
		}else {
			(*output_tree)->External_Node.Internal_Node.right = (*tree)->External_Node.Internal_Node.right;
		}

		(*tree)->External_Node.Internal_Node.right = *output_tree;

		return;
	}

	Pat_IInsert(&(*tree)->External_Node.Internal_Node.left, output_tree, key, sum, flag);

	if(*flag){
		return;
	}

	if((*tree)->External_Node.Internal_Node.pos_differ_key == 1){
		return;
	}else if((*tree)->External_Node.Internal_Node.pos_differ_key > (*output_tree)->External_Node.Internal_Node.pos_differ_key){
		(*tree)->External_Node.Internal_Node.pos_differ_key -= (*output_tree)->External_Node.Internal_Node.pos_differ_key;
		return;
	}

	*flag = 1;

	if(key[(*output_tree)->External_Node.Internal_Node.pos_differ_key-1] > (*output_tree)->External_Node.Internal_Node.comparison_char) {
		(*output_tree)->External_Node.Internal_Node.left = (*tree)->External_Node.Internal_Node.left;
	}else {
		(*output_tree)->External_Node.Internal_Node.right = (*tree)->External_Node.Internal_Node.left;
	}

	(*tree)->External_Node.Internal_Node.left = *output_tree;

}

void Pat_Insert(PatNode_Pointer* tree, data key){
	int flag = 0, sum = 0;
	PatNode_Pointer output;

	Pat_IInsert(tree, &output, key, &sum, &flag);
}

void Pat_SSearch(PatNode_Pointer tree, data key, int* sum, int *flag){

	/*Unitiliazed tree*/
	if(tree == NULL){
		*flag = -1;
		return;
	}

	/*First node bypass*/
	if(tree->External_Node.Internal_Node.pos_differ_key == 0){
		Pat_SSearch(tree->External_Node.Internal_Node.left, key, sum, flag);
		return;
	}

	/* Node type detection
	 * If the node is external, compares the key.
	 * If the no is internal, recursively calls the function.
	 */
	if(Pat_NodeType(tree)){
		if(!strcmp(key, tree->External_Node.key)){
			*flag = 1;
			printf("Key %s is on the tree.\n", tree->External_Node.key);
		}else{
			*flag = 0;
			printf("Key is not on the tree.\n");
		}
	}else {
		*sum  += tree->External_Node.Internal_Node.pos_differ_key;
		/* if the character of the key is "bigger" than than the node's,
		 * sends the key to the right node recursively.
		 */
		if (key[*sum-1] > tree->External_Node.Internal_Node.comparison_char) {
			printf("Passing in node %d right\n", tree->External_Node.Internal_Node.pos_differ_key);
			Pat_SSearch(tree->External_Node.Internal_Node.right, key, sum, flag);
		} else {
			printf("Passing in node %d left\n", tree->External_Node.Internal_Node.pos_differ_key);
			Pat_SSearch(tree->External_Node.Internal_Node.left, key, sum, flag);
		}
	}
}

void Pat_Search(PatNode_Pointer tree, data key){
	int sum = 0, flag = 0;

	Pat_SSearch(tree, key, &sum, &flag);
}
//********IMPORTANT*********//

//Pat_NewNode:
	//Creates two new nodes based on the result of the comparison between chavecomp_1 and chavecomp_2

//Pat_IInsert
	// u is the output tree
	// t is the input tree
	// i is the divergence index

