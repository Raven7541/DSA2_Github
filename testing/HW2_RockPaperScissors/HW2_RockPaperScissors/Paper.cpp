// Paper.cpp		2/21/2016
//
// A piece of paper!

#include <iostream>
#include <string>
#include "Paper.h"


// Constructor - default
Paper::Paper() : Player()
{
	name = "Random paper";
	type = 'p';
}

// Constructor - parameterized
Paper::Paper(std::string name, char type) : Player(name, type)
{

}

// Destructor
Paper::~Paper()
{
	std::cout << name << "'s paper is crumpled!" << std::endl;
}
