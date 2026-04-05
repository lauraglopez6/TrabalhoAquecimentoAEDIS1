#include <stdio.h>
#include <stdlib.h>
#include "populacao.h"

Individuo* gerarPopulacao(int tamanhoPop){
    Individuo *populacao = (Individuo*) malloc(tamanhoPop * sizeof(Individuo));

return populacao;
}

//gerar numero aleatorio
float gerarAleatorio(float valorMin, float valorMax){
    return valorMin + (rand() / (float)RAND_MAX) * (valorMax - valorMin);

}
void preencherPopulacao(Individuo *populacao, int tamanhoPop, float valorMin, float valorMax){
    for(int i = 0; i < tamanhoPop; i++){
        populacao[i].a = gerarAleatorio(valorMin, valorMax); 
        populacao[i].b = gerarAleatorio(valorMin, valorMax);
    }
}

void liberarPopulacao(Individuo *populacao){
    free(populacao);
}