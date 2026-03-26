#ifndef POPULACAO_H
#define POPULACAO_H

//tamanhoPop = m 

typedef struct{
    float a;
    float b;

}Individuo;

Individuo* gerarPopulacao(int tamanhoPop);

void preencherPopulacao(Individuo *populacao, int tamanhoPop, float valorMin, float valorMax);

void liberarPopulacao(Individuo *populacao);

#endif
