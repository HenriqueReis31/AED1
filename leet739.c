#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* prox;
} No;

typedef struct {
    No* topo;
} Pilha;

void Reset(Pilha* p) {
    p->topo = NULL;
}

int Vazia(Pilha* p) {
    return p->topo == NULL;
}

void Push(Pilha* p, int x) {
    No* novo = malloc(sizeof(No));
    novo->dado = x;
    novo->prox = p->topo;
    p->topo = novo;
}

int Pop(Pilha* p) {
    if (Vazia(p)) return -1;
    No* tmp = p->topo;
    int v = tmp->dado;
    p->topo = tmp->prox;
    free(tmp);
    return v;
}

int Peek(Pilha* p) {
    if (Vazia(p)) return -1;
    return p->topo->dado;
}

int* dailyTemperatures(int* T, int n, int* returnSize) {
    *returnSize = n;
    int* resp = calloc(n, sizeof(int));

    Pilha p;
    Reset(&p); // guardará índices

    for (int i = 0; i < n; i++) {

        while (!Vazia(&p) && T[i] > T[Peek(&p)]) {
            int idx = Pop(&p);
            resp[idx] = i - idx;
        }

        Push(&p, i);
    }

    return resp;
}
int main() {
    int T[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int n = sizeof(T)/sizeof(T[0]);
    int returnSize;

    int* resp = dailyTemperatures(T, n, &returnSize);

    printf("Daily Temperatures:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", resp[i]);
    }
    printf("\n");

    free(resp);
    return 0;
}