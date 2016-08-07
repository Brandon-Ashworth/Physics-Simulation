#pragma once

#include "SFML_Input.h"
#include "Key.h"

/**
 * @brief The input class
 * @details This is the engine it takes in the inputs from other parts and puts them into an
 * eays to work with file.
 * 
 * @author Umar Badat
 * @note store the input and can keep track of when a button is releaed (only occurs once after it has been pressed)
 */
class Input
{
public:
	Input(void);
	~Input(void);

	//the button things
	/**
	 * @brief check is a key is pressed
	 * @details Use the enum from the key class to determin what kind of input is being checked
	 * 
	 * @param key, an Enum of the key being estted
	 * @return bool, true if it is being pressed
	 */
	bool isPress(Keyboard::Key key);

	/**
	 * @brief check if a key has been released (once occurs once after a press)
	 * 
	 * 
	 * @param key key to check
	 * @return bool if the key has been released
	 */
	bool isReleased(Keyboard::Key key);

	//mouse thing
	/**
	 * @brief check if a mouse button has been pressed
	 * @details Check if a mouse button has been pressed
	 * 
	 * @param but enum representing a key
	 * @return true if the button is being pressed
	 */
	bool isMousePress(Mouse::Button but);
	/**
	 * @brief check if a mouse button has been released
	 * @details only registers once after the key has been released
	 * 
	 * @param but an enum representing a button on the mouse
	 * @return returns true once after the button wass released
	 */
	bool isMouseReleased(Mouse::Button but);


	//mouse things
	/**
	 * @brief lock the mouse in a position
	 * @details Locks the mouse in a position set by the setMouseLockPostion(intx, int y) function;
	 */
	void lockMouse();
	/**
	 * @brief release the mouse from its lock
	 * @details releases the mouse from its locked position
	 */
	void releaseMouse();

	/**
	 * @brief Set the mouse lock position 
	 * @details When it is locked this is the position it will be set to
	 * 
	 * @param x int, position on the screen
	 * @param y int, position on the screen
	 */
	void setMouseLockPosition(int x, int y);//call setMouse

	/**
	 * @brief get the current mouse location
	 * @details Get the current mouse location in windows space (not relative to your window)
	 * 
	 * @param x address of an int, x is then assigned
	 * @param y address of an int, y is then assigned
	 */
	void getMouseLocation(int &x,int &y);

	/**
	 * @brief get the difference in movement from one call to the next
	 * @details get the vector of a movement of the mouse from one call to the next
	 * 
	 * @param x address x gives the mouses x position
	 * @param y address y gives the mouses y position
	 */
	void getMouseVec(int &x,int &y);

	/**
	 * @brief Call to keep the mouse function good
	 * @details This function keeps track of the user mouse so we can alwasy see the movement of it
	 */
	void mouseUpdate();


private:
	bool press[Keyboard::KeyCount];
	bool rel[Keyboard::KeyCount];

	bool mousePress[Mouse::ButtonCount];
	bool mouseRel[Mouse::ButtonCount];

	SFML_Input inputs;
};

