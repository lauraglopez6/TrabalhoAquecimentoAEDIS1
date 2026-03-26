#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "populacao.h"
#include "dados.h"

int main(){
    
    srand(42); 

    int qtdPontos;
    int tamanhoPop;
    int geracoes;
    float *valorX;
    float *valorY;


    printf("=== TESTE ===\n");
    lerDados("input.dat", &qtdPontos,&tamanhoPop,&geracoes,&valorX,&valorY);

    float **populacao = gerarPopulacao( tamanhoPop);

    preencherPopulacao(populacao, tamanhoPop, -10, 10);

    for(int i=0; i<tamanhoPop; i++){
        printf("Individuo %d -> a = %.2f | b = %.2f\n",
        i,
         populacao[i][0], 
         populacao[i][1]);
    }

    //TESTE
    printf("pontos: %d\n", qtdPontos);
    printf("populacao: %d\n", tamanhoPop);
    printf("geracoes: %d\n", geracoes);
    for(int i=0; i<qtdPontos;i++){
        printf("X = %.2f | Y = %2f\n", valorX[i], valorY[i]);
    }

    liberarPopulacao(populacao, tamanhoPop);
    free(valorX);
    free(valorY);

    return 0;
}