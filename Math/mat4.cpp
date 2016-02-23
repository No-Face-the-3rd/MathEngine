#include "mat4.h"

meow::mat4 &meow::mat4::operator=(const mat4 &a)
{
	for (int i = 0; i < 4; ++i)
		this->c[i] = a.c[i];
	return *this;
}

meow::mat4 &meow::mat4::operator+=(const float &a)
{
	for (int i = 0; i < 4; ++i)
		this->c[i] += a;
	return *this;
}
meow::mat4 &meow::mat4::operator+=(const mat4 &a)
{
	for (int i = 0; i < 4; ++i)
		this->c[i] += a.c[i];
	return *this;
}

meow::mat4 &meow::mat4::operator-=(const float &a)
{
	for (int i = 0; i < 4; ++i)
		this->c[i] -= a;
	return *this;
}
meow::mat4 &meow::mat4::operator-=(const mat4 &a)
{
	for (int i = 0; i < 4; ++i)
		this->c[i] -= a.c[i];
	return *this;
}

meow::mat4 &meow::mat4::operator*=(const mat4 &a)
{
	mat4 tmp = this->transpose();
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			this->c[i].v[j] = tmp.c[j].dot(a.c[i]);
	return *this;
}

meow::mat4 meow::mat4::identity() const
{
	return meow::mat4Identity();
}
meow::mat4 meow::mat4::inverse() const
{

}
meow::mat4 meow::mat4::transpose() const
{
	mat4 tmp;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			tmp.c[i].v[j] = this->c[j].v[i];
	return tmp;
}
meow::mat4 meow::mat4::scale(const vec3 &a) const
{
	mat4 tmp = meow::mat4Identity();
	for (int i = 0; i < 3;++i)
		tmp.c[i].v[i] *= a.v[i];
	return tmp;
}