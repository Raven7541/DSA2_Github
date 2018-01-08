// EvenOdd.h			10/4/2016
//
// Uses mutex

#pragma once
#include <iostream>
#include <thread>
#include <mutex>
using namespace std::chrono_literals;

namespace MUTEX_ICE
{
	// Variables
	int number = 0;
	std::mutex m;    // allow only 1 thread access to a block of code
					 // at a time


	//------------
	// Methods
	//------------
	// Check if number is even
	void opEven(int id)
	{
		while (true)
		{
			m.lock();  // either lock the mutex (if unlocked
					   // or get in queue to lock the mutex
					   // (and wait for it)

			if (!(number & 1))
			{
				number++;
				std::cout << "Thread " << id << " sets num to " << number << std::endl;
				m.unlock();  // unlock the mutex
				std::this_thread::sleep_for(4s);
			}
			else
			{
				m.unlock();  // unlock the mutex
			}
		}
	}

	// Check if number is odd
	void opOdd(int id)
	{
		while (true)
		{
			m.lock();  // either lock the mutex (if unlocked
					   // or get in queue to lock the mutex
					   // (and wait for it)

			if (number & 1)
			{
				number++;
				std::cout << "Thread " << id << " sets num to " << number << std::endl;
				m.unlock();  // unlock the mutex
				std::this_thread::sleep_for(4s);
			}
			else
			{
				m.unlock();  // unlock the mutex
			}
		}
	}

	// Run the threads (using mutex)
	void playMutex()
	{
		std::thread t0(opOdd, 0);
		std::thread t1(opOdd, 1);
		std::thread t2(opEven, 2);
		std::thread t3(opEven, 3);

		t0.join();
		t1.join();
		t2.join();
		t3.join();
	}
}