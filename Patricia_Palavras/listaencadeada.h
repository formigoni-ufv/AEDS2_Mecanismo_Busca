#ifndef PATRICIA_LISTAENCADEADA_H
#define PATRICIA_LISTAENCADEADA_H
#include "dados.h"

typedef struct LL_Node* LL_NodePointer;
typedef struct LL_Node{
	InvertedIndex index;
	LL_NodePointer next;
}LL_Node;

typedef struct LinkedList* LL_Pointer;
typedef struct LinkedList{
	LL_NodePointer first;
	LL_NodePointer last;
}LinkedList;

void LL_Inititialize(LL_Pointer* LL);
void LL_Insert(LL_Pointer* LL, InvertedIndex index);
void LL_Print(LL_Pointer LL);

#endif //PATRICIA_LISTAENCADEADA_H
