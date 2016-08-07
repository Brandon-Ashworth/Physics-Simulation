#include "SFML_Clock.h"


SFML_Clock::SFML_Clock(void)
{
	clock.restart();
}


SFML_Clock::~SFML_Clock(void)
{
}

float SFML_Clock::elapsed()
{
	time = clock.restart();
	return(time.asMilliseconds());
}
