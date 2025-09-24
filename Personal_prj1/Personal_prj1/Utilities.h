#pragma once

#include <stdlib.h>

int GenerateRandomNumber(int Min, int Max)
{
	int Range = Max - Min + 1;
	return rand() % Range + Min;
}

template<typename T>
T Clamp(T InValue, T Min, T Max)
{
	if (InValue < Min) return Min;
	if (InValue > Max) return Max;
	return InValue;
}