// 16. Faça um programa em que troque todas as ocorrências de uma letra L1 pela letra L2 em uma string.
// A string e as letras L1 e L2 devem ser fornecidas pelo usuário.

#include <stdio.h>

int main(){
    char STR[50];
    char L1, L2;
    printf("Digite uma frase: ");
    fgets(STR, 50, stdin);
    printf("Digite L1: ");
    L1 = getchar();
    getchar();
    printf("Digite L2: ");
    L2 = getchar();
    for(int i = 0; STR[i] != '\0'; i++){
        if(STR[i] == L1){
            STR[i] = L2;
        }
        else if(STR[i] == L2){
            STR[i] = L1;
        }
    }
    printf("%s", STR);
}