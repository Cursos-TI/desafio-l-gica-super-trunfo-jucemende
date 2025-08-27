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

int main(void) {
    Carta carta1, carta2;

    /* --- Cadastro da Carta 1 --- */
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &carta1.estado);

    printf("Codigo da carta (ex: 01): ");
    scanf("%d", &carta1.codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta1.cidade);

    printf("Populacao: ");
    scanf("%lu", &carta1.populacao);

    printf("Area (km²): ");
    scanf("%f", &carta1.area);

    printf("PIB (em bilhoes): ");
    scanf("%f", &carta1.pib);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta1.pontos_turisticos);

    printf("\n");

    /* --- Cadastro da Carta 2 --- */
    printf("=== Cadastro da Carta 2 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &carta2.estado);

    printf("Codigo da carta (ex: 01): ");
    scanf("%d", &carta2.codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta2.cidade);

    printf("Populacao: ");
    scanf("%lu", &carta2.populacao);

    printf("Area (km²): ");
    scanf("%f", &carta2.area);

    printf("PIB (em bilhoes): ");
    scanf("%f", &carta2.pib);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    /* --- Exibicao das cartas --- */
    printf("\n=========================\n");
    printf("      CARTA 1\n");
    printf("=========================\n");
    printf("%c%02d - %s\n", carta1.estado, carta1.codigo, carta1.cidade);
    printf("Populacao: %lu\n", carta1.populacao);
    printf("Area: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhoes\n", carta1.pib);
    printf("Pontos turisticos: %d\n", carta1.pontos_turisticos);

    printf("\n=========================\n");
    printf("      CARTA 2\n");
    printf("=========================\n");
    printf("%c%02d - %s\n", carta2.estado, carta2.codigo, carta2.cidade);
    printf("Populacao: %lu\n", carta2.populacao);
    printf("Area: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhoes\n", carta2.pib);
    printf("Pontos turisticos: %d\n", carta2.pontos_turisticos);

    /* --- Comparacao (exemplo: POPULACAO) --- */
    printf("\n===== RESULTADO DA COMPARACAO =====\n");

    if (carta1.pib > carta2.pib) {
        printf("Carta vencedora: %c%02d - %s (maior PIB)\n",
               carta1.estado, carta1.codigo, carta1.cidade);
    } else if (carta2.pib > carta1.pib) {
        printf("Carta vencedora: %c%02d - %s (maior PIB)\n",
               carta2.estado, carta2.codigo, carta2.cidade);
    } else {
        printf("Empate em PIB!\n\n");
    }

    return 0;
}
