
#include "Collision_coarse.h"

BoundingSphere::BoundingSphere(const Vector3 &centre, float radius)
{
	BoundingSphere::centre = centre;
	BoundingSphere::radius = radius;
}

BoundingSphere::BoundingSphere(const BoundingSphere &one,
							   const BoundingSphere &two)
{
	Vector3 centreOffset = two.centre - one.centre;
	float distance = centreOffset.squareMagnitude();
	float radiusDiff = two.radius - one.radius;

	// Check if the larger sphere encloses the small one
	if (radiusDiff*radiusDiff >= distance)
	{
		if (one.radius > two.radius) 
		{ 
			centre = one.centre;
			radius = one.radius;
		}
		else
		{
			centre = two.centre;
			radius = two.radius;
		}
	}

	// Otherwise we need to work with partially 
	// overlapping spheres
	else
	{
		distance = sqrt(distance);
		radius = (distance + one.radius + two.radius) * 0.5f;

		// The new centre is based on one's centre, moved towards
		// two's centre by an ammount proportional to the spheres'
		// radii.
		centre = one.centre;
		if (distance > 0)
		{
			centre += centreOffset * ((radius - one.radius)/distance);
		}
	}
	
}

///>SphereBVHOverlap
bool BoundingSphere::overlaps(const BoundingSphere *other) const
{
	float distanceSquared = (centre - other->centre).squareMagnitude();
	return distanceSquared < (radius+other->radius)*(radius+other->radius);
}
///<SphereBVHOverlap

float BoundingSphere::getGrowth(const BoundingSphere &other) const
{
	BoundingSphere newSphere(*this, other);

	// We return a value proportional to the change in surface
	// area of the sphere.
	return newSphere.radius*newSphere.radius - radius*radius;
}
