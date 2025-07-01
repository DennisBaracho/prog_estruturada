// 39. Foi feita uma pesquisa entre os habitantes de uma região. Foram coletados os dados de idade,
// sexo (‘M’ ou ‘F’) e salário. Faça um algoritmo que informe:
// a. A média de salário do grupo;
// b. Maior e menor idade do grupo;
// c. Quantidade de mulheres com salário até R$1000,00.

#include <stdio.h>

int main()
{
    int idade, maior_idade, menor_idade, pessoas, f_milreais, primeira_exec;
    float soma, salario, media;
    char sexo;

    while (salario != -1)
    {
        printf("Digite o salario: ");
        scanf("%f", &salario);
        if (salario == -1)
        {
            break;
        }
        soma += salario;

        printf("Digite o sexo, 'M' ou 'F': ");
        scanf(" %c", &sexo);
        printf("Digite a idade: ");
        scanf("%d", &idade);

        if (primeira_exec == 1)
        {
            maior_idade = idade;
            menor_idade = idade;
            primeira_exec = 0;
        }
        else
        {
            if (idade <= menor_idade)
            {
                menor_idade = idade;
            }
            if (idade >= maior_idade)
            {
                maior_idade = idade;
            }
        }

        if ((sexo == 'F') && (salario <= 1000.00))
        {
            f_milreais++;
        }
        pessoas++;
    }
    media = soma / pessoas;
    printf("\nMedia de salario do grupo: %.2f\n", media);
    printf("Maior idade do grupo: %d\n", maior_idade);
    printf("Menor idade do grupo: %d\n", menor_idade);
    printf("Mulheres com salario de ate mil reais: %d\n", f_milreais);
}