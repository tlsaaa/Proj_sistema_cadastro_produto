#include <stdio.h>
#include "model/db_conexao/db.h"
#include "model/produto.h"

int main()
{
    sqlite3* db = conectar();

    struct Produto p;

    printf("__CADASTRO DE PRODUTOS__\n");
    printf("Nome: ");
    scanf("%49s", p.nome);

    printf("Preco: ");
    scanf("%lf", &p.preco);

    salvarProduto(db, p);

    printf("produto cadastrado \n");

    listarProdutos(db);
    

    desconectar(db);
    return 0;
    
}