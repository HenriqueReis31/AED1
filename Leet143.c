#include <stdio.h>
#include <stdlib.h>

/*
====================
ListNode_t

  Estrutura básica para lista ligada
====================
*/
struct ListNode_t {
	struct ListNode_t *next;
	int  val;
};

typedef struct ListNode_t ListNode_t;

/*
====================
CreateNode

  Cria um novo nó com valor val
====================
*/
ListNode_t *CreateNode( int val ) {
	ListNode_t *node = (ListNode_t *)malloc( sizeof( ListNode_t ) );
	node->val = val;
	node->next = NULL;
	return node;
}

/*
====================
AppendNode

  Adiciona um nó ao final da lista
====================
*/
void AppendNode( ListNode_t **head, int val ) {
	if ( *head == NULL ) {
		*head = CreateNode( val );
		return;
	}

	ListNode_t *p = *head;
	while ( p->next != NULL ) {
		p = p->next;
	}

	p->next = CreateNode( val );
}

/*
====================
PrintList

  Imprime a lista
====================
*/
void PrintList( ListNode_t *head ) {
	ListNode_t *p = head;

	while ( p != NULL ) {
		printf( "%d ", p->val );
		p = p->next;
	}
	printf( "\n" );
}

/*
====================
ReorderList

  Implementação do LeetCode 143
  Reordena a lista no formato:
  L1 → Ln → L2 → Ln-1 ...
====================
*/
void ReorderList( ListNode_t *head ) {

	if ( head == NULL || head->next == NULL ) {
		return;
	}

	// encontra o meio da lista
	ListNode_t *p = head;
	ListNode_t *q = head;

	while ( q->next != NULL && q->next->next != NULL ) {
		p = p->next;
		q = q->next->next;
	}

	// inverte segunda metade
	ListNode_t *r = NULL;
	ListNode_t *current = p->next;
	p->next = NULL;

	while ( current != NULL ) {
		ListNode_t *temp = current->next;
		current->next = r;
		r = current;
		current = temp;
	}

	// intercala as duas listas
	ListNode_t *Pri = head;
	ListNode_t *Seg = r;

	while ( Seg != NULL ) {
		ListNode_t *temp1 = Pri->next;
		ListNode_t *temp2 = Seg->next;

		Pri->next = Seg;
		Seg->next = temp1;

		Pri = temp1;
		Seg = temp2;
	}
}

/*
====================
main

  Testa ReorderList com exemplo típico do LeetCode 143
====================
*/
int main( void ) {

	ListNode_t *head = NULL;

	// exemplo: [1,2,3,4,5]
	AppendNode( &head, 1 );
	AppendNode( &head, 2 );
	AppendNode( &head, 3 );
	AppendNode( &head, 4 );
	

	printf( "Lista original:\n" );
	PrintList( head );

	ReorderList( head );

	printf( "Lista reorganizada:\n" );
	PrintList( head );

	return 0;
}
