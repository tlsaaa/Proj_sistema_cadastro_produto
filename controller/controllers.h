#ifndef CONTROLLERS_H
#define CONTROLLERS_H

#include "../model/db_conexao/db.h"
#include "../model/sqlite/sqlite3.h"
#include "../model/produto.h"
#include "../view/view.h"
#include <cstdlib>
#include <vector>
using namespace std;

void controllerMenuInicial();
void controllerCadastrarProduto();
void controllerListarProdutos();

#endif