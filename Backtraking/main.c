/*
 *
 * 1) Imprimir todas as combinações de 7, 17, 55 e 61 em que a soma seja inferior a 150. (perguntar tamanho N)
2) Todas as combinações de A, E, I, O, U de tamanho N (perguntar N) sem repetição
3) Conte o numero de combinações de 0s e 1s de tamanho N (perguntar) em que o numerode 1s seja pelo menos o dobro do numero de 0s
4) Suponha que vocês estão trabalhando com moedas de 1, 5, 10, 25 e 50 centavos. Recebendo um valor X como entrada, imprima na tela todas as combinações de moedas que totalizam o valor X.
 */
#include<stdio.h>
//IMPRIMIR todas as comb. de 3, 4 e 5 que tenham pelo menos um 5

int soma (int *vet, int n)
{
    int s=0;
    for (int i = 0; i < n; i++)
        s += vet[i];

    return s;
}

int repetidos (char *str)
{
    char letra;
    int cont = 0;

    for (int i=0; str[i]!='\0'; i++)
    {
        letra = str[i];

        for (int j=0; str[j]!='\0'; j++)
            if (letra == str[j])
                cont++;

        if (cont > 1)
            return 1;
    }

    return 0;
}

int repetidos2 (int *vet, int n, int num)
{
   int cont = 0;

    for (int j=0; j<n; j++)
            if (num == vet[j])
                cont++;

    return cont;
}

void combinacao01(int *vet, int pos, int n)
{
    int vetor[] = {7, 17, 55, 61};

    if(pos == n)
    {
        if (soma(vet, n) < 150)
            for (int i=0; i<n; i++)
                printf("%d ", vet[i]);
    }
    else
    {
        int i;
        for(i=0;i<4;i++)
        {
            vet[pos] = vetor[i];
            combinacao01(vet, pos+1, n);
        }
    }
}

void combinacaoVogais(int* vet, int pos, int n)
{
    int cont = 0;
    char vogais[] = {'a', 'e', 'i', 'o', 'u'};

    if (pos == n)
    {
        for (int i=0; i<n; i++)
        {
            if (repetidos2(vet, n, vet[i]))
            {
                cont++;
            }
        }

        printf("CONT = %d", cont);

        if (cont == 0)
        {
            for (int i = 0; i < n; i++)
                printf("%c", vet[i]);
            printf("\n");
        }
    }
    else
    {
        for(int i=0; i<5; i++)
        {
            vet[pos] = (int) vogais[i];
            combinacaoVogais(vet, pos+1, n);
        }
    }
}



int main()
{
    int v[3];
    int vet[5];

    //combinacao01(v, 0, 3);

    combinacaoVogais(vet, 0, 3);

    return 0;
}