#include "view.h"
#include <stdio.h>
#include <cstdlib>
#include <unistd.h>

char telaSucessoDeletar(Produto produtoDeletado) {
    printf("PRODUTO DELETADO COM SUCESSO!\n");
    printf("ID: %d\n", produtoDeletado.id);
    printf("NOME: %s\n", produtoDeletado.nome);
    sleep(2);
    printf("DESEJA CONTINUAR? (S/N): ");
    char opcao;
    scanf(" %c", &opcao);
    return opcao;
}