#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int destino;
    float custo;
    Lista prox;
};

Lista iniLista(void)
{
    return NULL;
}

Lista freeLista(Lista lista)
{
    if (lista != NULL)
    {
        lista->prox = freeLista(lista->prox);
        free(lista);
    }
    return NULL;
}

Lista inserirLista(Lista lista, int destino, float custo)
{
    Lista novo = (Lista) malloc(sizeof(struct lista));
    novo->destino = destino;
    novo->custo = custo;
    novo->prox = lista;
    return novo;
}

Lista removerLista(Lista lista, int destino)
{
    if (lista->destino == destino)
    {
        Lista tmp = lista;
        lista = lista->prox;
        free(tmp);
    }
    else
    {
        lista->prox = removerLista(lista->prox, destino);
    }
    return lista;
}

void imprimirLista(Lista lista)
{
    for (Lista p = lista; p != NULL; p = p->prox)
        printf(" - [%d|%.1f]", p->destino, p->custo);
}

int contarDestinoLista(Lista lista, int destino)
{
    int cont = 0;

    for (Lista p = lista; p != NULL; p = p->prox)
        if (p->destino == destino)
            cont++;

    return cont;
}

int contarElementosLista(Lista lista)
{
    int cont = 0;

    for (Lista p = lista; p != NULL; p = p->prox)
        cont++;

    return cont;
}

bool existeLista(Lista lista, int destino)
{
    for (Lista p = lista; p != NULL; p = p->prox)
        if (p->destino == destino)
            return true;

    return false;
}
