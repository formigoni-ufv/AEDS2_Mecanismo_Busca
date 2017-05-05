#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxprocedures.h"
#include "patricia.h"

int main() {
	char *key1 = "karah";
	char *key2 = "kadah";
	char *key3 = "korah";
	char *key4 = "marah";
	char *key5 = "kirah";

	PatNode_Pointer patricia;

	Pat_Initialize(&patricia);

	Pat_Insert(&patricia, key1);
	Pat_Insert(&patricia, key2);
	Pat_Insert(&patricia, key3);
	Pat_Insert(&patricia, key4);
	Pat_Search(patricia, key1);
	Pat_Search(patricia, key2);
	Pat_Search(patricia, key3);
	Pat_Search(patricia, key4);

	PatNode_Pointer zero = patricia->External_Node.Internal_Node.left;

//	printf("%c %d\n",
//	zero->External_Node.Internal_Node.comparison_char,
//	zero->External_Node.Internal_Node.pos_differ_key
//	);
}