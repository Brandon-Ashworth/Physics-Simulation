#include "Input.h"


Input::Input(void)
{
	int i = 0;

	for(i=0;i<Keyboard::KeyCount;i++)
	{
		press[i] = false;
		rel[i] = false;
	}

	for(i=0;i<Mouse::ButtonCount;i++)
	{
		mousePress[i] = false;
		mouseRel[i] = false;
	}

}


Input::~Input(void)
{
}

bool Input::isPress(Keyboard::Key key)
{
	if(inputs.isPressed(key) == true)
	{
		press[key] = true;
		return(press[key]);
	}
	else 
	{
		if(press[key] == true)
		{
			rel[key] = true;
			press[key] = false;
		}
		
		return (false);
	}

	
}

bool Input::isReleased(Keyboard::Key key)
{
	//might cancel a release if it is done too fast
	if (inputs.isPressed(key) == true)
	{
		rel[key] = false;
		press[key] = true;
		return (false);
	}
	else // key is not pressed
	{
		if (press[key] == true)
		{
			rel[key] = false;
			press[key] = false;
			return (true);
		}
		else if (rel[key] == true)
		{
			rel[key] = false;
			return (true);
		}
		return (false);
	}

}

bool Input::isMousePress(Mouse::Button but)
{
	if(inputs.isPressed(but) == true)
	{
		mousePress[but] = true;
		return(mousePress[but]);
	}
	else 
	{
		if(mousePress[but] == true)
		{
			mouseRel[but] = true;
			mousePress[but] = false;
		}
		
		return (false);
	}
}

bool Input::isMouseReleased(Mouse::Button but)
{
	if (inputs.isPressed(but) == true)
	{
		mouseRel[but] = false;
		mousePress[but] = true;
		return (false);
	}
	else // but is not mousePressed
	{
		if (mousePress[but] == true)
		{
			mouseRel[but] = false;
			mousePress[but] = false;
			return (true);
		}
		else if (mouseRel[but] == true)
		{
			mouseRel[but] = false;
			return (true);
		}
		return (false);
	}
}

void Input::lockMouse()
{
	inputs.lockMouse();
}

void Input::releaseMouse()
{
	inputs.ReleaseMouse();
}

void Input::setMouseLockPosition(int x, int y)
{
	inputs.setMouse(x,y);
}

void Input::getMouseLocation(int &x, int &y)
{
	inputs.getMouse(x,y);
}

void Input::getMouseVec(int &x, int &y)
{
	inputs.getMouseVec(x,y);
}

void Input::mouseUpdate()
{
	inputs.mouseUpdate();
}