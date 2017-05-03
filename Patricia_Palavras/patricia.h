#ifndef PATRICIA_H
#define PATRICIA_H
#define KEY_SIZE 7

typedef char* data;

typedef enum{
	Internal, External
}NodeType;

typedef struct NodePat* PatNode_Pointer;
typedef struct NodePat{
	NodeType nodetype;
	union{
		struct{
			int	pos_differ_key;
			char internal_key;
			PatNode_Pointer left, right;
		}Internal_Node;						//U0
		data key;
	}External_Node;							//UU
}PatNode;


void Pat_Initialize(PatNode_Pointer* tree);
int Pat_NodeType(PatNode_Pointer tree);
void Pat_NewNode(PatNode_Pointer* tree, data key, data internal_key, PatNode_Pointer* output_tree, int* flag);
void Pat_IInsert(PatNode_Pointer* tree, data key, int key_length, int* flag);
void Pat_Insert(PatNode_Pointer* tree);
void Pat_Search(PatNode_Pointer tree);

//int Pat_BitScan(int i, char character);	//Returns the i-bit from the left to the right
//int Pat_NodeType(PatNode_Pointer tree);			//Returns 1 to an external node and 0 to an internal node
//void Pat_Initialize(PatNode_Pointer* tree);
//void Pat_NewNode(char newkey, char oldkey, int i, PatNode_Pointer* branch, int* h);
//void Pat_Search(PatNode_Pointer tree, char key);
//void Pat_IInsert(char k, PatNode_Pointer* t, PatNode_Pointer* u, int i, int* h);
//void Pat_Insert(char k, PatNode_Pointer* t);
//void Pat_Print(PatNode_Pointer tree);


#endif //PATRICIA_H
