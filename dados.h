#ifndef DADOS_H
#define DADOS_H

//nao coloquei com m, n e g as variaveis pq me deixa confusa e esqueco oq é oq. 

typedef struct{
    int qtdPontos;
    int tamanhoPop;
    int geracoes;
    float *valorX;
    float *valorY;
} Dados;

Dados lerDados(const char *nome);

#endif