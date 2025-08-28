/**************************************************************************************** 
Trabalho Computacional - Programação Estruturada/Programação II - 2025/1 
Dennis Francisco Guimarães de Oliveira Baracho
****************************************************************************************/ 

#include <stdio.h>
#include <stdlib.h>

/* Struct que sera utilizada, tabuleiro do jogo contendo o nome do arquivo de entrada,
nome do arquivo de saida, numero de colunas, numero de linhas, numero de geracoes e a matriz principal. */
typedef struct{
    char arquivo_entrada[200];
    char arquivo_saida[200];
    int n_colunas;
    int n_linhas;
    int n_geracoes;
    int **matriz;
} tabuleiro;

// Prototipando as funcoes do programa.
void lerNomeArquivo(tabuleiro*jogo);
void criarArquivoDeSaida(tabuleiro*jogo);
int** alocarMatriz(tabuleiro*jogo);
void incorporarValores(FILE* entrada, tabuleiro*jogo);
void rodarGeracoes(FILE* saida, tabuleiro*jogo, int **matriz_temp);
int contarVizinhos(tabuleiro*jogo, int i, int j);
void analisarEstado(tabuleiro*jogo, int** matriz_temp, int vizinhos, int i, int j);
void imprimirMatriz(FILE* saida, tabuleiro*jogo, int** matriz_temp, int i);
void liberarMatriz(int*** matriz, tabuleiro*jogo);

int main(){
    // Valor da opcao escolhida pelo usuario.
    int menu; 
    // Inicializando a struct.
    tabuleiro jogo; 
    // Inicializando arquivos como null para tratamento de erro ao abrir.
    FILE* entrada = NULL; 
    FILE* saida = NULL;
    // Exibe o menu de opcoes enquanto nao receber -1.
    do{
        // Printando o menu de opcoes e recebendo a opcao escolhida
        printf("Menu de opcoes:\n\t1 - Abrir o arquivo de entrada\n\t2 - Preencher o arquivo de entrada\n\t3 - Rodar n_geracoes\n\tEscolha sua opcao(-1 para sair): ");
        scanf("%d", &menu);
        // Eliminando o "\n" que surge ao fim do inteiro recebido no scanf.
        getchar();
        switch(menu){
            // Abre o arquivo de entrada e cria o nome do arquivo de saida.
            case 1:
                // Le o nome do arquivo e checa se ele realmente existe no diretorio.
                lerNomeArquivo(&jogo);
                entrada = fopen(jogo.arquivo_entrada, "r");
                if (entrada == NULL){
                    printf("\tFalha ao abrir o arquivo! Voltando ao menu inicial!\n\n");
                    break;
                }
                // Caso o arquivo exista, cria o nome do arquivo de saida dentro da struct, chamado "<nomeinserido>_out.txt".
                criarArquivoDeSaida(&jogo);
                printf("\tArquivo de entrada aberto e arquivo de saida criado!\n\n");
                break;
        
            // Preenche o arquivo de entrada
            case 2:
                if(entrada != NULL){
                    // Le a primeira linha, que contem n_linhas, n_colunas e n_geracoes da partida.
                    fscanf(entrada, "%d %d %d", &jogo.n_linhas, &jogo.n_colunas, &jogo.n_geracoes);
                    // Aloca-se espaco na memoria para a matriz do jogo, a depender do numero de n_linhas e n_colunas.
                    jogo.matriz = alocarMatriz(&jogo);
                    // Por fim, os valores presente no arquivo sao incorporados para dentro da matriz do jogo.
                    incorporarValores(entrada, &jogo);
                    printf("\tArquivo de entrada preenchido.\n\n");
                }
                else printf("\tNao ha arquivo de entrada a ser lido. Retornando ao menu inicial.\n\n");
                break;
            
            // Roda as n_geracoes e imprime elas dentro do arquivo de saida.
            case 3: 
                if(entrada != NULL){
                    // Cria uma matriz temporaria e aloca seu espaco na memoria.
                    int** matriz_novaGen = alocarMatriz(&jogo);
                    // Abre o arquivo de saida, caso nao exista, volta ao menu inicial.
                    saida = fopen(jogo.arquivo_saida, "w");
                    if (saida == NULL){
                        printf("\tFalha ao abrir o arquivo de saida! Voltando ao menu inicial!\n\n");
                        break;
                    }
                    // Roda as n_geracoes, inserindo-as no menu de saida.
                    rodarGeracoes(saida, &jogo, matriz_novaGen);
                    // Fecha o arquivo de saida.
                    fclose(saida);
                    // Libera o espaco alocado para a matriz temporaria
                    liberarMatriz(&matriz_novaGen, &jogo);
                    printf("\tArquivo de saida preenchido com as novas n_geracoes.\n\n");
                }
                else printf("\tNao ha arquivo de entrada a ser lido. Retornando ao menu inicial.\n\n");
                break;

            default:
                // Caso o usuario insira -1, encerra o jogo. Caso insira um valor nao esperado, volta ao menu inicial.
                if(menu == -1) printf("\tJogo encerrado.\n");
                else printf("\tInsira uma das entradas previstas no menu.\n\n");
                break;
        }
    } while(menu != -1);
    // Libera o espaco alocado para a matriz do jogo.
    liberarMatriz(&jogo.matriz, &jogo);
    // Caso entrada e saida existam, fecha os arquivos no programa.
    if (entrada != NULL) fclose(entrada);
    if (saida != NULL) fclose(saida);
}

