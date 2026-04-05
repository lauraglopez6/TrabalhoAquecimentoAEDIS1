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
    
    Dados d = lerDados("input.dat");

    Individuo *populacao = gerarPopulacao(d.tamanhoPop);
    preencherPopulacao(populacao, d.tamanhoPop, -10, 10);

    //loop
    for(int g = 0; g < d.geracoes; g++){

        ordenarPopulacao(populacao, d.tamanhoPop, d.qtdPontos, d.valorX, d.valorY);

        Individuo melhor = populacao[0];

        float melhorFitness = calcularFitness(melhor, d.qtdPontos, d.valorX, d.valorY);
        float melhorErro = calcularErro(melhor, d.qtdPontos, d.valorX, d.valorY);
        
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

            populacao[index++] = filho;
        }

        //mutacao
        for(int i =0; i < qtdMutacao; i++){
            Individuo mutado = populacao[rand() % metade];
            mutacao(&mutado);

            populacao[index++] = mutado;
        }
        
        //ordenar populacao dnv
        ordenarPopulacao(populacao, d.tamanhoPop, d.qtdPontos, d.valorX, d.valorY);

        melhor = populacao[0];
        melhorFitness = calcularFitness(melhor, d.qtdPontos, d.valorX, d.valorY);
        melhorErro = calcularErro(melhor, d.qtdPontos, d.valorX, d.valorY);


        salvarResultados("output.dat", melhor, melhorFitness, melhorErro);
    }

    liberarPopulacao(populacao);
    free(d.valorX);
    free(d.valorY);

    return 0;
}