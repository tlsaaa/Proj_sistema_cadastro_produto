#include "controllers.h"
#include <stdio.h>

void controllerCadastrarProduto(sqlite3* db) {
    Produto novoProduto = telaCadastroProduto();
    bool sucesso = salvarProduto(db, novoProduto);
    telaSucessoCadastro(sucesso);
    controllerMenuInicial(db);
    
}

    void controllerListarProdutos(sqlite3* db) { 
        vector<Produto> produtos = listarProdutos(db);
        char opcao = telaListarProdutos(produtos);

      if (opcao == 'S' || opcao == 's') {
    controllerMenuInicial(db);
        } else {
          exit(0);
}
    }

void controllerAtualizarProduto(sqlite3* db) {
    int id = telaParaPassarId();
    Produto produto = telaAtualizarProduto();
    Produto produtoAtualizado = atualizarProduto(db, id, produto);
    char opcao = telaSucessoAtualizacao(produtoAtualizado);
    if (opcao == 'S' || opcao == 's') {
        controllerMenuInicial(db);
    } else {
        exit(0);
    }
    controllerMenuInicial(db);
}