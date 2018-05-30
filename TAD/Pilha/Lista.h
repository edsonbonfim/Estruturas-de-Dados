/**
 * Estruturas de Dados
 *
 * Tipo Abstrato de Dados (Pilha)
 *
 * Edson Onildo
 * Isabela Carvalho
 *
 * lista.h
 */

#ifndef TAD_LISTA_H
#define TAD_LISTA_H

typedef struct lista *Lista;

int vaziaLista(Lista l);
int contarLista(Lista l);

void imprimirLista(Lista l);

Lista inicializarLista(void);
Lista destruirLista(Lista l);
Lista inserirFinalLista(Lista l, int val);
Lista removerFinalLista(Lista l, int *ret);

#endif