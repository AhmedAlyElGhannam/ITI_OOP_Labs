#include <iostream.h>

typedef enum
{
  true = 1,
  false = 0
} bool;

class Stack
{
	private:
		unsigned int topOfStack;
		unsigned int stackSize;
		int *stackArr;
		static int counter;
	public:
		Stack(const unsigned int _size = 1)
		{
			counter++;
			topOfStack = 0;
			this->stackSize = _size;
			this->stackArr = new int[this->stackSize];

			// for debugging purposes
			cout << "Hello From Constructor with Counter Value of "
				 << this->getCounter()
				 << endl;
		}
		~Stack()
		{
			delete[] (this->stackArr);
			this->stackSize = 0;
			counter--;

			// for debugging purposes
			cout << "Goodbye From Destructor with Counter Value of "
				 << this->getCounter()
				 << endl;
		}

		bool isStackEmpty()
		{
			return (topOfStack == 0 ? true : false);
		}
		bool isStackFull()
		{
			return (topOfStack == stackSize ? true : false);
		}
		bool push(const int _val)
		{
			if (this->isStackFull())
			{
				return false;
			}

			this->stackArr[topOfStack] = _val;
			topOfStack++;

			return true;
		}
		bool pop(int & _val)
		{
			if (this->isStackEmpty())
			{
				return false;
			}

			topOfStack--;
			_val = this->stackArr[topOfStack];
			return true;
		}
		const int getCounter()
		{
			return counter;
		}
		void print();

};






void Stack::print()
{
	if (this->isStackEmpty())
	{
		cout << "\[ \]"
			 << endl;
	}
	cout << "\[";
	for (int i = 0; i < this->topOfStack; i++)
	{
		cout << this->stackArr[i];
		if (i < (this->topOfStack - 1))
			cout << " ";
	}
	cout << "\]"
		 << endl;
}

int Stack::counter = 0;

void main()
{
	Stack stackystacky(5);

	stackystacky.push(6);
	stackystacky.push(7);
	stackystacky.push(99);
	stackystacky.push(86);
	stackystacky.push(42);

	// printing stack after pushing 5 elements
	stackystacky.print();

	// poping element then printing stack
	int n;
	stackystacky.pop(n);
	cout << "Popped Element = "
		 << n
		 << endl;
	stackystacky.print();

	return;
}