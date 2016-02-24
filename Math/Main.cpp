#include "mat4.h"

#include <iostream>

void main()
{
	meow::mat4 rawr = { 1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2 };
	std::cout << rawr.determinant() << std::endl;

	meow::mat4 pew = { 1,2,3,-1,6,4,-3,2,0,3,0,0,2,-1,1,2 };
	std::cout << pew.determinant() << std::endl;

	system("pause");
	return;
}