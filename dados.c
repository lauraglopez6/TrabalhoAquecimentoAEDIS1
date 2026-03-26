#include <stdio.h>
#include <stdlib.h>
#include "dados.h"

//qtdPontos = n
//tamanhoPop = m
//geracoes = G


void lerDados(const char *nome, int *qtdPontos, int *tamanhoPop, int *geracoes, float **valorX, float **valorY){

FILE *arquivo = fopen(nome, "r");

if(arquivo == NULL){
    printf("Erro ao abrir o arquivo de dados");
    exit(1);
}

fscanf(arquivo, "%d", qtdPontos);
fscanf(arquivo, "%d", tamanhoPop);
fscanf(arquivo, "%d", geracoes);

printf("DEBUG: %d %d %d\n", *qtdPontos, *tamanhoPop, *geracoes);
//criando espaco pra gurdar os valores
*valorX = (float*) malloc ((*qtdPontos)* sizeof(float));
*valorY = (float*) malloc ((*qtdPontos)* sizeof(float));

for(int i=0; i < *qtdPontos; i++){

    fscanf(arquivo, "%f", &(*valorX)[i]);
    fscanf(arquivo, "%f", &(*valorY)[i]);
}
fclose(arquivo);

}