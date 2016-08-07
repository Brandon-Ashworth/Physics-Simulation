#pragma once

#include "OPENGL_Facade.h"
#include "Texture.h"
#include "Axis.h"
/**
 * @brief The render portion of the RenderEngine
 * @details Takes values from the user like rotation transformation ect and renders them to screen
 * @author Umar Badat
 */
class Render
{
public:
	Render(void);
	~Render(void);


	/**
	 * @brief translate the next rendered model to that position
	 * @details The translation specified will be applied to the next object only
	 * 
	 * @param x float, movement along this axis
	 * @param y float, movement along this axis
	 * @param z float, movement along this axis
	 */
	void translate(float x, float y, float z);
	
	/**
	 * @brief apply a rotation matrix
	 * @details Rotate the next rendered object only
	 * 
	 * @param axis enum specifying what axis you want to rotate on
	 * @param angle float, what is the rotaion angle
	 */
	void rotate(Axis axis, float angle); // enable the correct andgle and call ect

	/**
	 * @brief Turn on or off wireframe
	 * @details Turn WireFram on or off
	 * 
	 * @param enable true, will turn wire frame on
	 */
	void setWireFrame(bool enable); //enable or disable, after the render set this back (maybe)

	/**
	 * @brief bind a texture
	 * @details Bind a texture for the next model to use as its texture
	 * 
	 * @param tex address of the Texture, which will then call the bind function
	 */
	void bindTex(Texture &tex);//bind the texture enable 2d, disable otherwise

	/**
	 * @brief set the colour for when textures are not ebing used
	 * @details use a colour
	 * 
	 * @param R red
	 * @param G green
	 * @param B blue
	 * 
	 * @bug this function is currently disabled due to falts in the code
	 */
	void setColour(float R, float G, float B);//set the base colour (after set it to white)

	/**
	 * @brief render 
	 * @details render a VAO
	 * 
	 * @param data takes in the address of a VAO and renders it with all the parameters set previously
	 * @note this will then reset all the data in previous calls except the wireframe call
	 */
	void render(VAO &data);

	void scale(float x, float y, float z);


private:
	bool rotX,rotY,rotZ;

	float angX, angY, angZ;

	bool tran;
	float tranX, tranY, tranZ;

	bool texture;

	//all the scale shit
	bool isScaled;
	float scaleX, scaleY, scaleZ;
	void scaleDefault();

	

};

