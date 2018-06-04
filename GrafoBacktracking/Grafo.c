#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Tools.h"
#include "Aresta.h"
#include "Grafo.h"

struct vertice
{
    int tam;
    Aresta *vet;
};

Grafo GrafoInit(int n)
{
    Grafo g = (Grafo) malloc(sizeof(struct vertice));

    checkMalloc(g);

    g->tam = n += 1;
    g->vet = (Aresta *) malloc(n * sizeof(Aresta));

    checkMalloc(g->vet);

    for (int i = 0; i < n; i++)
        g->vet[i] = ArestaInit();

    return g;
}

Grafo GrafoFree(Grafo g)
{
    for (int i = 1; i < g->tam; i++)
        g->vet[i] = ArestaFree(g->vet[i]);

    free(g->vet);
    free(g);

    return NULL;
}

Aresta GrafoGetAresta(Grafo g, int vertice)
{
    return g->vet[vertice];
}

void GrafoImprimir(Grafo grafo)
{
    for (int i = 1; i < grafo->tam; i++)
    {
        printf("|%d|", i);
        ArestaImprimir(grafo->vet[i]);
        printf("\n");
    }
}

int GrafoGetTamanho(Grafo g)
{
    return g->tam - 1;
}

int GrafoGrauEntrada(Grafo g, int vertice)
{
    int cont = 0;

    for (int i = 1; i < g->tam; i++)
        cont += ArestaContDest(g->vet[i], vertice);

    return cont;
}

int GrafoGrauSaida(Grafo g, int vertice)
{
    return ArestaContElem(g->vet[vertice]);
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
    return ArestaGetCusto(g->vet[pos]);
}

bool GrafoInserir(Grafo g, int orig, int dest, float custo)
{
    if (ArestaExisteDest(g->vet[orig], dest))
        return false;

    g->vet[orig] = ArestaInserir(g->vet[orig], dest, custo);
    return true;
}

bool GrafoRemover(Grafo g, int orig, int dest)
{
    if (!ArestaExisteDest(g->vet[orig], dest))
        return false;

    g->vet[orig] = ArestaRemover(g->vet[orig], dest);
    return true;
}

bool GrafoEsparco(Grafo g)
{
    int n = g->tam - 1;
    int total = n*(n-1)/2;
    return GrafoContAresta(g) <= total * 0.3;
}
