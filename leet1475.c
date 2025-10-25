#include <stdio.h>
#include <stdlib.h>

int* finalPrices(int* prices, int pricesSize, int* returnSize);

int main (){
   int returnSize, pricesSize=5;
    
    
    int prices [] = {8,4,6,2,3};

    int *result = finalPrices(prices, 5, &returnSize);
    for(int i=0; i<pricesSize; i++){
     printf("%d ", result[i]);
    }
    free(result);
}



int* finalPrices(int* prices, int pricesSize, int* returnSize) {
    int *num =(int *) malloc( sizeof(int) * pricesSize);
     if (num == NULL){
         printf("Erro na alocação de memoria!\n");
        return 0;
}
    *returnSize = pricesSize;

    for(int i = 0; i<pricesSize; i++){  
        num[i]=prices[i];
        for(int j = i+1; j<pricesSize; j++){

            if (prices[j] <= prices[i]){

                num[i] = prices[i]-prices[j];

                    break;    
                
        }
       
     }
}
return num;
}