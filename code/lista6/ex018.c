// 18. Faça um programa que, dada uma string, diga se ela e um palíndromo ou não. Lembrando que um
// palíndromo é uma palavra que tenha a propriedade de poder ser lida tanto da direita para a esquerda
// como da esquerda para a direita. Exemplo:
// ovo
// arara
// Socorram-me, subi no ônibus em Marrocos.
// Anotaram a data da maratona

#include <stdio.h>

int main(){
    char palavra[100];
    int tamanho = 0;
    int cont = 0;
    printf("Digite uma palavra: ");
    fgets(palavra, 100, stdin);
    for(int i = 0; (palavra[i] != '\0') && (palavra[i] != '\n'); i++){
        tamanho++;
    }
    for(int i = 0; i < tamanho; i++){
        if(palavra[i] == palavra[(tamanho-1-i)]){
            cont++;
        }
    }
    if(cont == tamanho){
        printf("Eh palindromo!");
    }
}