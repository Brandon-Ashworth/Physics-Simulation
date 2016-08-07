#include "GameObject.h"

HUD::HUD()
{
	m_pos.x = 0.0;
	m_pos.y = 0.0;
	m_pos.z = 0.0;
	m_translate.x = 0.0;
	m_translate.y = 0.0;
	m_translate.z = 0.0;
	m_angle.x = 0.0;
	m_angle.y = 0.0;
	m_angle.z = 0.0;
	m_Enable = true;
}

int HUD::isType()
{
	return (int)3;
}

void HUD::enable(bool e)
{
	m_Enable = e;
}

bool HUD::getEnable()
{
	return m_Enable;
}

void HUD::translate(float x, float y, float z)
{
	m_translate.x = x;
	m_translate.y = y;
	m_translate.z = z;
	m_pos.x += x;
	m_pos.y += y;
	m_pos.z += z;
}

void HUD::setPos(float x, float y, float z)
{
	m_pos.x = x;
	m_pos.y = y;
	m_pos.z = z;
}

Vector3 HUD::getPos()
{
	return m_pos;
}

float HUD::getPosX()
{
	return m_pos.x;
}

float HUD::getPosY()
{
	return m_pos.y;
}

float HUD::getPosZ()
{
	return m_pos.z;
}

void HUD::setScript(const char* file)
{
	m_Script = file;
}

std::string HUD::getScript()
{
	std::string s(m_Script, 0, sizeof(m_Script));
	return s;
}

std::string HUD::getName()
{
	return m_Name;
}

void HUD::setName(std::string n)
{
	m_Name = n;
}

std::string HUD::getTexture()
{
	return m_Texture;
}

void HUD::setTexture(std::string t)
{
	m_Texture = t;
}

float HUD::getTranslateX()
{
	return m_translate.x;
}

float HUD::getTranslateY()
{
	return m_translate.y;
}

float HUD::getTranslateZ()
{
	return m_translate.z;
}

void HUD::setRotation(Axis axis, float angle)
{
	switch(axis)
	{
	case Axis::xAxis:
		{
			m_angle.x = angle;
			break;
		}
	case Axis::yAxis:
		{
			m_angle.y = angle;
			break;
		}
	case Axis::zAxis:
		{
			m_angle.z = angle;
			break;
		}
	}
}

float HUD::getRotationX()
{
	return m_angle.x;
}

float HUD::getRotationY()
{
	return m_angle.y;
}

float HUD::getRotationZ()
{
	return m_angle.z;
}