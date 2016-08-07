#pragma once

#include "Component.h"
#include <string>

class TrueAffordance : public Component
{
public:
	TrueAffordance();
	std::string getName();
	void setName(std::string name);
	float getMinValue();
	void setMinValue(float minValue);
	float getMaxValue();
	void setMaxValue(float maxValue);
	float getValue();
	void setValue(float value);
	bool hasWithinInclusive(float value);
	bool hasWithinExclusive(float value);

private:
	std::string m_Name;
	float m_MinValue;
	float m_MaxValue;
	float m_Value;
};