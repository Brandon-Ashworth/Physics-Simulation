#pragma once
/**
 * @brief Vector2 class specifically for int
 * @details This class does what a normal Vector Class does but stores values as integers for faster computation 
 * 
 * @author Umar Badat
 */
class Vector2Int
{
public:
	/**
	 * @brief Default Construct
	 * @details Sets all variables to zero
	 */
	Vector2Int(void);
	/**
	 * @brief Default destructor
	 * @details Nothing in new'ed so this does nothing
	 */
	~Vector2Int(void);

	/**
	 * @brief Default constructor with variables input
	 * @details Takes normal integer numbers and places them in this object
	 * 
	 * @param x The X variable
	 * @param y the Y variable
	 */
	Vector2Int(int x, int y);
	/**
	 * @brief Copy Contructor
	 * @details if you want to duplicate the object this copy contructor can take in itself as a variable and assign it to the new variable
	 * 
	 * @param copy The variable you want to make a copy of
	 */
	Vector2Int(const Vector2Int &copy);

	/**
	 * @brief assignment operator
	 * @details Takes whats on the other side of the '=' and copies all the variables to this one
	 * 
	 * @param copy the varaible you want to take a copy of
	 */
	void operator=(Vector2Int& copy);

	/**
	 * @brief returns a new value of this minus the one passed in
	 * @details eg. Vector vec1, vec2; vec1-vec2 will produce vec3 which will be vec1.x-vec2.x
	 * 
	 * @param the vector to take with
	 * @return a new Vector2Int with the new values placed
	 */
	Vector2Int operator-(const Vector2Int &toTake);//take the value supplied and return a new vector 2 of this one minus the one supplied

	/**
	 * @brief addition operator
	 * @details returns a new vector with the 2 numbers added together
	 * 
	 * @param toAdd the other variable to add
	 * @return a new vector with the results of the addition
	 */
	Vector2Int operator+(const Vector2Int &toAdd);//return a new vector of the 2 added together

	//divide?
	//Multiply?

	/**
	 * Variables kept as public to make access easy
	 */
	int m_x;//easy access public
	int m_y;//easy access public
};

