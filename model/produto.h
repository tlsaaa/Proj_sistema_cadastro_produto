#ifndef PRODUTO_H
#define PRODUTO_H


#include "sqlite/sqlite3.h"

struct Produto {
    int id;
    char nome[50];
    double preco;
};

void salvarProduto(sqlite3* db, struct Produto p);
void listarProdutos(sqlite3* db);

#endif
