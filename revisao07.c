/*Faca um programa que leia do usuario o tamanho de um vetor a ser lido e faca a alocacao
dinamica de memoria. Em seguida, leia do usuario seus valores e mostre quantos dos 
numeros sao pares e quantos sao ımpares. */
#include <stdio.h>
#include <stdlib.h>
void array ();

int main (){
    array();
}
void array(){
   int TamArray;
   int pares = 0, impares = 0;
  

    printf("digite o tamanho do vetor: ");
    scanf("%d", &TamArray);

    int *numeros = malloc(TamArray * sizeof(int));

    if (numeros == NULL) {
        printf("Erro na alocação de memoria!\n");
        return;
    }
    printf("digite os  numeros:\n");
    for (int i = 0; i < TamArray; i++){
        printf ("numero %d: ", i+1);
        scanf ("%d", &numeros[i]);

    }
     printf("\nOs numeros digitados foram:\n");
    for (int i = 0; i < TamArray; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    for (int i = 0; i < TamArray; i++) {
        if (numeros[i] % 2 == 0) {
            pares++;
        } else {
            impares++;
        }
    }
    printf("\nRESULTADO:\n");
    printf("Quantidade de pares: %d\n", pares);
    printf("Quantidade de impares: %d\n", impares);

   
    printf("\nPares: ");
    for (int i = 0; i < TamArray; i++) {
        if (numeros[i] % 2 == 0) {
            printf("%d ", numeros[i]);
        }
    }
    
    printf("\nImpares: ");
    for (int i = 0; i < TamArray; i++) {
        if (numeros[i] % 2 != 0) {
            printf("%d ", numeros[i]);
        }
    }
    printf("\n");

    free(numeros);
}
