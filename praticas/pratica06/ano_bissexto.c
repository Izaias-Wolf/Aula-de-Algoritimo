#include <stdio.h>

int main () {

    int ano = 0;

    scanf("%i", &ano);

    int ano_multiplo_4 = ano % 4 == 0;
    int ano_multiplo_100 = ano % 100 != 0;
    int ano_multiplo_4_e_ano_nao_multiplo_100 = ano_multiplo_4 && ano_multiplo_100;
    int ano_multiplo_400 = ano % 400 == 0;
    int ano_multiplo_e_nao_multiplo_100_ou_ano_multiplo_400 = ano_multiplo_4_e_ano_nao_multiplo_100 || ano_multiplo_400;

    if (ano_multiplo_e_nao_multiplo_100_ou_ano_multiplo_400)  {
      printf("O ano %d eh bissexto!\n", ano);
    } else {
      printf("O ano %d naum eh bissexto!\n", ano);  
    } 
    

    return 9;
}