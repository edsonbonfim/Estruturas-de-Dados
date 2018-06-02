#ifndef GRAFO_GRAFO_H
#define GRAFO_GRAFO_H

typedef struct grafo *Grafo;

Grafo GrafoInit(int n);
Grafo GrafoFree(Grafo g);

struct lista *GrafoGetVertice(Grafo g, int vertice);

void GrafoImprimir(Grafo g);

int GrafoTamanho(Grafo g);
int GrafoGrauVertice(Grafo g, int vertice);

float GrafoGetCusto(Grafo g, int pos);

_Bool GrafoInserir(Grafo g, int orig, int dest, float custo);
_Bool GrafoRemover(Grafo g, int orig, int dest);
_Bool GrafoEsparco(Grafo g);

#endif //GRAFO_GRAFO_H
