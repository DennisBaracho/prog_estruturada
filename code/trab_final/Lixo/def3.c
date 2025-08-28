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

void lerNomeArquivo(tabuleiro*jogo){
    int i = 0;
    printf("Digite o nome do arquivo de entrada: ");
    fgets(jogo->arquivo_entrada, 50, stdin);
    while (jogo->arquivo_entrada[i] != '\0') {
        if (jogo->arquivo_entrada[i] == '\n') {
            jogo->arquivo_entrada[i] = '\0';
            break;
        }
        i++;
    }
}

void criarArquivoDeSaida(tabuleiro*jogo){
    int i = 0; 
    int j = 0; 
    int k = 0;
    char sufixo[4] = "_out";
    for(i = 0; jogo->arquivo_entrada[i] != '\n' && jogo->arquivo_entrada[i] != '\0'; i++){
        if(jogo->arquivo_entrada[i] == '.'){
            for(k = 0; k < 4; k++){
                jogo->arquivo_saida[j] = sufixo[k];
                j++;
            }
            jogo->arquivo_saida[j] = '.';
            j++;
        }
        else{
            jogo->arquivo_saida[j] = jogo->arquivo_entrada[i];
            j++;
        }
    }
    jogo->arquivo_saida[j] = '\0';
}

void incorporarValores(FILE* entrada, tabuleiro*jogo){
    char valorLido;
    int valorIncorporado = 0;
    int i, j; 
    for(i = 0; i < jogo->linhas; i++){
        for(j = 0; j < jogo->colunas; j++){
            // Celulas mortas convertidas em 0
            fscanf(entrada, " %c", &valorLido);
                if(valorLido == '.'){
                    valorIncorporado = 0;
                }
                // Celulas vivas convertidas em 1
                else if(valorLido == '0'){
                    valorIncorporado = 1;
                }
            (jogo->matriz)[i][j] = valorIncorporado;  
        }
    }
}

void lerMatriz(FILE* entrada, tabuleiro*jogo){
    fscanf(entrada, "%d %d %d", &jogo->linhas, &jogo->colunas, &jogo->geracoes);
}

void alocarMatriz(tabuleiro*jogo){
    jogo->matriz = (int **) malloc(jogo->linhas * sizeof(int *));
    for(int i = 0; i < jogo->linhas; i++){
        (jogo->matriz)[i] = malloc(jogo->colunas * sizeof(int));
    }
}

int contarVizinhos(tabuleiro*jogo, int i, int j){
    int vizinhos = 0;
    if(i-1 >= 0 && jogo->matriz[i-1][j] == 1){
        vizinhos++;
    }
    if(i+1 < jogo->linhas && jogo->matriz[i+1][j] == 1){
        vizinhos++;
    }
    if(j-1 >= 0 && jogo->matriz[i][j-1] == 1){
        vizinhos++;
    }
    if(j+1 < jogo->colunas && jogo->matriz[i][j+1] == 1){
        vizinhos++;
    }
    if(i-1 >= 0 && j-1 >= 0 && jogo->matriz[i-1][j-1] == 1){
        vizinhos++;
    }
    if(i-1 >= 0 && j+1 < jogo->colunas && jogo->matriz[i-1][j+1] == 1){
        vizinhos++;
    }
    if(i+1 < jogo->linhas && j-1 >= 0 && jogo->matriz[i+1][j-1] == 1){
        vizinhos++;
    }
    if(i+1 < jogo->linhas && j+1 < jogo->colunas && jogo->matriz[i+1][j+1] == 1){
        vizinhos++;
    }
    return vizinhos;
}

void analisarEstado(tabuleiro*jogo, int** matriz_temp, int vizinhos, int i, int j){
    if(jogo->matriz[i][j] == 1){
        if(vizinhos < 2 || vizinhos > 3){
            matriz_temp[i][j] = 0;
        }
        else if(vizinhos == 2 || vizinhos == 3){
            matriz_temp[i][j] = 1;
        }
    }
    else{
        if(vizinhos == 3){
            matriz_temp[i][j] = 1;
        }
        else{
            matriz_temp[i][j] = 0;
        }
    }
}

