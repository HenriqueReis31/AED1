#include <stdio.h>
#include <stdbool.h>

/*
====================
CanPlaceFlowers

  Verifica se é possível plantar n flores sem violar a regra de
  não haver flores adjacentes.

  Só posso plantar se a posição atual está vazia (0), e
  os dois vizinhos (esquerda e direita) também estão vazios
====================
*/
bool CanPlaceFlowers( int *flowerbed, int flowerbedSize, int n ) {
	if ( n == 0 ) {
		return true;
	}

	int count = 0;



	for ( int i = 0; i < flowerbedSize; i++ ) {
		if ( flowerbed[i] == 0 ) {
			int left = 0, right = 0;

			if ( i > 0 ) {
				left = flowerbed[i - 1];
			}

			if ( i < flowerbedSize - 1 ) {
				right = flowerbed[i + 1];
			}

			if ( left == 0 && right == 0 ) {
				flowerbed[i] = 1;
				count++;

				if ( count >= n ) {
					return true;
				}
			}
		}
	}

	return false;
}

/*
====================
Main
====================
*/
int main( void ) {
	int flowerbed [ 5 ] = { 1, 0, 0, 0, 1 };
	int tam = 5;
	int n = 1;

	if ( CanPlaceFlowers( flowerbed, tam, n ) ) {
		printf( "TRUE\n" );
	} else {
		printf( "FALSE\n" );
	}

	return 0;
}
