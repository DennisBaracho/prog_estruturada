// 1. Crie um programa em C que solicite ao usuário seu nome e idade e salve essas informações em um arquivo chamado dados.txt. Cada execução do programa deve sobrescrever os dados anteriores
// Requisitos:
// Usar a função fopen() no modo de escrita ("w").
// Utilizar fprintf() para escrever os dados no arquivo.
// Fechar o arquivo com fclose().

#include <stdio.h>
int main()
{
    char nome[45];
    int idade;
    // Criação e escrita do arquivo
    FILE *arquivo = fopen("dados.txt", "w");
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return (1);
    }
    printf("Digite seu nome: ");
    fgets(nome, 45, stdin);

    printf("Digite sua idade: ");
    scanf("%d", &idade);
    fprintf(arquivo, "%s%d", nome, idade);
    fclose(arquivo);
}