/**
 * @author Kayky Pimentel de Sena
 * @author Miller Matheus Lima Anacleto Rocha
 * @author Jorge Augusto Salgado Salhani
 * 
 * @brief Resolucao do problema do caixeiro viajante
 * 
 * Codigo cliente para resolução do problema do caixeiro
 * viajante utilizando Pilha em algoritmo similar a busca em
 * profundidade
 * 
 * Projeto 1 - Algoritmo e Estrutura de Dados I
 * Grupo 5
 * 
 * Prof. Rudinei Goularte
*/

#include <stdio.h>
#include <stdlib.h>
#include "viagem.h"
#include "cidade.h"
#include "lista.h"
#include "pilha.h"
#include <time.h>

int main(void)
{
    int numero_cidades, cidade_inicial;
    numero_cidades = 4;
    cidade_inicial = 1;
    scanf("%d\n%d\n", &numero_cidades, &cidade_inicial);
    LISTA *lista = lista_criar();
    lista_input_conexoes(lista);

    CIDADE *cidade_atual = lista_get_cidade_por_nome(lista, cidade_inicial);
    PILHA *pilha = pilha_criar();
    VIAGEM *melhor_caminho = NULL;
    int menor_distancia = __INT_MAX__;

    for (int i = 0; i < cidade_get_numero_conexoes(cidade_atual); i++) // Empilha todas cidades que podem ser alcançadas a partir da cidade de origem.
    {
        int origem = cidade_get_nome(cidade_atual);
        int destino = cidade_get_conexao(cidade_atual, i);
        int distancia = cidade_get_distancia(cidade_atual, i);

        VIAGEM *viagem = viagem_criar(origem, destino, distancia);
        lista_inserir(viagem_get_cidades_visitadas(viagem), cidade_atual);

        pilha_empilhar(pilha, viagem);
    }

    while (!pilha_vazia(pilha)) // Quando a pilha estiver vazia, todas roteiros de viagem possíveis foram testados.
    {
        // Desloca o caixeiro viajante para a cidade de destino da conexão armazenada no topo da pilha.

        VIAGEM *viagem = pilha_desempilhar(pilha);
        cidade_atual = lista_get_cidade_por_nome(lista, viagem_get_destino(viagem));

        if ((cidade_get_nome(cidade_atual) == cidade_inicial) && (viagem_get_distancia(viagem) <= menor_distancia)) // Um caminho mais curto do que o atual foi encontrado.
        {
            menor_distancia = viagem_get_distancia(viagem);
            viagem_apagar(&melhor_caminho);
            melhor_caminho = viagem;
        }
        else if (viagem_get_distancia(viagem) >= menor_distancia) // O caminho atual é descartado, pois já é mais longo que o caminho mais curto encontrado até o momento.
            viagem_apagar(&viagem);
        else
        {
            for (int i = 0; i < cidade_get_numero_conexoes(cidade_atual); i++) // Empilha todas cidades que podem ser alcançadas a partir da cidade atual.
            {
                VIAGEM *copia = viagem_copiar(viagem);

                int origem = cidade_get_nome(cidade_atual);
                int destino = cidade_get_conexao(cidade_atual, i);
                int distancia = cidade_get_distancia(cidade_atual, i);

                LISTA *cidades_visitadas = viagem_get_cidades_visitadas(copia);

                viagem_set_distancia(copia, viagem_get_distancia(copia) + distancia);
                viagem_set_origem(copia, origem);
                viagem_set_destino(copia, destino);

                lista_inserir(cidades_visitadas, cidade_atual);

                if (destino == cidade_inicial && lista_tamanho(cidades_visitadas) == numero_cidades) // Empilha a viagem atual do caixeiro viajante caso ela tenha sido válida.
                    pilha_empilhar(pilha, copia);
                else if (lista_get_cidade_por_nome(cidades_visitadas, destino) == NULL) // Se a cidade não tiver sido visitada, empilha-se a viagem atual.
                    pilha_empilhar(pilha, copia);
                else
                    viagem_apagar(&copia); // Se a cidade atual tiver sido visitada anteriormente, a viagem atual é descartada.
            }

            viagem_apagar(&viagem);
        }
    }

    //printf("Cidade inicial:\t%d\n", cidade_inicial);
    //printf("caminho:\t");
    lista_imprimir(viagem_get_cidades_visitadas(melhor_caminho));
    printf("%d\n", cidade_inicial);
    //printf("Distancia:\t%d\n", menor_distancia);
    
    viagem_apagar(&melhor_caminho);
    lista_apagar(&lista);
    pilha_apagar(&pilha);
    return 0;
}
