#pragma once

#include <string>
#include "SFML_Texture.h"

/**
 * @brief Loads in the texture from a file
 * @details This class handles loading all the textures and Binding them to openGL
 * @return N/A
 * @author Umar Badat
 * @note Because it was not possible to seperate the sfml Texture into a data structure of my own. I could not seperate the functionality from the data so the texture could not be done independantly of the texture object
 * 
 */
class Texture
{
public:
	Texture(void);
	~Texture(void);

	/**
	 * @brief Load in texture from the a location
	 * @details Loads in a texture from the given location and stores the texture data within this class. binding is a function from within this class as well
	 * 
	 * 	
	 * @param location A string to the location of the data
	 * @note It would have been nice to seperate the data from the function so I could keep components sperated
	 */
	void load(std::string location);

	/**
	 * @brief bind the texture
	 * @details Bind the Texture stored in this class to any polygons drawn after it
	 * @note It might be an idea to find the gluInts so i can manage the memory and reduce a need to pass large objects around.
	 */
	void bind();

	void setrepeatable(bool rp);

private:
	SFML_Texture m_texture;

};

