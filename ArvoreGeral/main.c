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

//Estrutura da arvore geral
typedef struct arvore
{
    int info;
    struct arvore *filho;
    struct arvore *irmao;
} arvore;

//Le arvore do arquivo
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

//Altura da arvore
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

//Conta as folhas da arvore
int contarFolhas (arvore *a)
{
    static int cont = 0;

    if (a != NULL)
    {
        if (a->filho == NULL)
        {
            cont++;
        }
        else
        {
            contarFolhas(a->filho);
            contarFolhas(a->irmao);
        }
    }
}

//Verificar se um no existe na arvore
bool existe(arvore *a, int num)
{
    if (a != NULL)
    {
        if (a->info == num)
            return true;
        else
        {
            return existe(a->filho, num) && existe(a->irmao, num);
        }
    }

    return false;
}

arvore *inserir(arvore *a, int x, int y)
{
    if (a != NULL)
    {
        if (a->info == y)
        {
            if (a->filho == NULL)
            {
                a->filho = (arvore *) malloc(sizeof(arvore));
                a->filho->info = x;
                a->filho->filho = NULL;
                a->filho->irmao = NULL;
            }

            else
            {
                arvore *aux = (arvore *) malloc(sizeof(arvore));
                aux->info = x;
                aux->filho = NULL;
                aux->irmao = a->irmao;
                a = aux;
            }
        }

        else
        {
            a = inserir(a, x, y);
        }
    }

    return a;
}

int nivelDoNo(arvore *a, int elem, int cont)
{
    int t1,t2;

    if (a == NULL)
    {
        return 0;
    }

    else
    {
        if (a->info == elem)
        {
            return cont;
        }
        else
        {
            t1 = nivelDoNo(a->filho, elem, cont+1);
            t2 = nivelDoNo(a->irmao, elem, cont);
            if (t1 == 0 || t2 == 0)
            {
                return t1 + t2;
            }
            else
            {
                return t1;
            }
        }
    }
}

//Imprimir Pre Ordem
void preOrdem(arvore *a)
{
    if (a != NULL)
    {
        printf("%d ", a->info);
        preOrdem(a->filho);
        preOrdem(a->irmao);
    }
}

//Imprimir Em Ordem
void emOrdem(arvore *a)
{
    if (a != NULL)
    {
        emOrdem(a->filho);
        printf("%d ", a->info);
        emOrdem(a->irmao);
    }
}

//Imprimir Pos Ordem
void posOrdem(arvore *a)
{
    if (a != NULL)
    {
        posOrdem(a->filho);
        posOrdem(a->irmao);
        printf("%d ", a->info);
    }
}

//Imprimir em Notacao de Parenteses
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

//Imprimir Um Nivel da arvore
void imprimirNivel(arvore *a, int nivel, int cont)
{
    if (a != NULL)
    {
        if (cont == nivel)
        {
            printf("%d ", a->info);
            imprimirNivel(a->irmao, nivel, cont);
        } else{
            imprimirNivel(a->filho, nivel, cont+1);
            imprimirNivel(a->irmao, nivel, cont);
        }
    }
}

//Imprimir a arvore em Largura
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
    if (a != NULL)
    {
        a->irmao = liberar(a->irmao);
        a->filho = liberar(a->filho);
        free(a);
    }

    return NULL;
}

//Imprimir um No Interno
void imprimirNoInterno(arvore *a)
{
    if (a != NULL)
    {
        if (a->filho != NULL)
            printf("%d ", a->info);

        imprimirNoInterno(a->filho);
        imprimirNoInterno(a->irmao);
    }
}

void menu()
{
    printf("Digite a opcao desejada: \n");
    printf("\n1 - Imprimir em Notacao de Parenteses\n");
    printf("2 - Imprimir em Largura\n");
    printf("3 - Imprimir os nos internos\n");
    printf("4 - Imprimir o nivel de um no\n");
    printf("5 - Altura da Arvore\n");
    printf("6 - Numero de Folhas\n");
    printf("7 - Inserir um no x como filho do no y\n");
}

int main(void)
{
    char entrada[20];

    printf("DIGITE O NOME DO ARQUIVO: ");
    scanf("%s", entrada);

    if (!strstr(entrada, ".txt"))
    {
        strcat(entrada, ".txt");
    }

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
                printf("Digite um elemento: ");
                scanf("%d", &elem);
                printf("O ELEMENTO '%d' ESTA NO NIVEL '%d'", elem, nivelDoNo(a, elem, 1));
                break;

            case 5:
                printf("A Arvore tem altura: %d", altura(a));
                break;

            case 6:
                printf("A Arvore possui %d folhas\n", contarFolhas(a));
                break;

            case 7:
                printf("Digite um elemento para ser inserido: ");
                scanf("%d", &x);
                printf("Digite o no y: ");
                scanf("%d", &y);

            default:
                liberar(a);
                return EXIT_SUCCESS;
        }
        printf("\n\n");
    }
}