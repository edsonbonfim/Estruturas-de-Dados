#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvoreGeral
{
    int info;
    struct arvoreGeral *filho;
    struct arvoreGeral *irmao;
} arvoreGeral;

arvoreGeral *ler(arvoreGeral *a, FILE *arq)
{
    int num;
    char ch;

    fscanf(arq, "%c", &ch);
    fscanf(arq, "%d", &num);

    if (num == -1)
    {
        a = NULL;
    }

    else
    {
        a = (arvoreGeral*) malloc(sizeof(arvoreGeral));
        a->info = num;
        a->filho = ler(a->filho, arq);
        a->irmao = ler(a->irmao, arq);
    }

    fscanf(arq, "%c", &ch);

    return a;
}

void imprimirPreOrdem(arvoreGeral *a)
{
    if (a != NULL)
    {
        printf("%d ", a->info);
        imprimirPreOrdem(a->filho);
        imprimirPreOrdem(a->irmao);
    }
}

void imprimirEmOrdem (arvoreGeral *a)
{
    if (a != NULL)
    {
        imprimirEmOrdem(a->filho);
        printf("%d ", a->info);
        imprimirEmOrdem(a->irmao);
    }
}

void imprimirPosOrdem(arvoreGeral *a)
{
    if (a != NULL)
    {
        imprimirPosOrdem(a->filho);
        imprimirPosOrdem(a->irmao);
        printf("%d ", a->info);
    }
}

void imprimirNivel (arvoreGeral *a, int nivel, int cont)
{
    if (a != NULL)
    {
        if (cont == nivel)
        {
            printf("%d ", a->info);
        }
        else
        {
            imprimirNivel(a->filho, nivel, cont + 1);
            imprimirNivel(a->irmao, nivel, cont + 1);
        }
    }
}

void imprimirEmLargura(arvoreGeral *arvore, int h)
{
    static int nivel = 0;

    if (nivel <= h)
    {
        nivel++;
        imprimirNivel(arvore, nivel, 1);
        printf("\n");
        imprimirEmLargura(arvore, h);
    }
}

void imprimir(arvoreGeral *a)
{
    printf("(");

    if (a != NULL)
    {
        printf("%d", a->info);
        imprimir(a->filho);
        imprimir(a->irmao);
    }
    else
    {
        printf("-1");
    }

    printf(")");
}

void imprimirFolha(arvoreGeral *a)
{
    if (a != NULL)
    {
        if (a->filho == NULL && a->irmao == NULL)
            printf("%d ", a->info);

        else
        {
            imprimirFolha(a->filho);
            imprimirFolha(a->irmao);
        }
    }
}

int existe(arvoreGeral *a, int elem)
{
    if (a == NULL)
        return 0;

    if (a->info == elem)
        return 1;

    if (existe(a->filho, elem))
        return 1;

    if (existe(a->irmao, elem))
        return 1;
}

int somar(arvoreGeral *a)
{
    if (a == NULL)
    {
        return 0;
    }
    else
    {
        return a->info + somar(a->filho) + somar(a->irmao);
    }
}

int contarElemento(arvoreGeral *a, int elem)
{
    if (a == NULL)
        return 0;

    if (a->info == elem)
        return 1 + contarElemento(a->filho, elem) + contarElemento(a->irmao, elem);
    else
        return contarElemento(a->filho, elem) + contarElemento(a->irmao, elem);
}

int contar(arvoreGeral *a)
{
    if (a == NULL)
        return 0;

    return 1 + contar(a->filho) + contar(a->irmao);
}

int contarNoInterno(arvoreGeral *a)
{
    if (a == NULL)
        return 0;

    if (a->filho == NULL && a->irmao == NULL)
        return 0;
    else
        return 1 + contarNoInterno(a->filho) + contarNoInterno(a->irmao);

}

int altura(arvoreGeral *a)
{
    int hd, he;

    if (a == NULL)
        return 0;

    he = altura(a->filho);
    hd = altura(a->irmao);

    if (he > hd)
        return he + 1; //conferir
    else
        return hd + 1;
}

int contaFolha (arvoreGeral *a)
{
    if (a == NULL)
        return 0;

    if (a->filho == NULL && a->irmao == NULL)
        return 1;

    else
        return contaFolha(a->filho) + contaFolha(a->irmao);
}

void liberar(arvoreGeral *a)
{
    if (a != NULL)
    {
        liberar(a->filho);
        liberar(a->irmao);
        free(a);
    }

    a = NULL;
}

int main(void)
{
    FILE *arq;
    char entrada[21];

    printf("Digite o nome do arquivo: ");
    scanf("%s", entrada);

    if (strstr(entrada, ".txt") == NULL)
        strcat(entrada, ".txt");

    if (!(arq = fopen(entrada, "r")))
    {
        printf("Nao foi possivel abrir o arquivo %s\n", entrada);
        return -1;
    }

    arvoreGeral *arvore = NULL;

    arvore = ler(arvore, arq);

    fclose(arq);

    imprimirEmOrdem(arvore);

    return 0;
}
