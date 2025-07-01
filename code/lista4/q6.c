#include <stdio.h>
int main()
{
    int vetor[10];
    int iguais30[10];
    int qtdIguais30 = 0;
    for (int i = 0; i < 10; i++)
    {
        printf("Informe um elemento para a posicao %d do vetor:  ", i);
        scanf("%d", &vetor[i]);
    }
    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        if (vetor[i] == 30)
        {
            iguais30[qtdIguais30] = i;
            qtdIguais30++;
        }
    }

    printf("Posicoes dos elementos iguais a 30 no vetor: ");
    for (int i = 0; i < qtdIguais30; i++)
    {
        printf("[%d] ", iguais30[i]);
    }
}