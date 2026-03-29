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
        
        //impar ou par
        if(g % 2 ==0){
            //se for par cross
            Individuo pai1 = populacao[0];
            Individuo pai2 = populacao[1];

            Individuo filho = crossover(pai1, pai2);

            printf("crossover -> filho: a = %.2f | b = %.2f\n",filho.a, filho.b);
            populacao[d.tamanhoPop -1] = filho;
        }else{
            //se nao, muta
            Individuo mutado = populacao[0];
            mutacao(&mutado);
            printf("mutacao -> a = %.2f | b = %.2f\n", mutado.a, mutado.b);
            //substitui o pior
            populacao[d.tamanhoPop - 1] = mutado;
        }  
        //reordenar
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