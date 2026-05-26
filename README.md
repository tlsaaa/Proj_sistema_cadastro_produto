para testar digite esses comandos no terminal que esteja aberto na pasta do projeto:
gcc -c model/sqlite/sqlite3.c -o model/sqlite/sqlite3.o


depois:
 g++ main.cpp model/db_conexao/db.cpp model/produto.cpp model/sqlite/sqlite3.o -o prototipo_projeto -lpthread -ldl


para executar o programa digite esse comando e ele vai abrir direto no terminal:
 ./prototipo_projeto 
