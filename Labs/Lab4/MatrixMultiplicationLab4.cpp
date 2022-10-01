/*
File Name       : BITF19M529.cpp
Programmer Name : Muhammad Adnan Sardar
Date            : 2020-10-17
Description     : This is Matrix Multiplication Program using Operator Overloading.
*/

#include<iostream>
using namespace std;

class matrix
{
private:
	int row;
	int col;
	int** ptr;
public:
	matrix()
	{
		row = 0;
		col = 0;
		ptr = new int* [row];
		for (int i = 0; i < row; i++)
		{
			ptr[i] = new int[col];
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				ptr[i][j] = 0;
			}
		}
	}
	matrix(int r, int c)
	{
		row = r;
		col = c;
		ptr = new int* [row];
		for (int i = 0; i < row; i++)
		{
			ptr[i] = new int[col];
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				ptr[i][j] = 0;
			}
		}
	}
	matrix(const matrix& m)
	{
		row = m.row;
		col = m.col;
		ptr = new int* [row];
		for (int i = 0; i < row; i++)
		{
			ptr[i] = new int[col];
		}

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				ptr[i][j] = m.ptr[i][j];
			}
		}
	}
	int fun(int i, int j, const matrix& b)
	{
		int c = 0;
		for (int k = 0; k < col; k++)
		{
			c = ((ptr[i][k] * b.ptr[k][j]) + c);
		}
		return c;
	}
	matrix operator*(const matrix& input)
	{
		if (col == input.row)
		{
			matrix output(row, input.col);

			for (int i = 0; i < output.row; i++)
			{
				for (int j = 0; j < output.col; j++)
				{
					for (int k = 0; k < col; k++)
					{
						output.ptr[i][j] = fun(i, j, input);
					}
				}
			}
			return output;
		}
		return matrix();
	}
	void input()
	{
		cout << "Enter Elements of the Matrix : " << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cin >> ptr[i][j];
			}
		}
	}
	void print()
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << ptr[i][j] << " ";
			}
			cout << endl;
		}
	}
	~matrix()
	{
		if (ptr != NULL)
		{
			for (int i = 0; i < row; i++)
			{
				delete[]ptr[i];

			}
		}
	}
};

int main()
{
	int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
	cout << "Enter Row Number and Coloumn Number of Matrix 1 : " << endl;
	cin >> r1 >> c1;
	matrix M1(r1, c1);
	M1.input();
	cout << "MATRIX 1 is : " << endl;
	M1.print();

	cout << "Enter Row Number and Coloumn Number of Matrix 2 : " << endl;
	cin >> r2 >> c2;
	matrix M2(r2, c2);
	M2.input();
	cout << "MATRIX 2 is : " << endl;
	M2.print();

	matrix M3 = M1 * M2;
	cout << endl << endl << "MULTIPLICATION OF THESE MATRICES IS" << endl;
	M3.print();
	return 0;
}
