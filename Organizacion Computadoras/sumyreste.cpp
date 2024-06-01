#include <stdio.h>

// Función para sumar dos números binarios con punto flotante
float suma_binaria(float a, float b) {
    return a + b;
}

// Función para restar dos números binarios con punto flotante
float resta_binaria(float a, float b) {
    return a - b;
}

int main() {
    float num1, num2;

    printf("Introduce el primer número binario con punto flotante: ");
    scanf("%f", &num1);

    printf("Introduce el segundo número binario con punto flotante: ");
    scanf("%f", &num2);

    // Realizar la suma y la resta
    float suma = suma_binaria(num1, num2);
    float resta = resta_binaria(num1, num2);

    printf("Suma: %.2f\n", suma);
    printf("Resta: %.2f\n", resta);

    return 0;
}

