#include <iostream.h>
#include <conio.h>
#include <math.h>

typedef enum
{
  true = 1,
  false = 0
};

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
		/***********************************/
		// haha, Operator Overloading go brrr!

		// c + c
		Complex operator + (Complex & c)
		{
			Complex c1((this->real + c.img), (this->img + c.img));
			return c1;
		}

		// c + f
		Complex operator + (float f)
		{
			Complex c1((this->real + f), (this->img));
			return c1;
		}

		// c - c
		Complex operator - (Complex & c)
		{
			Complex c1((this->real - c.real), (this->img - c.img));
			return c1;
		}

		// c - f
		Complex operator - (float f)
		{
			Complex c1((this->real - f), (this->img));
			return c1;
		}

		// c * c
		Complex operator * (Complex & c)
		{
			// (x + yi)*(a + bi) = (x*a - y*b) + (x*b + a*y)i
			Complex c1( (this->real * c.real) - (this->img * c.img),
						(this->real * c.img) + (this->img * c.real) );
			return c1;
		}

		// c * f
		Complex operator * (float f)
		{
			// (x + yi) * f = f*x + f*yi
			Complex c1((this->real * f), (this->img * f));
			return c1;
		}

		// c < c && c > c
		int operator < (Complex & c)
		{
			return ((this->real < c.real) && (this->img < c.img));
		}
		int operator > (Complex & c)
		{
			return ((this->real > c.real) && (this->img > c.img));
		}

		// c = c
		Complex & operator = (Complex & c)
		{
			this->real = c.real;
			this->img = c.img;
			return (*this);
		}

		// c++ && ++c
		Complex & operator ++ () // prefix
		{
			(this->real)++;
			(this->img)++;
			return (*this);
		}
		Complex operator ++ (int dumdum) // postfix
		{
			Complex temp(*this);
			(this->real)++;
			(this->img)++;
			return temp;
		}

		// c-- && --c
		Complex & operator -- () // prefix
		{
			(this->real)--;
			(this->img)--;
			return (*this);
		}
		Complex operator -- (int dumdum) // postfix
		{
			Complex temp(*this);
			(this->real)--;
			(this->img)--;
			return temp;
		}

		// c == c
		int operator == (Complex & c)
		{
			return ((this->real == c.real) && (this->img == c.img));
		}

		// c += c
		Complex & operator += (Complex & c)
		{
			this->real += c.real;
			this->img += c.img;
			return (*this);
		}

		// c -= c
		Complex & operator -= (Complex & c)
		{
			this->real -= c.real;
			this->img -= c.img;
			return (*this);
		}

		// (float)c
		operator float ()
		{
			return (float)sqrt((this->real * this->real) + (this->img * this->img));
		}

		// << && >> with i/o stream
		friend istream & operator >> (istream & in, Complex & c);
		friend ostream & operator << (ostream & out, Complex & c);
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

istream & operator >> (istream & in, Complex & c)
{
	cout << "Enter Real Part: ";
	in >> c.real;
	cout << "Enter Imaginary Part: ";
	in >> c.img;
	return in;
}

ostream & operator << (ostream & out, Complex & c)
{
	if ((int)c.img == 1)
	{
		out << "\nNumber = "
			<< c.real
			<< " "
			<< '+'
			<< " "
			<< "j\n";
	}
	else if ((int)c.img == -1)
	{
		out << "\nNumber = "
			<< c.real
			<< " "
			<< '-'
			<< " "
			<< "j\n";
	}
	else if ((int)c.img == 0)
	{
		out << "\nNumber = "
			<< c.real
			<< "\n";
	}
	else if ((int)c.img < 0)
	{
		out << "\nNumber = "
			<< c.real
			<< " "
			<< '-'
			<< " "
			<< -1 * c.img
			<< "j\n";
	}
	else if ((int)c.img > 0)
	{
		out << "\nNumber = "
			<< c.real
			<< " "
			<< '+'
			<< " "
			<< c.img
			<< "j\n";
	}

	return out;
}

int Complex::counter = 0;

void main()
{
	//clrscr();
	cout << "\n\n\n\n\n";

	Complex c1(3.7, -4), c2(6, 8.5);

	viewContent(c1);
	viewContent(c2);

	c1 = c2;

	cout << "\nAfter = Operation: \n";
	viewContent(c1);

	c1 += c2;
	cout << "\nAfter += Operation: \n";
	viewContent(c1);

	c1 -= c2;
	cout << "\nAfter -= Operation: \n";
	viewContent(c1);

	c1++;
	cout << "\nAfter ++ Operation: \n";
	viewContent(c1);

	c1--;
	cout << "\nAfter -- Operation: \n";
	viewContent(c1);

	c1 = c1 * c2;
	cout << "\nAfter * Operation: \n";
	viewContent(c1);

	cout << "\nTesting <, >, == : \n";
	cout << (c1 == c2) << endl;// 0
	cout << (c1 > c2) << endl; // 0
	cout << (c1 < c2) << endl; // 0

	float c1_mag = (float)c1;
	cout << "\nTesting Casting to Float: \n";
	cout << c1_mag << endl;

	cout << "\nTesting printing using << :\n";
	cout << c1 << endl;


	return;

}

