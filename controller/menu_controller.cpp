#include "controllers.h"
#include "../view/view.h"
#include <cstdlib>
#include<stdio.h>

void controllerMenuInicial() { 
    sqlite3* db = conectar();
    int opcao = menuInicial();

    switch (opcao) {
        case 1:
            controllerCadastrarProduto();
            break;
        case 2:
            controllerListarProdutos();
            break;
        case 3:
            // controllerAtualizarProduto();
            break;
        case 4:
            // controllerDeletarProduto();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }
    desconectar(db);
}