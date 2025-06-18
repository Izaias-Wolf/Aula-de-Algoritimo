#include <stdio.h>    // Para entrada e saída (printf, scanf)
#include <stdbool.h>  // Para usar o tipo booleano (true/false)
#include <string.h>   // Para manipulação de strings (strcpy)
#include <stdlib.h>   // Para system("cls") ou system("clear") - opcional, para limpar tela

// --- Definicoes de Constantes ---
#define MAP_SIZE 5             // Tamanho do mapa (5x5)
#define NUM_ITEMS 3            // Numero de tipos de itens no jogo (Madeira, Frutas, Peixe)
#define NUM_LOCATIONS_TYPES 4  // Numero de tipos de locais na ilha (Porto, Floresta, Vila, Lago)
#define INITIAL_MONEY 100      // Dinheiro inicial do jogador
#define MAX_ITEM_QUANTITY 50   // Quantidade maxima de um item que o jogador pode carregar

// --- Definicoes de Estruturas ---

// Estrutura para representar o Jogador
struct Player {
    int x; // Coordenada X (linha) atual do jogador no mapa
    int y; // Coordenada Y (coluna) atual do jogador no mapa
    int money; // Dinheiro atual do jogador
    int inventory[NUM_ITEMS]; // Array para armazenar a quantidade de cada item no inventario
                              // inventory[0] = qtd_madeira, inventory[1] = qtd_frutas, etc.
};

// Estrutura para representar um Item no jogo
struct Item {
    char name[20]; // Nome do item (ex: "Madeira")
};

// Estrutura para detalhar um tipo de local no mapa
struct LocationDetail {
    char symbol; // Simbolo que representa o local no mapa (ex: 'P' para Porto)
    char name[30]; // Nome completo do local (ex: "Porto Comercial")
    int sells_item_id; // ID do item que este local VENDE (-1 se nao vende nenhum item)
    int buys_item_id;  // ID do item que este local COMPRA (-1 se nao compra nenhum item)
    int base_sell_price; // Preco base pelo qual o local VENDE 'sells_item_id'
    int base_buy_price;  // Preco base pelo qual o local COMPRA 'buys_item_id'
};

