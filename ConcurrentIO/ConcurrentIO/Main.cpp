// Main.cpp			9/27/2016
//
// ICE - Multithreading part 1a

#include <iostream>
#include <cstring>
#include <thread>
using namespace std::chrono_literals;  // allows use of 1s, 2s, 3s, etc. in sleep_for(...)


// Input thread
void inputThreadFunc(char* word)
{
	// Loop until the user calls quit
	while (strcmp(word, "quit") != 0)
	{
		std::cin.getline(word, 99);  // get input
	}
}

// Output thread
void outputThreadFunc(char* word)
{
	// Loop until it finds "quit"
	while ( 0 != strcmp(word, "quit"))
	{
		std::this_thread::sleep_for(1s);  // sleep for 1s
		std::cout << word << std::endl;   // output
	}
}

// Main method
int main() 
{
	// Create c-string
	char word[100] = "Hello, Threads!";

	// Thread actions
	// Spawn input and output threads
	// and rejoin them together!
	std::thread inputThread(inputThreadFunc, word);
	std::thread outputThread(outputThreadFunc, word);

	// join() won't finish working until input thread is done
	// detach() will cause the thread to keep working past the time it goes out of scope

	inputThread.join();    // won't finish working until input thread is done
	outputThread.join();   // won't finish working until output thread is done
						   /*inputThread.detach();
						   outputThread.detach();*/

						   // if a thread's destructor is called before detaching or joining it, program crashes!

	return 0;
}