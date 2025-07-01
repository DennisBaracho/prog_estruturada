#include <stdio.h>
int main()
{
    float valor[10];
    float valor_total = 0;
    float valor_geral = 0;
    float comissao = 0;
    int mais_vendido = 0;
    int quantidade[10];
    for (int i = 0; i < 5; i++)
    {
        printf("\n----------------- Produto %d -----------------", (i + 1));
        printf("\nInforme o valor unitario do produto....: ");
        scanf(" %f", &valor[i]);
        printf("Informe a quantidade vendida do produto: ");
        scanf(" %d", &quantidade[i]);
        valor_total = valor[i] * quantidade[i];
        if ((i == 0) || quantidade[i] > mais_vendido)
        {
            mais_vendido = i;
        }
        valor_geral += valor_total;
    }
    comissao = valor_geral * 0.05;
    printf("----------------- Relatorio -----------------\n\n");
    for (int i = 0; i < 5; i++)
    {
        valor_total = quantidade[i] * valor[i];
        printf("Produto %d. Quantidade: %d. Valor unitario: R$ %.2f. Valor total: R$ %.2f\n", i, quantidade[i], valor[i], valor_total);
    }
    printf("\nValor Geral das Vendas......: R$ %.2f\n", valor_geral);
    printf("Valor da Comissao...........: R$ %.2f\n", comissao);
    printf("Valor do objeto mais vendido: R$ %.2f. Posicao no vetor: %d\n", valor[mais_vendido], mais_vendido);
}