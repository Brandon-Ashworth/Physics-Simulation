#include "TrueGameObject.h"

TrueGameObject::TrueGameObject()
{
	m_Name = "GameObject";
	m_Pos.x = 0;
	m_Pos.y = 0;
	m_Pos.z = 0;
	m_Angle.x = 0;
	m_Angle.y = 0;
	m_Angle.z = 0;
}

float TrueGameObject::getPositionX()
{
	return m_Pos.x;
}

void TrueGameObject::setPositionX(float x)
{
	m_Pos.x = x;
}

float TrueGameObject::getPositionY()
{
	return m_Pos.y;
}

void TrueGameObject::setPositionY(float y)
{
	m_Pos.y = y;
}

float TrueGameObject::getPositionZ()
{
	return m_Pos.z;
}

void TrueGameObject::setPositionZ(float z)
{
	m_Pos.z = z;
}

float TrueGameObject::getRotationX()
{
	return m_Angle.x;
}

float TrueGameObject::getRotationY()
{
	return m_Angle.y;
}

float TrueGameObject::getRotationZ()
{
	return m_Angle.z;
}

void TrueGameObject::setRotation(Axis axis, float angle)
{
	switch(axis)
	{
	case Axis::xAxis:
		{
			m_Angle.x = angle;
		}
	case Axis::yAxis:
		{
			m_Angle.y = angle;
		}
	case Axis::zAxis:
		{
			m_Angle.z = angle;
		}
	}
}

std::string TrueGameObject::getName()
{
	return m_Name;
}

void TrueGameObject::setName(std::string n)
{
	m_Name = n;
}

void TrueGameObject::addComponent(Component::componentType componenttype)
{
	switch(componenttype)
	{
	case Component::MODEL:
		{
			m_component.push_back(new TrueModel);
		}
	case Component::AI:
		{
			m_component.push_back(new AI);
		}
	default:
		{
		}
	}
}

void TrueGameObject::deleteComponent(int index)
{
	m_component.erase(m_component.begin() + index);
}

Component* TrueGameObject::getComponent(int index)
{
	return m_component[index];
}

void TrueGameObject::setComponent(int index, Component* component)
{
	m_component[index] = component;
}

std::vector<Component*> TrueGameObject::getComponents()
{
	return m_component;
}

void TrueGameObject::setComponents(std::vector<Component*> components)
{
	m_component = components;
}