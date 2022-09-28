#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "conexao.h"
#include "item.h"

struct conexao
{
    int origem;
    int destino;
    int distancia;
};

CONEXAO* conexao_criar(int origem, int destino, int distancia)
{
  CONEXAO *conexao = (CONEXAO*) malloc(sizeof(CONEXAO));

    if (conexao != NULL)
    {
        conexao->origem = origem;
        conexao->destino = destino;
        conexao->distancia = distancia;
        return conexao;
    }
    else
        return NULL;
}

void conexao_apagar(CONEXAO **conexao)
{
    if (*conexao != NULL)
    {
        free(*conexao);
        *conexao = NULL;
    }
}

void conexao_set_origem(CONEXAO* conexao, int origem){
    if (conexao != NULL)
        conexao->origem = origem;
}

void conexao_set_destino(CONEXAO* conexao, int destino){
    if (conexao != NULL)
        conexao->destino = destino;
}

void conexao_set_distancia(CONEXAO* conexao, int distancia){
    if (conexao != NULL)
        conexao->distancia = distancia;
}

int conexao_get_origem(CONEXAO *conexao){
    if (conexao != NULL)
        return conexao->origem;
    else
        return ERRO;
}

int conexao_get_destino(CONEXAO *conexao){
    if (conexao != NULL)
        return conexao->destino;
    else
        return ERRO;
}

int conexao_get_distancia(CONEXAO *conexao){
    if (conexao != NULL)
        return conexao->distancia;
    else
        return ERRO;
}
