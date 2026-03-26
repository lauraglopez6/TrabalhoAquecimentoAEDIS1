#ifndef DADOS_H
#define DADOS_H

typedef struct{
    int qtdPontos;
    int tamanhoPop;
    int geracoes;
    float *valorX;
    float *valorY;
} Dados;

Dados lerDados(const char *nome);

#endif