// Dada uma matriz Am×n, imprimir o número de linhas e o número de colunas nulas da matriz.
// m = 4, n = 4
// | 1 0 2 3 |
// | 4 0 5 6 |
// | 0 0 0 0 |
// | 0 0 0 0 |
// Exemplo: tem 2 linhas nulas e 1 coluna nula.

#include <stdio.h>
int main(){
    int lin = 0;
    int col = 0;
    int cont = 0;
    int lNula = 0;
    int cNula = 0;

    printf("Digite o numero de linhas e colunas da matriz separados por espaco: ");
    scanf("%d %d", &lin, &col);
    int A[lin][col];

    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            printf("Digite o elemento A[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }

    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            if(A[i][j] == 0){
                cont++;
            }   
            if(cont == lin){
                lNula++;
            }
        }
        cont = 0;
    }

    for(int j = 0; j < col; j++){
        for(int i = 0; i < lin; i++){
            if(A[i][j] == 0){
                cont++;
            }   
            if(cont == col){
                cNula++;
            }
        }
        cont = 0;
    }

    printf("\n\nm = %d, n = %d\n", lin, col);
    for(int i = 0; i < lin; i++){
        for(int j = 0; j < col; j++){
            printf("%d\t", A[i][j]);
        }
        printf("\n");
    }

    printf("Tem %d linhas nulas e %d colunas nulas.", lNula, cNula);
}