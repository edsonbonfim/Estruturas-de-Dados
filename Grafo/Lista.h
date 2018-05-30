#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include <stdbool.h>

typedef struct lista *Lista;

Lista iniLista(void);
Lista freeLista(Lista lista);
Lista inserirLista(Lista lista, int destino, float custo);
Lista removerLista(Lista lista, int destino);

void imprimirLista(Lista lista);

int contarDestinoLista(Lista lista, int destino);
int contarElementosLista(Lista lista);

bool existeLista(Lista lista, int destino);

#endif //GRAFO_LISTA_H
