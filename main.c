#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "populacao.h"
#include "dados.h"
#include "erro.h"
#include "genetica.h"

int main(){
    
    srand(42); 

    printf("TESTE \n");
    
    Dados d = lerDados("input.dat");

    Individuo *populacao = gerarPopulacao(d.tamanhoPop);
    preencherPopulacao(populacao, d.tamanhoPop, -10, 10);

    //loop
    for(int g = 0; g < d.geracoes; g++){

        printf("\n GERACAO %d \n", g);

        
        ordenarPopulacao(populacao, d.tamanhoPop, d.qtdPontos, d.valorX, d.valorY);

        
        Individuo melhor = populacao[0];

        float melhorFitness = calcularFitness(melhor, d.qtdPontos, d.valorX, d.valorY);
        float melhorErro = calcularErro(melhor, d.qtdPontos, d.valorX, d.valorY);

        printf("Melhor -> a = %.2f | b = %.2f | fitness = %.4f | erro = %.2f\n",
               melhor.a, melhor.b, melhorFitness, melhorErro);

        
        salvarResultados("output.dat", melhor, melhorFitness, melhorErro);

        
        Individuo mutado = melhor;
        mutacao(&mutado);

        printf("Mutado -> a = %.2f | b = %.2f\n", mutado.a, mutado.b);

        
        populacao[d.tamanhoPop - 1] = mutado;
    }

    // TESTE 
    printf("\nDADOS\n");
    printf("numero de pontos: %d\n", d.qtdPontos);
    printf("populacao: %d\n", d.tamanhoPop);
    printf("geracoes: %d\n", d.geracoes);

    for(int i = 0; i< d.qtdPontos; i++){
        printf("X = %.2f | Y = %2f\n", d.valorX[i], d.valorY[i]);
    }

    // liberar memória
    liberarPopulacao(populacao);
    free(d.valorX);
    free(d.valorY);

    return 0;
}