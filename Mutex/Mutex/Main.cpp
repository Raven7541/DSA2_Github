// Main.cpp					10/4/2016
//
// ICE - Mutex and shared resources

#include "EvenOdd.h"
#include "CVEvenOdd.h"

// Main method
int main()
{
	// Start the threads!
	MUTEX_ICE::playMutex();
	//CV_ICE::playCV();

	std::cin.get();
	return 0;
}