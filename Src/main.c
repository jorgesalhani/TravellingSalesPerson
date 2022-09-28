#include <stdio.h>
#include <stdlib.h>
#include "listaAdjacencia.h"
#include "pilha.h"
#include "conexao.h"
#include "item.h"

void input_valores(int* end_total_cidades, int* end_cidade_inicial) {
  scanf("%d\n", end_total_cidades);
  scanf("%d\n", end_cidade_inicial);
}

CONEXAO *undo(PILHA *pilha, int *distancia_atual); // Desfaz o caminho percorrido.

int main(void)
{

  int total_cidades, cidade_inicial;
  input_valores(&total_cidades, &cidade_inicial);

  LISTA_ADJACENCIA* lista_adj = lista_adjacencia_criar(total_cidades);

  lista_adjacencia_input_conexoes(lista_adj);

  lista_adjacencia_imprimir(lista_adj);

  ITEM *cidade_atual = lista_get_item(lista_adj, cidade_inicial);
  PILHA *pilha = pilha_criar();
  int menor_distancia;
  int distancia_atual = 0;
  char *caminho;

  do
  {
    for (int i = 0; i < item_get_numero_conexoes(cidade_atual); i++) // Empilha todas cidades que podem ser alcançadas a partir da cidade atual.
    {
      int origem = item_get_cidade(cidade_atual);
      int destino = item_get_conexao(cidade_atual, i);
      int distancia = item_get_distancia(cidade_atual, i);

      CONEXAO *conexao = conexao_criar(origem, destino, distancia);

      pilha_empilhar(pilha, conexao);
    }

    // Desloca o caixeiro viajante para a cidade de destino da conexão armazenada no topo da pilha.

    CONEXAO *conexao = pilha_topo(pilha);
    cidade_atual = lista_get_item(lista_adj, conexao_get_destino(conexao));
    distancia_atual += conexao_get_distancia(conexao);

    // Verifica se o caixeiro viajante retornou para a cidade de origem.

    ITEM *cidade_origem = lista_get_item(lista_adj, cidade_inicial);
    if (item_get_cidade(cidade_atual) == item_get_cidade(cidade_origem))
    {
      if (distancia_atual < menor_distancia)
        menor_distancia = distancia_atual;

      undo(pilha, distancia_atual); // Desfaz o deslocamento do caixeiro viajante.
    }

    // Verifica tanto se a viagem atual do caixeiro viajante é mais longa do que a viagem mais curta testada até o momento quanto se a cidade atual foi visitada anteriormente na viagem atual.

    else if (distancia_atual > menor_distancia /*ou a cidade já tiver sido visitada*/)
      undo(pilha, distancia_atual); // Desfaz o deslocamento do caixeiro viajante.

  } while (!pilha_vazia(pilha)); // Quando a pilha estiver vazia, todas roteiros de viagem possíveis foram testados.
  
  lista_adjacencia_apagar(&lista_adj);
  pilha_apagar(&pilha);
  return 0;
}

CONEXAO *undo(PILHA *pilha, int *distancia_atual)
{
  CONEXAO *conexao_atual = pilha_desempilhar(pilha);
  *distancia_atual -= conexao_get_distancia(conexao_atual);

  CONEXAO *conexao_anterior = pilha_topo(pilha);
  if (conexao_get_destino(conexao_anterior) == conexao_get_origem(conexao_atual))
  {
    conexao_atual = pilha_desempilhar(pilha);
    *distancia_atual -= conexao_get_distancia(conexao_atual);
  }
}