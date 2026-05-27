# Documentação do Projeto de Cadastro de Produtos

## 1. Visão Geral

Este projeto é um sistema de cadastro de produtos em C++ que utiliza SQLite para armazenar os dados em um banco local.
A aplicação segue o padrão de arquitetura MVC (Model-View-Controller) para separar responsabilidades de interface, lógica de controle e persistência de dados.

## 2. Objetivo

Permitir cadastrar produtos e listar produtos já cadastrados em um banco SQLite.

## 3. Estrutura do Projeto

```
Proj_sistema_cadastro_produto/
├── main.cpp
├── controller/
│   ├── controllers.h
│   ├── menu_controller.cpp
│   └── produto_controller.cpp
├── model/
│   ├── db_conexao/
│   │   ├── db.cpp
│   │   └── db.h
│   ├── produto.cpp
│   ├── produto.h
│   └── sqlite/
│       ├── sqlite3.c
│       └── sqlite3.h
├── types/
│   └── produto_struct.h
├── view/
│   ├── menuInicial.cpp
│   ├── telaCadastroProduto.cpp
│   ├── telaListarProdutos.cpp
│   └── view.h
├── sistema.db
└── README.md
```

## 4. Arquitetura

### 4.1 Model (Modelo)
Responsável por acessar e manipular os dados.

- `model/produto.cpp` e `model/produto.h`
  - `salvarProduto(sqlite3* db, Produto p)` insere um produto na tabela `produtos`.
  - `listarProdutos(sqlite3* db)` busca todos os produtos cadastrados.

- `model/db_conexao/db.cpp` e `model/db_conexao/db.h`
  - `conectar()` abre o banco `sistema.db` e cria a tabela `produtos`, se necessário.
  - `desconectar(sqlite3* db)` fecha a conexão.

### 4.2 View (Visão)
Responsável pela interação com o usuário via terminal.

- `view/menuInicial.cpp`
  - Exibe o menu principal e retorna a opção escolhida.

- `view/telaCadastroProduto.cpp`
  - Solicita o nome e o preço do produto.
  - Mostra mensagem de sucesso ou erro após o cadastro.

- `view/telaListarProdutos.cpp`
  - Exibe a lista de produtos cadastrados.
  - Permite retornar ao menu principal.

- `view/view.h`
  - Declara as funções de apresentação usadas pelas views.

### 4.3 Controller (Controlador)
Responsável por receber a opção do usuário, processar as ações e coordenar Model/View.

- `controller/menu_controller.cpp`
  - Executa o menu inicial e chama os outros controladores dependendo da escolha.

- `controller/produto_controller.cpp`
  - `controllerCadastrarProduto(sqlite3* db)` obtém o produto da view e pede ao model para salvar.
  - `controllerListarProdutos(sqlite3* db)` busca todos os produtos no model e exibe pela view.

- `controller/controllers.h`
  - Declara os controladores principais do sistema.

## 5. Arquivo de Tipos

- `types/produto_struct.h`
  - Define a struct `Produto` com os campos:
    - `int id`
    - `char nome[50]`
    - `double preco`

## 6. Banco de Dados

O banco de dados é `sistema.db` e possui a tabela `produtos` com a estrutura:

- `id_produto INTEGER PRIMARY KEY AUTOINCREMENT`
- `nome_produto TEXT NOT NULL`
- `preco REAL`

A tabela é criada automaticamente na primeira execução, pelo código em `model/db_conexao/db.cpp`.

## 7. Como Compilar

No terminal dentro da pasta do projeto, execute:

```bash
gcc -c model/sqlite/sqlite3.c -o model/sqlite/sqlite3.o

g++ main.cpp model/db_conexao/db.cpp model/produto.cpp model/sqlite/sqlite3.o controller/menu_controller.cpp controller/produto_controller.cpp view/menuInicial.cpp view/telaCadastroProduto.cpp view/telaListarProdutos.cpp -o prototipo_projeto -lpthread -ldl
```

> Observação: em Windows, execute o binário gerado como `prototipo_projeto.exe`.

## 8. Como Executar

```bash
./prototipo_projeto
```

Em Windows:

```powershell
.\prototipo_projeto.exe
```

## 9. Fluxo de Uso

1. O usuário inicia o programa pelo `main.cpp`.
2. `main()` conecta ao banco e chama `controllerMenuInicial(db)`.
3. O menu exibe as opções:
   - Cadastrar novo produto
   - Listar produtos
   - Atualizar produto (não implementado)
   - Deletar produto (não implementado)
   - Sair
4. Se escolher cadastrar, a tela de cadastro coleta dados e o produto é salvo no banco.
5. Se escolher listar, o programa mostra os produtos existentes.
6. O usuário pode voltar ao menu principal ou sair.

## 10. Observações

- As opções de atualizar e deletar produto estão presentes no menu, mas ainda não implementadas.
- O uso de `system("cls")` e `sleep(2)` faz o projeto depender de comandos do sistema e pode não funcionar da mesma forma em todos os ambientes.
- O campo `nome` aceita até 49 caracteres.

