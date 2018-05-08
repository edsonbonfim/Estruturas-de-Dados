#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#include "Lista.h"

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

int removerPilha(Pilha p)
{
	int ret;
	p->lista = removerFinalLista(p->lista, &ret);
	return ret;
}