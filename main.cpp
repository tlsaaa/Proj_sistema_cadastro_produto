#include <stdio.h>
#include "model/db_conexao/db.h"
#include "controller/controllers.h"
int main() {
    sqlite3* db = conectar();

    controllerMenuInicial(db);

    desconectar(db);
    return 0;
}