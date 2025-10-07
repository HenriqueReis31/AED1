/*Faça um programa que leia do usuario o tamanho de um vetor a ser lido e faca a alocacao
dinamica de memoria. Em seguida, leia do usuario seus valores e imprima o vetor lido.*/
#include <stdio.h>
#include <stdlib.h>
void array ();

int main (){
    array();
}
void array(){
   int TamArray;
  

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
    
    
    free(numeros);
}
