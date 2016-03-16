#pragma once

#ifndef SHAPES
#define SHAPES

#include "mat4.h"

#include <vector>
namespace meow
{
	struct circle
	{
		meow::vec2 pos;
		float rad;
	};
	struct aabb
	{
		meow::vec2 pos, dim;
		meow::vec2 min() const;
		meow::vec2 max() const;
	};
	struct plane
	{
		meow::vec2 pos, normal;
	};
	struct ray
	{
		meow::vec2 pos, dir;
		float length;
	};
	struct convexHull
	{
		std::vector<meow::vec2> verts;
	};

	circle operator*(const meow::mat3 &a, const meow::circle &b);
	aabb operator*(const meow::mat3 &a, const meow::aabb &b);
	plane operator*(const meow::mat3 &a, const meow::plane &b);
	ray operator*(const meow::mat3 &a, const meow::ray &b);
	convexHull operator*(const meow::mat3 &a, const meow::convexHull &b);
}


#endif