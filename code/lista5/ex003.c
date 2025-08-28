// Leia uma matriz M[5,5]. A seguir, ordene os elementos da matriz M e mostre como ficou a matriz
// ordenada, linha por linha.

#include <stdio.h>
int main(){
    int M[5][5];
    int temp = 0;
    int V[25];
    int i = 0;

    for(int lin = 0; lin < 5; lin++){
        for(int col = 0; col < 5; col++){
            printf("Digite o elemento M[%d][%d]: ", lin + 1, col + 1);
            scanf("%d", &M[lin][col]);
            V[i++] = M[lin][col];
        }
    }

    for(int i = 0; i < 25 - 1; i++){
        for(int j = 0; j < 25 - 1 - i; j++){
            if(V[j] > V[j + 1]){
                temp = V[j];
                V[j] = V[j+1];
                V[j+1] = temp;
            }
        }
    }

    i = 0;
    for(int lin = 0; lin < 5; lin++){
        for(int col = 0; col < 5; col++){
            M[lin][col] = V[i++];
        }
    }

    printf("\n\t Matriz ordenada \n");

    for(int lin = 0; lin < 5; lin++){
        for(int col = 0; col < 5; col++){
            printf("%d\t", M[lin][col]);
        }
        printf("\n");
    }
}