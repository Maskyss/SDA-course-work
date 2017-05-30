#pragma once
#include "Menu.h"

#ifndef VECTORACTIONS_H
#define VECTORACTIONS_H
void vectorsPrint();//���� ���� �� ���� ������� ��� �������
void RandomVector(vector, int);//���������� ������� ��������
void SortedVector(vector, int);//���������� ������� �����������
void RevSortedVector(vector, int);//���������� ������� �������� �����������
void outputV(vector, int);//���� ������� �������

clock_t insertionSortVector(vector, int);
clock_t selectionSortVector(vector, int);
clock_t shellSortVector(vector, int);
clock_t quickPartSortVector(vector, int);
void quickSortVector(vector, int, int);

#endif