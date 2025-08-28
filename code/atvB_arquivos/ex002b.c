// 2. Leia esse arquivo binário e exiba todos os números.

#include <stdio.h>

int main(){
    FILE* leitura = fopen("vetor.bin", "rb");
    if (leitura == NULL){
        printf("Erro ao ler o arquivo!\n");
        return 1;
    }
    
    int numeros[100];
    fread(numeros, sizeof(int), 100, leitura);
    printf("Numeros: ");
    for(int i = 0; i < 100; i++){
        printf("%d ", numeros[i]);
    }
    fclose(leitura);
}