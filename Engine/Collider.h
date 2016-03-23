#pragma once


#ifndef COLLIDER_H
#define COLLIDER_H

#include "GCData.h"
#include "Transform.h"

#include <Math/collision.h>

struct Collider : GCData<Collider>
{
	enum Shape {e_AABB, e_CIRCLE, e_HULL, e_PLANE, e_RAY} shape;

	union
	{
		meow::aabb aabb;
		meow::circle circle;
		meow::plane plane;
		meow::ray ray;
	};
	meow::convexHull hull;	

	Collider();
};

meow::collisionData evalCollision(const Transform &at, const Collider &ac, const Transform &bt, const Collider &bc);
#endif