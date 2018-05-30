/**
 * Estruturas de Dados
 *
 * Tipo Abstrato de Dados (Pilha)
 *
 * Edson Onildo
 * Isabela Carvalho
 *
 * main.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

int contarElementosPares(Pilha p)
{
    int elem, cont = 0;

    Pilha tmp = inicializarPilha();

    while (!vaziaPilha(p))
    {
        elem = removerPilha(p);

        if (elem % 2 == 0)
            cont++;
        
        inserirPilha(tmp, elem);
    }

    while (!vaziaPilha(tmp))
        inserirPilha(p, removerPilha(tmp));

    tmp = destruirPilha(tmp);

    return cont;
}

int main()
{
    Pilha p = inicializarPilha();

    int opt, val;

    do
    {
        printf("1. INSERIR NA PILHA\n");
        printf("2. REMOVER DA PILHA\n");
        printf("3. CONTAR ELEMENTOS PARES\n");
        printf("4. SAIR\n");

        printf("INFORME A OPCAO DESEJADA: ");
        scanf("%d", &opt);

        printf("\n");

        switch (opt)
        {
            case 1:
                if (!cheiaPilha(p))
                {
                    printf("INFORME O VALOR A SER INSERIDO NA PILHA: ");
                    scanf("%d", &val);
                    inserirPilha(p, val);
                }
                else
                {
                    printf("A PILHA ESTA CHEIA");
                }
                break;

            case 2:
                if (!vaziaPilha(p))
                    printf("O ELEMENTO '%d' FOI REMOVIDO DA PILHA", removerPilha(p));
                break;

            case 3:
                printf("A PILHA CONTEM '%d' ELEMENTOS PARES\n", contarElementosPares(p));
                break;

            default:
                p = destruirPilha(p);
                return EXIT_SUCCESS;
        }

        printf("\n\nPILHA:\n======\n");
        !vaziaPilha(p) ? imprimirPilha(p) : printf("A PILHA ESTA VAZIA!");

        printf("\n\n");
    }
    while (1);
}