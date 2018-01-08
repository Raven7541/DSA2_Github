// Scissor.cpp			2/21/2016
//
// A pair of scissors!

#include <iostream>
#include <string>
#include "Scissor.h"


// Constructor - default
Scissor::Scissor()
{
	name = "Random scissor";
	type = 's';
}

// Constructor - parameterized
Scissor::Scissor(std::string name, char type) : Player(name, type)
{

}

// Destructor
Scissor::~Scissor()
{
	std::cout << name << "'s scissors are getting rusty!" << std::endl;
}
