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


int* nextGreaterElements(int* nums, int n, int* returnSize) {
    *returnSize = n;
    int* ans = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        ans[i] = -1;

    Pilha p;
    Reset(&p);

    // percorre 2x (circular)
    for (int i = 0; i < 2*n; i++) {
        int j = i % n;

        while (!Vazia(&p) && nums[j] > nums[Peek(&p)]) {
            int idx = Pop(&p);
            ans[idx] = nums[j];
        }

        if (i < n) Push(&p, j);
    }

    return ans;
}
int main() {
    int nums[] = {1, 2, 1};
    int n = sizeof(nums)/sizeof(nums[0]);
    int returnSize;

    int* resp = nextGreaterElements(nums, n, &returnSize);

    printf("Next Greater Element II:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", resp[i]);
    }
    printf("\n");

    free(resp);
    return 0;
}
