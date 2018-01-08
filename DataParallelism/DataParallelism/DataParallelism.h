#pragma once
#include <iostream>
#include <thread>
using namespace std::chrono_literals;


// Operate on range
void operateOnRange(float* data, int a, int b)
{
	for (int i = a; i < b; i++)
	{
		data[i] = sqrt(i);
	}
}

// Test parallels
void testParallel(float* test, int n)
{
	std::cout << "Doing " << n << " things in 4 threads." << std::endl;

	// Set up threads
	std::thread t0(operateOnRange, test, 0,	    n/4);
	std::thread t1(operateOnRange, test, n/4,	n/2);
	std::thread t2(operateOnRange, test, n/2,	3*n/4);
	std::thread t3(operateOnRange, test, 3*n/4, n);

	// Join threads
	t0.join();
	t1.join();
	t2.join();
	t3.join();
}

// Test series
void testSeries(float* test, int n)
{
	std::cout << "Doing " << n << " things in 1 thread." << std::endl;

	operateOnRange(test, 0, n);
}

// Run a bunch of tests
void runTests(int n)
{
	float* data = new float[n];
	
	// Test series
	clock_t t1 = clock();
	// do work
	testSeries(data, n);
	t1 = clock() - t1;		// calculates delta-t
	std::cout << "Series t (ms): " << 1000.f*(float)t1 / (float)CLOCKS_PER_SEC << std::endl;

	// Test parallels
	clock_t t2 = clock();
							// do work
	testParallel(data, n);
	t2 = clock() - t2;		// calculates delta-t
	std::cout << "Parallel t (ms): " << 1000.f*(float)t2 / (float)CLOCKS_PER_SEC << std::endl;

	delete data;
	std::cout << std::endl;
}