// 3. Ler e mostrar os 3 registros gravados.

#include <stdio.h>

typedef struct{
    char nome[45];
    int idade;
} Pessoa;

int main(){
    FILE* leitura = fopen("pessoas.bin", "rb");
    if (leitura == NULL){
        printf("Erro ao ler o arquivo!\n");
        return 1;
    }

    Pessoa pLido;
    for(int i = 1; i <= 3; i++){
        fread(&pLido, sizeof(Pessoa), 1, leitura);
        printf("\nPessoa %d\nNome: %sIdade: %d\n", i, pLido.nome, pLido.idade);
    }
    fclose(leitura);
}