#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void **pbuffer;

/*
====================
DeathMalloc

  Desaloca toda memória de nome e email dos contatos cadastrados
====================
*/
void DeathMalloc( void ) {

	// Percorre todos os índices de pessoas cadastradas, incrementando pbuffer[4] a cada iteração
	for ( pbuffer[4] = (void*)0; (int)pbuffer[4] < (int)pbuffer[1]; pbuffer[4] = (void*)((int)pbuffer[4] + 1) ) {
		free( pbuffer[6 + (int)pbuffer[4] * 3] );		// nome
		free( pbuffer[6 + (int)pbuffer[4] * 3 + 2] );	// email
	}
}


/*
====================
Resize

  Realoca o tamanho do pbuffer para inserir mais contatos
====================
*/
void Resize( void ) {
	pbuffer[2] = (void*)((int)pbuffer[2] + 30);
	pbuffer = realloc( pbuffer, sizeof( void* ) * (int)pbuffer[2] );
}


/*
====================
Insert

  Insere uma nova pessoa na agenda usando o pbuffer como armazenamento
====================
*/
void Insert( void ) {

	if ( (int)pbuffer[3] + 3 >= (int)pbuffer[2] ) {
		Resize();	// se nao tiver espaco (espaco para 10 pessoas) então realoca;
	}

	pbuffer[4] = (void*)(int)pbuffer[3];	// Usa a posição temp diretamente

	// LEITURA DO NOME
	printf( "Nome: " );
	pbuffer[5] = malloc( sizeof( char ) * 1023 );
	scanf( "\n%[^\n]s", pbuffer[5] );

	pbuffer[(int)pbuffer[4]] = malloc( sizeof( char ) * ( 1 + strlen( pbuffer[5] ) ) );
	memcpy( pbuffer[(int)pbuffer[4]], pbuffer[5], ( 1 + strlen( pbuffer[5] ) ) );

	// LEITURA DA IDADE  
	printf( "idade: " );
	scanf( "%d", (int*)&pbuffer[(int)pbuffer[4] + 1] );

	// LEITURA DO EMAIL
	printf( "email: " );
	scanf( "%s", pbuffer[5] );

	pbuffer[(int)pbuffer[4] + 2] = malloc( sizeof( char ) * ( 1 + strlen( pbuffer[5] ) ) );
	memcpy( pbuffer[(int)pbuffer[4] + 2], pbuffer[5], ( 1 + strlen( pbuffer[5] ) ) );

	// ATUALIZA CONTADORES
	pbuffer[1] = (void*)((int)pbuffer[1] + 1);	// Incrementa número de pessoas
	pbuffer[3] = (void*)((int)pbuffer[3] + 3);	// Avança indices em 3 posições

	// LIMPEZA
	free( pbuffer[5] );
}


/*
====================
PrintAll

  Lista todas as pessoas cadastradas
====================
*/
void PrintAll( void ) {

	if ( (int)pbuffer[1] == 0 ) {
		printf( "A lista esta vazia\n" );
		return;
	}

	for ( pbuffer[4] = (void*)0; (int)pbuffer[4] < (int)pbuffer[1]; pbuffer[4] = (void*)((int)pbuffer[4] + 1) ) {
		printf( "Nome: %s\nIdade: %d\nEmail: %s\n\n",
			pbuffer[6 + (int)pbuffer[4] * 3 + 0],
			pbuffer[6 + (int)pbuffer[4] * 3 + 1],
			pbuffer[6 + (int)pbuffer[4] * 3 + 2] );
	}
}


/*
====================
SearchForName

  Busca um contato pelo nome informado
====================
*/
void SearchForName( void ) {

	if ( (int)pbuffer[1] == 0 ) {
		printf( "A lista está vazia\n" );
		return;
	}

	pbuffer[5] = malloc( sizeof( char ) * 1024 );

	printf( "Digite o nome da pessoa:\n" );
	scanf( "\n%[^\n]s", (char*)pbuffer[5] );

	for ( pbuffer[4] = 0; (int)pbuffer[4] < (int)pbuffer[1]; pbuffer[4] = (void*)((int)pbuffer[4] + 1) ) {
		if ( strcmp( (char*)pbuffer[6 + (int)pbuffer[4] * 3], (char*)pbuffer[5] ) == 0 ) {

			printf( "\n=== Pessoa encontrada! ===\n" );
			printf( "Nome:  %s\n",  (char*)pbuffer[6 + (int)pbuffer[4] * 3] );
			printf( "Idade: %d\n",  (int)pbuffer[6 + (int)pbuffer[4] * 3 + 1] );
			printf( "Email: %s\n", (char*)pbuffer[6 + (int)pbuffer[4] * 3 + 2] );

			free( pbuffer[5] );
			return;
		}
	}

	printf( "Pessoa não encontrada.\n" );
	free( pbuffer[5] );
}


