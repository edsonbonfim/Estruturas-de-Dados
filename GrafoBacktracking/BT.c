#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Lista.h"
#include "Grafo.h"
#include "BT.h"

struct backtrack
{
    int pos, *vet, origem, destino;
    Grafo grafo;
};

BT BTInit(Grafo grafo)
{
    BT backtrack = (BT) malloc(sizeof(struct backtrack));

    backtrack->grafo = grafo;
    backtrack->vet = (int *) malloc(GrafoTamanho(grafo) * sizeof(int));
    backtrack->pos = 1;
    backtrack->origem = 0;
    backtrack->destino = 0;

    return backtrack;
}

int BTTamVet(BT bt)
{
    return GrafoTamanho(bt->grafo);
}

void BTImprimir(BT bt, bool (*cond)(BT), bool (*rec)(BT))
{
    if (cond(bt))
    {
        for (int i = 0; i < bt->pos; i++)
            printf("%d  ", bt->vet[i]);

        printf("\n");
    }
    else
    {
        for (Lista l = GrafoGetVertice(bt->grafo, bt->vet[bt->pos - 1]); l != NULL; l = ListaProx(l))
        {
            if (!BTExistirVet(bt, ListaGetDestino(l)))
            {
                if (rec != NULL)
                    if (rec(bt))
                        continue;

                bt->vet[bt->pos] = ListaGetDestino(l);
                bt->pos += 1;
                BTImprimir(bt, cond, rec);
                bt->pos -= 1;
            }
        }
    }
}

void BTSetOrig(BT *bt, int origem)
{
    (*bt)->origem = origem;
}

void BTSetDest(BT *backtrack, int destino)
{
    (*backtrack)->destino = destino;
}

void BTSetVet(BT *backtrack, int pos, int val)
{
    (*backtrack)->vet[pos] = val;
}

bool BTExistirVet(BT b, int elem)
{
    for (int i = 0; i < b->pos; i++)
        if (b->vet[i] == elem)
            return true;

    return false;
}

int BTGetOrigem(BT backtrack)
{
    return backtrack->origem;
}

int BTGetDestino(BT backtrack)
{
    return backtrack->destino;
}

int BTGetPos(BT b)
{
    return b->pos;
}

int *BTGetVet(BT backtrack)
{
    return backtrack->vet;
}

float BTGetCusto(BT bt)
{
    return GrafoGetCusto(bt->grafo, bt->pos);
}