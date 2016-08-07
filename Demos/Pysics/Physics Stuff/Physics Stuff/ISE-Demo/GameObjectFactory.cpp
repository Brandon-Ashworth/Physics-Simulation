#include "GameObjectFactory.h"

GameObjectFactory::GameObjectFactory()
{

}

GameObject* GameObjectFactory::Create(objectType ot)
{
	switch(ot)
	{
	case OBJECT2D:
		{
			return new Object2D;
		}
	case OBJECT3D:
		{
			return new Object3D;
		}
	case EFFECT:
		{
			return new Effect;
		}
	case hud:
		{
			return new HUD;
		}
	}
}