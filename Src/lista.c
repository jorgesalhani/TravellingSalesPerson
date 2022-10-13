#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "cidade.h"

struct lista
{
    CIDADE *lista[TAM_MAX];
    int tamanho;
};

CIDADE *lista_get_cidade_por_cidade(LISTA *lista, CIDADE *cidade);

CIDADE *lista_get_cidade_por_nome(LISTA *lista, int nome)
{
    if (lista != NULL)
        for (int i = 0; i < lista->tamanho; i++)
            if (cidade_get_nome(lista->lista[i]) == nome)
                return lista->lista[i];
    
    return NULL;
}

CIDADE *lista_get_cidade_por_indice(LISTA *lista, int indice)
{
    if (lista != NULL && indice < lista->tamanho)
        return lista->lista[indice];
    else
        return NULL;   
}

LISTA *lista_criar(void)
{
    LISTA *lista = (LISTA *) malloc(sizeof(LISTA));

    if (lista != NULL)
    {
        lista->tamanho = 0;
        return lista;
    }
    else
        return false;
}

void lista_apagar(LISTA **lista)
{
    if (*lista != NULL)
    {
        while (!lista_vazia(*lista))
        {
            free((*lista)->lista[(*lista)->tamanho - 1]);
            (*lista)->lista[(*lista)->tamanho - 1] = NULL;
            (*lista)->tamanho--;
        }

        free(*lista);
        *lista = NULL;
    }
}

bool lista_inserir(LISTA *lista, CIDADE *cidade)
{
    if (!lista_cheia(lista) && cidade != NULL)
    {
        lista->lista[lista->tamanho] = cidade;
        lista->tamanho++;
    }
    else
        return false;
}

void lista_imprimir(LISTA *lista)
{
    if (lista != NULL) 
        for (int i = 0; i < lista->tamanho; i++)
            printf("%d ", cidade_get_nome(lista->lista[i]));
}

bool lista_vazia(LISTA *lista)
{
    if (lista != NULL && lista->tamanho == 0)
        return true;
    else
        return false;
}

bool lista_cheia(LISTA *lista)
{
    if (lista != NULL && lista->tamanho == TAM_MAX)
        return true;
    else
        return false;
}

void lista_input_conexoes(LISTA *lista)
{
    int cidade_A, cidade_B, distancia;
    CIDADE *cidade_nova;

    while (!feof(stdin))
    {
        scanf("%d %d %d\n", &cidade_A, &cidade_B, &distancia);

        cidade_nova = cidade_criar(cidade_A);

        CIDADE* cidade = lista_get_cidade_por_cidade(lista, cidade_nova);
        if (cidade != NULL)
        {
            cidade_adicionar_conexao(cidade, cidade_B, distancia);
            cidade_apagar(&cidade_nova);
        }
        else
        {
            cidade_adicionar_conexao(cidade_nova, cidade_B, distancia);
            lista_inserir(lista, cidade_nova);
        }

        cidade_nova = cidade_criar(cidade_B);

        cidade = lista_get_cidade_por_cidade(lista, cidade_nova);
        if (cidade != NULL)
        {
            cidade_adicionar_conexao(cidade, cidade_A, distancia);
            cidade_apagar(&cidade_nova);
        }
        else
        {
            cidade_adicionar_conexao(cidade_nova, cidade_A, distancia);
            lista_inserir(lista, cidade_nova);
        }
    }
}

CIDADE *lista_get_cidade_por_cidade(LISTA *lista, CIDADE *cidade)
{
    if (!lista_vazia(lista) && cidade != NULL)
        for (int i = 0; i < lista->tamanho; i++)
            if (cidade_get_nome(lista->lista[i]) == cidade_get_nome(cidade))
                return lista->lista[i];

    return NULL;
}

int lista_tamanho(LISTA *lista)
{
    if (lista != NULL)
        return lista->tamanho;
    else
        return ERRO;
}