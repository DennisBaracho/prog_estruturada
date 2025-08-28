// 6. Crie um programa que compara duas strings (não use a função strcmp)

#include <stdio.h>

int main(){
    char STR_1[20];
    char STR_2[20];
    int cont1 = 0;
    int cont2 = 0;
    int letras_iguais = 0;

    printf("Digite a primeira string: ");
    fgets(STR_1, 20, stdin);
    printf("Digite a segunda string: ");
    fgets(STR_2, 20, stdin);
    for(int i = 0; STR_1[i] != '\0'; i++){
        if(STR_1[i] != '\n'){
            cont1++;
        }
    }

    for(int i = 0; STR_2[i] != '\0'; i++){
        if(STR_2[i] != '\n'){
            cont2++;
        }
    }

    if(cont1 != cont2){
        printf("As duas strings tem tamanhos diferentes!");
    }
    else{
        for(int i = 0; i < cont1; i++){
            if(STR_1[i] != STR_2[i]){
                printf("As strings sao diferentes!");
                break;
            }
            else{
                letras_iguais++;
            }
        }
        if (letras_iguais == cont1){
            printf("As strings sao identicas!");
        }
    }
}