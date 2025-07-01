#include <math.h>
#include <stdio.h>
#define numerador 2
int main()
{
    float denominador = 50;
    float S;
    float expoente = 1;
    for (denominador; denominador > 1; denominador--)
    {
        S += (pow(numerador, expoente)) / denominador;
        expoente++;
    }
    printf("%f", S);
}