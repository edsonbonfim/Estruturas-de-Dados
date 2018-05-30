/**
 * Estruturas de Dados
 *
 * Tipo Abstrato de Dados (Pilha)
 *
 * Edson Onildo
 * Isabela Carvalho
 *
 * pilha.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#include "Lista.h"

#define N 100

struct pilha
{
    Lista lista;
};

Pilha inicializarPilha(void)
{
    Pilha p = (Pilha) malloc(sizeof(struct pilha));
    p->lista = inicializarLista();
    return p;
}

Pilha destruirPilha(Pilha p)
{
    p->lista = destruirLista(p->lista);
    free(p);
    return NULL;
}

void inserirPilha(Pilha p, int val)
{
    p->lista = inserirFinalLista(p->lista, val);
}

void imprimirPilha(Pilha p)
{
    imprimirLista(p->lista);
}

int vaziaPilha(Pilha p)
{
    return vaziaLista(p->lista);
}

int contarPilha(Pilha p)
{
    return contarLista(p->lista);
}

int cheiaPilha(Pilha p)
{
    return contarPilha(p) >= N;
}

int removerPilha(Pilha p)
{
    int ret;
    p->lista = removerFinalLista(p->lista, &ret);
    return ret;
}