/*
====================
Removee

  Remove uma pessoa da lista e reorganiza o vetor
====================
*/
void Removee( void ) {

	if ( (int)pbuffer[1] == 0 ) {
		printf( "A lista esta vazia\n" );
		return;
	}

	pbuffer[5] = malloc( sizeof( char ) * 1023 );

	printf( "Digite o nome para remover: " );
	scanf( "\n%[^\n]s", (char*)pbuffer[5] );

	pbuffer[4] = 0;

	while ( (int)pbuffer[4] < (int)pbuffer[1] &&
			strcmp( (char*)pbuffer[6 + (int)pbuffer[4] * 3], (char*)pbuffer[5] ) != 0 )	{

		pbuffer[4] = (void*)((int)pbuffer[4] + 1);
	}

	if ( (int)pbuffer[4] == (int)pbuffer[1] ) {
		printf( "Nome não encontrado.\n" );
		free( pbuffer[5] );		
		return;
	}

	// base = 6 + índice*3
	pbuffer[3] = (void*)( 6 + (int)pbuffer[4] * 3 );

	free( pbuffer[(int)pbuffer[3] + 0] );	// libera nome
	free( pbuffer[(int)pbuffer[3] + 2] );	// libera email

	pbuffer[4] = (void*)((int)pbuffer[4] + 1);

	while ( (int)pbuffer[4] < (int)pbuffer[1] ) {

		pbuffer[2] = (void*)( 6 + (int)pbuffer[4] * 3 );
		pbuffer[3] = (void*)((int)pbuffer[2] - 3);

		pbuffer[(int)pbuffer[3] + 0] = pbuffer[(int)pbuffer[2] + 0];
		pbuffer[(int)pbuffer[3] + 1] = pbuffer[(int)pbuffer[2] + 1];
		pbuffer[(int)pbuffer[3] + 2] = pbuffer[(int)pbuffer[2] + 2];

		pbuffer[4] = (void*)((int)pbuffer[4] + 1);
	}

	pbuffer[1] = (void*)((int)pbuffer[1] - 1 );
	pbuffer[3] = (void*)((int)pbuffer[3] - 3 );

	printf( "Removido com sucesso!\n" );

	free( pbuffer[5] );
}


/* variaveis de controle
     [0] opcao
     [1] quantidade de contatos
     [2] tamanho alocado
     [3] próximo índice livre
     [4] temp i/j
     [5] auxiliar
*/

/*
====================
Main
====================
*/
int main( void ) {

	pbuffer = (void**)malloc( sizeof( void* ) * 36 );

	// as 6 primeiras pocições são alocadas para variaveis, o resto é a agenda
	pbuffer[0] = (void*)0;	// opcao (inicial)
	pbuffer[1] = (void*)0;	// qtd de contatos
	pbuffer[2] = (void*)36;	// tamanho alocado (nº de ponteiros)
	pbuffer[3] = (void*)6;	// prox indice livre
	pbuffer[4] = (void*)0;	// temp i/j
	pbuffer[5] = NULL;	// auxiliar

	do {
		printf( "\ndigite operacao\n 1. inserir pessoa\n 2. remover\n 3. buscar\n 4. listar \n 5. sair\n " );
		scanf( "%d", (int*)&pbuffer[0] );

		switch ( (int)pbuffer[0] ) {

			case 1:
				Insert();
				break;

			case 2:
				Removee();
				break;

			case 3:
				SearchForName();
				break;

			case 4:
				PrintAll();
				break;

			case 5:
				DeathMalloc();
				free( pbuffer );
				return 0;

			default:
				printf( "Digite um valor de entrada valido\n" );
				break;
		}

	} while ( 1 );
}
