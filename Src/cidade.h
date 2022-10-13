#ifndef ITEM_H
    #define ITEM_H
    
    #include <stdbool.h>

    #define TAM_MAX 12
    #define ERRO -1

    typedef struct cidade CIDADE;

    CIDADE* cidade_criar(int nome);
    bool cidade_apagar(CIDADE **cidade);

    bool cidade_adicionar_conexao(CIDADE *cidade, int destino, int distancia);

    int cidade_get_nome(CIDADE *cidade);
    int cidade_get_numero_conexoes(CIDADE *cidade);
    int cidade_get_conexao(CIDADE *cidade, int indice);
    int cidade_get_distancia(CIDADE *cidade, int indice);

    bool cidade_set_numero_conexoes(CIDADE *cidade, int chave);

    void cidade_imprimir(CIDADE *cidade);
#endif