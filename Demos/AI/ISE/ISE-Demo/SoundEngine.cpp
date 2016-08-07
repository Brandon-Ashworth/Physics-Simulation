#include "SoundEngine.h"


SoundEngine::SoundEngine(void)
{
}


SoundEngine::~SoundEngine(void)
{
}

void SoundEngine::playOnce(Sound &sound)
{
	
	sound.play();
}

void SoundEngine::playWithLoop(Sound &sound)
{
	sound.playWithLoop();
}

void SoundEngine::setVolume(Sound &sound, float volume)
{
	sound.setVolume(volume);
}

float SoundEngine::getVolume(Sound &sound)
{
	return(sound.getVolume());
}