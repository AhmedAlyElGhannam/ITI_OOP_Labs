#include <iostream.h>
#include <conio.h>

typedef enum
{
  true = 1,
  false = 0
} bool;

template<class T>
class Stack
{
	private:
		int topOfStack;
		unsigned int stackSize;
		T *stackArr;
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
			this->stackArr = new T[this->stackSize];

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
			this->stackArr = new T[this->stackSize];
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
		bool push(const T _val)
		{
			if (this->isStackFull())
			{
				return false;
			}

			this->stackArr[topOfStack] = _val;
			topOfStack++;

			return true;
		}
		bool pop(T & _val)
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
			this->stackArr = new T[this->stackSize];

			for (int i = 0; i < s.topOfStack; i++)
			{
				this->stackArr[i] = s.stackArr[i];
			}

			return (*this);
		}

};





template <class T>
void viewContent(Stack<T> & s)
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

template <class T>
int Stack<T>::counter = 0;

void main()
{
	clrscr();
	Stack<float> stackystacky(5);

	stackystacky.push(6.7);
	stackystacky.push(7.1);
	stackystacky.push(99.4);
	stackystacky.push(86.9);
	stackystacky.push(42.6);

	// printing stack after pushing 5 elements
	viewContent(stackystacky);

	// poping element then printing stack
	int n;
	stackystacky.pop(n);
	cout << "Popped Element = "
		 << n
		 << endl;
	viewContent(stackystacky);
	stackystacky.push(731.4);
	viewContent(stackystacky);

	Stack<float> stackystacky2(7);

	cout << "\nTrying operator = on stackyStacky: \n";
	stackystacky2 = stackystacky;
	viewContent(stackystacky2);

	return;
}