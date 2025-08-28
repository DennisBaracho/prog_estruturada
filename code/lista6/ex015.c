// 15. Leia um vetor contendo letras de uma frase inclusive os espaços em branco. Retirar os espaços em
// branco do vetor e depois escrever o vetor resultante.

#include <stdio.h>

int main(){
    char frase[50];
    char frase_nova[50];
    int j = 0;
    printf("Digite uma frase: ");
    fgets(frase, 50, stdin);
    for(int i = 0; frase[i] != '\0'; i++){
        if(frase[i] != ' '){
            frase_nova[j] = frase[i];
            j++;
        } 
    }
    frase_nova[j] = '\0';
    printf("Frase nova: %s", frase_nova);
}