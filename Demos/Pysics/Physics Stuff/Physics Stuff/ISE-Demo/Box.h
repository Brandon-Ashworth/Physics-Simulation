#include "Collision_fine.h"
#include "RigidBody.h"

#pragma once
class Box : public CollisionBox
{
public:
	Box(void);
	~Box(void);

	bool isOverlapping;

	void setState(Vector3 &position, Quaternion &orientation, Vector3 &extents, Vector3 &velocity);

};

