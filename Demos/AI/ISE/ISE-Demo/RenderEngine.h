#pragma once
#include "Render.h"
#include "Window.h"
#include <string>
#include "Axis.h"
#include "Texture.h"
#include "VAO.h"
#include "Camera.h"

/**
 * @brief Render Engine
 * @details Brings all of the render components together
 * @author Umar Badat
 * @author 
 * 
 */
class RenderEngine
{
public:
	RenderEngine(void);
	~RenderEngine(void);

	//window interactions
	//create window and make it the active opengl context (dont let them have multiple)
	//set Depth buffer to true, light to false
	/**
	 * @brief create the window
	 * @details Create a Window with the valuse specified
	 * 
	 * @param width int width of the window
	 * @param height int height of the window
	 * @param name the name that appears on the window
	 */
	void create(int width, int height, std::string name);

	/**
	 * @brief swap buffers
	 * @details display all the gl calls to the window
	 */
	void display();

	/**
	 * @brief get Width of the window
	 * @return int width of the window
	 */
	int getWidth();

	/**
	 * @brief set the Width of the window
	 * @details sets the width of the window
	 */
	void setWidth(int w);

	/**
	 * @brief Get the height of the window
	 * @return int height
	 */
	int getHeight();

	/**
	 * @brief set the Height of the window
	 * @details sets the height of the window
	 */
	void setHeight(int h);

	/**
	 * @brief set the title of the window
	 * @details set the  name or title of the window
	 */
	void setTitle(std::string t);

	/**
	 * @brief set window position
	 * @details Set the window position on the screen
	 * 
	 * @param x int x position
	 * @param y int y position
	 */
	void setWinPos(int x,int y);
	
	/**
	 * @brief get the position of thw window
	 * @details Get the position of the window on screen
	 * 
	 * @param x address of x is assigned the window position
	 * @param y address of y is assigned the window position
	 */
	void getWinPos(int &x,int &y);

	/**
	 * @brief set the depth buffer on or off
	 * @details [long description]
	 * 
	 * @param on true to turn the depth buffer on
	 */
	void setDepth(bool on);

	/**
	 * @brief get the depth buffer state (on or off)
	 * @return bool, true if it is on
	 */
	bool getDepth();

	/**
	 * @brief set Light
	 * @details set light on or off with true being on
	 * 
	 * @param on boolean true for on false for off
	 */
	void setLighting(bool on);

	/**
	 * @brief get the state of light
	 * @details Get the current state of light
	 * @return bool true = on false = off
	 */
	bool getLighting();

	//true if it is focus
	/**
	 * @brief check if the window has focus or not
	 * @return true if the window is currently selected
	 */
	bool getFocus();
	
	//call display, update, get focus,
	/**
	 * @brief update the event calls
	 */
	void update();

	//********************************
	//render Functions

	/**
	 * @brief apply translation to next render
	 * @details Apply this translation to the next render
	 * 
	 * @param x translation across x
	 * @param y translation across y
	 * @param z translation across z
	 */
	void translate(float x, float y, float z);

	/**
	 * @brief rotation
	 * @details rotation on a certain axis depending on axis
	 * 
	 * @param axis and enum specifying the rotation axis
	 * @param angle what angle do you want to rotate at
	 */
	void rotate(Axis axis, float angle);

	/**
	 * @brief scale
	 * @details This scales the next draw object in on each direction by the specified number,
	 *  If a number less then 0 is given it will be set to 1 (no scale). it enable and disables the normalization depending on if this has been called
	 *
	 * @param x scale on x
	 * @param y scale on y
	 * @param z scale on z
	 *
	 */
	 void scale(float x, float y, float z);

	/**
	 * @brief set wireframe
	 * @details set the wireframe to true or false
	 * 
	 * @param enable true = turn on wireframe
	 */
	void setWireFrame(bool enable);//true means on

	/**
	 * @brief get wireframe
	 * @details get the wireframe condition
	 */
	bool getWireFrame();

	/**
	 * @brief use texture
	 * @details bind this texture to the next render object
	 * 
	 * @param tex address of a Texture object
	 */
	void bindTex(Texture &tex);

	//void setColour(float R, float G, float B);

	/**
	 * @brief render object
	 * @details Take in a VAO and render it using the values specified before
	 * 
	 * @param data address of a VAO  to render
	 */
	void renderV(VAO &data);

	/**
	 * @brief set camera position
	 * @details Takes three floats and sets the camera's position in the world
	 * 
	 * @param floats representing the camera coordinates
	 */
	void setCameraPosition(float x, float y, float z);

	/**
	 * @brief get camera position
	 * @details Get the camera's x coordinate
	 * @return float x
	 */
	float getCameraPositionX();

	float getCameraPositionY();

	float getCameraPositionZ();

	void setCameraFocus(float x, float y, float z);

	float getCameraFocusX();

	float getCameraFocusY();

	float getCameraFocusZ();

	void setCameraUp(float x, float y, float z);

	float getCameraUpX();

	float getCameraUpY();

	float getCameraUpZ();

	void setCameraMode(Camera::cameraMode m);

	void moveCameraForward(float x);

	void moveCameraLeft(float x);

	void moveCameraUp(float x);

	void rotateCameraUp(float x);

	void rotateCameraLeft(float x);

	void setPerspective(float fov, float ratio, float cnear, float cfar);

	void setOrtho2D(float left, float right, float down, float up);

	void Ortho2DBegin();

	void Ortho2DEnd();

private:
	Window window;
	Render render;
	Camera camera;

	bool depth;
	bool Light;
	bool focus;
	bool ret;
	bool wireframe;
};

