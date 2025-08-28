// Crie um programa que aloque um array de inteiros contendo o tamanho que o usuário informar 
// como entrada para o programa (O TAMANHO MÁXIMO DO VETOR DEVE SER 1000, TRATE 
// CASO O VALOR DIGITADO FOR MAIOR). Leia os valores desse array de um arquivo de texto 
// inputs_int_lista8_p2.txt e, utilizando apenas aritmética de ponteiros, imprima o dobro de cada 
// valor lido.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
    FILE*arquivo;
}ab;
int main (){
    int *p;
    ab ab;
    int i, tam=-1;
    printf("Tamanho do vetor:");
    scanf("%d",&tam);
    while (tam>1000){
        printf("Seu vetor maior que o máximo, coloque abaixo de 1000:");
        scanf("%d",&tam);
    }
    p=malloc(tam*sizeof(int));
    if (p==NULL){
        printf("Deu errado aí!");
        exit(1);
    }
    ab.arquivo = fopen("inputs_int_lista8_p2.txt","r");
    if (ab.arquivo == NULL){
        printf("Falha ao abrir o arquivo");
        return 1;
    }
    for (i=0;i<tam;i++){
        fscanf(ab.arquivo,"%d",p+i);
        p[i]=temp[i];
        p[i]*=2;
        printf("%d\n");
    }
    free(p);

}