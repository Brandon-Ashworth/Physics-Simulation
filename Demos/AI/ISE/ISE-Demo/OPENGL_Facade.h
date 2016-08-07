#pragma once

#include <SFML\OpenGL.hpp>
#include "VAO.h"

class OPENGL_Facade
{
public:
	OPENGL_Facade(void);
	~OPENGL_Facade(void);

	//these fucions are here to initialise the open gl thing needs to be called first
	//disables lighting, clears color and depth
	//clears the colour and depth
	/**
	 * @brief Specifies the Color you write to when you clear the buffer bit
	 * @details When you call the function clear color buffer bit it sets it to the colour specified here
	 * 
	 * @param R float representing the red value
	 * @param G float representing the green value
	 * @param B float representing the blue value
	 * @return true, to show it completed the function
	 */
	static bool colour(float R, float G, float B);

	/**
	 * @brief Clear the Depth buffer
	 * @details Clears the Depth buffer with a float specified by the user
	 * 
	 * @param Depth float
	 * @return true, if completed successfully 
	 */
	static bool Depth(float Depth);

	/**
	 * @brief calls two other functions with pre-defined values
	 * @details Calls Colour(float R, float G, float B) and Depth(float Depth) with some predefined values. This call should be enough for most users
	 * @return true, if the function completed successfully
	 */
	static bool colourDepth();

	//enable and disable depth and the mask as well
	/**
	 * @brief Enables Depth
	 * @details Enables the depth buffer and depth mask to allow for 3d rendering
	 * @return true, if the function completed successfully 
	 */
	static bool enableDepth();

	/**
	 * @brief Disables Depth
	 * @details Disables the Depth buffer and depth mask so that the user can no loger render in 3D
	 * @return true, if the function completed successfully
	 */
	static bool disableDepth();

	//Lighting, enable or disable
	/**
	 * @brief enables Lighting
	 * @details Enables Lighting in openGL
	 * @return true if completed successfully
	 * @note Though the function to enable lighting is provided no actual lights can be made without using direct openGL, this function was not goignt to be used but it is here for future expansions
	 */ 
	static bool enableLighting();

	/**
	 * @brief Disables Lighting
	 * @details Disables the lighting in opengl
	 * @return true, if completed successfully
	 * @note As mentioned in the enables lighting function no actual way to create lights are provided.
	 */
	static bool disableLighting();


	//matrix mode's should always be left on model view, just changes the matrix 
	//(internal commands should push and pop the matrix to aloow the user to not have to change anything
	//after it has been changed by us, eg no useless calls to this class.
	
	/**
	 * @brief Sets the matrix mode to model view
	 * @details Sets the matrix mode to model view and loads the identity
	 * @return bool depending on if the action completed (always returns true);
	 * 
	 * @note ModelView Matrix shoul always be left on not the projection matrix
	 */
	static bool ModelMatrix();

	/**
	 * @brief sets the matrix mode to Porjection
	 * @details Sets the matrix mode to projectiong and calls LoadIdentity
	 * @return bool true if it succeeded
	 * @note matrix mode should be left as the default becuase projection is only used for very specific cases
	 */
	static bool ProjectionMatrix();

	
	 
	
	
	

	//enable projectiong matrix use push and pop, load ideentity

	/**
	 * @brief Sets the Perspective
	 * @details Push's the Matrix, changes to the Projection Matrix makes the change Switches to the modelview matrix and pops it back off the stack
	 * 
	 * @param fov float representing the field of view
	 * @param apect float representing the aspect ratio. this is usually obtained by the window width divided by height (width/height)
	 * @param zNear float specifying the zNear plane, this must be a positive number (usually 1)
	 * @param zFar [description]
	 * @return bool 
	 */
	static bool perspective(float fov, float apect, float zNear, float zFar);

	//viewport, cos the first 2 values are always 0 we will not let them input (case they screw up)
	//the default matrix mode is modelview
	/**
	 * @brief Adjust the viewport (not window size)
	 * @details This function allows the user to adjust the view port of the opengl rendered window
	 * 
	 * @param width takes in the new width of the windw
	 * @param height Takes in the new height of the window
	 * 
	 * @return true, if functions completed successfully
	 */
	static bool viewport(int width, int height);

	//push and pop matrix usually only called from within the class
	/**
	 * @brief push the current matrix onto the stack
	 * @details Push the current OpenGL matrix onto the stack so rotate and translate can be called just for particular objects
	 * @return true, if completed successfully
	 */
	static bool pushMatrix();

	/**
	 * @brief pop a matrix off the stack
	 * @details Pop the matrix off the stack in openGL and replace it with the one you currently have
	 * @return true, if completed successfully
	 */
	static bool popMatrix();

	//rotation and translation******************************
	/**
	 * @brief apply a rotation to the world
	 * @details Apply a rotation to the world so all points draw from now on will use that
	 * 
	 * @param angle float, The rotation to be applied numbers from 0-360 will have unique effects
	 * @param xAxis float, If 1 used This is rotation axis
	 * @param yAxis float, If 1 used This is rotation axis
	 * @param zAxis float, If 1 used This is rotation axis
	 * @return true, if completed successfully
	 */
	static bool rotate(float angle, float xAxis, float yAxis, float zAxis);

	/**
	 * @brief applies and transformation to the world
	 * @details Specifies a new Zero point so all thigns are draw relative to that point instead of the old one
	 * 
	 * @param xAxis float, representing the movement along that Axis
	 * @param yAxis float, representing the movement along that Axis
	 * @param zAxis float, representing the movement along that Axis
	 * @return true, if fucntion completed successfully
	 */
	static bool transform(float xAxis, float yAxis, float zAxis);

	/**
	 * @brief Scales the world
	 * @details Applies a Scale to the world so all objects are draw to the new sizes base on the scale
	 * 
	 * @param xAxis The Scale to be applied in the xAxis
	 * @param yAxis The Scale to be applied in the yAxis
	 * @param zAxis The Scale to be applied in the zAxis
	 * @return true, if completed successfully
	 */
	static bool scale(float xAxis, float yAxis, float zAxis);

	//Wire Frame
	/**
	 * @brief Sets OpenGL to render wireframe
	 * 
	 */
	static void enableWire();

	/**
	 * @brief Sets openGL to render PolyGon
	 *
	 */
	static void disableWire();

	//render VAO's
	/**
	 * @brief tells openGLto render this VAO
	 * @details Sends a VAO ot openGL to render as a vertex array object
	 * 
	 * @param data A VAO
	 */
	static void render(VAO &data);

	//polygon color
	/**
	 * @brief Sets the polygon colour 
	 * @details This function sets the polygon colour in case we don't have atexture and just want a coloured object
	 * 
	 * @param R float, Representing the Red value
	 * @param G float, Representing the Green value
	 * @param B float, Representing the Blue value
	 */
	static void polyColour(float R, float G, float B);

	//texture
	/**
	 * @brief Enable Texture
	 * @details Enable Texture 2D in the openGL environment
	 */
	static void enableTexture();

	/**
	 * @brief Disables Textture
	 * @details Disables texture 2D in the openGl environment
	 */
	static void disableTexture();

	/**
	* @brief update
	* @ needs to be called every loop
	*/
	static void update();

	/**
	* @brief right and top are the window width and height
	*
	*
	*/
	static void ortho2DRender(int left, int right,int bottom, int top);

	/**
	* @brief specify the width and height of the window (ortho will use 0 as some default values
	*
	*/
	static void ortho2DRender(int width, int height);


	static void Normalize(bool norm);


};

//re do this all functions should be called from the init