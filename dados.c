#include <stdio.h>
#include <stdlib.h>
#include "dados.h"

//qtdPontos = n
//tamanhoPop = m
//geracoes = G
//void lerDados(const char *nome, int *qtdPontos, int *tamanhoPop, int *geracoes, float **valorX, float **valorY){

Dados lerDados(const char *nome){
    
    Dados d;

FILE *arquivo = fopen(nome, "r");

if(arquivo == NULL){
    printf("Erro ao abrir o arquivo de dados");
    exit(1);
}

fscanf(arquivo, "%d", &d.qtdPontos);
fscanf(arquivo, "%d", &d.tamanhoPop);
fscanf(arquivo, "%d", &d.geracoes);

//espaco pra gurdar os valores
d.valorX = (float*) malloc (d.qtdPontos * sizeof(float));
d.valorY = (float*) malloc (d.qtdPontos * sizeof(float));

for(int i=0; i < d.qtdPontos; i++){

    fscanf(arquivo, "%f", &d.valorX[i]);
    fscanf(arquivo, "%f", &d.valorY[i]);
}
fclose(arquivo);

return d;

}