void imprimirMatriz(FILE* saida, tabuleiro*jogo, int** matriz_temp, int i){
    fprintf(saida, "Geracao %d:\n", i);
    for(int j = 0; j < jogo->linhas; j++){
        for(int k = 0; k < jogo->colunas; k++){
            if(i == 0){
                jogo->matriz[j][k] == 0 ? fprintf(saida, "%s ", ".") : fprintf(saida, "%s ", "0");
            }
            else{
                jogo->matriz[j][k] = matriz_temp[j][k];
                jogo->matriz[j][k] == 0 ? fprintf(saida, "%s ", ".") : fprintf(saida, "%s ", "0");
            }
        }
        fprintf(saida, "\n");
    }
}

void liberarMatriz(int** matriz, tabuleiro*jogo){
    for (int i = 0; i < jogo->linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void rodarGeracoes(FILE* saida, tabuleiro*jogo, int **matriz_temp){
    for (int i = 0; i <= jogo->geracoes; i++){
        for(int j = 0; j < jogo->linhas; j++){
            for(int k = 0; k < jogo->colunas; k++){
                int vizinhos = contarVizinhos(jogo, j, k);
                analisarEstado(jogo, matriz_temp, vizinhos, j, k);
            }
        }
    imprimirMatriz(saida, jogo, matriz_temp, i);
    }
}
int main(){
    int menu;
    tabuleiro jogo;
    FILE* entrada = NULL;
    FILE* saida = NULL;
    do{
        printf("Menu de opcoes:\n\t1 - Abrir o arquivo de entrada\n\t2 - Preencher o arquivo de entrada\n\t3 - Rodar geracoes\n\tEscolha sua opcao(-1 para sair): ");
        scanf("%d", &menu);
        getchar();
        switch(menu){
            case 1:
                lerNomeArquivo(&jogo);
                entrada = fopen(jogo.arquivo_entrada, "r");
                if (entrada == NULL){
                    printf("\tFalha ao abrir o arquivo! Voltando ao menu inicial!\n\n");
                break;
                }
                criarArquivoDeSaida(&jogo);
                printf("\tArquivo de entrada aberto e arquivo de saida criado!\n\n");
                break;
        
            case 2:
                if(entrada != NULL){
                    lerMatriz(entrada, &jogo);
                    alocarMatriz(&jogo);
                    incorporarValores(entrada, &jogo);
                    printf("\tArquivo de entrada preenchido.\n\n");
                }
                else{
                    printf("\tNao ha arquivo de entrada a ser lido. Retornando ao menu inicial.\n\n");
                }
                break;

            case 3: 
                if(entrada != NULL){
                    {int** matriz_novaGen = malloc(jogo.linhas * sizeof(int *));
                    for(int i = 0; i < jogo.linhas; i++){
                        matriz_novaGen[i] = malloc(jogo.colunas * sizeof(int));
                    }
                    saida = fopen(jogo.arquivo_saida, "w");
                    if (saida == NULL){
                        printf("\tFalha ao abrir o arquivo de saida! Voltando ao menu inicial!\n\n");
                        break;
                    }
                    rodarGeracoes(saida, &jogo, matriz_novaGen);
                    fclose(saida);
                    liberarMatriz(matriz_novaGen, &jogo);
                    printf("\tArquivo de saida preenchido com as novas geracoes.\n\n");
                    }
                }
                else{
                    printf("\tNao ha arquivo de entrada a ser lido. Retornando ao menu inicial.\n\n");
                }
                break;
        default:
            if(menu == -1){
                printf("\tJogo encerrado.\n");
            }
            else{
            printf("\tInsira uma das entradas previstas no menu.\n\n");
            }
            break;
        }
    } while(menu != -1);
}