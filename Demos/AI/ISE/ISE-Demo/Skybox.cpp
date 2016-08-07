#include "Skybox.h"



Skybox::Skybox()
{
	setSize(5000.0);
	m_pos.x = 0.0;
	m_pos.y = 0.0;
	m_pos.z = 0.0;
	m_locations[0] = "";
	m_locations[1] = "";
	m_locations[2] = "";
	m_locations[3] = "";
	m_locations[4] = "";
	m_locations[5] = "";
}

Skybox::~Skybox()
{

}

void Skybox::setSize(float s)
{
	m_size = s;
	VAO* tempVAO;
	tempVAO = new VAO;

	// ----- top -----
	
	float tempFloat[18] = {m_pos.x - (m_size / 2.0), m_pos.y + (m_size / 2.0), m_pos.z + (m_size / 2.0),
		                   m_pos.x + (m_size / 2.0), m_pos.y + (m_size / 2.0), m_pos.z - (m_size / 2.0),
	                       m_pos.x - (m_size / 2.0), m_pos.y + (m_size / 2.0), m_pos.z - (m_size / 2.0),

	                       m_pos.x - (m_size / 2.0), m_pos.y + (m_size / 2.0), m_pos.z + (m_size / 2.0),
						   m_pos.x + (m_size / 2.0), m_pos.y + (m_size / 2.0), m_pos.z + (m_size / 2.0),
						   m_pos.x + (m_size / 2.0), m_pos.y + (m_size / 2.0), m_pos.z - (m_size / 2.0)};

	tempVAO->vertexArray = new float[18];
	for(int i = 0; i < 18; i++)
	{
		tempVAO->vertexArray[i] = tempFloat[i];
	}

	float tempNorm[9] = {0.0, -1.0, 0.0,
						 0.0, -1.0, 0.0,
	                     0.0, -1.0, 0.0};

	tempVAO->normalArray = new float[9];
	for(int i = 0; i < 9; i++)
	{
		tempVAO->normalArray[i] = tempNorm[i];
	}

	tempVAO->numVerts = 6;

	float tempUV[12] = {0.0, 0.0,
	                   1.0, 1.0,
	                   0.0, 1.0,
	                   
	                   0.0, 0.0,
	                   1.0, 0.0,
	                   1.0, 1.0};

	tempVAO->uvArray = new float[12];
	for(int i = 0; i < 12; i++)
	{
		tempVAO->uvArray[i] = tempUV[i];
	}

	m_skybox[0] = *tempVAO;

	// ----- front -----

	tempFloat[0] = m_pos.x - (m_size / 2.0);
	tempFloat[1] = m_pos.y - (m_size / 2.0);
	tempFloat[2] = m_pos.z + (m_size / 2.0);

	tempFloat[3] = m_pos.x + (m_size / 2.0);
	tempFloat[4] = m_pos.y + (m_size / 2.0);
	tempFloat[5] = m_pos.z + (m_size / 2.0);

	tempFloat[6] = m_pos.x - (m_size / 2.0);
	tempFloat[7] = m_pos.y + (m_size / 2.0);
	tempFloat[8] = m_pos.z + (m_size / 2.0);



	tempFloat[9] = m_pos.x - (m_size / 2.0);
	tempFloat[10] = m_pos.y - (m_size / 2.0);
	tempFloat[11] = m_pos.z + (m_size / 2.0);

	tempFloat[12] = m_pos.x + (m_size / 2.0);
	tempFloat[13] = m_pos.y - (m_size / 2.0);
	tempFloat[14] = m_pos.z + (m_size / 2.0);
	
	tempFloat[15] = m_pos.x + (m_size / 2.0);
	tempFloat[16] = m_pos.y + (m_size / 2.0);
	tempFloat[17] = m_pos.z + (m_size / 2.0);

	for(int i = 0; i < 18; i++)
	{
		tempVAO->vertexArray[i] = tempFloat[i];
	}
	
	tempNorm[0] = 0.0;
	tempNorm[1] = 0.0;
	tempNorm[2] = -1.0;
	tempNorm[3] = 0.0;
	tempNorm[4] = 0.0;
	tempNorm[5] = -1.0;
	tempNorm[6] = 0.0;
	tempNorm[7] = 0.0;
	tempNorm[8] = -1.0;

	for(int i = 0; i < 9; i++)
	{
		tempVAO->normalArray[i] = tempNorm[i];
	}

	tempVAO->numVerts = 6;

	m_skybox[1] = *tempVAO;

	// ----- back -----

	tempFloat[0] = m_pos.x + (m_size / 2.0);
	tempFloat[1] = m_pos.y - (m_size / 2.0);
	tempFloat[2] = m_pos.z - (m_size / 2.0);

	tempFloat[3] = m_pos.x - (m_size / 2.0);
	tempFloat[4] = m_pos.y + (m_size / 2.0);
	tempFloat[5] = m_pos.z - (m_size / 2.0);

	tempFloat[6] = m_pos.x + (m_size / 2.0);
	tempFloat[7] = m_pos.y + (m_size / 2.0);
	tempFloat[8] = m_pos.z - (m_size / 2.0);



	tempFloat[9] = m_pos.x + (m_size / 2.0);
	tempFloat[10] = m_pos.y - (m_size / 2.0);
	tempFloat[11] = m_pos.z - (m_size / 2.0);

	tempFloat[12] = m_pos.x - (m_size / 2.0);
	tempFloat[13] = m_pos.y - (m_size / 2.0);
	tempFloat[14] = m_pos.z - (m_size / 2.0);
	
	tempFloat[15] = m_pos.x - (m_size / 2.0);
	tempFloat[16] = m_pos.y + (m_size / 2.0);
	tempFloat[17] = m_pos.z - (m_size / 2.0);

	for(int i = 0; i < 18; i++)
	{
		tempVAO->vertexArray[i] = tempFloat[i];
	}
	
	tempNorm[0] = 0.0;
	tempNorm[1] = 0.0;
	tempNorm[2] = 1.0;
	tempNorm[3] = 0.0;
	tempNorm[4] = 0.0;
	tempNorm[5] = 1.0;
	tempNorm[6] = 0.0;
	tempNorm[7] = 0.0;
	tempNorm[8] = 1.0;

	for(int i = 0; i < 9; i++)
	{
		tempVAO->normalArray[i] = tempNorm[i];
	}

	tempVAO->numVerts = 6;

	m_skybox[2] = *tempVAO;

	// ----- left -----

	tempFloat[0] = m_pos.x - (m_size / 2.0);
	tempFloat[1] = m_pos.y - (m_size / 2.0);
	tempFloat[2] = m_pos.z - (m_size / 2.0);

	tempFloat[3] = m_pos.x - (m_size / 2.0);
	tempFloat[4] = m_pos.y + (m_size / 2.0);
	tempFloat[5] = m_pos.z + (m_size / 2.0);

	tempFloat[6] = m_pos.x - (m_size / 2.0);
	tempFloat[7] = m_pos.y + (m_size / 2.0);
	tempFloat[8] = m_pos.z - (m_size / 2.0);



	tempFloat[9] = m_pos.x - (m_size / 2.0);
	tempFloat[10] = m_pos.y - (m_size / 2.0);
	tempFloat[11] = m_pos.z - (m_size / 2.0);

	tempFloat[12] = m_pos.x - (m_size / 2.0);
	tempFloat[13] = m_pos.y - (m_size / 2.0);
	tempFloat[14] = m_pos.z + (m_size / 2.0);
	
	tempFloat[15] = m_pos.x - (m_size / 2.0);
	tempFloat[16] = m_pos.y + (m_size / 2.0);
	tempFloat[17] = m_pos.z + (m_size / 2.0);

	for(int i = 0; i < 18; i++)
	{
		tempVAO->vertexArray[i] = tempFloat[i];
	}
	
	tempNorm[0] = 1.0;
	tempNorm[1] = 0.0;
	tempNorm[2] = 0.0;
	tempNorm[3] = 1.0;
	tempNorm[4] = 0.0;
	tempNorm[5] = 0.0;
	tempNorm[6] = 1.0;
	tempNorm[7] = 0.0;
	tempNorm[8] = 0.0;

	for(int i = 0; i < 9; i++)
	{
		tempVAO->normalArray[i] = tempNorm[i];
	}

	tempVAO->numVerts = 6;

	m_skybox[3] = *tempVAO;

	// ----- right -----

	tempFloat[0] = m_pos.x + (m_size / 2.0);
	tempFloat[1] = m_pos.y - (m_size / 2.0);
	tempFloat[2] = m_pos.z + (m_size / 2.0);

	tempFloat[3] = m_pos.x + (m_size / 2.0);
	tempFloat[4] = m_pos.y + (m_size / 2.0);
	tempFloat[5] = m_pos.z - (m_size / 2.0);

	tempFloat[6] = m_pos.x + (m_size / 2.0);
	tempFloat[7] = m_pos.y + (m_size / 2.0);
	tempFloat[8] = m_pos.z + (m_size / 2.0);



	tempFloat[9] = m_pos.x + (m_size / 2.0);
	tempFloat[10] = m_pos.y - (m_size / 2.0);
	tempFloat[11] = m_pos.z + (m_size / 2.0);

	tempFloat[12] = m_pos.x + (m_size / 2.0);
	tempFloat[13] = m_pos.y - (m_size / 2.0);
	tempFloat[14] = m_pos.z - (m_size / 2.0);
	
	tempFloat[15] = m_pos.x + (m_size / 2.0);
	tempFloat[16] = m_pos.y + (m_size / 2.0);
	tempFloat[17] = m_pos.z - (m_size / 2.0);

	for(int i = 0; i < 18; i++)
	{
		tempVAO->vertexArray[i] = tempFloat[i];
	}
	
	tempNorm[0] = -1.0;
	tempNorm[1] = 0.0;
	tempNorm[2] = 0.0;
	tempNorm[3] = -1.0;
	tempNorm[4] = 0.0;
	tempNorm[5] = 0.0;
	tempNorm[6] = -1.0;
	tempNorm[7] = 0.0;
	tempNorm[8] = 0.0;

	for(int i = 0; i < 9; i++)
	{
		tempVAO->normalArray[i] = tempNorm[i];
	}

	tempVAO->numVerts = 6;

	m_skybox[4] = *tempVAO;

	// ----- bottom -----

	tempFloat[0] = m_pos.x - (m_size / 2.0);
	tempFloat[1] = m_pos.y - (m_size / 2.0);
	tempFloat[2] = m_pos.z - (m_size / 2.0);

	tempFloat[3] = m_pos.x + (m_size / 2.0);
	tempFloat[4] = m_pos.y - (m_size / 2.0);
	tempFloat[5] = m_pos.z + (m_size / 2.0);

	tempFloat[6] = m_pos.x - (m_size / 2.0);
	tempFloat[7] = m_pos.y - (m_size / 2.0);
	tempFloat[8] = m_pos.z + (m_size / 2.0);



	tempFloat[9] = m_pos.x - (m_size / 2.0);
	tempFloat[10] = m_pos.y - (m_size / 2.0);
	tempFloat[11] = m_pos.z - (m_size / 2.0);

	tempFloat[12] = m_pos.x + (m_size / 2.0);
	tempFloat[13] = m_pos.y - (m_size / 2.0);
	tempFloat[14] = m_pos.z - (m_size / 2.0);
	
	tempFloat[15] = m_pos.x + (m_size / 2.0);
	tempFloat[16] = m_pos.y - (m_size / 2.0);
	tempFloat[17] = m_pos.z + (m_size / 2.0);

	for(int i = 0; i < 18; i++)
	{
		tempVAO->vertexArray[i] = tempFloat[i];
	}
	
	tempNorm[0] = 0.0;
	tempNorm[1] = 1.0;
	tempNorm[2] = 0.0;
	tempNorm[3] = 0.0;
	tempNorm[4] = 1.0;
	tempNorm[5] = 0.0;
	tempNorm[6] = 0.0;
	tempNorm[7] = 1.0;
	tempNorm[8] = 0.0;

	for(int i = 0; i < 9; i++)
	{
		tempVAO->normalArray[i] = tempNorm[i];
	}

	tempVAO->numVerts = 6;

	m_skybox[5] = *tempVAO;
}

