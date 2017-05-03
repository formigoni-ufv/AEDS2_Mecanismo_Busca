#include <stdio.h>
#include <stdlib.h>
#include "patricia.h"
#include "auxprocedures.h"
#define ASCIIOFFSET 48
/*************Erros no Livro********************
 * Codigo de inserçao à direita repetido duas vezes.
**********************************************/
//Todo perguntar nodo cabeça na impl.

/******************DONE*************************/
int Pat_BitScan(int i, char character){			//Returns the bit in the ith position (1 to n)
	int index=0;
	char* binary;

	ASCIItoBINARY(character, &binary);

	return (int) (binary[i-1] - ASCIIOFFSET);	//Selected bit(n - offset) - the ASCII decimal standard offset
}

int Pat_NodeType(PatNode_Pointer tree){
	return (tree->nodetype == External);
}

void Pat_Initialize(PatNode_Pointer* tree){
	*tree = (PatNode_Pointer)malloc(sizeof(PatNode));
	(*tree)->nodetype = Internal;
	(*tree)->External_Node.Internal_Node.right = NULL;
	(*tree)->External_Node.Internal_Node.left = NULL;
	(*tree)->External_Node.Internal_Node.index = 0;
}

void Pat_NewNode(char newkey, char oldkey, int i, PatNode_Pointer* branch, int* h){ // i>0
	PatNode_Pointer internal, new_node;

	/*while i is less or equal to n (n+1 bits), also compares '\0'*/
	while(i <= KEY_SIZE){
		if(Pat_BitScan(i, newkey) == Pat_BitScan(i, oldkey)) {				//1 to 1 bit comparison
			i++;															//If bits are equal, i increases
		}else{
			break;															//Otherwise the loop stops
		}
	}

	/*if the i size exceeds the KEY_SIZE, that means the keys are identical, in which case
	 * the operation should be terminated.
	 */
	if(i>KEY_SIZE){
		*h = 1;
		return;
	}

	/*if the size of the i integer is not bigger than KEY_SIZE, that means
	 * the operation should continue (the keys are different).
	 */
	*h=0;	//Indicates the operation hasn't ended, there's a new subtree which should be properly placed on the main tree

	/*1. A new internal node is created with it's index set to the
	 * differing bit index of the previous comparison
	 *2. A new external node is created to hold the value
	 * of the inserted key*/
	internal = (PatNode_Pointer) malloc(sizeof(PatNode));		//New internal node
	new_node = (PatNode_Pointer) malloc (sizeof(PatNode));		//The new node which will receive the new key

	internal->nodetype = Internal;								//Sets the first node as an internal one
	internal->External_Node.Internal_Node.index = i;			//Gives it the index in which the bits diverge

	new_node->nodetype = External;
	new_node->External_Node.key = newkey;

	/*if the differing bit is 0, the new key is to be put on the
	 * left node of internal one, which is the newly allocated q otherwise it stays
	 * on the right node.
	 */
	if(Pat_BitScan(i, newkey) == 0){
		internal->External_Node.Internal_Node.left = new_node;		//Puts it to the left in case it's 0

	}else{
		internal->External_Node.Internal_Node.right = new_node;		//Otherwise it's set to the right
	}

	*branch = internal;												//Returns the new 'half tree'
}

void Pat_Search(PatNode_Pointer tree, char key){
	if(Pat_NodeType(tree)) {					//if it's an external node, the searched key must be in it
		if(key == tree->External_Node.key){
			printf("Key is on the tree.\n");
		}else{
			printf("Key not found.\n");
		}
	}else{
		/*Differing bit indicates the way to walk the trie
		 * if the i-bit of the key is 0, it means it should
		 * be to the left of the trie, otherwise, it should
		 * be to the right.
		 * */
		if(tree->External_Node.Internal_Node.index != 0){
			if (Pat_BitScan(tree->External_Node.Internal_Node.index, key) == 0){
				Pat_Search(tree->External_Node.Internal_Node.left, key);
			}else{
				Pat_Search(tree->External_Node.Internal_Node.right, key);
			}
		}else{
			Pat_Search(tree->External_Node.Internal_Node.left, key);
		}
	}
}

