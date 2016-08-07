#pragma once

#include "Component.h"
#include "Vector3.h"
#include "Axis.h"
#include <string>

class TrueModel: public Component
{
public:
	TrueModel();
	float getPositionX();
	void setPositionX(float x);
	float getPositionY();
	void setPositionY(float y);
	float getPositionZ();
	void setPositionZ(float z);
	float getRotationX();
	float getRotationY();
	float getRotationZ();
	void setRotation(Axis axis, float angle);
	std::string getTexture();
	void setTexture(std::string t);
	std::string getModel();
	void setModel(std::string m);
	bool getStatus();
	void setStatus(bool s);

private:
	Vector3 m_Pos;
	Vector3 m_Angle;
	std::string m_Texture;
	std::string m_Model;
	bool m_Status;
};