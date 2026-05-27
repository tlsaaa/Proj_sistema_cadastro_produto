# Comandos para Testar o Projeto

Para testar, digite esses comandos no terminal aberto na pasta do projeto:

```bash
gcc -c model/sqlite/sqlite3.c -o model/sqlite/sqlite3.o
```

Depois:

```bash
g++ main.cpp model/db_conexao/db.cpp model/produto.cpp model/sqlite/sqlite3.o controller/menu_controller.cpp controller/produto_controller.cpp view/menuInicial.cpp view/telaCadastroProduto.cpp view/telaListarProdutos.cpp -o prototipo_projeto -lpthread -ldl

```

Para executar o programa:

```bash
./prototipo_projeto
```

---

# Arquitetura MVC

## O que é MVC?

MVC (Model-View-Controller) é um padrão de arquitetura de software que separa uma aplicação em três camadas com responsabilidades distintas, facilitando a organização, manutenção e escalabilidade do código.

## As três camadas

**Model (Modelo)** — é responsável pelos dados e pela lógica de negócio. Ele acessa o banco de dados, valida informações e aplica as regras da aplicação. Não sabe nada sobre a interface do usuário.

**View (Visão)** — é responsável pela apresentação dos dados ao usuário. Exibe as informações recebidas do Controller e captura as entradas do usuário. Não contém lógica de negócio.

**Controller (Controlador)** — é o intermediário entre o Model e a View. Recebe as requisições do usuário, consulta o Model quando necessário e decide qual View exibir com os dados resultantes.

## Fluxo de funcionamento

```
Usuário → Controller → Model → Controller → View → Usuário
```

## Exemplo básico em C++

Estrutura de pastas:

```
projeto/
├── main.cpp
├── model/
│   └── produto.cpp / produto.h
├── view/
│   └── produto_view.cpp / produto_view.h
└── controller/
    └── produto_controller.cpp / produto_controller.h
```

### Model — `model/produto.h`

```cpp
#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>

class Produto {
public:
    int id;
    std::string nome;
    double preco;

    Produto(int id, std::string nome, double preco);
};

#endif
```

```cpp
// model/produto.cpp
#include "produto.h"

Produto::Produto(int id, std::string nome, double preco)
    : id(id), nome(nome), preco(preco) {}
```

### View — `view/produto_view.h`

```cpp
#ifndef PRODUTO_VIEW_H
#define PRODUTO_VIEW_H

#include "../model/produto.h"

class ProdutoView {
public:
    void exibirProduto(const Produto& produto);
};

#endif
```

```cpp
// view/produto_view.cpp
#include "produto_view.h"
#include <iostream>

void ProdutoView::exibirProduto(const Produto& produto) {
    std::cout << "ID: "    << produto.id    << "\n";
    std::cout << "Nome: "  << produto.nome  << "\n";
    std::cout << "Preço: " << produto.preco << "\n";
}
```

### Controller — `controller/produto_controller.h`

```cpp
#ifndef PRODUTO_CONTROLLER_H
#define PRODUTO_CONTROLLER_H

#include "../model/produto.h"
#include "../view/produto_view.h"

class ProdutoController {
private:
    ProdutoView view;
public:
    void mostrarProduto();
};

#endif
```

```cpp
// controller/produto_controller.cpp
#include "produto_controller.h"

void ProdutoController::mostrarProduto() {
    // Simula busca no banco de dados
    Produto produto(1, "Caneta", 2.50);

    // Passa os dados para a View
    view.exibirProduto(produto);
}
```

### Ponto de entrada — `main.cpp`

```cpp
#include "controller/produto_controller.h"

int main() {
    ProdutoController controller;
    controller.mostrarProduto();
    return 0;
}
```

### Saída esperada

```
ID: 1
Nome: Caneta
Preço: 2.5
```

## Resumo das responsabilidades

| Camada     | Responsabilidade                          |
|------------|-------------------------------------------|
| Model      | Dados, regras de negócio, banco de dados  |
| View       | Interface e apresentação ao usuário       |
| Controller | Intermediário: processa e direciona fluxo |

> O principal benefício do MVC é que cada camada pode ser modificada de forma independente, sem impactar as demais.