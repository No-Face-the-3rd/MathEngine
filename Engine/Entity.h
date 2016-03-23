#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include "GCData.h"

#include "Collider.h"
#include "Transform.h"


struct Entity : GCData<Entity>
{
	Handle<Transform> transform;
	Handle<Collider> collider;
};

#endif