// 3. Salve e leia múltiplos registros:
// Escreva um programa para cadastrar 3 pessoas (nome/idade), salvar no arquivo “pessoas.bin” e
// outro programa para ler e mostrar os 3 registros gravados.

#include <stdio.h>

typedef struct{
    char nome[45];
    int idade;
} Pessoa;

int main(){
    FILE* arquivo = fopen("pessoas.bin", "wb");
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    Pessoa p;
    for(int i = 1; i <= 3; i++){
        printf("Digite o nome da pessoa %d: ", i);
        fgets(p.nome, 45, stdin);
        printf("Digite a idade da pessoa %d: ", i);
        scanf("%d", &p.idade);
        getchar();
        fwrite(&p, sizeof(Pessoa), 1, arquivo);
    }
    fclose(arquivo);
}