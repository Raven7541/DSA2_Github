#pragma once
#include "Player.h"


class Rock : public Player
{

public:
	Rock();  // Constructor, default
	Rock(std::string name, char type);  // Constructor, parameterized
	~Rock();  // Destructor

	// Print the stuff!
	virtual void print() 
	{
		getName();  // parent method
		std::cout << name << " (O Rock)";
	};

	// Operators
	// Check if it's scissors - if so, crush 'em!
	virtual bool operator>(Player* other)
	{
		return other->getType() == 's';
	}

	// Check if it's paper - if so, we're doomed!
	virtual bool operator<(Player* other)
	{
		return other->getType() == 'p';
	}

	// Check if it's rock - if so, ow, my head hurts!
	virtual bool operator==(Player* other)
	{
		return other->getType() == 'r';
	}

};

