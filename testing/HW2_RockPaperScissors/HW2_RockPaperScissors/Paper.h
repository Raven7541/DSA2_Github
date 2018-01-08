#pragma once
#include "Player.h"


class Paper : public Player
{

public:
	Paper();  // Constructor - default
	Paper(std::string name, char type);  // Constructor, parameterized
	~Paper();  // Destructor

	// Print the stuff!
	virtual void print()
	{
		getName();  // parent method
		std::cout << name << " (--- Paper)";
	};

	// Operators
	// Check if it's rock - if so, wrap 'em up!
	virtual bool operator>(Player* other)
	{
		return other->getType() == 'r';
	}

	// Check if it's scissor - if so, we're doomed!
	virtual bool operator<(Player* other)
	{
		return other->getType() == 's';
	}

	// Check if it's paper - if so, ow, my finger!
	virtual bool operator==(Player* other)
	{
		return other->getType() == 'p';
	}

};

