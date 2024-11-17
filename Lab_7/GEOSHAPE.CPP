#include <iostream.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

class GeoShape
{
	protected:
		float dim1;
		float dim2;
	public:
		GeoShape()
		{
			dim1 = 0;
			dim2 = 0;
		}
		GeoShape(float _dim)
		{
			dim1 = _dim;
			dim2 = _dim;
		}
		GeoShape(float _dim1, float _dim2)
		{
			dim1 = _dim1;
			dim2 = _dim2;
		}
		void setDim1(float _dim)
		{
			dim1 = _dim;
		}
		void setDim2(float _dim)
		{
			dim2 = _dim;
		}
		float getDim1()
		{
			return dim1;
		}
		float getDim2()
		{
			return dim2;
		}
		// make it virtual because it will DEFINITELY be overridden
		virtual float calcArea()
		{
			return 0.0;
		}
};

class Rect : protected GeoShape
{
	// no section for private variables since it inherited them
	public:
		Rect(float x, float y) : GeoShape(x, y)
		{

		}
		float calcArea()
		{
			return (dim1 * dim2);
		}
};

class Square : protected Rect
{
	// no section for private variables
	public:
		Square(float x) : Rect(x, x)
		{

		}
		void setSide(float x)
		{
			dim1 = x;
			dim2 = x;
		}
		// no need to rewrite calcArea if it is public inher
		// HOWEVER
		float calcArea()
		{
			return (dim1 * dim2);
		}
};

class Triangle : protected GeoShape
{
	// no section for private variables
	public:
		Triangle(float base, float height) : GeoShape(base, height)
		{

		}
		float calcArea()
		{
			return (0.5 * dim1 * dim2);
		}
};

class Circle : protected GeoShape
{
	// no section for private variables
	public:
		Circle(float radius) : GeoShape(radius)
		{

		}
		void setRadius(float r)
		{
			dim1 = r;
			dim2 = r;
		}
		float calcArea()
		{
			return ( (22.0/7.0) * dim1 * dim2 );
		}
};

float calcSumOfAreas(GeoShape *ptr1, GeoShape *ptr2, GeoShape *ptr3)
{
	return ( (ptr1->calcArea()) + (ptr2->calcArea()) + (ptr3->calcArea()) );
}

int main()
{
	clrscr();

	Circle c1(10), c2(20), c3(30);
	Rect r1(10, 20), r2(30, 40), r3(50, 60);
	Square s1(40), s2(50), s3(60);

	// printing individual areas to make my life easier
	cout << "Areas of Circles: \n"
		 << "C1 = " << c1.calcArea() << "\n"
		 << "C2 = " << c2.calcArea() << "\n"
		 << "C3 = " << c3.calcArea() << "\n";

	cout << "Areas of Rectangles: \n"
		 << "R1 = " << r1.calcArea() << "\n"
		 << "R2 = " << r2.calcArea() << "\n"
		 << "R3 = " << r3.calcArea() << "\n";

	cout << "Areas of Squares: \n"
		 << "S1 = " << s1.calcArea() << "\n"
		 << "S2 = " << s2.calcArea() << "\n"
		 << "S3 = " << s3.calcArea() << "\n";

	// printing sum of areas
	cout << "Sum of Areas: \n"
		 << "C1 + R1 + S1 = " << calcSumOfAreas((GeoShape*)&c1, (GeoShape*)&r1, (GeoShape*)&s1) << "\n"
		 << "C2 + R2 + S2 = " << calcSumOfAreas((GeoShape*)&c2, (GeoShape*)&r2, (GeoShape*)&s2) << "\n"
		 << "C3 + R3 + S3 = " << calcSumOfAreas((GeoShape*)&c3, (GeoShape*)&r3, (GeoShape*)&s3) << "\n";

	return 1;
}