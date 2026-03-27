#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "populacao.h"
#include "dados.h"
#include "erro.h"

int main(){
    
    srand(42); 

    printf("=== TESTE ===\n");
    
    Dados d = lerDados("input.dat");

    Individuo *populacao = gerarPopulacao( d.tamanhoPop);

    preencherPopulacao(populacao, d.tamanhoPop, -10, 10);

    for(int i = 0; i < d.tamanhoPop; i++){

        float erro = calcularErro(populacao[i], d.qtdPontos, d.valorX, d.valorY);

        printf("Individuo %d -> a = %.2f \t| b = %.2f \t| erro = %.2f\n\n",
         i,
         populacao[i].a, 
         populacao[i].b,
         erro);
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