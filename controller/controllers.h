#ifndef CONTROLLERS_H
#define CONTROLLERS_H

#include "../model/sqlite/sqlite3.h"
#include "../model/produto.h"
#include "../view/view.h"
#include <cstdlib>
#include <vector>
using namespace std;

void controllerMenuInicial(sqlite3* db);
void controllerCadastrarProduto(sqlite3* db);
void controllerListarProdutos(sqlite3* db);

#endif