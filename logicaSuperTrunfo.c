#include <stdio.h>

typedef struct {
    char estado;
    int codigo;
    char cidade[50];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

/* Função para cadastrar uma carta */
void cadastrarCarta(Carta *c) {
    printf("Estado (A-H): ");
    scanf(" %c", &c->estado);

    printf("Codigo da carta (ex: 01): ");
    scanf("%d", &c->codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", c->cidade);

    printf("Populacao: ");
    scanf("%lu", &c->populacao);

    printf("Area (km²): ");
    scanf("%f", &c->area);

    printf("PIB (em bilhoes): ");
    scanf("%f", &c->pib);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &c->pontos_turisticos);

    printf("\n");
}

/* Função para exibir uma carta */
void exibirCarta(Carta c) {
    printf("%c%02d - %s\n", c.estado, c.codigo, c.cidade);
    printf("Populacao: %lu\n", c.populacao);
    printf("Area: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhoes\n", c.pib);
    printf("Pontos turisticos: %d\n", c.pontos_turisticos);
}

/* Função que retorna o valor numérico de um atributo */
float getAtributo(Carta c, int opcao) {
    switch (opcao) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontos_turisticos;
        default: return -1; // erro
    }
}

/* Função para imprimir nome do atributo */
const char* nomeAtributo(int opcao) {
    switch (opcao) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "PIB";
        case 4: return "Pontos turisticos";
        default: return "Desconhecido";
    }
}

/* Função de comparação mestre */
void compararCartas(Carta c1, Carta c2, int atributo1, int atributo2) {
    float v1_c1 = getAtributo(c1, atributo1);
    float v1_c2 = getAtributo(c2, atributo1);

    printf("\n===== RESULTADO DA COMPARACAO =====\n");
    printf("Primeiro criterio: %s\n", nomeAtributo(atributo1));
    printf("Segundo criterio (desempate): %s\n", nomeAtributo(atributo2));

    if (v1_c1 > v1_c2) {
        printf("Vencedora: %s (maior %s)\n", c1.cidade, nomeAtributo(atributo1));
    } else if (v1_c2 > v1_c1) {
        printf("Vencedora: %s (maior %s)\n", c2.cidade, nomeAtributo(atributo1));
    } else {
        // empate -> comparar segundo atributo
        float v2_c1 = getAtributo(c1, atributo2);
        float v2_c2 = getAtributo(c2, atributo2);

        (v2_c1 > v2_c2) ? 
            printf("Empate em %s! Vencedora: %s (maior %s)\n", nomeAtributo(atributo1), c1.cidade, nomeAtributo(atributo2)) :
        (v2_c2 > v2_c1) ?
            printf("Empate em %s! Vencedora: %s (maior %s)\n", nomeAtributo(atributo1), c2.cidade, nomeAtributo(atributo2)) :
            printf("Empate total! (%s e %s iguais)\n", nomeAtributo(atributo1), nomeAtributo(atributo2));
    }
}

int main(void) {
    Carta carta1, carta2;
    int atributo1, atributo2;

    printf("=== Cadastro da Carta 1 ===\n");
    cadastrarCarta(&carta1);

    printf("=== Cadastro da Carta 2 ===\n");
    cadastrarCarta(&carta2);

    /* Exibindo cartas */
    printf("\n=========================\n");
    printf("      CARTA 1\n");
    printf("=========================\n");
    exibirCarta(carta1);

    printf("\n=========================\n");
    printf("      CARTA 2\n");
    printf("=========================\n");
    exibirCarta(carta2);

    /* Menu de comparação dinâmico */
    printf("\nEscolha o PRIMEIRO atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos turisticos\n");
    printf("Opcao: ");
    scanf("%d", &atributo1);

    printf("\nAgora escolha o SEGUNDO atributo (para desempate, diferente do primeiro):\n");
    for (int i = 1; i <= 4; i++) {
        if (i != atributo1) {
            printf("%d - %s\n", i, nomeAtributo(i));
        }
    }
    printf("Opcao: ");
    scanf("%d", &atributo2);

    compararCartas(carta1, carta2, atributo1, atributo2);

    return 0;
}