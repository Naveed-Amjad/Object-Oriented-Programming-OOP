/*
File Name       : BITF19M529.cpp
Programmer Name : Muhammad Adnan Sardar
Date            : 2020-10-07
Description     : This is Matrices Related Menu Program.
*/

#include <iostream>
using namespace std;

class Matrix
{
private:
	int row;
	int col;
	int** ptr;
public:
	Matrix()
	{
		row = 0;
		col = 0;
		ptr = new int* [row];
		for (int i = 0; i < row; i++)
			ptr[i] = new int[col];
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				ptr[i][j] = 0;
			}
		}
	}
	Matrix(int r, int c)
	{
		row = r;
		col = c;
		ptr = new int* [r];
		for (int i = 0; i < r; i++)
			ptr[i] = new int[c];
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				ptr[i][j] = 0;
			}
		}

	}
	Matrix(const Matrix& obj)
	{
		row = obj.row;
		col = obj.col;
		ptr = new int* [row];
		for (int i = 0; i < row; i++)
			ptr[i] = new int[col];
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				ptr[i][j] = obj.ptr[i][j];
			}
		}
	}
	void inputMatrix()
	{
		cout << "Enter Elements of Matrix: " << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cin >> ptr[i][j];
			}
		}
	}
	void outputMatrix()
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
	int get(int i, int j)
	{
		return  ptr[i][j];
	}
	void set(int i, int j, int val)
	{
		ptr[i][j] = val;
		cout << "Values have been changed Successfully." << endl;
	}
	bool IsSquare()
	{
		if (row == col)
			return true;
		else
			return false;
	}
	bool IsIdentity()
	{
		int identity = 0;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if ((ptr[i][j] != 1) && (ptr[j][i] != 0))
				{
					identity = 1;
					break;
				}

			}
		}
		if (identity == 0)
			return true;
		else
			return false;
	}
	bool IsDiagonal()
	{
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				if (i == j)
				{
					if (ptr[i][j] == 0)
						return false;
				}
				else
				{
					if (ptr[i][j] != 0)
						return false;
				}
		return true;
	}
	bool IsNull()
	{
		int total = 0;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (ptr[i][j] == 0)
					total++;
			}
		}
		if (total == (row * col))
			return true;
		else
			return false;
	}
	bool IsUpper()
	{

		for (int i = 1; i < row; i++)
			for (int j = 0; j < i; j++)
				if (ptr[i][j] == 0)
					return true;

		return false;
	}

	bool IsLower()
	{
		for (int i = 0; i < col; i++)
			for (int j = i + 1; j < col; j++)
				if (ptr[i][j] != 0)
					return false;
		return true;
	}
	bool IsEqual(Matrix m)
	{
		int equal = 0;
		if (row == m.row && col == m.col)
		{
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					if (ptr[i][j] != m.ptr[i][j])
						equal++;
				}
			}
			if (equal == 0)
				return true;
			else
				return false;
		}
		else
			cout << "Both Matrices do not have same order." << endl;
		return false;
	}
	Matrix Transpose()
	{

		int r, c;
		r = col;
		c = row;
		Matrix trans(r,c);
		
		for (int i = 0; i < row; i++) 
		{
			for (int j = 0; j < col; j++) 
			{
				trans.ptr[j][i] = ptr[i][j];
			}
		}
		return trans;
	}
	Matrix add(const Matrix& m)
	{
		Matrix ADD(m);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				ADD.ptr[i][j] = ptr[i][j] + m.ptr[i][j];
			}
		}
		 return ADD;
	}
	Matrix sub(Matrix& m)
	{
		Matrix SUB(m);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				SUB.ptr[i][j] = ptr[i][j] - m.ptr[i][j];
			}
		}
		 return SUB;
	}
	Matrix mul(Matrix& m)
	{
		Matrix MUL(row,m.col);
        for(int i=0; i<row; ++i)
      for(int j=0; j<m.col; ++j) {
         MUL.ptr[i][j] = 0;
      }
      for(int i=0; i<row; ++i)
      for(int j=0; j<m.col; ++j)
      for(int k=0; k<col; ++k) 
	  {
         MUL.ptr[i][j]+=ptr[i][k]*m.ptr[k][j];
      }
	 return 	MUL;
	}
	~Matrix()
	{
		for (int i = 0; i < row; i++)
			delete[] ptr[i];
		delete[]ptr;
	}

};

