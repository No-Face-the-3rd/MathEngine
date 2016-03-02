#include "vec4.h"

meow::vec4 &meow::vec4::operator=(const float &a)
{
	this->x = a;
	this->y = a;
	this->z = a;
	this->w = a;
	return *this;
}
meow::vec4 &meow::vec4::operator=(const vec2 &a)
{
	this->xy = a;
	this->zw = 0.0f;
	return *this;
}
meow::vec4 &meow::vec4::operator=(const vec3 &a)
{
	this->xyz = a;
	this->w = 0.0f;
	return *this;
}
meow::vec4 &meow::vec4::operator=(const vec4 &a)
{
	this->xyz = a.xyz;
	this->w = a.w;
	return *this;
}

meow::vec4 &meow::vec4::operator+=(const float &a)
{
	this->xyz += a;
	this->w += a;
	return *this;
}
meow::vec4 &meow::vec4::operator+=(const vec2 &a)
{
	this->xy += a;
	return *this;
}
meow::vec4 &meow::vec4::operator+=(const vec3 &a)
{
	this->xyz += a;
	return *this;
}
meow::vec4 &meow::vec4::operator+=(const vec4 &a)
{
	this->xyz += a.xyz;
	this->w += a.w;
	return *this;
}

meow::vec4 &meow::vec4::operator-=(const float &a)
{
	this->xyz -= a;
	this->w -= a;
	return *this;
}
meow::vec4 &meow::vec4::operator-=(const vec2 &a)
{
	this->xy -= a;
	return *this;
}
meow::vec4 &meow::vec4::operator-=(const vec3 &a)
{
	this->xyz -= a;
	return *this;
}
meow::vec4 &meow::vec4::operator-=(const vec4 &a)
{
	this->xyz -= a.xyz;
	this->w -= a.w;
	return *this;
}

meow::vec4 &meow::vec4::operator*=(const float &a)
{
	this->xyz *= a;
	this->w *= a;
	return *this;
}

meow::vec4 &meow::vec4::operator/=(const float &a)
{
	this->xyz /= a;
	this->w /= a;
	return *this;
}

meow::vec4 meow::vec4::normal() const
{
	return vec4{ this->x / this->magnitude(), this->y / this->magnitude(), this->z / this->magnitude(), this->w / this->magnitude() };
}
void meow::vec4::normalize()
{
	*this /= this->magnitude();
	return;
}
float meow::vec4::magnitude() const
{
	return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2) + pow(this->w, 2));
}
float meow::vec4::dot(const vec4 &a) const
{
	return (this->xyz.dot(a.xyz) + this->w *a.w);
}
meow::vec4 meow::vec4::lerp(const vec4 &a, const float &b) const
{
	return (*this + std::max(std::min(b, 1.0f), 0.0f) * (a - *this));
}
meow::vec4 meow::vec4::reflection(const vec4 &a) const
{
	return (2 * (this->dot(a.normal())) * a.normal() - *this);
}

meow::vec4 meow::operator+(const vec4 &a, const float &b)
{
	return vec4{ a.x + b, a.y + b, a.z + b, a.w + b };
}
meow::vec4 meow::operator+(const float &a, const vec4 &b)
{
	return vec4{ a + b.x, a + b.y, a + b.z, a + b.w };
}
meow::vec4 meow::operator+(const vec4 &a, const vec2 &b)
{
	return vec4{ a.x + b.x, a.y + b.y, a.z, a.w };
}
meow::vec4 meow::operator+(const vec2 &a, const vec4 &b)
{
	return vec4{ a.x + b.x, a.y + b.y, b.z, b.w };
}
meow::vec4 meow::operator+(const vec4 &a, const vec3 &b)
{
	return vec4{ a.x + b.x, a.y + b.y, a.z + b.z, a.w };
}
meow::vec4 meow::operator+(const vec3 &a, const vec4 &b)
{
	return vec4{ a.x + b.x, a.y + b.y, a.z + b.z, b.w };
}
meow::vec4 meow::operator+(const vec4 &a, const vec4 &b)
{
	return vec4{ a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w };
}

meow::vec4 meow::operator-(const vec4 &a, const float &b)
{
	return vec4{ a.x - b, a.y - b, a.z - b, a.w - b };
}
meow::vec4 meow::operator-(const vec4 &a, const vec2 &b)
{
	return vec4{ a.x - b.x, a.y - b.y, a.z, a.w };
}
meow::vec4 meow::operator-(const vec4 &a, const vec3 &b)
{
	return vec4{ a.x - b.x, a.y - b.y, a.z - b.z, a.w };
}
meow::vec4 meow::operator-(const vec4 &a, const vec4 &b)
{
	return vec4{ a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w };
}

meow::vec4 meow::operator-(const vec4 &a)
{
	return vec4{ -a.x, -a.y, -a.z, -a.w };
}

meow::vec4 meow::operator*(const vec4 &a, const float &b)
{
	return vec4{ a.x * b, a.y * b, a.z *b, a.w * b };
}
meow::vec4 meow::operator*(const float &a, const vec4 &b)
{
	return vec4{ a * b.x, a * b.y, a  * b.z, a*b.w };
}

meow::vec4 meow::operator/(const vec4 &a, const float &b)
{
	return vec4{ a.x / b, a.y / b, a.z / b, a.w / b };
}

bool meow::operator==(const vec4 &a, const vec4 &b)
{
	return (a.xyz == b.xyz && fabs(b.w - a.w) < FLT_EPSILON);
}
bool meow::operator!=(const vec4 &a, const vec4 &b)
{
	return !(a == b);
}
bool meow::operator<(const vec4 &a, const vec4 &b)
{
	return (a.xyz < b.xyz && a.w < b.w);
}
bool meow::operator<=(const vec4 &a, const vec4 &b)
{
	return (a < b || a == b);
}
bool meow::operator>(const vec4 &a, const vec4 &b)
{
	return !(a <= b);
}
bool meow::operator>=(const vec4 &a, const vec4 &b)
{
	return !(a < b);
}

std::ostream &meow::operator<<(std::ostream &os, const vec4 &p)
{
	os << p.xyz << "," << p.w;
	return os;
}

meow::vec4 meow::normal(const vec4 &a)
{
	return a.normal();
}
void meow::normalize(vec4 &a)
{
	a.normalize();
	return;
}
float meow::magnitude(const vec4 &a)
{
	return a.magnitude();
}
float meow::dot(const vec4 &a, const vec4 &b)
{
	return a.dot(b);
}
meow::vec4 meow::lerp(const vec4 &a, const vec4 &b, const float &c)
{
	return a.lerp(b, c);
}
meow::vec4 meow::reflection(const vec4 &a, const vec4 &b)
{
	return a.reflection(b);
}