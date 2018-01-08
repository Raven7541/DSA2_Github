// CVEvenOdd.h			10/4/2016
//
// Uses control variables

#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std::chrono_literals;

namespace CV_ICE
{
	// Variables
	int number = 0;
	int time = 0;
	std::mutex m;    // allow only 1 person can sit on the guard chair
					 // at a time
	std::condition_variable cv[4];  // one control_variable for everyone!

	//------------
	// Methods
	//------------
	// Adventurer
	void adventurer(int i)
	{
		// Until the night is over...
		while (time < 8)
		{
			// Try to sit on the comfy chair
			std::unique_lock<std::mutex> lck(m);  // create unique variable,
												  // lock the mutex
			// _i_		start time			end time
			//  0			 0					2
			//  1			 2					4
			//  2			 4					6
			//  3			 6					8

			// Determine if it's not your shift
			// If not, wait for someone to wake you
			//     too soon         too late
			if ((time < i * 2) || (time >= (i + 1) * 2))
			{
				std::cout << "Adventurer " << i << " is going to sleep.\n";
				cv[i].wait(lck);  // wait
			}
			else
			{
				//	Take guard duty for 2 hours
				std::this_thread::sleep_for(2s);
				time += 2;
				std::cout << "Adventuerer " << i << " : \"" << time << " o 'clock and all's well!\"\n";

				//	Wake up the next person
				cv[(i + 1) % 4].notify_all();
			}
		}

		std::cout << "Good morning!" << std::endl;
	}

	// Run the threads (using mutex and control variable)
	void playCV()
	{
		std::thread t0(adventurer, 0);
		std::thread t1(adventurer, 1);
		std::thread t2(adventurer, 2);
		std::thread t3(adventurer, 3);

		t0.join();
		t1.join();
		t2.join();
		t3.join();
	}
}