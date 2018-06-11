#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Tools.h"
#include "Aresta.h"

struct aresta
{
    int dest;
    float custo;
    Aresta prox;
};

Aresta ArestaInit(void)
{
    return NULL;
}

Aresta ArestaFree(Aresta a)
{
    if (isNull(a))
    {
        a->prox = ArestaFree(a->prox);
        free(a);
    }
    return NULL;
}

Aresta ArestaProx(Aresta a)
{
    return a->prox;
}

Aresta ArestaInserir(Aresta a, int dest, float custo)
{
    Aresta novo = (Aresta) malloc(sizeof(struct aresta));

    checkMalloc(novo);

    novo->dest = dest;
    novo->custo = custo;
    novo->prox = a;

    return novo;
}

Aresta ArestaRemover(Aresta a, int dest)
{
    if (a->dest == dest)
    {
        Aresta tmp = a;
        a = a->prox;
        free(tmp);
    }
    else
    {
        a->prox = ArestaRemover(a->prox, dest);
    }
    return a;
}

void ArestaImprimir(Aresta a)
{
    for (Aresta p = a; !isNull(p); p = p->prox)
        printf(" - [%d|%.1f]", p->dest, p->custo);
}

int ArestaContDest(Aresta a, int dest)
{
    int cont = 0;

    for (Aresta p = a; !isNull(p); p = p->prox)
        if (p->dest == dest)
            cont++;

    return cont;
}

int ArestaContElem(Aresta a)
{
    int cont = 0;

    for (Aresta p = a; !isNull(p); p = p->prox)
        cont++;

    return cont;
}

int ArestaGetDest(Aresta a)
{
    return a->dest;
}

float ArestaGetCusto(Aresta a)
{
    return a->custo;
}

bool ArestaExisteDest(Aresta a, int dest)
{
    for (Aresta p = a; !isNull(p); p = p->prox)
        if (p->dest == dest)
            return true;

    return false;
}
