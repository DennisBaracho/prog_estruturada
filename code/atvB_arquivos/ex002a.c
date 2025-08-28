// 2. Crie e leia um vetor de inteiros binário:
// Crie um array de 100 inteiros (valores de 1 a 100) e salve em "vetor.bin".
// Em outro programa (ex002b.c), leia esse arquivo binário e exiba todos os números.

#include <stdio.h>

int main(){
    FILE* arquivo = fopen("vetor.bin", "wb");
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    int numeros[100];
    for(int i = 0; i < 100; i++){
        numeros[i] = i + 1;
    }
    fwrite(numeros, sizeof(int), 100, arquivo);
    fclose(arquivo);
}