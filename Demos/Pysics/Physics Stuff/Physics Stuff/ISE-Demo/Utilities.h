#pragma once

static const float pi = 3.14159f;

float DegtoRad(float degrees);

float RadtoDeg(float radians);

template<typename T>
T Clamp(T value, T min, T max)
{
	if (value < min)
		return min;
	else if (value > max)
		return max;
	else
		return value;
}

template<typename T>
T Min(T a, T b)
{
	return (a < b) ? a : b;
}

template<typename T>
T Max(T a, T b)
{
	return (a > b) ? a : b;
}

template<typename T>
T Sign(T value)
{
	if (value < 0)
		return -1;
	else
		return 1;
}

