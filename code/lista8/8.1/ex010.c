// Com um vetor de 5 inteiros, utilize um ponteiro para percorrer o array. Para cada elemento par, 
// multiplique seu valor por 2. Mostre na tela o vetor antes e depois das modificações. 
#include <stdio.h>
int main (){
    int vetor[5]={0, 1, 2, 3, 4};
    int *p;
    p=vetor;
    for(int i=0;i<5;i++){
        printf("%d",vetor[i]);
    }
    printf("\n");
    for(int i=0;i<5;i++){
        if (p[i]%2==0){
            p[i]*=2;
        }
        printf("%d",vetor[i]);
    }
}