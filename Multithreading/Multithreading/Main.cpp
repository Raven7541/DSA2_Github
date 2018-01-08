// Main.cpp					9/27/2016
//
// HW3 - Multithreading

#include <iostream>
#include "barbers.h"
#include "philosophers.h"
#include "smokers.h"

int main()
{
	// Start the sleeping barber
	BARBER::play();
	std::cout << std::endl;

	// Start the dining philosophers
	PHILOSOPHER::play();
	std::cout << std::endl;

	// Start the cigarette smokers
	SMOKER::play();

	std::cout << "\nEveryone's done! :)" << std::endl;
	std::cin.get();
	return 0;
}