#include <stdio.h>
#define numerador 1
int main()
{
    float S = 1;
    int n;
    float fatorial = 1;
    printf("Digite o valor de n: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        fatorial *= i;
        S += (1/fatorial);
    }
    printf("%f", S);
}
