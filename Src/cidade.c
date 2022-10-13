#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "cidade.h"

struct cidade
{
    int nome;
    int conexoes[TAM_MAX];
    int distancias[TAM_MAX];
    int numero_conexoes;
};

CIDADE *cidade_criar(int nome)
{
    CIDADE *cidade = (CIDADE *) malloc(sizeof(CIDADE));

    if (cidade != NULL)
    {
      cidade->nome = nome;
      cidade->numero_conexoes = 0;

      return cidade;
    }
    else
        return false;
}

bool cidade_adicionar_conexao(CIDADE *cidade, int destino, int distancia)
{
    if (cidade != NULL)
    {
        cidade->conexoes[cidade->numero_conexoes] = destino;
        cidade->distancias[cidade->numero_conexoes] = distancia;
        cidade->numero_conexoes++;

        return true;
    }
    else
        return false;

}

bool cidade_apagar(CIDADE **cidade)
{
    if (*cidade != NULL)
    {
        free(*cidade);
        *cidade = NULL;

        return true;
    } 
    else
        return false;
}

void cidade_imprimir(CIDADE *cidade)
{
    if (cidade != NULL)
    {
        printf("| Cidade: %d\n", cidade->nome);
        printf("| Conexoes: ");
        for (int i = 0; i < cidade->numero_conexoes; i++) printf("%d ", cidade->conexoes[i]);
        printf("\n");
        printf("| Distanc.: ");
        for (int i = 0; i < cidade->numero_conexoes; i++) printf("%d ", cidade->distancias[i]);
        printf("\n\n");
    }
}

int cidade_get_nome(CIDADE *cidade)
{
    if (cidade != NULL)
        return cidade->nome;
    else
        return -1;
}

bool cidade_set_numero_conexoes(CIDADE *cidade, int chave)
{
    if (cidade != NULL)
    {
        cidade->numero_conexoes = chave;

        return true;
    }
    else
        return false;
}

int cidade_get_numero_conexoes(CIDADE *cidade)
{
    if (cidade != NULL)
        return cidade->numero_conexoes;
    else
        return ERRO;
}

int cidade_get_conexao(CIDADE *cidade, int indice)
{
    if (cidade != NULL)
        return cidade->conexoes[indice];
    else
        return ERRO;
}

int cidade_get_distancia(CIDADE *cidade, int indice)
{
    if (cidade != NULL)
        return cidade->distancias[indice];
    else
        return ERRO;
}