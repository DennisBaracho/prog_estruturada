#include <stdio.h>

int main()
{
    int sexo, olhos, cabelos, idade = 0;
    int masculino, feminino, individuos = 0;
    int maior_idade = -999;
    while (idade != -1)
    {
        printf("\nSexo: Digite 1 para Masculino e 2 para Feminino: ");
        scanf("%d", &sexo);
        printf("Cor dos olhos: Digite 1 para azul, 2 para verde, 3 para castanho: ");
        scanf("%d", &olhos);
        printf("Cor dos cabelos: Digite 1 para louro, 2 para castanho, 3 para preto: ");
        scanf("%d", &cabelos);
        printf("Digite sua idade: ");
        scanf("%d", &idade);
        if (idade >= maior_idade)
        {
            maior_idade = idade;
        }
        if ((sexo == 2) && (olhos == 2) && (cabelos == 1) && (idade >= 18) && (idade <= 35))
        {
            individuos++;
        }
    }
    printf("\nA maior idade registrada foi: %d\n", maior_idade);
    printf("Pessoas do sexo feminino com olhos verdes, cabelos louros e idade entre 18 e 35 anos: %d", individuos);

}