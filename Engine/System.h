#pragma once


#ifndef SYSTEM_H
#define SYSTEM_H

#include "Entity.h"

class System
{
	virtual bool condition(Handle<Entity> i) = 0;
	virtual void update(Handle<Entity> i) = 0;
	virtual void onStep()
	{

	}
public:
	void step()
	{
		onStep();
		for (int i = 0; i < Entity::getData().size(); ++i)
			if (Entity::at(i).isValid() && condition(i))
				update(i);
	}
};

class BinarySystem
{
	virtual bool condition(Handle<Entity> i) = 0;
	virtual void update(Handle<Entity> i, Handle<Entity> j) = 0;
	virtual void onStep()
	{

	}
public:
	void step()
	{
		onStep();
		for (int i = 0; i < Entity::getData().size() - 1; ++i)
			for (int j = 0; j < Entity::getData().size(); ++j)
				if (Entity::at(i).isValid() && condition(i) && Entity::at(j).isValid() && condition(j))
					update(i, j);
	}
};


#endif