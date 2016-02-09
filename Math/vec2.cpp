#pragma once

#include "vec2.h"

meow::vec2 &meow::vec2::operator=(const float &a)
{
	this->x = a;
	this->y = a;
	return *this;
}
meow::vec2 &meow::vec2::operator=(const vec2 &a)
{
	this->x = a.x;
	this->y = a.y;
	return *this;
}

meow::vec2 &meow::vec2::operator+=(const float &a)
{
	this->x += a;
	this->y += a;
	return *this;
}
meow::vec2 &meow::vec2::operator+=(const vec2 &a)
{
	this->x += a.x;
	this->y += a.y;
	return *this;
}

meow::vec2 &meow::vec2::operator-=(const float &a)
{
	this->x -= a;
	this->y -= a;
	return *this;
}
meow::vec2 &meow::vec2::operator-=(const vec2 &a)
{
	this->x -= a.x;
	this->y -= a.y;
	return *this;
}

meow::vec2 &meow::vec2::operator*=(const float &a)
{
	this->x *= a;
	this->y *= a;
	return *this;
}

meow::vec2 &meow::vec2::operator/=(const float &a)
{
	this->x /= a;
	this->y /= a;
	return *this;
}

meow::vec2 meow::vec2::normal() const
{
	return vec2{ this->x / this->magnitude(), this->y / this->magnitude() };
}
void meow::vec2::normalize()
{
	*this /= this->magnitude();
	return;
}
float meow::vec2::magnitude() const
{
	return sqrt(pow(x, 2) + pow(y, 2));
}
float meow::vec2::dot(const vec2 &a) const
{
	return this->x * a.x + this->y * a.y;
}
meow::vec2 meow::vec2::perpendicular() const
{
	return vec2{ -this->y,this->x };
}
float meow::vec2::angle() const
{
	return acosf(this->normal().dot(vec2{ 1.0f,0.0f }));
}
meow::vec2 meow::vec2::lerp(const vec2 &a, const float &b) const
{
	return (*this + std::max(std::min(b, 1.0f), 0.0f) * (a - *this));
}
meow::vec2 meow::vec2::reflection(const vec2 &a) const
{
	return (*this - 2 * (this->dot(a.normal())) * a.normal());
}

meow::vec2 meow::operator+(const vec2 &a, const vec2 &b)
{
	return vec2{ a.x + b.x,a.y + b.y };
}
meow::vec2 meow::operator+(const vec2 &a, const float &b)
{
	return vec2{ a.x + b,a.y + b };
}
meow::vec2 meow::operator+(const float &a, const vec2 &b)
{
	return vec2{ b.x + a, b.y + a };
}

meow::vec2 meow::operator-(const vec2 &a, const vec2 &b)
{
	return vec2{ a.x - b.x,a.y - b.y };
}
meow::vec2 meow::operator-(const vec2 &a, const float &b)
{
	return vec2{ a.x - b,a.y - b };
}

meow::vec2 meow::operator-(const vec2 &a)
{
	return vec2{ -a.x,-a.y };
}

meow::vec2 meow::operator*(const vec2 &a, const float &b)
{
	return vec2{ a.x*b,a.y*b };
}
meow::vec2 meow::operator*(const float &a, const vec2 &b)
{
	return vec2{ b.x * a, b.y * a };
}

meow::vec2 meow::operator/(const vec2 &a, const float &b)
{
	return vec2{ a.x / b,a.y / b };
}

bool meow::operator==(const vec2 &a, const vec2 &b)
{
	return (fabs(b.x - a.x) < FLT_EPSILON && fabs(b.y - a.y) < FLT_EPSILON);
}
bool meow::operator!=(const vec2 &a, const vec2 &b)
{
	return !(a == b);
}
bool meow::operator<(const vec2 &a, const vec2 &b)
{
	return (a.x < b.x && a.y < b.y);
}
bool meow::operator<=(const vec2 &a, const vec2 &b)
{
	return (a < b || a == b);
}
bool meow::operator>(const vec2 &a, const vec2 &b)
{
	return !(a <= b);
}
bool meow::operator>=(const vec2 &a, const vec2 &b)
{
	return !(a < b);
}

std::ostream &meow::operator<<(std::ostream &os, const vec2 &p)
{
	os << p.x << "," << p.y;
	return os;
}

meow::vec2 meow::normal(const vec2 &a)
{
	return a.normal();
}
void meow::normalize(vec2 &a)
{
	a.normalize();
	return;
}
meow::vec2 meow::perpendicular(const vec2 &a)
{
	return a.perpendicular();
}
float meow::dot(const vec2 &a, const vec2 &b)
{
	return a.dot(b);
}
float meow::angle(const vec2 &a)
{
	return a.angle();
}
meow::vec2 meow::lerp(const vec2 &a, const vec2 &b, const float &c)
{
	return a.lerp(b, c);
}
meow::vec2 meow::reflection(const vec2 &a, const vec2 &b)
{
	return a.reflection(b);
}