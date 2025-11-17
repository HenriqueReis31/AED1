/* Dada a raiz de uma árvore binária, retorne o percurso
 em ordem dos valores de seus nós.

Input: root = [1,null,2,3]
Output: [1,3,2]
*/
#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int* inorderTraversal(struct TreeNode* root, int* returnSize);

int main(){
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
 *returnSize = 0; 

 if(root == NULL){
    return NULL;
 }


 int * result = malloc (100*sizeof(int));

 if (result == NULL){
    printf("erro de alocacao de memoria");
 }


}