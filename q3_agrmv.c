/*
NOME: ANDERSON GOMES ROMÃO DE MIRANDA VALENÇA
CURSO: CIÊNCIA DA COMPUTAÇÃO 
PERÍODO: 3º PERÍODO
DATA: 29/08
HORA: 20:08
*/



#include <stdio.h>
#include <stdint.h>
#include <string.h>

void imprimirBits(uint64_t n, int bits);
void mostrarDetalhesFloat(float f);
void mostrarDetalhesDouble(double d);

int main() {
    float f;
    scanf("%f", &f);
    double d = f;

    mostrarDetalhesFloat(f);
    mostrarDetalhesDouble(d);

    return 0;
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
