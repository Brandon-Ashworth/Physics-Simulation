#pragma once

#include<SFML\Window.hpp>

#include <string>

/**
 * @brief The Facade of SFML
 * @details This class provides a Facade between some components in our engine and SFML
 * @author Umar Badat
 * @note Some Functions are not used in this class, while others may have been split down furthure.
 */
class SFML_Facade
{
public:
	SFML_Facade(void);
	~SFML_Facade(void);

	/**
	 * @brief Create a Window
	 * @details Creates a window for the user
	 * 
	 * @param width int, Representing the Width of the window
	 * @param height int, Representing the Height of the window
	 * @param name std::string, Representing the Name of the window
	 * @return true, if Succeeded 
	 */
	bool win_Create(int width,int height,std::string name);//create the window

	/**
	 * @brief Set the window as the active openGL context
	 * @details Sets the Window as the current openGL context so alll openGL commands will be performed here
	 * @return true, if completed successfully
	 */
	bool win_active();//sets window as opengl render context

	/**
	 * @brief Display all the draws between the previous render the the current one
	 * @details Swaps the Buffer's 
	 */
	void win_display();//swaps the buffer increase speed i think


	/**
	 * @brief Get the Window Width
	 * 
	 * @return int representing the Width of the window
	 */
	int win_getWidth();//get the window width

	/**
	 * @brief Get the Height of the window
	 * 
	 * @return int Representing the Height of the window
	 */
	int win_getHeight();//get window height
	
	//poll event
	/**
	 * @brief returns the event log from sfml
	 * @details Returns the Event log from sfml
	 * @return sf::Window* returns the window so polling can take place
	 * @note This function was initially used for testing and a possible way to poll for keyBoard events. 
	 * The issue is that the input events are locked to the window that was created. this is a limitation by most operating systems
	 * The best way to resolve it would be to pass the window or find another method of input
	 * 
	 * @deprecated This fuction is no longer needed as a better way was found and implemented in the input engine
	 */
	sf::Window* getEvent() {return window;};

	



	 //new additions near the end (focus and position)
	/**
	 * @brief Sets the window Position
	 * @details Sets the window to a position on the screen 
	 * 
	 * @param x int, The position in the X plane
	 * @param y [description]
	 */
	void setWindowPos(int x, int y);

	/**
	 * @brief Gets the window position
	 * @details Gets the window position
	 * 
	 * @param x int, Pass in an int and the x position is assigned to it
	 * @param y int, Pass in an int and the y position is assigned to it
	 */
	void getWindowPos(int &x, int &y);

	//return true if this window is the current focus
	/**
	 * @brief Gets current focus of the window
	 * @details If the window is the current focussed window in windows, it will be true
	 * @return true, if this window is the one currently selected
	 */
	bool getFocus();

	/**
	 * @brief Gets if the window has been resized
	 *
	 * @return true, if the window has been resized
	 */
	bool getReshape();

	/**
	 * @brief Gets the information from the window facade
	 * @details Polls for events from the window part
	 * @note As mentioned before there are certain limitations with input and events when it comes to almost all operating systems
	 */
	void update();



private:
	 sf::Window *window;
	 bool focus;

};

