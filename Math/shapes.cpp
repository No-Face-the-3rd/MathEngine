#include "shapes.h"


meow::vec2 meow::aabb::min() const
{
	return (pos - (dim / 2.0f));
}
meow::vec2 meow::aabb::max() const
{
	return (pos + (dim / 2.0f));
}

meow::circle meow::operator*(const mat3 &a, const circle &b)
{

}