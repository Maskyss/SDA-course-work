#include "ArrayIn.h"

void RandomArray(arrayType arraySort, int P, int M, int N)
{
	int i, j, k;
	for (i = 0; i < P; i++)
		for (j = 0; j < M; j++)
			for (k = 0; k < N; k++)
				arraySort[i][j][k] = rand()%(P*M*N) ;
}

void SortedArray(arrayType arraySort, int P, int M, int N)
{
	int i, j, k;
	int counter=0;
	for (i = 0; i < P; i++)
		for (j = 0; j < M; j++)
			for (k = 0; k < N; k++)
				arraySort[i][j][k] =  counter++;
}

void RevSortedArray(arrayType arraySort, int P, int M, int N)
{
	int i, j, k;
	int counter = 100;
	for (i = 0; i < P; i++)
		for (j = 0; j < M; j++)
			for (k = 0; k < N; k++)
				arraySort[i][j][k] = counter--;
}

void output(arrayType arraySort, int P, int M, int N)
{
	int i, j, k;
	printf("\n**********************\n");
	for (j = 0; j<M; j++)
	{
		for (i = 0; i<P; i++)
		{
			printf("|");
			for (k = 0; k<N; k++)
			{
				printf("%4.1d", arraySort[i][j][k]);
			}
		}
		printf(" |");
		printf("\n");
	}
	printf("\n");
}
