// 19. Faça um programa usando switch case e que só encerra sua execução no momento em que o
// usuário digita uma opção inválida que contenha um menu com as seguintes opções:
// a. Ler uma string S1 (tamanho maximo 20 caracteres);
// b. Imprimir o tamanho da string S1;
// c. Comparar a string S1 com uma nova string S2 fornecida pelo usuário e imprimir o resultado
// da comparação;
// d. Concatenar a string S1 com uma nova string S2 e imprimir na tela o resultado da
// concatenação;
// e. Imprimir a string S1 de forma reversa;
// f. Contar quantas vezes um dado caractere aparece na string S1. Esse caractere desse ser
// informado pelo usuário;
// g. Substituir a primeira ocorrência do caractere C1 da string S1 pelo caractere C2. Os caracteres
// C1 e C2 serão lidos pelo usuário;
// h. Verificar se uma string S2 é substring de S1. A string S2 deve ser informada pelo usuário;
// i. Retornar uma substring da string S1. Para isso o usuário deve informar a partir de qual
// posição deve ser criada a substring e qual é o tamanho da substring.

#include <stdio.h>

int main(){
    char S1[20];
    char S2[20];
    int tamanho = 0;
    int menu = 0;
    
    do{
    printf("\n=== MENU ===\n1 - Ler uma String S1\n2 - Imprimir o tamanho da String S1\n3 - Comparar a String S1 com uma nova String S2\n4 - Concatenar a String S1 com a S2\n5 - Imprimir a String S1 de forma reversa\n6 - Contar quantas vezes um caractere escolhido aparece\n7 - Substituir a primeira ocorrencia do caractere C1 da String S1 pelo caractere C2 escolhido.\n8 - Verificar se S2 eh substring de S1\n9 - Retornar uma substring da String S1, informe o tamanho da substring.\nDigite uma opcao: ");
    scanf("%d", &menu);
    getchar();
    switch(menu){
        case 1:
            printf("\nDigite a string S1: ");
            fgets(S1, 20, stdin);
            int i = 0;
            while (S1[i] != '\0') {
                if (S1[i] == '\n') {
                    S1[i] = '\0';
                    break;
                }
                i++;
            }
        break;

        case 2:
            for(int i = 0; S1[i] != '\0'; i++){
                tamanho++;
            }
            printf("\nA String tem: %d caracteres.\n", tamanho);
        break;

        case 3:
        printf("\nDigite a string S2: ");
            fgets(S1, 20, stdin);
            i = 0;
            while (S2[i] != '\0') {
                if (S2[i] == '\n') {
                    S2[i] = '\0';
                    break;
                }
                i++;
            }
            for(int i = 0; S1[i] != '\0'; i++){
            if(S1[i] == S2[i]){
                printf("As strings sao iguais!");
            }
            else{
                printf("As strings sao diferentes!");
            }
        }
        break;

        default:
            printf("Encerrado.\n");
        break;
    }
} while(menu >= 1 && menu <= 9);
}