#include <stdio.h>

int main()
{
    float vetor[10];
    float maior_valor = 0;
    float divisao = 1;

    for (int i = 0; i < 10; i++)
    {
        printf("Informe um elemento para a posicao %d do vetor:  ", i);
        scanf("%f", &vetor[i]);

        if (i == 0 || maior_valor < vetor[i])
        {
            maior_valor = vetor[i];
        }
    }
    printf("\n--- Elementos do vetor depois dos calculos ---\n");
    for (int i = 0; i < 10; i++)
    {
        divisao = vetor[i] / maior_valor;
        printf("[%.2f] ", divisao);
    }
    printf("\n");
}