#include "view.h"
#include <stdio.h>
#include <cstdlib>
#include <unistd.h>


Produto telaAtualizarProduto(){
Produto produto = {0};
int opcao;
printf("SELECIONE O QUE DESEJA ATUALIZAR:\n");
printf("1 - NOME\n");
printf("2 - PRECO\n");
printf("3 - QUANTIDADE\n");
scanf(" %d", &opcao);

switch (opcao) {
    case 1:
        printf("DIGITE O NOVO NOME: ");
        scanf(" %49[^\n]", produto.nome);
        break;
    case 2:
        printf("DIGITE O NOVO PRECO: ");
        scanf(" %lf", &produto.preco);
        break;
    case 3:
        printf("DIGITE A NOVA QUANTIDADE: ");
        scanf(" %d", &produto.quantidade);
        break;
    default:
        printf("OPCAO INVALIDA.\n");
        break;
    }
    return produto;
}

int telaParaPassarId() {
    int id;
    printf("DIGITE O ID DO PRODUTO QUE DESEJA ATUALIZAR: ");
    scanf(" %d", &id);
    return id;
}

char telaSucessoAtualizacao(Produto produtoAtualizado) {
    printf("PRODUTO ATUALIZADO COM SUCESSO!\n");
    printf("ID: %d\n", produtoAtualizado.id);
    printf("NOME: %s\n", produtoAtualizado.nome);
    printf("PRECO: %.2lf\n", produtoAtualizado.preco);
    printf("QUANTIDADE: %d\n", produtoAtualizado.quantidade);
    sleep(2);
    printf("DESEJA CONTINUAR? (S/N): ");
    char opcao;
    scanf(" %c", &opcao);
    return opcao;
}