/**
 * Estruturas de Dados
 * Trabalho 4 (Arvore Geral)
 *
 * Edson Onildo
 * Isabela Carvalho
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct arvore
{
    int info;
    struct arvore *filho;
    struct arvore *irmao;
} arvore;

arvore *ler(arvore *a, FILE *arq)
{
    int num;
    char ch;

    fscanf(arq, "%c", &ch);
    fscanf(arq, "%d", &num);

    if (num == -1)
        a = NULL;
    else
    {
        a = (arvore *) malloc(sizeof(arvore));
        a->info = num;
        a->filho = ler(a->filho, arq);
        a->irmao = ler(a->irmao, arq);
    }

    fscanf(arq, "%c", &ch);

    return a;
}

int altura(arvore *a)
{
    if (a == NULL)
        return 0;
    else
    {
        int hf = altura(a->filho) + 1;
        int hi = altura(a->irmao);

        if (hf > hi)
            return hf;
        else
            return hi;
    }
}

int contarFolhas (arvore *a)
{
    if (a == NULL)
        return 0;

    int cont = contarFolhas(a->filho) + contarFolhas(a->irmao);

    return (a->filho == NULL) ? 1 + cont : cont;
}

bool existe(arvore *a, int num)
{
    if (a == NULL)
        return false;

    if (a->info == num)
        return true;

    return existe(a->filho, num) || existe(a->irmao, num);
}

arvore *inserir(arvore *a, int x, int y)
{
    if (a != NULL)
    {
        if (a->info == y)
        {
            arvore *filho = a->filho;
            a->filho = (arvore *) malloc(sizeof(arvore));
            a->filho->info = x;
            a->filho->filho = NULL;
            a->filho->irmao = (filho != NULL) ? filho : NULL;
        }
        else
        {
            a->filho = inserir(a->filho, x, y);
            a->irmao = inserir(a->irmao, x, y);
        }
    }

    return a;
}

int nivelDoNo(arvore *a, int elem, int cont)
{
    if (a == NULL)
        return 0;

    if (a->info == elem)
        return cont;

    return nivelDoNo(a->filho, elem, cont+1) + nivelDoNo(a->irmao, elem, cont);
}

void imprimirNotacao(arvore *a)
{
    printf("(");

    if (a == NULL)
        printf("-1");
    else
    {
        printf("%d", a->info);
        imprimirNotacao(a->filho);
        imprimirNotacao(a->irmao);
    }

    printf(")");
}

void imprimirNivel(arvore *a, int nivel, int cont)
{
    if (a == NULL)
        return;

    if (cont == nivel)
    {
        printf("%d ", a->info);
        imprimirNivel(a->irmao, nivel, cont);
    }
    else
    {
        imprimirNivel(a->filho, nivel, cont+1);
        imprimirNivel(a->irmao, nivel, cont);
    }
}

void imprimirLargura(arvore *a, int h)
{
    for (int i = 1; i <= h; i++)
    {
        imprimirNivel(a, i, 1);
        printf("\n");
    }
}

arvore *liberar(arvore *a)
{
    if (a == NULL)
        return NULL;

    a->irmao = liberar(a->irmao);
    a->filho = liberar(a->filho);
    free(a);
}

void imprimirNoInterno(arvore *a)
{
    if (a == NULL)
        return;

    if (a->filho != NULL)
        printf("%d ", a->info);

    imprimirNoInterno(a->filho);
    imprimirNoInterno(a->irmao);
}

void menu()
{
    printf("DIGITE A OPCAO DESEJADA: \n\n");
    printf("1. IMPRIMIR EM NOTACAO DE PARENTESES\n");
    printf("2. IMPRIMIR EM LARGURA\n");
    printf("3. IMPRIMIR OS NOS INTERNOS\n");
    printf("4. IMPRIMIR O NIVEL DE UM NO\n");
    printf("5. ALTURA DA ARVORE\n");
    printf("6. NUMERO DE FOLHAS\n");
    printf("7. INSERIR UM NO X COMO FILHO DO NO Y\n");
}

int main(void)
{
    char entrada[20];

    printf("DIGITE O NOME DO ARQUIVO: ");
    scanf("%s", entrada);

    if (!strstr(entrada, ".txt"))
        strcat(entrada, ".txt");

    FILE *arq = fopen(entrada, "r");

    if (arq == NULL)
    {
        fprintf(stderr, "ERRO: NAO FOI POSSIVEL ABRIR O ARQUIVO '%s'.", entrada);
        return EXIT_FAILURE;
    }

    arvore *a = NULL;

    a = ler(a, arq);

    fclose(arq);

    int opcao, elem, x, y;

    while (true)
    {
        menu();
        scanf("%d", &opcao);

        printf("\n");

        switch (opcao)
        {
            case 1:
                imprimirNotacao(a);
                break;

            case 2:
                imprimirLargura(a, altura(a));
                break;

            case 3:
                imprimirNoInterno(a);
                break;

            case 4:
                printf("DIGITE UM ELEMENTO: ");
                scanf("%d", &elem);
                printf("O ELEMENTO '%d' ESTA NO NIVEL '%d'.", elem, nivelDoNo(a, elem, 1));
                break;

            case 5:
                printf("A ARVORE TEM ALTURA '%d'.", altura(a));
                break;

            case 6:
                printf("A ARVORE POSSUI '%d' FOLHAS.", contarFolhas(a));
                break;

            case 7:
                printf("DIGITE UM ELEMENTO PARA SER INSERIDO: ");
                scanf("%d", &x);
                printf("DIGITE O NO Y: ");
                scanf("%d", &y);
                if (existe(a, y))
                    a = inserir(a, x, y);
                else
                    fprintf(stderr, "ERRO: ELEMENTO '%d' NAO ENCONTRADO.", y);
                break;

            default:
                liberar(a);
                return EXIT_SUCCESS;
        }
        fflush(stdin);
        printf("\n\n");
    }
}