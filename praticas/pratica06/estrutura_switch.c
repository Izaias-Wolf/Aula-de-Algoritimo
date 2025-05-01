#include <stdio.h>

int main () {

    int nota = 0;

    scanf("%i", &nota);

    switch (nota)   {
    case 1: printf("Voce ganhou '*'.\n");        break;
    case 2: printf("Voce ganhou '**'.\n");       break;
    case 3: printf("Voce ganhou '***'.\n");      break;
    case 4: printf("Voce ganhou '****'.\n");     break;
    case 5: printf("Voce ganhou '*****'.\n");    break; 
       
      default: printf("Nota Invalida! Tente novamente.\n");
       
    }

    return 0;
}