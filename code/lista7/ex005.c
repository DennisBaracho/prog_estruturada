// Para controle dos veículos em uma determinada cidade, a Secretaria de Transportes criou o 
// seguinte registro:  
// - Nome do Proprietário  
// - Número do Chassi  
// - Modelo do veículo  
// - Marca  
// - Cor  
// - Combustível  
// - Ano de Fabricação  
// - Placa  
// Sabendo que o número máximo de veículos na cidade é 5000, e suponha que os veículos já foram 
// todos cadastrados (5000 veículos).  
// a) Construa um algoritmo que liste todos os proprietários cujos carros são do ano de 1990 ou inferior, 
// e movidos a gasolina.  
// b) Escreva um algoritmo que liste todas as placas e os proprietários dos veículos que comecem com a 
// letra 'A' e terminem com '0', '2' ou '7'. DICA: faça com que a placa seja um vetor de caracteres!  
// c) Elabore um algoritmo que liste o modelo e a cor do automóvel cuja soma dos caracteres numéricos 
// da placa seja par.  
// d) Permita a troca do nome do proprietário do veículo informando-se o número do chassi do carro.  
 
#include <stdio.h>
#include <string.h>
int main(){
    typedef struct {
        char nome_proprietario[50];
        int chassi;
        char modelo_veiculo[50];
        char marca[50];
        char cor[50];
        char combustivel[50];
        int ano;
        char placa[50];
    } Registro;
    Registro veiculos[100];

    for(int i = 0; i < 100; i++){
        printf("Digite o nome do proprietario");
        fgets(veiculos[i].nome_proprietario, 50, stdin);
        int j = 0;
        while (veiculos[i].nome_proprietario[j] != '\0') {
            if (veiculos[i].nome_proprietario[j] == '\n') {
                veiculos[i].nome_proprietario[j] = '\0';
                break;
            }
            j++;
        }

        printf("Digite o numero do chassi");
        scanf("%d", &veiculos[i].chassi);
        getchar();

        printf("Digite o modelo do veiculo");
        fgets(veiculos[i].modelo_veiculo, 50, stdin);
         j = 0;
        while (veiculos[i].modelo_veiculo[j] != '\0') {
            if (veiculos[i].modelo_veiculo[j] == '\n') {
                veiculos[i].modelo_veiculo[j] = '\0';
                break;
            }
            j++;
        }

        printf("Digite a marca do veiculo");
        fgets(veiculos[i].marca, 50, stdin);
         j = 0;
        while (veiculos[i].marca[j] != '\0') {
            if (veiculos[i].marca[j] == '\n') {
                veiculos[i].marca[j] = '\0';
                break;
            }
            j++;
        }

        printf("Digite a cor do veiculo");
        fgets(veiculos[i].cor, 50, stdin);
         j = 0;
        while (veiculos[i].cor[j] != '\0') {
            if (veiculos[i].cor[j] == '\n') {
                veiculos[i].cor[j] = '\0';
                break;
            }
            j++;
        }

        printf("Digite o tipo de combustivel do carro");
        fgets(veiculos[i].combustivel, 50, stdin);
         j = 0;
        while (veiculos[i].combustivel[j] != '\0') {
            if (veiculos[i].combustivel[j] == '\n') {
                veiculos[i].combustivel[j] = '\0';
                break;
            }
            j++;
        }

        printf("Digite o ano de fabricacao do carro");
        scanf("%d", &veiculos[i].ano);
        getchar();

        printf("Digite a placa do carro");
        fgets(veiculos[i].placa, 50, stdin);
        j = 0;
        while (veiculos[i].placa[j] != '\0') {
            if (veiculos[i].placa[j] == '\n') {
                veiculos[i].placa[j] = '\0';
                break;
            }
            j++;
        }
    }

    printf("\nProprietarios cujos carros sao do ano de 1990 ou inferior e movidos a gasolina: ");
    for(int i = 0; i < 100; i++){
        if(veiculos[i].ano <= 1990 && strcmp(veiculos[i].combustivel, "gasolina") == 0){
            printf("%s\n", veiculos[i].nome_proprietario);
        }
    }

    printf("\nTodas as placas e proprietarios dos veiculos que começam com a letra 'A' e terminem com '0', '2', ou '7'");
    for(int i = 0; i < 100; i++){
            if(veiculos[i].placa[0] == 'A' && (veiculos[i].placa[6] == '2' || veiculos[i].placa[6] == '0' || veiculos[i].placa[6] == '7')){
                printf("O carro %s do proprietario %s\n", veiculos[i].placa, veiculos[i].nome_proprietario);
            }
    }

    int soma = 0;

    printf("\nModelo e a cor do automovel cuja soma dos caracteres numericos da placa seja par");
    for(int i = 0; i < 100; i++){
        soma = 0;
        for(int j = 0; veiculos[i].placa[j] != '\0'; j++){
            if(veiculos[i].placa[j] >= '0' && veiculos[i].placa[j] <= '9'){
            soma += veiculos[i].placa[j] - '0';
            }
        }
        if(soma % 2 == 0){
            printf("modelo: %s, cor: %s\n", veiculos[i].modelo_veiculo, veiculos[i].cor);
        }
    }
    // d) Permita a troca do nome do proprietário do veículo informando-se o número do chassi do carro.  
}