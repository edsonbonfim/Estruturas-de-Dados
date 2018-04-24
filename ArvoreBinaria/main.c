#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//estrutura da arvore
typedef struct arvore
{
    int info;
    struct arvore *esq;
    struct arvore *dir;
} arvore;

//cria e le a arvore do arquivo
arvore *criar (arvore *a, FILE *arq)
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
        a = (arvore*) malloc(sizeof(arvore));
        a->info = num;
        a->esq = criar(a->esq, arq);
        a->dir = criar(a->dir, arq);
    }

    fscanf(arq, "%c", &ch);

    return a;
}

//imprime a arvore em pre odem
void imprimirPreOrdem (arvore *a)
{
    if (a != NULL)
    {
        printf("%d ", a->info);
        imprimirPreOrdem(a->esq);
        imprimirPreOrdem(a->dir);
    }
}

//imprime a arvore em ordem
void imprimirEmOrdem (arvore *a)
{
    if (a != NULL)
    {
        imprimirEmOrdem(a->esq);
        printf("%d ", a->info);
        imprimirEmOrdem(a->dir);
    }
}

//imprime a arvore em pos ordem
void imprimirPosOrdem(arvore *a)
{
    if (a != NULL)
    {
        imprimirPosOrdem(a->esq);
        imprimirPosOrdem(a->dir);
        printf("%d ", a->info);
    }
}

//imprime um nivel da arvore
void imprimirNivel (arvore *a, int nivel, int cont)
{
    if (a != NULL)
    {
        if (cont == nivel)
        {
            printf("%d ", a->info);
        }
        else
        {
            imprimirNivel(a->esq, nivel, cont + 1);
            imprimirNivel(a->dir, nivel, cont + 1);
        }
    }
}

//imprimir em largura
void imprimirEmLargura(arvore *arvore, int h)
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

//imprime a arvore na notacao da sala
void imprimir(arvore *a)
{
    printf("(");

    if (a != NULL)
    {
        printf("%d", a->info);
        imprimir(a->esq);
        imprimir(a->dir);
    }
    else
    {
        printf("-1");
    }

    printf(")");
}

//imprime as folhas da arvore
void imprimirFolha(arvore *a)
{
    if (a != NULL)
    {
        if (a->esq == NULL && a->dir == NULL)
            printf("%d ", a->info);

        else
        {
            imprimirFolha(a->esq);
            imprimirFolha(a->dir);
        }
    }
}


//verifica se um elemento existe na arvore
int existe(arvore *a, int elem)
{
    if (a == NULL)
        return 0;

    if (a->info == elem)
        return 1;

    if (existe(a->esq, elem))
        return 1;

    if (existe(a->dir, elem))
        return 1;
}

//soma todos os elementos da arvore
int somar(arvore *a)
{
    if (a == NULL)
    {
        return 0;
    }
    else
    {
        return a->info + somar(a->esq) + somar(a->dir);
    }
}

//conta quantas ocorrencias de um elemento a arvore possui
int contarElemento(arvore *a, int elem)
{
    if (a == NULL)
        return 0;

    if (a->info == elem)
        return 1 + contarElemento(a->esq, elem) + contarElemento(a->dir, elem);
    else
        return contarElemento(a->esq, elem) + contarElemento(a->dir, elem);
}

//conta quantos elementos a arvore possui
int contar(arvore *a)
{
    if (a == NULL)
        return 0;

    return 1 + contar(a->esq) + contar(a->dir);
}

//conta quantos nos internos a arvore possui
int contarNoInterno(arvore *a)
{
    if (a == NULL)
        return 0;

    if (a->esq == NULL && a->dir == NULL)
        return 0;
    else
        return 1 + contarNoInterno(a->esq) + contarNoInterno(a->dir);

}

//verificando a altura da arvore
int altura(arvore *a)
{
    int hd, he;

    if (a == NULL)
        return 0;

    he = altura(a->esq);
    hd = altura(a->dir);

    if (he > hd)
        return he + 1; //conferir
    else
        return hd + 1;
}

//retorna o nivel de um no na arvore
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
            t1 = nivelDoNo(a->esq, elem, cont+1);
            t2 = nivelDoNo(a->dir, elem, cont+1);
            if (t1 == 0 || t2 == 0)
            {
                return t1 + t2;
            }
            else
            {
                if(t1 == 0)
                {
                    return t2;
                }
                else
                {
                    return t1;
                }
            }
        }
    }

    return cont;
}

