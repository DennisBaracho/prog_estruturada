// Declare duas variáveis inteiras que receba dois valores DIFERENTES do usuário 
// (TRATAMENTO  DE  ERRO:  caso  os  valores  sejam  iguais,  solicitar  novos  valores)  e  dois 
// ponteiros para inteiros. Utilize apenas os ponteiros para trocar os conteúdos dessas variáveis 
// e  exiba  os  valores  antes  e  depois  da  troca.  NÃO  É  PERMITIDO  O  USO  DE  VARIÁVEIS 
// TEMPORÁRIAS PARA FAZER A TROCA
#include <stdio.h>
int main(){
    int x=0,y=0;
    int *p1,*p2;
    do{
        printf("algo:");
        scanf("%d %d",&x,&y);
    }while(x==y);
    p1=&x;
    p2=&y;
    printf("%d,%d\n",x,y);
    *p1=*p1+*p2;
    *p2=*p1-*p2;
    *p1=*p1-*p2;
    printf("%d,%d",x,y);
}