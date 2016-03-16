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

	circle operator*(const mat3 &a, const circle &b);
	aabb operator*(const mat3 &a, const aabb &b);
	plane operator*(const mat3 &a, const plane &b);
	ray operator*(const mat3 &a, const ray &b);
	convexHull operator*(const mat3 &a, const ray &b);
}


#endif