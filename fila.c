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
    No* fim;
} Fila;

void Reset(Fila* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

int Vazia(Fila* f) {
    return f->inicio == NULL;
}

int Enfileirar(Fila* f, Pessoa* pes) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar nó.\n");
        exit(1);
    }

    Pessoa* copia = (Pessoa*)malloc(sizeof(Pessoa));
    if (copia == NULL) {
        printf("Erro ao alocar pessoa.\n");
        exit(1);
    }

    strcpy(copia->nome, pes->nome);
    copia->idade = pes->idade;

    novo->dados = copia;
    novo->prox  = NULL;

    if (Vazia(f))
        f->inicio = novo;
    else
        f->fim->prox = novo;

    f->fim = novo;
    return 1;
}

Pessoa Desenfileirar(Fila* f) {
    Pessoa erro = {"ERRO", -1};

    if (Vazia(f)) {
        printf("Fila vazia!\n");
        return erro;
    }

    No* oldHead = f->inicio;
    Pessoa retorno = *oldHead->dados;

    f->inicio = oldHead->prox;
    if (f->inicio == NULL)
        f->fim = NULL;

    free(oldHead->dados);
    free(oldHead);

    return retorno;
}

Pessoa* Espiar(Fila* f) {
    if (Vazia(f)) {
        printf("Fila vazia!\n");
        return NULL;
    }
    return f->inicio->dados;
}

void Limpar(Fila* f) {
    No* atual = f->inicio;
    while (atual != NULL) {
        No* prox = atual->prox;
        free(atual->dados);
        free(atual);
        atual = prox;
    }
}

int main() {
    Fila fila;
    Reset(&fila);

    Pessoa a = {"Paulo", 25};
    Pessoa b = {"Henrique", 22};

    Enfileirar(&fila, &a);
    Enfileirar(&fila, &b);

    Pessoa x = Desenfileirar(&fila);
    printf("Saiu: %s\n", x.nome);

    Pessoa* y = Espiar(&fila);
    printf("Primeiro agora: %s\n", y->nome);

    Limpar(&fila);
    return 0;
}
