/*Faca uma funcao para verificar se um numero é um quadrado perfeito. Um quadrado 
perfeito e um numero inteiro nao negativo que pode ser expresso como o quadrado de outro numero inteiro.*/
#include <stdio.h>
#include <math.h>


int VerificaQuadradoPerfeito (int numero);
int main (){
    int num;
    printf("digite um numero (positivo)\n");
    scanf("%d", &num);
    int resultado = VerificaQuadradoPerfeito(num);

    if (resultado == 1) {
        printf("%d eh quadrado perfeito!\n", num);
    } else if (resultado == 0) {
        printf("%d nao eh um quadrado perfeito\n", num);
    } else { 
        
    }
    return 0;

}
int VerificaQuadradoPerfeito (int numero){
    int raiz;
     if (numero < 0){
        printf("numero negativos sao invalidos \n");
       return -1;
     } 
    
        raiz = (int)sqrt(numero);  // (int) muda o tipo double do sqrt para o tipo int;
        return (raiz * raiz == numero);
}