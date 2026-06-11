#ifndef PRODUTO_H
#define PRODUTO_H
#include <vector>
#include "sqlite/sqlite3.h"
#include "../types/produto_struct.h"

using namespace std;

bool salvarProduto(sqlite3* db, struct Produto p);
vector<Produto> listarProdutos(sqlite3* db);
Produto atualizarProduto(sqlite3* db, int id, struct Produto p);
Produto deletarProduto(sqlite3* db, int id);

#endif