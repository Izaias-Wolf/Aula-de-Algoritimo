#include <stdio.h>

int main () {
    char frase [17] = {'E', 'u', ' ', 'p', 'r', 'o', 'g', 'r', 'a', 'm', 'o', ' ', 'e', 'm', ' ', 'C', '\0'};
    
    //char frase[16] = "Eu programo em C";

    //frase[5] = '\0'; para poder colocar o \0 na posição da frase dentro de uma string

    for (int i=0; i<17; i++)  {
        printf("%c", frase[i]);
    }
    
    printf("\n");
    printf("%s\n", frase);

    printf("Entre com uma frase: ");
    scanf("%[^\n]s", frase);
    while (getchar() != '\n');

    char cesar[6][5];
    int k=0;
    for (int i=0; i<6; i++) {
        for (int j=0; j<5; j++)  {
            cesar[i][j] = frase[k];
            k++;
        }
        
    }
    
    printf("Sua frase codificada: ");
    for (int j=0;j<5;j++) {
        for (int i=0;i<6; i++)  {
            printf("%c", cesar[i][j]);
        }
        
    }
    
   /*   0 1 2 3 4
    0 E u   p r
    1 o g r a m
    2 o  e m
    3 C 
    4
    5
    6         */

    {
        /* code */
    }
    

    return 0;
}