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
    No* topo;
} Pilha;

void Reset(Pilha* p) {
    p->topo = NULL;
}

int Vazia(Pilha* p) {
    return p->topo == NULL;
}

int Push(Pilha* p, Pessoa* pes) {
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
    novo->prox = p->topo;

    p->topo = novo;
    return 1;
}

Pessoa Pop(Pilha* p) {
    Pessoa erro = {"ERRO", -1};

    if (Vazia(p)) {
        printf("Pilha vazia!\n");
        return erro;
    }

    No* oldTop = p->topo;
    Pessoa retorno = *oldTop->dados;

    p->topo = oldTop->prox;

    free(oldTop->dados);
    free(oldTop);

    return retorno;
}

Pessoa* Peek(Pilha* p) {
    if (Vazia(p)) {
        printf("Pilha vazia!\n");
        return NULL;
    }
    return p->topo->dados;
}

void Limpar(Pilha* p) {
    No* atual = p->topo;
    while (atual != NULL) {
        No* prox = atual->prox;
        free(atual->dados);
        free(atual);
        atual = prox;
    }
}

int main() {
    Pilha pilha;
    Reset(&pilha);

    Pessoa a = {"Carlos", 20};
    Pessoa b = {"Maria", 30};

    Push(&pilha, &a);
    Push(&pilha, &b);

    Pessoa retirado = Pop(&pilha);
    printf("POP: %s (%d)\n", retirado.nome, retirado.idade);

    Pessoa* topo = Peek(&pilha);
    printf("Topo atual: %s\n", topo->nome);

    Limpar(&pilha);
    return 0;
}
