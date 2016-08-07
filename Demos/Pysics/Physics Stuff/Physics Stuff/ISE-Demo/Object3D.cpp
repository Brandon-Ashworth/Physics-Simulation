#include "GameObject.h"

Object3D::Object3D()
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

int Object3D::isType()
{
	return (int)1;
}

void Object3D::enable(bool e)
{
	m_Enable = e;
}

bool Object3D::getEnable()
{
	return m_Enable;
}

void Object3D::translate(float x, float y, float z)
{
	m_translate.x = x;
	m_translate.y = y;
	m_translate.z = z;
	m_pos.x += x;
	m_pos.y += y;
	m_pos.z += z;
}

void Object3D::setPos(float x, float y, float z)
{
	m_pos.x = x;
	m_pos.y = y;
	m_pos.z = z;
}

Vector3 Object3D::getPos()
{
	return m_pos;
}

float Object3D::getPosX()
{
	return m_pos.x;
}

float Object3D::getPosY()
{
	return m_pos.y;
}

float Object3D::getPosZ()
{
	return m_pos.z;
}

void Object3D::setScript(const char* file)
{
	m_Script = file;
}

std::string Object3D::getScript()
{
	std::string s(m_Script, 0, sizeof(m_Script));
	return s;
}

std::string Object3D::getName()
{
	return m_Name;
}

void Object3D::setName(std::string n)
{
	m_Name = n;
}

std::string Object3D::getTexture()
{
	return m_Texture;
}

void Object3D::setTexture(std::string t)
{
	m_Texture = t;
}

float Object3D::getTranslateX()
{
	return m_translate.x;
}

float Object3D::getTranslateY()
{
	return m_translate.y;
}

float Object3D::getTranslateZ()
{
	return m_translate.z;
}

void Object3D::setRotation(Axis axis, float angle)
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

float Object3D::getRotationX()
{
	return m_angle.x;
}

float Object3D::getRotationY()
{
	return m_angle.y;
}

float Object3D::getRotationZ()
{
	return m_angle.z;
}