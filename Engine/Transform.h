#pragma once


#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "GCData.h"

#include <Math/collision.h>

#include <list>

class Transform : public GCData<Transform>
{
	Transform *e_parent;
	std::list<Transform*> e_children;
	meow::vec2 pos, scale;
	float angle;
public:
	Transform();
	~Transform();

	meow::mat3 getGlobalTransform() const;

	void setParent(Transform* a);
	void setPosition(const meow::vec2 &a);
	void setScale(const meow::vec2 &a);
	void setAngle(const float &a);

	meow::vec2 getPosition() const;
	meow::vec2 getScale() const;
	float getAngle() const;
};




#endif