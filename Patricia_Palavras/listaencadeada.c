#include <stdio.h>
#include <stdlib.h>
#include "listaencadeada.h"
#include "dados.h"

void LL_Inititialize(LL_Pointer* LL){
	*LL = (LL_Pointer)malloc(sizeof(LinkedList));
	(*LL)->first = (LL_NodePointer)malloc(sizeof(LL_Node));
	(*LL)->last = (*LL)->first;
	(*LL)->last->next = NULL;
}

void LL_Insert(LL_Pointer* LL, InvertedIndex index){
	(*LL)->last->next = (LL_NodePointer)malloc(sizeof(LL_Node));
	(*LL)->last = (*LL)->last->next;
	(*LL)->last->index = index;
	(*LL)->last->next = NULL;
}

void LL_Print(LL_Pointer LL){
	LL_NodePointer node = LL->first->next;
	while(node != NULL){
		printf("qtde: %d | idDoc %d\n", node->index.qtde, node->index.idDoc);
		node = node->next;
	}
}