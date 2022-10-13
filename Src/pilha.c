#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "viagem.h"

struct no
{
    VIAGEM *viagem;
    NO *anterior;
};

struct pilha
{
    NO *topo;
    int tamanho;
};

PILHA *pilha_criar(void)
{
    PILHA* pilha = (PILHA *) malloc(sizeof (PILHA));

    if (pilha != NULL)
    {
        pilha->topo = NULL;
        pilha->tamanho = 0;
    }

    return pilha;
}

void pilha_apagar(PILHA **pilha) 
{
    NO* topo;

    if (!pilha_vazia(*pilha)) 
    {
        while ((*pilha)->topo != NULL)
        {
            topo = (*pilha)->topo;
            (*pilha)->topo = (*pilha)->topo->anterior;
            viagem_apagar(&topo->viagem);
            topo->anterior = NULL;
            free(topo);
            topo = NULL;
        }
    }

    free(*pilha);
    *pilha = NULL;
}

bool pilha_empilhar(PILHA *pilha, VIAGEM *viagem)
{
    NO* no = (NO *) malloc(sizeof (NO));

    if (no != NULL)
    {
        no->viagem = viagem;
        no->anterior = pilha->topo;
        pilha->topo = no;
        pilha->tamanho++;

        return true;
    }
    else
        return false;
}

VIAGEM *pilha_desempilhar(PILHA *pilha)
{
    if (!pilha_vazia(pilha))
    {
        NO* topo = pilha->topo;
        VIAGEM* viagem = pilha->topo->viagem;
        pilha->topo = pilha->topo->anterior;
        topo->anterior=NULL; 
        free(topo); 
        topo = NULL;
        pilha->tamanho--;

        return viagem;
    }
    else
        return NULL;
}

bool pilha_vazia(PILHA *pilha)
{
    if (pilha != NULL && pilha->tamanho == 0)
        return true;
    else
        return false;
}

bool pilha_cheia(PILHA *pilha)
{
    NO *auxiliar = (NO *) malloc(sizeof(NO));

    if (pilha != NULL && auxiliar != NULL)
    {
        free(auxiliar);
        return false;
    }
    else
        return true;
}

int pilha_tamanho(PILHA *pilha){
    return pilha != NULL ? pilha->tamanho : ERRO;
}

VIAGEM *pilha_topo(PILHA *pilha)
{
    if (!pilha_vazia(pilha))
        return (pilha->topo->viagem);
    else
        return NULL;
}