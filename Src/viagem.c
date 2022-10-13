#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "viagem.h"
#include "lista.h"

// A struct "viagem" armazena o status da viagem do caixeiro viajante:
// "origem" indica a sua cidade atual, de onde ele está saindo no momento;
// "destino" indica o seu próximo ponto de parada, para onde ele está indo;
// "distância" indica a distância total percorrida durante a viagem;
// "cidades_visitadas" indica, em ordem, as cidades visitadas durante a viagem.

struct viagem
{
    int origem;
    int destino;
    int distancia;
    LISTA *cidades_visitadas;
};

VIAGEM *viagem_criar(int origem, int destino, int distancia)
{
    VIAGEM *viagem = (VIAGEM *) malloc(sizeof(VIAGEM));

    if (viagem != NULL)
    {
        viagem->cidades_visitadas = lista_criar();

        if (viagem->cidades_visitadas == NULL)
        {
            viagem_apagar(&viagem);
            return NULL;
        }

        viagem->origem = origem;
        viagem->destino = destino;
        viagem->distancia = distancia;

        return viagem;
    }
    else
        return NULL;
}

VIAGEM *viagem_copiar(VIAGEM *viagem)
{
    VIAGEM *copia = viagem_criar(viagem->origem, viagem->destino, viagem->distancia);
    
    if (copia != NULL)
    {
        LISTA *lista_copia = copia->cidades_visitadas;
        LISTA *lista_viagem = viagem->cidades_visitadas;

        for (int i = 0; i < lista_tamanho(lista_viagem); i++)
            lista_inserir(lista_copia, lista_get_cidade_por_indice(lista_viagem, i));

        return copia;
    }
    else
        return NULL;
}

void viagem_apagar(VIAGEM **viagem)
{
    if (*viagem != NULL)
    {
        free((*viagem)->cidades_visitadas);
        (*viagem)->cidades_visitadas = NULL;

        free(*viagem);
        *viagem = NULL;
    }
}

bool viagem_set_origem(VIAGEM *viagem, int origem){
    if (viagem != NULL)
    {
        viagem->origem = origem;
        return true;
    }
    else
        return false;
}

bool viagem_set_destino(VIAGEM *viagem, int destino){
    if (viagem != NULL)
    {
        viagem->destino = destino;
        return true;
    }
    else
        return false;
}

bool viagem_set_distancia(VIAGEM *viagem, int distancia){
    if (viagem != NULL)
    {
        viagem->distancia = distancia;
        return true;
    }
    else
        return false;
}

int viagem_get_origem(VIAGEM *viagem){
    return viagem != NULL ? viagem->origem : ERRO;
}

int viagem_get_destino(VIAGEM *viagem){
    return viagem != NULL ? viagem->destino : ERRO;
}

int viagem_get_distancia(VIAGEM *viagem){
    return viagem != NULL ? viagem->distancia : ERRO;
}

LISTA *viagem_get_cidades_visitadas(VIAGEM *viagem){
    return viagem != NULL ? viagem->cidades_visitadas : NULL;
}