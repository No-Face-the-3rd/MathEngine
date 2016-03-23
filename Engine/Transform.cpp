#include "Transform.h"

Transform::Transform() : e_parent(nullptr), scale(meow::vec2{ 1.0f,1.0f }), pos(meow::vec2{ 0.0f,0.0f }), angle(0.0f)
{
}
Transform::~Transform()
{
	auto t = e_children;
	for each(Transform* child in t)
		child->setParent(e_parent);
	setParent(nullptr);
}

meow::mat3 Transform::getGlobalTransform() const
{
	return (e_parent ? e_parent->getGlobalTransform() : meow::mat3Identity()) * meow::translate(pos) * meow::scale(scale) * meow::rotate(angle);
}

void Transform::setParent(Transform* a_parent)
{
	if (e_parent)
		e_parent->e_children.remove(this);

	if (a_parent)
		a_parent->e_children.push_front(this);
	e_parent = a_parent;
}
void Transform::setPosition(const meow::vec2 &a)
{
	pos = a;
}
void Transform::setScale(const meow::vec2 &a)
{
	scale = a;
}
void Transform::setAngle(const float &a)
{
	angle = a;
}

meow::vec2 Transform::getPosition() const
{
	return pos;
}
meow::vec2 Transform::getScale() const
{
	return scale;
}
float Transform::getAngle() const
{
	return angle;
}
