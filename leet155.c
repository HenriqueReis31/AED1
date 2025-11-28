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
typedef struct {
    Pilha val;
    Pilha minimo;
} MinStack;

MinStack* minStackCreate() {
    MinStack* s = malloc(sizeof(MinStack));
    Reset(&s->val);
    Reset(&s->minimo);
    return s;
}

void minStackPush(MinStack* obj, int x) {
    Push(&obj->val, x);

    if (Vazia(&obj->minimo)) Push(&obj->minimo, x);
    else {
        int atualMin = Peek(&obj->minimo);
        Push(&obj->minimo, x < atualMin ? x : atualMin);
    }
}

void minStackPop(MinStack* obj) {
    Pop(&obj->val);
    Pop(&obj->minimo);
}

int minStackTop(MinStack* obj) {
    return Peek(&obj->val);
}

int minStackGetMin(MinStack* obj) {
    return Peek(&obj->minimo);
}

void minStackFree(MinStack* obj) {
    free(obj);
}


int main() {
    MinStack* ms = minStackCreate();

    minStackPush(ms, -2);
    minStackPush(ms, 0);
    minStackPush(ms, -3);

    printf("Min: %d\n", minStackGetMin(ms)); // -3

    minStackPop(ms);

    printf("Top: %d\n", minStackTop(ms));    // 0
    printf("Min: %d\n", minStackGetMin(ms)); // -2

    minStackFree(ms);
    return 0;
}
