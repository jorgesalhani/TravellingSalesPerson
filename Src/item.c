#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "item.h"

struct item_ {
  int cidade;
  int conexoes[MAX_CONEXOES];
  int distancias[MAX_CONEXOES];
  int numero_conexoes;
};

ITEM* item_criar(int cidade) {
  ITEM* item = (ITEM*)malloc(sizeof(ITEM));
  if (item != NULL) {
    item->cidade = cidade;
    item->numero_conexoes = 0;
  }
  return item;
}

bool item_adicionar_conexao(ITEM* item, int cidade_destino, int distancia) {
  if (item == NULL) return false;
  int n_conexoes = item->numero_conexoes;
  (item->conexoes)[n_conexoes] = cidade_destino;
  (item->distancias)[n_conexoes] = distancia;
  item->numero_conexoes++;
  return true;
}

bool item_apagar(ITEM** end_item) {
  if (*end_item == NULL) return false;
  free(*end_item);
  *end_item = NULL;
  return true;
}

void item_imprimir(ITEM* item) {
  if (item == NULL) return;
  printf("| Cidade: %d\n", item->cidade);
  printf("| Conexoes: ");
  for (int i = 0; i < item->numero_conexoes; i++) printf("%d ", item->conexoes[i]);
  printf("\n");
  printf("| Distanc.: ");
  for (int i = 0; i < item->numero_conexoes; i++) printf("%d ", item->distancias[i]);
  printf("\n\n");
}

int item_get_cidade(ITEM* item) {
  if (item == NULL) return -1;
  return item->cidade;
}