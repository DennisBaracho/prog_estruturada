// Crie um programa que contenha uma matriz de float contendo o número de linhas e colunas 
// que o usuário informar como entrada para o programa. Atribua valores para cada posição desse 
// array (use um loop  e atribua para cada  posição  o valor  de  i*j). Imprima o endereço de cada 
// posição dessa matriz. 

#include <stdio.h>
#include <stdlib.h>

int main(){
    int linhas;
    int colunas;
    float **p = NULL; 
    printf("Digite o numero de linhas: ");
    scanf("%d", &linhas);
    getchar();
    printf("Digite o numero de colunas: ");
    scanf("%d", &colunas);
    p = malloc(linhas * sizeof(float*));
    for(int i = 0; i < linhas; i++){
        p[i] = malloc(colunas * sizeof(float));
    }
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            p[i][j] = i*j;
            printf("Valor: %.2f Endereco: %d\n", p[i][j] ,&p[i][j]);
        }
    }
}