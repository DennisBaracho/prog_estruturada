// Escreva um programa que leia um valor e informe seus divisores em caso de 
// não ser primo, ou mostre na tela “É PRIMO” caso contrário

#include <stdio.h> 

int main(){
    int numero;
    int contador = 0;
    printf("Digite um numero: ");
    scanf("%d", &numero);

    for(int divisor = 2; divisor < numero; divisor++){
        if(numero % divisor == 0){
            printf("%d\n", divisor);
            contador++;
        }
    }
    if(contador < 1){
        printf("Eh primo");
    }
}