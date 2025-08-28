// 1. Crie uma variável do tipo inteiro e um ponteiro para inteiro. Faça o ponteiro apontar para a
// variável criada e, utilizando o ponteiro, mostre o valor armazenado na variável na tela.

#include <stdio.h>

int main(){
    int dado = 10, *p;
    p = &dado; // p aponta para dado
    printf("Valor armazenado na variavel: %d\n", *p);
    printf("Digite o novo valor a ser armazenado: ", *p);
    scanf("%d", &*p);
    printf("Novo valor ao qual *p aponta: %d\n", *p);
    printf("Novo valor armazenado na variavel dado: %d", dado);
}