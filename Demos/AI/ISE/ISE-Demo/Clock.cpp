#include "Clock.h"


Clock::Clock(void)
{
	time.elapsed();
}


Clock::~Clock(void)
{
}

float Clock::getElapsed()
{
	return(time.elapsed());
}