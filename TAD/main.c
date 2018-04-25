#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(void)
{
    Fila f = inicializar();
    int x;

    inserir(f, 10);
    inserir(f, 20);

    x = remover(f);
    printf("%d", x);

    destruir(f);

    return EXIT_SUCCESS;
}