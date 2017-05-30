#pragma once
#include "Sorts.h"

clock_t insertionSort(arrayType ArrayForSort, int P, int M, int N)
{
	int i, j, k, x, y, L, R;/*змінні i, j, k -  для лічильників загального сортування вставки, 
								L, R -  для лівої та правої межі(бо вставка з бінарним пошуком)
								x, y -  для  лічильниців перезапису до додаткової матриці tmpA*/
	tmpArrayType tmpA;//додаткова матриця m*n

	clock_t time_start,time_stop;
	time_start = clock();
	for (i = 1; i < P; i++)
	{
		for (x = 0; x < M; x++)
			for (y = 0; y < N; y++)
				tmpA[x][y] = ArrayForSort[i][x][y];

		L = 0; R = i;
		while (L < R)
		{
			j = (L + R) / 2;
			if (ArrayForSort[j][0][0] <= tmpA[0][0])
				L = j + 1;
			else R = j;
		}
		for (k = i - 1; k >= R; k--)
			for (x = 0; x < M; x++)
				for (y = 0; y < N; y++)
					ArrayForSort[k + 1][x][y] = ArrayForSort[k][x][y];
		for (x = 0; x < M; x++)
			for (y = 0; y < N; y++)
				ArrayForSort[R][x][y] = tmpA[x][y];
	}

	time_stop = clock();
	return time_stop - time_start;
}


clock_t selectionSort(arrayType ArrayForSort, int P, int M, int N)
{
	int min, imin, min1, x, y, s, i; /*min -  змінна для початкового запису значення,
									 imin - запам*ятовування номер комірки, 
									 min1 - додаткова змінна для обміну останніх значень перерізу*/

	clock_t time_start, time_stop;
	time_start = clock();
	for (s = 0; s < P - 1; s++) {
		min = ArrayForSort[s][0][0];
		imin = s;
		for (i = s + 1; i < P; i++)
			if (ArrayForSort[i][0][0] < min) {
				min = ArrayForSort[i][0][0];
				imin = i;
			}
		if (imin != s) {
			for (x = 0; x < M; x++)
				for (y = 0; y < N; y++)
				{
					min1 = ArrayForSort[imin][x][y];
					ArrayForSort[imin][x][y] = ArrayForSort[s][x][y];
					ArrayForSort[s][x][y] = min1;
				}
		}
	}
	time_stop = clock();
	return time_stop - time_start;					
}


clock_t shellSort(arrayType ArrayForSort, int P, int M, int N)
{
	int i, j, h, t,d ;/*змінні i, j -  для лічильників загального сортування вставки
					 h - для запам*ятовування кількості відстані між елементами для перестановки */
	int  x, y;/* x, y -  для  лічильниців перезапису до додаткової матриці tmpA*/
	tmpArrayType tmpA;//додаткова матриця m*n
	int H[p];//
	
	if (P < 4) t = 1;
	else t = log2(P) - 1;
	H[t - 1] = 1;
	for (i = t - 2; i >= 0; i--) H[i] = 2 * H[i + 1];

	clock_t time_start, time_stop;	
	time_start = clock();
	
	for (d = 0; d < t; d++) {
		h = H[d];
		for (i = h; i < P; i++) {
			for (x = 0; x < M; x++)
				for (y = 0; y < N; y++)
					tmpA[x][y] = ArrayForSort[i][x][y];
			j = i;
			while (j >= h && tmpA[0][0] < ArrayForSort[j - h][0][0]) {
				for (x = 0; x < M; x++) {
					for (y = 0; y < N; y++)
						ArrayForSort[j][x][y] = ArrayForSort[j - h][x][y];
				}
				j -= h;
			}
			for (x = 0; x < M; x++)
				for (y = 0; y < N; y++)
					ArrayForSort[j][x][y] = tmpA[x][y];
		}
	}
	time_stop = clock();
	return time_stop - time_start;
}

clock_t quickPartSort(arrayType ArrayForSort, int P, int M, int N) {
	clock_t time_start, time_stop;
	time_start = clock();

	quickSort(ArrayForSort, 0, P - 1, M, N);

	time_stop = clock();
	return time_stop - time_start;
}

void quickSort(arrayType ArrayForSort, int left, int right, int M, int N) {
	int i = left, j = right, x, y;
	int tmp;//буферна змінна
	int pivot = ArrayForSort[((left + right) / 2)][0][0];

	while (i <= j) {
		while (ArrayForSort[i][0][0] < pivot)
			i++;
		while (ArrayForSort[j][0][0] > pivot)
			j--;

		if (i <= j) {
			
			for (x = 0; x < M; x++)
				for (y = 0; y < N; y++)
				{
					tmp = ArrayForSort[i][x][y];
					ArrayForSort[i][x][y] = ArrayForSort[j][x][y];
					ArrayForSort[j][x][y] = tmp;
				}
			i++;
			j--;
		}
	}

	if (left < j)
		quickSort(ArrayForSort, left, j, M, N);
	if (i < right)
		quickSort(ArrayForSort, i, right, M, N);
}
