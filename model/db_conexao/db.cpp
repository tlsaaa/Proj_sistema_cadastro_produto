#include "db.h"
#include <stdio.h>


void criarTabelas (sqlite3* db){
    const char* sql = 
   "CREATE TABLE IF NOT EXISTS produtos ("
    "id_produto INTEGER PRIMARY KEY AUTOINCREMENT,"
    "nome_produto TEXT NOT NULL,"
    "preco REAL"
    ");";
    sqlite3_exec(db, sql, NULL, NULL, NULL);
}

sqlite3* conectar(){
    sqlite3* db;
    if(sqlite3_open("sistema.db", &db)!= SQLITE_OK){
        printf("erro ao conectar: %s\n", sqlite3_errmsg(db));
        return NULL;
    }
    criarTabelas(db);
    return db;
}

void desconectar(sqlite3* db){
    sqlite3_close(db);
}

