#include "Collider.h"

Collider::Collider() : shape(e_CIRCLE), circle{ {0.0f,0.0f}, 1.0f }
{
}


meow::collisionData evalCollision(const Transform &at, const Collider &ac, const Transform &bt, const Collider &bc)
{
	meow::collisionData tmp;

	switch (ac.shape | (bc.shape << 5))
	{
	case Collider::e_AABB | (Collider::e_AABB << 5):
		tmp = meow::cTest(at.getGlobalTransform() * ac.aabb, bt.getGlobalTransform() * bc.aabb);
	case Collider::e_AABB | (Collider::e_CIRCLE << 5):
		tmp = meow::cTest(at.getGlobalTransform() * ac.aabb, bt.getGlobalTransform() * bc.circle);
	case Collider::e_AABB | (Collider::e_HULL << 5):
		tmp = meow::cTest(at.getGlobalTransform() * ac.aabb, bt.getGlobalTransform() * bc.hull);
	case Collider::e_AABB | (Collider::e_PLANE << 5):
		tmp = meow::cTest(at.getGlobalTransform() * ac.aabb, bt.getGlobalTransform() * bc.plane);
	case Collider::e_AABB | (Collider::e_RAY << 5):
		tmp = meow::cTest(at.getGlobalTransform() * ac.aabb, bt.getGlobalTransform() * bc.ray);
	case Collider::e_CIRCLE | (Collider::e_AABB << 5):
		tmp = meow::cTest(at.getGlobalTransform() * ac.circle, bt.getGlobalTransform() * bc.aabb);
	case Collider::e_CIRCLE | (Collider::e_CIRCLE << 5):
		tmp = meow::cTest(at.getGlobalTransform() * ac.circle, bt.getGlobalTransform() * bc.circle);
	case Collider::e_CIRCLE | (Collider::e_HULL << 5):
		tmp = meow::cTest(at.getGlobalTransform() * ac.circle, bt.getGlobalTransform() * bc.hull);
	case Collider::e_CIRCLE | (Collider::e_PLANE << 5):
		tmp = meow::cTest(at.getGlobalTransform() * ac.circle, bt.getGlobalTransform() * bc.plane);
	case Collider::e_CIRCLE | (Collider::e_RAY << 5):
		tmp = meow::cTest(at.getGlobalTransform() * ac.circle, bt.getGlobalTransform() * bc.ray);
	case Collider::e_HULL | (Collider::e_AABB << 5) :
		tmp = meow::cTest(at.getGlobalTransform() * ac.hull, bt.getGlobalTransform() * bc.aabb);
	case Collider::e_HULL | (Collider::e_CIRCLE << 5) :
		tmp = meow::cTest(at.getGlobalTransform() * ac.hull, bt.getGlobalTransform() * bc.circle);
	case Collider::e_HULL | (Collider::e_HULL << 5) :
		tmp = meow::cTest(at.getGlobalTransform() * ac.hull, bt.getGlobalTransform() * bc.hull);
	case Collider::e_HULL | (Collider::e_PLANE << 5) :
		tmp = meow::cTest(at.getGlobalTransform() * ac.hull, bt.getGlobalTransform() * bc.plane);
	case Collider::e_HULL | (Collider::e_RAY << 5) :
		tmp = meow::cTest(at.getGlobalTransform() * ac.hull, bt.getGlobalTransform() * bc.ray);
	case Collider::e_PLANE | (Collider::e_AABB << 5) :
		tmp = meow::cTest(at.getGlobalTransform() * ac.plane, bt.getGlobalTransform() * bc.aabb);
	case Collider::e_PLANE | (Collider::e_CIRCLE << 5) :
		tmp = meow::cTest(at.getGlobalTransform() * ac.plane, bt.getGlobalTransform() * bc.circle);
	case Collider::e_PLANE | (Collider::e_HULL << 5) :
		tmp = meow::cTest(at.getGlobalTransform() * ac.plane, bt.getGlobalTransform() * bc.hull);
	case Collider::e_PLANE | (Collider::e_PLANE << 5) :
		tmp = meow::cTest(at.getGlobalTransform() * ac.plane, bt.getGlobalTransform() * bc.plane);
	case Collider::e_PLANE | (Collider::e_RAY << 5) :
		tmp = meow::cTest(at.getGlobalTransform() * ac.plane, bt.getGlobalTransform() * bc.ray);
	case Collider::e_RAY | (Collider::e_AABB << 5) :
		tmp = meow::cTest(at.getGlobalTransform() * ac.ray, bt.getGlobalTransform() * bc.aabb);
	case Collider::e_RAY | (Collider::e_CIRCLE << 5) :
		tmp = meow::cTest(at.getGlobalTransform() * ac.ray, bt.getGlobalTransform() * bc.circle);
	case Collider::e_RAY | (Collider::e_HULL << 5) :
		tmp = meow::cTest(at.getGlobalTransform() * ac.ray, bt.getGlobalTransform() * bc.hull);
	case Collider::e_RAY | (Collider::e_PLANE << 5) :
		tmp = meow::cTest(at.getGlobalTransform() * ac.ray, bt.getGlobalTransform() * bc.plane);
	case Collider::e_RAY | (Collider::e_RAY << 5) :
		tmp = meow::cTest(at.getGlobalTransform() * ac.ray, bt.getGlobalTransform() * bc.ray);
	}
	return tmp;
}