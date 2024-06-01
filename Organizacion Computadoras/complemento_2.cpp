#include <stdio.h>

// Función para calcular el complemento a dos de un número binario
int complemento_a_dos(int num) {
    // Invertir todos los bits del número
    int complemento = ~num;

    // Sumar 1 al número invertido
    complemento += 1;

    return complemento;
}

int main() {
    int numero_binario;

    printf("Introduce un número binario: ");
    scanf("%d", &numero_binario);

    // Calcular el complemento a dos
    int complemento = complemento_a_dos(numero_binario);

    printf("El complemento a dos de %d es %d\n", numero_binario, complemento);

    return 0;
}
