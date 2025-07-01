#include <stdio.h>
// Escrever os cinco primeiros numeros perfeitos
// Um numero perfeito eh igual a soma dos seus divisores. Ex: 6 = 1 + 2 + 3
int main(){
    int contador = 0;
    int numero = 2;
    while(contador < 5){
        int soma = 0;
        for(int divisor = 1; divisor < numero; divisor++){
            if(numero % divisor == 0){
                soma += divisor;
            }
        }
        if(soma == numero){
            contador++;
            printf("%d\n", numero);
        }
        numero++;
    }
}