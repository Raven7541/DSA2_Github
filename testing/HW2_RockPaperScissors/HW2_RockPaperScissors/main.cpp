// Main.cpp				Ellen Chen, 2/21/2016
//						Adjusted on 8/30/2016
//
// Where the main game happens (full game, not Early Access!)!

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include "Game.h"


SCENARIO("Trying to play a game of Rock Paper Scissors")
{
	Game game;  // set up the game
	
	GIVEN("Setting up the game")
	{
		game.assemble();
		/*REQUIRE(game.checkPlayers() >= 2);
		REQUIRE(game.checkPlayers() <= 10);*/

		WHEN("the player enters a number of players")
		{
			// Checks if the number of players is valid
			REQUIRE(game.checkPlayers() >= 2);
			REQUIRE(game.checkPlayers() <= 10);

			THEN("the game has been assembled")
			{
				std::cout << "Game can start!" << std::endl;  // affirmative
			}
		}

		WHEN("all conditions has been met")
		{
			// Checks if all conditions have been met
			REQUIRE(game.checkPlayers() >= 2);
			REQUIRE(game.checkPlayers() <= 10);
			REQUIRE(game.checkGame() == true);

			THEN("run the game")
			{
				game.run();
			}
		}
	}
}


// Main method
//int main()
//{
//	// Set up the game
//	Game game;
//
//	// Run it!
//	game.assemble();
//	game.run();
//
//	std::cin.ignore();
//	std::cin.get();
//	return 0;
//}