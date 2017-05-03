#include <stdio.h>
#include <stdlib.h>
#include "auxprocedures.h"
#define BASE 2

void ASCIItoBINARY(char input, char** output){
	int i=0, j=0, ASCII = input;
	int* integers = (int*) malloc(sizeof(int));

	while(ASCII != 0){
		integers[i] = ASCII % BASE;
		ASCII = ASCII / BASE;
		i++;
		integers = realloc(integers, (i+1)*sizeof(int));	//Finishes with one extra vector space
	}

	*output = (char*) malloc((i+1)*sizeof(char));			//Allocates the string plus /0 using this extra space

	j=i-1;													//Makes the j variable receive the size of the int vector
	i=0;

	while(j>=0){
		(*output)[i] = (char)(integers[j]+48);				//Adjust the integers 0s e 1s to 0s e 1s in the ASCII Standard
		i++;
		j--;
	}

	(*output)[i] = '\0';
}