#include <iostream.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>

// defining colours
#define BLACK			0x00
#define BLUE			0x01
#define GREEN           0x02
#define CYAN            0x03
#define RED             0x04
#define MAGENTA         0x05
#define BROWN           0x06
#define LIGHT_GRAY      0x07
#define DARK_GRAY       0x08
#define LIGHT_BLUE      0x09
#define LIGHT_GREEN     0x0A
#define LIGHT_CYAN      0x0B
#define LIGHT_RED       0x0C
#define LIGHT_MAGENTA   0x0D
#define YELLOW          0x0E
#define WHITE           0x0F

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
		Point(Point & _point)
		{
			this->x = _point.getX();
			this->y = _point.getY();
		}
		~Point()
		{

		}
		void setX(int _x)
		{
			this->x = _x;
		}
		void setY(int _y)
		{
			this->y = _y;
		}
		int getX()
		{
			return this->x;
		}
		int getY()
		{
			return this->y;
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

class Circle
{
	private:
		Point centre;
		int radius;
		int colour;
	public:
		Circle() : centre(100, 100)
		{
			this->colour = 0;
			this->radius = 25;
		}
		Circle(int x, int y, int _radius, int _colour)
		: centre(x, y)
		{
			this->colour = _colour;
			this->radius = _radius;
		}
		Point getCentre()
		{
			return this->centre;
		}
		void setCentre(int _x, int _y)
		{
			this->centre(_x, _y);
		}
		void setColour(int _colour)
		{
			this->colour = _colour;
		}
		void setRadius(int _radius)
		{
			this->radius = _radius;
		}
		Circle(Circle & _circle)
		: centre(_circle.centre)
		{
			this->colour = _circle.colour;
			this->radius = _circle.radius;
		}
		void drawCircle()
		{
			setcolor(this->colour);
			circle(centre.getX(), centre.getY(), radius * 2);
		}
		~Circle()
		{

		}

};

void main()
{

	// essential if you want to use graphics.h
	int gm, gd = DETECT;
	initgraph(&gm, &gd, "D:\\BGI\\"); // this is where bgi folder is located on my machine

	// creating circle
	Circle c1(300, 300, 75, CYAN);

	// drawing rectangle
	c1.drawCircle();


	return;
}