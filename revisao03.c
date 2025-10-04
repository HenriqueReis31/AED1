/*Faca uma funcao para verificar se um numero é positivo ou negativo. Sendo que o valor 
de retorno sera 1 se positivo, -1 se negativo e 0 se for igual a 0.*/
#include <stdio.h>

int VerificaSinal(double numero);
int main (){
    double numero;
    printf("digite um numero qualquer:\n");
    scanf("%lf", &numero);
     int resultado = VerificaSinal(numero);
    
    if (resultado == 1) {
        printf("O numero %.2f eh positivo\n", numero);
    } else if (resultado == -1) {
        printf("O numero %.2f eh negativo\n", numero);
    } else {
        printf("O numero eh zero\n");
    }
    
    return 0;
}

int VerificaSinal(double numero) {
    if (numero > 0) {
        return 1;      
    } else if (numero < 0) {
        return -1;     
    } else {
        return 0;    
    }
}