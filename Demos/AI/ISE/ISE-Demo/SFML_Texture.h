#pragma once

#include <string>
#include <SFML\Graphics.hpp>

/**
 * @brief Handles the textures
 * @details Stores loads and binds the texture
 * @return 
 * @author Umar Badat
 * @note This class acts as a mediator between the asset manager and sfml to ensure an easy switch if the need should arise
 */
class SFML_Texture
{
public:
	SFML_Texture(void);
	~SFML_Texture(void);

	/**
	 * @brief load a texture in
	 * @details Loads the texture into the class
	 * 
	 * @param location String storing the location
	 */
	void load(std::string location);

	/**
	 * @brief bind the texture 
	 * @details set this texture as the one to draw onto objects
	 */
	void bind();

	void setrepeatable(bool rp);
	


private:
	sf::Texture m_texture;
	
};

