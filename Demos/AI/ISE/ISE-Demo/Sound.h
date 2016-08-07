#pragma once

#include "SFML_Sound.h"
#include <string>
#include <iostream>

class Sound
{
public:
	Sound(void);
	~Sound(void);

	void Load(std::string location);

	void play();

	void playWithLoop();

	void pause();

	void stop();

	void setVolume(float volume);

	float getVolume();

	//bool getLoop();//function not needed call to loop and not loop

	//void setLoop();///function not needed call to loop and not loop

private:
	SFML_Sound sound;
	bool loop;
};

