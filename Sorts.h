#pragma once
#include "ArrayIn.h"

#ifndef SORTS_H
#define SORTS_H

clock_t insertionSort(arrayType, int, int, int);
clock_t selectionSort(arrayType, int, int, int);
clock_t shellSort(arrayType, int, int, int);
clock_t quickPartSort(arrayType, int, int, int);
void quickSort(arrayType, int, int, int, int);

#endif