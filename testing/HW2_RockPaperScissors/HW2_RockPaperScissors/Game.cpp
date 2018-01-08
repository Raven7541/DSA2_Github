// Game.cpp				2/24/2016
//						Adjusted on 8/30/2016
//
// Not the games! Not the gaaammmeessss!

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Player.h"
#include "Rock.h"
#include "Paper.h"
#include "Scissor.h"
#include "Game.h"

// Constructor - default (nothing!)
Game::Game() { gameRunning = false;  }

// Destructor - end of game
Game::~Game()
{
	std::cout << "Game over! Thanks for playing! :)" << std::endl;

	// Delete everyone (whaaa?!)!
	for (int i = 0; i < numPlayers; i++)
	{
		delete players[i];
	}
}

// Players, assemble!
void Game::assemble()
{
	// Begin!
	std::cout << "Welcome to Rock, Paper, Scissors!" << std::endl;

	// Ask for user input
	while (true)
	{
		numPlayers = 0;  // default
		std::cout << "Enter the number of players (between 2 and 10): ";
		std::cin >> numPlayers;

		// Verifies the input
		if (!std::cin)
		{
			std::cout << "Invalid entry! Try again!" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
			break;
		}
		else if (numPlayers < 2 || numPlayers > 10)
		{
			// Too low/high!
			std::cout << "Invalid number! Try again!" << std::endl;
			numPlayers = 0;  // leaving the numPlayers value the way it is will crash the program
			break;
		}
		else
		{
			gameRunning = true;
			break;
		}
	}

	// Get the name of players and
	// assign random type
	if (gameRunning)
	{
		for (int i = 0; i < numPlayers; i++)
		{
			// Name!
			std::string name;
			std::cout << "Enter the name for player " << i + 1 << ": ";
			if (i == 0)
			{
				std::cin.ignore();  // prevents first character of string from being removed later
			}
			getline(std::cin, name);

			// Type!
			int randNum = rand() % 3;  // number between 0 and 2

			if (randNum == 0)
			{
				// Rock!
				players.push_back(new Rock(name, 'r'));
			}
			else if (randNum == 1)
			{
				// Scissor!
				players.push_back(new Scissor(name, 's'));
			}
			else if (randNum == 2)
			{
				// Paper!
				players.push_back(new Paper(name, 'p'));
			}
		}
	}
}

// Run the game!
void Game::run()
{
	while (gameRunning)
	{
		bool tied = false;  // default
		
		// Set up or reset players
		int p1 = 0;  // default
		int p2 = 0;

		// Pick your players!
		while (true)
		{
			// Get user input
			std::cout << std::endl << "* Select your players (1..." << numPlayers << " 1..." << numPlayers << ")! ";
			std::cin >> p1 >> p2;

			// Verify user input
			if (!std::cin)
			{
				std::cout << "Invalid entry! Try again!" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
			}
			else if (p1 < 1 || p1 > numPlayers || p2 < 1 || p2 > numPlayers
				|| p1 == p2)
			{
				std::cout << "Invalid inputs! Try again!" << std::endl;
			}
			else
			{
				break;
			}
		}

		// Call the players!
		players[p1-1]->print();
		std::cout << std::endl;
		players[p2-1]->print();
		std::cout << std::endl;

		// Now fight!
		if (*players[p1-1] > players[p2-1])
		{
			// Win!
			players[p1 - 1]->print();
			std::cout << " beats ";
			players[p2 - 1]->print();
			std::cout << "!" << std::endl;

			// Remove the loser!
			delete players[p2-1];
			players.erase(players.begin() + (p2-1));  // remove from vector
			numPlayers--;
		}
		else if (*players[p1-1] < players[p2-1])
		{
			// Lose!
			players[p2 - 1]->print();
			std::cout << " beats ";
			players[p1 - 1]->print();
			std::cout << "!" << std::endl;

			// Remove the loser!
			delete players[p1-1];
			players.erase(players.begin() + (p1-1));  // remove from vector
			numPlayers--;
		}
		else if (*players[p1-1] == players[p2-1])
		{
			// Ow! Tied!
			players[p1 - 1]->print();
			std::cout << " are tied ";
			players[p2 - 1]->print();
			std::cout << "!" << std::endl;
			tied = true;
		}

		// Checks if there is only one player left
		// or if there's a tie
		if (numPlayers == 1)
		{
			std::cout << "We have a winner!" << std::endl;
			break;
		}
		else if (tied)
		{
			bool checkForSame = true;

			// Checks if all remaining Players have the same type
			for (int i = 0; i < numPlayers; i++)
			{
				if (!(*players[p1 - 1] == players[i]))
				{
					// Paper, paper, paper...wait, scissors! Hold!
					checkForSame = false;
					break;
				}
			}
			
			if (checkForSame)
			{
				// Stalemate!
				std::cout << "We have a game-ending tie!" << std::endl;
				break;
			}
			else
			{
				// Play again?
				char answer;
				std::cout << "Play again (y/n)? ";
				std::cin >> answer;
				if (answer == 'n')
				{
					gameRunning = false;
					break;  // quit!
				}
			}
		}
		else
		{
			// Play again?
			char answer;
			std::cout << "Play again (y/n)? ";
			std::cin >> answer;
			if (answer == 'n')
			{
				gameRunning = false;
				break;  // quit!
			}
		}
	}
}

// Check how many players
int Game::checkPlayers()
{
	return numPlayers;
}

// Check if the game's running
bool Game::checkGame()
{
	return gameRunning;
}