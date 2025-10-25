#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// ---------- ESTRUTURAS ----------
typedef struct {
    char nome[30];
    int idade;
} Pessoa;

typedef struct {
    Pessoa *dados;  // vetor dinâmico
    int topo;       // quantidade de elementos
} Pilha;

// ---------- FUNÇÕES DO TAD ----------

// Inicializa a pilha
void RESET(Pilha *p) {
    p->dados = NULL;
    p->topo = 0;
}

// Verifica se está vazia
bool EMPTY(Pilha *p) {
    return p->topo == 0;
}

// Insere nova pessoa no topo
bool PUSH(Pilha *p, Pessoa nova) {
    Pessoa *temp = realloc(p->dados, (p->topo + 1) * sizeof(Pessoa));
    if (temp == NULL) {
        printf("Erro ao alocar memória!\n");
        return false;
    }
    p->dados = temp;
    p->dados[p->topo] = nova;
    p->topo++;
    return true;
}

// Remove pessoa do topo
bool POP(Pilha *p, Pessoa *removida) {
    if (EMPTY(p)) {
        printf("Pilha vazia!\n");
        return false;
    }

    *removida = p->dados[p->topo - 1];
    p->topo--;

    if (p->topo == 0) {
        free(p->dados);
        p->dados = NULL;
    } else {
        Pessoa *temp = realloc(p->dados, p->topo * sizeof(Pessoa));
        if (temp)
            p->dados = temp;
    }
    return true;
}

// Limpa completamente a pilha
void CLEAR(Pilha *p) {
    free(p->dados);
    p->dados = NULL;
    p->topo = 0;
}

// ---------- FUNÇÃO EXTRA: LISTAR ----------
void LISTAR(Pilha *p) {
    printf("\n--- PILHA DE PESSOAS ---\n");
    if (EMPTY(p)) {
        printf("(vazia)\n");
    } else {
        for (int i = p->topo - 1; i >= 0; i--) {
            printf("%d - %s (%d anos)\n", i + 1, p->dados[i].nome, p->dados[i].idade);
        }
    }
    printf("------------------------\n");
}

// ---------- PROGRAMA PRINCIPAL ----------
int main() {
    Pilha pilha;
    Pessoa pessoa, removida;
    int opcao;
    RESET(&pilha);

    do {
        printf("\n===== MENU =====\n");
        printf("0 - Sair\n");
        printf("1 - Inserir pessoa\n");
        printf("2 - Remover pessoa do topo\n");
        printf("3 - Limpar pilha\n");
        printf("4 - Listar pilha\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); // limpar o '\n' do buffer

        switch (opcao) {
        case 1:
            printf("Nome: ");
            fgets(pessoa.nome, sizeof(pessoa.nome), stdin);
            pessoa.nome[strcspn(pessoa.nome, "\n")] = '\0'; // remove \n
            printf("Idade: ");
            scanf("%d", &pessoa.idade);
            getchar();
            PUSH(&pilha, pessoa);
            break;

        case 2:
            if (POP(&pilha, &removida))
                printf("Removido: %s (%d anos)\n", removida.nome, removida.idade);
            break;

        case 3:
            CLEAR(&pilha);
            printf("Pilha limpa!\n");
            break;

        case 4:
            LISTAR(&pilha);
            break;

        case 0:
            CLEAR(&pilha);
            printf("Encerrando...\n");
            break;

        default:
            printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
