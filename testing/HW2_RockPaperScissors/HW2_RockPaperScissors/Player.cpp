// Player.cpp			2/21/2016
//
// You, the player!

#include <iostream>
#include <string>
#include "Player.h"


// Constructor - default
Player::Player()
{
	name = "Random player";
	type = 'r';
}

Player::Player(std::string name, char type)
{
	this->name = name;
	this->type = type;
}

// Destructor
Player::~Player()
{
	std::cout << "Bye bye, " << name << std::endl;
}

// Returns player name
std::string Player::getName()
{
	return name;
}

// Returns player type
char Player::getType()
{
	return type;
}