#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "conexao.h"

struct no
{
    CONEXAO *conexao;
    NO *anterior;
};

struct pilha
{
    NO *topo;
    int tamanho;
};

PILHA *pilha_criar()
{
    PILHA* pilha = (PILHA *) malloc(sizeof (PILHA));

    if (pilha != NULL)
    {
        pilha->topo = NULL;
        pilha->tamanho = 0;
    }

    return pilha;
}

void pilha_apagar(PILHA** pilha) 
{
    NO* topo;

    if (!pilha_vazia(*pilha)) 
    {
        while ((*pilha)->topo != NULL)
        {
            topo = (*pilha)->topo;
            (*pilha)->topo = (*pilha)->topo->anterior;
            item_apagar(&topo->conexao);
            topo->anterior = NULL;
            free(topo);
            topo = NULL;
        }
    }

    free(*pilha);
    *pilha = NULL;
}

bool pilha_empilhar(PILHA* pilha, CONEXAO* conexao)
{
    NO* no = (NO *) malloc(sizeof (NO));

    if (no != NULL)
    {
        no->conexao = conexao;
        no->anterior = pilha->topo;
        pilha->topo = no;
        pilha->tamanho++;

        return true;
    }
    else
        return false;
}

CONEXAO* pilha_desempilhar(PILHA* pilha)
{
    if (!pilha_vazia(pilha))
    {
        NO* topo = pilha->topo;
        CONEXAO* conexao = pilha->topo->conexao;
        pilha->topo = pilha->topo->anterior;
        topo->anterior=NULL; 
        free(topo); 
        topo = NULL;
        pilha->tamanho--;

        return conexao;
    }
    else
        return NULL;
}

bool pilha_vazia(PILHA* pilha)
{
    if (pilha != NULL)
        return pilha->tamanho == 0 ? true : false;
    else
        return false;
}

bool pilha_cheia(PILHA *pilha)
{
    NO *auxiliar = (NO*) malloc(sizeof(NO));

    if (pilha != NULL && auxiliar != NULL)
    {
        free(auxiliar);
        return false;
    }
    else
        return true;
}

int pilha_tamanho(PILHA* pilha){
    return pilha != NULL ? pilha->tamanho : ERRO;
}

CONEXAO* pilha_topo(PILHA* pilha)
{
    if (!pilha_vazia(pilha))
        return (pilha->topo->conexao);
    else
        return NULL;
}