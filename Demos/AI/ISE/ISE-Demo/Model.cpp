#include "Model.h"

Model::Model()
{
	m_ObjectType = MODEL;
	m_Texture = "";
	m_Model = "";
	m_Status = true;
}

std::string Model::getTexture()
{
	return m_Texture;
}

void Model::setTexture(std::string t)
{
	m_Texture = t;
}

std::string Model::getModel()
{
	return m_Model;
}

void Model::setModel(std::string m)
{
	m_Model = m;
}

bool Model::getStatus()
{
	return m_Status;
}

void Model::setStatus(bool s)
{
	m_Status = s;
}