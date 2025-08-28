// Leia uma matriz 100 x 10 que se refere respostas de 10 questões de múltipla escolha, referentes a
// 100 alunos. Leia também um vetor de 10 posições contendo o gabarito de respostas que podem ser
// a, b, c ou d. Seu programa deverá comparar as respostas de cada candidato com o gabarito e emitir
// um vetor Resultado, contendo a pontuação correspondente.

#include <stdio.h>

int main(){
    char P[100][10];
    char Gabarito[10] = {'a', 'b', 'c', 'd', 'd', 'c', 'b', 'a', 'a', 'b'};
    int Resultado[100];
    int i = 0;
    int pontuacao = 0;

    for(int lin = 0; lin < 100; lin++){
        for(int col = 0; col < 10; col++){
            printf("Digite o elemento P[%d][%d]: ", lin + 1, col + 1);
            scanf(" %c", &P[lin][col]);

            if(P[lin][col] == Gabarito[col]){
                pontuacao++;
            }
        }
        Resultado[lin] = pontuacao;
        pontuacao = 0;
    }

    printf("\nResultado: ");
    for(int i = 0; i < 10; i++){
        printf("[%d]", Resultado[i]);
    }
}