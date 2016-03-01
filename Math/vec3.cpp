#include "vec3.h"

meow::vec3 &meow::vec3::operator=(const float &a)
{
	this->x = a;
	this->y = a;
	this->z = a;
	return *this;
}
meow::vec3 &meow::vec3::operator=(const vec2 &a)
{
	this->x = a.x;
	this->y = a.y;
	this->z = 0.0f;
	return *this;
}
meow::vec3 &meow::vec3::operator=(const vec3 &a)
{
	this->x = a.x;
	this->y = a.y;
	this->z = a.z;
	return *this;
}

meow::vec3 &meow::vec3::operator+=(const float &a)
{
	this->x += a;
	this->y += a;
	this->z += a;
	return *this;
}
meow::vec3 &meow::vec3::operator+=(const vec2 &a)
{
	this->x += a.x;
	this->y += a.y;
	return *this;
}
meow::vec3 &meow::vec3::operator+=(const vec3 &a)
{
	this->x += a.x;
	this->y += a.y;
	this->z += a.z;
	return *this;
}

meow::vec3 &meow::vec3::operator-=(const float &a)
{
	this->x -= a;
	this->y -= a;
	this->z -= a;
	return *this;
}
meow::vec3 &meow::vec3::operator-=(const vec2 &a)
{
	this->x -= a.x;
	this->y -= a.y;
	return *this;
}
meow::vec3 &meow::vec3::operator-=(const vec3 &a)
{
	this->x -= a.x;
	this->y -= a.y;
	this->z -= a.z;
	return *this;
}

meow::vec3 &meow::vec3::operator*=(const float &a)
{
	this->x *= a;
	this->y *= a;
	this->z *= a;
	return *this;
}

meow::vec3 &meow::vec3::operator/=(const float &a)
{
	this->x /= a;
	this->y /= a;
	this->z /= a;
	return *this;
}

meow::vec3 meow::vec3::normal() const
{
	return vec3{ this->x / this->magnitude(), this->y / this->magnitude(), this->z / this->magnitude() };
}
void meow::vec3::normalize()
{
	*this /= this->magnitude();
	return;
}
float meow::vec3::magnitude() const
{
	return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}
float meow::vec3::dot(const vec3 &a) const
{
	return (this->xy.dot(a.xy) + this->z * a.z);
}
meow::vec3 meow::vec3::cross(const vec3 &a) const
{
	return vec3{ this->y * a.z - this->z * a.y,this->z * a.x - this->x * a.z,this->x * a.y - this->y * a.x };
}
meow::vec3 meow::vec3::lerp(const vec3 &a, const float &b) const
{
	return (*this + std::max(std::min(b, 1.0f), 0.0f) * (a - *this));
}
meow::vec3 meow::vec3::reflection(const vec3 &a) const
{
	return (*this - 2 * (this->dot(a.normal())) * a.normal());
}

meow::vec3 meow::operator+(const vec3 &a, const float &b)
{
	return vec3{ a.x + b, a.y + b, a.z + b };
}
meow::vec3 meow::operator+(const float &a, const vec3 &b)
{
	return vec3{ a + b.x, a + b.y, a + b.z };
}
meow::vec3 meow::operator+(const vec3 &a, const vec2 &b)
{
	return vec3{ a.x + b.x, a.y + b.y, a.z };
}
meow::vec3 meow::operator+(const vec2 &a, const vec3 &b)
{
	return vec3{ a.x + b.x, a.y + b.y, b.z };
}
meow::vec3 meow::operator+(const vec3 &a, const vec3 &b)
{
	return vec3{ a.x + b.x, a.y + b.y, a.z + b.z };
}

meow::vec3 meow::operator-(const vec3 &a, const float &b)
{
	return vec3{ a.x - b, a.y - b, a.z - b };
}
meow::vec3 meow::operator-(const vec3 &a, const vec2 &b)
{
	return vec3{ a.x - b.x, a.y - b.y, a.z };
}
meow::vec3 meow::operator-(const vec3&a, const vec3 &b)
{
	return vec3{ a.x - b.x,a.y - b.y,a.z - b.z };
}

meow::vec3 meow::operator-(const vec3&a)
{
	return vec3{ -a.x,-a.y,-a.z };
}

meow::vec3 meow::operator*(const vec3 &a, const float &b)
{
	return vec3{ a.x * b, a.y * b, a.z * b };
}
meow::vec3 meow::operator*(const float &a, const vec3 &b)
{
	return vec3{ a * b.x, a * b.y, a * b.z };
}

meow::vec3 meow::operator/(const vec3 &a, const float &b)
{
	return vec3{ a.x / b, a.y / b, a.z / b };
}

bool meow::operator==(const vec3 &a, const vec3 &b)
{
	return (fabs(b.x - a.x) < FLT_EPSILON && fabs(b.y - a.y) < FLT_EPSILON && fabs(b.z - a.z) < FLT_EPSILON);
}
bool meow::operator!=(const vec3 &a, const vec3 &b)
{
	return !(a == b);
}
bool meow::operator<(const vec3 &a, const vec3 &b)
{
	return (a.x < b.x && a.y < b.y && a.z < b.z);
}
bool meow::operator<=(const vec3 &a, const vec3 &b)
{
	return (a < b || a == b);
}
bool meow::operator>(const vec3 &a, const vec3 &b)
{
	return !(a <= b);
}
bool meow::operator>=(const vec3 &a, const vec3 &b)
{
	return !(a < b);
}

std::ostream &meow::operator<<(std::ostream &os, const vec3 &p)
{
	os << p.xy << "," << p.z;
	return os;
}

meow::vec3 meow::normal(const vec3 &a)
{
	return a.normal();
}
void meow::normalize(vec3 &a)
{
	a.normalize();
	return;
}
float meow::magnitude(const vec3 &a)
{
	return a.magnitude();
}
float meow::dot(const vec3 &a, const vec3 &b)
{
	return a.dot(b);
}
meow::vec3 meow::cross(const vec3 &a, const vec3 &b)
{
	return a.cross(b);
}
meow::vec3 meow::lerp(const vec3 &a, const vec3 &b, const float &c)
{
	return a.lerp(b, c);
}
meow::vec3 meow::reflection(const vec3 &a, const vec3 &b)
{
	return a.reflection(b);
}