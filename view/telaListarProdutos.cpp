#include "view.h"
#include <stdio.h>
#include <cstdlib>

char telaListarProdutos(vector<Produto> produtos) {
    printf("\n%-5s %-20s %-10s\n", "ID", "NOME", "PRECO");
    printf("----------------------------------------\n");

    for (int i = 0; i < produtos.size(); i++) {
        printf("%-5d %-20s %-10.2f\n", produtos[i].id, produtos[i].nome, produtos[i].preco);
    }

    printf("\nDeseja voltar ao menu principal? (S/N): ");
    char opcao;
    scanf(" %c", &opcao);
    return opcao;
}