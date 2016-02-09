#include "vec4.h"


#include <iostream>



struct mat3
{
	union
	{
		meow::vec3 c[3];
	};

};


std::ostream &operator<<(std::ostream &os, const mat3 &p)
{
	for (int i = 0; i < 3; ++i)
	{ 
		meow::vec3 tmp{ 0.0f };
		for (int j = 0; j < 3; ++j)
			tmp.v[j] = p.c[j].v[i];
		os << tmp << std::endl;
	}
	return os;
}

mat3 inverse(const mat3 &a);

void main()
{
	meow::vec2 rawr = { 1.0f,2.0f };
	meow::vec3 silly = { 1.0f, 2.0f,3.0f };

	std::cout << rawr.magnitude() << std::endl;

	std::cout << rawr.normal().magnitude() << " " << rawr.normal() << std::endl;


	

	mat3 pew = { 4,-3,2,3,0,0,-1,1,2 };

	std::cout << std::endl << pew << std::endl;

	std::cout << std::endl << pew.c[0] << std::endl;
	std::cout << std::endl << rawr.y << std::endl;

	std::cout << std::endl << inverse(pew) << std::endl;
	


	std::cout << rawr.dot(rawr) << std::endl;
	std::cout << rawr << std::endl;

	system("pause");
	return;
}




mat3 inverse(const mat3 &a)
{
	mat3 aInv;
	int nums[6] = { 1,0,0,2,2,1 };
	float det = 0.0f;
	for (int i = 0; i < 3; ++i)
	{
		det += a.c[i].v[0] * a.c[(i + 1) % 3].v[1] * a.c[(i + 2) % 3].v[2];
		det -= a.c[0].v[(3 - i) % 3] * a.c[1].v[(3 - i - 1) % 3] * a.c[2].v[(6 - i - 2) % 3];
	}
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			aInv.c[j].v[i] = std::pow(-1, (i + j + 2)) / det *(a.c[nums[i]].v[nums[j]] * a.c[nums[i + 3]].v[nums[j + 3]] - a.c[nums[i]].v[nums[j + 3]] * a.c[nums[i + 3]].v[nums[j]]);
	return aInv;
}