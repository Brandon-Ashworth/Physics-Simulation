#pragma once

#include "Component.h"
#include "Vector3.h"
#include "Quaternion.h"
#include "Axis.h"
#include <string>
#include <vector>

class GameObject2
{
public:
	enum objectType
	{
		MODEL = 0, HUD
	};
	GameObject2();
	float getPositionX();
	void setPositionX(float x);
	float getPositionY();
	void setPositionY(float y);
	float getPositionZ();
	void setPositionZ(float z);
	float getRotationX();
	float getRotationY();
	float getRotationZ();
	void setRotation(Axis axis, float angle);
	void addRotation(Vector3 rot);
	void addPosition(float x, float y, float z);
	void setPosition(Vector3 pos);
	void setRotation(Vector3 rot);
	Vector3 getPosition();

	std::string getName();
	void setName(std::string n);
	objectType getType();
	// Adds a Component pointer.
	void addComponent(Component* component);
	// Deletes a Component pointer by index.
	void deleteChild(int index);

protected:
	Vector3 m_Pos;
	Vector3 m_Angle;
	std::string m_Name;
	objectType m_ObjectType;

private:
	std::vector<Component*> m_component;
};