void Pat_IInsert(char k, PatNode_Pointer* t, PatNode_Pointer* u, int i, int* h){
	if(*t == NULL){											//If the tree is NULL, insert key
		*h = 1;
		*t = (PatNode_Pointer) malloc(sizeof(PatNode));
		(*t)->nodetype = External;
		(*t)->External_Node.key = k;
		return;
	}

	/*If the node is external, creates a new internal node and puts the new key attached to it, leaving the other
	 * side untouched*/
	if(Pat_NodeType(*t)){
		Pat_NewNode(k, (*t)->External_Node.key, i+1, u, h);
		return;
	}

	/* 0.Checks if the node isn't the first one.
	 *
	 * 1.Compares differing bit of the external node with the key
	 *if it's 0, sends it to the left node
	 *
	 * 2.The left node can be an external node, in which case the bits
	 * of the binary components will be compared and it could have h=1 if the
	 * keys were equal, otherwise creates an internal node which will hold on
	 * either side a new external node with the inserted key.
	 *
	 * 3.If the differing bit(index) of the output 'half tree' is smaller or equal to the
	 * current tree, it's sent back one recursive level
	 *
	 * 4. h is set to 1 which means this is the last operation to be executed in the recursive pile,
	 * the 'half tree' will receive the current left node (external or internal) of the current tree,
	 * if i-bit of the inserted key is 0, the new node is on the left and the old node should be put
	 * on the right of the three, same goes otherwise. After that, the current three points to the new
	 * node
	 *
	 */

	if((*t)->External_Node.Internal_Node.index == 0){
		Pat_IInsert(k, &(*t)->External_Node.Internal_Node.left, u, i, h);
		if(*h){
			return;														//Its already on the tree
		}
		*h = 1;
		if(Pat_BitScan((*u)->External_Node.Internal_Node.index, k) == 0){
			(*u)->External_Node.Internal_Node.right = (*t)->External_Node.Internal_Node.left;
		}else{
			(*u)->External_Node.Internal_Node.left = (*t)->External_Node.Internal_Node.left;
		}
		(*t)->External_Node.Internal_Node.left = (*u);
		return;

	}

	if(Pat_BitScan((*t)->External_Node.Internal_Node.index, k) == 0){
		Pat_IInsert(k, &(*t)->External_Node.Internal_Node.left, u, i, h);
		if(*h){
			return;														//Its already on the tree
		}
		if((*t)->External_Node.Internal_Node.index >= (*u)->External_Node.Internal_Node.index){
			return;
		}
		*h = 1;
		if(Pat_BitScan((*u)->External_Node.Internal_Node.index, k) == 0){
			(*u)->External_Node.Internal_Node.right = (*t)->External_Node.Internal_Node.left;
		}else{
			(*u)->External_Node.Internal_Node.left = (*t)->External_Node.Internal_Node.left;
		}
		(*t)->External_Node.Internal_Node.left = *u;
		return;
	}

	Pat_IInsert(k, &(*t)->External_Node.Internal_Node.right, u, i, h);
	if(*h){
		return;
	}
	if((*t)->External_Node.Internal_Node.index >= (*u)->External_Node.Internal_Node.index) {
		return;
	}
	*h = 1;
	if(Pat_BitScan((*u)->External_Node.Internal_Node.index, k) == 0){
		(*u)->External_Node.Internal_Node.right = (*t)->External_Node.Internal_Node.right;
	}else{
		(*u)->External_Node.Internal_Node.left = (*t)->External_Node.Internal_Node.right;
	}
	(*t)->External_Node.Internal_Node.right = *u;
}

void Pat_Insert(char k, PatNode_Pointer* t){
	int i=0, h;
	PatNode_Pointer u;

	Pat_IInsert(k, t, &u, i, &h);
}
/***********************************************/

//********IMPORTANT*********//

//Pat_NewNode:
	//Creates two new nodes based on the result of the comparison between chavecomp_1 and chavecomp_2

//Pat_IInsert
	// u is the output tree
	// t is the input tree
	// i is the divergence index

