#include <stdio.h>
#include "controller/controllers.h"
#include "model/db_conexao/db.h"

int main() {
    sqlite3* db = conectar();
    controllerMenuInicial(db);
    desconectar(db);
    return 0;
}