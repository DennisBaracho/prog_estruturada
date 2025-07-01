#include <stdio.h>
#include <math.h>

int main()
{
    for (int i = 0; i <= 100000; i++)
    {
        int numero = i;
        int num_digitos = 0;
        int contador = i;
        int contador_soma = i;
        int soma_potencias = 0;
        if (numero == 0)
        {
            num_digitos = 1;
        }
        else
        {
            while (contador > 0)
            {
                contador /= 10;
                num_digitos++;
            }
        }

        while(contador_soma > 0){
            int digito = contador_soma % 10;
            soma_potencias += pow(digito, num_digitos);
            contador_soma /= 10;
        }

        if(soma_potencias == numero){
            printf("%d\n", numero);
        }
    }
}
