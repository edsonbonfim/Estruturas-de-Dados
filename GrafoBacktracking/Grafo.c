#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Tools.h"
#include "Lista.h"
#include "Grafo.h"

struct grafo
{
    int tam;
    Lista *vet;
};

Grafo GrafoInit(int n)
{
    Grafo g = (Grafo) malloc(sizeof(struct grafo));

    checkMalloc(g);

    g->tam = n += 1;
    g->vet = (Lista *) malloc(n * sizeof(Lista));

    checkMalloc(g->vet);

    for (int i = 0; i < n; i++)
        g->vet[i] = ListaInit();

    return g;
}

Grafo GrafoFree(Grafo g)
{
    for (int i = 1; i < g->tam; i++)
        g->vet[i] = ListaFree(g->vet[i]);

    free(g->vet);
    free(g);

    return NULL;
}

Lista GrafoGetVertice(Grafo g, int vertice)
{
    return g->vet[vertice];
}

void GrafoImprimir(Grafo grafo)
{
    for (int i = 1; i < grafo->tam; i++)
    {
        printf("|%d|", i);
        ListaImprimir(grafo->vet[i]);
        printf("\n");
    }
}

int GrafoTamanho(Grafo g)
{
    return g->tam;
}

int GrafoGrauEntrada(Grafo g, int vertice)
{
    int cont = 0;

    for (int i = 1; i < g->tam; i++)
        cont += ListaContDest(g->vet[i], vertice);

    return cont;
}

int GrafoGrauSaida(Grafo g, int vertice)
{
    return ListaContElem(g->vet[vertice]);
}

int GrafoContAresta(Grafo g)
{
    int cont = 0;

    for (int i = 1; i < g->tam; i++)
        cont += GrafoGrauSaida(g, i);

    return cont;
}

int GrafoGrauVertice(Grafo g, int vertice)
{
    return GrafoGrauEntrada(g, vertice) + GrafoGrauSaida(g, vertice);
}

float GrafoGetCusto(Grafo g, int pos)
{
    return ListaGetCusto(g->vet[pos]);
}

bool GrafoInserir(Grafo g, int orig, int dest, float custo)
{
    if (ListaExisteDestino(g->vet[orig], dest))
        return false;

    g->vet[orig] = ListaInserir(g->vet[orig], dest, custo);
    return true;
}

bool GrafoRemover(Grafo g, int orig, int dest)
{
    if (!ListaExisteDestino(g->vet[orig], dest))
        return false;

    g->vet[orig] = ListaRemover(g->vet[orig], dest);
    return true;
}

bool GrafoEsparco(Grafo g)
{
    int n = g->tam - 1;
    int total = n*(n-1)/2;
    return GrafoContAresta(g) <= total * 0.3;
}
