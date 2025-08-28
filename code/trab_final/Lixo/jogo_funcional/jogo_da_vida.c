/**************************************************************************************** 
Trabalho Computacional - Programação Estruturada/Programação II - 2025/1 
Dennis Francisco Guimarães de Oliveira Baracho
****************************************************************************************/ 

#include <stdio.h>
#include <stdlib.h>

typedef struct{
        char arquivo_entrada[50];
        char arquivo_saida[50];
        int colunas;
        int linhas;
        int geracoes;
        int **matriz;
    } tabuleiro;

void lerNomeArquivo(char *arquivo_entrada){
    int i = 0;
    printf("Digite o nome do arquivo de entrada: ");
    fgets(arquivo_entrada, 50, stdin);
    while (arquivo_entrada[i] != '\0') {
        if (arquivo_entrada[i] == '\n') {
            arquivo_entrada[i] = '\0';
            break;
        }
        i++;
    }
}

void criarArquivoDeSaida(char* arquivo_entrada, char* arquivo_saida){
    int i = 0; 
    int j = 0; 
    int k = 0;
    char sufixo[4] = "_out";
    for(i = 0; arquivo_entrada[i] != '\n' && arquivo_entrada[i] != '\0'; i++){
                if(arquivo_entrada[i] == '.'){
                    for(k = 0; k < 4; k++){
                        arquivo_saida[j] = sufixo[k];
                        j++;
                    }
                    arquivo_saida[j] = '.';
                    j++;
                }
                else{
                    arquivo_saida[j] = arquivo_entrada[i];
                    j++;
                }
            }
            arquivo_saida[j] = '\0';
}

void lerMatriz(FILE* entrada, int *linhas, int* colunas, int* geracoes, int*** matriz){
    int i = 0; int j = 0; int k = 0;
    fscanf(entrada, "%d %d %d", linhas, colunas, geracoes);
    *matriz = (int **) malloc(*linhas * sizeof(int *));
    for(i = 0; i < *linhas; i++){
        (*matriz)[i] = malloc(*colunas * sizeof(int));
    }
    char valorLido;
    int valorIncorporado = 0;
    for(j = 0; j < *linhas; j++){
        for(k = 0; k < *colunas; k++){
        // Celulas mortas convertidas em 0
            fscanf(entrada, " %c", &valorLido);
                if(valorLido == '.'){
                    valorIncorporado = 0;
                }
                // Celulas vivas convertidas em 1
                else if(valorLido == '0'){
                    valorIncorporado = 1;
                }
            (*matriz)[j][k] = valorIncorporado;  
        }
    }
}

int contarVizinhos(int linhas, int colunas, int** matriz, int i, int j){
    int vizinhos = 0;
    if(i-1 >= 0 && matriz[i-1][j] == 1){
        vizinhos++;
    }
    if(i+1 < linhas && matriz[i+1][j] == 1){
        vizinhos++;
    }
    if(j-1 >= 0 && matriz[i][j-1] == 1){
        vizinhos++;
    }
    if(j+1 < colunas && matriz[i][j+1] == 1){
        vizinhos++;
    }
    if(i-1 >= 0 && j-1 >= 0 && matriz[i-1][j-1] == 1){
        vizinhos++;
    }
    if(i-1 >= 0 && j+1 < colunas && matriz[i-1][j+1] == 1){
        vizinhos++;
    }
    if(i+1 < linhas && j-1 >= 0 && matriz[i+1][j-1] == 1){
        vizinhos++;
    }
    if(i+1 < linhas && j+1 < colunas && matriz[i+1][j+1] == 1){
        vizinhos++;
    }
    return vizinhos;
}

int main(){
    int menu;
    int i = 0, j = 0, k = 0;
    tabuleiro jogo;
    
    do{
    printf("Menu de opcoes:\n\t1 - Abrir o arquivo de entrada\n\t2 - Preencher o arquivo de entrada\n\t3 - Rodar geracoes\n\tEscolha sua opcao(-1 para sair): ");
    scanf("%d", &menu);
    getchar();
    switch(menu){
        case 1:
            lerNomeArquivo(jogo.arquivo_entrada);
            FILE* entrada = fopen(jogo.arquivo_entrada, "r");
            if (entrada == NULL){
                printf("Falha ao abrir o arquivo! Voltando ao menu inicial!\n");
            break;
            }
            criarArquivoDeSaida(jogo.arquivo_entrada, jogo.arquivo_saida);
        break;
        
        case 2:
            lerMatriz(entrada, &jogo.linhas, &jogo.colunas, &jogo.geracoes, &jogo.matriz);
        break;

        case 3: 
            {int** matriz_novaGen = malloc(jogo.linhas * sizeof(int *));
            for(i = 0; i < jogo.linhas; i++){
                matriz_novaGen[i] = malloc(jogo.colunas * sizeof(int));
            }
            FILE* saida = fopen(jogo.arquivo_saida, "w");
            for (i = 0; i <= jogo.geracoes; i++){
                for(j = 0; j < jogo.linhas; j++){
                    for(k = 0; k < jogo.colunas; k++){
                        int vizinhos = contarVizinhos(jogo.linhas, jogo.colunas, jogo.matriz, j, k);
                        if(jogo.matriz[j][k] == 1){
                            if(vizinhos < 2 || vizinhos > 3){
                                matriz_novaGen[j][k] = 0;
                            }
                            else if(vizinhos == 2 || vizinhos == 3){
                                matriz_novaGen[j][k] = 1;
                            }
                        }
                        else{
                            if(vizinhos == 3){
                                matriz_novaGen[j][k] = 1;
                            }
                            else{
                                matriz_novaGen[j][k] = 0;
                            }
                        }
                    }
                }
                fprintf(saida, "Geracao %d:\n", i);
                for(j = 0; j < jogo.linhas; j++){
                    for(k = 0; k < jogo.colunas; k++){
                        if(i == 0){
                            jogo.matriz[j][k] == 0 ? fprintf(saida, "%s ", ".") : fprintf(saida, "%s ", "0");
                        }
                        else{
                            jogo.matriz[j][k] = matriz_novaGen[j][k];
                            jogo.matriz[j][k] == 0 ? fprintf(saida, "%s ", ".") : fprintf(saida, "%s ", "0");
                        }
                    }
                    fprintf(saida, "\n");
                }
            }
            fclose(saida);
        for (i = 0; i < jogo.linhas; i++) {
        free(matriz_novaGen[i]);
        }
        free(matriz_novaGen);
        break;
    }
        default:
        break;
    }
    } while(menu != -1);
}