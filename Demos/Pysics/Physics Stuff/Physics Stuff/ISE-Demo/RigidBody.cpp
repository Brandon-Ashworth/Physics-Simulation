
#include "RigidBody.h"
#include <memory.h>
#include <assert.h>
#include <math.h>

/*
 * --------------------------------------------------------------------------
 * INTERNAL OR HELPER FUNCTIONS:
 * --------------------------------------------------------------------------
 */

/**
 * Internal function that checks the validity of an inverse inertia tensor.
 */
static inline void _checkInverseInertiaTensor(const Matrix3 &iitWorld)
{
	// TODO: Perform a validity check in an assert.
}

/**
 * Internal function to do an intertia tensor transform by a quaternion.
 * Note that the implementation of this function was created by an
 * automated code-generator and optimizer.
 */
static inline void _transformInertiaTensor(Matrix3 &iitWorld,
										   const Quaternion &q,
										   const Matrix3 &iitBody,
										   const Matrix4 &rotmat)
{
	float t4 = rotmat.data[0]*iitBody.data[0]+
		rotmat.data[1]*iitBody.data[3]+
		rotmat.data[2]*iitBody.data[6];
	float t9 = rotmat.data[0]*iitBody.data[1]+
		rotmat.data[1]*iitBody.data[4]+
		rotmat.data[2]*iitBody.data[7];
	float t14 = rotmat.data[0]*iitBody.data[2]+
		rotmat.data[1]*iitBody.data[5]+
		rotmat.data[2]*iitBody.data[8];
	float t28 = rotmat.data[4]*iitBody.data[0]+
		rotmat.data[5]*iitBody.data[3]+
		rotmat.data[6]*iitBody.data[6];
	float t33 = rotmat.data[4]*iitBody.data[1]+
		rotmat.data[5]*iitBody.data[4]+
		rotmat.data[6]*iitBody.data[7];
	float t38 = rotmat.data[4]*iitBody.data[2]+
		rotmat.data[5]*iitBody.data[5]+
		rotmat.data[6]*iitBody.data[8];
	float t52 = rotmat.data[8]*iitBody.data[0]+
		rotmat.data[9]*iitBody.data[3]+
		rotmat.data[10]*iitBody.data[6];
	float t57 = rotmat.data[8]*iitBody.data[1]+
		rotmat.data[9]*iitBody.data[4]+
		rotmat.data[10]*iitBody.data[7];
	float t62 = rotmat.data[8]*iitBody.data[2]+
		rotmat.data[9]*iitBody.data[5]+
		rotmat.data[10]*iitBody.data[8];

	iitWorld.data[0] = t4*rotmat.data[0]+
		t9*rotmat.data[1]+
		t14*rotmat.data[2];
	iitWorld.data[1] = t4*rotmat.data[4]+
		t9*rotmat.data[5]+
		t14*rotmat.data[6];
	iitWorld.data[2] = t4*rotmat.data[8]+
		t9*rotmat.data[9]+
		t14*rotmat.data[10];
	iitWorld.data[3] = t28*rotmat.data[0]+
		t33*rotmat.data[1]+
		t38*rotmat.data[2];
	iitWorld.data[4] = t28*rotmat.data[4]+
		t33*rotmat.data[5]+
		t38*rotmat.data[6];
	iitWorld.data[5] = t28*rotmat.data[8]+
		t33*rotmat.data[9]+
		t38*rotmat.data[10];
	iitWorld.data[6] = t52*rotmat.data[0]+
		t57*rotmat.data[1]+
		t62*rotmat.data[2];
	iitWorld.data[7] = t52*rotmat.data[4]+
		t57*rotmat.data[5]+
		t62*rotmat.data[6];
	iitWorld.data[8] = t52*rotmat.data[8]+
		t57*rotmat.data[9]+
		t62*rotmat.data[10];
}

/**
 * Inline function that creates a transform matrix from a
 * position and orientation.
 */
