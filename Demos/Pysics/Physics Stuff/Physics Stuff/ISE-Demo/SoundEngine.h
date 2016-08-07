#pragma once

#include "Sound.h"

class SoundEngine
{
public:
	SoundEngine(void);
	~SoundEngine(void);

	void playOnce(Sound &sound);

	void playWithLoop(Sound &sound);

	void setVolume(Sound &sound, float volume);

	float getVolume(Sound &sound);

private:

};

