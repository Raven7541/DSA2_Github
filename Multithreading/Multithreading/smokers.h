//***************
// smokers.h		9/27/2016
//
// The cigarette smokers
//******************************

#pragma once
#include <iostream>
#include <cstring>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std::chrono_literals;

namespace SMOKER
{
	// Variables
	bool paper = false;
	bool match = false;
	bool tobacco = false;
	bool ready = false;
	bool quit = false;

	std::mutex m;  // mutex
	std::condition_variable cv;  // condition variable

	//-----------
	// Methods
	//-----------
	// The smoker with the paper
	void smokerPaper(int i)
	{
		while (!quit)
		{
			if (ready)
			{
				std::unique_lock<std::mutex> lck(m);  // create unique lock

				if (!paper && match && tobacco)
				{
					// I have the paper!
					std::cout << "Smoker " << i << " is making the cigarette\n";
					match = false;
					tobacco = false;

					// We're done! Take a smoke!
					std::cout << "Smoker " << i << " is now smoking\n";
					std::this_thread::sleep_for(2s);
					ready = false;

					cv.notify_all();
					lck.unlock();  // unlock mutex
				}
			}
		}
	}

	// The smoker with the matches
	void smokerMatch(int i)
	{
		while (!quit)
		{
			if (ready)
			{
				std::unique_lock<std::mutex> lck(m);  // create unique lock

				if (paper && !match && tobacco)
				{
					// I have the matches!
					std::cout << "Smoker " << i << " is making the cigarette\n";
					paper = false;
					tobacco = false;

					// We're done! Take a smoke!
					std::cout << "Smoker " << i << " is now smoking\n";
					std::this_thread::sleep_for(2s);
					ready = false;

					cv.notify_all();
					lck.unlock();  // unlock mutex
				}
			}
		}
	}

	// The smoker with the tobacco
	void smokerTobacco(int i)
	{
		while (!quit)
		{
			if (ready)
			{
				std::unique_lock<std::mutex> lck(m);  // create unique lock

				if (paper && match && !tobacco)
				{
					// I have the tobacco!
					std::cout << "Smoker " << i << " is making the cigarette\n";
					paper = false;
					match = false;

					// We're done! Take a smoke!
					std::cout << "Smoker " << i << " is now smoking\n";
					std::this_thread::sleep_for(2s);
					ready = false;

					cv.notify_all();
					lck.unlock();  // unlock mutex
				}
			}
		}
	}

	// Agent (make more!)
	void agent(int i)
	{
		while (!quit)
		{
			std::cout << "\nAgent is placing the following items on table\n";
			std::unique_lock<std::mutex> lck(m);  // create unique lock

			if (!paper && !match && !tobacco && !ready)
			{
				int select = rand() % 100 + 1;

				if (select <= 33)
				{
					paper = true;
					match = true;
					std::cout << "Paper and match are on the table!\n";
					cv.notify_all();  // time to work!
				}
				else if (select > 33 && select <= 66)
				{
					paper = true;
					tobacco = true;
					std::cout << "Paper and tobacco are on the table!\n";
					cv.notify_all();  // time to work!
				}
				else if (select > 66 && select <= 99)
				{
					match = true;
					tobacco = true;
					std::cout << "Match and tobacco are on the table!\n";
					cv.notify_all();  // time to work!
				}

				ready = true;
			}

			cv.wait(lck);
		}
	}

	// That's enough cigarettes! Now take a break!
	void endWork()
	{
		if (std::cin.get() && !quit)
		{
			quit = true;
			std::cout << "Ending work" << std::endl;
		}
	}

	// Run the threads
	void play()
	{
		std::thread agentThread(agent, 0);
		std::thread t0(smokerPaper, 1);
		std::thread t1(smokerMatch, 2);
		std::thread t2(smokerTobacco, 3);
		std::thread quitThread(endWork);

		agentThread.join();
		t0.join();
		t1.join();
		t2.join();
		quitThread.join();
	}
}