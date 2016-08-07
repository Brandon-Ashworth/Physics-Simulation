#include "GameObject2.h"

GameObject2::GameObject2()
{
	m_Name = "GameObject";
	m_Pos.x = 0;
	m_Pos.y = 0;
	m_Pos.z = 0;
	m_Angle.x = 0;
	m_Angle.y = 0;
	m_Angle.z = 0;
}

float GameObject2::getPositionX()
{
	return m_Pos.x;
}

void GameObject2::setPositionX(float x)
{
	m_Pos.x = x;
}

float GameObject2::getPositionY()
{
	return m_Pos.y;
}

void GameObject2::setPositionY(float y)
{
	m_Pos.y = y;
}

float GameObject2::getPositionZ()
{
	return m_Pos.z;
}

void GameObject2::setPositionZ(float z)
{
	m_Pos.z = z;
}

float GameObject2::getRotationX()
{
	return m_Angle.x;
}

float GameObject2::getRotationY()
{
	return m_Angle.y;
}

float GameObject2::getRotationZ()
{
	return m_Angle.z;
}

void GameObject2::setRotation(Axis axis, float angle)
{
	switch(axis)
	{
	case Axis::xAxis:
		{
			m_Angle.x = angle;
			break;
		}
	case Axis::yAxis:
		{
			m_Angle.y = angle;
			break;
		}
	case Axis::zAxis:
		{
			m_Angle.z = angle;
			break;
		}
	}
}

std::string GameObject2::getName()
{
	return m_Name;
}

void GameObject2::setName(std::string n)
{
	m_Name = n;
}

GameObject2::objectType GameObject2::getType()
{
	return m_ObjectType;
}