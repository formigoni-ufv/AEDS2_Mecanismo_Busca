#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxprocedures.h"
#include "patricia.h"

int main() {
	char* key = "karah";

	PatNode_Pointer patricia;

	Pat_Initialize(&patricia);

//	Pat_IInsert(&patricia, key, 5+1);

	printf("Len: %d\n", strlen(key));
}