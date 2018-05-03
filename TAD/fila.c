/** Trabalho de Estruturas de Dados
 *
 * Trabalho 06 - Tipo abstrato de dados
 *
 * Edson Onildo
 * Isabela Carvalho
 *
 *
 * fila.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#define N 100

typedef struct lista
{
    int info;
    struct lista *prox;
} Lista;

struct fila
{
    Lista *lista;
    int cont;
};


Fila inicializar(void)
{
    Fila f = (Fila) malloc(sizeof(struct fila));

    f->lista = NULL;

    f->cont= 0;
    return f;
}

Lista *destruirLista(Lista *l)
{
    if (l != NULL)
    {
        l->prox = destruirLista(l->prox);
        free(l);
    }

    return NULL;
}

Fila destruir(Fila f)
{
    f->lista = destruirLista(f->lista);

    free(f);
    return NULL;
}

int vazia(Fila f)
{
    return f->lista == NULL;
}

int cheia(Fila f)
{
    return f->cont >= N;


}

void inserir(Fila f, int x)
{
    Lista *p;

    if (!vazia(f))
    {
        for (p = f->lista; p->prox!=NULL; p = p->prox);

        Lista *novo = (Lista*) malloc(sizeof(Lista));
        novo->info = x;
        novo->prox = NULL;
        p->prox = novo;
    }
    else
    {

        f->lista = (Lista*) malloc(sizeof(Lista));
        f->lista->info = x;
        f->lista->prox = NULL;
    }

    f->cont++;

}

int remover(Fila f)
{
    int ret = f->lista->info;

    Lista *p = f->lista->prox;

    free(f->lista);

    f->lista = p;
    f->cont--;

    return ret;
}

void imprimir(Fila f)
{
    Lista *p;

    for (p = f->lista; p!=NULL; p=p->prox)
        printf("%d ", p->info);
}