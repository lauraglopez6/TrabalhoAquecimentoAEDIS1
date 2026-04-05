#include <stdio.h>
#include <stdlib.h>
#include "erro.h"

//MSE
float calcularErro(Individuo ind, int qtdPontos, float *x, float *y){

    float erroTotal = 0;

    //^y = ax + b
    for(int i = 0; i < qtdPontos; i++){
        float yPrevisto = ind.a * x[i] + ind.b;
        float erro = y[i] - yPrevisto;
        erroTotal += erro * erro;
    }
    return erroTotal / qtdPontos;
}

float calcularFitness(Individuo ind, int qtdPontos, float *x, float *y){

    float erro = calcularErro(ind, qtdPontos, x, y);
    return 1.0 / (1.0 + erro);
}
//menor erro, maior fitness
//maior erro, menor fitness