#ifndef CONEXAO_H
    #define CONEXAO_H
    #include "lista.h"

    typedef struct conexao CONEXAO;

    CONEXAO* conexao_criar(int origem, int destino, int distancia);
    CONEXAO* conexao_copy(CONEXAO* conexao);
    void conexao_apagar(CONEXAO **conexao);

    void conexao_set_origem(CONEXAO* conexao, int origem);
    void conexao_set_destino(CONEXAO* conexao, int destino);
    void conexao_set_distancia(CONEXAO* conexao, int distancia);

    int conexao_get_origem(CONEXAO *conexao);
    int conexao_get_destino(CONEXAO *conexao);
    int conexao_get_distancia(CONEXAO *conexao);
    LISTA * conexao_get_visitadas(CONEXAO *conexao);

#endif