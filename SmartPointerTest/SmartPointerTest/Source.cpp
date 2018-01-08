#include <iostream>
#include <map>

std::map <void*, int> refCount;

// Unique pointers
template<typename p>
class UniqPtr 
{
	private:
		p* ptr = nullptr;
	
	public:
		UniqPtr() {};

		// Destructor
		~UniqPtr() 
		{ 
			std::cout << "Destructing unique pointer!" << std::endl;

			// Delete only if there's something!
			if (ptr) 
			{ 
				std::cout << "Deleting unique pointer!" << std::endl;
				delete ptr; 
			} 
		}  

		// Constructor - parameterized
		UniqPtr(p* _ptr)
		{
			ptr = _ptr;
		}

		// Constructor - copy copy
		UniqPtr(UniqPtr<p>& other)
		{
			// Check if there's something
			if (other.ptr)
			{
				ptr = new p;
				*ptr = *(other.ptr);
			}
		}

		p* get() { return ptr; }  // accessor
		p& operator*() { return *ptr; }
};

// Shared pointers
template<typename p>
class SharePtr
{
private:
	p* ptr = nullptr;

public:
	// Constructor - default
	SharePtr() {};

	// Destructor
	~SharePtr()
	{
		std::cout << "Destructing shared pointer!" << std::endl;

		// Delete only if there's something!
		// and if refCount == 0
		if (ptr)
		{
			std::cout << "Ref count: " << refCount[ptr] << std::endl;

			if (--refCount[ptr] == 0)
			{
				std::cout << "Deleting unique pointer!" << std::endl;
				delete ptr;
			}
		}
	}

	// Constructor - parameterized
	SharePtr(p* _ptr)
	{
		ptr = _ptr;
		refCount[ptr]++;
	}

	// Constructor - copy copy
	SharePtr(SharePtr<p>& other)
	{
		// Check if there's something
		if (other.ptr)
		{
			ptr = other.ptr;
			refCount[ptr]++;
		}
	}

	p* get() { return ptr; }  // accessor
	p& operator*() { return *ptr; }
};

// Weak pointers (uhhh...I can't move!)
template<typename p>
class WeakPtr
{
private:
	p* ptr = nullptr;

public:
	// Constructor - default
	WeakPtr() {};

	// Destructor (that's it?!)
	~WeakPtr() { std::cout << "Destructing weak pointer!" << std::endl; }

	// Constructor - parameterized
	WeakPtr(p* _ptr)
	{
		ptr = _ptr;
	}

	// Constructor - copy copy
	WeakPtr(SharePtr<p>& other)
	{
		// Check if there's something
		if (other.get())
		{
			ptr = other.get();
		}
	}

	p* get() { return ptr; }  // accessor
	p& operator*() { return *ptr; }
};

// Test pointers
void testPtrs()
{
	// Testing unique pointers in this scope!
	{
		std::cout << "Testing unique pointers!" << std::endl;

		UniqPtr<int> ptr1(new int);
		*ptr1 = 10;

		UniqPtr<int> ptr2(ptr1);
		*ptr2 = 20;

		std::cout << "Print ptr 1: " << ptr1.get() << '\t' << *ptr1 << std::endl;
		std::cout << "Print ptr 2: " << ptr2.get() << '\t' << *ptr2 << std::endl;
	}
	
	std::cout << std::endl;

	// Testing shared pointers in this scope!
	{
		std::cout << "Testing shared pointers!" << std::endl;

		SharePtr<int> ptr1(new int);
		*ptr1 = 10;

		SharePtr<int> ptr2(ptr1);
		*ptr2 = 20;

		std::cout << "Print ptr 1: " << ptr1.get() << '\t' << *ptr1 << std::endl;
		std::cout << "Print ptr 2: " << ptr2.get() << '\t' << *ptr2 << std::endl;
	}

	std::cout << std::endl;

	// Testing weak pointers in this scope!
	{
		std::cout << "Testing weak pointers!" << std::endl;

		SharePtr<int> ptr1(new int);
		*ptr1 = 10;

		WeakPtr<int> ptr2(ptr1);
		*ptr2 = 20;

		std::cout << "Print ptr 1: " << ptr1.get() << '\t' << *ptr1 << std::endl;
		std::cout << "Print ptr 2: " << ptr2.get() << '\t' << *ptr2 << std::endl;
	}
	
	//// Testing raw pointers, will crash if both are deleted
	//// This is a new scope btw
	//{
	//	int* ptr1 = new int;
	//	*ptr1 = 10;

	//	int* ptr2 = ptr1;
	//	*ptr2 = 20;

	//	std::cout << "Print ptr 1: " << ptr1 << '\t' << *ptr1 << std::endl;
	//	std::cout << "Print ptr 2: " << ptr2 << '\t' << *ptr2 << std::endl;

	//	std::cout << "Deleting raw pointer" << std::endl;
	//	delete ptr1;
	//	std::cout << "Deleting raw pointer" << std::endl;
	//	delete ptr2;
	//}

	std::cout << "\nWe're done! Go home!" << std::endl;
}

int main()
{
	testPtrs();

	//std::map<char, unsigned int> letterCount;
	//letterCount['e'] = 1;
	//letterCount['l'] = 2;
	//letterCount['l'] = 3;
	//letterCount['e'] = 2;
	//letterCount['n'] = 1;  // hey, that's me!

	return 0;
}