#pragma once
#include "Sorts.h"
//#include "ArrayIn.h"
#include "VectorActions.h"

#ifndef MEASUREMENTS_H
#define MEASUREMENTS_H
#define measurements_number 28

extern clock_t Res[measurements_number];

void MeasurementProcessing(clock_t *Res);

#endif