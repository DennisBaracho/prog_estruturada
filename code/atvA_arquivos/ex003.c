// 3. Escreva um programa para criar o arquivo "multiplos7.txt" e gravar em seu conteúdo os números
// múltiplos de sete de 1 até 94365, um em cada linha.

#include <stdio.h>
int main()
{
    int multiplos = 1;
    // Criação e escrita do arquivo
    FILE *arquivo = fopen("multiplos7.txt", "w");
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return (1);
    }

    fprintf(arquivo, "%d\n", multiplos);
    for (int i = 1; multiplos <= 94365; i++){
        multiplos = (7 * i);
        if (multiplos < 94365){
            fprintf(arquivo, "%d\n", (multiplos));
        }
    }

    fclose(arquivo);
}