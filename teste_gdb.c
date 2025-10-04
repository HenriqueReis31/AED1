//teste GDB;
#include <stdio.h>
#include <stdlib.h>

int calcular_fatorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * calcular_fatorial(n - 1);
}

int main() {
    int numero = 5;
    int resultado;
    int* ponteiro = NULL;
    
    printf("=== Testando GDB ===\n");
    
    resultado = calcular_fatorial(numero);
    printf("Fatorial de %d é: %d\n", numero, resultado);
    
  
    for(int i = 0; i < 3; i++) {
        printf("Iteracao %d\n", i);
        int temp = i * 10;
        printf("Valor temporario: %d\n", temp);
    }
    
   
    
    printf("Programa finalizado com sucesso!\n");
    return 0;
}