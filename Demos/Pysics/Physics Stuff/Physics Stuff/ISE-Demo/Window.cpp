#include "Window.h"


Window::Window(void)
{
	created = false;
	update();
}


Window::~Window(void)
{
}

Window::Window(SFML_Facade window)
{
	created = true;
	m_Win = &window;
}

void Window::create(int width, int height, std::string name)
{
	setWidthHeight(width, height);
	setTitle(name);
	//create window
	m_Win = new SFML_Facade();
	m_Win->win_Create(m_width, m_height, m_name);
	created = true;

	//make this window the active opengl context so all the calls go to it
	m_Win->win_active();

	//clear color and depth color
	OPENGL_Facade::colourDepth();

	//enable depth test
	OPENGL_Facade::enableDepth();

	//disable Lighting
	OPENGL_Facade::disableLighting();

}

void Window::setWidthHeight(int width, int height)
{
	setWidth(width);
	setHeight(height);
}

void Window::setWidth(int width)
{
	m_width = width;
}

void Window::setHeight(int height)
{
	m_height = height;
}

void Window::setTitle(std::string name)
{
	m_name = name;
}

void Window::active()
{
	m_Win->win_active();
}

void Window::display()
{
	m_Win->win_display();
}

int Window::getWidth()
{
	return(m_Win->win_getWidth());
	
}

int Window::getHeight()
{
	return(m_Win->win_getHeight());
}

void Window::enableDepth()
{
	m_Win->win_active();
	OPENGL_Facade::enableDepth();
}

void Window::disableDepth()
{
	m_Win->win_active();
	OPENGL_Facade::disableDepth();
}

void Window::enableLighting()
{
	m_Win->win_active();
	OPENGL_Facade::enableLighting();
}

void Window::colourDepth()
{
	m_Win->win_active();
	OPENGL_Facade::colourDepth();
}

void Window::setColour(float R, float G, float B)
{
	m_Win->win_active();
	OPENGL_Facade::colour(R,G,B);
}

void Window::setDepth(float Depth)
{
	m_Win->win_active();
	OPENGL_Facade::Depth(Depth);
}

void Window::update()
{
	//we should have the event thing hhere to get the reshape and focus data(maybe more in the future but we try to keep it minimal
	//we should also remove the reliance on the event portion
	OPENGL_Facade::update();
}

void Window::setWindowPos(int x, int y)
{
	m_Win->setWindowPos( x, y);
}

void Window::getWindowPos(int &x, int &y)
{
	m_Win->getWindowPos(x,y);
}
/*
bool Window::getFocus()
{
	//return (m_Win->getFocus());
	return(true);
}*/

