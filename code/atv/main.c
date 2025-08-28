#include <stdio.h>

int main(){
    char STR[1000];
    char SUBSTR[1000];
    int  i=0, j=0, contem=0;
    int Tam_SUBSTR = 0;

    printf("Entre com a string principal: ");
    fgets(STR, 1000, stdin);

    printf("Entre com a sub string: ");
    fgets(SUBSTR, 1000, stdin);
    
    //Contando Tamanho das strings
    
    for (j = 0; SUBSTR[j] != '\n'; j++){
        Tam_SUBSTR++;
    }
    
    j=0;
    
    for (i=0; STR[i] != '\n' && STR[i] != '\0' ; i++){
        if (SUBSTR[j] != STR[i]){
            j = 0;
            contem = 0;
        }
        if (SUBSTR[j] == STR[i]){
            contem++;
            j++;
            if (contem == Tam_SUBSTR){
                break;
            }
        }
    }
    
    if (contem == Tam_SUBSTR){
        printf("B esta contido em A!");
    } else {
        printf("B nao esta contido em A!");
    }
}
