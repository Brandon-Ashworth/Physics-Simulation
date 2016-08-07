#pragma once

#include "GameObject2.h"

class Model: public GameObject2
{
public:
	Model();
	std::string getTexture();
	void setTexture(std::string t);
	std::string getModel();
	void setModel(std::string m);
	bool getStatus();
	void setStatus(bool s);

private:
	std::string m_Texture;
	std::string m_Model;
	bool m_Status;
};