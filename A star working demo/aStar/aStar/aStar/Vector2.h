#pragma once
class Vector2
{
public:
	Vector2(void);
	~Vector2(void);

	Vector2(float x, float y);
	Vector2(const Vector2 &copy);

	void operator=(Vector2& copy);

	//take the value supplied and return a new vector 2 of this one minus the one supplied
	Vector2 operator-(const Vector2 &toTake);

	//return a new vector of the 2 added together
	Vector2 operator+(const Vector2 &toAdd);

	//divide?
	//Multiply?


	float m_x;//easy access public
	float m_y;//easy access public
};

