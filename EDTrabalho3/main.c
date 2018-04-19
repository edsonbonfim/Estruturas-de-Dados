/**
 * Estrutura de Dados
 * Trabalho 3 (Arvore Binaria de Busca)
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

int menor(arvore *a, int m)
{
    if (a != NULL && a->esq != NULL && a->dir != NULL)
    {
        m = (m > a->esq->info) ? a->esq->info : m;
        m = (m > a->dir->info) ? a->dir->info : m;

        m = menor(a->esq, m);
        m = menor(a->dir, m);
    }
    return m;
}

int maior(arvore *a, int m)
{
    if (a != NULL && a->esq != NULL && a->dir != NULL)
    {
        m = (m < a->esq->info) ? a->esq->info : m;
        m = (m < a->dir->info) ? a->dir->info : m;

        m = maior(a->esq, m);
        m = maior(a->dir, m);
    }
    return m;
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

bool arvoreOrdenada(arvore *a)
{
    if (a == NULL || a->esq == NULL || a->dir == NULL)
        return true;

    if (maior(a->esq, a->esq->info) > a->info || menor(a->dir, a->dir->info) < a->info)
        return false;

    return arvoreOrdenada(a->esq) && arvoreOrdenada(a->dir);
}

arvore *inserir(arvore *a, int elem)
{
    if (a == NULL)
    {
        a = (arvore *) malloc(sizeof(arvore));
        a->info = elem;
        a->esq = NULL;
        a->dir = NULL;
    }

    else if (elem < a->info)
        a->esq = inserir(a->esq, elem);

    else
        a->dir = inserir(a->dir, elem);

    return a;
}

arvore *remover(arvore *a, int elem)
{
    if (a == NULL)
        return NULL;

    if (a->info == elem)
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

    else if (elem < a->info)
        a->esq = remover(a->esq, elem);

    else
        a->dir = remover(a->dir, elem);

    return a;
}

bool existe(arvore *a, int elem)
{
    if (a == NULL)
        return false;

    if (a->info == elem)
        return true;

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
    if (a == NULL)
        return;

    if (a->info >= x && a->info <= y)
    {
        imprimirIntervalo(a->esq, x, y);
        printf("%d ", a->info);
        imprimirIntervalo(a->dir, x, y);
    }

    else if (a->info < x)
        imprimirIntervalo(a->dir, x, y);

    else
        imprimirIntervalo(a->esq, x, y);
}

void imprimirUniao (arvore *a, int x, int y)
{
    if (a == NULL)
        return;

    if (a->info <= x || a->info >= y)
        printf("%d ", a->info);

    imprimirUniao(a->esq, x, y);
    imprimirUniao(a->dir, x, y);
}

arvore *liberar(arvore *a)
{
    if (a != NULL)
    {
        a->esq = liberar(a->esq);
        a->dir = liberar(a->dir);
        free(a);
    }

    return NULL;
}

int main(void)
{
    char entrada[20];

    printf("DIGITE O NOME DO ARQUIVO: ");
    scanf("%s", entrada);

    if(strstr(entrada, ".txt") == NULL)
        strcat(entrada, ".txt");

    FILE *arq = fopen(entrada, "r");

    if (arq == NULL)
    {
        fprintf(stderr, "ERRO: NAO FOI POSSIVEL ABRIR O ARQUIVO: '%s'.", entrada);
        return -1;
    }

    arvore *a = NULL;

    a = ler(a, arq);

    fclose(arq);

    if (!arvoreOrdenada(a))
    {
        fprintf(stderr, "ERRO: A ARVORE NAO ESTA ORDENADA.");
        liberar(a);
        return -1;
    }

    int opt, elem, x, y;

    while (true)
    {
        printf("1. INSERIR UM ELEMENTO NA ARVORE\n");
        printf("2. REMOVER UM ELEMENTO NA ARVORE\n");
        printf("3. IMPRIMIR EM-ORDEM\n");
        printf("4. IMPRIMIR PRE-ORDEM\n");
        printf("5. IMPRIMIR POS-ORDEM\n");
        printf("6. IMPRIMIR NOTACAO PARENTESES\n");
        printf("7. ALTURA DA ARVORE\n");
        printf("8. IMPRIMIR ELEMENTOS NO INTERVALO X <= ELEM <= Y\n");
        printf("9. IMPRIMIR ELEMENTO NO INTERVALO X >= ELEM >= Y\n");
        printf("10. SAIR\n");

        scanf("%d", &opt);

        printf("\n");

        switch (opt)
        {
            case 1:
                printf("QUAL ELEMENTO DESEJA INSERIR?\n");
                scanf("%d", &elem);
                a = inserir(a, elem);
                printf("ELEMENTO '%d' INSERIDO COM SUCESSO!\n", elem);
                break;

            case 2:
                printf("QUAL ELEMENTO DESEJA REMOVER?\n");
                scanf("%d", &elem);
                if (existe(a, elem))
                {
                    a = remover(a, elem);
                    printf("ELEMENTO '%d' REMOVIDO COM SUCESSO!\n", elem);
                }
                else
                    fprintf(stderr, "ERRO: ELEMENTO '%d' NAO ENCONTRADO.\n", elem);
                break;

            case 3:
                emOrdem(a);
                break;

            case 4:
                preOrdem(a);
                break;

            case 5:
                posOrdem(a);
                break;

            case 6:
                notacaoParenteses(a);
                break;

            case 7:
                printf("A ARVORE TEM ALTURA '%d'\n", altura(a));
                break;

            case 8:
                printf("QUAL INTERVALO DESEJA USAR CONSULTAR?\n");
                scanf("%d %d", &x, &y);
                imprimirIntervalo(a, x, y);
                break;

            case 9:
                printf("QUAL INTERVALO DESEJA USAR CONSULTAR?\n");
                scanf("%d %d", &x, &y);
                imprimirUniao(a, x, y);
                break;

            default:
                liberar(a);
                return 0;
        }

        printf("\n");
    }
}
