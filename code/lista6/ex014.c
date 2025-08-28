// 14. Leia uma cadeia de caracteres e converta todos os caracteres para maiúscula. Dica: subtraia 32 dos
// caracteres cujo código ASCII está entre 97 e 122.

#include <stdio.h>

int main(){
    char palavra[50];
    char string_nova[50];
    printf("Digite uma palavra composta por letras minusculas: ");
    fgets(palavra, 50, stdin);
    for(int i = 0; palavra[i] != '\0'; i++){
        if(palavra[i] >= 'a' && palavra[i] <= 'z'){
            string_nova[i] = (int)palavra[i] - 32;
        }
        else{
            string_nova[i] = (int)palavra[i];
        }
    }
    printf("String resultante: %s", string_nova);   
}