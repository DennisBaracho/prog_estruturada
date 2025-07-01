#include <stdio.h>
#include <math.h>

int potencia(int base, int exp){
    int resultado = 1;
    for ( int i = 0; i < exp; i++){
        resultado *= base;
    } 
    return resultado;
}

int main(){
    int numero, soma;
    int u, d, c, m, dm, cm;
    int exp;
    for(cm = 0; cm <= 1; cm++){
        for(dm = 0; dm <= 9; dm++){
            for(m = 0; m <= 9; m++){
                for(c = 0; c <= 9; c++){
                    for(d = 0; d <= 9; d++){
                        for(u = 0; u <= 9; u++){
                            numero = 100000*cm + 10000*dm + 1000*m + 100*c + 10*d + u;
                            exp = 1;
                            if (d > 0){
                                exp = 2;
                                if (c > 0){
                                    exp = 3;
                                    if (m > 0){
                                        exp = 4;
                                        if (dm > 0){
                                            exp = 5;
                                            if (cm > 0){
                                                exp = 6;
                                            }
                                        }
                                    }
                                }
                            }
                            soma = potencia(cm, exp) + potencia(dm, exp) + potencia(m, exp)+ potencia(c, exp) + potencia(d, exp) + potencia(u, exp);
                            if (numero == soma){
                                printf("%d\n", numero);
                            }
                        }
                    }
                }
            }
        }
    }
}