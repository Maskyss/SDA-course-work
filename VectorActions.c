#include "VectorActions.h"
//всі функції виключно для векторів з розмірністю  V
clock_t Res_vpor[measurements_number], Res_rand[measurements_number], Res_obr[measurements_number];//вектори типу clock_t для запам*ятовування значень часу для впорядковано, рандомно та обернено заповненого масива
vector VectorForSort;//типізований вектор, оголошений на початку

void vectorsPrint()
{
	wchar_t *columnsTags[] = { L"Sorted", L"Random",L"RevSorted" };
	wchar_t *rowsTags[] = { L"InsertionSort", L"SelectionSort",L"ShellSort", L"QuickSort" };
	float time[12];
	// start Insertion Sort
		for (int i = 0; i < measurements_number; i++)
		{
			SortedVector(VectorForSort,V);
			Res_vpor[i] = insertionSortVector(VectorForSort, V);//заповнення Res_vpor array[measurements_number] clock_t для визначення середнього значення часу
			RandomVector(VectorForSort, V);
			Res_rand[i] = insertionSortVector(VectorForSort, V);//заповнення Res_rand array[measurements_number] clock_t для визначення середнього значення часу
			RevSortedVector(VectorForSort, V);
			Res_obr[i] = insertionSortVector(VectorForSort, V);//заповнення Res_obr array[measurements_number] clock_t для визначення середнього значення часу
		}
		MeasurementProcessing(Res_vpor);
		MeasurementProcessing(Res_rand);
		MeasurementProcessing(Res_obr);
		time[0] = (float)Res_vpor[0] / 20;
		time[1] = (float)Res_rand[0] / 20;
		time[2] = (float)Res_obr[0] / 20;
		
		// start Sekection Sort
		for (int i = 0; i < measurements_number; i++)
		{
			SortedVector(VectorForSort, V);
			Res_vpor[i] = selectionSortVector(VectorForSort, V);
			RandomVector(VectorForSort, V);
			Res_rand[i] = selectionSortVector(VectorForSort, V);
			RevSortedVector(VectorForSort, V);
			Res_obr[i] = selectionSortVector(VectorForSort, V);
		}
		MeasurementProcessing(Res_vpor);
		MeasurementProcessing(Res_rand);
		MeasurementProcessing(Res_obr);
		time[3] = (float)Res_vpor[0] / 20;
		time[4] = (float)Res_rand[0] / 20;
		time[5] = (float)Res_obr[0] / 20;
		// start Shell Sort
		for (int i = 0; i < measurements_number; i++)
		{
			SortedVector(VectorForSort, V);
			Res_vpor[i] = shellSortVector(VectorForSort, V);
			RandomVector(VectorForSort, V);
			Res_rand[i] = shellSortVector(VectorForSort, V);
			RevSortedVector(VectorForSort, V);
			Res_obr[i] = shellSortVector(VectorForSort, V);
		}
		MeasurementProcessing(Res_vpor);
		MeasurementProcessing(Res_rand);
		MeasurementProcessing(Res_obr);
		time[6] = (float)Res_vpor[0] / 20;
		time[7] = (float)Res_rand[0] / 20;
		time[8] = (float)Res_obr[0] / 20;
		// start Quick Sort
		for (int i = 0; i < measurements_number; i++)
		{
			SortedVector(VectorForSort, V);
			Res_vpor[i] = quickPartSortVector(VectorForSort, V);
			RandomVector(VectorForSort, V);
			Res_rand[i] = quickPartSortVector(VectorForSort, V);
			RevSortedVector(VectorForSort, V);
			Res_obr[i] = quickPartSortVector(VectorForSort, V);
		}
		MeasurementProcessing(Res_vpor);
		MeasurementProcessing(Res_rand);
		MeasurementProcessing(Res_obr);
		time[9] = (float)Res_vpor[0] / 20;
		time[10] = (float)Res_rand[0] / 20;
		time[11] = (float)Res_obr[0] / 20;
	
	printTable(columnsTags, 3, rowsTags, 4, time);

}
void RandomVector(vector VectorForSort, int P)
{
	for (int i = 0; i < P; i++)
		VectorForSort[i] = rand() % P;
}

void SortedVector(vector VectorForSort, int P)
{
	int counter = 0;
	for (int i = 0; i < P; i++)
		VectorForSort[i] = counter++;
}

void RevSortedVector(vector VectorForSort, int P)
{
	int counter = 100;
	for (int i = 0; i < P; i++)
		VectorForSort[i] = counter--;
}


void outputV(vector VectorForSort, int P)
{
		for (int i = 0; i<P; i++)
		{
			printf("| ");
			printf("%4.1d ", VectorForSort[i]);
		}		
	printf("\n");
}

clock_t insertionSortVector(vector VectorForSort, int P)
{
	int i, j, k, X, L, R;
	clock_t time;

	time = clock();
	for (i = 1; i < P; i++)
	{
				X = VectorForSort[i];
		L = 0; R = i;
		while (L < R)
		{
			j = (L + R) / 2;
			if (VectorForSort[j] <= X)
				L = j + 1;
			else R = j;
		}
		for (k = i - 1; k >= R; k--)
			VectorForSort[k + 1] = VectorForSort[k];
		
		VectorForSort[R] = X;
	}

	time = clock() - time;
	return time;
}


clock_t selectionSortVector(vector VectorForSort, int P)
{
	int min, imin, s, i;
	clock_t time_start, time_stop;

	time_start = clock();
	for (s = 0; s < P - 1; s++) {
		min = VectorForSort[s];
		imin = s;
		for (i = s + 1; i < P; i++)
			if (VectorForSort[i] < min) 
			{
				min = VectorForSort[i];
				imin = i;
			}
		if (imin != s) 
		{
			VectorForSort[imin] = VectorForSort[s];
			VectorForSort[s] = min;
		}
	}
	time_stop = clock();
	return time_stop - time_start;
}


clock_t shellSortVector(vector VectorForSort, int P)
{
	int i, j, h, B;
	
	clock_t time_start, time_stop;
	time_start = clock();

	for (h = P; h /= 2;)
		for (i = h; i < P; i++) {
			B = VectorForSort[i];
			j = i;
			while ((j >= h) && (B < VectorForSort[j-h]))
			{		
				VectorForSort[j] = VectorForSort[j - h];
				j -= h;
			}
			VectorForSort[j] =B;
		}

	time_stop = clock();
	return time_stop - time_start;
}

clock_t quickPartSortVector(vector VectorForSort, int P) {
	clock_t time_start, time_stop;

	time_start = clock();
	quickSortVector(VectorForSort, 0, P - 1);

	time_stop = clock();
	return time_stop - time_start;
}

void quickSortVector(vector VectorForSort,  int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = VectorForSort[((left + right) / 2)];

	while (i <= j) {
		while (VectorForSort[i] < pivot)
			i++;
		while (VectorForSort[j] > pivot)
			j--;

		if (i <= j) {
			tmp = VectorForSort[i];
			VectorForSort[i] = VectorForSort[j];;
			VectorForSort[j] = tmp;
			i++;
			j--;
		}
	}

	if (left < j)
		quickSortVector(VectorForSort, left, j);
	if (i < right)
		quickSortVector(VectorForSort, i, right);
}
