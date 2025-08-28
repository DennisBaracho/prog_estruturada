// 9. Faça um programa que receba uma string e a imprima de trás-para-frente.

#include <stdio.h>

int main(){
    char str[20];
    char str2[20];
    int tamanho = 0;

    printf("Digite a string: ");
    fgets(str, 20, stdin);

    for(int i = 0; str[i] != '\n'; i++){
        tamanho++;
    }

    for(int j = 0; str2[j] != '\n'; j++){
        str2[j] = str[(tamanho - j)];
        printf("%d", tamanho);
    }
    printf("\nString de tras pra frente: %s", str2);
}