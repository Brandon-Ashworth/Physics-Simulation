#pragma once
class Vector2Int
{
public:
	Vector2Int(void);
	~Vector2Int(void);

	Vector2Int(int x, int y);
	Vector2Int(const Vector2Int &copy);

	void operator=(Vector2Int& copy);

	//take the value supplied and return a new vector 2 of this one minus the one supplied
	Vector2Int operator-(const Vector2Int &toTake);

	//return a new vector of the 2 added together
	Vector2Int operator+(const Vector2Int &toAdd);

	//divide?
	//Multiply?


	int m_x;//easy access public
	int m_y;//easy access public
};

