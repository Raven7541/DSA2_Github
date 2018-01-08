//****************
// Source.cpp			9/8/2016
//
// A* pathfinding
//****************

#include <iostream>
#include <fstream>
#include "Heap.h"
#include "Pathfinder.h"

// Test if priority queue/heap works as intended
void testHeap()
{
	// Create a heap and push in values
	Heap<float, char> heap = Heap<float, char>();
	heap.push(2.5, 'w');
	heap.push(10.0, 'a');
	heap.push(1.1, 's');
	heap.push(7.7, 'x');
	heap.push(5.5, 'd');

	// Output
	while (heap.size > 0)
	{
		char output = heap.pop();
		std::cout << output << std::endl;
	}
}

// Main method (where everything runs!)
int main()
{
	//testHeap();
	Pathfinder path;
	path.setMap("map.txt");
	path.run();

	return 0;
}
