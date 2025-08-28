// Uma indústria faz a folha mensal de pagamentos de seus 80 empregados baseada no 
// seguinte: Existe uma tabela com os dados de cada funcionário (matrícula, nome e salário 
// bruto); Escreva um algoritmo que leia e processe a tabela e emita, para cada funcionário, 
// seu contracheque, cujo formato é dado a seguir: 
// Matrícula: 
// Nome: 
// Salário Bruto: 
// Dedução INSS: 
// Salário Liquido: 
// O desconto do INSS é de 12% do salário bruto. 
// O salário líquido é a diferença entre o salário bruto e a dedução do INSS.

#include <stdio.h>

int main(){
    typedef struct {
        int matricula;
        char nome[50];
        float salario;
        float deducao_inss;
        float salario_liquido;
    } Contracheque;

    Contracheque funcionario[100];

    for(int i = 0; i < 100; i++){
        printf("Digite o salario bruto do funcionario: ");
        scanf("%f", &funcionario[i].salario);
        getchar();

        printf("Digite a matricula do funcionario: ");
        scanf("%d", &funcionario[i].matricula);
        getchar();
        
        printf("Digite o nome do funcionario: ");
        fgets(funcionario[i].nome, 50, stdin);
        int j = 0;
        while (funcionario[i].nome[j] != '\0') {
            if (funcionario[i].nome[j] == '\n') {
                funcionario[i].nome[j] = '\0';
                break;
            }
            j++;
        }
        funcionario[i].deducao_inss = 0.12*funcionario[i].salario;
        funcionario[i].salario_liquido = funcionario[i].salario - funcionario[i].deducao_inss;
    }
    for(int i = 0; i < 100; i++){
        printf("\n==== Funcionario %d ====", i + 1);
        printf("\nMatricula: %d", funcionario[i].matricula);
        printf("\nNome: %s", funcionario[i].nome);
        printf("\nSalario bruto: %.2f reais", funcionario[i].salario);
        printf("\nDeducao INSS: %.2f reais", funcionario[i].deducao_inss);
        printf("\nSalario liquido: %.2f reais", funcionario[i].salario_liquido);
        printf("\n");
    }
}