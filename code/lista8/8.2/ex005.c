// Considere a seguinte declaração de variáveis: int A, *B, **C, ***D;  
// Escreva um programa que leia a variável “A” e calcule e exiba o dobro, o triplo e o quádruplo 
// desse valor utilizando apenas os ponteiros B, C e D. O ponteiro B deve ser usada para calcular 
// o dobro, C o triplo e D o quadruplo. 

#include <stdio.h>
#include <stdlib.h>

int main(){
    int A, *B, **C, ***D;
    printf("Digite o valor de A: ");
    scanf("%d", &A);
    B = &A;
    *B *= 2;
    printf("B: %d", *B);
    C = &B;
    **C *= 3;
    printf("C: %d", **C);
    D = &C;
    ***D *= 4;
    printf("D: %d", ***D);
    printf("A: %d", A);
}