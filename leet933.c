#include <stdio.h>
#include <stdlib.h>



typedef struct No {
    int dado;
    struct No* prox;
} No;

typedef struct {
    No* inicio;
    No* fim;
} Fila;

void Reset(Fila* f){ f->inicio = f->fim = NULL; }

int Vazia(Fila* f){ return f->inicio == NULL; }

void Enfileirar(Fila* f, int v){
    No* novo = malloc(sizeof(No));
    novo->dado = v;
    novo->prox = NULL;

    if (Vazia(f)) f->inicio = novo;
    else f->fim->prox = novo;

    f->fim = novo;
}

int Desenfileirar(Fila* f){
    if (Vazia(f)) return -1;

    No* old = f->inicio;
    int v = old->dado;

    f->inicio = old->prox;
    if (!f->inicio) f->fim = NULL;

    free(old);
    return v;
}

void Limpar(Fila* f){
    No* a = f->inicio;
    while(a){
        No* p = a->prox;
        free(a);
        a = p;
    }
    f->inicio = f->fim = NULL;
}



typedef struct {
    Fila f;
} RecentCounter;

RecentCounter* recentCounterCreate(){
    RecentCounter* rc = malloc(sizeof(RecentCounter));
    Reset(&rc->f);
    return rc;
}

int recentCounterPing(RecentCounter* obj, int t){
    Enfileirar(&obj->f, t);

    // remover os timestamps antigos
    while (!Vazia(&obj->f) && obj->f.inicio->dado < t - 3000)
        Desenfileirar(&obj->f);

    // contar o tamanho da fila
    int cont = 0;
    for (No* n = obj->f.inicio; n; n = n->prox)
        cont++;

    return cont;
}

void recentCounterFree(RecentCounter* obj){
    Limpar(&obj->f);
    free(obj);
}



int main() {
    RecentCounter* rc = recentCounterCreate();

    printf("%d\n", recentCounterPing(rc, 1));    // 1
    printf("%d\n", recentCounterPing(rc, 100));  // 2
    printf("%d\n", recentCounterPing(rc, 3001)); // 3
    printf("%d\n", recentCounterPing(rc, 3002)); // 3

    recentCounterFree(rc);
    return 0;
}
