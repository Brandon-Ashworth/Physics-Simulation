#pragma once

//#include "GameObjectFactory.h"
#include "Vector3.h"
#include "Axis.h"
#include <string>

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 * @author [author]
 */

class GameObject
{
public:
	/**
	 * @brief [brief description]
	 * @details [long description]
	 */
	GameObject();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param m [description]
	 * @param t [description]
	 */
	virtual void enable(bool e) = 0;
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param m [description]
	 * @param t [description]
	 */
	virtual bool getEnable() = 0;
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	virtual int isType() = 0;
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param x [description]
	 * @param y [description]
	 * @param z [description]
	 */
	virtual void translate(float x, float y, float z) = 0;
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param x [description]
	 * @param y [description]
	 * @param z [description]
	 */
	virtual void setPos(float x, float y, float z) = 0;
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	virtual Vector3 getPos() = 0;
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	virtual float getPosX() = 0;
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	virtual float getPosY() = 0;
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	virtual float getPosZ() = 0;
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param file [description]
	 */
	virtual void setScript(const char* file) = 0;
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	virtual std::string getScript() = 0;
	/**
	 * 
	 */
	virtual std::string getName() = 0;
	/**
	 * 
	 */
	virtual void setName(std::string n) = 0;
	/**
	 * 
	 */
	virtual std::string getTexture() = 0;
	/**
	 * 
	 */
	virtual void setTexture(std::string t) = 0;
	/**
	 * 
	 */
	virtual float getTranslateX() = 0;
	/**
	 * 
	 */
	virtual float getTranslateY() = 0;
	/**
	 * 
	 */
	virtual float getTranslateZ() = 0;
	/**
	 * 
	 */
	virtual void setRotation(Axis axis, float angle) = 0;
	/**
	 * 
	 */
	virtual float getRotationX() = 0;
	/**
	 * 
	 */
	virtual float getRotationY() = 0;
	/**
	 * 
	 */
	virtual float getRotationZ() = 0;

protected:
	Vector3 m_pos;
	Vector3 m_translate;
	Vector3 m_angle;
	std::string m_Script;
	std::string m_Name;
	std::string m_Texture;
	bool m_Enable;
};



// ------------------------------



/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */

class Object2D: public GameObject
{
public:
	/**
	 * @brief [brief description]
	 * @details [long description]
	 */
	Object2D();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	int isType();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param m [description]
	 * @param t [description]
	 */
	void enable(bool e);
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param m [description]
	 * @param t [description]
	 */
	bool getEnable();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param x [description]
	 * @param y [description]
	 * @param z [description]
	 */
	void translate(float x, float y, float z);
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param x [description]
	 * @param y [description]
	 * @param z [description]
	 */
	void setPos(float x, float y, float z);
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	Vector3 getPos();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	float getPosX();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	float getPosY();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	float getPosZ();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param file [description]
	 */
	void setScript(const char* file);
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	std::string getScript();
	/**
	 * 
	 */
	std::string getName();
	/**
	 * 
	 */
	void setName(std::string n);
	/**
	 * 
	 */
	std::string getTexture();
	/**
	 * 
	 */
	void setTexture(std::string t);
	/**
	 * 
	 */
	float getTranslateX();
	/**
	 * 
	 */
	float getTranslateY();
	/**
	 * 
	 */
	float getTranslateZ();
	/**
	 * 
	 */
	void setRotation(Axis axis, float angle);
	/**
	 * 
	 */
	float getRotationX();
	/**
	 * 
	 */
	float getRotationY();
	/**
	 * 
	 */
	float getRotationZ();
};



// ------------------------------



/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 * @author [author]
 */
