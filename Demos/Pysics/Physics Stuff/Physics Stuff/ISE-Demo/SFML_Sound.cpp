#include "SFML_Sound.h"


SFML_Sound::SFML_Sound(void)
{
	
}


SFML_Sound::~SFML_Sound(void)
{
}

bool SFML_Sound::load(std::string location)
{
	//return true if it loaded successfully 
	


	if(!buffer.loadFromFile(location))
	{
		sound.setBuffer(buffer);
		return (false);
	}
	else
	{
		sound.setBuffer(buffer);
		return(true);
	}
}

void SFML_Sound::play()
{
	sound.play();
}

void SFML_Sound::play(bool loop)
{
	if(loop)
	{
		sound.setLoop(true);
	}
	else
	{
		sound.setLoop(false);
	}
	sound.play();
	
}

void SFML_Sound::pause()
{
	sound.pause();
}

void SFML_Sound::stop()
{
	sound.stop();
}

void SFML_Sound::setVolume(float volume)
{
	sound.setVolume(volume);
}

float SFML_Sound::getVolume()
{
	return(sound.getVolume());
}

bool SFML_Sound::getLoop()
{
	return(sound.getVolume());
}

void SFML_Sound::setLoop(bool loop)
{
	if(loop)
	{
		sound.setLoop(true);
	}
	else
	{
		sound.setLoop(false);
	}
}