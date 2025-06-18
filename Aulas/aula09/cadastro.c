#include <stdio.h>
#include <string.h>

int main()
{
    struct endereco_t {
        char logradouro[61];
        int numero;
        char bairro[41];
        char cidade[41];
        char uf[3];
        int cep;

    };
    struct cliente_t
    {
        char nome[101];
        long long int telefone;
        char email[101];
        struct endereco_t endereco;
    };

    struct forncedor_t {
        struct endereco_t endereco;
    };

    struct cliente_t cliente;
  
    strcpy(cliente.nome, "Jose");
    cliente.telefone = 61999999999L;
    strcpy(cliente.email, "jose@iesb.br");
    strcpy(cliente.endereco.logradouro, "SQS");
    cliente.endereco.numero = 612;
    strcpy(cliente.endereco.bairro, "Asa Sul");
    strcpy(cliente.endereco.cidade, "Brasilia");
    strcpy(cliente.endereco.uf, "DF");
    cliente.endereco.cep = 70000000;
 
    struct cliente_t clientes[10];

    for (int i=0; i<10; i++)  {
        printf("Dados do cliente %i\n", i+1);
        printf("Nome do cliente: ");
        scanf("%[^\n]s", clientes[i].nome);
        while (getchar() != '\n');      
        printf("Telefone do cliente: ");
        scanf("%lli", &clientes[i].telefone);
        while (getchar() != '\n');      
        printf("E-mail do cliente: ");
        scanf("%[^\n]s", clientes[i].email);
        while (getchar() != '\n');      
        printf("Endereco do cliente:\n");
        printf("Logradouro: ");
        scanf("%[^\n]s", clientes[i].endereco.logradouro);
        while (getchar() != '\n');      
        printf("Numero: ");
        scanf("%[^\n]s", clientes[i].endereco.numero);
        while (getchar() != '\n');      
        printf("Bairro: ");
        scanf("%[^\n]s", clientes[i].endereco.bairro);
        while (getchar() != '\n');      
        printf("Cidade: ");
        scanf("%[^\n]s", clientes[i].endereco.cidade);
        while (getchar() != '\n');     
        printf("UF: ");
        scanf("%[^\n]s", clientes[i].endereco.uf);
        while (getchar() != '\n');      
        printf("CEP");
        scanf("%[^\n]s", clientes[i].endereco.cep);
        while (getchar() != '\n');      
        
    }    

printf("Meus Clientes\n");
for (int i=0; i<10; i++) {
        printf("Dados do cliente %i\n", i+1);   
        printf("Nome do cliente: %s\n", clientes[i].nome);
        printf("Telefone do cliente: %lli\n", &clientes[i].telefone);
        printf("E-mail do cliente: %s\n", clientes[i].email);
        printf("Endereco do cliente:\n");
        printf("Logradouro: %s, %i - %s - %s/%s\n", clientes[i].endereco.logradouro, clientes[i].endereco.numero), clientes[i].endereco.bairro, clientes[i].endereco.cidade, clientes[i].endereco.uf;
        printf("CEP: %i\n", clientes[i].endereco.cep);
    }
    

    
    return 0;
}