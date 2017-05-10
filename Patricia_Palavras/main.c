#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patricia.h"
#include "relevancia.h"
#include "dados.h"
#include "relevancia.h"

void Arquivo_Leitura(String file_name, PatNode_Pointer* patricia, unsigned idDoc);
void Arquivo_Duplica(FILE* input, FILE* copy, char* nomedoArquivo);	 //Duplica arquivos
void Arquivo_Index(FILE* input, FILE* copy, InvertedIndex* index, String* out_string);	//Quantidade da palavra em 1 arquivo

int main() {
	PatNode_Pointer patricia;
	Pat_Initialize(&patricia);
	LL_Pointer list = NULL;
	PatNode_Pointer out_node;

	char *key1 = "cascalho";
	char *key2 = "cascata";
	char *key3 = "casco";
	char *key4 = "dama";
	char *key5 = "domando";
	char *key6 = "dominar";
	char *key7 = "cascalho";

	Pat_Insert(&patricia, key1, &list);
	Pat_Insert(&patricia, key2, &list);
	Pat_Insert(&patricia, key3, &list);
//	Pat_Insert(&patricia, key5, &list);
//	Pat_Insert(&patricia, key6, &list);
//	Pat_Insert(&patricia, key7, &list);

	Pat_Search(patricia, key1, &out_node);
	Pat_Search(patricia, key2, &out_node);
	Pat_Search(patricia, key3, &out_node);
//	Pat_Search(patricia, key4, &out_node);
//	Pat_Search(patricia, key5, &out_node);
//	Pat_Search(patricia, key6, &out_node);
//	Pat_Search(patricia, key7, &out_node);

}

void Arquivo_Leitura(String file_name, PatNode_Pointer* patricia, unsigned idDoc){
	char nomedoArquivo[15];
	FILE* entrada;
	FILE* copy1;
	FILE* copy2;
	InvertedIndex index;
	Content list;

	index.qtde = 0;
	index.idDoc = idDoc;
	list.key = (String)malloc(30*sizeof(char));

	strcpy(nomedoArquivo, file_name);
	entrada = fopen(nomedoArquivo, "rt");

	/*ARQUIVO É COPIADO PARA 2 AUXILIARES*/
	copy1 = fopen("copy1.txt", "wt");
	copy2 = fopen("copy2.txt", "wt");
	Arquivo_Duplica(entrada, copy1, nomedoArquivo);
	Arquivo_Duplica(entrada, copy2, nomedoArquivo);
	fclose(copy1);
	fclose(copy2);

	/*AUXILIARES AVALIAM NUMERO EM QUE UMA PALAVRA APARECE NO DOCUMENTO*/
	copy1 = fopen("copy1.txt", "rt");
	copy2 = fopen("copy2.txt", "rt");

	LL_Inititialize(&list.invertedindex);
	do{
		Arquivo_Index(copy2, copy1, &index, &list.key);
		LL_Insert(&list.invertedindex, index);
		Pat_Insert(patricia, list.key, &(list.invertedindex));
		index.qtde = 0;
		list.invertedindex = NULL;
		LL_Inititialize(&list.invertedindex);
	}while(!feof(copy2));

	fclose(copy1);
	fclose(copy2);
	fclose(entrada);
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

void Arquivo_Index(FILE* input, FILE* copy, InvertedIndex* index, String* out_string){
	char in_string[30], cpy_string[30];

	fscanf(input, "%s ", in_string);
	strlwr(in_string);
	strcpy(*out_string, in_string);

	do{
		fscanf(copy, "%s ", cpy_string);
		if(!strcmp(in_string, cpy_string)){
			index->qtde += 1;
		}
	}while(!feof(copy));
	rewind(copy);
}