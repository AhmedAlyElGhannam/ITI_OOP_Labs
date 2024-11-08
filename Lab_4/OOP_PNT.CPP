#include <iostream.h>
#include <stdlib.h>

class Point
{
	private:
		int x;
		int y;
	public:
		Point(int _x = 0, int _y = 0)
		{
			this->x = _x;
			this->y = _y;
		}
		~Point()
		{

		}
		void print()
		{
			cout << "Point Coordinates: "
				 << "\( "
				 << this->x
				 << ", "
				 << this->y
				 << " \)"
				 << endl;
		}
		/**********************************/
		void operator () (int _x, int _y)
		{
			this->x = _x;
			this->y = _y;
		}

};

void main()
{
	Point p1;

	cout << "\np1's Default Value: \n";
    p1.print();

	cout << "\nTrying () Overloading: \n";
	p1(6, 9);
	p1.print();

	return;
}