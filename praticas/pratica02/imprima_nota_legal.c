#include <stdio.h>

int main (){
    printf("===================================\n");
    printf("        N O T A    L E G A L\n");
    printf("===================================\n");
    printf("Produto          Qtd  Valor Unit\n");
    printf("%-16s %03i %11.2f\n",  "Camiseta", 002, 39.99);
    printf("%-16s %03i %11.2f\n",  "Calca", 001, 89.90);
    printf("%-16s %03i %11.2f\n",  "Meia social", 003, 19.99);
    printf("===================================\n");
    printf("%s %25.2f\n",  "Total:",  229.85);


    return 0;
}