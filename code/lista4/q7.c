#include <stdio.h>

int main()
{
    float vetor[10];
    int qtdNegativos = 0;
    float soma = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("Informe um elemento para a posicao %d do vetor:  ", i);
        scanf("%f", &vetor[i]);

        if (vetor[i] < 0)
        {
            qtdNegativos++;
        }
        else
        {
            soma += vetor[i];
        }
    }

    printf("\nQuantidade de numeros negativos: %d\n", qtdNegativos);
    printf("Soma dos numeros positivos: %.2f", soma);
    printf("\n");
}