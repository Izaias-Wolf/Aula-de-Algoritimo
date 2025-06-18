#include <stdio.h>

int main () {

    float boletim[8][3]; //matriz bidimensional = tabela = array
    //    0 1 2
    // 0 | | | |
    // 1 | | | |
    // 2 | | | |
    // 3 | | | |
    // 4 | | | |
    // 5 | | | |
    // 6 | | | |
    // 7 | | | |
    
    for (int i=0; i<8; i++) {
      printf("Disciplina %i\n", i+1);
      for (int j=0; j<2; j++) {
        printf("Nota A%i: ", j+1);
        scanf("%f", &boletim[i][j]);
      }
      boletim[i][2] = 0.4f * boletim[i][0] + 0.6f * boletim[i][1];
    }
    
    printf("Seu boletim\n");
    for (int i=0; i<8; i++) {
        printf("Disciplina %i: ", i+1);
        for (int j=0; j<3; j++) {
            printf("%4.1f", boletim[i][j]);
        }
        printf("\n");
    }
    
    


    return 0;
}