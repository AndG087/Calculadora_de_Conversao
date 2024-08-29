/*
NOME: ANDERSON GOMES ROMÃO DE MIRANDA VALENÇA
CURSO: CIÊNCIA DA COMPUTAÇÃO 
PERÍODO: 3º PERÍODO
DATA: 29/08
HORA: 19:57
*/


#include <stdio.h>
#include <stdlib.h>

void decimalParaBinario(int num, char *binStr);
void decimalParaOctal(int num, char *octStr);
void decimalParaHexadecimal(int num, char *hexStr);
void decimalParaBCD(int num);

int main() {
    int num;
    char binStr[32], octStr[32], hexStr[32];

    printf("Digite um número decimal: ");
    scanf("%d", &num);

    decimalParaBinario(num, binStr);
    printf("Binário: %s\n", binStr);

    decimalParaOctal(num, octStr);
    printf("Octal: %s\n", octStr);

    decimalParaHexadecimal(num, hexStr);
    printf("Hexadecimal: %s\n", hexStr);

    decimalParaBCD(num);

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
