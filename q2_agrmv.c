/*
NOME: ANDERSON GOMES ROMÃO DE MIRANDA VALENÇA
CURSO: CIÊNCIA DA COMPUTAÇÃO 
PERÍODO: 3º PERÍODO
DATA: 29/08
HORA: 19:10
*/


#include <stdio.h>
#include <stdlib.h>

void exibirBinario(unsigned short int num) {
    for (int i = 15; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

void decimalParaComplemento2(int num) {
    unsigned short int resultado;

    printf("\nConvertendo %d para complemento a 2 com 16 bits:\n", num);

    if (num < 0) {
        num = abs(num);

        printf("1. Convertendo para binário com 16 bits:\n");
        resultado = num;
        exibirBinario(resultado);

        printf("2. Invertendo todos os bits:\n");
        resultado = ~resultado;
        exibirBinario(resultado);

        printf("3. Somando 1 ao complemento de 1 para obter o complemento a 2:\n");
        resultado += 1;
        exibirBinario(resultado);

    } else {
        printf("Convertendo para binário com 16 bits:\n");
        resultado = num;
        exibirBinario(resultado);
    }

    printf("\nResultado final em complemento a 2: ");
    exibirBinario(resultado);
}

int main() {
    int num;

    printf("Digite um número decimal: ");
    scanf("%d", &num);

    decimalParaComplemento2(num);

    return 0;
}
