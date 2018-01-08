// Rock.cpp			2/21/2016
//
// A rock!

#include <iostream>
#include <string>
#include "Rock.h"


// Constructor - default
Rock::Rock() : Player()
{
	name = "Random rock";
	type = 'r';
}


// Constructor - parameterized
Rock::Rock(std::string name, char type) : Player(name, type)
{

}

// Destructor
Rock::~Rock()
{
	std::cout << name << "'s rock is pretty heavy!" << std::endl;
}