// 3. Faça um programa que leia um nome e imprima as 4 primeiras letras do nome.

#include <stdio.h>
int main(){
    char nome[15];
    int i = 0;
    printf("Digite seu nome: ");
    fgets(nome, 15, stdin);
    for(i = 0; i < 4; i++){
        printf("Letra %d: %c\n", (i+1), nome[i]);
    }
}