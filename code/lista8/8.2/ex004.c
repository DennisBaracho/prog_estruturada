// Crie um programa que aloque um array de inteiros contendo o tamanho que o usuário informar 
// como entrada para o programa. Leia os valores desse array do teclado e imprima o endereço 
// das posições contendo valores pares.  

#include <stdio.h>
#include <stdlib.h>

int main(){
    int tam;
    int *p = NULL;
    printf("Digite o tamanho: ");
    scanf("%d", &tam);
    getchar();
    p = malloc(tam * sizeof(int));
    printf("Digite os valores desse array: \n");
    for(int i = 0; i < tam; i++){
        printf("Digite o valor %d: ", i);
        scanf("%d", &p[i]);
    }
    for(int j = 0; j < tam; j++){
        printf("\nValor: %d, Endereco: %d", p[j], &p[j]);
    }
}
