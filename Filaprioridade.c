#include <stdio.h>
#include <stdlib.h>

/* ======================================
      ESTRUTURA DO DADO (Item Coringa)
   ====================================== */

typedef struct {
    int prioridade;   // Maior prioridade sai primeiro
    int valor;        // Pode trocar por outro dado se quiser
} Item;

/* ======================================
         NODO DA FILA DE PRIORIDADE
   ====================================== */

typedef struct No {
    Item dado;
    struct No* prox;
} No;

/* ======================================
             CABEÇA DA FILA
   ====================================== */

typedef struct {
    No* primeiro;
    No* ultimo;
} FilaP;

/* ======================================
               CRIAR FILA
   ====================================== */

FilaP* criarFilaP() {
    FilaP* f = (FilaP*) malloc(sizeof(FilaP));
    f->primeiro = NULL;
    f->ultimo = NULL;
    return f;
}

/* ======================================
        PUSH ORDENADO POR PRIORIDADE
   ====================================== */

void pushP(FilaP* f, Item elem) {
    No* novo = (No*) malloc(sizeof(No));
    novo->dado = elem;
    novo->prox = NULL;

    // Caso 1 – fila vazia
    if (!f->primeiro) {
        f->primeiro = f->ultimo = novo;
        return;
    }

    // Caso 2 – entra no começo (maior prioridade)
    if (elem.prioridade > f->primeiro->dado.prioridade) {
        novo->prox = f->primeiro;
        f->primeiro = novo;
        return;
    }

    // Caso 3 – entra no meio
    No* aux = f->primeiro;
    while (aux->prox && aux->prox->dado.prioridade >= elem.prioridade) {
        aux = aux->prox;
    }

    novo->prox = aux->prox;
    aux->prox = novo;

    // Caso 4 – entrou no fim
    if (novo->prox == NULL)
        f->ultimo = novo;
}

/* ======================================
                POP
   ====================================== */

int popP(FilaP* f, Item* saida) {
    if (!f->primeiro)
        return 0; // Fila vazia

    No* nodo = f->primeiro;
    *saida = nodo->dado;

    f->primeiro = nodo->prox;
    if (!f->primeiro)
        f->ultimo = NULL;

    free(nodo);
    return 1;
}

/* ======================================
                RESET
   ====================================== */

void resetFilaP(FilaP* f) {
    No* aux = f->primeiro;
    while (aux) {
        No* tmp = aux->prox;
        free(aux);
        aux = tmp;
    }
    f->primeiro = NULL;
    f->ultimo = NULL;
}

/* ======================================
             IMPRIMIR FILA
   ====================================== */

void imprimirFilaP(FilaP* f) {
    No* aux = f->primeiro;
    printf("FILA (maior prioridade primeiro):\n");
    while (aux) {
        printf("  [prio=%d val=%d]\n", aux->dado.prioridade, aux->dado.valor);
        aux = aux->prox;
    }
    printf("---- fim ----\n");
}

/* ======================================
             MAIN PARA TESTE
   ====================================== */

int main() {

    FilaP* fila = criarFilaP();

    Item a = {5, 10};
    Item b = {1, 20};
    Item c = {9, 30};
    Item d = {5, 40};

    pushP(fila, a);
    pushP(fila, b);
    pushP(fila, c);
    pushP(fila, d);

    imprimirFilaP(fila);

    Item x;
    popP(fila, &x);
    printf("POP -> prio=%d val=%d\n", x.prioridade, x.valor);

    imprimirFilaP(fila);

    resetFilaP(fila);

    free(fila);

    return 0;
}
