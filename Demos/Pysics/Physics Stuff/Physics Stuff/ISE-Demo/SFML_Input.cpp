#include "SFML_Input.h"

#include  <iostream>

//oh god
SFML_Input::SFML_Input(void)
{
	mouseLock = false;
	setMouse(0,0);
	//oldPos = pos;

	//comp_but or but_comp
	but_comp[0] = sf::Mouse::Left;
	but_comp[1] = sf::Mouse::Right;
	but_comp[2] = sf::Mouse::Middle;
	but_comp[3] = sf::Mouse::XButton1;
	but_comp[4] = sf::Mouse::XButton2;

	//comp[i]=sf::Keyboard::Unknown 
	int i = 0;
	comp[i]=sf::Keyboard::A;
	i++;       
	comp[i]=sf::Keyboard::B;
	i++;            
	comp[i]=sf::Keyboard::C;
	i++;            
	comp[i]=sf::Keyboard::D;
	i++;            
	comp[i]=sf::Keyboard::E;
	i++;            
	comp[i]=sf::Keyboard::F;
	i++;            
	comp[i]=sf::Keyboard::G;
	i++;            
	comp[i]=sf::Keyboard::H;
	i++;            
	comp[i]=sf::Keyboard::I;
	i++;            
	comp[i]=sf::Keyboard::J;
	i++;            
	comp[i]=sf::Keyboard::K;
	i++;            
	comp[i]=sf::Keyboard::L;
	i++;            
	comp[i]=sf::Keyboard::M;
	i++;            
	comp[i]=sf::Keyboard::N;
	i++;            
	comp[i]=sf::Keyboard::O;
	i++;            
	comp[i]=sf::Keyboard::P;
	i++;            
	comp[i]=sf::Keyboard::Q;
	i++;            
	comp[i]=sf::Keyboard::R;
	i++;            
	comp[i]=sf::Keyboard::S;
	i++;            
	comp[i]=sf::Keyboard::T;
	i++;            
	comp[i]=sf::Keyboard::U;
	i++;            
	comp[i]=sf::Keyboard::V;
	i++;            
	comp[i]=sf::Keyboard::W;
	i++;            
	comp[i]=sf::Keyboard::X;
	i++;            
	comp[i]=sf::Keyboard::Y;
	i++;            
	comp[i]=sf::Keyboard::Z;
	i++;            
	comp[i]=sf::Keyboard::Num0;
	i++;         
	comp[i]=sf::Keyboard::Num1;
	i++;         
	comp[i]=sf::Keyboard::Num2;
	i++;         
	comp[i]=sf::Keyboard::Num3;
	i++;         
	comp[i]=sf::Keyboard::Num4;
	i++;         
	comp[i]=sf::Keyboard::Num5;
	i++;         
	comp[i]=sf::Keyboard::Num6;
	i++;         
	comp[i]=sf::Keyboard::Num7;
	i++;         
	comp[i]=sf::Keyboard::Num8;
	i++;         
	comp[i]=sf::Keyboard::Num9;
	i++;         
	comp[i]=sf::Keyboard::Escape;
	i++;       
	comp[i]=sf::Keyboard::LControl;
	i++;     
	comp[i]=sf::Keyboard::LShift;
	i++;       
	comp[i]=sf::Keyboard::LAlt;
	i++;        
	comp[i]=sf::Keyboard::LSystem;
	i++;      
	comp[i]=sf::Keyboard::RControl;
	i++;     
	comp[i]=sf::Keyboard::RShift;
	i++;       
	comp[i]=sf::Keyboard::RAlt;
	i++;         
	comp[i]=sf::Keyboard::RSystem;
	i++;      
	comp[i]=sf::Keyboard::Menu;
	i++;         
	comp[i]=sf::Keyboard::LBracket;
	i++;     
	comp[i]=sf::Keyboard::RBracket;
	i++;     
	comp[i]=sf::Keyboard::SemiColon;
	i++;    
	comp[i]=sf::Keyboard::Comma;
	i++;        
	comp[i]=sf::Keyboard::Period;
	i++;       
	comp[i]=sf::Keyboard::Quote;
	i++;        
	comp[i]=sf::Keyboard::Slash;
	i++;        
	comp[i]=sf::Keyboard::BackSlash;
	i++;    
	comp[i]=sf::Keyboard::Tilde;
	i++;        
	comp[i]=sf::Keyboard::Equal;
	i++;        
	comp[i]=sf::Keyboard::Dash;
	i++;         
	comp[i]=sf::Keyboard::Space;
	i++;        
	comp[i]=sf::Keyboard::Return;
	i++;       
	comp[i]=sf::Keyboard::BackSpace;
	i++;    
	comp[i]=sf::Keyboard::Tab;
	i++;          
	comp[i]=sf::Keyboard::PageUp;
	i++;       
	comp[i]=sf::Keyboard::PageDown;
	i++;     
	comp[i]=sf::Keyboard::End;
	i++;          
	comp[i]=sf::Keyboard::Home;
	i++;         
	comp[i]=sf::Keyboard::Insert;
	i++;       
	comp[i]=sf::Keyboard::Delete;
	i++;       
	comp[i]=sf::Keyboard::Add;
	i++;          
	comp[i]=sf::Keyboard::Subtract;
	i++;     
	comp[i]=sf::Keyboard::Multiply;
	i++;     
	comp[i]=sf::Keyboard::Divide;
	i++;       
	comp[i]=sf::Keyboard::Left;
	i++;         
	comp[i]=sf::Keyboard::Right;
	i++;        
	comp[i]=sf::Keyboard::Up;
	i++;           
	comp[i]=sf::Keyboard::Down;
	i++;         
	comp[i]=sf::Keyboard::Numpad0;
	i++;      
	comp[i]=sf::Keyboard::Numpad1;
	i++;      
	comp[i]=sf::Keyboard::Numpad2;
	i++;      
	comp[i]=sf::Keyboard::Numpad3;
	i++;      
	comp[i]=sf::Keyboard::Numpad4;
	i++;      
	comp[i]=sf::Keyboard::Numpad5;
	i++;      
	comp[i]=sf::Keyboard::Numpad6;
	i++;      
	comp[i]=sf::Keyboard::Numpad7;
	i++;      
	comp[i]=sf::Keyboard::Numpad8;
	i++;      
	comp[i]=sf::Keyboard::Numpad9;
	i++;      
	comp[i]=sf::Keyboard::F1;
	i++;           
	comp[i]=sf::Keyboard::F2;
	i++;           
	comp[i]=sf::Keyboard::F3;
	i++;           
	comp[i]=sf::Keyboard::F4;
	i++;           
	comp[i]=sf::Keyboard::F5;
	i++;           
	comp[i]=sf::Keyboard::F6;
	i++;           
	comp[i]=sf::Keyboard::F7;
	i++;           
	comp[i]=sf::Keyboard::F8;
	i++;           
	comp[i]=sf::Keyboard::F9;
	i++;           
	comp[i]=sf::Keyboard::F10;
	i++;          
	comp[i]=sf::Keyboard::F11;
	i++;          
	comp[i]=sf::Keyboard::F12;
	i++;          
	comp[i]=sf::Keyboard::F13;
	i++;          
	comp[i]=sf::Keyboard::F14;
	i++;          
	comp[i]=sf::Keyboard::F15;
	i++;          
	comp[i]=sf::Keyboard::Pause;
	i++;           
	
	pos.x = 0;
	pos.y = 0;
	newPos.x = 0;
	newPos.y = 0;
	difference.x = 0;
	difference.y = 0;
}


