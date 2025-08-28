// Faça um programa que preencha uma matriz de string com os modelos de cinco carros (exemplos
// de modelos: Fusca, Gol, Vectra, etc.). Em seguida, preencha um vetor com o consumo desses
// carros, isto é, quantos quilômetros cada um deles faz com um litro de combustível. Calcule e mostre:
// a. O modelo de carro mais econômico;
// b. Quantos litros de combustível cada um dos carros cadastrados consome para percorrer uma
// distância de 1.000 quilômetros

#include <stdio.h>

int main(){
    char mat[5][20];
    float kml[5];
    int mais_economico;
    for(int i = 0; i < 5; i++){
        printf("Digite o %do modelo de carro: ", (i+1));
        fgets(mat[i], 20, stdin);
        printf("Quantos km o carro faz com 1l? ");
        scanf("%f", &kml[i]);
        getchar();
        if(i == 0){
            mais_economico = i;
        }
        if(kml[mais_economico] < kml[i]){
            mais_economico = i;
        }

         int j = 0;
        while (mat[i][j] != '\0') {
            if (mat[i][j] == '\n') {
                mat[i][j] = '\0';
                break;
            }
            j++;
    }
}
    printf("Carro mais economico: %s\n", mat[mais_economico]);
    for(int i = 0; i < 5; i++){
        printf("%s consome %2.f litros para percorrer 1000km\n", mat[i], (1000/kml[i]));
    }
}