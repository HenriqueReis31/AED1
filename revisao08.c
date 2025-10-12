/*Faca um programa que receba do usuario o tamanho de uma string e chame uma funcao para alocar dinamicamente essa string. 
Em seguida, o usuario devera informar o conteudo dessa string. O programa imprime a string sem suas vogais.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void AlocarDinamicamente();
int main (){
        AlocarDinamicamente();
        return 0;
} 
void AlocarDinamicamente(){
    int Tamanhostring;
    
    printf("Digite o tamanho que deseja para a string (incluindo o \\0): ");
    scanf("%d", &Tamanhostring);
    
    
    while (getchar() != '\n');
    
  
    char *Sstring = malloc(Tamanhostring * sizeof(char));
    if (Sstring == NULL) {
        printf("Erro na alocação de memoria!\n");
        return;
    } 
    printf("Digite o conteudo da string: ");
    
    
    fgets(Sstring, Tamanhostring, stdin);
    
    
    Sstring[strcspn(Sstring, "\n")] = '\0';
    
    printf("\nString original: %s\n", Sstring);
    
    
    printf("String sem vogais: ");
    for(int i = 0; Sstring[i] != '\0'; i++){
        char c = Sstring[i];
        if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
              c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')) {
            printf("%c", c);
        }
    }
    printf("\n");
    


    free (Sstring);
} 