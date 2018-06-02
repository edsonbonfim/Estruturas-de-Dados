#include <stdio.h>
#include <stdlib.h>
#include "Grafo.h"
#include "BT.h"

//void caminhosNoIntermediario(BT bt, int v)
//{
//    bool cond(BT bt)
//    {
//        return BTGetVet(bt)[BTGetPos(bt)-1] == BTGetDestino(bt) && BTExistirVet(bt, v);
//    }
//    BTImprimir(bt, cond, NULL);
//}

//void caminhosMenorCusto(BT bt)
//{
//    bool cond(BT bt)
//    {
//        if (BTGetVet(bt)[0] != BTGetOrigem(bt))
//            return false;
//
//        if (BTGetVet(bt)[BTGetPos(bt)-1] != BTGetDestino(bt))
//            return false;
//
//        return true;
//    }
//
//    BTImprimir(bt, cond);
//}

//void ciclosHamiltonianos(BT bt, int v)
//{
//    BTSetOrig(&bt, v);
//    BTSetDest(&bt, v);
//
//    bool cond(BT bt)
//    {
//        if (BTGetPos(bt) == BTTamVet(bt))
//            return true;
//
//        return false;
//    }
//
//    bool rec(BT bt)
//    {
//        return false;
//    }
//
//    BTImprimir(bt, cond, rec);
//}

void setOrigemDestino(BT backtrack)
{
    int origem, destino;

    printf("ORIGEM: ");
    scanf("%d", &origem);

    printf("DESTINO: ");
    scanf("%d", &destino);

    BTSetOrig(&backtrack, origem);
    BTSetDest(&backtrack, destino);
    BTSetVet(&backtrack, 0, origem);
}

int main()
{
    int n, vertice, destino;
    float custo;
    Grafo g;

//    printf("NUMERO DE VERTICES: ");
//    scanf("%d", &n);

//    g = GrafoInit(n);

    g = GrafoInit(5);

    GrafoInserir(g, 1, 5, 3);
    GrafoInserir(g, 1, 2, 1);
    GrafoInserir(g, 2, 5, 1);
    GrafoInserir(g, 2, 4, 6);
    GrafoInserir(g, 2, 3, 5);
    GrafoInserir(g, 3, 2, 4);
    GrafoInserir(g, 4, 3, 1);
    GrafoInserir(g, 5, 4, 1);
    GrafoInserir(g, 5, 2, 2);

    BT bt = BTInit(g);

    while (1)
    {
        printf("\nGrafo:\n\n");

        printf("1. INSERIR UMA ARESTA\n");
        printf("2. REMOVER UMA ARESTA\n");
        printf("3. IMPRIMIR O GRAFO\n");
        printf("4. GRAU DE UM VERTICE\n");
        printf("5. VERIFICAR SE EH ESPARCO\n");

        printf("\nGrafo + BACKTRACK\n\n");
        printf("6. IMPRIMIR CAMINHOS QUE PASSAM POR UM VERTICE INTERMEDIARIO\n");
        printf("7. IMPRIMIR O CAMINHO DE MENOR CUSTO\n");
        printf("8. SAIR\n");

        printf("\nOPCAO: ");

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
                GrafoInserir(g, vertice, destino, custo);
                break;

            case 2:
                printf("\nVERTICE: ");
                scanf("%d", &vertice);
                printf("DESTINO: ");
                scanf("%d", &destino);
                GrafoRemover(g, vertice, destino);
                break;

            case 3:
                GrafoImprimir(g);
                break;

            case 4:
                printf("\nVERTICE: ");
                scanf("%d", &vertice);
                printf("GRAU: %d\n", GrafoGrauVertice(g, vertice));
                break;

            case 5:
                GrafoEsparco(g) ? printf("\nEH ESPARCO\n") : printf("\nNAO EH ESPARCO\n");
                break;

            case 6:
                setOrigemDestino(bt);
                printf("NO INTERMEDIARIO: ");
                scanf("%d", &n);
                printf("\n");
                //caminhosNoIntermediario(bt, n);
                break;

            case 7:
                setOrigemDestino(bt);
                printf("\n");
                //caminhosMenorCusto(bt);
                break;

            case 8:
                printf("VERTICE DE PARTIDA: ");
                scanf("%d", &n);
                printf("\n");
                //ciclosHamiltonianos(bt, n);
                break;

            default:
                GrafoFree(g);
                return EXIT_SUCCESS;
        }
    }
}
