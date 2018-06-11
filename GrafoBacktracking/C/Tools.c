#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Tools.h"

#define ERR_MALLOC (-1)

bool isNull(void *ptr)
{
    return ptr == NULL;
}

void checkMalloc(void *ptr)
{
    if (isNull(ptr))
    {
        fprintf(stderr, "Falha ao tentar alocar memoria dinamicamente.");
        exit(ERR_MALLOC);
    }
}
