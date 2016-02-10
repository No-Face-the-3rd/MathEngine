#pragma once


#ifndef MAT4_H
#define MAT4_H

#include "mat3.h"

namespace meow
{
	__declspec(align(32)) struct mat4
	{
		union
		{
			float m[16];
			float mm[4][4];
			vec4 c[4];
			struct 
			{
				union { vec4 c1; vec3 right; };
				union { vec4 c2; vec3 up; };
				union { vec4 c3; vec3 forward; };
				union { vec4 c4; vec3 position; };
			};
		};

		mat4 &operator=(const mat4 &a);

		mat4 &operator+=(const float &a);
		mat4 &operator+=(const mat4 &a);

		mat4 &operator-=(const float &a);
		mat4 &operator-=(const mat4 &a);

		mat4 &operator*=(const mat4 &a);

		mat4 identity() const;
		mat4 inverse() const;
		mat4 transpose() const;
		mat4 orthographicProjection() const;

	};

}



#endif