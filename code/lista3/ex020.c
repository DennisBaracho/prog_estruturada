#include <stdio.h>
int main()
{
    float cos = 1;
    float alpha;
    int sinal = -1;
    scanf("%f", &alpha);

    for (int i = 0; i < 40; i++)
    {
        float potencia = 1;
        for (int j = 1; j < i; j += 2)
        {
            potencia *= alpha;
        }
        float fatorial = 1;
        for (int j = 1; j < i; j += 2)
        {
            fatorial *= j;
        }

        cos += sinal * (potencia / fatorial);
        sinal *= -1;
    }
    printf("%f", cos);
}