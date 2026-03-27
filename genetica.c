#include <stdio.h>
#include <stdlib.h>
#include "erro.h"

void ordenarPopulacao(Individuo *populacao, int tamanhoPop, int qtdPontos, float *x, float *y){
    for(int i = 0; i < tamanhoPop - 1; i++){
        for(int j =0; j < tamanhoPop - 1 - i; j++){

            float fitness1 = calcularFitness(populacao[j], qtdPontos, x, y);
            float fitness2 = calcularFitness(populacao[j+1], qtdPontos, x, y);

            if (fitness2 > fitness1){
                Individuo temp = populacao[j];
                populacao[j] = populacao[j+1];
                populacao[j+1] = temp;
            }
        }
    }
}
int dividirPopulacao(int tamanhoPop){
    return tamanhoPop / 2;
}