#include "Collider.h"

Collider::Collider() : shape(e_CIRCLE), circle{ {0.0f,0.0f}, 1.0f }
{
}

meow::collisionData evalCollision(const Transform &at, const Collider &ac, const Transform &bt, const Collider &bc)
{
	meow::collisionData tmp;



	return tmp;
}