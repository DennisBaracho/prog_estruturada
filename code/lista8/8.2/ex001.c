// Crie um programa que aloque um array de float contendo o tamanho que o usuário informar 
// como entrada para o programa. Atribua valores para cada posição desse array (use um loop e 
// atribua para cada posição o valor de i). Imprima o endereço de cada posição desse array.
#include <stdio.h>
#include <stdlib.h>
int main (){
    int tam,i;
    int *p;
    p=NULL;
    printf("Tamanho:");
    scanf("%d",&tam);
    p=malloc(tam*(sizeof(int)));
    if (p==NULL){
        printf("coda melhor aí!");
        exit(1);
    }
    for (i=0;i<tam;i++){
        p[i]=i;
        printf("Valor: %d | Endereço: %d\n", p[i], &p[i]);
    }
    free(p);
}