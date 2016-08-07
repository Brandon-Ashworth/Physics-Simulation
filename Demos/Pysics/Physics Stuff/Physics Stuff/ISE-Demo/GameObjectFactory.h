#pragma once

#include "GameObject.h"

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 * @author [author]
 */
class GameObjectFactory
{
public:
	enum objectType
	{
		OBJECT2D = 0, OBJECT3D, EFFECT, hud
	};
	/**
	 * @brief [brief description]
	 * @details [long description]
	 */

	GameObjectFactory();
	/**
	 * @brief [brief description]
	 * @details [long description]
	 * 
	 * @param ot [description]
	 * @return [description]
	 */
	GameObject* Create(objectType ot);
};