#include <stdio.h>
int main()
{
    int vetor[6];
    int pares[6];
    int impares[6];
    int qtdPares = 0;
    int qtdImpares = 0;
    for (int i = 0; i < 6; i++)
    {
        printf("Informe um elemento para a posicao %d do vetor:  ", i);
        scanf("%d", &vetor[i]);
    }
    printf("\n");

    for (int i = 0; i < 6; i++)
    {
        if (vetor[i] % 2 == 0)
        {
            pares[qtdPares] = vetor[i];
            qtdPares++;
        }
        else
        {
            impares[qtdImpares] = vetor[i];
            qtdImpares++;
        }
    }
    printf("Elementos pares do vetor: ");
    for (int i = 0; i < qtdPares; i++)
    {
        printf("[%d] ", pares[i]);
    }
    printf("Quantidade -> %d\n", qtdPares);

    printf("Elementos impares do vetor: ");
    for (int i = 0; i < qtdImpares; i++)
    {
        printf("[%d] ", impares[i]);
    }
    printf("Quantidade -> %d\n", qtdImpares);
}