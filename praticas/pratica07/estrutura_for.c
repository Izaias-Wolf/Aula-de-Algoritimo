#include <stdio.h>

int main () {
    for (int i=0; i<10; i++)  {
        printf("%i ", i);
    }
      // printf("\n");   serviu para eu poder finalizar a linha de cima e colocar a informação na linha de baixo
    for (int i=9; i>=0; i--)  {
        printf("%i ", i);
    }
    for (;;)  {
        printf("Ao infinito e alem!!!\n");
    }
    // para poder interromper o programa tem que pressionar as teclas ctrl + c

    return 0;
}