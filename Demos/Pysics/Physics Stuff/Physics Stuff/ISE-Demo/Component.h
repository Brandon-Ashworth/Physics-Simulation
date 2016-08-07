#pragma once

class Component
{
public:
	enum componentType
	{
		MODEL = 0, AI
	};

	virtual ~Component() {};
};