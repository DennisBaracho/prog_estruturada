// Escreva um algoritmo que lê uma matriz M[5,5]. Substitua, a seguir, todos os valores negativos da
// matriz pelo seu módulo. Exemplo: substitua -2 por 2, -16 por 16, assim por diante.

#include <stdio.h>
int main(){
    int M[5][5];

    for(int lin = 0; lin < 5; lin++){
        for(int col = 0; col < 5; col++){
            printf("Digite o elemento M[%d][%d]: ", lin + 1, col + 1);
            scanf("%d", &M[lin][col]);
            if(M[lin][col] < 0){
                M[lin][col] *= -1;
            }
        }
    }
    printf("\n\t --- Matriz M ---\n");

    for(int lin = 0; lin < 5; lin++){
        for(int col = 0; col < 5; col++){
            printf("%d\t", M[lin][col]);
        }
        printf("\n");
    }
}