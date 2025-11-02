#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool lemonadeChange(int* bills, int billsSize);

int main(){
    int Lemonade_Vector [5] = {5,5,5,10,20};
   int tam = 5;
   if (lemonadeChange(Lemonade_Vector, tam)){
    printf("TRUE");
} else{

    printf("FALSE");
}
    return 0;
}
bool lemonadeChange(int* bills, int billsSize){
    int *alc =(int *) malloc( sizeof(int) * billsSize);
      if (alc == NULL){
         printf("Erro na alocação de memoria!\n");
          return 0;
    }
    int FiveDollar = 0;
    int TenDollar = 0;
    int count = 0;
    for(int i =0; i < billsSize; i++){
        if (bills[i]== 5){
            FiveDollar++;
            count++;
        }
       else if(bills[i] == 10 && FiveDollar >=1){
            TenDollar++;
            FiveDollar--;
            count++;

        }
        else if (bills[i] == 20 &&(TenDollar >=1 && FiveDollar >=1)){
            TenDollar--;
            FiveDollar--;
            count++;
        }
        else if (bills[i] == 20 && FiveDollar>=3){
            FiveDollar = FiveDollar-3;
            count++;
        }
    }
    if (count == billsSize){
        return true;
    } else
    return false;

    free(alc);

}
