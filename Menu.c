#pragma once
#include "Menu.h"

clock_t Res_vpor[measurements_number], Res_rand[measurements_number], Res_obr[measurements_number];//вектори типу clock_t для запам*ятовування значень часу для впорядковано, рандомно та обернено заповненого масива
arrayType ArrayForSort;//типізована 3д матриця, оголошена на початку роботи для зручності написання функцій
vector VectorForSort;//типізований вектор, оголошений на початку

void setText(HDC hdc, int x, int y, LPCTSTR message, int color)// використання в функції printTable(); LPCTSTR message має тип wchar_t(як масив символів)оголошені значення в  menu()
{
	RECT rect; 
	SetTextColor(hdc, color);
	SetBkMode(hdc, TRANSPARENT);
	SetRect(&rect, x, y, x + 100, y + 100);
	DrawText(hdc, message, -1, &rect, DT_SINGLELINE | DT_NOCLIP);//стандартні функції windows.h для тексту в консолі
}

void drawLine(HDC hdc, int x0, int y0, int x, int y, int color)//викликається в printTable()
{
	HPEN pen, oldPen;
	pen = CreatePen(PS_SOLID, 3, color);
	oldPen = (HPEN)SelectObject(hdc, pen);
	MoveToEx(hdc, x0, y0, NULL);
	LineTo(hdc, x, y); //стандартні функції windows.h для намалювання ліній, тобто таблиці в консолі
}

void printTable(wchar_t *columnsTags[], int columnsNum, wchar_t *rowsTags[], int rowsNum, float *time)
/*функція приймає значення в menu(),а саме columnsTags -  назви совпців,
columnsNum - кількість стовбчиків таблиці(3 типи заповнення масивів),rowsTags - назви рядків,
rowsNum - кількість рядків таблиці(3 типи заповнення масивів +1)
*/
{
	system("cls");
	HWND hwnd = GetConsoleWindow();
	Sleep(40);
	HDC hdc = GetDC(hwnd);
	RECT rect;

	GetWindowRect(hwnd, &rect);
	int height = rect.bottom - rect.top - 40;
	int width = rect.right - rect.left - 35;

	int rowSize = height / (rowsNum+1);
	int columnSize = width / (columnsNum+1);
	wchar_t textBuffer[256];

	for (int i = 0; i <= height; i += rowSize)
		drawLine(hdc, 0, i, width, i, RGB(255, 255, 255));

	for (int i = 0; i <= width; i += columnSize)
		drawLine(hdc, i, 0, i, height, RGB(255, 255, 255));

	int k = 0;
	for (int i = rowSize / 2+ rowSize; i < height; i += rowSize)
		setText(hdc, columnSize / 3, i, rowsTags[k++], RGB(255, 255, 255));

	k = 0;
	for (int i = columnSize / 2 + columnSize; i < width; i += columnSize)
		setText(hdc, i, rowSize / 3, columnsTags[k++], RGB(255, 255, 255));
	
	k = 0;
	for (int i = 0; i < rowsNum; ++i)
		for (int j = 0; j < columnsNum; ++j)
		{
			swprintf(textBuffer, 100, L"%f", time[k++]);
			setText(hdc, (j+1)*columnSize + columnSize/4, (i+1)*rowSize + rowSize / 2, textBuffer, RGB(255,255,0));
		}

	setText(hdc, 2, 0, L"Press any key", RGB(255, 255, 255));
	setText(hdc, 2, 15, L"to continue...", RGB(255, 255, 255));
	swprintf(textBuffer, 100, L"Array[%d][%d][%d]", p,m,n);
	setText(hdc, 2, 50, textBuffer, RGB(255, 255, 255));
	swprintf(textBuffer, 100, L"Vector[%d]",V);
	setText(hdc, 2, 70, textBuffer, RGB(255, 255, 255));
	ReleaseDC(hwnd, hdc);   
	_getch();
	rect.top = 0;
	rect.left = 0;
	InvalidateRect(hwnd, &rect, 1); 
	UpdateWindow(hwnd);
}

void printMenu() //вивідменю для вибору користувача однієї з дій
{	
	printf("Hello, do you want sort 3d-array[%d][%d][%d] and vector[%d]?  \n\n",p,m,n,V);
	printf("Choose your option for demonstration of sorts: \n");
	printf("\t1.Table of all sorting\n");
	printf("\t2.View on sorting on 3d-array and vector(good choose for 3d-array[5][5][5] and vector[17])\n");
	printf("\t3.Table for one sort\n");
	printf("\t4.Table of all sorting  vector\n");
	printf("\t5.Quit\n\n");
	printf("Enter your option: ");
}

