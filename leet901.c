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
    Pilha preco;
    Pilha span;
} StockSpanner;

StockSpanner* stockSpannerCreate() {
    StockSpanner* s = malloc(sizeof(StockSpanner));
    Reset(&s->preco);
    Reset(&s->span);
    return s;
}

int stockSpannerNext(StockSpanner* obj, int price) {
    int sp = 1;

    while (!Vazia(&obj->preco) && Peek(&obj->preco) <= price) {
        Pop(&obj->preco);
        sp += Pop(&obj->span);
    }

    Push(&obj->preco, price);
    Push(&obj->span, sp);

    return sp;
}

void stockSpannerFree(StockSpanner* obj) {
    free(obj);
}
int main() {
    StockSpanner* ss = stockSpannerCreate();

    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices)/sizeof(prices[0]);

    printf("Stock Spanner:\n");
    for (int i = 0; i < n; i++) {
        int span = stockSpannerNext(ss, prices[i]);
        printf("Price %d -> Span %d\n", prices[i], span);
    }

    stockSpannerFree(ss);
    return 0;
}
