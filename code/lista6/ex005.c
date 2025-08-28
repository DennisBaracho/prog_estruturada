// 5. Faça um programa que leia um nome, sexo e idade. Se sexo for feminino e idade menor que 25,
// imprima o nome da pessoa e a palavra “ACEITA”, caso contrário imprimir “NÃO ACEITA”.

#include <stdio.h>

int main(){
    char nome[48];
    char sexo[1];
    int idade;

    printf("Digite seu nome: ");
    fgets(nome, 48, stdin);
    printf("Digite seu sexo ('F' ou 'M'): ");
    fgets(sexo, 1, stdin);
    getchar();
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    if (((sexo[1] == 'F') || (sexo[1] == 'f')) && (idade < 25)){
        printf("%s ACEITA", nome);
    }
    else{
        printf("%s NAO ACEITA!");
    }
}