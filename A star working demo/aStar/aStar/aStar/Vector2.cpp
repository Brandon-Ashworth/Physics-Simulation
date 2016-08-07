#include "Vector2.h"


Vector2::Vector2(void)
{
	m_x = 0;
	m_y = 0;
}


Vector2::~Vector2(void)
{

}

Vector2::Vector2(float x, float y)
{
	m_x = x;
	m_y = y;
}

Vector2::Vector2(const Vector2 &copy)
{
	m_x = copy.m_x;
	m_y = copy.m_y;
}

Vector2 Vector2::operator+(const Vector2 &toAdd)
{
	Vector2 ret;
	ret.m_x = m_x + toAdd.m_x;
	ret.m_y = m_y + toAdd.m_y;

	return(ret);
}


Vector2 Vector2::operator-(const Vector2 &toTake)
{
	Vector2 ret;
	ret.m_x = m_x - toTake.m_x;
	ret.m_y = m_y - toTake.m_y;
	return(ret);
}

void Vector2::operator=(Vector2& copy)
{
	m_x = copy.m_x;
	m_y = copy.m_y;
		
}

