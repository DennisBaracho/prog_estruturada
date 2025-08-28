// Nesta tarefa NÃO É PERMITIDO USAR A BIBLIOTECA string.h e é para ser feito INDIVIDUAL.
// Escreva um programa em C que receba do usuário duas strings A e B.
// Seu programa deve verificar se B é uma substring de A.
// A saída do seu programa deve ser:
// "B está contido em A" ou "B não está contido em A"

#include <stdio.h>
int main()
{
    char A[100];
    char B[100];
    int contador_semelhanca = 0;
    int tamanhoA = 0;
    int tamanhoB = 0;
    printf("Digite a string principal A: ");
    fgets(A, 100, stdin);
    printf("Digite a substring B: ");
    fgets(B, 100, stdin);

    for (tamanhoB; B[tamanhoB] != '\0'; tamanhoB++){
        if (B[tamanhoB] == '\n'){
            B[tamanhoB] = '\0';
            break;
        }
    }

    for (int i = 0; A[i] != '\0' && A[i] != '\n'; i++){
        if (A[i] != B[contador_semelhanca]){
            contador_semelhanca = 0;
        }
        if (A[i] == B[contador_semelhanca]){
            contador_semelhanca++;
            if (contador_semelhanca == tamanhoB){
                break;
            }
        }
    }

    if (contador_semelhanca == tamanhoB){
        printf("B esta contido em A");
    }
    else{
        printf("B nao esta contido em A");
    }
}
