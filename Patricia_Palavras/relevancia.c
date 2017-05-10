#include <math.h>
#include "relevancia.h"
#include "patricia.h"

void calculaRelevancia(PatNode_Pointer* patricia, String pBusca,  int qtdNA, float* saidaRelevancia, int* saidaArq){ //deve retornar dois vetores com relevancia e o id do arquivo de entrada
	int cont,i,j,k,qtdA,guarda=0,maior=0,diffe;
	char vPalavra[100][100];
	int qtdEntradas;
	float R,RT;//30 pois e o numero maximo para arquivos
	PatNode_Pointer output;
	R=0;
	cont = 0;
	qtdA = 0;
	j=0;
	i=0;
	k=0;
	diffe =0;

	Pat_Search(*patricia, pBusca, &output);
	if(output == NULL){
		return;
	}else{
		qtdEntradas = LL_Count(output->External_Node.data.invertedindex);
	}


	/**********separa palavras************/
	while(pBusca[i] != '\0'){
		while(pBusca[i] != ' ' || pBusca[i] != '\0'){
			vPalavra[j][k] = pBusca[i];
			k++;
			i++;
		}
		vPalavra[j][k] = '\0';
		diffe++;
		j++;
		k=0;
	}
	for(j=0;j<diffe;j++){
		//compara vPalavra[j] com a arvore patricia para ver se ela tem algum registro, se tiver recebe um no e passa para as variaveis
		qtdA = LL_Count((*patricia)->External_Node.data.invertedindex);
		LL_NodePointer lista = (*patricia)->External_Node.data.invertedindex->first->next;
		for(i = 1; i <= qtdA; i++){
			qtdNA = lista->index.qtde;
			R += qtdNA*log(2)/qtdEntradas; //qtdNA = quantidade de vezes que o termo aparece no arquivo, qtdEntradas = quantidade de arquivos
			if(i == 1){
				maior = lista->index.qtde;
				guarda = lista->index.idDoc;
			}else{
				if(maior < qtdNA){
					maior = lista->index.qtde;
					guarda = lista->index.idDoc;
				}
			}
			lista = lista->next;
		}
		RT = 1/qtdNA*R; //qtdTDNA quantidade de termos distintos no arquivo
		saidaRelevancia[cont] = RT;
		saidaArq[cont] = guarda;
	}
}