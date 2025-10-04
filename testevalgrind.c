#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = malloc(sizeof(int));  // aloca memória
    *ptr = 42;
    printf("Valor: %d\n", *ptr);

    // esqueci de dar free(ptr);  <-- vazamento de memória
    return 0;
}
