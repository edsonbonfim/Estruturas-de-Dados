#ifndef TAD_FILA_H
#define TAD_FILA_H

typedef struct fila *Fila;

Fila inicializar(void);
Fila destruir(Fila f);

int vazia(Fila f);
int cheia(Fila f);
int remover(Fila f);

void imprimir(Fila f);
void inserir(Fila f, int x);

#endif //TAD_FILA_H
