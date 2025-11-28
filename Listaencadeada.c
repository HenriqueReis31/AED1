#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[30];
    int idade;
} Pessoa;

typedef struct No {
    Pessoa* dados;
    struct No* prox;
} No;

typedef struct {
    No* inicio;
} Lista;

void Reset(Lista* l) {
    l->inicio = NULL;
}

void InserirFim(Lista* l, Pessoa* pes) {
    No* novo = (No*)malloc(sizeof(No));
    Pessoa* copia = (Pessoa*)malloc(sizeof(Pessoa));

    strcpy(copia->nome, pes->nome);
    copia->idade = pes->idade;

    novo->dados = copia;
    novo->prox = NULL;

    if (l->inicio == NULL) {
        l->inicio = novo;
        return;
    }

    No* atual = l->inicio;
    while (atual->prox != NULL)
        atual = atual->prox;

    atual->prox = novo;
}

void Imprimir(Lista* l) {
    No* atual = l->inicio;
    printf("LISTA: ");
    while (atual != NULL) {
        printf("[%s (%d)] -> ", atual->dados->nome, atual->dados->idade);
        atual = atual->prox;
    }
    printf("NULL\n");
}

void Remover(Lista* l, char nome[]) {
    No *atual = l->inicio, *anterior = NULL;

    while (atual != NULL && strcmp(atual->dados->nome, nome) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Nome não encontrado!\n");
        return;
    }

    if (anterior == NULL)
        l->inicio = atual->prox;
    else
        anterior->prox = atual->prox;

    free(atual->dados);
    free(atual);
}

void Limpar(Lista* l) {
    No* atual = l->inicio;
    while (atual != NULL) {
        No* prox = atual->prox;
        free(atual->dados);
        free(atual);
        atual = prox;
    }
}

int main() {
    Lista l;
    Reset(&l);

    Pessoa a = {"Ana", 20};
    Pessoa b = {"Lucas", 30};

    InserirFim(&l, &a);
    InserirFim(&l, &b);

    Imprimir(&l);

    Remover(&l, "Ana");
    Imprimir(&l);

    Limpar(&l);
    return 0;
}
