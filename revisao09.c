/*Faça um programa que:
1. Leia um número inteiro N
2. Aloque dinamicamente um vetor de N inteiros e leia seus valores
3. Leia um número inteiro X
4. Conte e exiba quantos e quais elementos do vetor são múltiplos de X*/
#include <stdio.h>
#include <stdlib.h>
void array();

int main (){
    array();
    return 0;
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
     int x;
    
      printf("\ndigite um numero qualquer: \n");
      scanf("%d", &x);

    int contador =0;
        printf("Multiplos de %d no vetor: \n", x);
    
    for(int i = 0; i < TamArray; i++ ){
        if(numeros [i] %  x == 0){
         printf("%d ", numeros[i]);

        
            contador++;
        }
    }
    
    printf("\nTotal de multiplos de %d: %d\n", x, contador);
    
  
    free(numeros);
}