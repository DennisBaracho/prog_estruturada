#include <stdio.h>
int main()
{
    int vetor1[5];
    int vetor2[5];
    int vetor_resultante[10];
    int j = 0;
    int k = 0;

    for (int i = 0; i < 5; i++)
    {
        printf("Informe um elemento para a posicao %d do vetor 1:  ", i);
        scanf("%d", &vetor1[i]);
    }
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Informe um elemento para a posicao %d do vetor 2:  ", i);
        scanf("%d", &vetor2[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            vetor_resultante[i] = vetor1[j];
            j++;
        }
        else
        {
            vetor_resultante[i] = vetor2[k];
            k++;
        }
    }
    printf("\nVetor 1: ");
    for (int i = 0; i < 5; i++)
    {
        printf("[%d] ", vetor1[i]);
    }
    printf("\nVetor 2: ");
    for (int i = 0; i < 5; i++)
    {
        printf("[%d] ", vetor2[i]);
    }
    printf("\nVetor intercalado: ");
    for (int i = 0; i < 10; i++)
    {
        printf("[%d] ", vetor_resultante[i]);
    }
}