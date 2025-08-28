// Leia duas matrizes 3 x 3 e faça uma substituição entre a diagonal inferior da primeira com a
// diagonal superior da segunda.

#include <stdio.h>
 
int main(){
    int M1[3][3];
    int M2[3][3];

    for(int lin = 0; lin < 3; lin++){
        for(int col = 0; col < 3; col++){
            printf("Digite o elemento M1[%d][%d]: ", lin + 1, col + 1);
            scanf("%d", &M1[lin][col]);
        }
    }

    for(int lin = 0; lin < 3; lin++){
        for(int col = 0; col < 3; col++){
            printf("Digite o elemento M2[%d][%d]: ", lin + 1, col + 1);
            scanf("%d", &M2[lin][col]);
        }
    }

    printf("\n\nMatrizes originais: ");
    printf("\n\nMatriz M1: \n");
    for(int lin = 0; lin < 3; lin++){
        for(int col = 0; col < 3; col++){
            printf("%d\t", M1[lin][col]);
        }
        printf("\n");
    }

    printf("\n\nMatriz M2: \n");
    for(int lin = 0; lin < 3; lin++){
        for(int col = 0; col < 3; col++){
            printf("%d\t", M2[lin][col]);
        }
        printf("\n");
    }

    for(int lin = 0; lin < 3; lin++){
        for(int col = 0; col < 3; col++){
            if(lin != col){
                M1[lin][col] = M2[col][lin];
            }
        }
    }

    printf("\n\nMatriz M1 apos alteracoes: \n");
    for(int lin = 0; lin < 3; lin++){
        for(int col = 0; col < 3; col++){
            printf("%d\t", M1[lin][col]);
        }
        printf("\n");
    }

    printf("\n\nMatriz M2 apos alteracoes: \n");
    for(int lin = 0; lin < 3; lin++){
        for(int col = 0; col < 3; col++){
            printf("%d\t", M2[lin][col]);
        }
        printf("\n");
    }
}