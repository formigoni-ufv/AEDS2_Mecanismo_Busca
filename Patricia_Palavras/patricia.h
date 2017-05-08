#ifndef PATRICIA_H
#define PATRICIA_H
#include "dados.h"
#include "listaencadeada.h"

typedef enum{
	Internal, External
}NodeType;

typedef struct NodePat* PatNode_Pointer;
typedef struct NodePat{
	NodeType nodetype;
	union{
		struct{
			int	pos_differ_key;
			char comparison_char;
			PatNode_Pointer left, right;
		}Internal_Node;						//U0
		data key;
		LL_Pointer invertedindex;
	}External_Node;							//UU
}PatNode;


void Pat_Initialize(PatNode_Pointer* tree);
int Pat_NodeType(PatNode_Pointer tree);
void Pat_NewNode(PatNode_Pointer* tree, PatNode_Pointer* output_tree, data key, data internal_key, int* flag);
void Pat_IInsert(PatNode_Pointer* tree, PatNode_Pointer* output_tree, data key, int* sum, int* flag, int* overflow);
void Pat_Insert(PatNode_Pointer* tree, data key);
void Pat_SSearch(PatNode_Pointer tree, data key, int* sum, int *flag);
void Pat_Search(PatNode_Pointer tree, data key);

#endif //PATRICIA_H
