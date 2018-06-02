#ifndef GRAFOBACKTRACKING_BACKTRACK_H
#define GRAFOBACKTRACKING_BACKTRACK_H

typedef struct backtrack *BT;

BT BTInit(Grafo grafo);

void BTSetOrig(BT *bt, int orig);
void BTSetDest(BT *bt, int dest);

void BTSetVet(BT *backtrack, int pos, int val);
void BTImprimir(BT bt, _Bool (*cond)(BT), _Bool (*rec)(BT));

_Bool BTExistirVet(BT b, int elem);

int BTGetPos(BT b);
int BTGetOrigem(BT backtrack);
int BTGetDestino(BT backtrack);
int *BTGetVet(BT backtrack);
int BTTamVet(BT bt);

float BTGetCusto(BT bt);

Grafo BTGetGrafo(BT b);

#endif //GRAFOBACKTRACKING_BACKTRACK_H
