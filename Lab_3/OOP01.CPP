#include <iostream.h>
#include <conio.h>

class Complex
{
	private:
		float real;
		float img;
		static int counter;
	public:
		Complex(float _real = 0, float _img = 0)
		{
			counter++;
			real = _real;
			img = _img;
			cout << "\nCounter = "
				 << counter
				 << endl;
		}
		Complex(Complex & c)
		{
			counter++;
			this->real = c.real;
			this->img = c.img;
			cout << "\nCounter = "
				 << counter
				 << endl;
		}
		float getReal()
		{
			return (this->real);
		}
		float getImg()
		{
			return ((*this).img);
		}
		void setValue(float _real)
		{
			this->real = _real;
		}
		void setValue(float _real, float _img)
		{
			this->real = _real;
			this->img = _img;
		}
		void addComplexValue(Complex c1)
		{
			(this->real) += c1.real;
			(this->img) += c1.img;
		}
		void subComplexValue(Complex c1)
		{
			(this->real) -= c1.real;
			(this->img) -= c1.img;
		}
		int getCounter()
		{
			return counter;
		}
		friend void viewContent(Complex & c);
		~Complex()
		{
			counter--;
			cout << "\nCounter = "
				 << counter
				 << endl;
		}
};


Complex addComplex(Complex & x, Complex & y)
{
	static Complex c3(x.getReal() + y.getReal(), x.getImg() + y.getImg());

	return c3;
}

Complex subComplex(Complex & x, Complex & y)
{
	static Complex c3(x.getReal() - y.getReal(), x.getImg() - y.getImg());

	return c3;
}

void viewContent(Complex & c)
{
	if (c.img == 1)
	{
		cout << "\nNumber = "
			 << c.real
			 << " "
			 << '+'
			 << " "
			 << "j\n";
	}
	else if (c.img == -1)
	{
		cout << "\nNumber = "
			 << c.real
			 << " "
			 << '-'
			 << " "
			 << "j\n";
	}
	else if (c.img == 0)
	{
		cout << "\nNumber = "
			 << c.real
			 << "\n";
	}
	else if (c.img < 0)
	{
		cout << "\nNumber = "
			 << c.real
			 << " "
			 << '-'
			 << " "
			 << -1 * c.img
			 << "j\n";
	}
	else if (c.img > 0)
	{
		cout << "\nNumber = "
			 << c.real
			 << " "
			 << '+'
			 << " "
			 << c.img
			 << "j\n";
	}
}

int Complex::counter = 0;

void main()
{
	clrscr();

	Complex c1(3.7, -4), c2(6, 8.5);

	viewContent(c1); // THESE DO NOT GET PRINTED!
	viewContent(c2); // THESE DO NOT GET PRINTED!

	Complex c3(c2);

	c3.addComplexValue(c1);

	viewContent(c3);

	Complex c4(c1);
	c4.subComplexValue(c2);
	viewContent(c4);

	//viewContent(c1);
	//viewContent(c2);

	return;

}

