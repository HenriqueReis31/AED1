/*Crie uma funcao que recebe como parametro um numero inteiro e devolve  o seu dobro. */
#include <stdio.h>
int Num ( void );
int Calculo ( int numero );
int main (){
    int var;
     var =  Num (  );
     Calculo ( var );
    int dobro = Calculo( var );
    printf("o numero eh %d ", var);
    printf ("o dobro de %d eh: %d", var, dobro);
    return 0;
}
int Num ( void ){
    int numero;
        printf("digite um numero: ");
         scanf("%d", &numero);
    return numero;
}
int Calculo( int numero ){
    int calcular;
    
     calcular = numero * 2;

     return calcular;
}  
