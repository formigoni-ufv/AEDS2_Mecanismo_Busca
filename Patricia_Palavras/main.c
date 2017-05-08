#include <stdio.h>
#include <string.h>
#include "dados.h"

void Arquivo_Duplica(FILE* input, FILE* copy, char* nomedoArquivo);	 //Duplica arquivos
void Arquivo_Index(FILE* input, FILE* copy, InvertedIndex* index);	//Quantidade da palavra em 1 arquivo

int main() {
	FILE* input;
	FILE* copy1 = fopen("copy1.txt", "wt");
	FILE* copy2 = fopen("copy2.txt", "wt");
	InvertedIndex index;
	char nomedoArquivo[15];

	index.qtde = 0;
	index.idDoc = 0;

	sprintf(nomedoArquivo, "arquivo%d.txt", index.idDoc);

	/*ARQUIVO É COPIADO PARA 2 AUXILIARES*/
	copy1 = fopen("copy1.txt", "wt");
	copy2 = fopen("copy2.txt", "wt");
	Arquivo_Duplica(input, copy1, nomedoArquivo);
	Arquivo_Duplica(input, copy2, nomedoArquivo);
	fclose(copy1);
	fclose(copy2);


	/*AUXILIARES AVALIAM NUMERO EM QUE UMA PALAVRA APARECE NO DOCUMENTO*/
	copy1 = fopen("copy1.txt", "rt");
	copy2 = fopen("copy2.txt", "rt");
	Arquivo_Index(copy1, copy2, &index);
	Arquivo_Index(copy1, copy2, &index);
	Arquivo_Index(copy1, copy2, &index);
	fclose(copy1);
	fclose(copy2);
}

void Arquivo_Duplica(FILE* input, FILE* copy, char* nomedoArquivo){
	char string[30];
	char prox;

	input = fopen(nomedoArquivo, "rt");

	do{
		prox = (char)fgetc(input);
		if(prox == EOF)	break;
		fseek(input, -1, SEEK_CUR);

		fscanf(input, "%[A-Za-z0-9]s", string);
		strlwr(string);
		fprintf(copy, "%s ", string);

		if(feof(input)){
			break;
		}

		prox = (char)fgetc(input);
		if(prox == EOF)	break;

		if(prox == ',' || prox == '.' || prox == ':' || prox == '?' || prox == '!' || prox == ';' || prox == '\n'){
			prox = (char)fgetc(input);
			if(prox == EOF)	break;

			while(prox == ' '){
				fscanf(input, "%c", &prox);
			}

			if(prox != '\n'){
				fseek(input, -1, SEEK_CUR);
			}
		}
	}while(!feof(input));

	fclose(input);
}

void Arquivo_Index(FILE* input, FILE* copy, InvertedIndex* index){
	char in_string[30], cpy_string[30];

	fscanf(input, "%s", in_string);
	strlwr(in_string);

	do{
		fscanf(copy, "%s ", cpy_string);
		if(!strcmp(in_string, cpy_string)){
			index->qtde += 1;
		}
	}while(!feof(copy));
	rewind(copy);

	printf("Palavra: %s | QTDE: %d\n", in_string, index->qtde);
}