#pragma once

#include <SFML\Audio.hpp>
#include <string>



class SFML_Sound
{
public:
	enum Sound {
		S_LOOP = 0,
		S_NOTLOOP
	};

	SFML_Sound(void);
	~SFML_Sound(void);

	//load the sound into ram
	bool load(std::string location);

	//play the currently selcted sound, maybe call setLoop()
	void play();
	//play and set the loop
	void play(bool loop);
	//pause the currently loaded sound
	void pause();
	//stop the currently loaded sound
	void stop();
	//set volume
	void setVolume(float volume);
	//get volume
	float getVolume();
	//get loop
	bool getLoop();
	//set loop, this function should not need or rather should be ignored and only through play should things be done
	void setLoop(bool loop);

private:
	sf::SoundBuffer buffer;
	sf::Sound sound;
	

};

