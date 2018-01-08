//***************
// barbers.h		9/27/2016
//
// The sleeping barber
//
// When barber finishes a client, he checks the waiting room
// if empty, he goes to sleep
// if not empty, he works on a client
//
// When client walks into shop,
// he rings a bell to awaken the barber
//******************************

#pragma once
#include <iostream>
#include <cstring>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std::chrono_literals;

namespace BARBER
{
	// Variables
	int clientWaiting = 0, clientServed = 0;  // # of clients waiting, # of clients already served
	bool quit = false;
	std::mutex m;  // mutex
	std::condition_variable control;   // allow thread to sleep and relinquish control of mutex

	//-------------
	// Methods
	//-------------
	// Barber (wake up!)
	void barber()
	{
		while (!quit)
		{
			std::unique_lock<std::mutex> lck(m);  // create unique lock

												  // Check the waiting room
			if (clientWaiting < 1)
			{
				std::cout << "No work to do...ZZZZ" << std::endl;
				control.wait(lck);  // go to sleep!
			}
			if (clientWaiting > 0)
			{
				// Work to do
				clientWaiting--;
				clientServed++;
				std::cout << "Giving a haircut to client #" << clientServed << std::endl;

				lck.unlock();
				std::this_thread::sleep_for(1s);
			}
		}
	}

	// Client (waiting waiting waiting)
	void client()
	{
		while (!quit)
		{
			std::this_thread::sleep_for(1s*(rand() % 2 + 1));  // sleep for 1 or 2 sec

			std::unique_lock<std::mutex> lck(m);  // create unique lock

			std::cout << "Client enters with # ppl waiting = " << clientWaiting << std::endl;
			clientWaiting++;
			if (clientWaiting == 1)
			{
				control.notify_all();  // WAKE UP!
			}
		}
	}

	// I'm done with today! I want to go home!
	void quitWork()
	{
		if (std::cin.get() && !quit)
		{
			quit = true;
			std::cout << "Closing shop" << std::endl;
		}
	}

	// Where the threads run
	void play()
	{
		srand(time(NULL));

		std::thread quitThread(quitWork);
		std::thread t0(barber);
		std::thread t1(client);
		
		quitThread.join();
		t0.join();
		t1.join();
	}
}