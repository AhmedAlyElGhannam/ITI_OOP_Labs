#include <iostream.h>

class Complex
{
	private:
		float real;
		float img;
	public:
		Complex(float _real = 0, float _img = 0)
		{
			real = _real;
			img = _img;
		}
		float getReal()
		{
			return (this->real);
		}
		float getImg()
		{
			return ((*this).img);
		}
		void setValue(float _real, float _img)
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

	c1.setValue(3.7, -4);
	c2.setValue(6, 8.5);

	c1.print();
	c2.print();

	Complex c3 = addComplex(c1, c2);

	c3.print();

	Complex c4 = subComplex(c1, c2);
	c4.print();

	return;

}
