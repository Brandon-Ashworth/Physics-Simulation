#pragma once

#include <SFML\Window.hpp>
#include "Key.h"

/**
 * @brief The Facade of the input portion of SFML
 * @details This is the sperate facade for inputs only
 * @author Umar Badat
 * @note This facade provides both keyboard inputs and mouse, controller support would be something to 
 * look to add in the future.
 */
class SFML_Input
{
public:
	SFML_Input(void);
	~SFML_Input(void);
	
	/**
	 * @brief checks if a key from th keyboard is pressed
	 * @details An enum is taken in representing the key input to check and a boolean is returned if that key is being pressed
	 * 
	 * @param key An enum representing the keys on a keyboard
	 * @return boolean if it is pressed or not
	 */
	bool isPressed(Keyboard::Key key);

	/**
	 * @brief Check if a mouse button is pressed
	 * @details Check if a mouse button is pressed has support for 5 mouse buttons
	 * 
	 * @param but an enum representing the buttons on a mouse
	 * @return boolean if it is pressed or not
	 */
	bool isPressed(Mouse::Button but);


	//mouse things
	/**
	 * @brief Lock the mouse to the position specified by the setMouse(int x,int y) function
	 * @details sets the mouse back to a position specifiec by the client, default is given 0,0
	 */
	void lockMouse();

	/**
	 * @brief release the mouse from its lock
	 * @details Stops the mouse from being locked
	 */
	void ReleaseMouse();

	/**
	 * @brief Set the mouse position for when it is being locked
	 * @details Sets the mouse to the position when lockNouse() called
	 * 
	 * @param x int, Rrepresenting a position on screen
	 * @param y int, Represengint a position on screen
	 */
	void setMouse(int x, int y);

	/**
	 * @brief Get the mouse position
	 * @details Gets the current position of the mouse on the screen
	 * 
	 * @param x int passed in and the x value is asssigned to it
	 * @param y int passed in and the y value is asssigned to it
	 */
	void getMouse(int &x, int &y);

	//at the monement it only returns the difference between setPosition and current position
	/**
	 * @brief Returns the difference be
	 * @details [long description]
	 * 
	 * @param x [description]
	 * @param y [description]
	 */
	void getMouseVec(int &x, int &y);//get the movement from the last frame call to this one

	/**
	 * @brief Should be called every itteration.
	 * 
	 * @details This function keeps the mouse position in check so when the mouse vector function is called it can properly tell you the movement
	 */
	void mouseUpdate();//this function keeps the mouse in position mostly but does update the movement


private:
	sf::Keyboard::Key comp[Keyboard::KeyCount];
	sf::Mouse::Button but_comp[Mouse::ButtonCount];
	sf::Mouse mouse;

	sf::Vector2<int> pos; // the position is should reset to every time
	sf::Vector2<int> oldPos;// the old position
	bool mouseLock;
	sf::Vector2<int> newPos;
	sf::Vector2<int> difference;
};