static inline void _calculateTransformMatrix(Matrix4 &transformMatrix,
											 const Vector3 &position,
											 const Quaternion &orientation)
{
	transformMatrix.data[0] = 1-2*orientation.j*orientation.j-
		2*orientation.k*orientation.k;
	transformMatrix.data[1] = 2*orientation.i*orientation.j -
		2*orientation.r*orientation.k;
	transformMatrix.data[2] = 2*orientation.i*orientation.k +
		2*orientation.r*orientation.j;
	transformMatrix.data[3] = position.x;

	transformMatrix.data[4] = 2*orientation.i*orientation.j +
		2*orientation.r*orientation.k;
	transformMatrix.data[5] = 1-2*orientation.i*orientation.i-
		2*orientation.k*orientation.k;
	transformMatrix.data[6] = 2*orientation.j*orientation.k -
		2*orientation.r*orientation.i;
	transformMatrix.data[7] = position.y;

	transformMatrix.data[8] = 2*orientation.i*orientation.k -
		2*orientation.r*orientation.j;
	transformMatrix.data[9] = 2*orientation.j*orientation.k +
		2*orientation.r*orientation.i;
	transformMatrix.data[10] = 1-2*orientation.i*orientation.i-
		2*orientation.j*orientation.j;
	transformMatrix.data[11] = position.z;
}


void RigidBody::setSleepEpsilon(float value)
{
	sleepEpsilon = value;
}

float RigidBody::getSleepEpsilon()
{
	return sleepEpsilon;
}

void RigidBody::calculateDerivedData()
{
	orientation.normalise();

	// Calculate the transform matrix for the body.
	_calculateTransformMatrix(transformMatrix, position, orientation);

	// Calculate the inertiaTensor in world space.
	_transformInertiaTensor(inverseInertiaTensorWorld,
		orientation,
		inverseInertiaTensor,
		transformMatrix);

}

void RigidBody::integrate(float duration)
{
	if (!isAwake || inverseMass == 0.0f) return; // return if the rigidbody is not awake or has infinite mass. 

	// Calculate linear acceleration from force inputs.
	lastFrameAcceleration = acceleration;
	lastFrameAcceleration.addScaledVector(forceAccum, inverseMass);

	// Calculate angular acceleration from torque inputs.
	Vector3 angularAcceleration =
		inverseInertiaTensorWorld.transform(torqueAccum);

	// Adjust velocities
	// Update linear velocity from both acceleration and impulse.
	velocity.addScaledVector(lastFrameAcceleration, duration);

	// Update angular velocity from both acceleration and impulse.
	rotation.addScaledVector(angularAcceleration, duration);

	// Impose drag.
	velocity *= powf(linearDamping, duration);
	rotation *= powf(angularDamping, duration);

	// Adjust positions
	// Update linear position.
	position.addScaledVector(velocity, duration);

	// Update angular position.
	orientation.addScaledVector(rotation, duration);

	// Impose drag.
	velocity *= powf(linearDamping, duration);
	rotation *= powf(angularDamping, duration);

	// Normalise the orientation, and update the matrices with the new
	// position and orientation
	calculateDerivedData();

	// Clear accumulators.
	clearAccumulators();

	// Update the kinetic energy store, and possibly put the body to
	// sleep.
	if (canSleep) {
		float currentMotion = velocity.scalarProduct(velocity) +
			rotation.scalarProduct(rotation);

		float bias = powf(0.5, duration);
		motion = bias*motion + (1-bias)*currentMotion;

		if (motion < sleepEpsilon) setAwake(false);
		else if (motion > 10 * sleepEpsilon) motion = 10 * sleepEpsilon;
	}
}

void RigidBody::setMass(const float mass)
{
	assert(mass != 0);
	RigidBody::inverseMass = ((float)1.0f)/mass;
}

float RigidBody::getMass() const
{
	if (inverseMass == 0) {
		return FLT_MAX;
	} else {
		return ((float)1.0)/inverseMass;
	}
}

void RigidBody::setInverseMass(const float inverseMass)
{
	RigidBody::inverseMass = inverseMass;
}

float RigidBody::getInverseMass() const
{
	return inverseMass;
}

bool RigidBody::hasFiniteMass() const
{
	return inverseMass >= 0.0f;
}

void RigidBody::setInertiaTensor(const Matrix3 &inertiaTensor)
{
	inverseInertiaTensor.setInverse(inertiaTensor);
	_checkInverseInertiaTensor(inverseInertiaTensor);
}

void RigidBody::getInertiaTensor(Matrix3 *inertiaTensor) const
{
	inertiaTensor->setInverse(inverseInertiaTensor);
}

Matrix3 RigidBody::getInertiaTensor() const
{
	Matrix3 it;
	getInertiaTensor(&it);
	return it;
}

