#include "TrueAffordance.h"

TrueAffordance::TrueAffordance()
{
	m_ComponentType = Component::AFFORDANCE;
	m_MinValue = 0.0;
	m_MaxValue = 0.0;
	m_Value = 0.0;
}

std::string TrueAffordance::getName()
{
	return m_Name;
}

void TrueAffordance::setName(std::string name)
{
	m_Name = name;
}

float TrueAffordance::getMinValue()
{
	return m_MinValue;
}

void TrueAffordance::setMinValue(float minValue)
{
	m_MinValue = minValue;
}

float TrueAffordance::getMaxValue()
{
	return m_MaxValue;
}

void TrueAffordance::setMaxValue(float maxValue)
{
	m_MaxValue = maxValue;
}

float TrueAffordance::getValue()
{
	return m_Value;
}

void TrueAffordance::setValue(float value)
{
	m_Value = value;
}

bool TrueAffordance::hasWithinInclusive(float value)
{
	if(value >= m_MinValue && value <= m_MaxValue)
	{
		return true;
	}
	return false;
}

bool TrueAffordance::hasWithinExclusive(float value)
{
	if(value > m_MinValue && value < m_MaxValue)
	{
		return true;
	}
	return false;
}