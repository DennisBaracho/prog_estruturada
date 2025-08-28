// 4. Faça um programa que o usuário digite um nome, calcule e retorne quantas letras tem esse nome.

#include <stdio.h>

int main(){
    char nome[50];
    int cont = 0;
    printf("Digite seu nome completo: ");
    fgets(nome, 50, stdin);
    for(int i = 0; nome[i] != '\0'; i++){
        if((nome[i] != '\n') && (nome[i] != ' ')){
            cont++;
        }
    }
    printf("Seu nome tem %d letras.", cont);
}