int main()
{
	int check = 0, r1, c1, r2, c2;


	cout << "Enter No. of Rows and Columns of 1st Matrix: " << endl;
	cin >> r1 >> c1;

	Matrix m1(r1, c1);

	m1.inputMatrix();
	cout << "Enter No. of Rows and Columns of 2nd Matrix: " << endl;
	cin >> r2 >> c2;
	Matrix m2(r2, c2);

	m2.inputMatrix();

	do
	{
		cout << endl<< "\t \t \t User Menu \nPress:  \n 1 FOR INPUT IN MATRIX 1. \n 2 FOR INPUT IN MATRIX 2. \n 3 TO GET AN ELEMENT OF MATRIX 1 or 2. \n 4 TO UPDATE AN ELEMENT OF MATRIX 1 or 2. \n 5 TO CHECK IF MATRICES ARE SQUARE. \n 6 TO CHECK IF MATRICES ARE IDENTITY. \n 7 TO CHECK IF MATRICES ARE DIAGONAL. \n 8 TO CHECK IF MATRICES ARE NULL. \n 9 TO CHECK IF MATRICES ARE UPPER TRIANGLE. \n 10 TO CHECK IF MATRICES ARE LOWER TRIANGLE. \n 11 TO CHECK IF MATRICES ARE EQUAL. \n 12 TO FIND TRANSPOSE OF MATRICES. \n 13 TO ADD MATRICES. \n 14 TO SUBTRACT MATRICES. \n 15 TO MULTIPLY MATRICES. \n 16 TO QUIT MENU." << endl;
		cin >> check;
		switch (check)
		{
		case 1:
		{
			cout << "You Pressed 1." << endl;
			m1.inputMatrix();
			break;
		}
		case 2:
		{
			cout << "You Pressed 2." << endl;
			m2.inputMatrix();

			break;
		}
		case 3:
		{
			cout << "You Pressed 3." << endl;
			int matrix, r, c;
			cout << "Enter 1 to Access Matrix 1 and Enter 2 to Access Matrix 2" << endl;
			cin >> matrix;
			if (matrix == 1)
			{
				cout << "Enter row number : ";
				cin >> r;
				cout << "Enter column number : ";
				cin >> c;
				if (r <= r1 && c <= c1)
				{
					int index1 = m1.get(r - 1, c - 1);
					cout << "The value at index " << r << " , " << c << " is " << index1 << endl;
				}
				else
					cout << "NOT VALID INDEX." << endl;
			}
			if (matrix == 2)
			{
				cout << "Enter row number : ";
				cin >> r;
				cout << "Enter column number : ";
				cin >> c;
				if (r <= r2 && c <= c2)
				{
					int index2 = m2.get(r - 1, c - 1);
					cout << "The value at index " << r << " , " << c << " is " << index2 << endl;
				}
				else
					cout << "NOT VALID INDEX." << endl;
			}
			break;
		}

		case 4:
		{
			cout << "You Pressed 4." << endl;
			int matrix, r, c, val = 0;
			cout << "Enter 1 to access Matrix 1 and Enter 2 to access Matrix 2" << endl;
			cin >> matrix;
			if (matrix == 1)
			{
				cout << "Enter row number : ";
				cin >> r;
				cout << "Enter column number : ";
				cin >> c;
				cout << "Enter the value you want to set : ";
				cin >> val;
				m1.set(r - 1, c - 1, val);
			}
			if (matrix == 2)
			{
				cout << "Enter row number : ";
				cin >> r;
				cout << "Enter column number : ";
				cin >> c;

				cout << "Enter the value you want to set : ";
				cin >> val;
				m2.set(r - 1, c - 1, val);
			}

			break;
		}
		case 5:
		{

			cout << "You Pressed 5." << endl;
			if (m1.IsSquare())
				cout << "Matrix 1 is square Matrix." << endl;
			else
				cout << "Matrix 1 is not square Matrix." << endl;
			if (m2.IsSquare())
				cout << "Matrix 2 is square Matrix." << endl;
			else
				cout << "Matrix 2 is not square Matrix." << endl;
			break;
		}
		case 6:
		{
			cout << "You Pressed 6." << endl;
			if (m1.IsSquare())
			{
				if (m1.IsIdentity())
					cout << "Matrix 1 is Identity." << endl;
				else
					cout << "Matrix 2 is not Identity." << endl;
			}
			else
				cout << "Matrix 1 is not a square hence not Identity." << endl;
			if (m2.IsSquare())
			{
				if (m2.IsIdentity())
					cout << "Matrix 2 is identity." << endl;
				else
					cout << "Matrix 2 is not identity." << endl;
			}
			else
				cout << "Matrix 1 is not a square hence not Identity." << endl;


			break;
		}
		case 7:
		{
			cout << "You Pressed 7." << endl;
			if (m1.IsSquare())
			{
				if (m1.IsDiagonal())
					cout << "Matrix 1 is a diagonal matrix." << endl;
				else
				{
					cout << "Matrix 1 is not a diagonal matrix." << endl;

				}
			}
			else
			{
				cout << "Matrix 1 is not a square matrix hence not Diagonal" << endl;
			}
			if (m2.IsSquare())
			{
				if (m2.IsDiagonal())
					cout << "Matrix 2 is a diagonal matrix." << endl;
				else
				{
					cout << "Matrix 2 is not a diagonal matrix. " << endl;

				}
			}
			else
				cout << "Matrix 2 is not a square matrix hence not Diagonal" << endl;
			break;
		}
		case 8:
		{
			cout << "You Pressed 8." << endl;
			if (m1.IsNull())
				cout << "Matrix 1 is NULL" << endl;
			else
				cout << " Matrix 1 is not NULL" << endl;

			if (m2.IsNull())
				cout << "Matrix 2 is NULL" << endl;
			else
				cout << " Matrix 2 is not NULL" << endl;


			break;
		}
		case 9:
		{
			cout << "You Pressed 9." << endl;
			if (m1.IsUpper())
				cout << "Matrix 1 is upper triangular" << endl;
			else
				cout << "Matrix 1 is not upper triangular" << endl;

			if (m2.IsUpper())
				cout << "Matrix 2 is upper triangular" << endl;
			else
				cout << "Matrix 2 is not upper triangular" << endl;

			break;
		}
		case 10:
		{
			cout << "You Pressed 10." << endl;
			if (m1.IsLower())
				cout << "Matrix 1 is Lower Triangular" << endl;
			else
				cout << "Matrix 1 is not a Lower Triangular Matrix" << endl;

			if (m2.IsLower())
				cout << "Matrix 2 is Lower Triangular" << endl;
			else
				cout << "Matrix 2 is not a Lower Triangular Matrix" << endl;

			break;
		}
		case 11:
		{
			cout << "You Pressed 11." << endl;
			if (m1.IsEqual(m2))
				cout << "Matrices 1 and 2 are Equal" << endl;
			else
				cout << " Matrices 1 and 2 are not Equal" << endl;
			break;
		}
		case 12:
		{
			cout << "You Pressed 12." << endl;
			cout << "TRANSPOSE OF MATRIX 1 IS" << endl;
				Matrix tran1 = m1.Transpose();
				tran1.outputMatrix();
				cout << "TRANSPOSE OF MATRIX 2 IS" << endl;
				Matrix tran2 = m2.Transpose();
                tran2.outputMatrix();
		   break;
		}
		case 13:
		{
			cout << "You Pressed 13." << endl;
			if (r1 == r2 && c1 == c2)
			{
				cout << "ADDITION OF MATRIX 1 AND 2 IS" << endl;
	            Matrix add1 = m1.add(m2);
                add1.outputMatrix();
			}
			else
				cout << "Addition of two matrices with diffrent order is not possible.";

			break;
		}
		case 14:
		{
			cout << "You Pressed 14." << endl;
         if (r1==r2 && c1==c2)
				{
                int choose;
                cout<<"Enter 1 If you want to subtract 2 from 1 and Enter 2 If vice versa : " ;
                cin>>choose;
                if(choose==1)
                {
				
					cout << "SUBTRACTION OF MATRIX 2 from 1 IS :" << endl;
				    Matrix sub1 =m1.sub(m2);
                    sub1.outputMatrix();
                }
                    else if(choose==2)
                    {
                      cout << "SUBTRACTION OF MATRIX 1 from 2 IS :" << endl;
					  Matrix sub2 = m2.sub(m1); 
                      sub2.outputMatrix();
                     }
            }
			else
				cout << "Subtraction of two matrices with diffrent order is not possible.";

			break;
		}
		case 15:
		{
			cout << "You Pressed 15." << endl;
				if (c1 == r2)
				{
                 int choose;
                cout<<"Enter 1 If you want to multiply 1 to 2 and Enter 2 If vice versa :";
                cin>>choose;
                if(choose==1)
                { 
					cout << "MULTIPLICATION OF MATRIX 1 AND 2 IS :" << endl;
					Matrix mul1 = m1.mul(m2);
                        mul1.outputMatrix();
				}
                   else if(choose==2)
                { 
					cout << "MULTIPLICATION OF MATRIX 2 AND 1 IS " << endl;
					Matrix mul2 = m2.mul(m1);
                        mul2.outputMatrix();
                }
				}
			else
				cout << "MULTIPLICATION NOT POSSIBLE" << endl;

			break;
		}
		case 16:
		{
			cout << "You Pressed 16." << endl;
			break;
		}

}
}
	while (check != 16);
	return 0;
}




