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

meow::mat4 &meow::mat4::operator*=(const float &a)
{
	for (int i = 0; i < 4; ++i)
		this->c[i] *= a;
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
	return this->rotate(vec3{ 0.0f, 0.0f ,0.0f });
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

meow::mat4 meow::operator+(const mat4 &a, const float &b)
{
	mat4 tmp = a;
	return (tmp += b);
}
meow::mat4 meow::operator+(const float &a, const mat4 &b)
{
	return (b + a);
}
meow::mat4 meow::operator+(const mat4 &a, const mat4 &b)
{
	mat4 tmp = a;
	return (tmp += b);
}

meow::mat4 meow::operator-(const mat4 &a, const float &b)
{
	mat4 tmp = a;
	return (tmp -= b);
}
meow::mat4 meow::operator-(const mat4 &a, const mat4 &b)
{
	mat4 tmp = a;
	return (tmp -= b);
}

meow::mat4 meow::operator*(const mat4 &a, const float &b)
{
	mat4 tmp = a;
	return (tmp *= b);
}
meow::mat4 meow::operator*(const float &a, const mat4 &b)
{
	return (b * a);
}
meow::mat4 meow::operator*(const mat4 &a, const mat4 &b)
{
	mat4 tmp = a;
	return (tmp *= b);
}

meow::vec4 meow::operator*(const mat4 &a, const vec4 &b)
{
	mat4 tmp = a.transpose();
	return vec4{ dot(tmp.c[0],b),dot(tmp.c[1],b),dot(tmp.c[2],b),dot(tmp.c[3],b) };
}
meow::vec4 meow::operator*(const vec4 &a, const mat4 &b)
{
	return vec4{ dot(a, b.c[0]),dot(a,b.c[1]),dot(a,b.c[2]),dot(a,b.c[3]) };
}

bool meow::operator==(const mat4 &a, const mat4 &b)
{
	return (a.c[0] == b.c[0] && a.c[1] == b.c[1] && a.c[2] == b.c[2] && a.c[3] == b.c[3]);
}
bool meow::operator!=(const mat4 &a, const mat4 &b)
{
	return !(a == b);
}
bool meow::operator<(const mat4 &a, const mat4 &b)
{
	return (a.c[0] < b.c[0] && a.c[1] < b.c[1] && a.c[2] < b.c[2] && a.c[3] < b.c[3]);
}
bool meow::operator<=(const mat4 &a, const mat4 &b)
{
	return (a == b || a < b);
}
bool meow::operator>(const mat4 &a, const mat4 &b)
{
	return !(a <= b);
}
bool meow::operator>=(const mat4 &a, const mat4 &b)
{
	return !(a < b);
}

std::ostream &meow::operator<<(std::ostream &os, const mat4 &a)
{
	mat4 tmp = a.transpose();
	for (int i = 0; i < 3; ++i)
		os << tmp.c[i] << std::endl;
	return os;
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
meow::mat4 meow::inverse(const mat4 &a)
{
	return a.inverse();
}
meow::mat4 meow::transpose(const mat4 &a)
{
	return a.transpose();
}
meow::mat4 meow::rotate(const mat4 &a, const float &b)
{
	return a.rotate(b);
}
meow::mat4 meow::rotate(const mat4 &a, const vec3 &b)
{
	return a.rotate(b);
}
meow::mat4 meow::scale(const mat4 &a, const vec3 &b)
{
	return a.scale(b);
}
meow::mat4 meow::translate(const mat4 &a, const vec3 &b)
{
	return a.translate(b);
}

float meow::determinant(const mat4 &a)
{
	return a.determinant();
}

meow::mat4 meow::mat3ToMat4(const mat3 &a)
{
	mat4 tmp = meow::mat4Identity();
	tmp.c[0] = { a.c[0].v[0],a.c[0].v[1],tmp.c[0].v[2],a.c[0].v[2] };
	tmp.c[1] = { a.c[1].v[0],a.c[1].v[1],tmp.c[1].v[2],a.c[1].v[2] };
	tmp.c[3] = { a.c[2].v[0],a.c[2].v[1],tmp.c[3].v[2],a.c[2].v[2] };
	return tmp;
}

meow::mat3 meow::minor(const mat4 &a, const int &b, const int &c)
{
	return a.minor(b, c);
}