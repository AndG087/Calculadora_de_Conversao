/*
NOME: ANDERSON GOMES ROMÃO DE MIRANDA VALENÇA
CURSO: CIÊNCIA DA COMPUTAÇÃO 
PERÍODO: 3º PERÍODO
DATA: 29/08
HORA: 20:54
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void decimalParaBinario(int num, char *binStr);
void decimalParaOctal(int num, char *octStr);
void decimalParaHexadecimal(int num, char *hexStr);
void decimalParaBCD(int num);
void exibirBinario(unsigned short int num);
void decimalParaComplemento2(int num);
void imprimirBits(uint64_t n, int bits);
void mostrarDetalhesFloat(float f);
void mostrarDetalhesDouble(double d);

int main() {
    int num;
    float f;
    double d;
    char binStr[32], octStr[32], hexStr[32];

    // Parte 1: Conversões de decimal para binário, octal, hexadecimal e BCD
    printf("Digite um número decimal: ");
    scanf("%d", &num);

    decimalParaBinario(num, binStr);
    printf("Binário: %s\n", binStr);

    decimalParaOctal(num, octStr);
    printf("Octal: %s\n", octStr);

    decimalParaHexadecimal(num, hexStr);
    printf("Hexadecimal: %s\n", hexStr);

    decimalParaBCD(num);

    // Parte 2: Complemento de 2
    decimalParaComplemento2(num);

    // Parte 3: Detalhes em ponto flutuante (float e double)
    printf("\nDigite um número float: ");
    scanf("%f", &f);
    d = f;

    mostrarDetalhesFloat(f);
    mostrarDetalhesDouble(d);

    return 0;
}

void decimalParaBinario(int num, char *binStr) {
    int index = 0;
    
    if (num == 0) {
        binStr[index++] = '0';
    } else {
        while (num > 0) {
            binStr[index++] = (num % 2) + '0';
            num /= 2;
        }
    }
    binStr[index] = '\0';

    // Invertendo a string
    for (int i = 0; i < index / 2; i++) {
        char temp = binStr[i];
        binStr[i] = binStr[index - i - 1];
        binStr[index - i - 1] = temp;
    }
}

void decimalParaOctal(int num, char *octStr) {
    int index = 0;
    
    if (num == 0) {
        octStr[index++] = '0';
    } else {
        while (num > 0) {
            octStr[index++] = (num % 8) + '0';
            num /= 8;
        }
    }
    octStr[index] = '\0';

    // Invertendo a string
    for (int i = 0; i < index / 2; i++) {
        char temp = octStr[i];
        octStr[i] = octStr[index - i - 1];
        octStr[index - i - 1] = temp;
    }
}

void decimalParaHexadecimal(int num, char *hexStr) {
    int index = 0;
    const char *hexChars = "0123456789ABCDEF";
    
    if (num == 0) {
        hexStr[index++] = '0';
    } else {
        while (num > 0) {
            hexStr[index++] = hexChars[num % 16];
            num /= 16;
        }
    }
    hexStr[index] = '\0';

    // Invertendo a string
    for (int i = 0; i < index / 2; i++) {
        char temp = hexStr[i];
        hexStr[i] = hexStr[index - i - 1];
        hexStr[index - i - 1] = temp;
    }
}

void decimalParaBCD(int num) {
    printf("BCD: ");
    if (num == 0) {
        printf("0000");
    } else {
        while (num > 0) {
            int digito = num % 10;
            char binStr[5];
            decimalParaBinario(digito, binStr);
            printf("%04s ", binStr);  // Exibindo cada dígito com 4 bits
            num /= 10;
        }
    }
    printf("\n");
}

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

void imprimirBits(uint64_t n, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

void mostrarDetalhesFloat(float f) {
    uint32_t bits;
    memcpy(&bits, &f, sizeof(bits));

    uint32_t sinal = (bits >> 31) & 1;
    uint32_t expoente = (bits >> 23) & 0xFF;
    uint32_t mantissa = bits & 0x7FFFFF;

    printf("Float: %f\n", f);
    printf("Bits: ");
    imprimirBits(bits, 32);
    printf("Sinal: %u\n", sinal);
    printf("Expoente com viés: %u\n", expoente);
    printf("Fração: ");
    imprimirBits(mantissa, 23);
}

void mostrarDetalhesDouble(double d) {
    uint64_t bits;
    memcpy(&bits, &d, sizeof(bits));

    uint64_t sinal = (bits >> 63) & 1;
    uint64_t expoente = (bits >> 52) & 0x7FF;
    uint64_t mantissa = bits & 0xFFFFFFFFFFFFF;

    printf("\nDouble: %lf\n", d);
    printf("Bits: ");
    imprimirBits(bits, 64);
    printf("Sinal: %llu\n", sinal);
    printf("Expoente com viés: %llu\n", expoente);
    printf("Fração: ");
    imprimirBits(mantissa, 52);
}
