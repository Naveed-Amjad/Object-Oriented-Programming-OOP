/*
Naveed Amjad
BITF19M541
*/

#include<iostream>
using namespace std;



class Age
{
private:
	  int day;
	  int month;
	  int year;
public:
	Age(int day = 0, int month = 0, int year = 0)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	bool operator==(Age a)
	{
		if (this->day == a.day && this->month == a.month && this->year==a.year)
			return true;
		else	
		    return false;
	}
};


template <typename T>
bool isEqualTo(T x, T y)
{
	if (x == y)
		return true;
	else	
	    return false;
}

template <typename T>
int printArray(T*array, int count,int lowerArgument,int higherArgument)
{
	if (lowerArgument<0 || higherArgument>count-1||higherArgument<=lowerArgument)
		return 0;
	int z = (higherArgument - lowerArgument) + 1;
	cout << "Elements of array"<<endl;
	for (int i = lowerArgument; i <= higherArgument; i++)
	{
		cout << array[i] <<" ";
	}
	cout << endl;
	return z;
}

template <typename T>
void sort(T* array, int index)
{
	T dummy ;
	for (int i = 0; i < index; i++)            
	{
		for (int j = i + 1; j < index; j++)
		{
			if (array[i] > array[j])
			{
				dummy = array[i];
				array[i] = array[j];
				array[j] = dummy;
			}
		}
	}
	for (int i = 0; i < index; i++)        
	{
		cout << array[i] << " ";
	}
	cout << endl << endl;
}


int main()
{
	//Question No.1
	
	if (isEqualTo<int>(1, 1))
		cout << "integer type values are equal"<<endl;
	else
		cout << "\ninteger type values are not equal"<<endl;
	if (isEqualTo<double>(1.22, 1.2))
		cout << "\ndoubletype values are equal"<<endl;
	else
		cout << "\ndouble type values are not equal"<<endl;
	if (isEqualTo<char>('x', 'X'))
		cout << "\nchar type values are equal"<<endl;
	else
		cout << "\nchar type values are not equal"<<endl;
	
	
	Age date1(17,1,2021);
	Age date2(17,5,2021);
	if(isEqualTo<Age>(date1,date2))
		cout << "Dates are equal"<<endl;
	else
		cout << "Both of the Dates are not equal"<<endl;
		
	//what happens when you attempt to run this program?
	//It will give error without overloading assignment (==) operator 
	cout << endl << endl;
			
	//Question No.2
	int a[5] = { 1, 2, 3, 4, 5 };
	double b[7] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
	char c[6] = "Hello";

	int array1 = printArray<int>(a, 5, 2, 4);
	cout << "No. of elements of sub array 1 are: " << array1<<endl;
	int array2 = printArray<double>(b, 7, 1, 3);
	cout << "No.of elements of sub array 2 is: " << array2 << endl;
	int array3 = printArray<char>(c, 6, 1, 3);
	cout << "No.of elements of sub array 3 is: " << array3 << endl;
	cout << endl << endl;


	//Question No.3
	int arry1[10] = { 1,10,8,6,5,4,7,3,9,2 };
	double arry2[7] = { 2.2,3.3,5.5,7.7,6.6,1.1,4.4 };
	char arry3[6] = "abcde";
	sort<int>(arry1, 10);
	sort<double>(arry2, 7);
	sort<char>(arry3, 6);

}



