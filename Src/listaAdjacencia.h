#ifndef LISTA_ADJACENCIA_H
  #define LISTA_ADJACENCIA_H
  #define MAX_ITENS 20
  #include <stdbool.h>
  #include "item.h"

  typedef struct lista_adjacencia_ LISTA_ADJACENCIA;

  LISTA_ADJACENCIA* lista_adjacencia_criar();
  void lista_adjacencia_apagar(LISTA_ADJACENCIA** end_lista_adjacencia);
  bool lista_adjacencia_inserir(LISTA_ADJACENCIA* lista_adjacencia, ITEM* item);
  void lista_adjacencia_imprimir(LISTA_ADJACENCIA* lista_adjacencia);
  int lista_adjacencia_get_numero_total_cidades(LISTA_ADJACENCIA* lista_adjacencia);
  bool lista_adjacencia_vazia(LISTA_ADJACENCIA* lista_adjacencia);
  bool lista_adjacencia_cheia(LISTA_ADJACENCIA* lista_adjacencia);
  void lista_adjacencia_input_conexoes(LISTA_ADJACENCIA* lista_adjacencia);
  ITEM *lista_adjacencia_get_item(LISTA_ADJACENCIA* lista_adjacencia, int cidade);
  int lista_adjacencia_get_distancia(LISTA_ADJACENCIA* lista_adjacencia, int cidadeA, int cidadeB);
#endif