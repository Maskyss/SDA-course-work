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
#define V 6000//��������� �������

typedef int arrayType[p][m][n];//���������� 3� ����� , �� ����� ��� ������ , ��� ����������� � �������� �� ������� ������
typedef int tmpArrayType[m][n];//���������� ���������� 2� �����, ��������������� Sorts   shellSort()
typedef int vector[V]; //���������� ������ ��� �������������� ������ , ��� VectorActions

void RandomArray(arrayType, int, int, int);//����������  3� ������ ��������
void SortedArray(arrayType, int, int, int);//����������  3� ������ ��������� � ����������(������������ �����)
void RevSortedArray(arrayType, int, int, int);//����������  3� ������ ��������� � ���������(�������� ������������ �����)
void output(arrayType, int, int, int);//���� ��������� ������ ��� ����������

#endif
