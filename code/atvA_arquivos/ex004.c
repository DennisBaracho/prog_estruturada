// 4. Crie um arquivo chamado "entrada.txt" com o conteúdo requerido
// Faça um programa em C que leia o conteúdo do arquivo linha por linha usando o fscanf(). A cada linha lida,
// conte e imprima a quantidade de letras da string

#include <stdio.h>
int main()
{
    int n_Letras = 0;
    char linha[100];
    // Leitura do arquivo
    FILE *leitura = fopen("entrada.txt", "r");
    if (leitura == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return (1);
    }
    while(fscanf(leitura, "%s", linha) == 1){
        n_Letras = 0;
        for(int i = 0; linha[i] != '\0'; i++){
            n_Letras++;
        }
        printf("%s", linha);
        printf("\nNumero de letras: %d\n\n", n_Letras);
    }
    fclose(leitura);
}