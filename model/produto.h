#ifndef PRODUTO_H
#define PRODUTO_H
#include <vector>
#include "sqlite/sqlite3.h"
#include "../types/produto_struct.h"

using namespace std;

void salvarProduto(sqlite3* db, struct Produto p);
vector<Produto> listarProdutos(sqlite3* db);

#endif