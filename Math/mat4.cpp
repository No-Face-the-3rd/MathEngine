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
	mat4 tmp;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			tmp.c[i].v[j] = this->minor(i, j).determinant();
	return ((1/this->determinant()) * tmp);
}
meow::mat4 meow::mat4::transpose() const
{
	mat4 tmp;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			tmp.c[i].v[j] = this->c[j].v[i];
	return tmp;
}
meow::mat4 meow::mat4::rotate(const float &a) const
{
	return this->rotate(vec3{ a,a,a });
}
meow::mat4 meow::mat4::rotate(const vec3 &a) const
{
	mat4 tmp = meow::mat4Identity();
	return tmp;
}
meow::mat4 meow::mat4::scale(const vec3 &a) const
{
	mat4 tmp = meow::mat4Identity();
	for (int i = 0; i < 3;++i)
		tmp.c[i].v[i] *= a.v[i];
	return tmp;
}
meow::mat4 meow::mat4::translate(const vec3 &a) const
{
	mat4 tmp = mat4::identity();
	tmp.c[3].v[0] = a.x;
	tmp.c[3].v[1] = a.y;
	tmp.c[3].v[2] = a.z;
	return tmp;
}

float meow::mat4::determinant() const
{
	float det = 0.0f;
	for (int i = 0; i < 4; ++i)
		det += std::pow(-1, (i + 2)) * this->mm[i][0] * this->minor(i, 0).determinant();
	return det;
}

meow::mat3 meow::mat4::minor(const int &a, const int &b) const
{
	int tmp = 0;
	mat3 tmpMat;
	for (int i = 0;i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (!(i == a) && !(j == b))
			{
				tmpMat.m[tmp] = this->mm[i][j];
				++tmp;
			}
	return tmpMat;
}

meow::mat4 meow::mat4Identity()
{
	mat4 tmp;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (i == j)
				tmp.c[i].v[j] = 1.0f;
			else
				tmp.c[i].v[j] = 0.0f;
	return tmp;
}