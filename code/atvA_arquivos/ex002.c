// 2. Crie um programa em C que abra o arquivo dados.txt, criado no exercício anterior, e exiba seu
// conteúdo na tela.
// Requisitos:
// Abrir o arquivo no modo de leitura ("r").
// Usar fgets() para ler os dados linha por linha.
// Exibir o conteúdo na tela com printf().
// Tratar o erro caso o arquivo não exista.

#include <stdio.h>
int main()
{
    char linha[2];
    char nome[45];
    int idade;
    // Leitura do arquivo
    FILE *leitura = fopen("dados.txt", "r");
    if (leitura == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return (1);
    }
    while (fgets(linha, sizeof(linha), leitura) != NULL){
        printf("%s", linha);
    }
    fclose(leitura);
}