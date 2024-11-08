#include <iostream.h>
#include <conio.h>

typedef enum
{
  true = 1,
  false = 0
} bool;

class Stack
{
	private:
		int topOfStack;
		unsigned int stackSize;
		int *stackArr;
		static int counter;
	public:
		Stack()
		{

		}
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
		// adding copy constructor to solve Dynamic Area Problem
		Stack(Stack & s)
		{
			counter++;
			this->topOfStack = s.topOfStack;
			this->stackSize = s.stackSize;
			this->stackArr = new int[this->stackSize];
			// copying each element inside the original stack to the copy
			for (int i = 0; i < (this->topOfStack); i++)
			{
				(this->stackArr[i]) = s.stackArr[i];
			}
		}
		~Stack()
		{
			delete[] (this->stackArr);
			this->stackSize = 0;
			this->topOfStack = -1;
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
		friend void viewContent(Stack &s);

		/****************************************/
		// haha, Operator Overloading goes brrr!

		// s1 = s2
		Stack & operator = (Stack & s)
		{
			this->topOfStack = s.topOfStack;
			this->stackSize = s.stackSize;

			delete[] this->stackArr;
			this->stackArr = new int[this->stackSize];

			for (int i = 0; i < s.topOfStack; i++)
			{
				this->stackArr[i] = s.stackArr[i];
			}

			return (*this);
		}

};






void viewContent(Stack & s)
{
	if (s.isStackEmpty())
	{
		cout << "\[ \]"
			 << endl;
	}
	cout << "\[";
	for (int i = 0; i < s.topOfStack; i++)
	{
		cout << s.stackArr[i];
		if (i < (s.topOfStack - 1))
			cout << " ";
	}
	cout << "\]"
		 << endl;
}

int Stack::counter = 0;

void main()
{
	clrscr();
	Stack stackystacky(5);

	stackystacky.push(6);
	stackystacky.push(7);
	stackystacky.push(99);
	stackystacky.push(86);
	stackystacky.push(42);

	// printing stack after pushing 5 elements
	viewContent(stackystacky);

	// poping element then printing stack
	int n;
	stackystacky.pop(n);
	cout << "Popped Element = "
		 << n
		 << endl;
	viewContent(stackystacky);
	stackystacky.push(731);
    viewContent(stackystacky);

	Stack stackystacky2(7);

	cout << "\nTrying operator = on stackyStacky: \n";
	stackystacky2 = stackystacky;
	viewContent(stackystacky2);

	return;
}