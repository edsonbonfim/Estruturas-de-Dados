#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "Grafo.h"

struct grafo
{
    int tam;
    Lista *vet;
};

Grafo iniGrafo(int n)
{
    Grafo grafo = (Grafo) malloc(sizeof(struct grafo));

    grafo->tam = n += 1;
    grafo->vet = (Lista *) malloc(n * sizeof(Lista));

    for (int i = 0; i < n; i++)
        grafo->vet[i] = iniLista();

    return grafo;
}

Grafo freeGrafo(Grafo grafo)
{
    for (int i = 1; i < grafo->tam; i++)
        grafo->vet[i] = freeLista(grafo->vet[i]);

    free(grafo->vet);
    free(grafo);

    return NULL;
}

void imprimirGrafo(Grafo grafo)
{
    for (int i = 1; i < grafo->tam; i++)
    {
        printf("|%d|", i);
        imprimirLista(grafo->vet[i]);
        printf("\n");
    }
}

int grauEntradaVertice(Grafo grafo, int vertice)
{
    int grau = 0;

    for (int i = 1; i < grafo->tam; i++)
        grau += contarDestinoLista(grafo->vet[i], vertice);

    return grau;
}

int grauSaidaVertice(Grafo grafo, int vertice)
{
    return contarElementosLista(grafo->vet[vertice]);
}

int numArestas(Grafo grafo)
{
    int arestas = 0;

    for (int i = 1; i < grafo->tam; i++)
        arestas += grauSaidaVertice(grafo, i);

    return arestas;
}

int grauVertice(Grafo grafo, int vertice)
{
    return grauEntradaVertice(grafo, vertice) + grauSaidaVertice(grafo, vertice);
}

bool inserirArestaGrafo(Grafo grafo, int pos, int destino, float custo)
{
    if (existeLista(grafo->vet[pos], destino))
        return false;

    grafo->vet[pos] = inserirLista(grafo->vet[pos], destino, custo);
    return true;
}

bool removerArestaGrafo(Grafo grafo, int pos, int destino)
{
    if (!existeLista(grafo->vet[pos], destino))
        return false;

    grafo->vet[pos] = removerLista(grafo->vet[pos], destino);
    return true;
}

bool isEsparco(Grafo grafo)
{
    int n = grafo->tam - 1;
    int total = n*(n-1)/2;
    return numArestas(grafo) <= total * 0.3;
}
