#pragma once

#include "../sqlite/sqlite3.h"

sqlite3* conectar();
void desconectar(sqlite3* db);