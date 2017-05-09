#ifndef PATRICIA_H
#define PATRICIA_H
#include "dados.h"
#include "listaencadeada.h"

typedef struct{
	String key;
	LL_Pointer invertedindex;
}Content;

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
		Content data;
	}External_Node;							//UU
}PatNode;


void Pat_Initialize(PatNode_Pointer* tree);
int Pat_NodeType(PatNode_Pointer tree);
void Pat_NewNode(PatNode_Pointer* tree, PatNode_Pointer* output_tree, String key, LL_Pointer* list, String internal_key, int* flag);
void Pat_IInsert(PatNode_Pointer* tree, PatNode_Pointer* output_tree, String key, LL_Pointer* list, int* sum, int* flag, int* overflow);
void Pat_Insert(PatNode_Pointer* tree, String key, LL_Pointer* list);
void Pat_SSearch(PatNode_Pointer tree, String key, int* sum, int *flag);
void Pat_Search(PatNode_Pointer tree, String key);

#endif //PATRICIA_H