// Blocos de codigo das funcoes utilizadas no programa:
void lerNomeArquivo(tabuleiro*jogo){
    int i = 0;
    printf("Digite o nome do arquivo de entrada: ");
    // Recebe o nome do arquivo de entrada.
    fgets(jogo->arquivo_entrada, 50, stdin);
    // Remove '\n' do nome do arquivo de entrada.
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
    // Passa por todos os caracteres do nome do arquivo de entrada, encerrando caso encontre '\n' e '\0'
    for(i = 0; jogo->arquivo_entrada[i] != '\n' && jogo->arquivo_entrada[i] != '\0'; i++){
        // Caso o caractere seja '.', comeca a escrever o sufixo '_out' no lugar, inserindo o ponto depois disso.
        if(jogo->arquivo_entrada[i] == '.'){
            for(k = 0; k < 4; k++){
                jogo->arquivo_saida[j] = sufixo[k];
                j++;
            }
            jogo->arquivo_saida[j] = '.';
            j++;
        }
        // Caso nao seja '.', copia o nome do arquivo de entrada para o nome do arquivo de saida.
        else{
            jogo->arquivo_saida[j] = jogo->arquivo_entrada[i];
            j++;
        }
    }
    // Por fim, adiciona '\0', garantindo que o nome do arquivo de saida seja uma string valida.
    jogo->arquivo_saida[j] = '\0';
}

void incorporarValores(FILE* entrada, tabuleiro *jogo){
    // Valor da atual celula lida arquivo.
    char valorLido;
    // Valor a ser incorporado na matriz na matriz principal.
    int valorIncorporado = 0;
    int linha, coluna; 
    /* Lê os valores presentes no arquivo. 
       Caso seja '.', ou morta, insere 0 em matriz[linha][coluna]. 
       Caso seja '0', ou viva, insere 1 em matriz[linha][coluna]. */
    for(linha = 0; linha < jogo->n_linhas; linha++){
        for(coluna = 0; coluna < jogo->n_colunas; coluna++){
            fscanf(entrada, " %c", &valorLido);
            if(valorLido == '.'){
                valorIncorporado = 0;
            }
            else if(valorLido == '0'){
                valorIncorporado = 1;
            }
            else{
                printf("\tSeu arquivo de entrada nao eh valido. Encerrando o programa.\n");
                exit(1);
            }
            (jogo->matriz)[linha][coluna] = valorIncorporado;  
        }
    }
}

int** alocarMatriz(tabuleiro*jogo){
    // Cria a matriz de inteiros e aloca espaco para n_linhas e n_colunas.
    int** matriz = malloc(jogo->n_linhas * sizeof(int *));
    for(int i = 0; i < jogo->n_linhas; i++){
        (matriz)[i] = malloc(jogo->n_colunas * sizeof(int));
    }
    return matriz;
}

