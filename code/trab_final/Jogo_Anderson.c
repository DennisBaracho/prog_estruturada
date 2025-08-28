/****************************************************************************************
Trabalho Computacional - Programação Estruturada/Programação II - 2025/1
Anderson Cordeiro de Sousa
****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome_arquivo_entrada[100]; // Nome do arquivo de entrada.
    char nome_arquivo_saida[100];  // Nome do arquivo de saída.
    int num_linhas;  // Número de linhas.
    int num_colunas; // Número de colunas .
    int num_geracoes; // Número de gerações.
    char **matriz;    // Matriz bidimensional.
} tabuleiro;

// Funções
int menu(); // Parte inicial do código, primeiro contato direto do usuário com o programa
int abrir_arquivo_entrada(tabuleiro *jogo); // Abrir o arquivo que já esteja na máquina
int preencher_tabuleiro(tabuleiro *jogo); // Verifica se um arquivo foi aberto e começa a preencher o tabuleiro
int rodar_geracoes(tabuleiro *jogo); // É o processo mais difícil, de rodar as próximas gerações
void criar_nome_arquivo_saida(const char *entrada, char *saida); //Cria o arquivo de saída com base no arquivo de entrada
void alocar_matriz(tabuleiro *jogo); // Alocação dinâmica de matriz (armazenar um espaço na memória, esperando receber algo)
void liberar_matriz(tabuleiro *jogo); // Liberar memória alocada que já não será mais utilizada naquele momento
int contar_vizinhos_vivos(tabuleiro *jogo, int linha, int coluna); //Fazer contagem sobre células mortas e vivas, apenas dados
void calcular_proxima_geracao(tabuleiro *jogo, char **nova_matriz); //Determinar quais serão os pontos de novas mortes e vida
void salvar_geracao(FILE *arquivo, tabuleiro *jogo, int num_geracao); //Salvar mudanças geradas pela nova geração

// Função principal
int main() {
    tabuleiro jogo; //jogo se torna uma variável do tipo tabuleiro da struct
    int opcao; // Variável que será utilizada no comando do-while
    
    do {
        opcao = menu(); //variável opção é enviado para função menu
        switch (opcao) {
            case 1: // Usuário digita 1, é direcionado para abrir um arquivo
                abrir_arquivo_entrada(&jogo);
                break;
            case 2: // Usuário digita 2, é esperado que já tenha adicionado um arquivo para poder preenchê-lo
                preencher_tabuleiro(&jogo);
                break;
            case 3:
                rodar_geracoes(&jogo); // Usuário digita 3, principal objetivo dessa função é mostrar todas as gerações no arquivo de saída
                break;
            case -1: // Usuário digita -1, comando para encerrar código
                printf("Saindo do programa!\n");
                break;
            default: // Usuário digitou qualquer coisa que não se encaixe em nenhum opção
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != -1); // Esse looping se manterá até que o usuário queira sair, digitando -1.
    
    // Liberar memória antes de sair
    liberar_matriz(&jogo);
    
    return 0;
}

// Função para exibir o menu e retornar a opção escolhida
int menu() {
    int opcao;
    printf("\nMenu de opcoes:\n");
    printf("1 - Abrir arquivo de entrada\n");
    printf("2 - Preencher tabuleiro de entrada\n");
    printf("3 - Rodar geracoes\n");
    printf("Escolha sua opcao(-1 para sair): ");
    scanf("%d", &opcao);
    return opcao;
}

// Função para criar o nome do arquivo de saída baseado no arquivo de entrada
void criar_nome_arquivo_saida(const char *entrada, char *saida) {
    char temp[100]; //Criando vetor temporário
    strcpy(temp, entrada); //Fazendo cópia da variável entrada para temp.
    
    // Encontrar a última ocorrência de '.'
    char *ponto = strrchr(temp, '.');
    if (ponto != NULL) {
        *ponto = '\0'; // Remove a extensão
    }

    // Criando o nome de saída com sufixo "_out.txt".
    sprintf(saida, "%s_out.txt", temp);
}

// Função para alocar dinamicamente a matriz do tabuleiro
void alocar_matriz(tabuleiro *jogo) {
    jogo->matriz = (char**)malloc(jogo->num_linhas * sizeof(char*)); //Fazendo alocação dinâmica de **ponteiro(char) para *ponteiro(char)
    for (int i = 0; i < jogo->num_linhas; i++) {
        jogo->matriz[i] = (char*)malloc(jogo->num_colunas * sizeof(char)); //Fazendo alocação dinâmica de *ponteiro(char) para char
    }
}

// Função para liberar a memória alocada para a matriz
void liberar_matriz(tabuleiro *jogo) {
    if (jogo->matriz != NULL) { //Verificando se o ponteiro está apontando para algum lugar
        for (int i = 0; i < jogo->num_linhas; i++) {
            free(jogo->matriz[i]);
        }
        free(jogo->matriz);
        jogo->matriz = NULL;
    }
}

// Opção 1: Abrir arquivo de entrada
int abrir_arquivo_entrada(tabuleiro *jogo) {
    FILE *arquivo;
    
    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", jogo->nome_arquivo_entrada); //Momento em que ponteiro do nome do arquivo recebe o nome digitado pelo usuário
    
    // Tenta abrir o arquivo
    arquivo = fopen(jogo->nome_arquivo_entrada, "r");
    if (arquivo == NULL) { //Verificando se o ponteiro está apontando para algum lugar
        printf("Falha ao abrir o arquivo! Voltando ao menu inicial!\n");
        return 0;
    }
    
    fclose(arquivo);
    
    // Criar nome do arquivo de saída
    criar_nome_arquivo_saida(jogo->nome_arquivo_entrada, jogo->nome_arquivo_saida);
    
    printf("Arquivo aberto com sucesso!\n");
    printf("Arquivo de saida sera: %s\n", jogo->nome_arquivo_saida);
    
    return 1;
}

// Opção 2: Preencher o tabuleiro de entrada
int preencher_tabuleiro(tabuleiro *jogo) {
    FILE *arquivo;
    
    // Verificar se um arquivo foi aberto
    if (strlen(jogo->nome_arquivo_entrada) == 0) {
        printf("Erro: Nenhum arquivo de entrada foi aberto!\n");
        return 0;
    }
    

    //Tentando abrir o arquivo de entrada para leitura
    arquivo = fopen(jogo->nome_arquivo_entrada, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de entrada!\n");
        return 0;
    }
    
    // Ler primeira linha, linhas, colunas e gerações
    fscanf(arquivo, "%d %d %d", &jogo->num_linhas, &jogo->num_colunas, &jogo->num_geracoes);
    
    // Alocar matriz dinamicamente
    alocar_matriz(jogo);
    
    // Ler o estado inicial do tabuleiro
    for (int i = 0; i < jogo->num_linhas; i++) {
        for (int j = 0; j < jogo->num_colunas; j++) {
            char celula;
            fscanf(arquivo, " %c", &celula); //Verifica o tipo de arquivo que está sendo tratado
            jogo->matriz[i][j] = celula;
        }
    }
    
    fclose(arquivo); //Fechand arquivo de entrada
    
    printf("Tabuleiro preenchido com sucesso!\n"); //Mensagem que garante que foi bem sucedido
    printf("Dimensoes da Matriz: %dx%d, Geracoes: %d\n", jogo->num_linhas, jogo->num_colunas, jogo->num_geracoes);
    
    return 1;
}

// Função para contar vizinhos vivos de uma célula
int contar_vizinhos_vivos(tabuleiro *jogo, int linha, int coluna) {
    int contador = 0;

    // Checa cada uma das 8 posições vizinhas manualmente

    // Vizinho de Cima_Esquerda
    if (linha > 0 && coluna > 0 && jogo->matriz[linha - 1][coluna - 1] == '0') contador++;
    // Vizinho de Cima
    if (linha > 0 && jogo->matriz[linha - 1][coluna] == '0') contador++;
    // Vizinho de Cima_Direita
    if (linha > 0 && coluna < jogo->num_colunas - 1 && jogo->matriz[linha - 1][coluna + 1] == '0') contador++;
    // Vizinho da Esquerda
    if (coluna > 0 && jogo->matriz[linha][coluna - 1] == '0') contador++;
    // Vizinho da Direita
    if (coluna < jogo->num_colunas - 1 && jogo->matriz[linha][coluna + 1] == '0') contador++;
    // Vizinho de Baixo_Esquerda
    if (linha < jogo->num_linhas - 1 && coluna > 0 && jogo->matriz[linha + 1][coluna - 1] == '0') contador++;
    // Vizinho de Baixo
    if (linha < jogo->num_linhas - 1 && jogo->matriz[linha + 1][coluna] == '0') contador++;
    // Vizinho de BaixoDireita
    if (linha < jogo->num_linhas - 1 && coluna < jogo->num_colunas - 1 && jogo->matriz[linha + 1][coluna + 1] == '0') contador++;

    //Retorna o valor de contador que será extremamente útil da nossa última contagem
    return contador;
}

// Função para calcular a próxima geração
void calcular_proxima_geracao(tabuleiro *jogo, char **nova_matriz) {
    for (int i = 0; i < jogo->num_linhas; i++) { //for que percorre todas as linhas da matriz
        for (int j = 0; j < jogo->num_colunas; j++) { //for que percorre todas as colunas da matriz
            int vizinhos_vivos = contar_vizinhos_vivos(jogo, i, j); // Chamada da função que mostra quantos vizinhos existem/existirão
            char celula_atual = jogo->matriz[i][j];
            
            // Aplicar regras do Jogo da Vida
            if (celula_atual == '.') { // Célula morta
                if (vizinhos_vivos == 3) {
                    nova_matriz[i][j] = '0'; // Nasce
                } else {
                    nova_matriz[i][j] = '.'; // Permanece morta
                }
            } else { // Célula viva ('0')
                if (vizinhos_vivos < 2 || vizinhos_vivos > 3) {
                    nova_matriz[i][j] = '.'; // Morre
                } else {
                    nova_matriz[i][j] = '0'; // Permanece viva
                }
            }
        }
    }
}

// Função para salvar uma geração no arquivo
void salvar_geracao(FILE *arquivo, tabuleiro *jogo, int num_geracao) {
    fprintf(arquivo, "Geracao %d:\n", num_geracao); //comando para escrever numero da geração no output do arquivo
    
    for (int i = 0; i < jogo->num_linhas; i++) { //for percorrendo todas as linhas
        for (int j = 0; j < jogo->num_colunas; j++) { // for percorrendo todas as colunas
            fprintf(arquivo, "%c ", jogo->matriz[i][j]); // print para dizer se escolha era 0 ou "."
        }
        fprintf(arquivo, "\n");
    }
}

// Opção 3: Rodar gerações
int rodar_geracoes(tabuleiro *jogo) {
    FILE *arquivo_saida;
    
    // Verificar se o tabuleiro foi preenchido
    if (jogo->matriz == NULL) {
        printf("Erro: Tabuleiro nao foi preenchido!\n");
        return 0;
    }
    
    // Abrir arquivo de saída
    arquivo_saida = fopen(jogo->nome_arquivo_saida, "w");
    if (arquivo_saida == NULL) {
        printf("Erro ao criar arquivo de saida!\n");
        return 0;
    }
    
    // Salvar geração 0 (estado inicial)
    salvar_geracao(arquivo_saida, jogo, 0);
    
    // Alocar matriz auxiliar para cálculos
    char **matriz_auxiliar = (char**)malloc(jogo->num_linhas * sizeof(char*));
    for (int i = 0; i < jogo->num_linhas; i++) {
        matriz_auxiliar[i] = (char*)malloc(jogo->num_colunas * sizeof(char));
    }
    
    // Calcular e salvar as próximas gerações
    for (int geracao = 1; geracao <= jogo->num_geracoes; geracao++) {
        // Calcular próxima geração
        calcular_proxima_geracao(jogo, matriz_auxiliar);
        
        // Copiar resultado para a matriz principal
        for (int i = 0; i < jogo->num_linhas; i++) {
            for (int j = 0; j < jogo->num_colunas; j++) {
                jogo->matriz[i][j] = matriz_auxiliar[i][j];
            }
        }
        
        // Salvar geração no arquivo
        salvar_geracao(arquivo_saida, jogo, geracao);
    }
    
    // Liberar matriz auxiliar
    for (int i = 0; i < jogo->num_linhas; i++) {
        free(matriz_auxiliar[i]);
    }
    free(matriz_auxiliar);
    
    fclose(arquivo_saida);
    
    printf("Geracoes processadas com sucesso!\n");
    printf("Resultado salvo em: %s\n", jogo->nome_arquivo_saida);
    
    return 1;
}