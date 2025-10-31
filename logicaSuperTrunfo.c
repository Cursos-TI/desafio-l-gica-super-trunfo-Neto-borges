#include <stdio.h>

int main() {
    // ======= Cadastro das Cartas =======
    // Carta 1
    char estado1;
    char codigo1[5];
    char nome1[50];
    unsigned long int populacao1;
    float area1, pib1;
    int turismo1;
    float densidade1, pibPerCapita1;

    // Carta 2
    char estado2;
    char codigo2[5];
    char nome2[50];
    unsigned long int populacao2;
    float area2, pib2;
    int turismo2;
    float densidade2, pibPerCapita2;

    // ======= Entrada dos Dados =======
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Digite o estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Digite o codigo (ex: A01): ");
    scanf("%s", codigo1);

    printf("Digite o nome da cidade (sem espacos): ");
    scanf("%s", nome1);

    printf("Digite a populacao: ");
    scanf("%lu", &populacao1);

    printf("Digite a area (km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB (em bilhoes): ");
    scanf("%f", &pib1);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &turismo1);

    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Digite o estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Digite o codigo (ex: B02): ");
    scanf("%s", codigo2);

    printf("Digite o nome da cidade (sem espacos): ");
    scanf("%s", nome2);

    printf("Digite a populacao: ");
    scanf("%lu", &populacao2);

    printf("Digite a area (km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB (em bilhoes): ");
    scanf("%f", &pib2);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &turismo2);

    // ======= Cálculos =======
    densidade1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000.0) / populacao1;

    densidade2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0) / populacao2;

    // ======= Exibição das Cartas =======
    printf("\n--- CARTA 1 ---\n");
    printf("Estado: %c | Codigo: %s | Cidade: %s\n", estado1, codigo1, nome1);
    printf("Populacao: %lu | Area: %.2f km² | PIB: %.2f bilhoes | Pontos Turisticos: %d\n", populacao1, area1, pib1, turismo1);
    printf("Densidade: %.2f hab/km² | PIB per Capita: %.2f reais\n", densidade1, pibPerCapita1);

    printf("\n--- CARTA 2 ---\n");
    printf("Estado: %c | Codigo: %s | Cidade: %s\n", estado2, codigo2, nome2);
    printf("Populacao: %lu | Area: %.2f km² | PIB: %.2f bilhoes | Pontos Turisticos: %d\n", populacao2, area2, pib2, turismo2);
    printf("Densidade: %.2f hab/km² | PIB per Capita: %.2f reais\n", densidade2, pibPerCapita2);

    // ======= Menu de Comparação =======
    int atributo1, atributo2;
    float valor1_carta1 = 0, valor1_carta2 = 0;
    float valor2_carta1 = 0, valor2_carta2 = 0;

    printf("\n======= MENU DE COMPARACAO =======\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Populacional\n");
    printf("6 - PIB per Capita\n");

    printf("\nEscolha o primeiro atributo para comparar: ");
    scanf("%d", &atributo1);

    // Menu dinâmico: impede escolher o mesmo atributo duas vezes
    printf("\nEscolha o segundo atributo (diferente do primeiro): ");
    scanf("%d", &atributo2);
    while (atributo2 == atributo1) {
        printf("Atributo repetido! Escolha outro: ");
        scanf("%d", &atributo2);
    }

    // ======= Comparação =======
    // Função interna simulada via switch
    for (int i = 1; i <= 2; i++) {
        int atributo = (i == 1) ? atributo1 : atributo2;
        float *v1 = (i == 1) ? &valor1_carta1 : &valor2_carta1;
        float *v2 = (i == 1) ? &valor1_carta2 : &valor2_carta2;

        switch (atributo) {
            case 1: // População
                *v1 = populacao1;
                *v2 = populacao2;
                break;
            case 2: // Área
                *v1 = area1;
                *v2 = area2;
                break;
            case 3: // PIB
                *v1 = pib1;
                *v2 = pib2;
                break;
            case 4: // Pontos Turísticos
                *v1 = turismo1;
                *v2 = turismo2;
                break;
            case 5: // Densidade
                *v1 = densidade1;
                *v2 = densidade2;
                break;
            case 6: // PIB per Capita
                *v1 = pibPerCapita1;
                *v2 = pibPerCapita2;
                break;
            default:
                printf("Atributo invalido!\n");
                return 1;
        }
    }

    // ======= Lógica de Comparação =======
    // Para densidade populacional, vence o menor valor
    int carta1_vitorias = 0, carta2_vitorias = 0;

    // Comparação 1
    if (atributo1 == 5) {
        if (valor1_carta1 < valor1_carta2) carta1_vitorias++;
        else if (valor1_carta2 < valor1_carta1) carta2_vitorias++;
    } else {
        if (valor1_carta1 > valor1_carta2) carta1_vitorias++;
        else if (valor1_carta2 > valor1_carta1) carta2_vitorias++;
    }

    // Comparação 2
    if (atributo2 == 5) {
        if (valor2_carta1 < valor2_carta2) carta1_vitorias++;
        else if (valor2_carta2 < valor2_carta1) carta2_vitorias++;
    } else {
        if (valor2_carta1 > valor2_carta2) carta1_vitorias++;
        else if (valor2_carta2 > valor2_carta1) carta2_vitorias++;
    }

    // Soma final (atributos combinados)
    float soma1 = valor1_carta1 + valor2_carta1;
    float soma2 = valor1_carta2 + valor2_carta2;

    // ======= Exibição do Resultado =======
    printf("\n======= RESULTADO FINAL =======\n");
    printf("Carta 1 (%s) - Soma dos atributos: %.2f\n", nome1, soma1);
    printf("Carta 2 (%s) - Soma dos atributos: %.2f\n", nome2, soma2);

    if (soma1 > soma2)
        printf("\nResultado: Carta 1 (%s) venceu!\n", nome1);
    else if (soma2 > soma1)
        printf("\nResultado: Carta 2 (%s) venceu!\n", nome2);
    else
        printf("\nResultado: Empate!\n");

    return 0;
}

