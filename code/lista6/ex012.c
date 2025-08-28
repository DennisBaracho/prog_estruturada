// 12. Faça um programa que leia uma palavra (máximo de 50 letras) e some 1 no valor ASCII de cada
// caractere da palavra. Imprima a string resultante.

#include <stdio.h>

int main(){
    char palavra[50];
    char string_nova[50];
    printf("Digite uma palavra de no maximo 50 letras: ");
    fgets(palavra, 50, stdin);
    for(int i = 0; palavra[i] != '\0'; i++){
        string_nova[i] = (int)palavra[i] + 1;
    }
    printf("String resultante: %s", string_nova);   
}