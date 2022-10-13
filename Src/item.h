#ifndef ITEM_H
  #define ITEM_H
  
  #include <stdbool.h>

  #define MAX_CONEXOES 20

  typedef struct item_ ITEM;

  ITEM* item_criar(int cidade);
  bool item_adicionar_conexao(ITEM* item, int cidade_destino, int distancia);
  bool item_apagar(ITEM** end_item);
  void item_imprimir(ITEM* item);
  int item_get_cidade(ITEM* item);

  bool item_set_numero_conexoes(ITEM *item, int chave);
  int item_get_numero_conexoes(ITEM *item);

  int item_get_conexao(ITEM *item, int indice);
  int item_get_distancia(ITEM *item, int indice);

#endif