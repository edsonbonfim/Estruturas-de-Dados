#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

typedef struct lista *Lista;

Lista ListaInit(void);
Lista ListaFree(Lista l);
Lista ListaProx(Lista l);

Lista ListaInserir(Lista l, int dest, float custo);
Lista ListaRemover(Lista l, int dest);

void ListaImprimir(Lista l);

int ListaContDest(Lista l, int dest);
int ListaContElem(Lista l);

int ListaGetDestino(Lista l);
float ListaGetCusto(Lista l);

_Bool ListaExisteDestino(Lista l, int dest);

#endif //GRAFO_LISTA_H
