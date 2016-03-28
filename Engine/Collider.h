#pragma once


#ifndef COLLIDER_H
#define COLLIDER_H

#include "GCData.h"
#include "Transform.h"

#include <Math/Math.h>

struct Collider : GCData<Collider>
{
	enum Shape {e_AABB = 1, e_CIRCLE = 2, e_HULL = 4, e_PLANE = 8, e_RAY = 16} shape;

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