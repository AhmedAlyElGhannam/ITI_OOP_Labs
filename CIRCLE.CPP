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


class Line
{
	private:
		Point start;
		Point end;
		int colour;
	public:
		Line() : start(0, 0), end(0, 0)
		{
			this->colour = 0;
		}
		Line(int x1, int y1, int x2, int y2, int _colour)
		: start(x1, y1), end(x2, y2)
		{
			this->colour = _colour;
		}
		Point getStart()
		{
			return this->start;
		}
		Point getEnd()
		{
			return this->end;
		}
		void setStart(int _x, int _y)
		{
			this->start(_x, _y);
		}
		void setEnd(int _x, int _y)
		{
			this->end(_x, _y);
		}
		void setColour(int _colour)
		{
			this->colour = _colour;
		}
		Line(Line &_line)
		: start(_line.start), end(_line.end)
		{
			this->colour = _line.colour;
		}
		void drawLine()
		{
			setcolor(this->colour);
			line(start.getX(), start.getY(), end.getX(), end.getY());
		}
		~Line()
		{

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


class Rect
{
	private:
		Point upperLeft;
		Point lowerRight;
		int colour;
	public:
		Rect() : upperLeft(0, 0), lowerRight(0, 0)
		{
			this->colour = 0;
		}
		Rect(int x1, int y1, int x2, int y2, int _colour)
		: upperLeft(x1, y1), lowerRight(x2, y2)
		{
			this->colour = _colour;
		}
		Point getUpperLeft()
		{
			return this->upperLeft;
		}
		Point getLowerRight()
		{
			return this->lowerRight;
		}
		void setUpperLeft(int _x, int _y)
		{
			this->upperLeft(_x, _y);
		}
		void setLowerRight(int _x, int _y)
		{
			this->lowerRight(_x, _y);
		}
		void setColour(int _colour)
		{
			this->colour = _colour;
		}
		Rect(Rect & _rect)
		: upperLeft(_rect.upperLeft), lowerRight(_rect.lowerRight)
		{
			this->colour = _rect.colour;
		}
		void drawRect()
		{
			setcolor(this->colour);
			rectangle(upperLeft.getX(), upperLeft.getY(), lowerRight.getX(), lowerRight.getY());
		}
		~Rect()
		{

		}

};

class Picture
{
	private:
		Line *linePtr;
		Circle *circPtr;
		Rect *rectPtr;
}

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
