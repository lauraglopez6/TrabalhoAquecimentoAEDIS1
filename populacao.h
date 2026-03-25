#ifndef POPULACAO_H
#define POPULACAO_H

//tamanhoPop = m 
float** gerarPopulacao(int tamanhoPop);

void preencherPopulacao(float **populacao, int tamanhoPop, float valorMin, float valorMax);
//randon, gera a populacao

void liberarPopulacao(float **populacao, int tamanhoPop);

#endif
