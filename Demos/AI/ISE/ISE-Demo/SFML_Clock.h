#pragma once

#include <SFML\System\Clock.hpp>

class SFML_Clock
{
public:
	SFML_Clock(void);
	~SFML_Clock(void);

	float elapsed();

private:
	sf::Clock clock;
	sf::Time time;
};

