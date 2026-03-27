#ifndef ERRO_H
#define ERRO_H
#include "populacao.h"

float calcularErro(Individuo ind, int qtdPontos, float *x, float *y);
float calcularFitness(Individuo ind, int qtdPontos, float *x, float *y);

#endif