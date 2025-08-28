// 7. Faça um programa que leia uma string alfanumérica conte o número de 1’s que aparecem em nela.
// Exemplo: ´ “0011001” -> 3

#include <stdio.h>

int main(){
    char str[20];
    int cont = 0;
    printf("Digite a string alfanumerica: ");
    fgets(str, 20, stdin);
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == '1'){
            cont++;
        }
    }
    printf("Numero de 1's: %d", cont);
}