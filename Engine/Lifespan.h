#pragma once


#ifndef LIFESPAN_H
#define LIFESPAN_H

#include "GCData.h"

class Lifespan : public GCData<Lifespan>
{
public:
	float currAge, maxAge;

	Lifespan() : currAge(0.0f), maxAge(5.0f)
	{

	}
};

#endif