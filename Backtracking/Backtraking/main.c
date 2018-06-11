#include <stdio.h>
#include <stdio.h>

void combinacao(int *comb, int tam_comb, int n, int callback(const int *vet, int n))
{
    static int pos = 0;
    static int *vet[10];

    if (n == pos)
    {
        if (callback(comb, tam_comb))
        {
            for (int i = 0; i < n; i++)
                printf("%d ", vet[i]);
            printf("\n");
        }
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            vet[pos] = comb[i];
            pos++;
            combinacao(n, callback);
            pos--;
        }
    }
}

int somaMenor150(const int *vet, int n)
{
    int soma = 0;
    for (int i = 0; i < n; i++)
        soma += vet[i];

    return soma < 150;
}

int main()
{
    int comb[] = {7, 17, 55, 56, 61};

    combinacao(comb, 5, 3, somaMenor150);
}