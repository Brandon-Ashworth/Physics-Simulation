#pragma once
#include "VAO.h"
#include "Vector3.h"
#include "Texture.h"



class Skybox
{
public:
	Skybox();

	~Skybox();

	void setSize(float s);

	float getSize();

	void setX(float x);

	void setY(float y);

	void setZ(float z);

	float getX();

	float getY();

	float getZ();

	VAO getTop();

	VAO getFront();

	VAO getBack();

	VAO getLeft();

	VAO getRight();

	VAO getBottom();

	void setTopTexture(std::string t);

	std::string getTopTexture();

	void setFrontTexture(std::string t);

	std::string getFrontTexture();

	void setBackTexture(std::string t);

	std::string getBackTexture();

	void setLeftTexture(std::string t);

	std::string getLeftTexture();

	void setRightTexture(std::string t);

	std::string getRightTexture();

	void setBottomTexture(std::string t);

	std::string getBottomTexture();

private:
	VAO m_skybox[6];
	Texture m_tex[6];
	std::string m_locations[6];
	float m_size;
	Vector3 m_pos;
};