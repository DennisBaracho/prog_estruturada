#include <stdio.h>

int main()
{
    int vet[8];
    int cont = 1;
    for (int i = 0; i <= 8; i++)
    {
        printf("Informe um elemento para a posicao %d do vetor:  ", i);
        scanf("%d", &vet[i]);
    }

    for (int i = 0; i < 8; i++)
    {
        cont = 1;
        for (int j = 2; j <= vet[i]; j++)
        {
            if (vet[i] % j == 0)
            {
                cont++;
            }
        }
        if (cont == 2)
        {
            printf("Elemento primo encontrado: %d. Posicao no vetor: %d\n", vet[i], i);
        }
    }
}