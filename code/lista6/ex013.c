// 13. Escreva um programa para converter uma cadeia de caracteres de letras maiúsculas em letras
// minúsculas. Dica: some 32 dos caracteres cujo código ASCII está entre 65 e 90.

#include <stdio.h>

int main(){
    char palavra[50];
    char string_nova[50];
    printf("Digite uma palavra composta por letras maiusculas: ");
    fgets(palavra, 50, stdin);
    for(int i = 0; palavra[i] != '\0'; i++){
        if(palavra[i] >= 'A' && palavra[i] <= 'Z'){
            string_nova[i] = (int)palavra[i] + 32;
        }
        else{
            string_nova[i] = (int)palavra[i];
        }
    }
    printf("String resultante: %s", string_nova);   
}