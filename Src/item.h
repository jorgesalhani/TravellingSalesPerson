#ifndef ITEM_H
  #define ITEM_H
  #define MAX_CONEXOES 20
  #include <stdbool.h>

  typedef struct item_ ITEM;

  ITEM* item_criar(int cidade);
  bool item_adicionar_conexao(ITEM* item, int cidade_destino, int distancia);
  bool item_apagar(ITEM** end_item);
  void item_imprimir(ITEM* item);
  int item_get_cidade(ITEM* item);

#endif