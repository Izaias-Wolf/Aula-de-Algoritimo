#include <stdio.h>

int main () {
    printf("MENU PRINCIPAL\n");
    printf("1 - Consultar Saldo\n");
    printf("2 - Fazer Recarga\n");
    printf("3 - Ver Racados\n");
    printf("4 - Ultimas Ligacoes\n");
    printf("5 - Sair\n");
    printf("Escolha um opcao -> ");

    int opcao = 0;
    scanf("%i", &opcao);

//    if (opcao == 1)  {
//        printf("Seu saldo eh R$ 10.00\n");
//    } else if (opcao == 2) {
//        printf("Digite 1 p/ 10,00, 2 p/ 20,00 ou 5 p/ 50,00\n");
//    } else if (opcao == 3) {
//        printf("Voce tem recados um novo recado\n\n\n\n\n\n\n\n\n\n\n\n"); //originalmente o professor colocou "Voce naum tem recado!"
//        printf("Sua mulher falou que voce eh corno!!!\n");
//    } else if (opcao == 4) {
//        printf("Voce ligou para 8888-8888");
//    } else if (opcao == 5) {
//        printf("Obrigado pelo contato. Ate logo!\n");
//    } else {
//        printf("Opcao invalida. Tente novamente!\n");
 //   }
    
     switch (opcao)  {
        case 1: printf("Seu saldo eh R$ 10.00\n"); break;
        case 2: printf("Digite 1 p/ 10,00, 2 p/ 20,00 ou 5 p/ 50,00\n"); break;
        case 3: printf("Voce tem recados um novo recado\n"); break; //originalmente o professor colocou "Voce naum tem recado!"
        case 4: printf("Voce ligou para 8888-8888"); break;
        case 5: printf("Obrigado pelo contato. Ate logo!\n"); break;
        default: printf("Opcao invalida. Tente novamente!\n");
        A Linguagem C eh uma programacao que eu comecei a aprender e a desenvolver para o meu crescimento profissional dentro da area da tecnologia

        Agora vou postar isso mais tarde para eu poder ver de qual eh dentro do Instagram!!!
        
     }   
    

    return 0;
}