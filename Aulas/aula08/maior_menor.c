#include <stdio.h>

int main () {
    //int numero1;
    //int numero2;
    //int numero3;
    //int numero4;
    //int numero5;
    //int numero6;
    //int numero7;
    //int numero8;
    //int numero9;
    //int numero10;

    int numeros[10]; // matriz unidimesional = vetor = array
    //  0 1 2 3 4 5 6 7 8 9
    // |1|3|4|5|1|9|6|0|3|7|
    numeros[0] = 1;
    numeros[1] = 3;
    numeros[2] = 4;
    numeros[3] = 5;
    numeros[4] = 1;
    numeros[5] = 9;
    numeros[6] = 6;
    numeros[7] = 0;
    numeros[8] = 3;
    numeros[9] = 7;

    int maior_numero = -99999;
    int menor_numero =  99999;


    for (int i=0; i<10; i++)  {
        printf("Entre com o numero %i: ", i+1);
        scanf("%i", &numeros[i]);

        if (numeros[i] > maior_numero) {
            maior_numero = numeros[i];
        }
        
        if (numeros[i] < menor_numero)  {
            menor_numero = numeros[i];
        }
        
    }
    
    printf("Seus numeros foram\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%i, ", numeros[i]);
    }
    printf("\n");
    printf("O maior numero foi %i\n", maior_numero);
    printf("O menor numero foi %i\n", menor_numero);

    ///







    return 0;
}