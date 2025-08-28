// Seja A26×10 uma matriz fornecida, cujo conteúdo é a população dos 10 municípios mais populosos
// dos 26 estados brasileiros (A[i, j] representa a população do j-ésimo município do i-ésimo estado).
// Determinar o número do município mais populoso e o número do estado a que pertence.
// Considerando que a primeira coluna sempre contém a população da capital do estado, calcular a
// média da população das capitais dos 26 estados

#include <stdio.h>
int main(){
    int M[26][10];
    int estadoMaisPopuloso;
    int municipioMaisPopuloso;
    int maiorPopulacao;
    int mediaPopulacao = 0;
    for(int estado = 0; estado < 26; estado++){
        for(int municipio = 0; municipio < 10; municipio++){
            printf("Digite o elemento M[%d][%d]: ", estado + 1, municipio + 1);
            scanf("%d", &M[estado][municipio]);
            if(estado == 0 && municipio == 0){
                maiorPopulacao = M[estado][municipio];
                estadoMaisPopuloso = estado;
                municipioMaisPopuloso = municipio;
            }
            else if(M[estado][municipio] > maiorPopulacao){
                maiorPopulacao = M[estado][municipio];
                estadoMaisPopuloso = estado;
                municipioMaisPopuloso = municipio;
            }
            
        }
    }

    for(int estado = 0; estado < 26; estado++){
        mediaPopulacao += M[estado][0];
    }
    mediaPopulacao = mediaPopulacao/26;

    printf("\nMunicipio mais populoso eh %d, do estado %d", municipioMaisPopuloso + 1, estadoMaisPopuloso + 1);
    printf("\nMedia da populacao das capitais: %d", mediaPopulacao);
}