void reorderList(struct ListNode* head){
    
 if (head == NULL || head->next == NULL){ 
  
        return;
    }
// tentar achar o "meio" da lista para comecar a  definir  as posições
    struct ListNode *p = head;
    struct ListNode *q = head;

while (q->next != NULL && q->next->next != NULL) {  // enquanto p nao termina p vai 1 e q vai 2;
        p = p->next;
        q = q->next->next;
    }
    struct ListNode *r = NULL;
    struct ListNode *current = p->next;  

    p->next = NULL; 

    while (current != NULL) {
        struct ListNode *temp = current->next; // guarda o prox
        current->next = r;                      
        r = current;                           
        current = temp; 
    }       
    struct ListNode *Pri = head; 
    struct ListNode *Seg = r;    

    while (Seg != NULL) {
        
        struct ListNode *temp1 = Pri->next;
        struct ListNode *temp2 = Seg->next;

       // faz as trocas de posicoes
        Pri->next = Seg;    
        Seg->next = temp1; 
       
        Pri = temp1;
        Seg = temp2; 

}
}
