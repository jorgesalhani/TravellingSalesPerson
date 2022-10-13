#include <stdio.h>
#include <stdlib.h>
#include "listaAdjacencia.h"
#include "item.h"

struct lista_adjacencia_ {
 ITEM* itens[MAX_ITENS];
 int num_cidades_inseridas;
 int total_cidades;
};

ITEM *lista_adjacencia_get_item(LISTA_ADJACENCIA* lista_adjacencia, int cidade)
{
  if (lista_adjacencia != NULL)
  {
    if (cidade <= lista_adjacencia_get_numero_total_cidades(lista_adjacencia))
      return lista_adjacencia->itens[cidade - 1];
  }

  return false;
}


LISTA_ADJACENCIA* lista_adjacencia_criar(int total_cidades) {
  LISTA_ADJACENCIA* lista_adjacencia = (LISTA_ADJACENCIA*) malloc(sizeof(LISTA_ADJACENCIA));
  if (lista_adjacencia != NULL) {
    lista_adjacencia->total_cidades = total_cidades;
    lista_adjacencia->num_cidades_inseridas = 0;
    for(int i = 1; i <= total_cidades; i++){
      ITEM* item = item_criar(i);
      lista_adjacencia_inserir(lista_adjacencia, item);
    }
  }
  return lista_adjacencia;
}

void lista_adjacencia_apagar(LISTA_ADJACENCIA** end_lista_adjacencia){
  LISTA_ADJACENCIA* lista_adjacencia = *end_lista_adjacencia;
  if (*end_lista_adjacencia == NULL) return;

  if (lista_adjacencia_vazia(lista_adjacencia)) {
    free(lista_adjacencia);
    return;
  }

  for (int i = 0; i < lista_adjacencia->total_cidades; i++) {
    free(lista_adjacencia->itens[i]);
    lista_adjacencia->itens[i]= NULL;
  }
  free(lista_adjacencia);
  lista_adjacencia = NULL;
  end_lista_adjacencia = NULL;
}

bool lista_adjacencia_inserir(LISTA_ADJACENCIA* lista_adjacencia, ITEM* item) {
  if (lista_adjacencia == NULL || item == NULL || lista_adjacencia_cheia(lista_adjacencia)) return false;
  int num_item = lista_adjacencia->num_cidades_inseridas;
  lista_adjacencia->itens[num_item] = item;
  lista_adjacencia->num_cidades_inseridas++;
  return true;
}

void lista_adjacencia_imprimir(LISTA_ADJACENCIA* lista_adjacencia) {
  if (lista_adjacencia == NULL) return;
  for (int i = 0; i < lista_adjacencia->num_cidades_inseridas; i++) {
    item_imprimir(lista_adjacencia->itens[i]);
  }
}

int lista_adjacencia_get_numero_total_cidades(LISTA_ADJACENCIA* lista_adjacencia) {
  if (lista_adjacencia == NULL) return -1;
  return lista_adjacencia->total_cidades;
}

bool lista_adjacencia_vazia(LISTA_ADJACENCIA* lista_adjacencia){
  if (lista_adjacencia == NULL) return false;
  return lista_adjacencia->num_cidades_inseridas == 0 ? true : false;
}

bool lista_adjacencia_cheia(LISTA_ADJACENCIA* lista_adjacencia) {
  if (lista_adjacencia == NULL) return false;
  return lista_adjacencia->num_cidades_inseridas == MAX_ITENS ? true : false;
}

void lista_adjacencia_input_conexoes(LISTA_ADJACENCIA* lista_adjacencia) {
  int cidade_A, cidade_B, dist;
  int cid[16] = {1, 2, 5, 1, 4, 1, 1, 3, 7, 2, 3, 2, 3, 4, 3, 0};
  int i = 0;
  while (cid[i] != 0) {
    // scanf("%d %d %d\n", &cidade_A, &cidade_B, &dist);

    ITEM* item = lista_adjacencia_get_item(lista_adjacencia, cid[i]);
    item_adicionar_conexao(item, cid[i+1], cid[i+2]);
    item = lista_adjacencia_get_item(lista_adjacencia, cid[i+1]);
    item_adicionar_conexao(item, cid[i], cid[i+2]);
    i=i+3;
  }
}

int lista_adjacencia_get_distancia(LISTA_ADJACENCIA* lista_adjacencia, int cidadeA, int cidadeB){
  
  ITEM* item = lista_adjacencia_get_item(lista_adjacencia, cidadeA);

  return item_get_distancia(item, cidadeB);
}