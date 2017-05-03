#include <stdio.h>
#include <stdlib.h>
#include "auxprocedures.h"
#include "patricia.h"

int main() {
	PatNode_Pointer patricia;

	Pat_Initialize(&patricia);

	Pat_Insert('k', &patricia);
	Pat_Insert('z', &patricia);
	Pat_Insert('o', &patricia);
	Pat_Insert('c', &patricia);
	Pat_Insert('a', &patricia);
	Pat_Insert('l', &patricia);

	Pat_Search(patricia, 'k');
	Pat_Search(patricia, 'z');
	Pat_Search(patricia, 'o');
	Pat_Search(patricia, 'c');
	Pat_Search(patricia, 'a');
	Pat_Search(patricia, 'l');
}