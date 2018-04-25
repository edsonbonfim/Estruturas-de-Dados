Tipo Abstrato de Dados (TAD)
============================

O conteudo de um tipo abstrato de dados deve ser transparente ao usuario.

Exemplo:

```c
typedef struct aluno
{
    int mat;
    char nome[256];
    float cr;
} Aluno;
```

Alteracoes do TAD nao devem impedir o funcionamento dos programas que usam este TAD.

A manipulacao do TAD flui por **funcoes**.

Exemplo de tipo abstrato de dados
---------------------------------

### Fila

O primeiro a ser inserido eh o primeiro a ser removido

Implementacoes: Vetor ou lista

```c
// fila.h

typedef struct fila *Fila;

Fila inicializar(void);
Fila destruir(Fila f);
int vazia(Fila f);
int cheia(Fila f);
void inserir(Fila f, int x);
int remover(Fila f);
void imprimir(Fila f);
```

```c
// fila.c

#include "stdio.h"
#include "stdlib.h"
#include "fila.h"

#define N 100

struct fila
{
    int vet[N];
    int topo;
};

Fila inicializar(void)
{
    Fila *f = (Fila) malloc(sizeof(struct fila));
    f->topo = 0;
    return f;
}

Fila destruir(Fila f)
{
    free(f);
}

int vazia(Fila f)
{
    return f->topo == 0;
}

int cheia(Fila f)
{
    return f->topo >= 100;
}

void inserir(Fila f, int x)
{
    f->vet[f->topo] = x;
    f->topo++;
}

int remover(Fila f)
{
    int ret = f->vet[0];
    
    for (int i = 1; i < f->topo; i++)
        f->vet[i-1] = f->vet[i];
        
    f->topo--;
    
    return ret;
}

void imprimir(Fila f)
{
    for (int i = 0; i < f->topo; i++)
        printf("%d ", f->vet[i]);
}
```

```c
// main.c

#include "stdio.h"
#include "stdlib.h"
#include "fila.h"

int main(void)
{
    Fila f = inicializar();
    int x;
    
    inserir(f, 10);
    inserir(f, 20);
    
    x = remover(f);
    printf("%d ", x);
    
    f = destruir(f);
    
    return EXIT_SUCCESS;
}
```

Atividade
---------

Implementar o exemplo de fila usando lista encadeada, a main.c e o fila.h nao devem ser alterados e o programa final deve mostrar o mesmo resultado.
