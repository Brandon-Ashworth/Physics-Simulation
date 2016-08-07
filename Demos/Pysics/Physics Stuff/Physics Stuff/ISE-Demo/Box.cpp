#include "Box.h"


Box::Box(void)
{
	body = new RigidBody();
	body->setSleepEpsilon(0.3f);
}


Box::~Box(void)
{
	delete body;
}

void Box::setState(Vector3 &position, Quaternion &orientation, Vector3 &extents, Vector3 &velocity)
{
	Matrix3 tensor;

	body->setPosition(position);
	body->setOrientation(orientation);
	body->setVelocity(velocity);
	body->setRotation(Vector3(0,0,0));
	halfSize = extents;

	int mass = halfSize.x * halfSize.y * halfSize.z * 0.001f;
	body->setMass(mass);

	tensor.setBlockInertiaTensor(halfSize,mass);
	body->setInertiaTensor(tensor);

	body->setLinearDamping(0.9f);
	body->setAngularDamping(0.6f);
	body->clearAccumulators();
	body->setAcceleration(0,-100.0f,0);

	body->setAwake();

	body->calculateDerivedData();
}

