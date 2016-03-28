#pragma once


#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "GCData.h"

class PlayerController : public GCData<PlayerController>
{
public:
	char left, right, forward, back;
	float speed, turnSpeed;

	PlayerController() : left('A'), right('D'), forward('W'), back('S'), speed(30.0f), turnSpeed(1.0f)
	{

	}
};

#endif