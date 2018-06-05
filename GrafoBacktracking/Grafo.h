#ifndef GRAFO_GRAFO_H
#define GRAFO_GRAFO_H

#include "Aresta.h"

typedef struct vertice *Grafo;

Grafo GrafoInit(int n);
Grafo GrafoFree(Grafo g);

struct aresta *GrafoGetAresta(Grafo g, int vertice);

void GrafoImprimir(Grafo g);

int GrafoGetTam(Grafo g);
int GrafoGrauVertice(Grafo g, int vertice);

_Bool GrafoInserir(Grafo g, int orig, int dest, float custo);
_Bool GrafoRemover(Grafo g, int orig, int dest);
_Bool GrafoEsparco(Grafo g);

#endif //GRAFO_GRAFO_H
