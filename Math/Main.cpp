#include "vec4.h"


#include <iostream>




void main()
{


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