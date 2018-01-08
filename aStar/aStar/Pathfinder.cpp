// Pathfinder.cpp			9/19/2016
//
// Where the A* pathfinding stuff happens

#include <iostream>
#include <fstream>
#include <cmath>
#include "Pathfinder.h"


// Constructor - default
Pathfinder::Pathfinder()
{
	priorityQueue = Heap<float, float>();
	start = 0;
	goal = 0;
}

// Destructor
Pathfinder::~Pathfinder()
{

}

// Run A* pathfinding!
void Pathfinder::run()
{
	// Keep running until the goal has been found
	while (!visited[goal])
	{
		if (priorityQueue.size == 0)
		{
			std::cout << "There's nothing in the heap!" << std::endl;
			return;
		}
		
		// Get current node
		int current = priorityQueue.pop();
		visited[current] = true;
		displayMap();			// display the map for now
		addNeighbors(current);
		
		if (visited[goal])
		{
			clearSearch();
			break;   // get out!
		}
		else
		{
			std::cout << "Press 'Enter' to continue" << std::endl;
			std::cin.get();  // wait for user to press "Enter"
		}
	}

	// You found the exit! Get outta here!
	std::cout << "\nDistance: " << trace << std::endl;
	displayMap();

	std::cout << "Press 'Enter' to quit" << std::endl;
	std::cin.get();
}

// Look at the neighbors
// Private
void Pathfinder::addNeighbors(int current)
{
	int above = current - 5;
	int below = current + 5;
	int left = current - 1;
	int right = current + 1;

	// Check the neighbors
	if (below >= 0 && !visited[below])
	{
		// Below neighbor
		gDist[below] = gDist[current] + data[below];

		calcDistance(current);
		calcDistance(below);

		// Is f(n+5) <= f(n)?
		if (fDist[below] <= fDist[current])
		{
			priorityQueue.push(gDist[below], below);
			backTrace[below] = current;
			path[current] = true;
		}

		// Is it the goal?
		if (below == goal)
		{
			visited[goal] = true;
			path[goal] = true;
		}
	}
	if (above <= 24 && !visited[above])
	{
		// Above neighbor
		gDist[above] = gDist[current] + data[above];

		calcDistance(current);
		calcDistance(above);

		// Is f(n-5) <= f(n)?
		if (fDist[above] <= fDist[current])
		{
			priorityQueue.push(gDist[above], above);
			backTrace[above] = current;
			path[current] = true;
		}

		// Is it the goal?
		if (above == goal)
		{
			visited[goal] = true;
			path[goal] = true;
		}
	}
	if ((right % 5) <= 4 && !visited[right])
	{
		// Right neighbor
		gDist[right] = gDist[current] + data[right];

		calcDistance(current);
		calcDistance(right);

		// Is f(n+1) <= f(n)?
		if (fDist[right] <= fDist[current])
		{
			priorityQueue.push(gDist[right], right);
			backTrace[right] = current;
			path[current] = true;
		}

		// Is it the goal?
		if (right == goal)
		{
			visited[goal] = true;
			path[goal] = true;
		}
	}
	if (left >= 0 && !visited[left])
	{
		// Left neighbor
		gDist[left] = gDist[current] + data[left];

		calcDistance(current);
		calcDistance(left);

		// Is f(n-1) <= f(n)
		if (fDist[left] <= fDist[current])
		{
			priorityQueue.push(gDist[left], left);
			backTrace[left] = current;
			path[current] = true;
		}

		// Is it the goal?
		if (left == goal)
		{
			visited[goal] = true;
			path[goal] = true;
		}
	}

}

// Calculate h(n) and f(n)
// Private
void Pathfinder::calcDistance(int node)
{
	// Check if it's the start node
	if (node != 12)
	{
		hDist[node] = abs(xVal[node] - xVal[goal]) + abs(yVal[node] - yVal[goal]);  // h(n) = abs(current.x - goal.x) + abs(current.y - goal.y)
		fDist[node] = gDist[node] + hDist[node];
	}
	else
	{
		fDist[node] = 50;  // it's how it'll work
	}
}

// Display the map
// Private
void Pathfinder::displayMap()
{
	if (!visited[goal])
	{
		// Display map
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				// Determines if it's visited or not
				// If so, displays; if not, empty value			
				if (visited[i * 5 + j])
				{
					std::cout << "X ";
				}
				else
				{
					std::cout << data[i * 5 + j] << ' ';
				}
				//std::cout << ((visited[i * 5 + j]) ? 'X' : data[i * 5 + j]) << ' ';  <-- doesn't work!
			}
			std::cout << std::endl;
		}
	}
	else
	{
		// Display map
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				// Determines if it's visited or not
				// If so, displays; if not, empty value			
				if (visited[i * 5 + j])
				{
					std::cout << "O ";
				}
				else
				{
					std::cout << data[i * 5 + j] << ' ';
				}
			}
			std::cout << std::endl;
		}
	}
}

// Clear the map
// Private
void Pathfinder::clearSearch()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			// Is this part of the correct path?
			if (backTrace[i * 5 + j] >= -1 && backTrace[i * 5 + j] <= start && path[i*5+j])
			{
				trace += data[i * 5 + j];
				continue;
			}
			else
			{
				visited[i * 5 + j] = false;
			}
		}
	}
}

// Load the map
void Pathfinder::setMap(char* fileName)
{
	// Read map
	std::fstream file(fileName, std::ios_base::in);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			file >> data[i * 5 + j];

			if (0 == data[i * 5 + j] && (i * 5 + j) != 12)
			{
				goal = i * 5 + j;
			}
		}
	}
	file.close();

	// Fill up the xVals and yVals
	for (int i = 0; i < 25; i++)
	{
		if (i % 5 == 0)
		{
			for (int j = 0, k = i; j < 5, k < i+5; j++, k++)
			{
				xVal[k] = j % 25;
			}
			for (int j = i; j < i+5; j++)
			{
				yVal[j] = i / 5;
			}
		}
	}

	// Find the start node, 
	// set it up and add it into the priority queue
	for (int i = 0; i < 25; i++)
	{
		// Make sure we have a start node
		if (start == 0)
		{
			// Keep looking
			for (int j = 0; j < 5; j++)
			{
				if (0 == data[i * 5 + j] && (i * 5 + j) != goal)
				{
					start = i * 5 + j;
					break;
				}
			}
		}
		else
		{
			break;
		}
	}

	priorityQueue.push(start, start);
	backTrace[start] = -1;
	gDist[start] = data[start];
}
