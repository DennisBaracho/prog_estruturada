// 1. Crie um programa que calcula o comprimento de uma string (não use a função strlen)

#include <stdio.h>

int main(){
    char str[1000];
    int cont;
    printf("Digite a string: ");
    fgets(str, 1000, stdin);
    for(cont = 0; str[cont] != '\n'; cont++){}
    printf("A string tem comprimento de %d", cont);
}