void ExchangeSortMeasurement(int x)//determining the average value of time; x declared in menu()
{
	switch (x)
	{
	case 1:
	{ // start Insertion Sort
		for (int i = 0; i < measurements_number; i++)
		{
			SortedArray(ArrayForSort, p, m, n);
			Res_vpor[i] = insertionSort(ArrayForSort, p, m, n);
			//заповнення Res_vpor array[measurements_number] clock_t для визначення середнього значення
			RandomArray(ArrayForSort, p, m, n);
			Res_rand[i] = insertionSort(ArrayForSort, p, m, n);//заповнення Res_rand array[measurements_number] clock_t для визначення середнього значення
			RevSortedArray(ArrayForSort, p, m, n);
			Res_obr[i] = insertionSort(ArrayForSort, p, m, n);//заповнення Res_obr array[measurements_number] clock_t для визначення середнього значення
		}
		MeasurementProcessing(Res_vpor);
		MeasurementProcessing(Res_rand);
		MeasurementProcessing(Res_obr);
		break;
	}
	case 2:
	{ // start Selection Sort
		for (int i = 0; i < measurements_number; i++)
		{
			SortedArray(ArrayForSort, p, m, n);
			Res_vpor[i] = selectionSort(ArrayForSort, p, m, n);
			RandomArray(ArrayForSort, p, m, n);
			Res_rand[i] = selectionSort(ArrayForSort, p, m, n);
			RevSortedArray(ArrayForSort, p, m, n);
			Res_obr[i] = selectionSort(ArrayForSort, p, m, n);

		}
		MeasurementProcessing(Res_vpor);
		MeasurementProcessing(Res_rand);
		MeasurementProcessing(Res_obr);
		break;
	}
	case 3:
	{ // start Shell Sort
		for (int i = 0; i < measurements_number; i++)
		{
			SortedArray(ArrayForSort, p, m, n);
			Res_vpor[i] = shellSort(ArrayForSort, p, m, n);
			RandomArray(ArrayForSort, p, m, n);
			Res_rand[i] = shellSort(ArrayForSort, p, m, n);
			RevSortedArray(ArrayForSort, p, m, n);
			Res_obr[i] = shellSort(ArrayForSort, p, m, n);
		}
		MeasurementProcessing(Res_vpor);
		MeasurementProcessing(Res_rand);
		MeasurementProcessing(Res_obr);
		break;
	}
	case 4:
	{// start Quick Sort
		for (int i = 0; i < measurements_number; i++)
		{
			SortedArray(ArrayForSort, p, m, n);
			Res_vpor[i] = quickPartSort(ArrayForSort, p, m, n);
			RandomArray(ArrayForSort, p, m, n);
			Res_rand[i] = quickPartSort(ArrayForSort, p, m, n);
			RevSortedArray(ArrayForSort, p, m, n);
			Res_obr[i] = quickPartSort(ArrayForSort, p, m, n);
		}
		MeasurementProcessing(Res_vpor);
		MeasurementProcessing(Res_rand);
		MeasurementProcessing(Res_obr);
		break;
	}
	}
}

