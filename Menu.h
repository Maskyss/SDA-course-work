#pragma once
#include "Measurement.h"

#ifndef VIEWS_H
#define VIEWS_H

void setText(HDC , int , int , LPCTSTR , int );//������� ��� ������� ������ � ������� �� ����� �������
void drawLine(HDC , int , int , int , int , int );//������� ��� ��������� ���
void printTable(wchar_t *columnsTags[], int columnsNum, wchar_t *rowsTags[], int rowsNum, float *time);//������� ��� ��������� �������
void printMenu(); //���� ���������� ����
void ExchangeSortMeasurement(int);//���������� ���� 
void outSorts(int);/*���� ��� ���������� ��������� ������ �� ������� 
				   � ��������������� ������ �� � �������������
				   (����������� ������� ���� ���������� ����������*/
void menu();

#endif