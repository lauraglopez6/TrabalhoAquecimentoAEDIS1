#include <stdio.h>
#include <stdlib.h>
#include "erro.h"
#include "genetica.h"

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

Individuo crossover(Individuo pai1, Individuo pai2){
    Individuo filho;

    filho.a = pai1.a;
    filho.b = pai2.b;

    return filho;
}

void salvarResultados(const char *nome, Individuo melhor, float fitness,float erro ){

    FILE *arquivo = fopen(nome, "a");
     if(arquivo == NULL){
        printf("Erro ao abrir arquivo");
        return;
     }
     fprintf(arquivo, "fitness: %.4f | erro: %.2f | a: %.2f | b: %.2f\n",
            fitness, erro, melhor.a, melhor.b);

            fclose(arquivo);
}

void mutacao(Individuo *ind){
    float delta = (rand() / (float)RAND_MAX) * 2 - 1;

    if(rand() % 2 == 0){
        ind->a += delta;
    }else{
        ind->b += delta;
    }
}