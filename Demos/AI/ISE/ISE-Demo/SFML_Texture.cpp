#include "SFML_Texture.h"


SFML_Texture::SFML_Texture(void)
{
	
}


SFML_Texture::~SFML_Texture(void)
{
}

void SFML_Texture::load(std::string location)
{
	m_texture.loadFromFile(location);
}

void SFML_Texture::bind()
{
	sf::Texture::bind(&m_texture);
}

void SFML_Texture::setrepeatable(bool rp)
{
	m_texture.setRepeated(rp);
}

