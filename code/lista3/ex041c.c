// 41. Faça um programa que leia dois valores inteiros valor inteiro x e n, calcule e mostre
// c. inserir x, x**2

#include <stdio.h>

int main(){
    int x = 0;
    int n = 0;
    int somatorio = 0;

    printf("Digite x: ");
    scanf("%d", &x);
    printf("Digite n: ");
    scanf("%d", &n);

    for(int i = x; i <= n; i++){
        somatorio += (x*x);
    }

    printf("%d", somatorio);
}

