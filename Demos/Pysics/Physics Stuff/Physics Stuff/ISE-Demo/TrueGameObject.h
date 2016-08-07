#pragma once

#include "Component.h"
#include "Vector3.h"
#include "TrueModel.h"
#include "AI.h"
#include "Axis.h"
#include <string>
#include <vector>

class TrueGameObject
{
public:
	TrueGameObject();
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
	std::string getName();
	void setName(std::string n);
	// Adds a Component pointer.
	void addComponent(Component::componentType componenttype);
	// Deletes a Component pointer by index.
	void deleteComponent(int index);
	// Gets a Component pointer by index.
	Component* getComponent(int index);
	void setComponent(int index, Component* component);
	std::vector<Component*> getComponents();
	void setComponents(std::vector<Component*> components);

private:
	Vector3 m_Pos;
	Vector3 m_Angle;
	std::string m_Name;
	std::vector<Component*> m_component;
};