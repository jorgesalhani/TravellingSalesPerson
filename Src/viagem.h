#ifndef VIAGEM_H
    #define VIAGEM_H

    #include "lista.h"

    #define ERRO -1

    typedef struct viagem VIAGEM;

    VIAGEM *viagem_criar(int origem, int destino, int distancia);
    VIAGEM *viagem_copiar(VIAGEM *viagem);
    void viagem_apagar(VIAGEM **viagem);

    bool viagem_set_origem(VIAGEM *viagem, int origem);
    bool viagem_set_destino(VIAGEM *viagem, int destino);
    bool viagem_set_distancia(VIAGEM *viagem, int distancia);

    int viagem_get_origem(VIAGEM *viagem);
    int viagem_get_destino(VIAGEM *viagem);
    int viagem_get_distancia(VIAGEM *viagem);
    LISTA *viagem_get_cidades_visitadas(VIAGEM *viagem);
#endif