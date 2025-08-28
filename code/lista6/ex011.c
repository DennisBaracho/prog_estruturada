// 11. Faça um programa que receba uma palavra e calcule quantas vogais (a, e, i, o, u) possui essa palavra

#include <stdio.h>

int main(){
    char str[20];
    int j = 0;
    int n_vogais = 0;
    printf("Digite a palavra: ");
    fgets(str, 20, stdin);
    for(int i = 0; str[i] != '\n'; i++){
        if((str[i] == 'A') || (str[i] == 'E') || (str[i] == 'I') || (str[i] == 'O') || (str[i] == 'U') || (str[i] == 'a') || (str[i] == 'e') || (str[i] == 'i') || (str[i] == 'o') || (str[i] == 'u')) {
            n_vogais++;
        }
    }
    printf("Numero de vogais: %d", n_vogais);
}