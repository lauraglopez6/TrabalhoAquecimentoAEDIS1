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

    float melhorFitness = 0;
    int melhorIndividuo = 0;

    for(int i = 0; i < d.tamanhoPop; i++){

        float erro = calcularErro(populacao[i], d.qtdPontos, d.valorX, d.valorY);

        float fitness = calcularFitness(populacao[i], d.qtdPontos, d.valorX, d.valorY);

        printf("Individuo %d -> a = %.2f \t| b = %.2f \t| erro = %.2f\t\t| fitness = %.4f\n\n",
         i,
         populacao[i].a, 
         populacao[i].b,
         erro,
         fitness);

         if(fitness > melhorFitness){
            melhorFitness = fitness;
            melhorIndividuo = i;
         }
    }

    printf("\nMELHOR INDIVIDUO/FITNESS TESTE\n");
    printf("Indice: %d\n", melhorIndividuo);
    printf("a = %.2f | b = %.2f | fitness = %.4f\n\n",
           populacao[melhorIndividuo].a,
           populacao[melhorIndividuo].b,
           melhorFitness);

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