int contarVizinhos(tabuleiro *jogo, int linha, int coluna){
    int vizinhos = 0;
    // Verifica se pode existir uma casa vizinha. Caso exista celula vizinha e essa celula tenha uma celula viva, adiciona 1 a contagem de vizinhos.
    // Verifica a celula imediatamente a esquerda.
    if(linha-1 >= 0 && jogo->matriz[linha-1][coluna] == 1){
        vizinhos++;
    }
    // Verifica a celula imediatamente a direita.
    if(linha+1 < jogo->n_linhas && jogo->matriz[linha+1][coluna] == 1){
        vizinhos++;
    }
    // Verifica a celula imediatamente abaixo.
    if(coluna-1 >= 0 && jogo->matriz[linha][coluna-1] == 1){
        vizinhos++;
    }
    // Verifica a celula imediatamente acima.
    if(coluna+1 < jogo->n_colunas && jogo->matriz[linha][coluna+1] == 1){
        vizinhos++;
    }
    // Verifica a celula no canto esquerdo inferior.
    if(linha-1 >= 0 && coluna-1 >= 0 && jogo->matriz[linha-1][coluna-1] == 1){
        vizinhos++;
    }
    // Verifica a celula no canto esquerdo superior.
    if(linha-1 >= 0 && coluna+1 < jogo->n_colunas && jogo->matriz[linha-1][coluna+1] == 1){
        vizinhos++;
    }
    // Verifica a celula no canto direito inferior.
    if(linha+1 < jogo->n_linhas && coluna-1 >= 0 && jogo->matriz[linha+1][coluna-1] == 1){
        vizinhos++;
    }
    // Verifica a celula no canto direito superior.
    if(linha+1 < jogo->n_linhas && coluna+1 < jogo->n_colunas && jogo->matriz[linha+1][coluna+1] == 1){
        vizinhos++;
    }
    // Retorna o numero de vizinhos da celula.
    return vizinhos;
}


void analisarEstado(tabuleiro*jogo, int** matriz_temp, int vizinhos, int linha, int coluna){
    // Analisa o estado de cada celula de acordo com as regras do jogo.
    // Apos a analise, armazena o novo estado em uma matriz temporaria.
    // Caso a celula esteja viva...
    if(jogo->matriz[linha][coluna] == 1){
        // E tenha menos de 2 ou mais que 3 vizinhos, ela morre.
        if(vizinhos < 2 || vizinhos > 3){
            matriz_temp[linha][coluna] = 0;
        }
        // E tenha 2 ou 3 vizinhos, segue viva.
        else if(vizinhos == 2 || vizinhos == 3){
            matriz_temp[linha][coluna] = 1;
        }
    }
    // Caso a celula esteja morta...
    else{
        // E tenha 3 vizinhos, ela se torna viva.
        if(vizinhos == 3){
            matriz_temp[linha][coluna] = 1;
        }
        // Do contrario, segue morta.
        else{
            matriz_temp[linha][coluna] = 0;
        }
    }
}

void imprimirMatriz(FILE* saida, tabuleiro*jogo, int** matriz_temp, int geracao){
    // Imprime "Geracao" e o numero da geracao.
    fprintf(saida, "Geracao %d:\n", geracao);
    // Percorre a matriz.
    for(int linha = 0; linha < jogo->n_linhas; linha++){
        for(int coluna = 0; coluna < jogo->n_colunas; coluna++){
            // Caso a geracao seja diferente de zero, copia o valor da matriz temporaria para a principal. A copia nao acontece para a geracao 0, pois suas informacoes ja estao na matriz principal.
            if(geracao != 0){
                jogo->matriz[linha][coluna] = matriz_temp[linha][coluna];
            }
            // Imprime o valor da celula no arquivo de saida, caso seja 0, converte na string '.' e imprime '. '. Caso seja 1, converte na string '0' e imprime '0 '.
            jogo->matriz[linha][coluna] == 0 ? fprintf(saida, "%s ", ".") : fprintf(saida, "%s ", "0");
        }
        fprintf(saida, "\n");
    }
}

void liberarMatriz(int*** matriz, tabuleiro*jogo){
    // Libera a memoria alocada para a matriz torna o ponteiro apontado para a matriz nulo.
    for (int linha = 0; linha < jogo->n_linhas; linha++) {
        free((*matriz)[linha]);
    }
    free(*matriz);
    *matriz = NULL;
}

void rodarGeracoes(FILE* saida, tabuleiro *jogo, int **matriz_temp){
    // Percorre todas as geracoes do jogo.
    for (int geracao = 0; geracao <= jogo->n_geracoes; geracao++){
        for(int linha = 0; linha < jogo->n_linhas; linha++){
            for(int coluna = 0; coluna < jogo->n_colunas; coluna++){
                // Conta o numero de vizinhos vivos da celula atual.
                int vizinhos = contarVizinhos(jogo, linha, coluna);
                // Atualiza o estado da celula na matriz temporaria.
                analisarEstado(jogo, matriz_temp, vizinhos, linha, coluna);
            }
        }
        // Copia os valores da matriz temporaria para a matriz principal, entao imprime o estado atual da matriz principal no arquivo de saida
        imprimirMatriz(saida, jogo, matriz_temp, geracao);
    }
}