// --- Funcao Principal do Programa ---
int main() {
    // --- Declaracao de Variaveis de Estado do Jogo ---
    struct Player player; // Variavel para armazenar o estado do jogador
    struct Item items[NUM_ITEMS]; // Array de estruturas para os tipos de itens
    struct LocationDetail location_types[NUM_LOCATIONS_TYPES]; // Array de estruturas para os tipos de locais
    char game_map[MAP_SIZE][MAP_SIZE]; // Matriz que representa o tabuleiro do jogo (o mapa da ilha)
    bool game_over = false; // Flag booleana para controlar o loop principal do jogo
    int choice; // Variavel para armazenar a escolha do usuario no menu
    char move_direction; // Variavel para armazenar a direcao de movimento do jogador
    int i, j, k; // Variaveis de controle para loops (contadores)

    // --- 0. Inicializacao dos Dados do Jogo ---

    // 0.1. Inicializa os tipos de Itens
    // ID 0: Madeira
    strcpy(items[0].name, "Madeira");
    // ID 1: Frutas
    strcpy(items[1].name, "Frutas");
    // ID 2: Peixe
    strcpy(items[2].name, "Peixe");

    // 0.2. Inicializa os tipos de Locais e suas caracteristicas de comercio
    // ID 0: Porto (P)
    location_types[0].symbol = 'P';
    strcpy(location_types[0].name, "Porto Comercial");
    location_types[0].sells_item_id = 0; // Porto vende Madeira (ID 0)
    location_types[0].base_sell_price = 5; // Vende Madeira por 5 moedas
    location_types[0].buys_item_id = 2; // Porto compra Peixe (ID 2)
    location_types[0].base_buy_price = 8; // Compra Peixe por 8 moedas

    // ID 1: Floresta (F)
    location_types[1].symbol = 'F';
    strcpy(location_types[1].name, "Floresta Densa");
    location_types[1].sells_item_id = 0; // Floresta vende Madeira (ID 0)
    location_types[1].base_sell_price = 2; // Vende Madeira por 2 moedas
    location_types[1].buys_item_id = 1; // Floresta compra Frutas (ID 1)
    location_types[1].base_buy_price = 4; // Compra Frutas por 4 moedas

    // ID 2: Vila (V)
    location_types[2].symbol = 'V';
    strcpy(location_types[2].name, "Vila Agricola");
    location_types[2].sells_item_id = 1; // Vila vende Frutas (ID 1)
    location_types[2].base_sell_price = 6; // Vende Frutas por 6 moedas
    location_types[2].buys_item_id = 0; // Vila compra Madeira (ID 0)
    location_types[2].base_buy_price = 3; // Compra Madeira por 3 moedas

    // ID 3: Lago (L)
    location_types[3].symbol = 'L';
    strcpy(location_types[3].name, "Lago de Pesca");
    location_types[3].sells_item_id = 2; // Lago vende Peixe (ID 2)
    location_types[3].base_sell_price = 7; // Vende Peixe por 7 moedas
    location_types[3].buys_item_id = 0; // Lago compra Madeira (ID 0)
    location_types[3].base_buy_price = 4; // Compra Madeira por 4 moedas

    // 0.3. Inicializa o Mapa do Jogo
    // Usamos um layout fixo para simplificar, já que estamos em uma unica funcao main
    // P F . . .
    // . V . L .
    // . . . . .
    // . . . . .
    // . . . . .
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            game_map[i][j] = '.'; // Preenche o mapa com '.' (area vazia)
        }
    }
    game_map[0][0] = 'P'; // Posiciona o Porto
    game_map[0][1] = 'F'; // Posiciona a Floresta
    game_map[1][1] = 'V'; // Posiciona a Vila
    game_map[1][3] = 'L'; // Posiciona o Lago

    // 0.4. Inicializa o Jogador
    player.x = 0; // Comeca na linha 0
    player.y = 0; // Comeca na coluna 0 (Porto)
    player.money = INITIAL_MONEY; // Atribui o dinheiro inicial
    for (i = 0; i < NUM_ITEMS; i++) {
        player.inventory[i] = 0; // Zera o inventario do jogador
    }

    printf("Bem-vindo ao Ilha do Mercador!\n");
    printf("Seu objetivo e ganhar dinheiro comprando e vendendo mercadorias.\n");
    printf("Voce comeca no Porto (P) com %d moedas.\n\n", INITIAL_MONEY);
    printf("Pressione Enter para iniciar o jogo...");
    while (getchar() != '\n'); // Espera o usuario apertar Enter para comecar

    // --- 1. Loop Principal do Jogo ---
    // Este loop continua enquanto o jogo nao for encerrado (game_over for false)
    while (!game_over) {
        // --- 1.1. Apresentacao da Tela de Jogo (Mapa e Status) ---

        // Limpa a tela do console para uma melhor apresentacao (opcional e dependente do SO)
        #ifdef _WIN32 // Para sistemas Windows
            system("cls");
        #else // Para sistemas Linux/macOS
            system("clear");
        #endif

        printf("--- Mapa da Ilha ---\n");
        // Loop para desenhar o mapa
        for (i = 0; i < MAP_SIZE; i++) {
            for (j = 0; j < MAP_SIZE; j++) {
                if (player.x == i && player.y == j) {
                    printf(" P "); // Se as coordenadas forem as do jogador, desenha 'P' para o player
                } else {
                    printf(" %c ", game_map[i][j]); // Caso contrario, desenha o simbolo do mapa
                }
            }
            printf("\n"); // Quebra de linha apos cada linha do mapa
        }
        printf("Legenda: P=Porto, F=Floresta, V=Vila, L=Lago, .=Vazio\n\n");

        printf("--- Seu Status ---\n");
        printf("Localizacao: (%d, %d) - ", player.x, player.y);

        // Encontra os detalhes do local atual do jogador
        struct LocationDetail current_loc_detail; // Variavel temporaria para os detalhes do local
        bool loc_found = false; // Flag para indicar se um local conhecido foi encontrado
        for (k = 0; k < NUM_LOCATIONS_TYPES; k++) {
            if (location_types[k].symbol == game_map[player.x][player.y]) {
                current_loc_detail = location_types[k]; // Copia os detalhes do tipo de local
                loc_found = true; // Marca como encontrado
                break; // Sai do loop apos encontrar
            }
        }
        if (loc_found) {
            printf("%s\n", current_loc_detail.name); // Mostra o nome do local
        } else {
            printf("Area Vazia (Nao ha nada para comprar/vender aqui)\n");
        }

        printf("Dinheiro: %d moedas\n", player.money);
        printf("Inventario:\n");
        for (i = 0; i < NUM_ITEMS; i++) {
            printf(" - %s: %d\n", items[i].name, player.inventory[i]); // Mostra cada item e sua quantidade
        }
        printf("\n");

        // --- 1.2. Menu Principal e Entrada de Dados (com Validacao) ---
        printf("--- Menu Principal ---\n");
        printf("1. Mover\n");
        printf("2. Comprar Mercadoria\n");
        printf("3. Vender Mercadoria\n");
        printf("4. Ver Status (Atualizar Tela)\n");
        printf("5. Sair do Jogo\n");
        printf("Escolha uma opcao: ");

        // Loop de validacao para a escolha do menu:
        // Continua pedindo input ate que seja um inteiro valido entre 1 e 5
        while (scanf("%d", &choice) != 1 || choice < 1 || choice > 5) {
            printf("Opcao invalida. Por favor, digite um numero entre 1 e 5: ");
            while (getchar() != '\n'); // Limpa o buffer de entrada para evitar loops infinitos
        }
        while (getchar() != '\n'); // Limpa o buffer apos uma entrada valida (remove o Enter)

        // --- 1.3. Processar a Escolha do Usuario ---
        switch (choice) {
            case 1: // Opcao Mover
                printf("Para onde deseja ir? (W:Cima, A:Esquerda, S:Baixo, D:Direita): ");
                // Loop de validacao para a direcao de movimento
                while (scanf(" %c", &move_direction) != 1 ||
                       (move_direction != 'W' && move_direction != 'A' && move_direction != 'S' && move_direction != 'D' &&
                        move_direction != 'w' && move_direction != 'a' && move_direction != 's' && move_direction != 'd')) {
                    printf("Direcao invalida. Use W, A, S ou D: ");
                    while (getchar() != '\n'); // Limpa o buffer
                }
                while (getchar() != '\n'); // Limpa o buffer

                int new_x = player.x; // Proxima posicao X temporaria
                int new_y = player.y; // Proxima posicao Y temporaria

                // Atualiza as coordenadas temporarias com base na direcao
                if (move_direction == 'W' || move_direction == 'w') {
                    new_x--;
                } else if (move_direction == 'S' || move_direction == 's') {
                    new_x++;
                } else if (move_direction == 'A' || move_direction == 'a') {
                    new_y--;
                } else if (move_direction == 'D' || move_direction == 'd') {
                    new_y++;
                }

                // Verifica se a nova posicao esta dentro dos limites do mapa
                if (new_x >= 0 && new_x < MAP_SIZE && new_y >= 0 && new_y < MAP_SIZE) {
                    player.x = new_x; // Atualiza a posicao X do jogador
                    player.y = new_y; // Atualiza a posicao Y do jogador
                    printf("Voce se moveu para (%d, %d).\n", player.x, player.y);
                } else {
                    printf("Essa direcao esta fora dos limites da ilha!\n");
                }
                printf("Pressione Enter para continuar...\n");
                while (getchar() != '\n'); // Pausa a execucao ate o usuario apertar Enter
                break; // Sai do switch

            case 2: // Opcao Comprar Mercadoria
                if (!loc_found || current_loc_detail.sells_item_id == -1) { // Verifica se esta em local vazio ou nao vende
                    printf("Voce esta em uma area vazia ou este local nao vende mercadorias.\n");
                } else {
                    int item_to_buy_id = current_loc_detail.sells_item_id; // ID do item que o local vende
                    int item_price = current_loc_detail.base_sell_price; // Preco do item que o local vende
                    int quantity; // Quantidade a ser comprada

                    printf("Este local vende %s por %d moedas cada.\n", items[item_to_buy_id].name, item_price);
                    printf("Quantos %s deseja comprar? (Voce tem %d moedas): ", items[item_to_buy_id].name, player.money);

                    // Validacao da quantidade de compra
                    while (scanf("%d", &quantity) != 1 || quantity <= 0) {
                        printf("Quantidade invalida. Digite um numero positivo: ");
                        while (getchar() != '\n');
                    }
                    while (getchar() != '\n');

                    // Verifica se o jogador tem dinheiro suficiente
                    if (player.money >= (long)quantity * item_price) { // Usamos (long) para evitar overflow em calculos grandes
                        // Verifica se o inventario tem espaco (para este item)
                        if (player.inventory[item_to_buy_id] + quantity <= MAX_ITEM_QUANTITY) {
                            player.money -= quantity * item_price; // Reduz o dinheiro
                            player.inventory[item_to_buy_id] += quantity; // Aumenta a quantidade no inventario
                            printf("Voce comprou %d de %s. Dinheiro restante: %d.\n", quantity, items[item_to_buy_id].name, player.money);
                        } else {
                            printf("Inventario cheio para %s! Voce so pode carregar ate %d unidades deste item.\n", items[item_to_buy_id].name, MAX_ITEM_QUANTITY);
                        }
                    } else {
                        printf("Dinheiro insuficiente para comprar %d de %s.\n", quantity, items[item_to_buy_id].name);
                    }
                }
                printf("Pressione Enter para continuar...\n");
                while (getchar() != '\n');
                break;

            case 3: // Opcao Vender Mercadoria
                if (!loc_found || current_loc_detail.buys_item_id == -1) { // Verifica se esta em local vazio ou nao compra
                    printf("Voce esta em uma area vazia ou este local nao compra mercadorias.\n");
                } else {
                    int item_to_sell_id = current_loc_detail.buys_item_id; // ID do item que o local compra
                    int item_price = current_loc_detail.base_buy_price; // Preco do item que o local compra
                    int quantity; // Quantidade a ser vendida

                    printf("Este local compra %s por %d moedas cada.\n", items[item_to_sell_id].name, item_price);
                    printf("Quantos %s deseja vender? (Voce tem %d no inventario): ", items[item_to_sell_id].name, player.inventory[item_to_sell_id]);

                    // Validacao da quantidade de venda
                    while (scanf("%d", &quantity) != 1 || quantity <= 0) {
                        printf("Quantidade invalida. Digite um numero positivo: ");
                        while (getchar() != '\n');
                    }
                    while (getchar() != '\n');

                    // Verifica se o jogador tem a quantidade no inventario
                    if (player.inventory[item_to_sell_id] >= quantity) {
                        player.money += quantity * item_price; // Aumenta o dinheiro
                        player.inventory[item_to_sell_id] -= quantity; // Reduz a quantidade no inventario
                        printf("Voce vendeu %d de %s. Dinheiro atual: %d.\n", quantity, items[item_to_sell_id].name, player.money);
                    } else {
                        printf("Voce nao tem %d de %s para vender.\n", quantity, items[item_to_sell_id].name);
                    }
                }
                printf("Pressione Enter para continuar...\n");
                while (getchar() != '\n');
                break;

            case 4: // Opcao Ver Status (apenas para atualizar a tela)
                printf("Status atualizado. Pressione Enter para continuar...\n");
                while (getchar() != '\n');
                // O loop principal (while(!game_over)) se encarregara de redesenhar a tela
                break;

            case 5: // Opcao Sair do Jogo
                game_over = true; // Define a flag para encerrar o loop principal
                printf("Obrigado por jogar Ilha do Mercador! Dinheiro final: %d moedas.\n", player.money);
                break;

            default:
                // Este 'default' geralmente nao sera alcancado devido a validacao de input,
                // mas e boa pratica para lidar com casos inesperados.
                printf("Opcao invalida (erro interno no programa).\n");
                printf("Pressione Enter para continuar...\n");
                while (getchar() != '\n');
                break;
        } // Fim do switch
    } // Fim do loop while (!game_over)

    return 0; // Indica que o programa terminou com sucesso
} // Fim da funcao main()
