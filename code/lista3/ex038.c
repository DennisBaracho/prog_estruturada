// 38. Escreva um programa que leia um conjunto de 50 informações contendo, cada uma delas, a altura
// e o sexo de uma pessoa (‘M’ - masculino ou ‘F’ - feminino), calcule e mostre o seguinte:
// a. A maior e a menor altura da turma;
// b. A média da altura das mulheres.
// c. A média da altura da turma
#include <stdio.h>
int main()
{
    int primeira_exec = 1;
    float n_alunos, n_mulheres;
    char sexo;
    float altura, maior_altura, menor_altura, media_mulheres, media_turma, soma_turma, soma_mulheres;
    for (int i = 0; i <= 50; i++)
    {
        printf("Digite o sexo: 'M' para masculino e 'F' para feminino: ");
        scanf("%s", &sexo);
        printf("Digite a altura: ");
        scanf("%f", &altura);
        if (primeira_exec == 1)
        {
            maior_altura = altura;
            menor_altura = altura;
            primeira_exec = 0;
        }
        else
        {
            if (maior_altura < altura)
            {
                maior_altura = altura;
            }
            if (menor_altura > altura)
            {
                menor_altura = altura;
            }
        }
        soma_turma += altura;
        if (sexo == 'F')
        {
            soma_mulheres += altura;
            n_mulheres++;
        }
        n_alunos++;
    }
    media_mulheres = soma_mulheres / n_mulheres;
    media_turma = soma_turma / n_alunos;
    printf("\nMaior altura: %.2f\n", maior_altura);
    printf("Menor altura: %.2f\n", menor_altura);
    printf("Media de altura das mulheres: %.2f\n", media_mulheres);
    printf("Media de altura da turma: %.2f\n", media_turma);
}