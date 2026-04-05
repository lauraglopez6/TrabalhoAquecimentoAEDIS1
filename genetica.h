#ifndef GENETICA_H
#define GENETICA_H
#include "populacao.h"

void ordenarPopulacao(Individuo *populacao, int tamanhoPop, int qtdPontos, float *x, float *y);

Individuo crossover(Individuo pai1, Individuo pai2);

void salvarResultados(const char *nome, Individuo melhor, float fitness,float erro );

void mutacao(Individuo *ind);

#endif