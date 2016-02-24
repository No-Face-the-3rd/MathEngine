#include "mat4.h"

#include <cassert>
#include <iostream>

void mathAsserts();

void main()
{

	system("pause");
	return;
}

void mathAsserts()
{
#ifndef _DEBUG
	return;
#endif

	{
		meow::vec2 a = { 2.0f,2.0f }, b;
		b = 2.0f;
		assert(a == b);
		meow::vec2 c = a;
		assert(c == b);
		a += 1.0f;
		c = 3.0f;
		assert(a == c);
		b += a;
		c = 5.0f;
		assert(b == c);
	}
}