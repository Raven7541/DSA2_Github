#pragma once
#include <vector>
#include "Player.h"

class Game
{

public:
	Game();  // Constructor - default
	virtual ~Game();  // Destructor
	void assemble();  // Set up the game
	void run();  // Run the game

	int checkPlayers();  // Check on number of players
	bool checkGame();  // Check if it's still running

protected:
	std::vector<Player*> players;  // the players
	int numPlayers;  // number of players
	bool gameRunning;

};

