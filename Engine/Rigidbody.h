#pragma once


#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "GCData.h"
#include "Transform.h"

class Rigidbody : public GCData<Rigidbody>
{
public:
	union {
		struct {
			float mass, drag, torque, angularVelocity, angularAcceleration;
			meow::vec2 velocity, acceleration, force, jerk;
		};
		struct {
			float m, d, t, aVel, aAcc;
			meow::vec2 vel, acc, f, j;
		};
	};

	Rigidbody();
	~Rigidbody();
	void addForce(const meow::vec2 &a);
	void addTorque(const float &a);
	void integrate(Transform *a, const float &dt);
};



#endif