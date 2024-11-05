#include <iostream.h>

class Complex
{
	private:
		int real;
		int img;
	public:
		Complex(int _real = 0, int _img = 0)
		{
			real = _real;
			img = _img;
		}
		int getReal()
		{
			return (this->real);
		}
		int getImg()
		{
			return ((*this).img);
		}
		void setValue(int _real, int _img)
		{
			this->real = _real;
			this->img = _img;
		}
		void print()
		{
			if (this->img < 0)
			{
				cout << "Number = "
					 << this->real
					 << " "
					 << '-'
					 << " "
					 << -1 * this->img
					 << "j\n";
			}
			else
			{
				cout << "Number = "
					 << this->real
					 << " "
					 << '+'
					 << " "
					 << this->img
                     			 << "j\n";
			}
		}
		~Complex()
		{

		}
};


Complex addComplex(Complex & x, Complex & y)
{
	Complex c3(x.getReal() + y.getReal(), x.getImg() + y.getImg());

	return c3;
}

Complex subComplex(Complex & x, Complex & y)
{
	Complex c3(x.getReal() - y.getReal(), x.getImg() - y.getImg());

	return c3;
}

void main()
{
	cout << "\n\n\n";

	Complex c1, c2;

	c1.setValue(3, -4);
	c2.setValue(6, 8);

	c1.print();
	c2.print();

	Complex c3 = addComplex(c1, c2);

	c3.print();

	Complex c4 = subComplex(c1, c2);
    	c4.print();

	return;

}
