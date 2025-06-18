#include <stdio.h>

int main () {

    char meses[12][10] = {"Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};

    enum meses_do_ano_e { jan=1, fev, mar, abr, jun, jul, ago, set, out, nov, dez};

    printf("Informe i mes (1-12): ");
    int mes = 0;
    scanf("%i", &mes);


    if (jan <= mes && mes <= dez)  {
        printf("O mes escolhido foi %s\n", meses[mes-1]);
    } else {
        printf("Mes invalido\n");
    }
    
    
    
    
    return 0;
}