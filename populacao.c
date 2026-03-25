#include <stdio.h>
#include <stdlib.h>
#include "populacao.h"

float** gerarPopulacao(int tamanhoPop){
    float **populacao = (float**) malloc(tamanhoPop * sizeof(float*));

    for (int i = 0; i<tamanhoPop; i++){
        populacao[i] = (float*) malloc(2 * sizeof(float));

    }
return populacao;
}

//randon
float gerarAleatorio(float valorMin, float valorMax){
    return valorMin + (rand() / (float)RAND_MAX) * (valorMax - valorMin);

}
void preencherPopulacao(float **populacao, int tamanhoPop, float valorMin, float valorMax){
    for(int i = 0; i < tamanhoPop; i++){
        populacao[i][0] = gerarAleatorio(valorMin, valorMax); 
        populacao[i][1] = gerarAleatorio(valorMin, valorMax);
    }
}

void liberarPopulacao(float **populacao, int tamanhoPop){
    for (int i =0; i < tamanhoPop; i++){
        free(populacao[i]);
    }
    free(populacao);
}