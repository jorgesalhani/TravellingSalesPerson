#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "conexao.h"
#include "lista.h"

struct conexao
{
    int origem;
    LISTA * visitadas;
    int destino;
    int distancia;
};

CONEXAO* conexao_criar(int origem, int destino, int distancia)
{
    CONEXAO *conexao = (CONEXAO*) malloc(sizeof(CONEXAO));

    if (conexao != NULL)
    {
        conexao->visitadas = lista_criar();
        if(conexao->visitadas == NULL){
            conexao_apagar(&conexao);
            return NULL;
        }
        conexao->origem = origem;
        conexao->destino = destino;
        conexao->distancia = distancia;
        return conexao;
    }
    else
        return NULL;
}

CONEXAO* conexao_copy(CONEXAO* conexao){
    CONEXAO *copia = (CONEXAO*) malloc(sizeof(CONEXAO));
    
    if (copia != NULL)
    {
        copia->visitadas = lista_criar();
        if(copia->visitadas == NULL){
            conexao_apagar(&copia);
            return NULL;
        }
        LISTA * lista_copia = copia->visitadas;
        LISTA * lista_conexao = conexao->visitadas;
        for(int i = 0; i < lista_tamanho(lista_conexao); i++){
            lista_inserir(lista_copia, lista_busca(lista_conexao, i));
        }
        copia->origem = conexao->origem;
        copia->destino = conexao->destino;
        copia->distancia = conexao->distancia;
        return copia;
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

LISTA * conexao_get_visitadas(CONEXAO *conexao){
    if (conexao != NULL)
        return conexao->visitadas;
    else
        return NULL;
}