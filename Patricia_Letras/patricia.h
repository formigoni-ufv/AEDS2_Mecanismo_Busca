#ifndef PATRICIA_H
#define PATRICIA_H
#define KEY_SIZE 7

typedef enum{
	Internal, External
}NodeType;

typedef struct NodePat* PatNode_Pointer;
typedef struct NodePat{
	NodeType nodetype;
	union{
		struct{
			int index;						//Integer that indicates the differing bit
			PatNode_Pointer left, right;	//P
		}Internal_Node;						//U0
		char key;
	}External_Node;							//UU
}PatNode;

#endif //PATRICIA_H

int Pat_BitScan(int i, char character);	//Returns the i-bit from the left to the right
int Pat_NodeType(PatNode_Pointer tree);			//Returns 1 to an external node and 0 to an internal node
void Pat_Initialize(PatNode_Pointer* tree);
void Pat_NewNode(char newkey, char oldkey, int i, PatNode_Pointer* branch, int* h);
void Pat_Search(PatNode_Pointer tree, char key);
void Pat_IInsert(char k, PatNode_Pointer* t, PatNode_Pointer* u, int i, int* h);
void Pat_Insert(char k, PatNode_Pointer* t);
void Pat_Print(PatNode_Pointer tree);
