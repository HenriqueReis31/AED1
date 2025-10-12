#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize);

int main (){
    char *strs[] = {"flower","flow","flight"};

    char *result = longestCommonPrefix(strs,3);
    printf("%s",result);
    free(result);
}
char* longestCommonPrefix(char** strs, int strsSize) {
    char *c = (char *) malloc( sizeof(char));
    if (c == NULL){
         printf("Erro na alocação de memoria!\n");
        return 0;
    }
    int n=0;
    int var = 0;
   while (1){
        if(strs[0][n] == '\0'){
            break;
        }
        char temp = strs[0][n];
        for (int i = 0; i < strsSize; i++){
            if(strs[i][n] != temp){
                var = 1;
                break;
            }
        }
        
        if (var == 0){
            c[n]=temp;
          c =  (char *) realloc (c,(n+2)*sizeof(char));
          n++;
        }else
            break;
    }
    c[n] ='\0';
    return c;
    
}


