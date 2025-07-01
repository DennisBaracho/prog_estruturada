// 43. Escreva um algoritmo que calcula e escreve o produto dos números primos entre 92 e 1478.

#include <stdio.h>

int main(){
    unsigned long long produto = 1;
    int contador = 0;
    for(unsigned long long numero = 92; numero < 1478; numero++){
        for(unsigned long long divisor = 1; divisor < numero; divisor++){
            if(numero % divisor == 0){
                contador++;
            }
        }
        if (contador <= 2){
            printf("%llu\n", numero);
            produto *= numero;
        }
        contador = 0;
    }
    printf("%llu\n", produto);
}