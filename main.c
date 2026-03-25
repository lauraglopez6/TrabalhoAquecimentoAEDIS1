#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "populacao.h"

int main(){
    int tamanhoPop = 5;
    srand(42); 

    float **populacao = gerarPopulacao(tamanhoPop);

    preencherPopulacao(populacao, tamanhoPop, -10, 10);

    for(int i=0; i<tamanhoPop; i++){
        printf("Individuo %d -> a = %.2f | b = %.2f\n",
        i,
         populacao[i][0], 
         populacao[i][1]);
    }

    liberarPopulacao(populacao, tamanhoPop);
    return 0;
}