#include "shapes.h"


meow::vec2 meow::aabb::min() const
{
	return (pos - (dim / 2.0f));
}
meow::vec2 meow::aabb::max() const
{
	return (pos + (dim / 2.0f));
}

meow::circle meow::operator*(const meow::mat3 &a, const meow::circle &b)
{
	meow::circle circle;
	circle.pos = (a * meow::vec3{ b.pos.x,b.pos.y,1.0f }).xy;
	circle.rad = 0.0f;
}