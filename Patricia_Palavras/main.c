#include "patricia.h"
#include "dados.h"

int main() {
	char *key1 = "cascalho";
	char *key2 = "cascata";
	char *key3 = "casco";
	char *key4 = "dama";
	char *key5 = "domando";
	char *key6 = "dominar";
	char *key7 = "cascalho";
	unsigned i;

	LL_Pointer list;
	LL_Inititialize(&list);

	InvertedIndex index[4];
	for(i=0; i<4; i++){
		index[i].qtde = i;
		index[i].idDoc = i+1;
		LL_Insert(&list, index[i]);
	}

	PatNode_Pointer patricia;
	Pat_Initialize(&patricia);

	Pat_Insert(&patricia, key1, &list);
//	Pat_Insert(&patricia, key2);
//	Pat_Insert(&patricia, key3);
//	Pat_Insert(&patricia, key4);
//	Pat_Insert(&patricia, key5);
//	Pat_Insert(&patricia, key6);
//	Pat_Insert(&patricia, key7);

	Pat_Search(patricia, key1);
//	Pat_Search(patricia, key2);
//	Pat_Search(patricia, key3);
//	Pat_Search(patricia, key4);
//	Pat_Search(patricia, key5);
//	Pat_Search(patricia, key6);
//	Pat_Search(patricia, key7);
}