#include <stdio.h>

int main()
{
    float CR, CP, custo = 0;
    int qualidade = 0;
    int R = 0;
    int P = 40;
    printf("Digite o preço do litro da água da rede pública: ");
    scanf("%f", &CR);
    printf("Digite o preço do litro da água do poço: ");
    scanf("%f", &CP);
    for (R = 0; R <= 40; R += 10)
    {
        custo = R * CR + P * CP;
        qualidade = 2 * R + 1 * P;
        printf("Rede: %dL, Poço: %dL -> Qualidade: %d, Custo: R$%.2f\n", R, P, qualidade, custo);
        P -= 10;
    }
}