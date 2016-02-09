#include "mat3.h"

meow::mat3 &meow::mat3::operator=(const mat3 &a)
{
	for (int i = 0; i < 3; ++i)
		this->c[i] = a.c[i];
	return *this;
}

meow::mat3 &meow::mat3::operator+=(const float &a)
{
	for (int i = 0; i < 3; ++i)
		this->c[i] += a;
	return *this;
}
meow::mat3 &meow::mat3::operator+=(const mat3 &a)
{
	for (int i = 0; i < 3; ++i)
		this->c[i] += a.c[i];
	return *this;
}

meow::mat3 &meow::mat3::operator-=(const float &a)
{
	for (int i = 0; i < 3; ++i)
		this->c[i] -= a;
	return *this;
}
meow::mat3 &meow::mat3::operator-=(const mat3 &a)
{
	for (int i = 0; i < 3; ++i)
		this->c[i] -= a.c[i];
	return *this;
}

meow::mat3 &meow::mat3::operator*=(const mat3 &a)
{
	mat3 tmp = this->transpose();
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			this->c[i].v[j] = tmp.c[j].dot(a.c[i]);
	return *this;
}

meow::mat3 meow::mat3::identity() const
{
	mat3 tmp;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (i == j)
				tmp.c[i].v[j] = 1.0f;
			else
				tmp.c[i].v[j] = 0.0f;
	return tmp;
}
meow::mat3 meow::mat3::inverse() const
{
	mat3 tmp;
	int nums[6] = { 1,0,0,2,2,1 };
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			tmp.c[j].v[i] = std::pow(-1, (i + j + 2)) / this->determinant() *(this->c[nums[i]].v[nums[j]] * this->c[nums[i + 3]].v[nums[j + 3]] - this->c[nums[i]].v[nums[j + 3]] * this->c[nums[i + 3]].v[nums[j]]);
	return tmp;
}
meow::mat3 meow::mat3::transpose() const
{
	mat3 tmp;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			tmp.c[i].v[j] = this->c[j].v[i];
	return tmp;
}
meow::mat3 meow::mat3::rotate(const float &a) const
{
	mat3 tmp = mat3::identity();
	tmp.c[0] += vec2{ cos(a), sin(a) };
	tmp.c[1] += vec2{ -sin(a),cos(a) };
	return tmp;
}
meow::mat3 meow::mat3::scale(const vec2 &a) const
{
	mat3 tmp = mat3::identity();
	tmp.c[0].v[0] = a.x;
	tmp.c[1].v[1] = a.y;
	return tmp;
}
meow::mat3 meow::mat3::translate(const vec2 &a) const
{
	mat3 tmp = mat3::identity();
	tmp.c[2].v[0] = a.x;
	tmp.c[2].v[1] = a.y;
	return tmp;
}
float meow::mat3::determinant() const
{
	float det = 0.0f;
	for (int i = 0; i < 3; ++i)
	{
		det += this->c[i].v[0] * this->c[(i + 1) % 3].v[1] * this->c[(i + 2) % 3].v[2];
		det -= this->c[0].v[(3 - i) % 3] * this->c[1].v[(3 - i - 1) % 3] * this->c[2].v[(6 - i - 2) % 3];
	}
	return det;
}

