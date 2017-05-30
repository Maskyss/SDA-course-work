#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h> 
#include <conio.h>

#ifndef ARRAYIN_H
#define ARRAYIN_H

#define p 900
#define m 50
#define n 50
#define V 6000//розмірність вектора

typedef int arrayType[p][m][n];//оголошений 3д масив , це новий тип данних , щоб оголошувати в функціях під заданим іменем
typedef int tmpArrayType[m][n];//оголошений додатковий 2д масив, використовується Sorts   shellSort()
typedef int vector[V]; //оголошений вектор для перейменування змінних , для VectorActions

void RandomArray(arrayType, int, int, int);//заповнення  3д масиву рандомно
void SortedArray(arrayType, int, int, int);//заповнення  3д масиву послідовно зі зростанням(відсортований масив)
void RevSortedArray(arrayType, int, int, int);//заповнення  3д масиву послідовно зі спаданням(обернено відсортований масив)
void output(arrayType, int, int, int);//вивід невеликих масивів для наглядності

#endif
