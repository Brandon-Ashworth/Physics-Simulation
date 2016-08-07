#include "Vector2Int.h"


Vector2Int::Vector2Int(void)
{
	m_x = 0;
	m_y = 0;
}


Vector2Int::~Vector2Int(void)
{
}



Vector2Int::Vector2Int(int x, int y)
{
	m_x = x;
	m_y = y;
}

Vector2Int::Vector2Int(const Vector2Int &copy)
{
	m_x = copy.m_x;
	m_y = copy.m_y;
}

Vector2Int Vector2Int::operator+(const Vector2Int &toAdd)
{
	Vector2Int ret;
	ret.m_x = m_x + toAdd.m_x;
	ret.m_y = m_y + toAdd.m_y;

	return(ret);
}


Vector2Int Vector2Int::operator-(const Vector2Int &toTake)
{
	Vector2Int ret;
	ret.m_x = m_x - toTake.m_x;
	ret.m_y = m_y - toTake.m_y;
	return(ret);
}

void Vector2Int::operator=(Vector2Int& copy)
{
	m_x = copy.m_x;
	m_y = copy.m_y;
		
}