//FEITO EM SALA

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n);

int main (){
    int flowerbed [5] = {1,0,0,0,1};
    int tam = 5;
    
   if (canPlaceFlowers(flowerbed, tam, 0))
    printf("TRUE");
   else
    printf("FALSE");
    return 0;
}

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int *alc =(int *) malloc( sizeof(int) * flowerbedSize);
      if (alc == NULL){
         printf("Erro na alocação de memoria!\n");
          return 0;
    }
    
   int count = 0;
   int naoplanta =0;

    for(int i = 0; i<flowerbedSize;i++){
       
    
        if(flowerbed[i] == 1 && flowerbed[i+1]==0){
            
            naoplanta++;
            n = naoplanta;
            
        }
       else if(flowerbed[i] == 0 && flowerbed[i+1]==0){
       
        count++;
         n = count;
        
       } 
       else if(flowerbed[i] == 0 && flowerbed[i+1]==1){
           
            naoplanta++;
            n = naoplanta;
    }
    }//for

  if( n = count){
    return true;
  }
  if(n = naoplanta){
    return false;
  }
   free(alc);
}
 
