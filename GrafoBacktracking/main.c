#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Tools.h"
#include "Grafo.h"

bool existirElemVet(const int *vet, int pos, int elem)
{
    for (int i = 0; i < pos; i++)
        if (vet[i] == elem)
            return true;

    return false;
}

void caminhosNoIntermediario(Grafo g, int *vet, int pos, int dest, int noIntermed)
{
    Aresta a = GrafoGetAresta(g, vet[pos-1]);

    if (vet[pos-1] == dest && existirElemVet(vet, pos, noIntermed))
    {
        for (int i = 0; i < pos; i++)
            printf("%d ", vet[i]);

        printf("\n");
    }
    else
    {
        for (a; !isNull(a); a = ArestaProx(a))
        {
            if (!existirElemVet(vet, pos, ArestaGetDest(a)))
            {
                vet[pos] = ArestaGetDest(a);
                caminhosNoIntermediario(g, vet, pos+1, dest, noIntermed);
            }
        }
    }
}

void ciclosHamiltonianos(Grafo g, int *vet, int pos)
{
    Aresta a = GrafoGetAresta(g, vet[pos-1]);

    if (GrafoGetTamanho(g) == pos-1 && vet[pos-1] == vet[0])
    {
        for (int i = 0; i < pos; i++)
            printf("%d ", vet[i]);

        printf("\n");
    }
    else
    {
        for (a; !isNull(a); a = ArestaProx(a))
        {
            if (!existirElemVet(vet, pos, ArestaGetDest(a)) || ArestaGetDest(a) == vet[0])
            {
                vet[pos] = ArestaGetDest(a);
                ciclosHamiltonianos(g, vet, pos+1);
            }
        }
    }
}

int main()
{
    Grafo g;
    float custo;
    int n, orig, dest, *v;

    printf("NUMERO DE VERTICES: ");
    scanf("%d", &n);

    g = GrafoInit(n);
    v = (int *) malloc(n * sizeof(int));

    checkMalloc(v);

    while (1)
    {
        printf("\n1. INSERIR UMA ARESTA\n");
        printf("2. REMOVER UMA ARESTA\n");
        printf("3. IMPRIMIR O GRAFO\n");
        printf("4. GRAU DE UM VERTICE\n");
        printf("5. VERIFICAR SE EH ESPARCO\n");
        printf("6. IMPRIMIR CAMINHOS QUE PASSAM POR UM VERTICE INTERMEDIARIO\n");
        printf("7. IMPRIMIR O CAMINHO DE MENOR CUSTO\n");
        printf("8. IMPRIMIR CICLOS HAMILTONIANOS\n");
        printf("9. SAIR\n");
        printf("\nOPCAO: ");
        scanf("%d", &n);

        switch (n)
        {
            case 1:
                printf("ORIGEM DESTINO CUSTO: ");
                scanf("%d %d %f", &orig, &dest, &custo);
                GrafoInserir(g, orig, dest, custo);
                break;

            case 2:
                printf("ORIGEM DESTINO: ");
                scanf("%d %d", &orig, &dest);
                GrafoRemover(g, orig, dest);
                break;

            case 3:
                GrafoImprimir(g);
                break;

            case 4:
                printf("VERTICE: ");
                scanf("%d", &orig);
                printf("GRAU: %d\n", GrafoGrauVertice(g, orig));
                break;

            case 5:
                GrafoEsparco(g) ? printf("\nEH ESPARCO\n") : printf("\nNAO EH ESPARCO\n");
                break;

            case 6:
                printf("ORIGEM DESTINO INTERMEDIARIO: ");
                scanf("%d %d %d", &orig, &dest, &n);
                v[0] = orig;
                caminhosNoIntermediario(g, v, 1, dest, n);
                break;

            case 7:
                //caminhosMenorCusto(g, v, 1);
                break;

            case 8:
                printf("VERTICE DE PARTIDA: ");
                scanf("%d", &orig);
                v[0] = orig;
                ciclosHamiltonianos(g, v, 1);
                break;

            default:
                free(v);
                GrafoFree(g);
                return EXIT_SUCCESS;
        }
    }
}
