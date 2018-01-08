//***************
// philosophers.h		9/29/2016
//
// The dining philosophers
//
// Five philosophers are sitting at a round table with bowls of spaghetti.
// Five forks are placed between each pair of adjacent philosophers.
//
// A philosopher can only eat if there are the forks to his left and right available.
// If a philosopher is using two forks, the philosopher to his left and/or right has to wait
// until the former is done eating.
//******************************

#pragma once
#include <iostream>
#include <cstring>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std::chrono_literals;

namespace PHILOSOPHER
{
	// Variables
	const int NUM = 5;   // there can only be 5!
	bool phil[NUM];      // philosophers
	bool quit = false;

	std::mutex m;        // mutex


	//-----------
	// Methods
	//-----------
	// Philosopher (I'm hungry...)
	void philosopher(int i)
	{
		//			P0
		//      f4      f0
		//	 P4	           P1
		//    f3          f1
		//      P3      P2
		//		    f2
		
		while (!quit)
		{
			// The philosopher wants to eat...
			std::unique_lock<std::mutex> lck(m);  // create unique lock
			
			int left = i - 1;
			int right = i + 1;

			if (left < 0)
			{
				left = NUM-1;
			}
			else if (left > NUM - 1)
			{
				left = 0;
			}
			if (right < 0)
			{
				right = NUM - 1;
			}
			else if (right > NUM - 1)
			{
				right = 0;
			}

			if (phil[left] && phil[right])
			{
				phil[left] = false;
				phil[right] = false;
				
				// Eating
				std::cout << "Philosopher " << i << " is eating\n";
				lck.unlock();
				std::this_thread::sleep_for(2s);

				// Done eating...I want to think...
				phil[left] = true;
				phil[right] = true;
				std::cout << "Philosopher " << i << " is now thinking\n";
				std::this_thread::sleep_for(2s);
			}
			else
			{
				// Waiting...
				std::cout << "Philosopher " << i << " is waiting\n";
				std::this_thread::sleep_for(1s);
			}
		}
	}

	// End the party!
	void endDinner()
	{
		if (std::cin.get() && !quit)
		{
			quit = true;
			std::cout << "Dinner's over" << std::endl;
		}
	}

	// Run the threads
	void play()
	{
		for (int i = 0; i < NUM; i++)
		{
			phil[i] = true;
		}
		
		while (!quit)
		{
			std::thread quitThread(endDinner);
			std::thread t0(philosopher, 0);
			std::thread t1(philosopher, 1);
			std::thread t2(philosopher, 2);
			std::thread t3(philosopher, 3);
			std::thread t4(philosopher, 4);

			quitThread.join();
			t0.join();
			t1.join();
			t2.join();
			t3.join();
			t4.join();
		}
	}
}