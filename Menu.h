#pragma once
#include "Measurement.h"

#ifndef VIEWS_H
#define VIEWS_H

void setText(HDC , int , int , LPCTSTR , int );//функція для задання тексту в консоль на певну позицію
void drawLine(HDC , int , int , int , int , int );//функція для малювання ліній
void printTable(wchar_t *columnsTags[], int columnsNum, wchar_t *rowsTags[], int rowsNum, float *time);//функція для малювання таблиці
void printMenu(); //вивід текстового меню
void ExchangeSortMeasurement(int);//вимірювання часу 
void outSorts(int);/*вивід для наглядності невеликих масивів та векторів 
				   у невідсортованому вигляді та у відсортованому
				   (представлені матриці лише рандомного заповнення*/
void menu();

#endif