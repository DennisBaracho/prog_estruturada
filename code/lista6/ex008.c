// 8. Escreva um programa que substitui as ocorrências de um caractere ‘0’ em uma string pelo caractere ‘1’.

#include <stdio.h>

int main(){
    char str[20];
    printf("Digite a string alfanumerica: ");
    fgets(str, 20, stdin);
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == '0'){
            str[i] = '1';
        }
    }
    printf("Nova string: %s", str);
}