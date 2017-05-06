#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxprocedures.h"
#include "patricia.h"

int main() {
	char *key1 = "cascalho";
	char *key2 = "cascata";
	char *key3 = "casco";
	char *key4 = "dama";
	char *key5 = "domando";
	char *key6 = "dominar";


	PatNode_Pointer patricia;

	Pat_Initialize(&patricia);

	Pat_Insert(&patricia, key1);
	Pat_Insert(&patricia, key2);
	Pat_Insert(&patricia, key3);
	Pat_Insert(&patricia, key4);
	Pat_Insert(&patricia, key5);
//	Pat_Insert(&patricia, key6);
//	Pat_Search(patricia, key1);
//	Pat_Search(patricia, key2);
//	Pat_Search(patricia, key3);
	Pat_Search(patricia, key4);
//	Pat_Search(patricia, key5);
//	Pat_Search(patricia, key6);

	PatNode_Pointer zero = patricia->External_Node.Internal_Node.left;

//	printf("%d %c\n",
//	zero->External_Node.Internal_Node.pos_differ_key,
//	zero->External_Node.Internal_Node.comparison_char
//	);
}