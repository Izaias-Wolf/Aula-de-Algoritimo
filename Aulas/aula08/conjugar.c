#include <stdio.h>
#include <string.h>

int main () {
    //       0123456   78
    // VERBO PROGRAM + AR = tamanho 9
    // EU PROGRAM + O
    // TU PROGRAM + AS
    // ELE PROGRAM + AMOS
    // NOS PROGRAM + AIS
    // ELES PROGRAM + AM

    char verbo[21];
    char pronomes[6][5] = {"EU", "TU", "ELE", "NOS", "VOS", "ELES"};
    char sufixos[6][5] = {"O", "AS", "A", "AMOS", "AIS", "AM"};

    printf("Entre com um verbo  terminado em AR: ");
    scanf("%s", verbo);

    int tamanho = strlen(verbo);
    int ultima_posicao = tamanho - 1;
    int penultima_posicao = ultima_posicao - 1;

    if (verbo[penultima_posicao] == 'A'  && verbo[ultima_posicao] == 'R')  {
        printf("Verbo %s no presente do indicativo\n", verbo);
        char radical[21];
        strcpy(radical, verbo);  //radical = verbo
        radical[penultima_posicao] = '\0';  // troca A por nulo
        for (int i=0; i<6; i++)  {
            char conjugacao[100];
            strcpy(conjugacao, pronomes[i]);
            strcat(conjugacao, " ");
            strcat(conjugacao, radical);
            strcat(conjugacao, sufixos[i]);
            printf("%s\n", conjugacao);

        }
        


    } else {
        printf("Verbo %s nao termina em AR!", verbo);
    }
    


    return 0;
}