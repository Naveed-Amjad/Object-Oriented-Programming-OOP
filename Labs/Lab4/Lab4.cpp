/*
File Name       : BITF19M529.cpp
Programmer Name : Muhammad Adnan Sardar
Date            : 2020-10-17
Description     : This is a Complex Number Program using Operator Overloading.
*/
#include <iostream>
#include<math.h>
using namespace std;

class Complex
{
private:
	int realPart;
	int imaginaryPart;
public:
	Complex()
	{
		realPart = 0;
		imaginaryPart = 0;
	}
	Complex(int r, int i)
	{
		realPart = r;
		imaginaryPart = i;
	}

	Complex(const Complex& c)
	{
		realPart = c.realPart;
		imaginaryPart = c.imaginaryPart;

	}
	Complex operator+(const Complex& c)
	{
		Complex result(c);
		result.realPart = realPart + c.realPart;
		result.imaginaryPart = imaginaryPart + c.imaginaryPart;
		return result;

	}
	Complex operator-(const Complex& c)
	{
		Complex result(c);
		result.realPart = realPart - c.realPart;
		result.imaginaryPart = imaginaryPart - c.imaginaryPart;
		return result;
	}
	Complex operator*(const Complex& c)
	{
		Complex result(c);
		result.realPart = (realPart*c.realPart) - (imaginaryPart * c.imaginaryPart);
		result.imaginaryPart = (imaginaryPart*c.realPart) - (realPart*c.imaginaryPart);
		return result;
	}
	double Mod()
	{
		double mod,sum ,rel,imag;
		rel = (realPart * realPart);
		imag = (imaginaryPart * imaginaryPart);
		sum = rel + imag;
		mod = sqrt(sum);
		return mod;
		
	}
	void print()
	{
		cout <<"(" << realPart << " , " << imaginaryPart << "i )" << endl;
	}

};

int main()
{
	int r1, r2, c1, c2;
	cout << "Enter Real Part of 1st Complex Number:" << endl;
	cin >> r1;
	cout << "Enter Imaginary Part of 1st Complex Number:" << endl;
	cin >> c1;
	cout << "Enter Real Part of 2nd Complex Number:" << endl;
	cin >> r2;
	cout << "Enter Imaginart Part of 2nd Complex Number:" << endl;
	cin >> c2;
	Complex complex1(r1, c1);
	Complex complex2(r2, c2);
	Complex Addition , Subtraction , Multiplication;
	cout << "The 1st Complex Number is :" ;
	complex1.print();
	cout << "The 1st Complex Number is :";
	complex2.print();
	Addition = complex1 + complex2;
	cout << "The Addition is : ";
	Addition.print();
	Subtraction = complex1 - complex2;
	cout << "The Subtraction is : ";
	Subtraction.print();
	Multiplication = complex1 * complex2;
	cout << "The Multiplication is : ";
	Multiplication.print();
	cout << "The Mod of 1st Complex Number is : ";
	cout << complex1.Mod() << endl;
	cout << "The Mod of 2nd Complex Number is : ";
	cout << complex2.Mod();


	return 0;


}
