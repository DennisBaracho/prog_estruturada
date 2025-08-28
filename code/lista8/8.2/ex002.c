// Crie um programa que contenha uma matriz de float contendo o número de linhas e colunas 
// que o usuário informar como entrada para o programa. Atribua valores para cada posição desse 
// array (use um loop  e atribua para cada  posição  o valor  de  i*j). Imprima o endereço de cada 
// posição dessa matriz.
#include <stdio.h>
#include <stdlib.h>
int main(){
    float **p=NULL;
    int i, j,linha,coluna;
    printf("Coloque Linha e Coluna:");
    scanf("%d %d",&linha,&coluna);
    p=malloc(linha*sizeof(float*));
    if (p==NULL){
        printf("Deu errado aí amigo!");
        exit(1);
    }
    for (i=0;i<linha;i++){
        p[i]=malloc(coluna*sizeof(float));
    }
    for (i=0;i<linha;i++){
        for(j=0;j<coluna;j++){
            p[i][j] = i*j;
            printf("Elemento:%.2f || Endereco::%p\n",p[i][j],&p[i][j]);
        }
    }
    for (i=0;i<linha;i++){
        free(p[i]);
    }
    free(p);
}