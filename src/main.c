#include <stdio.h>

int main() {
    int opcaoModalidade;
    float distancia, peso, taxaBase = 0, valorTotal = 0;
    int totalEntregas = 0;
    float acumuladorValorTotal = 0;

    printf("=== SIMULADOR DE ENTREGAS ===\n");

    do {
        printf("\nEscolha a modalidade de entrega:\n");
        printf("1 - Padrao\n");
        printf("2 - Expressa\n");
        printf("3 - Internacional\n");
        printf("0 - Sair e ver resumo\n");
        printf("Digite a opcao: ");
        scanf("%d", &opcaoModalidade);

        if (opcaoModalidade == 0) {
            break;
        }

        if (opcaoModalidade < 1 || opcaoModalidade > 3) {
            printf("Opcao invalida! Tente novamente.\n");
            continue;
        }

        printf("Digite a distancia (em km): ");
        scanf("%f", &distancia);
        
        printf("Digite o peso do pacote (em kg): ");
        scanf("%f", &peso);

        if (distancia <= 0 || peso <= 0) {
            printf("Erro: Distancia e peso devem ser valores maiores que zero!\n");
            continue;
        }

        // Definir taxa base conforme a modalidade
        if (opcaoModalidade == 1) {
            taxaBase = 10.0 + (distancia * 1.5) + (peso * 0.5);
        } else if (opcaoModalidade == 2) {
            taxaBase = 20.0 + (distancia * 2.5) + (peso * 1.0);
        } else if (opcaoModalidade == 3) {
            taxaBase = 50.0 + (distancia * 5.0) + (peso * 2.0);
        }

        valorTotal = taxaBase;

        printf("-> Valor calculado para esta entrega: R$ %.2f\n", valorTotal);

        totalEntregas++;
        acumuladorValorTotal += valorTotal;

    } while (1);

    printf("\n=== RESUMO FINAL DA SESSAO ===\n");
    printf("Total de entregas simuladas: %d\n", totalEntregas);
    printf("Valor total acumulado: R$ %.2f\n", acumuladorValorTotal);
    printf("Programa encerrado com sucesso.\n");

    return 0;
}