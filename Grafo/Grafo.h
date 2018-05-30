#ifndef GRAFO_GRAFO_H
#define GRAFO_GRAFO_H

#include <stdbool.h>

typedef struct grafo *Grafo;

Grafo iniGrafo(int n);
Grafo freeGrafo(Grafo grafo);

void imprimirGrafo(Grafo grafo);

int grauVertice(Grafo grafo, int vertice);

bool inserirArestaGrafo(Grafo grafo, int vertice, int destino, float custo);
bool removerArestaGrafo(Grafo grafo, int vertice, int destino);
bool isEsparco(Grafo grafo);

#endif //GRAFO_GRAFO_H
