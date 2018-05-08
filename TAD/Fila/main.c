/** Trabalho de Estruturas de Dados
 *
 * Trabalho 06 - Tipo abstrato de dados
 *
 * Edson Onildo
 * Isabela Carvalho
 *
 *
 * main.c
 */


#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(void)
{
    Fila f = inicializar();
    int x;

    inserir(f, 10);
    inserir(f, 20);

    imprimir(f);

    x = remover(f);
    printf("\n%d", x);


    destruir(f);

    return EXIT_SUCCESS;
}