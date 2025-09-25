
#include <cstdlib>

#include "Utilities.h"

int GenerateRandomNumber(int Min, int Max)
{
	int Range = Max - Min + 1;
	return rand() % Range + Min;
}

int Clamp(int InValue, int Min, int Max)
{
	if (InValue < Min) return Min;
	if (InValue > Max) return Max;
	return InValue;
}
