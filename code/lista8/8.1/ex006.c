#include <stdio.h>
#include <string.h>
// //Declare uma variável inteira, um ponteiro para inteiro e um ponteiro para ponteiro de inteiro.
// Faça  o  ponteiro  simples  apontar  para  a  variável  e  o  ponteiro  duplo  apontar  para  o  ponteiro
// simples. Mostre como acessar o valor original da variável utilizando o ponteiro duplo.
int main()
{
    int x;
    int *p, **p1;
    x = 10;
    p = &x;
    p1 = &p;
    printf("%d", x);
    printf("%d", *p);
    printf("%d", **p1);
}