//Verificando se a arvore eh completa
int contaFolha (arvore *a)
{
    if (a == NULL)
        return 0;

    if (a->esq == NULL && a->dir == NULL)
        return 1;

    else
        return contaFolha(a->esq) + contaFolha(a->dir);
}

int verificaCheia(arvore *a)
{
    int folha = contaFolha(a);
    int h = altura(a);

    if (folha == pow(2, (h-1)))
        return 1;
    else
        return 0;
}

//Verificando se a arvore eh cheia
int contaPenultimoNivel(arvore *a)
{
    int static cont = 0;

    if (cont < altura(a) - 1)
    {
        cont++;

        if (a == NULL)
            return 0;

        if (a->esq == NULL && a->dir == NULL)
            return 1;

        else
            return contaPenultimoNivel(a->esq) + contaPenultimoNivel(a->dir);
    }
}

int verificaCompleta (arvore *a)
{
    int h = altura(a);
    int n = contaPenultimoNivel(a);

    if (n == pow(2, h-1))
        return 1;
    else
        return 0;
}

//liberar a arvore
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

int menuImprimir()
{
    int resp;

    printf("\t1 - Arvore em pre ordem\n");
    printf("\t2 - Arvore em ordem\n");
    printf("\t3 - Arvore em pos ordem\n");
    printf("\t4 - Arvore em Largura\n");
    printf("\t5 - Arvore em notacao de parenteses\n");
    printf("\t6 - Folhas da arvore\n");
    scanf("%d", &resp);

    return resp;
}

int menu()
{
    int resp;

    printf("\n\nSelecione a opcao desejada:\n\n");
    printf("1 - Imprimir:\n");
    printf("2 - Verificar se um elemento existe na arvore\n");
    printf("3 - Calcular a altura da arvore\n");
    printf("4 - Contar o numero de ocorrencias de um no na arvore\n");
    printf("5 - Contar o numero de nos internos da arvore\n");
    printf("6 - Verificar o nivel de um no na arvore\n");
    printf("7 - Verificar se a arvore eh cheia\n");
    printf("8 - Verificar se a arvore eh completa\n");
    printf("9 - Sair\n");
    scanf("%d", &resp);

    return resp;
}

void imprimeSwitch(arvore *a, int opcao)
{
    printf("\n\n");
    switch (opcao){
        case 1:
        imprimirPreOrdem(a);
        break;

        case 2:
        imprimirEmOrdem(a);
        break;

        case 3:
        imprimirPosOrdem(a);
        break;

        case 4:
        imprimirEmLargura(a, altura(a));
        break;

        case 5:
        imprimir(a);
        break;

        case 6:
        imprimirFolha(a);
        break;
    }
}

void menu2 (arvore *a)
{
    printf("\n\n==============================\n");

    int elem;
    int resp = menu();
    int imprime;

    printf("\n\n");

    switch (resp)
    {
        case 1:
        imprime = menuImprimir();
        imprimeSwitch(a, imprime);
        break;

        case 2:
        printf("Digite um elemento para ser procurado: ");
        scanf("%d", &elem);
        if (existe(a, elem))
            printf("O elemento %d foi encontrado!\n", elem);
        else
            printf("Elemento nao encontrado!\n");
        break;

        case 3:
        printf("A altura da arvore eh: %d\n", altura(a));
        break;

        case 4:
        printf("Digite um elemento: ");
        scanf("%d", &elem);
        printf("O elemento %d ocorre %d vezes na arvore\n", elem, contarElemento(a, elem));
        break;

        case 5:
        printf("A arvore possui %d nos internos\n", contarNoInterno(a));
        break;

        case 6:
        printf("Digite um elemento: ");
        scanf("%d", &elem);
        printf("O nivel do elemento selecionado eh: %d\n", nivelDoNo(a, elem, 1));
        break;

        case 7:
        if (verificaCheia(a))
            printf("A arvore eh cheia\n");
        else
            printf("A arvore nao eh cheia\n");
        break;

        case 8:
        if (verificaCompleta(a))
            printf("A arvore eh completa\n");
        else
            printf("A arvore nao eh completa\n");
        break;

        case 9:
        liberar(a);
        return;
    }

    menu2(a);
}

int main(void)
{
    FILE *arq;
    char entrada[21];

    printf("SEJA BEM VINDO!\n\n");
    printf("Digite o nome do arquivo: ");
    scanf("%s", entrada);

    if (!(arq = fopen(entrada, "r")))
    {
        printf("Nao foi possivel abrir o arquivo arvore.txt");
        return -1;
    }

    arvore *arvore;

    arvore = criar(arvore, arq);

    fclose(arq);

    menu2(arvore);

    return 0;
}
