#pragma once
#include "Player.h"


class Scissor : public Player
{

public:
	Scissor();  // Constructor, default
	Scissor(std::string, char type);  // Constructor - parameterized
	~Scissor();  // Destructor

	// Print the stuff!
	virtual void print()
	{
		getName();  // parent method
		std::cout << name << " (8>< Scissors)";
	};

	// Operators
	// Check if it's paper - if so, cut 'em up!
	virtual bool operator>(Player* other)
	{
		return other->getType() == 'p';
	}

	// Check if it's rock - if so, we're doomed!
	virtual bool operator<(Player* other)
	{
		return other->getType() == 'r';
	}

	// Check if it's scissor - if so, ow, my hand!
	virtual bool operator==(Player* other)
	{
		return other->getType() == 's';
	}

};

