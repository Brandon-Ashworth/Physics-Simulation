#include "SFML_Facade.h"


SFML_Facade::SFML_Facade(void)
{
	window = NULL;
	focus = true;
}


SFML_Facade::~SFML_Facade(void)
{
}

bool SFML_Facade::win_Create(int width, int height, std::string name)
{
	window = new sf::Window(sf::VideoMode(width,height,32),name);
	
	
	if(window != NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool SFML_Facade::win_active()
{
	return(window->setActive());//return true if it has been set false if it has been deactiivated
	
}

void SFML_Facade::win_display()
{
	window->display();
}

int SFML_Facade::win_getWidth()
{
	return(window->getSize().x); // return the width
}

int SFML_Facade::win_getHeight()
{
	return(window->getSize().y); // return the height
}

void SFML_Facade::setWindowPos(int x,int y)
{
	sf::Vector2<int> position(x,y);
	window->setPosition(position);
}

void SFML_Facade::getWindowPos(int &x, int &y)
{
	sf::Vector2<int> position = window->getPosition();
	x = position.x;
	y = position.y;

}

void SFML_Facade::update()
{
	sf::Event event;
	while(window->pollEvent(event))
	{
		if(event.type == sf::Event::GainedFocus)
		{
			focus = true;
		}
		if(event.type == sf::Event::LostFocus)
		{
			focus = false;
		}
		if(event.type == sf::Event::Resized)
		{
			//put the reshape code here
		} 
	}
}

bool SFML_Facade::getFocus()
{
	update();
	return(focus);
}

bool SFML_Facade::getReshape()
{
	update();
	return(false);//this function has not been implemented
}

