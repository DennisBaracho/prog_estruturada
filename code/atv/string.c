#include <stdio.h>

int main(){
    char STR[1000];
    char SUBSTR[1000];
    int  i =0, j=0, contem=0;
    int  Tam_SUBSTR=0;

    printf("Entre com a string principal: ");
    fgets(STR, 1000, stdin);

    printf("Entre com a sub string: ");
    fgets(SUBSTR, 1000, stdin);

    for(j = 0; SUBSTR[j] != '\0'; j++){
        if(SUBSTR[j] == '\n'){
            SUBSTR[j] = '\0';
        }
    }

    for(j = 0; SUBSTR[j] ; j++){
        Tam_SUBSTR++;
    }

    j = 0;

    for (i=0; STR[i] != '\0'; i++){
        if(SUBSTR[j] != STR[i]){
            j=0;
        }

        if (SUBSTR[j] == STR[i]){
            j++;

            if(j == Tam_SUBSTR){
                break;
            }
        } 
    }

    if (j == Tam_SUBSTR){
        printf("B esta contido em A!");
    } else {
        printf("B nao esta contido em A!");
    }
}