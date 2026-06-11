#include "produto.h"
#include <stdio.h>
#include <string.h>

bool salvarProduto(sqlite3* db, struct Produto p) {
    if (db == NULL) {
        printf("Erro: banco de dados nao conectado!\n");
        return false;
    }

    sqlite3_stmt* stmt;
    const char* sql =
        "INSERT INTO produtos (nome_produto, preco, quantidade) VALUES (?, ?, ?);";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        printf("Erro no prepare: %s\n", sqlite3_errmsg(db));
        return false;
    }

    sqlite3_bind_text(stmt, 1, p.nome, -1, SQLITE_STATIC);
    sqlite3_bind_double(stmt, 2, p.preco);
    sqlite3_bind_int(stmt, 3, p.quantidade);
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        printf("Erro ao inserir: %s\n", sqlite3_errmsg(db));
        return false;
    }

    sqlite3_finalize(stmt);
    return true;
}

vector<Produto> listarProdutos(sqlite3* db) {
    sqlite3_stmt* stmt;
    const char* sql = "SELECT id_produto, nome_produto, preco, quantidade FROM produtos;";

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
        p.quantidade = sqlite3_column_int(stmt, 3);
        produtos.push_back(p);
    }

    sqlite3_finalize(stmt);
    return produtos;
}

Produto atualizarProduto(sqlite3* db, int id, struct Produto p) {
    sqlite3_stmt* stmt;
    Produto produtoAtualizado = {0};

    const char* sql = NULL;

    if (p.nome[0] != '\0') {
        sql = "UPDATE produtos SET nome_produto = ? WHERE id_produto = ?;";
    } else if (p.preco != 0.0) {
        sql = "UPDATE produtos SET preco = ? WHERE id_produto = ?;";
    } else if (p.quantidade != 0) {
        sql = "UPDATE produtos SET quantidade = ? WHERE id_produto = ?;";
    } else {
        printf("Nenhum campo para atualizar.\n");
        return produtoAtualizado;
    }

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        printf("Erro ao preparar update: %s\n", sqlite3_errmsg(db));
        return produtoAtualizado;
    }

    if (p.nome[0] != '\0')      sqlite3_bind_text(stmt, 1, p.nome, -1, SQLITE_STATIC);
    else if (p.preco != 0.0)    sqlite3_bind_double(stmt, 1, p.preco);
    else if (p.quantidade != 0) sqlite3_bind_int(stmt, 1, p.quantidade);

    sqlite3_bind_int(stmt, 2, id);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        printf("Erro ao executar update: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return produtoAtualizado;
    }

    sqlite3_finalize(stmt);

    const char* sql1 = "SELECT id_produto, nome_produto, preco, quantidade FROM produtos WHERE id_produto = ?;";

    if (sqlite3_prepare_v2(db, sql1, -1, &stmt, NULL) != SQLITE_OK) {
        printf("Erro ao buscar produto: %s\n", sqlite3_errmsg(db));
        return produtoAtualizado;
    }

    sqlite3_bind_int(stmt, 1, id);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        produtoAtualizado.id = sqlite3_column_int(stmt, 0);
        strncpy(produtoAtualizado.nome, (const char*)sqlite3_column_text(stmt, 1), 49);
        produtoAtualizado.nome[49] = '\0';
        produtoAtualizado.preco      = sqlite3_column_double(stmt, 2);
        produtoAtualizado.quantidade = sqlite3_column_int(stmt, 3);
    }

    sqlite3_finalize(stmt);
    return produtoAtualizado;
}

Produto deletarProduto(sqlite3* db, int id) {
    sqlite3_stmt* stmt;
    Produto produtoDeletado = {0};

    const char* sqlSelect = "SELECT id_produto, nome_produto, preco, quantidade FROM produtos WHERE id_produto = ?;";
    if (sqlite3_prepare_v2(db, sqlSelect, -1, &stmt, NULL) != SQLITE_OK) {
        printf("Erro ao preparar select: %s\n", sqlite3_errmsg(db));
        return produtoDeletado;
    }

    sqlite3_bind_int(stmt, 1, id);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        produtoDeletado.id = sqlite3_column_int(stmt, 0);
        strncpy(produtoDeletado.nome, (const char*)sqlite3_column_text(stmt, 1), 49);
        produtoDeletado.nome[49] = '\0';
        produtoDeletado.preco      = sqlite3_column_double(stmt, 2);
        produtoDeletado.quantidade = sqlite3_column_int(stmt, 3);
    } else {
        printf("Produto com ID %d nao encontrado.\n", id);
        sqlite3_finalize(stmt);
        return produtoDeletado;
    }
    sqlite3_finalize(stmt);

    const char* sqlDelete = "DELETE FROM produtos WHERE id_produto = ?;";
    if (sqlite3_prepare_v2(db, sqlDelete, -1, &stmt, NULL) != SQLITE_OK) {
        printf("Erro ao preparar delete: %s\n", sqlite3_errmsg(db));
        return produtoDeletado;
    }

    sqlite3_bind_int(stmt, 1, id);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        printf("Erro ao executar delete: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);
    return produtoDeletado;
}