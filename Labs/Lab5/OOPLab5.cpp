/*
FileName: OOPLab5.cpp
Written By: Naveed Amjad
Student ID: BITF19M541
Date: 31 october, 2020.
Description: Implementation of a class polynomial with specific specifications. 
*/

#include <iostream>
#include <cmath>
using namespace std;

class Polynomial
{
private:
	   int array[15];
	   int degree;
public:
	Polynomial()
	{
		degree = 0;
		for (int i = 0; i < 15; i++)
		{
			array[i] = 0;
		}
	}
	Polynomial operator+(Polynomial& x)
	{
		Polynomial resultant;
		int greaterDegree;
		if (degree >= x.degree)
			greaterDegree = degree;
		else
			greaterDegree = x.degree;
		resultant.degree = greaterDegree;
		for (int i = 0; i <= greaterDegree; i++)
		{
			resultant.array[i] = array[i] + x.array[i];
		}
		return resultant;
	}
	int evaluate(int n)
	{
		int result=0;
		for (int i = 0; i <= degree; i++)
		{
			result = result + (array[i] * pow(n , i));
		}
		return result;
	}
	int operator()(int n)
	{
		int result = 0;
		for (int i = 0; i <= degree; i++)
		{
			result = result + (array[i] * pow(n , i));
		}
		return result;
	}
	friend ostream& operator<<(ostream& out, Polynomial& x);
	friend istream& operator>>(istream& in, Polynomial& x);
};

ostream& operator<<(ostream& out, Polynomial& x)
{
	if (x.array[x.degree] != 0)
		out << x.array[x.degree] << "x^" << x.degree;
	for (int i = x.degree-1; i >=0 ; i--)
	{
		if (x.array[i] != 0)
		{
			if(x.array[i]>0)
				out << "+" << x.array[i] << "x^" << i;
			else if(x.array[i]<0)
				out << x.array[i] << "x^" << i;
		}
	}
	out << endl;
	return out;
}

istream& operator>>(istream& in, Polynomial& x)
{
	cout << "Enter degree" << endl;
	in >> x.degree;
	
	cout << "Enter co-eficients starting from higher power to lower" << endl;
	
	for (int i = x.degree; i >= 0; i--)
	{
		cout << "Enter co-eficient of x ^ " << i << endl;
		in >> x.array[i];
	}
	return in;
}

int main() // main function starts here
{
	int repeat = 0;
	Polynomial A;
	Polynomial B;
	
	do
	{
		cout << "Enter 1st Polynomial" << endl;
		cin >> A;
		cout << "Enter 2nd Polynomial" << endl;
		cin >> B;
		
		int choice = 0;
		do
		{
			cout <<"Enter 1 to sum both polynomials"<<endl;
			cout <<"Enter 2 to evaluate 1st Polynomial"<<endl;
			cout <<"Enter 3 to evaluate 2nd polynomial"<<endl;
			cout <<"Enter 4 to print both polynomials"<<endl;
			cout <<"Enter 0 to end" << endl;
			cin >> choice;
			
			switch(choice)
			{
				case 1:
				{
					Polynomial C = A + B;
					cout << "Addition is\n" << C << endl;
					break;
				}
				case 2:
				{
					int z;
					cout << "Enter no. to evaluate" << endl;
					cin >> z;
					cout << "\nEvaluating by evaluate function" << endl;
					cout << A.evaluate(z);
					cout << "\nEvaluating by overloaded ()" << endl;
					cout << A(z);
					break;
				}
				case 3:
				{
					int z;
					cout << "Enter no. to evaluate" << endl;
					cin >> z;
					cout << "Evaluating by evaluate function" << endl;
					cout << B.evaluate(z);
					cout << "Evaluating by overloaded ()" << endl;
					cout << B(z);
					break;
				}
				case 4:
				{
					cout << "1st Polynomial\n" << A << "\n 2nd Polynomial\n" << B << endl;
					break;
				}
			}
		} while (choice != 0);
		
		cout << "Please enter Other Polynomials Again if you want to repeat.\n\tEnter 0 to end "<<endl;
		cin >> repeat;
		
	} while (repeat != 0);
	
	
}





