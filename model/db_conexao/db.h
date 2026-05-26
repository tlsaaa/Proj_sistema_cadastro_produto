#ifndef DB_H
#define DB_H

#include "../sqlite/sqlite3.h"

sqlite3* conectar();
void desconectar(sqlite3* db);



#endif