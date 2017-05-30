#pragma once
#include "Menu.h"

#ifndef VECTORACTIONS_H
#define VECTORACTIONS_H
void vectorsPrint();//вимір часу та друк таблиці для векторів
void RandomVector(vector, int);//заповнення вектора рандомно
void SortedVector(vector, int);//заповнення вектора відсортовано
void RevSortedVector(vector, int);//заповнення вектора обернено відсортовано
void outputV(vector, int);//друк значень вектора

clock_t insertionSortVector(vector, int);
clock_t selectionSortVector(vector, int);
clock_t shellSortVector(vector, int);
clock_t quickPartSortVector(vector, int);
void quickSortVector(vector, int, int);

#endif