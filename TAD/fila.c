#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#define N 100

struct fila
{
    int vet[N];
    int topo;
};

Fila inicializar(void)
{
    Fila f = (Fila) malloc(sizeof(struct fila));
    f->topo = 0;
    return f;
}

Fila destruir(Fila f)
{
    free(f);
    return NULL;
}

int vazia(Fila f)
{
    return f->topo == 0;
}

int cheia(Fila f)
{
    return f->topo >= 100;
}

void inserir(Fila f, int x)
{
    f->vet[f->topo] = x;
    f->topo++;
}

int remover(Fila f)
{
    int ret = f->vet[0];

    for (int i = 1; i < f->topo; i++)
        f->vet[i-1] = f->vet[i];

    f->topo--;

    return ret;
}

void imprimir(Fila f)
{
    for (int i = 0; i < f->topo; i++)
        printf("%d ", f->vet[i]);
}