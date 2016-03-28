#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include "GCData.h"

#include "Collider.h"
#include "Lifespan.h"
#include "PlayerController.h"
#include "Rigidbody.h"
#include "Transform.h"


struct Entity : GCData<Entity>
{
	Handle<Collider> collider;
	Handle<Lifespan> lifespan;
	Handle<PlayerController> controller;
	Handle<Rigidbody> rigidbody;
	Handle<Transform> transform;

	void onFree()
	{
		Collider::free(collider.index);
		Lifespan::free(lifespan.index);
		PlayerController::free(controller.index);
		Rigidbody::free(rigidbody.index);
		Transform::free(transform.index);
	}
};

#endif