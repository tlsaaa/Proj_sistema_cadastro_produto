#include "controllers.h"
#include <stdio.h>

void controllerCadastrarProduto(sqlite3* db) {
    Produto p;
    printf("__CADASTRO DE PRODUTOS__\n");
    printf("Nome: ");
    scanf("%49s", p.nome);
    printf("Preco: ");
    scanf("%lf", &p.preco);

    salvarProduto(db, p);
    printf("Produto cadastrado!\n");
}

void controllerListarProdutos(sqlite3* db) {
    vector<Produto> produtos = listarProdutos(db);
    char opcao = telaListarProdutos(produtos);

    if (opcao != 'S' && opcao != 's') {
        exit(0);
    }
    
    if (opcao == 'N' || opcao == 'n') {
        exit(0);
    }
}