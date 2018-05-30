#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"

int main()
{
    int n, vertice, destino;
    float custo;
    Grafo grafo;

    printf("NUMERO DE VERTICES: ");
    scanf("%d", &n);

    grafo = iniGrafo(n);

    while (1)
    {
        printf("\n1. INSERIR UMA ARESTA\n");
        printf("2. REMOVER UMA ARESTA\n");
        printf("3. IMPRIMIR O GRAFO\n");
        printf("4. GRAU DE UM VERTICE\n");
        printf("5. VERIFICAR SE EH ESPARCO\n");
        printf("6. SAIR\n");

        scanf("%d", &n);

        switch (n)
        {
            case 1:
                printf("\nVERTICE: ");
                scanf("%d", &vertice);
                printf("DESTINO: ");
                scanf("%d", &destino);
                printf("CUSTO: ");
                scanf("%f", &custo);
                inserirArestaGrafo(grafo, vertice, destino, custo);
                break;

            case 2:
                printf("\nVERTICE: ");
                scanf("%d", &vertice);
                printf("DESTINO: ");
                scanf("%d", &destino);
                removerArestaGrafo(grafo, vertice, destino);
                break;

            case 3:
                imprimirGrafo(grafo);
                break;

            case 4:
                printf("\nVERTICE: ");
                scanf("%d", &vertice);
                printf("GRAU: %d\n", grauVertice(grafo, vertice));
                break;

            case 5:
                isEsparco(grafo) ? printf("\nEH ESPARCO\n") : printf("\nNAO EH ESPARCO\n");
                break;

            default:
                freeGrafo(grafo);
                return EXIT_SUCCESS;
        }
    }
}
