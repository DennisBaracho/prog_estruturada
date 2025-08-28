// 1. Grave e leia uma struct em um arquivo binário:
// Crie um programa em C que solicite nome e idade do usuário, armazene-os numa struct e salve
// no arquivo “usuario.bin”.
// Feche o arquivo. Depois, abra para leitura binária, recupere os dados e exiba na tela.

#include <stdio.h>

typedef struct{
    char nome[45];
    int idade;
} Usuario;

int main()
{
    // Criação e escrita do arquivo
    FILE *arquivo = fopen("usuario.bin", "wb");
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    Usuario u;
    printf("Digite seu nome: ");
    fgets(u.nome, 45, stdin);
    printf("Digite sua idade: ");
    scanf("%d", &u.idade);
    fwrite(&u, sizeof(Usuario), 1, arquivo);
    fclose(arquivo);

    // Leitura do arquivo
    FILE *leitura = fopen("usuario.bin", "rb");

    if (leitura == NULL){
        printf("Erro ao ler o arquivo!\n");
        return 1;
    }

    Usuario uLido;
    fread(&uLido, sizeof(Usuario), 1, leitura);
    fclose(leitura);
    
    printf("Nome: %sIdade: %d", uLido.nome, uLido.idade);
}