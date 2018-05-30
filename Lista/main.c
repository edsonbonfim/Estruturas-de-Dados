#include <stdlib.h>
#include <stdio.h>

typedef struct lista {
    int info;
    struct lista *prox;
} Lista;

Lista *criaLista()
{
    return NULL;
}

int existe(Lista *l, int v)
{
    if (l == NULL)
        return 0;

    if (l->info == v)
        return 1;

    return existe(l->prox, v);
}

Lista *insereInicio (Lista *l, int v)
{
    Lista *no = (Lista*) malloc(sizeof(Lista));
    no->info = v;
    no->prox = l;

    return no;
}

Lista *insereFim (Lista *l, int v)
{
    if (l != NULL)
        l->prox = insereFim(l->prox, v);

    else
    {
        Lista *no = (Lista*) malloc(sizeof(Lista));
        no->info = v;
        no->prox = NULL;
        l = no;
    }

    return l;
}

Lista *retiraElemento (Lista* l, int v)
{
    if (l->info != v)
        l->prox = retiraElemento(l->prox, v);

    else
    {
        Lista *t = l;
        l = l->prox;
        free(t);
    }

    return l;
}

int conta (Lista *l)
{
    if (l == NULL)
        return 0;

    return 1 + conta(l->prox);
}

int somaPares (Lista *l)
{
    int soma = 0;

    if (l == NULL)
        return 0;

    if (l->info % 2 == 0)
        soma = l->info;

    return soma + somaPares(l->prox);
}

int menu()
{
    int aux;

    printf("\n\n----------------------------------------\n\n");
    printf("Digite um numero conforme a opcao desejada:\n\n");
    printf("1 - Inserir um elemento no inicio da lista;\n");
    printf("2 - Inserir um elemento no final da Lista;\n");
    printf("3 - Remover a primeira ocorrencia de um elemento na lista;\n");
    printf("4 - Verificar se um elemento existe na lista;\n");
    printf("5 - Contar os elementos da lista;\n");
    printf("6 - Somar os elementos pares da lista;\n");
    printf("7 - Sair\n");

    scanf("%d", &aux);

    printf("\n\n----------------------------------------\n\n");

    return aux;
}

void loop(Lista *l)
{
    int aux;

    switch (menu()) {
        case 1:
            printf("Digite o elemento a ser inserido: ");
            scanf("%d", &aux);
            l = insereInicio(l, aux);
            break;

        case 2:
            printf("Digite o elemento a ser inserido: ");
            scanf("%d", &aux);
            l = insereFim(l, aux);
            break;

        case 3:
            printf("Digite o elemento a ser retirado: ");
            scanf("%d", &aux);
            if (!existe(l, aux)){
                printf("Elemento nao encontrado.\n");
            } else {
                l = retiraElemento(l, aux);
                printf("Elemento retirado com sucesso.\n");
            }
            break;

        case 4:
            printf("Digite o elemento a ser procurado: ");
            scanf("%d", &aux);
            if (existe(l, aux))
                printf("Elemento encontrado!\n");
            else
                printf("Elemento nao encontrado!");
            break;

        case 5:
            if (!(aux = conta(l)))
                printf("A lista nao possui elementos\n");
            else
                printf("A lista possui %d elementos\n", aux);
            break;

        case 6:
            if (!(aux = somaPares(l)))
                printf("Nao existem elementos nesta lista");
            else
                printf("A soma e: %d\n", aux);
            break;

        default:
            return;
    }

    loop(l);
}

int main()
{
    loop(criaLista());
    return 0;
}
