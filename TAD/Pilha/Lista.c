/**
 * Estruturas de Dados
 *
 * Tipo Abstrato de Dados (Pilha)
 *
 * Edson Onildo
 * Isabela Carvalho
 *
 * lista.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

struct lista
{
    int info;
    struct lista *prox;
};

int vaziaLista(Lista l)
{
    return l == NULL;
}

int contarLista(Lista l)
{
    if (vaziaLista(l))
        return 0;

    return 1 + contarLista(l->prox);
}

void imprimirLista(Lista l)
{
    if (vaziaLista(l))
        return;

    printf("%d ", l->info);
    imprimirLista(l->prox);
}

Lista inicializarLista(void)
{
    return NULL;
}

Lista destruirLista(Lista l)
{
    if (!vaziaLista(l))
    {
        l->prox = destruirLista(l->prox);
        free(l);
    }
    return NULL;
}

Lista inserirFinalLista(Lista l, int val)
{
    if (vaziaLista(l))
    {
        l = (Lista) malloc(sizeof(struct lista));
        l->info = val;
        l->prox = inicializarLista();
    }
    else
    {
        l->prox = inserirFinalLista(l->prox, val);
    }
    return l;
}

Lista removerFinalLista(Lista l, int *ret)
{
    if (vaziaLista(l))
        return NULL;

    if (vaziaLista(l->prox))
    {
        *ret = l->info;
        free(l);
        return NULL;
    }

    l->prox = removerFinalLista(l->prox, ret);

    return l;
}