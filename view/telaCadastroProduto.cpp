#include "view.h"
#include <stdio.h>
#include <cstdlib>
#include <unistd.h>


Produto telaCadastroProduto(){
   Produto novoProduto;

printf("DIGITE O NOME DO PRODUTO: ");
scanf(" %49s", novoProduto.nome);
printf("DIGITE O PRECO DO PRODUTO: ");
scanf(" %lf", &novoProduto.preco);

return novoProduto;

}

void telaSucessoCadastro(bool sucesso) {
    system("cls");
    if (sucesso) {
        printf("PRODUTO CADASTRADO COM SUCESSO!\n");
    } else {
        printf("ERRO AO CADASTRAR PRODUTO! TENTE NOVAMENTE\n");
    }
    sleep(2);
}