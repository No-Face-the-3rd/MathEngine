#include "mat4.h"

#include <cassert>
#include <iostream>

void mathAsserts();

void main()
{
	meow::mat4 rawr = { 1,2,3,4,4,6,5,8,9,1,2,3,4,5,6,7 };
	
	std::cout << rawr << std::endl;

	std::cout << rawr.determinant() << std::endl << std::endl;

	std::cout << rawr * rawr << std::endl;
	std::cout << rawr + rawr << std::endl;
	std::cout << rawr - rawr << std::endl;
	
	std::cout << rawr.inverse() << std::endl;
	std::cout << rawr * rawr.inverse() << std::endl;
	std::cout << rawr.inverse().inverse() << std::endl;


	mathAsserts();

	system("pause");
	return;
}

void mathAsserts()
{
#ifndef _DEBUG
	return;
#endif
	//vec2
	{
		//internal operators
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
			b -= 1.0f;
			c = 4.0f;
			assert(b == c);
			b -= a;
			c = 1.0f;
			assert(b == c);
			b *= 3.0f;
			assert(b == a);
			b /= 3.0f;
			assert(b == c);
		}
		//internal functions
		{
			meow::vec2 a, b, c;
			a = c = 2.0f;
			b = 0.70710678f;
			assert(a.normal() == b);
			assert(a == c);
			a.normalize();
			assert(a == b);
			a = c;
			assert((b.magnitude() - 1.0f) < FLT_EPSILON);
			assert((a.dot(c) - 8.0f) < FLT_EPSILON);
			c = { -c.y,c.x };
			assert(a.perpendicular() == c);
			assert((a.angle() - 0.785398f) < FLT_EPSILON);
			c.y = 6.0f;
			b = { 0.0f,4.0f };
			assert(a.lerp(c, 0.5f) == b);
			c = { -2.0f,2.0f };
			assert(a.reflection(b) == c);
		}
		//external operators
		{
			meow::vec2 a, b, c;
			a = 2.0f;
			b = 1.0f;
			c = 3.0f;
			assert(a + b == c);
			assert(a + 1.0f == c);
			assert(1.0f + a == c);
			assert(c - b == a);
			assert(c - 1.0f == a);
			b = -2.0f;
			assert(-a == b);
			assert(a * -1.0f == b);
			assert(-1.0f * a == b);
			b = 1.0f;
			assert(c / 3.0f == b);
		}
		//bool operators
		{
			meow::vec2 a, b, c;
			a = b = 1.0f;
			c = 2.0f;
			assert(a == b);
			assert(a != c);
			assert(a < c);
			assert(a <= b);
			assert(c > b);
			assert(b >= a);
		}
		//external functions
		{
			meow::vec2 a, b, c;
			a = c = 2.0f;
			b = 0.70710678f;
			assert(meow::normal(a) == b);
			assert(a == c);
			meow::normalize(a);
			assert(a == b);
			a = c;
			assert((meow::magnitude(b) - 1.0f) < FLT_EPSILON);
			assert((meow::dot(a, c) - 8.0f) < FLT_EPSILON);
			c = { -c.y,c.x };
			assert(meow::perpendicular(a) == c);
			assert((meow::angle(a) - 0.785398f) < FLT_EPSILON);
			c.y = 6.0f;
			b = { 0.0f,4.0f };
			assert(meow::lerp(a, c, 0.5f) == b);
			c = { -2.0f,2.0f };
			assert(meow::reflection(a, b) == c);
		}
	}
	//vec3
	{
		//internal operators
		{
			meow::vec3 a, b, c;
			a = 2.0f;
			b = meow::vec2{ 2.0f,2.0f };
			c = { 2.0f,2.0f,2.0f };
			b.z = 2.0f;
			assert(a == b);
			assert(a == c);
			a += 2.0f;
			b = 4.0f;
			assert(a == b);
			a = 2.0f;
			b = { 4.0f,4.0f,2.0f };
			a += meow::vec2{ 2.0f,2.0f };
			assert(a == b);
			a = 2.0f;
			b = 4.0f;
			a += c;
			assert(a == b);
			a -= c;
			assert(a == c);
			a = b;
			a -= 2.0f;
			assert(a == c);
			a = b;
			b = { 2.0f,2.0f,4.0f };
			a -= meow::vec2{ 2.0f,2.0f };
			assert(a == b);
			a = c;
			b = 4.0f;
			a *= 2.0f;
			assert(a == b);
			a /= 2.0f;
			assert(a == c);
		}
		//internal functions
		{

		}
	}
}