#include "GameObject.h"

Effect::Effect()
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

int Effect::isType()
{
	return (int)2;
}

void Effect::enable(bool e)
{
	m_Enable = e;
}

bool Effect::getEnable()
{
	return m_Enable;
}

void Effect::translate(float x, float y, float z)
{
	m_pos.x += x;
	m_pos.y += y;
	m_pos.z += z;
}

void Effect::setPos(float x, float y, float z)
{
	m_pos.x = x;
	m_pos.y = y;
	m_pos.z = z;
}

Vector3 Effect::getPos()
{
	return m_pos;
}

float Effect::getPosX()
{
	return m_pos.x;
}

float Effect::getPosY()
{
	return m_pos.y;
}

float Effect::getPosZ()
{
	return m_pos.z;
}

void Effect::setScript(const char* file)
{
	m_Script = file;
}

std::string Effect::getScript()
{
	std::string s(m_Script, 0, sizeof(m_Script));
	return s;
}

std::string Effect::getName()
{
	return m_Name;
}

void Effect::setName(std::string n)
{
	m_Name = n;
}

std::string Effect::getTexture()
{
	return m_Texture;
}

void Effect::setTexture(std::string t)
{
	m_Texture = t;
}

float Effect::getTranslateX()
{
	return m_translate.x;
}

float Effect::getTranslateY()
{
	return m_translate.y;
}

float Effect::getTranslateZ()
{
	return m_translate.z;
}

void Effect::setRotation(Axis axis, float angle)
{
	switch(axis)
	{
	case Axis::xAxis:
		{
			m_angle.x = angle;
		}
	case Axis::yAxis:
		{
			m_angle.y = angle;
		}
	case Axis::zAxis:
		{
			m_angle.z = angle;
		}
	}
}

float Effect::getRotationX()
{
	return m_angle.x;
}

float Effect::getRotationY()
{
	return m_angle.y;
}

float Effect::getRotationZ()
{
	return m_angle.z;
}