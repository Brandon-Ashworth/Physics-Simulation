#pragma once

#include "SFML_Clock.h"

class Clock
{
public:
	Clock(void);
	~Clock(void);

	float getElapsed();

private:
	SFML_Clock time;
};