float Skybox::getSize()
{
	return m_size;
}

void Skybox::setX(float x)
{
	m_pos.x = x;
}

void Skybox::setY(float y)
{
	m_pos.y = y;
}

void Skybox::setZ(float z)
{
	m_pos.z = z;
}

float Skybox::getX()
{
	return m_pos.x;
}

float Skybox::getY()
{
	return m_pos.y;
}

float Skybox::getZ()
{
	return m_pos.z;
}

VAO Skybox::getTop()
{
	return m_skybox[0];
}

VAO Skybox::getFront()
{
	return m_skybox[1];
}

VAO Skybox::getBack()
{
	return m_skybox[2];
}

VAO Skybox::getLeft()
{
	return m_skybox[3];
}

VAO Skybox::getRight()
{
	return m_skybox[4];
}

VAO Skybox::getBottom()
{
	return m_skybox[5];
}

void Skybox::setTopTexture(std::string t)
{
	m_locations[0] = t;
	m_tex[0].load(m_locations[0]);
}

std::string Skybox::getTopTexture()
{
	return m_locations[0];
}

void Skybox::setFrontTexture(std::string t)
{
	m_locations[1] = t;
	m_tex[1].load(m_locations[1]);
}

std::string Skybox::getFrontTexture()
{
	return m_locations[1];
}

void Skybox::setBackTexture(std::string t)
{
	m_locations[2] = t;
	m_tex[2].load(m_locations[2]);
}

std::string Skybox::getBackTexture()
{
	return m_locations[2];
}

void Skybox::setLeftTexture(std::string t)
{
	m_locations[3] = t;
	m_tex[3].load(m_locations[3]);
}

std::string Skybox::getLeftTexture()
{
	return m_locations[3];
}

void Skybox::setRightTexture(std::string t)
{
	m_locations[4] = t;
	m_tex[4].load(m_locations[4]);
}

std::string Skybox::getRightTexture()
{
	return m_locations[4];
}

void Skybox::setBottomTexture(std::string t)
{
	m_locations[5] = t;
	m_tex[5].load(m_locations[5]);
}

std::string Skybox::getBottomTexture()
{
	return m_locations[5];
}