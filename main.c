#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "populacao.h"
#include "dados.h"
#include "erro.h"
#include "genetica.h"

int main(){
    
    srand(42); 
    
    FILE *f = fopen("output.dat", "w");
    fclose(f);

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
        
        //divide os melhores e os piores
        int metade = d.tamanhoPop / 2;
        int qtdNovos = d.tamanhoPop - metade;

        //60%mutacao 40%cross
        int qtdMutacao = qtdNovos * 0.6;
        int qtdCrossover = qtdNovos - qtdMutacao;

        int index = metade;

        //cross
        for(int i = 0; i < qtdCrossover; i++){
            Individuo pai1 = populacao[rand() % metade];
            Individuo pai2 = populacao[rand() % metade];

            Individuo filho = crossover(pai1, pai2);

            printf("crossover -> a = %.2f | b = %.2f\n", filho.a, filho.b);
            populacao[index++] = filho;
        }

        //mutacao
        for(int i =0; i < qtdMutacao; i++){
            Individuo mutado = populacao[rand() % metade];
            mutacao(&mutado);

            printf("mutacao -> a = %.2f | b = %.2f\n", mutado.a, mutado.b);
            populacao[index++] = mutado;
        }
        
        //ordenar populacao dnv
        ordenarPopulacao(populacao, d.tamanhoPop, d.qtdPontos, d.valorX, d.valorY);

        melhor = populacao[0];
        melhorFitness = calcularFitness(melhor, d.qtdPontos, d.valorX, d.valorY);
        melhorErro = calcularErro(melhor, d.qtdPontos, d.valorX, d.valorY);


        salvarResultados("output.dat", melhor, melhorFitness, melhorErro);
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