void outSorts(int x) //вивід у консоль сортувань за вибором х, демонструється лише рандомно заповнені масив та вектор
{	
		switch (x)
		{
		case 1:
			printf("*Insertion sort*\n");
			printf("Random array before");
			RandomArray(ArrayForSort, 5,5,5);
			output(ArrayForSort, 5, 5, 5);// на початку виводить невідсотрований масив
			printf("After");
			insertionSort(ArrayForSort, 5, 5, 5);
			output(ArrayForSort, 5, 5, 5);//вивід відсортованого масиву за значення Р(відсортовані перерізи за значенням Р  стають на свої місця)

			printf("Random vector before\n");
			RandomVector(VectorForSort, 17);
			outputV(VectorForSort,17);// на початку виводить невідсотрований вектор
			printf("After\n");
			insertionSortVector(VectorForSort, 17);//відсортований вектор
			outputV(VectorForSort, 17);
			break;
		case 2:
			printf("*Selection sort*\n");
			printf("Random array before");
			RandomArray(ArrayForSort, 5, 5, 5);
			output(ArrayForSort, 5, 5, 5);
			printf("After");
			selectionSort(ArrayForSort, 5, 5, 5);
			output(ArrayForSort, 5, 5, 5);

			printf("Random vector before\n");
			RandomVector(VectorForSort, 17);
			outputV(VectorForSort, 17);
			printf("After\n");
			selectionSortVector(VectorForSort,17);
			outputV(VectorForSort, 17);
			break;
		case 3:
			printf("*Shell sort*\n");
			printf("Random array before");
			RandomArray(ArrayForSort, 5, 5, 5);
			output(ArrayForSort, 5, 5, 5);
			printf("After");
			shellSort(ArrayForSort, 5, 5, 5);
			output(ArrayForSort, 5, 5, 5);

			printf("Random vector before\n");
			RandomVector(VectorForSort, 17);
			outputV(VectorForSort, 17);
			printf("After\n");
			shellSortVector(VectorForSort, 17);
			outputV(VectorForSort, 17);
			break;
		case 4:
			printf("*Quick sort*\n");
			printf("Random array before");
			RandomArray(ArrayForSort, 5, 5, 5);
			output(ArrayForSort, 5, 5, 5);
			printf("After");
			quickPartSort(ArrayForSort, 5, 5, 5);
			output(ArrayForSort, 5, 5, 5);

			printf("Random vector before\n");
			RandomVector(VectorForSort, 17);
			outputV(VectorForSort,17);
			printf("After\n");
			quickPartSortVector(VectorForSort, 17);
			outputV(VectorForSort, 17);
			break;
		}
}

void menu()
{
	wchar_t *columnsTags[] = { L"Sorted", L"Random", L"RevSorted" };
	wchar_t *rowsTags[] = { L"InsertionSort", L"SelectionSort", L"ShellSort", L"QuickSort" };
	float time[12];//масив має 3*4 значень часу =  4 сортування * 3 стани

	char number;
	int numbSort;

	printMenu();
	scanf_s("%ch", &number);	
	while (number != '5') {		
		switch (number) {
		case ('1'):
			system("cls");
			printf("Calculating...");
			ExchangeSortMeasurement(1);
			time[0] = (float)Res_vpor[0] / 20;
			time[1] = (float)Res_rand[0] / 20;
			time[2] = (float)Res_obr[0] / 20;
			ExchangeSortMeasurement(2);
			time[3] = (float)Res_vpor[0] / 20;
			time[4] = (float)Res_rand[0] / 20;
			time[5] = (float)Res_obr[0] / 20;
			ExchangeSortMeasurement(3);
			time[6] = (float)Res_vpor[0] / 20;
			time[7] = (float)Res_rand[0] / 20;
			time[8] = (float)Res_obr[0] / 20;
			ExchangeSortMeasurement(4);
			time[9] = (float)Res_vpor[0] / 20;
			time[10] = (float)Res_rand[0] / 20;
			time[11] = (float)Res_obr[0] / 20;
			system("cls");
			printTable(columnsTags, 3, rowsTags, 4, time);/*передається у функцію 
														  printTable(назви стовпчиків, кількість стовпчиків, назви рядків, кількість рядків)*/
			break;
		case ('2'):
			system("cls");
			do {				
				printf("Please, chose sort for view:\n1)Insertion sort \n2)Selection sort\n3)Shell sort\n4)Quick sort\n5)EXIT\n");
				scanf_s("%d", &numbSort);
				if (numbSort != 5)
				{	
					outSorts(numbSort);
				}
			} while (numbSort != 5);
			break;
		case ('4'):
			system("cls");
			printf("Please. Wait\n");
			vectorsPrint();
			break;
		case ('3'):	
			system("cls");
			do {
				printf("Please, chose sort for view:\n\t1)Insertion sort \n\t2)Selection sort\n\t3)Shell sort\n\t4)Quick sort\n\t5)EXIT\n");
				scanf_s("%d", &numbSort);
				if (numbSort != 5) 
				{
					ExchangeSortMeasurement(numbSort);
					time[0] = (float)Res_vpor[0] / 20;
					time[1] = (float)Res_rand[0] / 20;
					time[2] = (float)Res_obr[0] / 20;
					system("cls");
					wchar_t *rowsTag[] = { rowsTags[numbSort - 1] };
					printTable(columnsTags, 3, rowsTag, 1, time);
				}
			} while (numbSort != 5);
			break;
		}
		if (number != 5)
		{
			system("cls");
			printMenu();
			scanf_s("%ch", &number);
		}
	}	
	system("cls");
	printf("\tGoodbye\n\n");
}