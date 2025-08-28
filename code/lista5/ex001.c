// Faça um algoritmo que leia uma matriz S[6,6] e um valor A. A seguir, multiplique a matriz pelo valor
// A, colocando o resultado em um vetor V[36]. Mostre o vetor V[36].

#include <stdio.h>
int main(){
    int S[6][6];
    int A;
    int V[36];
    int i = 0;

    printf("Digite um valor A: ");
    scanf("%d", &A);
    for(int lin = 0; lin < 6; lin++){
        for(int col = 0; col < 6; col++){
            printf("Digite o elemento S[%d][%d]: ", lin + 1, col + 1);
            scanf("%d", &S[lin][col]);
            V[i] = S[lin][col]*A;
            i++;
        }
    }

    printf("\nVetor V: ");
    for(i = 0; i < 36; i++){
            printf("[%d] ", V[i]);
    }
}