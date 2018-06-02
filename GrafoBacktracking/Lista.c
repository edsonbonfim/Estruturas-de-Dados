#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Tools.h"
#include "Lista.h"

struct lista
{
    int dest;
    float custo;
    Lista prox;
};

Lista ListaInit(void)
{
    return NULL;
}

Lista ListaFree(Lista l)
{
    if (isNull(l))
    {
        l->prox = ListaFree(l->prox);
        free(l);
    }
    return NULL;
}

Lista ListaProx(Lista l)
{
    return l->prox;
}

Lista ListaInserir(Lista l, int dest, float custo)
{
    Lista novo = (Lista) malloc(sizeof(struct lista));

    checkMalloc(novo);

    novo->dest = dest;
    novo->custo = custo;
    novo->prox = l;

    return novo;
}

Lista ListaRemover(Lista l, int dest)
{
    if (l->dest == dest)
    {
        Lista tmp = l;
        l = l->prox;
        free(tmp);
    }
    else
    {
        l->prox = ListaRemover(l->prox, dest);
    }
    return l;
}

void ListaImprimir(Lista l)
{
    for (Lista p = l; !isNull(p); p = p->prox)
        printf(" - [%d|%.1f]", p->dest, p->custo);
}

int ListaContDest(Lista l, int dest)
{
    int cont = 0;

    for (Lista p = l; !isNull(p); p = p->prox)
        if (p->dest == dest)
            cont++;

    return cont;
}

int ListaContElem(Lista l)
{
    int cont = 0;

    for (Lista p = l; !isNull(p); p = p->prox)
        cont++;

    return cont;
}

int ListaGetDestino(Lista l)
{
    return l->dest;
}

float ListaGetCusto(Lista l)
{
    return l->custo;
}

bool ListaExisteDestino(Lista l, int dest)
{
    for (Lista p = l; !isNull(p); p = p->prox)
        if (p->dest == dest)
            return true;

    return false;
}