void RigidBody::getInertiaTensorWorld(Matrix3 *inertiaTensor) const
{
	inertiaTensor->setInverse(inverseInertiaTensorWorld);
}

Matrix3 RigidBody::getInertiaTensorWorld() const
{
	Matrix3 it;
	getInertiaTensorWorld(&it);
	return it;
}

void RigidBody::setInverseInertiaTensor(const Matrix3 &inverseInertiaTensor)
{
	_checkInverseInertiaTensor(inverseInertiaTensor);
	RigidBody::inverseInertiaTensor = inverseInertiaTensor;
}

void RigidBody::getInverseInertiaTensor(Matrix3 *inverseInertiaTensor) const
{
	*inverseInertiaTensor = RigidBody::inverseInertiaTensor;
}

Matrix3 RigidBody::getInverseInertiaTensor() const
{
	return inverseInertiaTensor;
}

void RigidBody::getInverseInertiaTensorWorld(Matrix3 *inverseInertiaTensor) const
{
	*inverseInertiaTensor = inverseInertiaTensorWorld;
}

Matrix3 RigidBody::getInverseInertiaTensorWorld() const
{
	return inverseInertiaTensorWorld;
}

void RigidBody::setDamping(const float linearDamping,
			   const float angularDamping)
{
	RigidBody::linearDamping = linearDamping;
	RigidBody::angularDamping = angularDamping;
}

void RigidBody::setLinearDamping(const float linearDamping)
{
	RigidBody::linearDamping = linearDamping;
}

float RigidBody::getLinearDamping() const
{
	return linearDamping;
}

void RigidBody::setAngularDamping(const float angularDamping)
{
	RigidBody::angularDamping = angularDamping;
}

float RigidBody::getAngularDamping() const
{
	return angularDamping;
}

void RigidBody::setPosition(const Vector3 &position)
{
	RigidBody::position = position;
}

void RigidBody::setPosition(const float x, const float y, const float z)
{
	position.x = x;
	position.y = y;
	position.z = z;
}

Vector3 RigidBody::getForceAccum() const
{
	return forceAccum;
}

void RigidBody::getPosition(Vector3 *position) const
{
	*position = RigidBody::position;
}

Vector3 RigidBody::getPosition() const
{
	return position;
}

void RigidBody::setOrientation(const Quaternion &orientation)
{
	RigidBody::orientation = orientation;
	RigidBody::orientation.normalise();
}

void RigidBody::setOrientation(const float r, const float i,
				   const float j, const float k)
{
	orientation.r = r;
	orientation.i = i;
	orientation.j = j;
	orientation.k = k;
	orientation.normalise();
}

void RigidBody::getOrientation(Quaternion *orientation) const
{
	*orientation = RigidBody::orientation;
}

Quaternion RigidBody::getOrientation() const
{
	return orientation;
}

void RigidBody::getOrientation(Matrix3 *matrix) const
{
	getOrientation(matrix->data);
}

void RigidBody::getOrientation(float matrix[9]) const
{
	matrix[0] = transformMatrix.data[0];
	matrix[1] = transformMatrix.data[1];
	matrix[2] = transformMatrix.data[2];

	matrix[3] = transformMatrix.data[4];
	matrix[4] = transformMatrix.data[5];
	matrix[5] = transformMatrix.data[6];

	matrix[6] = transformMatrix.data[8];
	matrix[7] = transformMatrix.data[9];
	matrix[8] = transformMatrix.data[10];
}

void RigidBody::getTransform(Matrix4 *transform) const
{
	memcpy(transform, &transformMatrix.data, sizeof(Matrix4));
}

void RigidBody::getTransform(float matrix[16]) const
{
	memcpy(matrix, transformMatrix.data, sizeof(float)*12);
	matrix[12] = matrix[13] = matrix[14] = 0;
	matrix[15] = 1;
}

void RigidBody::getGLTransform(float matrix[16]) const
{
	matrix[0] = (float)transformMatrix.data[0];
	matrix[1] = (float)transformMatrix.data[4];
	matrix[2] = (float)transformMatrix.data[8];
	matrix[3] = 0;

	matrix[4] = (float)transformMatrix.data[1];
	matrix[5] = (float)transformMatrix.data[5];
	matrix[6] = (float)transformMatrix.data[9];
	matrix[7] = 0;

	matrix[8] = (float)transformMatrix.data[2];
	matrix[9] = (float)transformMatrix.data[6];
	matrix[10] = (float)transformMatrix.data[10];
	matrix[11] = 0;

	matrix[12] = (float)transformMatrix.data[3];
	matrix[13] = (float)transformMatrix.data[7];
	matrix[14] = (float)transformMatrix.data[11];
	matrix[15] = 1;
}

