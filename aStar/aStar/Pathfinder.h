#pragma once
#include "Heap.h"

class Pathfinder
{

public:
	Pathfinder();  // Constructor - default
	~Pathfinder();

	void setMap(char* fileName);
	void run();

private:
	void displayMap();   // display the current map
	void addNeighbors(int current);   // check on neighbors
	void calcDistance(int node);   // calculate h(n) and f(n)
	void clearSearch();   // found the goal! Clear the map!

	int data[25];   // Map!
	bool visited[25] = {};  // default to false

	Heap<float, float> priorityQueue;

	int start;   // start node
	int goal;   // endgame

	int fDist[25];   // f(n) = g(n) + h(n)
	int gDist[25];   // g(n) = cost to move from spot
	int hDist[25];   // h(n) = abs(current.x - goal.x) + abs(current.y - goal.y)
	int backTrace[25];   // back trace
	bool path[25] = {};   // follow the yellow brick road!
	int trace = 0;   // final distance

	int xVal[25];   // Manhattan square!
	int yVal[25];

};

