#pragma once

#include "OPENGL_Facade.h"
#include "SFML_Facade.h"

class Window
{
public:
	//for a non existant window
	Window(void);
	~Window(void);

	//takes in a window and makes all the values
	/**
	 * @brief copy a window in so both use the same address 
	 * @details this functio was intended for seperating the input 
	 * from the render engine while still having access to the events
	 * 
	 * @param window SFML_Facade window
	 * @deprecated This function is no longer used, there are better ways to get the 
	 * key inputs from the user
	 */
	Window(SFML_Facade window);//{m_win = &window;}///set created to true


	//needs to do the viewport, clear the color and depth, disable lighting, enable depth
	/**
	 * @brief create a window
	 * @details create a window with a name width and heigh specified upon creation
	 * 
	 * @param width int
	 * @param height int
	 * @param name string
	 */
	void create(int width, int height, std::string name);

	/**
	 * @brief set this window's width and height
	 * @details the width and height of this window is set by two numbers
	 * 
	 * @param width int
	 * @param height int
	 */
	void setWidthHeight(int width, int height);

	/**
	 * @brief set this window's width
	 * @details the width of this window is set here
	 * 
	 * @param width int
	 */
	void setWidth(int width);

	/**
	 * @brief set this window's height
	 * @details the height of this window is set here
	 * 
	 * @param height int
	 */
	void setHeight(int height);

	/**
	 * @brief set this window's title
	 * @details the title of this window is set here
	 * 
	 * @param name string
	 */
	void setTitle(std::string name);

	/**
	 * @brief set this window to the active opengl context
	 * @details This window is now going to have all opengl calls applied to it
	 */
	void active();

	/**
	 * @brief swap buffers
	 * @details display all the openGL calls that have been called
	 */
	void display();

	/**
	 * @brief get width
	 * @details get the width of the window
	 * @return int width
	 */
	int getWidth();

	/**
	 * @brief ge height
	 * @details get th height of the window
	 * @return int height
	 */
	int getHeight();

	//set window width and height change the matrix mode and viewport

	//manual set the depth buffer on or off
	/**
	 * @brief enable depth items
	 * @details Enable depths test and depth mask
	 */
	void enableDepth();

	/**
	 * @brief Disable depth items
	 * @details Disable depth test and depth mask
	 */
	void disableDepth();

	//manual enable or disable lighting
	/**
	 * @brief enable light
	 * @details enable the opengl lights
	 * @bug  the functionality of this has not been implemented yet please don't use it unless you can call light
	 */
	void enableLighting();

	/**
	 * @brief disable lights
	 * @details disable the lights in opengl
	 */
	void disableLighting();

	//set the clear and depth values
	/**
	 * @brief set color and depth automatically
	 * @details [long description]
	 */
	void colourDepth();

	/**
	 * @brief set the clear colour
	 * 
	 * 
	 * @param R Red
	 * @param G Green
	 * @param B Blue
	 */
	void setColour(float R, float G, float B);

	/**
	 * @brief set depth
	 * 
	 * @param Depth depth
	 */
	void setDepth(float Depth);

	//this function is here just so that we can use inputs until the correct function is ccreated
	/**
	 * @brief Get events function
	 * @details This function was used to get to the window so you can poll it
	 * @return sf::Event
	 * @deprecated This function is no longer used it has been replaced by a better engine
	 */
	sf::Window* getEvent() {return(m_Win->getEvent());}

	void update(); // this function needs to bee called every loop in order to allow proper updates to take place

	/**
	 * @brief set window position
	 * @details set the window positio on the screen
	 * 
	 * @param x int x position on screen
	 * @param y int y position on screen
	 */
	void setWindowPos(int x, int y);

	/**
	 * @brief get window position
	 * @details get window position on screenn
	 * 
	 * @param x int pass in address the value is then assigned to it
	 * @param y int pass in address the value is then assigned to it
	 */
	void getWindowPos(int &x, int &y);

	//broken function
	/**
	 * @brief get focus is a broken function, will be fixed for the next release
	 * @details [long description]
	 * @return [description]
	 */
	//bool getFocus(); //return true if it has focus

private:
	SFML_Facade *m_Win;
	bool created;
	bool focus;

	float m_width;
	float m_height;
	std::string m_name;
};

