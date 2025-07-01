#include <stdio.h>
#include <math.h>

int main()
{
    float angulo, seno = 0;
    int n = 0;
    while ((n <= 1) || (n % 2 == 0))
    {
        printf("Digite um valor impar positivo para n: ");
        scanf("%d", &n);
    }

    printf("Digite o valor do angulo: ");
    scanf("%f", &angulo);
    seno = angulo;
    int sinal = -1;
    for (int i = 3; i <= n; i += 2)
    {
        float potencia = 1;
        for (int j = 1; j <= i; j++)
        {
            potencia *= angulo;
        }
        float fatorial = 1;
        for (int j = 1; j <= i; j++)
        {
            fatorial *= j;
        }
        seno += sinal * (potencia / fatorial);
        sinal *= -1;
    }
    printf("%f", seno);
}