#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Pilha.h"

int main()
{
    Pilha p = inicializarPilha();

    int opt, val;

    while (true)
    {
        printf("1. INSERIR NA PILHA\n");
        printf("2. REMOVER DA PILHA\n");
        printf("3. SAIR\n");

        printf("INFORME A OPCAO DESEJADA: ");
        scanf("%d", &opt);

        printf("\n");

        switch (opt)
        {
            case 1:
                printf("INFORME O VALOR A SER INSERIDO NA PILHA: ");
                scanf("%d", &val);
                inserirPilha(p, val);
                break;

            case 2:
                if (!vaziaPilha(p))
                    printf("O ELEMENTO '%d' FOI REMOVIDO DA PILHA", removerPilha(p));
                else
                    printf("A PILHA ESTA VAZIA!");
                break;

            default:
                p = destruirPilha(p);
                return EXIT_SUCCESS;
        }

        printf("\nPILHA:\n======\n");
        !vaziaPilha(p) ? imprimirPilha(p) : printf("A PILHA ESTA VAZIA!");

        printf("\n\n");
    }
}