SFML_Input::~SFML_Input(void)
{
}

bool SFML_Input::isPressed(Keyboard::Key key)
{
	return(sf::Keyboard::isKeyPressed(comp[key]));
}

bool SFML_Input::isPressed(Mouse::Button but)
{
	return(sf::Mouse::isButtonPressed(but_comp[but]));
}

void SFML_Input::lockMouse()
{
	mouseLock = true;
}

void SFML_Input::ReleaseMouse()
{
	mouseLock = false;
}

void SFML_Input::setMouse(int x, int y)
{
	pos.x = x;
	pos.y = y;
}
void SFML_Input::getMouse(int &x, int &y)
{
	//sf::Vector2<int> currentPos = sf::Mouse::getPosition();
	x = sf::Mouse::getPosition().x;
	y = sf::Mouse::getPosition().y;
}

//this function could be wrong in terms of its movement of mouse
void SFML_Input::getMouseVec(int &x, int &y)
{
	newPos = sf::Mouse::getPosition();

	//std::cout<< "X: " << x << " | Y: " << y <<std::endl;
	/*
	if(mouseLock == true)
	{
		difference = pos - newPos;
		//difference = newPos - pos;
		sf::Mouse::setPosition(pos);
	}
	else
	{
		difference = oldPos - newPos;
		//difference = newPos - pos;
		oldPos = newPos;
	}
	*/
	x = difference.x;
	y = difference.y;
	//std::cout<< "X: " << x << " | Y: " << y <<std::endl;
}

void SFML_Input::mouseUpdate()
{
	newPos = sf::Mouse::getPosition();

	if(mouseLock  == true)
	{
		difference = pos - newPos;
		sf::Mouse::setPosition(pos);
	}
	else
	{
		difference = oldPos - newPos;
		oldPos = newPos;
	}
}
