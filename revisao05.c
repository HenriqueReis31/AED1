/*Crie um programa que:
(a) Aloque dinamicamente um array de 5 numeros inteiros, 
(b) Peca para o usuario digitar os 5 numeros no espaço alocado, 
(c) Mostre na tela os 5 numeros, 
(d) Libere a memoria alocada*/
#include <stdio.h>
#include <stdlib.h>

void array();
int main (){

     array ();
    return 0;
}
void array(){
    int *numeros = malloc(5 * sizeof(int));
     if (numeros == NULL) {
        printf("Erro na alocação de memoria!\n");
        return;
    }
    printf("digite os 5 numeros:\n");
    for (int i = 0; i < 5; i++){
        printf ("numero %d: ", i+1);
        scanf ("%d", &numeros[i]);

    }
     printf("\nOs numeros digitados foram:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
    
    
    free(numeros);
}
