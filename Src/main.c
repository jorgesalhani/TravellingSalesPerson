#include <stdio.h>
#include <stdlib.h>
#include "listaAdjacencia.h"
#include "item.h"

void input_valores(int* end_total_cidades, int* end_cidade_inicial) {
  scanf("%d\n", end_total_cidades);
  scanf("%d\n", end_cidade_inicial);
}

int main(void) {

  int total_cidades, cidade_inicial;
  input_valores(&total_cidades, &cidade_inicial);

  LISTA_ADJACENCIA* lista_adj = lista_adjacencia_criar(total_cidades);

  lista_adjacencia_input_conexoes(lista_adj);

  lista_adjacencia_imprimir(lista_adj);

  lista_adjacencia_apagar(&lista_adj);
  return 0;
}