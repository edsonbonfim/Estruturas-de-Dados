/**
 * Estrutura de Dados
 * Trabalho 4 (Arvore AVL)
 *
 * Repita o trabalho de arvore binaria de busca
 * fazendo as seguintes modificacoes:
 *
 * 1. Ao ler a arvore do arquivo, verificar se a arvore
 * esta ordenada e tambem balanceada
 *
 * 2. Ao inserir ou remover um elemento, verificar se a
 * arvore desbalanceou, se desbalanceou, uma msg de arvore
 * desbalanceada deve ser escrita na tela e o algoritimo de
 * balanceamento deve ser executado
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct arvore
{
    int info;
    struct arvore *esq;
    struct arvore *dir;
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
        a->esq = ler(a->esq, arq);
        a->dir = ler(a->dir, arq);
    }

    fscanf(arq, "%c", &ch);
    return a;
}

int arvoreOrdenada(arvore *a, arvore *esq, arvore *dir)
{
    if (a == NULL)
        return 1;

    if (esq != NULL && a->info < esq->info)
        return 0;

    if (dir != NULL && a->info > dir->info)
        return 0;

    return arvoreOrdenada(a->esq, esq, a) && arvoreOrdenada(a->dir, a, dir);
}

arvore *inserir(arvore *a, int elemento)
{
    if (a == NULL)
    {
        a = (arvore *) malloc(sizeof(arvore));
        a->info = elemento;
        a->esq = NULL;
        a->dir = NULL;
    }

    else if (elemento < a->info)
        a->esq = inserir(a->esq, elemento);

    else
        a->dir = inserir(a->dir, elemento);

    return a;
}

arvore *remover(arvore *a, int elemento)
{
    if (a != NULL)
    {
        if (a->info == elemento)
        {
            if (a->esq == NULL && a->dir == NULL)
            {
                free(a);
                return NULL;
            }

            else if (a->esq == NULL || a->dir == NULL)
            {
                arvore *aux = !a->esq ? a->dir : a->esq;
                free(a);
                return aux;
            }

            else
            {
                arvore *m = a->esq;

                while (m->dir != NULL)
                    m = m->dir;

                a->info = m->info;
                a->esq = remover(a->esq, a->info);

                return a;
            }
        }

        else if (elemento < a->info)
            a->esq = remover(a->esq, elemento);

        else
            a->dir = remover(a->dir, elemento);
    }

    return a;
}

int altura(arvore *a)
{
    if (a == NULL)
        return 0;

    int he = altura(a->esq);
    int hd = altura(a->dir);

    if (he > hd)
        return he + 1;

    return hd + 1;
}

arvore *balancear(arvore *a)
{
    if (a != NULL)
    {
        int hd, he;

        a->esq = balancear(a->esq);
        a->dir = balancear(a->dir);

        he = altura(a->esq);
        hd = altura(a->dir);

        // Desbalanceado para a direita
        if (hd - he > 1)
        {
            int x;
            arvore *aux = a->dir;

            while (aux->esq != NULL)
                aux = aux->esq;

            x = a->info;
            a->info = aux->info;

            a->dir = remover(a->dir, aux->info);
            a->esq = inserir(a->esq, x);

            a = balancear(a);
        }

            // Desabalanceado para a esquerda
        else if (he - hd > 1)
        {
            int x;
            arvore *aux = a->esq;

            while (aux->dir != NULL)
                aux = aux->dir;

            x = a->info;
            a->info = aux->info;

            a->esq = remover(a->esq, aux->info);
            a->dir = inserir(a->dir, x);

            a = balancear(a);
        }
    }

    return a;
}

int existe(arvore *a, int elem)
{
    if (a == NULL)
        return 0;

    if (a->info == elem)
        return 1;

    return (a->info > elem) ? existe(a->esq, elem) : existe(a->dir, elem);
}

void emOrdem(arvore *a)
{
    if (a != NULL)
    {
        emOrdem(a->esq);
        printf("%d ", a->info);
        emOrdem(a->dir);
    }
}

void preOrdem(arvore *a)
{
    if (a != NULL)
    {
        printf("%d ", a->info);
        preOrdem(a->esq);
        preOrdem(a->dir);
    }
}

void posOrdem(arvore *a)
{
    if (a != NULL)
    {
        posOrdem(a->esq);
        posOrdem(a->dir);
        printf("%d ", a->info);
    }
}

void notacaoParenteses(arvore *a)
{
    printf("(");

    if (a == NULL)
        printf("-1");

    else
    {
        printf("%d", a->info);
        notacaoParenteses(a->esq);
        notacaoParenteses(a->dir);
    }

    printf(")");
}

void imprimirIntervalo(arvore *a, int x, int y)
{
    if (a != NULL)
    {
        if (a->info >= x && a->info <= y)
            printf("%d ", a->info);

        imprimirIntervalo(a->esq, x, y);
        imprimirIntervalo(a->dir, x, y);
    }
}

void imprimirUniao (arvore *a, int x, int y)
{
    if (a != NULL)
    {
        if (a->info <= x || a->info >= y)
            printf("%d ", a->info);

        imprimirUniao(a->esq, x, y);
        imprimirUniao(a->dir, x, y);
    }
}

void liberar(arvore *a)
{
    if (a != NULL)
    {
        liberar(a->esq);
        liberar(a->dir);
        free(a);
    }

    a = NULL;
}

int main()
{

    return 0;
}