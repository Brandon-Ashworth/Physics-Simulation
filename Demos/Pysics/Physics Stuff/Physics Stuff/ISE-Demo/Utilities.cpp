#include "Utilities.h"
#include <math.h>
#include <stdlib.h>

float DegtoRad(float degrees)
{
	return degrees/180.0f*pi;
}

float RadtoDeg(float radians)
{
	return radians * 180.0f/pi;
}

