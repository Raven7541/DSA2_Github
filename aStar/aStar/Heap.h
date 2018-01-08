#pragma once
template <typename keyValue, typename valValue>
class Heap
{

public:
	int size;  // heap size

	// Constructor
	Heap()
	{
		size = 0;
	}

	// Destructor
	~Heap() {};

	// Push a value into the heap
	void push(keyValue newKey, valValue newVal)
	{
		if (size < MAX_SIZE)
		{
			key[size] = newKey;
			value[size] = newVal;
			size++;
			heapifyUp(size - 1);
		}
	}

	// Pop out the top value from the heap
	valValue pop()
	{
		keyValue tempKey = key[0];  // get temp values
		valValue tempVal = value[0];
		key[0] = key[size - 1];		// replace
		value[0] = value[size - 1];
		key[size - 1] = NULL;		// remove
		value[size - 1] = NULL;
		size--;						// decrement
		heapifyDown(0);

		return tempVal;
	}


private:
	// Heapify up
	void heapifyUp(int i)
	{
		if (i <= 0) return;

		int j = parent(i);  // find parent node

		if (key[i] < key[j])
		{
			swap(i, j);
		}

		heapifyUp(j);
	}

	// Heapify down
	void heapifyDown(int i)
	{
		int j = 0;

		// If no children...
		if (childLeft(i) > size - 1) return;

		// If no right children...
		if (childRight(i) > size - 1)
		{
			j = childLeft(i);
		}
		else
		{
			// If both right and left children
			j = (key[childLeft(i)] < key[childRight(i)]) ? (childLeft(i)) : (childRight(i));
		}

		if (key[i] > key[j])
		{
			swap(i, j);
		}

		heapifyDown(j);
	}

	// Swap values
	void swap(int i, int j)
	{
		keyValue tempKey = key[i];
		key[i] = key[j];
		key[j] = tempKey;

		valValue tempVal = value[i];
		value[i] = value[j];
		value[j] = tempVal;
	}

	// Return parent
	int parent(int i)
	{
		return (i - 1) / 2;
	}
	
	// Return left child
	int childLeft(int i)
	{
		return 2 * i + 1;
	}

	// Return right child
	int childRight(int i)
	{
		return 2 * i + 2;
	}

	static const int MAX_SIZE = 100;
	keyValue key[MAX_SIZE];
	valValue value[MAX_SIZE];
};