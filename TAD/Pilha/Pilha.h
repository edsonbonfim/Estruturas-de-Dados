#ifndef TAD_PILHA_H
#define TAD_PILHA_H

typedef struct pilha *Pilha;

int vaziaPilha(Pilha p);
int removerPilha(Pilha p);

void inserirPilha(Pilha p, int val);
void imprimirPilha(Pilha p);

Pilha inicializarPilha(void);
Pilha destruirPilha(Pilha p);

#endif