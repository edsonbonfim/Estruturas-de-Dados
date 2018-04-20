Árvore Binária Geral
====================

* Árvore binária que simula qualquer outra árvore
* Duas direções: filho e irmão

Estrutura:
```c
typedef struct arvoreGeral
{
    int info;
    struct arvoreGeral *filho;
    struct arvoreGeral *irmao;
} arvoreGeral;
```

Trabalho
--------

Quinto trabalho para a disciplina de Estruturas de Dados:

* Ler uma árvore de um arquivo
* Imprimir
    * Notação de parênteses
    * Largura
* Altura da árvore
* Número de folhas
* Imprimir os nós internos
* Imprimir o nível de um nó
* Inserir um nó **x** como filho de um nó **y**
(verificar se o nó y existe, se existir, inserir o nó x)
(se o nó y ja tiver filho, incluir o nó x como irmão)