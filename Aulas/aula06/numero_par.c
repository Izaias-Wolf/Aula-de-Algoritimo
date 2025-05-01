#include <stdio.h>

int main () {
    int numero = 0;

    printf("Entre com um numero inteiro: ");
    scanf("%i", &numero);

    int numero_eh_divisivel_por_2 = numero % 2 == 0;

    if (numero_eh_divisivel_por_2) {
        printf("O numero %i eh par!\n", numero);
    } else {
        printf("O numero %i eh impar!\n", numero);
    }

    // if (!numero_eh_divisivel_por_2) {
    //    printf("O numero %i eh impar!\n", numero);
    // }
    return 0;
}