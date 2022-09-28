#include <stdio.h>
#include <stdlib.h>
#include "listaAdjacencia.h"
#include "item.h"

struct lista_adjacencia_ {
 ITEM* itens[MAX_ITENS];
 int num_cidades_inseridas;
 int total_cidades;
};

ITEM *lista_get_item(LISTA_ADJACENCIA* lista_adjacencia, int cidade)
{
  if (lista_adjacencia != NULL)
  {
    int i = 0;

    while (i < lista_adjacencia_get_numero_total_cidades)
    {
      if (item_get_cidade(lista_adjacencia->itens[i]) == cidade)
        return lista_adjacencia->itens[i];
      
      i++;
    }      
  }

  return false;
}


LISTA_ADJACENCIA* lista_adjacencia_criar(int total_cidades) {
  LISTA_ADJACENCIA* lista_adjacencia = (LISTA_ADJACENCIA*) malloc(sizeof(LISTA_ADJACENCIA));
  if (lista_adjacencia != NULL) {
    lista_adjacencia->total_cidades = total_cidades;
    lista_adjacencia->num_cidades_inseridas = 0;
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

  for (int i = 0; i < lista_adjacencia->num_cidades_inseridas; i++) {
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
  int num_total_cidades = lista_adjacencia_get_numero_total_cidades(lista_adjacencia);
  int cidade_A, cidade_B, dist;
  ITEM* item_novo;
  while (!feof(stdin)) {
    scanf("%d %d %d\n", &cidade_A, &cidade_B, &dist);

    item_novo = item_criar(cidade_A);

    ITEM* item = _lista_adjacencia_get_item_por_cidade(lista_adjacencia, item_novo);
    if (item != NULL) {
      item_adicionar_conexao(item, cidade_B, dist);
      item_apagar(&item_novo);
    }
    else {
      item_adicionar_conexao(item_novo, cidade_B, dist);
      lista_adjacencia_inserir(lista_adjacencia, item_novo);
    }
  }
}

ITEM* _lista_adjacencia_get_item_por_cidade(LISTA_ADJACENCIA* lista_adjacencia, ITEM* item) {
  if (lista_adjacencia == NULL || item == NULL || lista_adjacencia_vazia(lista_adjacencia)) return NULL;
  for (int i = 0; i < lista_adjacencia->num_cidades_inseridas; i++) {
    if (item_get_cidade(lista_adjacencia->itens[i]) == item_get_cidade(item)) {
      return lista_adjacencia->itens[i];
    }
  }
  return NULL;
}