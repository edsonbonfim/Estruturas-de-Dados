#ifndef GRAFO_ARESTA_H
#define GRAFO_ARESTA_H

typedef struct aresta *Aresta;

Aresta ArestaInit(void);
Aresta ArestaFree(Aresta a);
Aresta ArestaProx(Aresta a);

Aresta ArestaInserir(Aresta a, int dest, float custo);
Aresta ArestaRemover(Aresta a, int dest);

void ArestaImprimir(Aresta a);

int ArestaContDest(Aresta a, int dest);
int ArestaContElem(Aresta a);

int ArestaGetDest(Aresta a);
float ArestaGetCusto(Aresta a);

_Bool ArestaExisteDest(Aresta a, int dest);

#endif //GRAFO_ARESTA_H
