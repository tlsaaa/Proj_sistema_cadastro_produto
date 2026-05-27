#include "produto.h"
#include <stdio.h>
#include <string.h>

void salvarProduto(sqlite3* db, struct Produto p) {
    if (db == NULL) {
        printf("Erro: banco de dados nao conectado!\n");
        return;
    }

    sqlite3_stmt* stmt;
    const char* sql =
        "INSERT INTO produtos (nome_produto, preco) VALUES (?, ?);";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        printf("Erro no prepare: %s\n", sqlite3_errmsg(db));
        return;
    }

    sqlite3_bind_text(stmt, 1, p.nome, -1, SQLITE_STATIC);
    sqlite3_bind_double(stmt, 2, p.preco);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        printf("Erro ao inserir: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);
}

vector<Produto> listarProdutos(sqlite3* db) {
    sqlite3_stmt* stmt;
    const char* sql = "SELECT id_produto, nome_produto, preco FROM produtos;";

    vector<Produto> produtos;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        printf("Erro ao listar: %s\n", sqlite3_errmsg(db));
        return produtos;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Produto p;
        p.id = sqlite3_column_int(stmt, 0);
        strncpy(p.nome, (const char*)sqlite3_column_text(stmt, 1), 49);
        p.nome[49] = '\0';
        p.preco = sqlite3_column_double(stmt, 2);
        produtos.push_back(p);
    }

    sqlite3_finalize(stmt);
    return produtos;
}