#ifndef LISTA_H
    #define LISTA_H

    #include <stdbool.h>
    #include "cidade.h"

    #define TAM_MAX 12
    #define ERRO -1

    typedef struct lista LISTA;

    LISTA *lista_criar(void);
    void lista_apagar(LISTA **lista);

    bool lista_inserir(LISTA *lista, CIDADE *cidade);

    bool lista_vazia(LISTA *lista);
    bool lista_cheia(LISTA *lista);

    CIDADE *lista_get_cidade_por_nome(LISTA *lista, int nome);
    CIDADE *lista_get_cidade_por_indice(LISTA *lista, int indice);
    int lista_tamanho(LISTA *lista);

    void lista_input_conexoes(LISTA *lista);
    void lista_imprimir(LISTA *lista);
#endif