#include "GameObject.h"

Object2D::Object2D()
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

int Object2D::isType()
{
	return (int)0;
}

bool Object2D::getEnable()
{
	return m_Enable;
}

void Object2D::enable(bool e)
{
	m_Enable = e;
}

void Object2D::translate(float x, float y, float z)
{
	m_pos.x += x;
	m_pos.y += y;
	m_pos.z += z;
}

void Object2D::setPos(float x, float y, float z)
{
	m_pos.x = x;
	m_pos.y = y;
	m_pos.z = z;
}

Vector3 Object2D::getPos()
{
	return m_pos;
}

float Object2D::getPosX()
{
	return m_pos.x;
}

float Object2D::getPosY()
{
	return m_pos.y;
}

float Object2D::getPosZ()
{
	return m_pos.z;
}

void Object2D::setScript(const char* file)
{
	m_Script = file;
}

std::string Object2D::getScript()
{
	std::string s(m_Script, 0, sizeof(m_Script));
	return s;
}

std::string Object2D::getName()
{
	return m_Name;
}

void Object2D::setName(std::string n)
{
	m_Name = n;
}

std::string Object2D::getTexture()
{
	return m_Texture;
}

void Object2D::setTexture(std::string t)
{
	m_Texture = t;
}

float Object2D::getTranslateX()
{
	return m_translate.x;
}

float Object2D::getTranslateY()
{
	return m_translate.y;
}

float Object2D::getTranslateZ()
{
	return m_translate.z;
}

void Object2D::setRotation(Axis axis, float angle)
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

float Object2D::getRotationX()
{
	return m_angle.x;
}

float Object2D::getRotationY()
{
	return m_angle.y;
}

float Object2D::getRotationZ()
{
	return m_angle.z;
}