Matrix4 RigidBody::getTransform() const
{
	return transformMatrix;
}


Vector3 RigidBody::getPointInLocalSpace(const Vector3 &point) const
{
	return transformMatrix.transformInverse(point);
}

Vector3 RigidBody::getPointInWorldSpace(const Vector3 &point) const
{
	return transformMatrix.transform(point);
}

Vector3 RigidBody::getDirectionInLocalSpace(const Vector3 &direction) const
{
	return transformMatrix.transformInverseDirection(direction);
}

Vector3 RigidBody::getDirectionInWorldSpace(const Vector3 &direction) const
{
	return transformMatrix.transformDirection(direction);
}


void RigidBody::setVelocity(const Vector3 &velocity)
{
	RigidBody::velocity = velocity;
}

void RigidBody::setVelocity(const float x, const float y, const float z)
{
	velocity.x = x;
	velocity.y = y;
	velocity.z = z;
}

void RigidBody::getVelocity(Vector3 *velocity) const
{
	*velocity = RigidBody::velocity;
}

Vector3 RigidBody::getVelocity() const
{
	return velocity;
}

void RigidBody::addVelocity(const Vector3 &deltaVelocity)
{
	velocity += deltaVelocity;
}

void RigidBody::setRotation(const Vector3 &rotation)
{
	RigidBody::rotation = rotation;
}

void RigidBody::setRotation(const float x, const float y, const float z)
{
	rotation.x = x;
	rotation.y = y;
	rotation.z = z;
}

void RigidBody::getRotation(Vector3 *rotation) const
{
	*rotation = RigidBody::rotation;
}

Vector3 RigidBody::getRotation() const
{
	return rotation;
}

void RigidBody::addRotation(const Vector3 &deltaRotation)
{
	rotation += deltaRotation;
}

void RigidBody::setAwake(const bool awake)
{
	if (awake) {
		isAwake= true;

		// Add a bit of motion to avoid it falling asleep immediately.
		motion = sleepEpsilon*2.0f;
	} else {
		isAwake = false;
		velocity.clear();
		rotation.clear();
	}
}

void RigidBody::setCanSleep(const bool canSleep)
{
	RigidBody::canSleep = canSleep;

	if (!canSleep && !isAwake) setAwake();
}


void RigidBody::getLastFrameAcceleration(Vector3 *acceleration) const
{
	*acceleration = lastFrameAcceleration;
}

Vector3 RigidBody::getLastFrameAcceleration() const
{
	return lastFrameAcceleration;
}

void RigidBody::clearAccumulators()
{
	forceAccum.clear();
	torqueAccum.clear();
}

void RigidBody::addForce(const Vector3 &force)
{
	forceAccum += force;
	isAwake = true;
}

void RigidBody::addForceAtBodyPoint(const Vector3 &force,
									const Vector3 &point)
{
	// Convert to coordinates relative to center of mass.
	Vector3 pt = getPointInWorldSpace(point);
	addForceAtPoint(force, pt);

	isAwake = true;
}

void RigidBody::addForceAtPoint(const Vector3 &force,
								const Vector3 &point)
{
	// Convert to coordinates relative to center of mass.
	Vector3 pt = point;
	pt -= position;

	forceAccum += force;
	torqueAccum += pt % force;

	isAwake = true;
}

void RigidBody::addTorque(const Vector3 &torque)
{
	torqueAccum += torque;
	isAwake = true;
}

void RigidBody::setAcceleration(const Vector3 &acceleration)
{
	RigidBody::acceleration = acceleration;
}

void RigidBody::setAcceleration(const float x, const float y, const float z)
{
	acceleration.x = x;
	acceleration.y = y;
	acceleration.z = z;
}

void RigidBody::getAcceleration(Vector3 *acceleration) const
{
	*acceleration = RigidBody::acceleration;
}

Vector3 RigidBody::getAcceleration() const
{
	return acceleration;
}