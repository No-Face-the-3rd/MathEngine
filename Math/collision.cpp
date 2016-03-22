
#include "collision.h"

float meow::pointPlaneDist(const meow::vec2 & a, const meow::plane & b)
{
	return meow::dot(a - b.pos, b.normal);
}
float meow::rayPlaneDist(const meow::ray &a, const meow::plane &b)
{
	return meow::dot(b.pos - a.pos, b.normal) / meow::dot(b.normal, a.dir);
}

meow::collisionData meow::cTest(const meow::aabb &a, const meow::aabb &b)
{
	meow::collisionData tmp;
	if (b.max() > a.min() && a.max() > b.min())
	{
		tmp.collided = true;
		meow::vec2 c = b.max() - a.min(), d = a.max() - b.min();
		tmp.depth = std::fminf(std::fminf(c.x, d.x), std::fminf(c.y, d.y));
		tmp.normal = (c.x - tmp.depth) < FLT_EPSILON || (d.x - tmp.depth) < FLT_EPSILON ? meow::vec2{ 1.0f,0.0f } : meow::vec2{ 0.0f,1.0f };
	}
	return tmp;
}
meow::collisionData meow::cTest(const meow::aabb &a, const meow::circle &b)
{
	meow::collisionData tmp;
	meow::vec2 c = meow::vec2{ std::fminf(std::fmaxf(b.pos.x, a.min().x),a.max().x),std::fminf(std::fmaxf(b.pos.y, a.min().y),a.max().y) };
	meow::vec2 d = c - b.pos;
	if (d.magnitude() < b.rad)
	{
		tmp.collided = true;
		tmp.depth = b.rad - d.magnitude();
		tmp.normal = d.normal();
	}
	return tmp;
}
meow::collisionData meow::cTest(const meow::aabb &a, const meow::convexHull &b)
{
	meow::collisionData tmp;
	float c = FLT_MAX, d = 0.0f, e = 0.0f;
	std::vector<meow::vec2> f;
	int g = -1;

	for (int i = 0; i < b.verts.size(); ++i)
		f.push_back(meow::vec2{ b.verts[i] - b.verts[(i + 1) % b.verts.size()] }.perpendicular().normal());
	f.push_back(meow::vec2{ 1.0f, 0.0f });
	f.push_back(meow::vec2{ 0.0f,1.0f });

	for (int i = 0; i < f.size(); ++i)
	{
		float aMn = FLT_MAX, aMx = FLT_MIN, bMn = FLT_MAX, bMx = FLT_MIN;


		for (int j = 0; j < b.verts.size(); ++j)
		{
			d = meow::dot(f.at(i), b.verts.at(j));
			bMn = std::fminf(d, bMn);
			bMx = std::fmaxf(d, bMx);
		}

		d = meow::dot(a.min(), f.at(i));
		e = meow::dot(a.max(), f.at(i));
		aMn = std::fminf(e, std::fminf(d, aMn));
		aMx = std::fmaxf(e, std::fmaxf(d, aMx));
		if (aMx > bMn && bMx > aMn)
		{
			d = fminf(aMx - bMn, bMx - aMn);
			if (d < c)
			{
				c = d;
				g = i;
			}
		}
		else
			return tmp;
	}
	tmp.collided = true;
	tmp.depth = c;
	tmp.normal = f.at(g);
	return tmp;
}
meow::collisionData meow::cTest(const meow::aabb &a, const meow::plane &b)
{
	meow::collisionData tmp;
	float c = meow::dot(a.pos - b.pos, b.normal), d = a.dim.x / 2.0f * std::fabs(meow::dot(b.normal, meow::vec2{ 1.0f,0.0f })) + a.dim.y / 2.0f * std::fabs(meow::dot(b.normal, meow::vec2{ 0.0f,1.0f }));
	if (tmp.collided = c < d)
	{
		tmp.normal = b.normal;
		tmp.depth = d - c;
	}
	return tmp;
}
meow::collisionData meow::cTest(const meow::aabb &a, const meow::ray &b)
{
	meow::collisionData tmp;
	meow::plane c, d, e, f;
	float g, h, i = FLT_MAX, j = FLT_MIN;

	
	if (meow::dot(meow::vec2{ 1.0f,0.0f }, b.dir) > FLT_EPSILON)
	{
		c = meow::plane{ a.min(), meow::vec2{-1.0f,0.0f} };
		d = meow::plane{ a.max(), meow::vec2{1.0f,0.0f} };
		g = meow::rayPlaneDist(b, c);
		h = meow::rayPlaneDist(b, d);
		i = std::fminf(g, h);
		j = std::fmaxf(g, h);
	}
	if (meow::dot(meow::vec2{ 0.0f,1.0f }, b.dir) > FLT_EPSILON)
	{
		e = meow::plane{ a.min(), meow::vec2{0.0f,-1.0f} };
		f = meow::plane{ a.max(), meow::vec2{0.0f,1.0f} };
		g = meow::rayPlaneDist(b, e);
		h = meow::rayPlaneDist(b, f);
		i = std::fminf(i, std::fminf(g, h));
		j = std::fmaxf(j, std::fmaxf(g, h));
	}
	if (tmp.collided = (i <= j && 0 <= i && i <= b.length))
	{
		tmp.depth = i;
		tmp.normal = -b.dir;
	}
	return tmp;
}
meow::collisionData meow::cTest(const meow::circle &a, const meow::aabb &b)
{
	return meow::cTest(b, a);
}
meow::collisionData meow::cTest(const meow::circle &a, const meow::circle &b)
{
	meow::collisionData tmp;
	meow::vec2 c = b.pos - a.pos;
	float d = a.rad + b.rad;
	if (tmp.collided = (c.magnitude() <= d))
	{
		tmp.depth = d - c.magnitude();
		tmp.normal = c.normal();
	}
	return tmp;
}
meow::collisionData meow::cTest(const meow::circle &a, const meow::convexHull &b)
{
	meow::collisionData tmp;
	float c = FLT_MAX, d = 0.0f, e = 0.0f;
	std::vector<meow::vec2> f;
	int g = -1;

	for (int i = 0; i < b.verts.size(); ++i)
		f.push_back(meow::vec2{ b.verts[i] - b.verts[(i + 1) % b.verts.size()] }.perpendicular().normal());

	for (int i = 0; i < f.size(); ++i)
	{
		float aMn = FLT_MAX, aMx = FLT_MIN, bMn = FLT_MAX, bMx = FLT_MIN;


		for (int j = 0; j < b.verts.size(); ++j)
		{
			d = meow::dot(f.at(i), b.verts.at(j));
			bMn = std::fminf(d, bMn);
			bMx = std::fmaxf(d, bMx);
		}
		d = meow::dot(a.pos - a.rad / 2.0f, f.at(i));
		e = meow::dot(a.pos + a.rad / 2.0f, f.at(i));
		aMn = std::fminf(e, std::fminf(d, aMn));
		aMx = std::fmaxf(e, std::fmaxf(d, aMx));

		if (aMx > bMn && bMx > aMn)
		{
			d = fminf(aMx - bMn, bMx - aMn);
			if (d < c)
			{
				c = d;
				g = i;
			}
		}
		else
			return tmp;
	}
	tmp.collided = true;
	tmp.depth = c;
	tmp.normal = f.at(g);
	return tmp;
}
meow::collisionData meow::cTest(const meow::circle &a, const meow::plane &b)
{
	meow::collisionData tmp;
	float c = meow::dot(b.normal, a.pos - b.pos);
	if (tmp.collided = (c <= a.rad))
	{
		tmp.depth = a.rad - c;
		tmp.normal = b.normal;
	}
	return tmp;
}
meow::collisionData meow::cTest(const meow::circle &a, const meow::ray &b)
{
	meow::collisionData tmp;
	meow::vec2 c = b.pos + b.dir * std::fminf(std::fmaxf(meow::dot(a.pos - b.pos, b.dir), 0 ), b.length);
	float d = meow::dot((a.pos - c), (a.pos - c)), e = std::pow(a.rad, 2);
	if (tmp.collided = (d <= e))
	{
		tmp.normal = b.dir.perpendicular();
		tmp.depth = a.rad - sqrt(d);
	}
	return tmp;
}
meow::collisionData meow::cTest(const meow::convexHull &a, const meow::aabb &b)
{
	return meow::cTest(b, a);
}
meow::collisionData meow::cTest(const meow::convexHull &a, const meow::circle &b)
{
	return meow::cTest(b, a);
}
meow::collisionData meow::cTest(const meow::convexHull &a, const meow::convexHull &b)
{
	meow::collisionData tmp;
	float c = FLT_MAX, d = 0.0f, e = 0.0f;
	std::vector<meow::vec2> f;
	int g = -1;

	for (int i = 0; i < a.verts.size(); ++i)
		f.push_back(meow::vec2{ a.verts[i] - a.verts[(i + 1) % a.verts.size()] }.perpendicular().normal());
	for (int i = 0; i < b.verts.size(); ++i)
		f.push_back(meow::vec2{ b.verts[i] - b.verts[(i + 1) % b.verts.size()] }.perpendicular().normal());

	for (int i = 0; i < f.size(); ++i)
	{
		float aMn = FLT_MAX, aMx = FLT_MIN, bMn = FLT_MAX, bMx = FLT_MIN;

		for (int j = 0; j < a.verts.size(); ++j)
		{
			d = meow::dot(f.at(i), a.verts.at(j));
			aMn = std::fminf(d, aMn);
			aMx = std::fmaxf(d, aMx);
		}

		for (int j = 0; j < b.verts.size(); ++j)
		{
			d = meow::dot(f.at(i), b.verts.at(j));
			bMn = std::fminf(d, bMn);
			bMx = std::fmaxf(d, bMx);
		}

		if (aMx > bMn && bMx > aMn)
		{
			d = fminf(aMx - bMn, bMx - aMn);
			if (d < c)
			{
				c = d;
				g = i;
			}
		}
		else
			return tmp;
	}
	tmp.collided = true;
	tmp.depth = c;
	tmp.normal = f.at(g);
	return tmp;
}
meow::collisionData meow::cTest(const meow::convexHull &a, const meow::plane &b)
{
	meow::collisionData tmp;
	float c, d = FLT_MAX;

	for (int i = 0; i < a.verts.size(); ++i)
	{
		c = meow::pointPlaneDist(a.verts[i], b);
		d = std::fminf(d, c);
	}
	if (tmp.collided = (d <= 0.0f))
	{
		tmp.depth = d;
		tmp.normal = b.normal;
	}
	return tmp;
}
meow::collisionData meow::cTest(const meow::convexHull &a, const meow::ray &b)
{
	meow::collisionData tmp;
	float c = FLT_MAX, d = 0.0f, e = 1.0f, k;
	std::vector<meow::vec2> f;
	meow::vec2 j;
	int l = -1;

	for (int i = 0; i < a.verts.size(); i++)
		f.push_back(meow::vec2{ a.verts[i] - a.verts[(i + 1) % a.verts.size()] }.perpendicular().normal());
	
	for (int i = 0; i < f.size(); i++)
	{
		float g = meow::dot(f.at(i), a.verts.at(i) - b.pos), h = meow::dot(f.at(i), b.dir);

		if (std::fabs(h) < FLT_EPSILON)
			if (g < 0.0f)
				return tmp;
		
		g = g / h;

		if (h < 0.0f)
		{
			if (d < g)
			{
				d = g;
				l = i;
			}
		}
		else
			e = g;
	}

	if (tmp.collided = d <= e)
	{
		tmp.depth = b.length - d;
		tmp.normal = f.at(l);
	}
	return tmp;
}
meow::collisionData meow::cTest(const meow::plane &a, const meow::aabb &b)
{
	return meow::cTest(b, a);
}
meow::collisionData meow::cTest(const meow::plane &a, const meow::circle &b)
{
	return meow::cTest(b, a);
}
meow::collisionData meow::cTest(const meow::plane &a, const meow::convexHull &b)
{
	return meow::cTest(b, a);
}
meow::collisionData meow::cTest(const meow::plane &a, const meow::plane &b)
{
	meow::collisionData tmp;
	if (tmp.collided = !(a.normal == b.normal || a.normal == b.normal));
	return tmp;
}
meow::collisionData meow::cTest(const meow::plane &a, const meow::ray &b)
{
	meow::collisionData tmp;
	float c = -meow::dot(a.normal, b.dir), d = meow::dot(a.normal, b.pos - a.pos);
	if(c > 0.0f)
		if (tmp.collided = (d / c >= 0.0f && d / c <= b.length))
		{
			tmp.depth = b.length - d / c;
			tmp.normal = b.dir;
		}
	return tmp;
}
meow::collisionData meow::cTest(const meow::ray &a, const meow::aabb &b)
{
	return meow::cTest(b, a);
}
meow::collisionData meow::cTest(const meow::ray &a, const meow::circle &b)
{
	return meow::cTest(b, a);
}
meow::collisionData meow::cTest(const meow::ray &a, const meow::convexHull &b)
{
	return meow::cTest(b, a);
}
meow::collisionData meow::cTest(const meow::ray &a, const meow::plane &b)
{
	return meow::cTest(b, a);
}
meow::collisionData meow::cTest(const meow::ray &a, const meow::ray &b)
{

}
