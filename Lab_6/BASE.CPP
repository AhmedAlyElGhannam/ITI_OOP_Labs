#include <iostream.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>


class Base
{
	protected:
		int x;
		int y;
	public:
		Base()
		{
			this->x = 0;
			this->y = 0;
		}
		Base(int _x, int _y)
		{
			this->x = _x;
			this->y = _y;
		}
		Base(Base & _base)
		{
			this->x = _base.get1st();
			this->y = _base.get2nd();
		}
		~Base()
		{

		}
		void set1st(int _x)
		{
			this->x = _x;
		}
		void set2nd(int _y)
		{
			this->y = _y;
		}
		int get1st()
		{
			return this->x;
		}
		int get2nd()
		{
			return this->y;
		}
		int calculateSum()
		{
			return (this->x + this->y);
		}

		/**********************************/
		void operator () (int _x, int _y)
		{
			this->x = _x;
			this->y = _y;
		}

};

class Derived : public Base
{
	private:
		int z;
	public:
		Derived() : Base(0, 0)
		{
			this->z = 0;
		}
		Derived(int _x, int _y, int _z) : Base(_x, _y)
		{
			this->z = _z;
		}
		int get3rd()
		{
			return this->z;
		}
		void set3rd(int _z)
		{
			this->z = _z;
		}
		Derived(Derived & _derived)
		: Base(_derived)
		{
			this->z = _derived.z;
		}
		int calculateSum()
		{
			return (this->x + this->y + this->z);
		}
		~Derived()
		{

		}

};

void main()
{

	clrscr();
	Base based1(1, 2);
	cout << "Sum of Based Object = "
		 << based1.calculateSum()
		 << endl;
	Derived derived1(1, 2, 3);
	cout << "Sum of Derived Object = "
		 << derived1.calculateSum()
         << endl;

	return;
}