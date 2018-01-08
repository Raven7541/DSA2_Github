// Main.cpp				10/25/2016
//
// Generate shape models via a text-based UI

#include "GenerateModels.h"

int main()
{
	std::string input;
	int vertices;

	std::cout << "Hello! Select a shape: " << std::endl;
	std::cout << "test: Triangle (for testing purposes)" << std::endl;
	std::cout << "1: Quad" << std::endl;
	std::cout << "2: Box" << std::endl;
	std::cout << "3: Disc" << std::endl;
	std::cout << "4: Cylinder" << std::endl;
	std::cout << "5: Sphere" << std::endl;
	std::cout << "0: Exit" << std::endl;

	std::getline(std::cin, input);

	// Check user input
	if (input == "0")
	{
		std::cout << "Have a nice day!" << std::endl;
	}
	else if (input == "test")
	{
		// Triangle
		std::cout << "Name the file to import the triangle to: " << std::endl;
		std::getline(std::cin, input);
		makeTriangle(input);
		std::cout << "Congrats, you created a triangle!" << std::endl;
	}
	else if (input == "1")
	{
		// Quad
		std::cout << "Name the file to import the quad to: " << std::endl;
		std::getline(std::cin, input);
		makeQuad(input);
		std::cout << "Congrats, you created a quad!" << std::endl;
	}
	else if (input == "2")
	{
		// Box
		std::cout << "Name the file to import the box to: " << std::endl;
		std::getline(std::cin, input);
		makeBox(input);
		std::cout << "Congrats, you created a box!" << std::endl;
	}
	else if (input == "3")
	{
		// Disc
		std::cout << "Name the file to import the disc to: " << std::endl;
		std::getline(std::cin, input);
		std::cout << "How many sides? " << std::endl;
		std::cin >> vertices;
 		makeDisc(input, vertices);
		std::cout << "Congrats, you created a disc!" << std::endl;
	}
	else if (input == "4")
	{
		// Cylinder
		std::cout << "Name the file to import the cylinder to: " << std::endl;
		std::getline(std::cin, input);
		std::cout << "How many sides? " << std::endl;
		std::cin >> vertices;
		makeCylinder(input, vertices);
		std::cout << "Congrats, you created a cylinder!" << std::endl;
	}
	else if (input == "5")
	{
		int longtitude, latitude;
		
		// Sphere
		std::cout << "Name the file to import the sphere to: " << std::endl;
		std::getline(std::cin, input);
		std::cout << "Longtitude? " << std::endl;
		std::cin >> longtitude;
		std::cout << "Latitude? " << std::endl;
		std::cin >> latitude;
		makeSphere(input, longtitude, latitude);
		std::cout << "Congrats, you created a sphere!" << std::endl;
	}
	else
	{
		std::cout << "Huh? o_O" << std::endl;
	}
	
	return 0;
}