// 7. Leia uma matriz M[5,5] e crie 2 vetores Sl[5] e Sc[5] que contenham respectivamente as somas das linhas e das colunas de M.

#include <stdio.h>

int main(){
    int M[5][5];
    int Sl[5] = {0};
    int Sc[5] = {0};
    for(int lin = 0; lin < 5; lin++){
        for(int col = 0; col < 5; col++){
            printf("Digite o elemento M[%d][%d]: ", lin + 1, col + 1);
            scanf("%d", &M[lin][col]);
        }
    }

    for(int lin = 0; lin < 5; lin++){
        for(int col = 0; col < 5; col++){
            Sl[lin] += M[lin][col]; 
        }
    }

     for(int col = 0; col < 5; col++){
        for(int lin = 0; lin < 5; lin++){
            Sc[col] += M[lin][col]; 
        }
    }

    printf("\n");
    for(int lin = 0; lin < 5; lin++){
        for(int col = 0; col < 5; col++){
            printf("%d\t", M[lin][col]);
        }
        printf("\n");
    }

    printf("\nSl: ");
    for(int i = 0; i < 5; i++){
        printf("[%d] ", Sl[i]);
    }

    printf("\nSc: ");
    for(int i = 0; i < 5; i++){
        printf("[%d] ", Sc[i]);
    }

}