#pragma once
#include <map>
std::map<void*, int> refCount;

template<typename p>
class SharedPtr
{

private:
	p* ptr = nullptr;

public:
	SharedPtr()
	{
		ptr = nullptr;
	}

	~SharedPtr()
	{
		delete ptr;
	}

	p* get()
	{
		return ptr;
	}
	
	p& operator*()
	{
		//return *ptr;
	}

	SharedPtr(p* _ptr)
	{
		
	}

	SharedPtr(SharedPtr<p>& other)
	{
		
	}

};