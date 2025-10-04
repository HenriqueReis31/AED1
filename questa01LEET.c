#include <stdio.h>

int sum(int num1, int num2) {
    int result;
    result = num1 + num2;
    printf("num1 vale %d, num2 vale %d e a soma entre eles eh %d\n", num1, num2, result);
    return result;
}

int main() {
    // Testando a função com os exemplos fornecidos
    int resultado1 = sum(12, 5);
    int resultado2 = sum(-10, 4);
    
    printf("\nResultados dos testes:\n");
    printf("Teste 1: %d\n", resultado1);
    printf("Teste 2: %d\n", resultado2);
    
    return 0;
}