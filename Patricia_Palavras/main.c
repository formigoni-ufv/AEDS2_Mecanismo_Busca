#include <stdio.h>
#include "patricia.h"
#include "listaencadeada.h"
#include "dados.h"

int main() {
	unsigned i;
	char *key1 = "cascalho";
	char *key2 = "cascata";
	char *key3 = "casco";
	char *key4 = "dama";
	char *key5 = "domando";
	char *key6 = "dominar";
	char *key7 = "cascalho";
	FILE* saida = fopen("saida.txt", "wt");
	PatNode_Pointer patricia;
	PatNode_Pointer out_node;
	LL_Pointer list;

	LL_Inititialize(&list);
	InvertedIndex index[4];
	for(i=0; i<4; i++){
		index[i].qtde = i;
		index[i].idDoc = i+1;
		LL_Insert(&list, index[i]);
	}

	Pat_Initialize(&patricia);


	Pat_Insert(&patricia, key1, &list);
	Pat_Insert(&patricia, key2, &list);
	Pat_Insert(&patricia, key3, &list);
	Pat_Insert(&patricia, key4, &list);
	Pat_Insert(&patricia, key5, &list);
	Pat_Insert(&patricia, key6, &list);
	Pat_Insert(&patricia, key7, &list);

//	Pat_Print(patricia);
	Pat_FPrint(patricia, &saida);
	fclose(saida);
//	Pat_Search(patricia, key1, &out_node);
//	Pat_Search(patricia, key2, &out_node);
//	Pat_Search(patricia, key3, &out_node);
//	Pat_Search(patricia, key4, &out_node);
//	Pat_Search(patricia, key5, &out_node);
//	Pat_Search(patricia, key6, &out_node);
//	Pat_Search(patricia, key7, &out_node);
}