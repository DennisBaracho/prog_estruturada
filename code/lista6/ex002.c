// 2. Crie um programa em que a entrada seja um nome e imprima o nome somente se a primeira letra
// do nome for ‘a’ (maiúscula ou minúscula).

#include <stdio.h>

int main(){
    char nome[15];
    printf("Digite seu primeiro nome: ");
    fgets(nome, 15, stdin);
    if(nome[0] == 'a' || nome[0] == 'A'){
        printf("Ja que comeca com a letra A, esse eh seu nome: %s", nome);
    }
    else{
        printf("So imprimo se comecar com a letra A.");
    }
}