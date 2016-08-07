#include "TrueModel.h"

TrueModel::TrueModel()
{
	m_Texture = "";
	m_Model = "";
	m_Status = true;
	m_ComponentType = Component::MODEL;
}

float TrueModel::getPositionX()
{
	return m_Pos.x;
}

void TrueModel::setPositionX(float x)
{
	m_Pos.x = x;
}

float TrueModel::getPositionY()
{
	return m_Pos.y;
}

void TrueModel::setPositionY(float y)
{
	m_Pos.y = y;
}

float TrueModel::getPositionZ()
{
	return m_Pos.z;
}

void TrueModel::setPositionZ(float z)
{
	m_Pos.z = z;
}

float TrueModel::getRotationX()
{
	return m_Angle.x;
}

float TrueModel::getRotationY()
{
	return m_Angle.y;
}

float TrueModel::getRotationZ()
{
	return m_Angle.z;
}

void TrueModel::setRotation(Axis axis, float angle)
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

std::string TrueModel::getTexture()
{
	return m_Texture;
}

void TrueModel::setTexture(std::string t)
{
	m_Texture = t;
}

std::string TrueModel::getModel()
{
	return m_Model;
}

void TrueModel::setModel(std::string m)
{
	m_Model = m;
}

bool TrueModel::getStatus()
{
	return m_Status;
}

void TrueModel::setStatus(bool s)
{
	m_Status = s;
}