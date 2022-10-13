#ifndef PILHA_H
#define PILHA_H
    
#include "stdbool.h"
#include "viagem.h"

typedef struct no NO;
typedef struct pilha PILHA;

PILHA *pilha_criar(void);
void pilha_apagar(PILHA **pilha);

bool pilha_empilhar(PILHA* pilha, VIAGEM *viagem);
VIAGEM *pilha_desempilhar(PILHA* pilha);

bool pilha_vazia(PILHA *pilha);
bool pilha_cheia(PILHA *pilha);

int pilha_tamanho(PILHA* pilha);
VIAGEM *pilha_topo(PILHA *pilha);

#endif