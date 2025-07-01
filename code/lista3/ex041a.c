// 41. Faça um programa que leia dois valores inteiros valor inteiro x e n, calcule e mostre
// a. começa em x, vai somando até n com passo 1

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
        somatorio += i;
    }

    printf("%d", somatorio);
}

