//*************
// Source.cpp			9/22/2016
//
// DSA2 Exam 1

#include <iostream>
#include "SharedPtr.h"

int main()
{
	SharedPtr<int> p1(new int);
	SharedPtr<int> p2(p1);

	*p2 = 10;

	std::cout << "P1: " << p1.get() << " " << *p1 << std::endl;
	std::cout << "P2: " << p2.get() << " " << *p2 << std::endl;
	
	return 0;
}