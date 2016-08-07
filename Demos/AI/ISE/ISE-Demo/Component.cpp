#include "Component.h"

Component::Component()
{
	m_ComponentType = EMPTY;
}

Component::componentType Component::getComponentType()
{
	return m_ComponentType;
}