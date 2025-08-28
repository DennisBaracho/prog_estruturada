// 10. Faça um programa que receba do usuário uma string. O programa deve imprimir a string sem suas vogais.

#include <stdio.h>

int main(){
    char str[20];
    char str2[20];
    int j = 0;
    printf("Digite a string: ");
    fgets(str, 20, stdin);
    for(int i = 0; str[i] != '\n'; i++){
        if((str[i] == 'A') || (str[i] == 'E') || (str[i] == 'I') || (str[i] == 'O') || (str[i] == 'U') || (str[i] == 'a') || (str[i] == 'e') || (str[i] == 'i') || (str[i] == 'o') || (str[i] == 'u')) {
        }else{
            str2[j] = str[i];
            j++;
        }
    }
    str2[j] = '\0';
    printf("Nova string: %s", str2);
}