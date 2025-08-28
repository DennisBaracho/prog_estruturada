#include <stdio.h>
#include <stdlib.h>

int main() {
    int vetor[10] = {0, 1, 30, 3, 4, 5, 6, 70, 8, 9};

    // Dois ponteiros apontando para posições diferentes do vetor
    int *ptr1 = &vetor[1];  // Aponta para o elemento de índice 2
    int *ptr2 = &vetor[7];  // Aponta para o elemento de índice 7

    // Calcula a diferença entre os ponteiros (quantos elementos separam)
    int diff = abs(ptr2 - ptr1);

    printf("Numero de elementos entre os ponteiros: %d\n", diff);

    return 0;
}
