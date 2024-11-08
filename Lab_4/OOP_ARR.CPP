#include <iostream.h>
#include <stdlib.h>

class MyArray
{
	private:
		unsigned int arrSize;
		int *arrPtr;
	public:
		MyArray(int size = 1)
		{
			this->arrSize = size;
			this->arrPtr = new int[arrSize];
		}
		~MyArray()
		{
			delete[] this->arrPtr;
		}
		int & operator [] (unsigned int index)
		{
			if (index < this->arrSize)
				return arrPtr[index];
			else
				cout << "Array Index is Out of Bounds!\n";

			exit(1);
		}

};

void main()
{
	MyArray arr(10);

	for (int i = 0; i < 10; i++)
	{
		cout << "Enter a number to store in the array: ";
		cin >> arr[i];
	}

	cout << "\n\[ ";
	for (i = 0; i < 10; i++)
	{
		cout << arr[i]
			 << " ";
	}
	cout << "\]\n";

	return;
}