#include "Sound.h"


Sound::Sound(void)
{
	loop = false;

}


Sound::~Sound(void)
{
}

void Sound::Load(std::string location)
{
	sound.load(location);
}

void Sound::play()
{
	loop = false;
	sound.setLoop(loop);
	sound.play();
}

void Sound::playWithLoop()
{
	loop = true;
	sound.setLoop(loop);
	sound.play();
}

void Sound::pause()
{
	sound.pause();
}

void Sound::stop()
{
	sound.stop();
}

void Sound::setVolume(float volume)
{
	sound.setVolume(volume);
}

float Sound::getVolume()
{
	return(sound.getVolume());
}