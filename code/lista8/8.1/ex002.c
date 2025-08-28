// 2. Declare duas variáveis inteiras que receba dois valores DIFERENTES do usuário
// (TRATAMENTO DE ERRO: caso os valores sejam iguais, solicitar novos valores) e dois
// ponteiros para inteiros. Utilize apenas os ponteiros para trocar os conteúdos dessas variáveis
// e exiba os valores antes e depois da troca. NÃO É PERMITIDO O USO DE VARIÁVEIS TEMPORÁRIAS PARA FAZER A TROCA.

#include <stdio.h>

int main(){
    int valor1, valor2, *p1, *p2;

    do{
    printf("Digite o primeiro valor: ");
    scanf("%d", &valor1);    
    printf("Digite o segundo valor: ");
    scanf("%d", &valor2);
    } while (valor1 == valor2);

    printf("\nValor 1: %d Valor 2: %d\n", valor1, valor2);
    p1 = &valor1;
    p2 = &valor2;
    *p1 = *p1 + *p2;
    *p2 = *p1 - *p2;
    *p1 = *p1 - *p2;

    printf("Valor 1: %d Valor 2: %d", valor1, valor2);
}

