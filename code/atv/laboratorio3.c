#include <stdio.h>
int main()
{
    float saldo = 0;
    float valor_conta, valor_saque, valor_deposito;
    int opcao, n_contas;
    while (opcao != 5)
    {
        printf("\nO que deseja fazer?\n1. Consultar saldo\n2. Depositar valor\n3. Sacar valor\n4. Pagamentos de Multiplas Contas\n5. Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Seu saldo: R$%.2f\n", saldo);
            break;
        case 2:
            do
            {
                printf("Valor do deposito: R$");
                scanf(" %f", &valor_deposito);
                if (valor_deposito < 0)
                {
                    printf("Apenas valores positivos estao permitidos. Digite 0 para nao depositar nenhum valor.\n");
                }
            } while (valor_deposito < 0);
            saldo += valor_deposito;
            printf("Deposito realizado com sucesso. Saldo atual: R$%.2f\n", saldo);
            break;
        case 3:
            do
            {
                printf("Valor do saque: R$");
                scanf(" %f", &valor_saque);
                if ((valor_saque > saldo) || (valor_saque < 0))
                {
                    printf("Nao eh possivel realizar saques maiores que o saldo atual da conta ou menores que R$0,00.\n");
                }
            } while ((valor_saque > saldo) || (valor_saque < 0));
            saldo -= valor_saque;
            printf("Saque realizado com sucesso. Saldo atual: R$%.2f\n", saldo);
            break;
        case 4:
            printf("Quantas contas deseja pagar? ");
            scanf("%d", &n_contas);
            while (n_contas > 0)
            {
                do
                {
                    printf("Digite o valor da conta: ");
                    scanf("%f", &valor_conta);
                    if (valor_conta < 0)
                    {
                        printf("Digite um valor positivo.\n");
                    }
                } while (valor_conta < 0);

                if (saldo < valor_conta)
                {
                    printf("Saldo insuficiente. Saldo atual: R$%.2f.", saldo);
                    break;
                }
                else
                {
                    saldo -= valor_conta;
                    printf("Conta no valor de R$%.2f paga com sucesso. Saldo atual: R$%.2f\n", valor_conta, saldo);
                }
                n_contas--;
            }
            break;
        case 5:
            printf("Encerrando...");
            break;
        default:
            printf("Opcao invalida.\n");
            break;
        }
    }
}