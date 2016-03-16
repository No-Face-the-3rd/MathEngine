#include "mat4.h"

#include <cassert>
#include <iostream>

void mathAsserts();

void main()
{
#ifndef _DEBUG
	return;
#endif


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
			assert(a <= b && a <= c);
			assert(c > b);
			assert(b >= a && c >= a);
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
			meow::vec3 a, b, c;
			a = c = 2.0f;
			b = 0.577350269f;
			assert(a.normal() == b);
			assert(a == c);
			a.normalize();
			assert(a == b);
			a = c;
			assert((b.magnitude() - 1.0f) < FLT_EPSILON);
			assert((a.dot(c) - 12.0f) < FLT_EPSILON);
			b = 0.0f;
			assert(a.cross(c) == b);
			a = { -2.0f,2.0f,-2.0f };
			c = { 2.0f,-2.0f,2.0f };
			assert(a.lerp(c, 0.5f) == b);
			b.y = 1.0f;
			c.y = 2.0f;
			assert(a.reflection(b) == c);
		}
		//external operators
		{
			meow::vec3 a, b, c;
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
			meow::vec3 a, b, c;
			a = b = 1.0f;
			c = 2.0f;
			assert(a == b);
			assert(a != c);
			assert(a < c);
			assert(a <= b && a <= c);
			assert(c > b);
			assert(b >= a && c >= a);
		}
		//external functions
		{
			meow::vec3 a, b, c;
			a = c = 2.0f;
			b = 0.577350269f;
			assert(meow::normal(a) == b);
			assert(a == c);
			meow::normalize(a);
			assert(a == b);
			a = c;
			assert((meow::magnitude(b) - 1.0f) < FLT_EPSILON);
			assert((meow::dot(a, c) - 12.0f) < FLT_EPSILON);
			b = 0.0f;
			assert(meow::cross(a, c) == b);
			a = { -2.0f,2.0f,-2.0f };
			c = { 2.0f,-2.0f,2.0f };
			assert(meow::lerp(a, c, 0.5f) == b);
			b.y = b.x = 1.0f;
			assert(meow::reflection(a, b) == c);
		}
	}
	//vec4
	{
		//internal operators
		{
			meow::vec4 a = { 2.0f,2.0f,2.0f,2.0f }, b;
			b = 2.0f;
			assert(a == b);
			meow::vec4 c = a;
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
			meow::vec4 a, b, c;
			a = c = 2.0f;
			b = 0.5f;
			assert(a.normal() == b);
			assert(a == c);
			a.normalize();
			assert(a == b);
			a = c;
			assert((b.magnitude() - 1.0f) < FLT_EPSILON);
			assert((a.dot(c) - 16.0f) < FLT_EPSILON);
			b = 0.0f;
			a = { -2.0f,2.0f,-2.0f,2.0f };
			c = { 2.0f,-2.0f,2.0f,-2.0f };
			assert(a.lerp(c, 0.5f) == b);
			b.z = 1.0f;
			c = { 2.0f,-2.0f,-2.0f,-2.0f };
			assert(a.reflection(b) == c);
		}
		//external operators
		{
			meow::vec4 a, b, c;
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
			assert(a * -1 == b);
			assert(-1.0f * a == b);
			b = 1.0f;
			assert(c / 3.0f == b);
		}
		//bool operators
		{
			meow::vec4 a, b, c;
			a = b = 1.0f;
			c = 2.0f;
			assert(a == b);
			assert(a != c);
			assert(a < c);
			assert(a <= b && a <= c);
			assert(c > b);
			assert(b >= a && c >= a);
		}
		//external functions
		{
			meow::vec4 a, b, c;
			a = c = 2.0f;
			b = 0.5f;
			assert(meow::normal(a) == b);
			assert(a == c);
			meow::normalize(a);
			assert(a == b);
			a = c;
			assert((meow::magnitude(b) - 1.0f) < FLT_EPSILON);
			assert((meow::dot(a, c) - 16.0f) < FLT_EPSILON);
			b = 0.0f;
			a = { -2.0f,2.0f,-2.0f,2.0f };
			c = { 2.0f,-2.0f,2.0f,-2.0f };
			assert(meow::lerp(a, c, 0.5f) == b);
			b.z = 1.0f;
			c = { 2.0f,-2.0f,-2.0f,-2.0f };
			assert(meow::reflection(a, b) == c);
		}

	}
	//mat3
	{
		//internal operators
		{
			meow::mat3 a, b = { 1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f }, c;
			c = { 1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f };
			assert(c == b);
			a = b;
			assert(a == c);
			c = { 2.0f,2.0f,2.0f,2.0f,2.0f,2.0f,2.0f,2.0f,2.0f };
			a += 1.0f;
			assert(a == c);
			a = b;
			a += b;
			assert(a == c);
			a -= 1.0f;
			assert(a == b);
			a = c;
			a -= b;
			assert(a == b);
			a *= 2.0f;
			assert(a == c);
			a = b;
			a *= c;
			c = { 6.0f,6.0f,6.0f,6.0f,6.0f,6.0f,6.0f,6.0f,6.0f };
			assert(a == c);
		}
		//internal functions
		{
			meow::mat3 a, b, c;
			c = { 1.0f,0.0f,0.0f,0.0f,1.0f,0.0f,0.0f,0.0f,1.0f };
			b = b.identity();
			a = { 2.0f,4.0f,7.0f,2.0f,5.0f,8.0f,3.0f,6.0f,9.0f };
			assert(c == b);
			assert(a * a.inverse() == a.identity());
			b = a.transpose();
			c = { 2.0f,2.0f,3.0f,4.0f,5.0f,6.0f,7.0f,8.0f,9.0f };
			assert(b == c);
			b = { 0.0f,1.0f,0.0f,-1.0f,0.0f,0.0f,0.0f,0.0f,1.0f };
			assert(a.rotate(PI / 2.0f) == b);
			assert(a.rotate(meow::vec2{ PI / 2.0f, PI / 2.0f }) == b);
			b = { 2.0f,0.0f,0.0f,0.0f,2.0f,0.0f,0.0f,0.0f,1.0f };
			assert(a.scale(meow::vec2{ 2.0f,2.0f }) == b);
			b = { 1.0f,0.0f,0.0f,0.0f,1.0f,0.0f,1.0f,1.0f,1.0f };
			assert(a.translate(meow::vec2{ 1.0f,1.0f }) == b);
			assert(fabs(a.determinant() - (-3.0f)) <= FLT_EPSILON);
		}
		//external operators
		{
			meow::mat3 a, b, c;
			a = { 1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f };
			b = a;
			c = { 2.0f,2.0f,2.0f,2.0f,2.0f,2.0f,2.0f,2.0f,2.0f };
			assert(a + 1.0f == c);
			assert(1.0f + a == c);
			assert(a + b == c);
			assert(c - 1.0f == a);
			assert(c - b == a);
			assert(a * 2.0f == c);
			assert(2.0f * a == c);
			b = { 6.0f,6.0f,6.0f,6.0f,6.0f,6.0f,6.0f,6.0f,6.0f };
			assert(a * c == b);
			meow::vec3 av, bv;
			av = 2.0f;
			bv = 6.0f;
			assert(a * av == bv);
			assert(av * a == bv);
		}
		//bool operators
		{
			meow::mat3 a, b, c;
			a = b = { 1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f };
			c = { 2.0f,2.0f,2.0f,2.0f,2.0f,2.0f,2.0f,2.0f,2.0f };
			assert(a == b);
			assert(a != c);
			assert(a < c);
			assert(a <= c && a <= b);
			assert(c > b);
			assert(c >= b && b >= a);
		}
		//external functions
		{
			meow::mat3 a, b, c;
			c = { 1.0f,0.0f,0.0f,0.0f,1.0f,0.0f,0.0f,0.0f,1.0f };
			b = meow::mat3Identity();
			a = { 2.0f,4.0f,7.0f,2.0f,5.0f,8.0f,3.0f,6.0f,9.0f };
			assert(c == b);
			assert(a * meow::inverse(a) == meow::mat3Identity());
			b = meow::transpose(a);
			c = { 2.0f,2.0f,3.0f,4.0f,5.0f,6.0f,7.0f,8.0f,9.0f };
			assert(b == c);
			b = { 0.0f,1.0f,0.0f,-1.0f,0.0f,0.0f,0.0f,0.0f,1.0f };
			assert(meow::rotate((PI / 2.0f)) == b);
			assert(meow::rotate(meow::vec2{ PI / 2.0f, PI / 2.0f }) == b);
			b = { 2.0f,0.0f,0.0f,0.0f,2.0f,0.0f,0.0f,0.0f,1.0f };
			assert(meow::scale(meow::vec2{ 2.0f,2.0f }) == b);
			b = { 1.0f,0.0f,0.0f,0.0f,1.0f,0.0f,1.0f,1.0f,1.0f };
			assert(meow::translate(meow::vec2{ 1.0f,1.0f }) == b);
			assert(fabs(meow::determinant(a) - (-3.0f)) <= FLT_EPSILON);
		}

	}
	//mat4
	{
		//internal operators
		{
			meow::mat4 a, b = { 1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f }, c;
			c = { 1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f };
			assert(c == b);
			a = b;
			assert(a == c);
			c = { 2.0f,2.0f,2.0f,2.0f,2.0f,2.0f,2.0f,2.0f,2.0f,2.0f,2.0f,2.0f,2.0f,2.0f,2.0f,2.0f };
			a += 1.0f;
			assert(a == c);
			a = b;
			a += b;
			assert(a == c);
			a -= 1.0f;
			assert(a == b);
			a = c;
			a -= b;
			assert(a == b);
			a *= 2.0f;
			assert(a == c);
			a = b;
			a *= c;
			c = { 8.0f,8.0f,8.0f,8.0f,8.0f,8.0f,8.0f,8.0f,8.0f,8.0f,8.0f,8.0f,8.0f,8.0f,8.0f,8.0f };
			assert(a == c);
		}
		//internal functions
		{
			meow::mat4 a, b, c;
			c = { 1.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f,0.0f,0.0f,0.0f,1.0f };
			b = b.identity();
			a = { 1.0f,5.0f,8.0f,4.0f,2.0f,6.0f,7.0f,2.0f,3.0f,7.0f,6.0f,3.0f,4.0f,8.0f,8.0f,4.0f };
			assert(c == b);
			assert(a * a.inverse() == a.identity());
			b = a.transpose();
			c = { 1.0f,2.0f,3.0f,4.0f,5.0f,6.0f,7.0f,8.0f,8.0f,7.0f,6.0f,8.0f,4.0f,2.0f,3.0f,4.0f };
			assert(b == c);
			b = { 1.0f, 0.0f,0.0f,0.0f,0.0f,1.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f,-2.0f,-2.0f,2.0f,1.0f };
			assert(a.orthographicProjection(1.0f, 3.0f, 1.0f, 3.0f, 3.0f, 1.0f) == b);
			b = { 1.0f, 0.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f,0.0f,-1.0f,0.0f,0.0f,0.0f,0.0f,0.0f,1.0f };
			assert(a.rotate(PI / 2.0f, 0) == b);
			assert(a.rotate(meow::vec3{ 1.0f,0.0f,0.0f }, PI / 2.0f) == b);
			b = b.identity();
			b.c[0].v[0] = b.c[1].v[1] = b.c[2].v[2] = 2.0f;
			assert(a.scale(meow::vec3{ 2.0f,2.0f,2.0f }) == b);
			b = b.identity();
			b.c[3].xyz += 1.0f;
			assert(a.translate(meow::vec3{ 1.0f,1.0f,1.0f }) == b);
			assert(fabs(a.determinant() - 36.0f) <= FLT_EPSILON);
			meow::mat3 am;
			am = { 6.0f,7.0f,2.0f,7.0f,6.0f,3.0f,8.0f,8.0f,4.0f };
			assert(a.minor(0, 0) == am);
		}
		//external operators
		{
			meow::mat4 a, b, c;
			a = b = { 1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f };
			c = { 2.0f,2.0f,2.0f,2.0f,2.0f,2.0f,2.0f,2.0f,2.0f,2.0f,2.0f,2.0f,2.0f,2.0f,2.0f,2.0f };
			assert(a + 1.0f == c);
			assert(1.0f + a == c);
			assert(a + b == c);
			assert(c - 1.0f == a);
			assert(c - b == a);
			assert(a * 2.0f == c);
			assert(2.0f * a == c);
			b = { 8.0f,8.0f,8.0f,8.0f,8.0f,8.0f,8.0f,8.0f,8.0f,8.0f,8.0f,8.0f,8.0f,8.0f,8.0f,8.0f };
			assert(a * c == b);
			meow::vec4 av, bv;
			av = 2.0f;
			bv = 8.0f;
			assert(a * av == bv);
			assert(av * a == bv);
		}
		//bool operators
		{
			meow::mat4 a, b, c;
			a = b = { 1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f };
			c = meow::mat4{ 1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f,1.0f } * 2.0f;
			assert(a == b);
			assert(a != c);
			assert(a < c);
			assert(a <= c && a <= b);
			assert(c > b);
			assert(c >= b&& b >= a);
		}
		//external functions
		{
			meow::mat4 a, b, c;
			c = { 1.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f,0.0f,0.0f,0.0f,1.0f };
			b = meow::mat4Identity();
			a = { 1.0f,5.0f,8.0f,4.0f,2.0f,6.0f,7.0f,2.0f,3.0f,7.0f,6.0f,3.0f,4.0f,8.0f,8.0f,4.0f };
			assert(c == b);
			assert(a * meow::inverse(a) == meow::mat4Identity());
			b = meow::transpose(a);
			c = { 1.0f,2.0f,3.0f,4.0f,5.0f,6.0f,7.0f,8.0f,8.0f,7.0f,6.0f,8.0f,4.0f,2.0f,3.0f,4.0f };
			assert(b == c);
			b = { 1.0f, 0.0f,0.0f,0.0f,0.0f,1.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f,-2.0f,-2.0f,2.0f,1.0f };
			assert(meow::orthographicProjection(1.0f, 3.0f, 1.0f, 3.0f, 3.0f, 1.0f) == b);
			b = { 1.0f, 0.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f,0.0f,-1.0f,0.0f,0.0f,0.0f,0.0f,0.0f,1.0f };
			assert(meow::rotate(PI / 2.0f, 0) == b);
			assert(meow::rotate(meow::vec3{ 1.0f,0.0f,0.0f }, PI / 2.0f) == b);
			b = meow::mat4Identity();
			b.c[0].v[0] = b.c[1].v[1] = b.c[2].v[2] = 2.0f;
			assert(meow::scale(meow::vec3{ 2.0f,2.0f,2.0f }) == b);
			b = b.identity();
			b.c[3].xyz += 1.0f;
			assert(meow::translate(meow::vec3{ 1.0f,1.0f,1.0f }) == b);
			assert(fabs(meow::determinant(a) - 36.0f) <= FLT_EPSILON);
			meow::mat3 am;
			am = { 6.0f,7.0f,2.0f,7.0f,6.0f,3.0f,8.0f,8.0f,4.0f };
			assert(meow::minor(a, 0, 0) == am);
			b = { 6.0f,7.0f,0.0f,2.0f,7.0f,6.0f,0.0f,3.0f,0.0f,0.0f,1.0f,0.0f,8.0f,8.0f,0.0f,4.0f };
			assert(meow::mat3ToMat4(am) == b);
		}
	}
	return;
}