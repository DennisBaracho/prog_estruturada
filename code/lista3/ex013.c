#include <stdio.h>
#define pi = 3.14
int main() {
    float S, numerador, denominador;
    S = 0;
    numerador = 1;
    denominador = 1;
    for(int i = 0; i < 50; i++){
        S += numerador/denominador;
        printf("%f\n", S);
        numerador += 2;
        denominador += 1;
    }
}