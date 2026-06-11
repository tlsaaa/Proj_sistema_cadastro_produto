#ifndef VIEW
#define VIEW_H
#include <vector>
#include "../types/produto_struct.h"
using namespace std;

int menuInicial();
Produto telaCadastroProduto();
char telaListarProdutos(vector<Produto> produtos);
void telaSucessoCadastro(bool sucesso);
Produto telaAtualizarProduto();
char telaSucessoAtualizacao(Produto produtoAtualizado);
int telaParaPassarId();
char telaSucessoDeletar(Produto produtoDeletado);

#endif