/**
 * Estrutura de Dados
 * Trabalho 3 (Arvore Binaria de Busca)
 *
 * Edson Onildo
 * Isabela Carvalho
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

int main(void)
{
    char entrada[20];

    printf("Digite o nome do arquivo: ");
    scanf("%s", entrada);

    FILE *arq = fopen(entrada, "r");

    if (arq == NULL)
    {
        printf("Nao foi possivel abrir o arquivo!\n");
        exit(1);
    }

    arvore *a = NULL;

    a = ler(a, arq);

    fclose(arq);

    int opt = 1, elem, x, y;

    while (opt != 0)
    {
        printf("1. TESTAR SE A ARVORE ESTA ORDENADA\n");
        printf("2. INSERIR UM ELEMENTO NA ARVORE\n");
        printf("3. REMOVER UM ELEMENTO NA ARVORE\n");
        printf("4. IMPRIMIR EM-ORDEM\n");
        printf("5. IMPRIMIR PRE-ORDEM\n");
        printf("6. IMPRIMIR POS-ORDEM\n");
        printf("7. IMPRIMIR NOTACAO PARENTESES\n");
        printf("8. ALTURA DA ARVORE\n");
        printf("9. IMPRIMIR ELEMENTOS NO INTERVALO X <= ELEM <= Y\n");
        printf("10. IMPRIMIR ELEMENTO NO INTERVALO X >= ELEM >= Y\n");
        printf("11. SAIR\n");

        scanf("%d", &opt);

        printf("\n");

        switch (opt)
        {
            case 1:
                if (arvoreOrdenada(a, NULL, NULL))
                    printf("A ARVORE ESTA ORDENADA!\n");
                else
                {
                    printf("A ARVORE NAO ESTA ORDENADA!\n");
                    return -1;
                }
                break;

            case 2:
                printf("QUAL ELEMENTO DESEJA INSERIR?\n");
                scanf("%d", &elem);
                inserir(a, elem);
                printf("ELEMENTO %d INSERIDO COM SUCESSO!\n", elem);
                break;

            case 3:
                printf("QUAL ELEMENTO DESEJA REMOVER?\n");
                scanf("%d", &elem);
                if (existe(a, elem))
                {
                    remover(a, elem);
                    printf("ELEMENTO %d REMOVIDO COM SUCESSO!\n", elem);
                }
                else
                    printf("ESTA ARVORE NAO CONTEM O ELEMENTO %d", elem);
                break;

            case 4:
                emOrdem(a);
                break;

            case 5:
                preOrdem(a);
                break;

            case 6:
                posOrdem(a);
                break;

            case 7:
                notacaoParenteses(a);
                break;

            case 8:
                printf("A ARVORE TEM ALTURA %d\n", altura(a));
                break;

            case 9:
                printf("QUAL INTERVALO DESEJA USAR CONSULTAR?\n");
                scanf("%d %d", &x, &y);
                imprimirIntervalo(a, x, y);
                break;

            case 10:
                printf("QUAL INTERVALO DESEJA USAR CONSULTAR?\n");
                scanf("%d %d", &x, &y);
                imprimirUniao(a, x, y);
                break;

            default:
                opt = 0;
        }

        printf("\n");
    }

    liberar(a);

    return 0;
}
