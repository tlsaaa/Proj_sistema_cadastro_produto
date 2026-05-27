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