#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "populacao.h"
#include "dados.h"
#include "erro.h"
#include "genetica.h"

int main(){
    
    srand(42); 

    printf("=== TESTE ===\n");
    
    Dados d = lerDados("input.dat");

    Individuo *populacao = gerarPopulacao( d.tamanhoPop);

    preencherPopulacao(populacao, d.tamanhoPop, -10, 10);

    //float melhorFitness = 0;
    //int melhorIndividuo = 0;

    for(int i = 0; i < d.tamanhoPop; i++){

        float erro = calcularErro(populacao[i], d.qtdPontos, d.valorX, d.valorY);

        float fitness = calcularFitness(populacao[i], d.qtdPontos, d.valorX, d.valorY);

        printf("Individuo %d -> a = %.2f \t| b = %.2f \t| erro = %.2f\t\t| fitness = %.4f\n\n",
         i,
         populacao[i].a, 
         populacao[i].b,
         erro,
         fitness);
    }

    ordenarPopulacao(populacao, d.tamanhoPop, d.qtdPontos, d.valorX, d.valorY);

    printf("\nPOPULACAO ORDENADA DE ACORDO COM O FITNESS\n");
    for(int i =0; i < d.tamanhoPop; i++){
         float fitness = calcularFitness(populacao[i], d.qtdPontos, d.valorX, d.valorY);

         printf("Individuo %d -> a = %.2f | b = %.2f | fitness = %.4f\n",
        i, populacao[i].a, populacao[i].b, fitness);
    }

    printf("MELHOR INDIVIDUO\n");
    printf("a = %.2f | b = %.2f | fitness = %.4f\n",
           populacao[0].a, populacao[0].b,
           calcularFitness(populacao[0], d.qtdPontos, d.valorX, d.valorY));

    printf("DIVISAO DE MELHORES E PIORES");

    printf("Melhores:\n");
    int metade = d.tamanhoPop / 2;
    for(int i = 0; i < metade; i++){
        printf("Ind %d\n", i);
    }

    printf("Piores:\n");
    for(int i = metade; i < d.tamanhoPop; i++){
        printf("Ind %d\n", i);
    }

    //TESTE
    printf("numero de pontos: %d\n", d.qtdPontos);
    printf("populacao: %d\n", d.tamanhoPop);
    printf("geracoes: %d\n", d.geracoes);

    for(int i = 0; i < d.qtdPontos; i++){
        printf("X = %.2f | Y = %2f\n", d.valorX[i], d.valorY[i]);
    }

    liberarPopulacao(populacao);
    free(d.valorX);
    free(d.valorY);

    return 0;
}