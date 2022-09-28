#ifndef PILHA_H
    #define PILHA_H
    
    #include "stdbool.h"
    #include "conexao.h"

    #define ERRO -1;

    typedef struct no NO;
    typedef struct pilha PILHA;

    PILHA *pilha_criar();
    void pilha_apagar(PILHA **pilha);

    bool pilha_empilhar(PILHA* pilha, CONEXAO *conexao);
    CONEXAO *pilha_desempilhar(PILHA* pilha);

    bool pilha_vazia(PILHA *pilha);
    bool pilha_cheia(PILHA *pilha);

    int pilha_tamanho(PILHA* pilha);
    CONEXAO *pilha_topo(PILHA *pilha);

#endif