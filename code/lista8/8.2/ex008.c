// Crie  um  programa  que  aloque  três  matrizes  de  float,  cada  uma  com  5  linhas  e  50  colunas. 
// Preencha essas duas matrizes com os valores lidos do arquivo de texto 
// inputs_float_lista8_p2.txt. Leia da linha 1 até a linha 250 para a primeira matriz e da linha 251 
// até a linha 500. Calcule a soma dos elementos da primeira e segunda matriz e atribua à terceira 
// matriz. Imprima a terceira matriz. 

#include <stdio.h>
#include <stdlib.h>

int main(){
    float **p1 = NULL;
    float **p2 = NULL;
    float **p3 = NULL;

    float soma = 0;
    p1 = malloc(5*sizeof(float));
    for(int i = 0; i < 5; i++){
        p1[i] = malloc(50*sizeof(float*));
    }

    p2 = malloc(5*sizeof(float));
    for(int i = 0; i < 5; i++){
        p2[i] = malloc(50*sizeof(float*));
    }

    p3 = malloc(5*sizeof(float));
    for(int i = 0; i < 5; i++){
        p3[i] = malloc(50*sizeof(float*));
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 50; j++){
            scanf("%f", &p1[i][j]);
        }
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 50; j++){
            scanf("%f", &p2[i][j]);
        }
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 50; j++){
            soma = p1[i][j] + p2[i][j];
            p3[i][j] = soma;
        }
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 50; j++){
            printf("%d ", p3[i][j]);
        }
        printf("\n");
    }
}