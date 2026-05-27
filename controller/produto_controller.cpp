#include "controllers.h"
#include <stdio.h>

void controllerCadastrarProduto() {
    sqlite3* db = conectar();
    Produto novoProduto = telaCadastroProduto();
    bool sucesso = salvarProduto(db, novoProduto);
    telaSucessoCadastro(sucesso);
    controllerMenuInicial();
    desconectar(db);
}

    void controllerListarProdutos() {
        sqlite3* db = conectar(); 
        vector<Produto> produtos = listarProdutos(db);
        char opcao = telaListarProdutos(produtos);

      if (opcao == 'S' || opcao == 's') {
    desconectar(db);
    controllerMenuInicial();
        } else {
          desconectar(db);
          exit(0);
}
    }