class Object3D: public GameObject
{
public:
	/**
	 * @brief [brief description]
	 * @details [long description]
	 */
	Object3D();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	int isType();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param m [description]
	 * @param t [description]
	 */
	void enable(bool enable);
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param m [description]
	 * @param t [description]
	 */
	bool getEnable();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param x [description]
	 * @param y [description]
	 * @param z [description]
	 */
	void translate(float x, float y, float z);
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param x [description]
	 * @param y [description]
	 * @param z [description]
	 */
	void setPos(float x, float y, float z);
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	Vector3 getPos();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	float getPosX();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	float getPosY();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	float getPosZ();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param file [description]
	 */
	void setScript(const char* file);
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	std::string getScript();
	/**
	 * 
	 */
	std::string getName();
	/**
	 * 
	 */
	void setName(std::string n);
	/**
	 * 
	 */
	std::string getTexture();
	/**
	 * 
	 */
	void setTexture(std::string t);
	/**
	 * 
	 */
	float getTranslateX();
	/**
	 * 
	 */
	float getTranslateY();
	/**
	 * 
	 */
	float getTranslateZ();
	/**
	 * 
	 */
	void setRotation(Axis axis, float angle);
	/**
	 * 
	 */
	float getRotationX();
	/**
	 * 
	 */
	float getRotationY();
	/**
	 * 
	 */
	float getRotationZ();
};



// ------------------------------



/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 * @author [author]
 */

class Effect: public GameObject
{
public:
	/**
	 * @brief [brief description]
	 * @details [long description]
	 */
	Effect();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	int isType();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param m [description]
	 * @param t [description]
	 */
	void enable(bool e);
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param m [description]
	 * @param t [description]
	 */
	bool getEnable();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param x [description]
	 * @param y [description]
	 * @param z [description]
	 */
	void translate(float x, float y, float z);
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param x [description]
	 * @param y [description]
	 * @param z [description]
	 */
	void setPos(float x, float y, float z);
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	Vector3 getPos();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	float getPosX();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	float getPosY();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	float getPosZ();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param file [description]
	 */
	void setScript(const char* file);
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	std::string getScript();
	/**
	 * 
	 */
	std::string getName();
	/**
	 * 
	 */
	void setName(std::string n);
	/**
	 * 
	 */
	std::string getTexture();
	/**
	 * 
	 */
	void setTexture(std::string t);
	/**
	 * 
	 */
	float getTranslateX();
	/**
	 * 
	 */
	float getTranslateY();
	/**
	 * 
	 */
	float getTranslateZ();
	/**
	 * 
	 */
	void setRotation(Axis axis, float angle);
	/**
	 * 
	 */
	float getRotationX();
	/**
	 * 
	 */
	float getRotationY();
	/**
	 * 
	 */
	float getRotationZ();
};



// ------------------------------



/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 * @author [author]
 */

class HUD: public GameObject
{
public:
	/**
	 * @brief [brief description]
	 * @details [long description]
	 */
	HUD();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	int isType();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param m [description]
	 * @param t [description]
	 */
	void enable(bool e);
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param m [description]
	 * @param t [description]
	 */
	bool getEnable();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param x [description]
	 * @param y [description]
	 * @param z [description]
	 */
	void translate(float x, float y, float z);
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param x [description]
	 * @param y [description]
	 * @param z [description]
	 */
	void setPos(float x, float y, float z);
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	Vector3 getPos();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	float getPosX();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	float getPosY();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	float getPosZ();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param file [description]
	 */
	void setScript(const char* file);
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * @return [description]
	 */
	std::string getScript();
	/**
	 * 
	 */
	std::string getName();
	/**
	 * 
	 */
	void setName(std::string n);
	/**
	 * 
	 */
	std::string getTexture();
	/**
	 * 
	 */
	void setTexture(std::string t);
	/**
	 * 
	 */
	float getTranslateX();
	/**
	 * 
	 */
	float getTranslateY();
	/**
	 * 
	 */
	float getTranslateZ();
	/**
	 * 
	 */
	void setRotation(Axis axis, float angle);
	/**
	 * 
	 */
	float getRotationX();
	/**
	 * 
	 */
	float getRotationY();
	/**
	 * 
	 */
	float getRotationZ();
};