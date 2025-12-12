#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

Stack* stackCreate(int capacity) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->data = (int*)malloc(sizeof(int) * capacity);
    s->top = -1;
    s->capacity = capacity;
    return s;
}

bool stackIsEmpty(Stack* s) {
    return s->top == -1;
}

void stackPush(Stack* s, int val) {
    s->data[++s->top] = val;
}

int stackPop(Stack* s) {
    return s->data[s->top--];
}

int stackPeek(Stack* s) {
    return s->data[s->top];
}


// ===== QUEUE USANDO DUAS PILHAS =====

typedef struct {
    Stack* entrada;
    Stack* saida;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    q->entrada = stackCreate(100000);
    q->saida = stackCreate(100000);
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    stackPush(obj->entrada, x);
}

int myQueuePop(MyQueue* obj) {
    if (stackIsEmpty(obj->saida)) {
        while (!stackIsEmpty(obj->entrada)) {
            stackPush(obj->saida, stackPop(obj->entrada));
        }
    }
    return stackPop(obj->saida);
}

int myQueuePeek(MyQueue* obj) {
    if (stackIsEmpty(obj->saida)) {
        while (!stackIsEmpty(obj->entrada)) {
            stackPush(obj->saida, stackPop(obj->entrada));
        }
    }
    return stackPeek(obj->saida);
}

bool myQueueEmpty(MyQueue* obj) {
    return stackIsEmpty(obj->entrada) && stackIsEmpty(obj->saida);
}

void myQueueFree(MyQueue* obj) {
    free(obj->entrada->data);
    free(obj->saida->data);
    free(obj->entrada);
    free(obj->saida);
    free(obj);
}

