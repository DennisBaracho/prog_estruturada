#include <stdio.h>
int main()
{
    int vetor[7];
    int multi2[7];
    int multi3[7];
    int multi2e3[7];
    int qtdMulti2 = 0;
    int qtdMulti3 = 0;
    int qtdMulti2e3 = 0;
    for (int i = 0; i < 7; i++)
    {
        printf("Informe um elemento para a posicao %d do vetor:  ", i);
        scanf("%d", &vetor[i]);
    }
    printf("\n");

    for (int i = 0; i < 7; i++)
    {
        if ((vetor[i] % 2 == 0) && (vetor[i] % 3 == 0))
        {
            multi2e3[qtdMulti2e3] = vetor[i];
            qtdMulti2e3++;

            multi2[qtdMulti2] = vetor[i];
            qtdMulti2++;

            multi3[qtdMulti3] = vetor[i];
            qtdMulti3++;
        }
        else
        {
            if (vetor[i] % 2 == 0)
            {
                multi2[qtdMulti2] = vetor[i];
                qtdMulti2++;
            }
            else
            {
                if (vetor[i] % 3 == 0)
                {
                    multi3[qtdMulti3] = vetor[i];
                    qtdMulti3++;
                }
            }
        }
    }

    printf("Elementos multiplos de 2 no vetor: ");
    for (int i = 0; i < qtdMulti2; i++)
    {
        printf("[%d] ", multi2[i]);
    }

    printf("\nElementos multiplos de 3 no vetor: ");
    for (int i = 0; i < qtdMulti3; i++)
    {
        printf("[%d] ", multi3[i]);
    }

    printf("\nElementos multiplos de 2 e 3 no vetor: ");
    for (int i = 0; i < qtdMulti2e3; i++)
    {
        printf("[%d] ", multi2e3[i]);
    }
}