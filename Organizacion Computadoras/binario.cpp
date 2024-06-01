#include <stdio.h>
#include <stdlib.h>

// Función para sumar dos números binarios
int suma_binaria(int a, int b) {
    int carry = 0, result = 0, temp_a, temp_b, bit_sum;

    for (int i = 0; i < 32; i++) {
        temp_a = (a >> i) & 1;
        temp_b = (b >> i) & 1;

        bit_sum = temp_a ^ temp_b ^ carry;
        carry = (temp_a & temp_b) | (temp_b & carry) | (temp_a & carry);

        result |= (bit_sum << i);
    }

    return result;
}

// Función para restar dos números binarios
int resta_binaria(int a, int b) {
    return suma_binaria(a, suma_binaria(~b, 1));
}

// Función para multiplicar dos números binarios
int multiplicacion_binaria(int a, int b) {
    int result = 0;

    while (b > 0) {
        if (b & 1) {
            result = suma_binaria(result, a);
        }
        a <<= 1;
        b >>= 1;
    }

    return result;
}

// Función para dividir dos números binarios
int division_binaria(int a, int b) {
    if (b == 0) {
        printf("Error: División por cero.\n");
        return -1;
    }

    int quotient = 0, remainder = 0;

    for (int i = 31; i >= 0; i--) {
        remainder <<= 1;
        remainder |= (a >> i) & 1;

        if (remainder >= b) {
            remainder = resta_binaria(remainder, b);
            quotient |= (1 << i);
        }
    }

    return quotient;
}

int main() {
    int num1, num2;

    printf("Introduce el primer número binario: ");
    scanf("%d", &num1);

    printf("Introduce el segundo número binario: ");
    scanf("%d", &num2);

    printf("Suma: %d\n", suma_binaria(num1, num2));
    printf("Resta: %d\n", resta_binaria(num1, num2));
    printf("Multiplicación: %d\n", multiplicacion_binaria(num1, num2));
    printf("División: %d\n", division_binaria(num1, num2));

    return 0;
}
