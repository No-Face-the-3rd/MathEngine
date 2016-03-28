#include "shapes.h"


meow::vec2 meow::aabb::min() const
{
	return (pos - (dim / 2.0f));
}
meow::vec2 meow::aabb::max() const
{
	return (pos + (dim / 2.0f));
}

meow::aabb meow::aabb::genaabb(const std::vector<vec2>& corners)
{
	meow::aabb bb;
	float xMin, yMin, xMax, yMax;
	xMin = yMin = FLT_MAX;
	xMax = yMax = FLT_MIN;
	for each(meow::vec2 corner in corners)
	{
		if (corner.x < xMin)
			xMin = corner.x;
		if (corner.y < yMin)
			yMin = corner.y;
		if (corner.x > xMax)
			xMax = corner.x;
		if (corner.y > yMax)
			yMax = corner.y;
	}
	bb.dim.x = xMax - xMin;
	bb.dim.y = yMax - yMin;
	bb.pos.x = xMin + bb.dim.x * 0.5f;
	bb.pos.y = yMin + bb.dim.y * 0.5f;
	return bb;
}

void meow::aabb::rotate(float a)
{
	float w, h;
	w = dim.x * std::fabs(std::cos(a)) + dim.y * std::fabs(std::sin(a));
	h = dim.x * std::fabs(std::sin(a)) + dim.y * std::fabs(std::cos(a));
	dim.x = w;
	dim.y = h;
}

meow::aabb meow::operator*(const meow::mat3 &a, const meow::aabb &b)
{
	meow::aabb tmp;
	meow::vec2 min = b.min(), max = b.max(), tmpMin = a.c[2].xy, tmpMax = a.c[2].xy;
	float c, d;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			c = min.v[j] * a.c[j].v[i];
			d = max.v[j] * a.c[j].v[i];
			if (c < d) 
				std::swap(c, d);
			tmpMin += c;
			tmpMax += d;
		}
	tmp.pos = { (tmpMin + tmpMax) / 2.0f };
	tmp.dim = { (tmpMax - tmpMin) };
	return tmp;
}
meow::circle meow::operator*(const meow::mat3 &a, const meow::circle &b)
{
	meow::circle tmp;
	tmp.pos = (a * meow::vec3{ b.pos.x,b.pos.y,1.0f }).xy;
	tmp.rad = std::fmaxf((a * meow::vec3{ b.rad,0.0f,0.0f }).magnitude(), (a * meow::vec3{ 0.0f,b.rad ,0.0f }).magnitude());
	return tmp;
}
meow::convexHull meow::operator*(const meow::mat3 &a, const meow::convexHull &b)
{
	meow::convexHull tmp;
	for each(meow::vec2 c in b.verts)
		tmp.verts.push_back((a * meow::vec3{ c.x,c.y,1.0f }).xy);
	return tmp;
}
meow::plane meow::operator*(const meow::mat3 &a, const meow::plane &b)
{
	meow::vec3 nor = { b.normal.x, b.normal.y,0.0f }, pos = { b.pos.x,b.pos.y,1.0f };
	return { (a * pos).xy, (a * nor).xy };
}
meow::ray meow::operator*(const meow::mat3 &a, const meow::ray &b)
{
	meow::ray tmp;
	meow::vec3 dir = { b.dir.x, b.dir.y,0.0f }, pos = { b.pos.x, b.pos.y, 1.0f };
	dir *= b.length;
	tmp = meow::ray{ (a * pos).xy, (a * dir).xy };
	tmp.length = tmp.dir.magnitude();
	tmp.dir = tmp.dir.normal();
	return tmp;
}