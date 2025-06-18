#include <stdio.h>

#define DOMINGO 1
#define SEGUNDA 2
#define TERCA 3
#define QUARTA 4
#define QUINTA 5
#define SEXTA 6
#define SABADO 7

int main()
{

    enum dias_da_semana_e
    {
        dom = 1,
        seg,
        ter,
        qua,
        qui,
        sex,
        sab
    };

    enum boolean { false, true};

    printf("Informe um dia da semana (1 a 7): ");
    int dia_da_semana = 0;
    scanf("%i", &dia_da_semana);

    switch (dia_da_semana)  {
    case seg:
    case ter:
    case qua:
    case qui:
    case sex: printf("Eh um dia util\n"); break;
    case dom:
    case sab: printf("Naum eh um dia util\n"); break;
    default: printf("Dia invalido!\n");
    
    
        
    
        
    }
    return 0;
}