#include "view.h"
#include <stdio.h>
#include <cstdlib>


int menuInicial(){

    int opcao;
    system("cls");
    printf("BEM VINDO AO SISTEMA DE GERENCIAMENTO DE PRODUTOS\n");
    printf("ESCOLHA UMA DAS OPÇÕES ABAIXO:\n");
    printf("1 - CADASTRAR NOVO PRODUTO\n");
    printf("2 - LISTAR PRODUTOS\n");
    printf("3 - ATUALIZAR UM PRODUTO\n");
    printf("4 - DELETAR UM PRODUTO\n");
    printf("5 - SAIR\n");
    scanf("%d", &opcao);

    return opcao;

}