/*
File Name       : BITF19M529.cpp
Programmer Name : Muhammad Adnan Sardar
Date            : 2020-10-10
Description     : This is Set carrying Problem Involving Functions and Arrays.
*/

#include <iostream>
using namespace std;

class Set
{
private:
	int* set;
	int size;
public:
	Set(int siz = 0)
	{
		size = siz;
		set = new int[size];
		for (int i = 0; i < size; i++)
		{
			set[i] = 0;
		}
		for (int i = 0; i < size; i++)
		{
			cin >> set[i];
			while (set[i] < 0 && set[i]>100)
			{
				cout << "Invalid Input.Please Enter a Number between 0 and 100." << endl;
				cin >> set[i];
			}
			for (int j = 0; j < i; j++)
			{
				if (set[i] == set[j])
				{
					cout << "Invalid Input.Please Enter Again Non-Repeating Number between 0 and 100" << endl;
					cin >> set[i];
					j = -1;
				}
				if (set[i] < 0 || set[i]>100)
				{
					cout << "Invalid Input.Please Enter Again Non-Repeating Number between 0 and 100" << endl;
					cin >> set[i];
					j = -1;
				}
			}

		}
	}
	Set(const Set& s)
	{
		size = s.size;
		set = new int[s.size];
		for (int i = 0; i < s.size; i++)
		{
			set[i] = s.set[i];
		}
	}
	Set unionn(const Set& s)
	{
		{
			int test;
			int run;

			Set u;
			u.size = size + s.size;
			u.set = new int[u.size];
			for (int i = 0; i < u.size; i++)
			{
				u.set[i] = 0;
			}

			for (int i = 0; i < size; i++)
			{
				u.set[i] = set[i];

			}
			run = size;
			for (int i = 0; i < s.size; i++)
			{
				test = 1;
				for (int j = 0; j < size; j++)
				{
					if (s.set[i] == set[j])
					{
						test = 0;
						break;
					}
				}

				if (test)
				{
					u.set[run] = s.set[i];
					run++;
				}
			}

			Set Union;
			Union.size = run;
			Union.set = new int[run];
			for (int i = 0; i < Union.size; i++)
			{
				Union.set[i] = 0;
			}
			for (int i = 0; i <= run; i++)
			{
				Union.set[i] = u.set[i];
			}
			return Union;
		}

	}
	Set intersection(const Set& s)
	{


		Set inter;
		inter.size = size;
		inter.set = new int[size];
		for (int i = 0; i < inter.size; i++)
		{
			inter.set[i] = 0;
		}
		int run = 0;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < s.size; j++)
			{
				if (set[i] == s.set[j])
				{
					inter.set[run] = set[i];
					run++;
					break;
				}
			}
		}
		Set intersection;
		intersection.size = run;
		intersection.set = new int[intersection.size];

		for (int i = 0; i < run; i++)
		{
			intersection.set[i] = inter.set[i];
		}

		return intersection;
	}
	bool isEqualTo(const Set& s)
	{
		int temp;
		for (int i = 0; i < size; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (set[i] > set[j])
				{
					temp = set[i];
					set[i] = set[j];
					set[j] = temp;
				}
			}
		}
		for (int i = 0; i < s.size; i++)
		{
			for (int j = i + 1; j < s.size; j++)
			{
				if (s.set[i] > s.set[j])
				{
					temp = s.set[i];
					s.set[i] = s.set[j];
					s.set[j] = temp;
				}
			}
		}

		int yes = 0;
		if (size == s.size)
		{
			for (int i = 0; i < size; i++)
			{
				if (set[i] != s.set[i])
					yes++;
			}
		}
		else
		{
			return false;
		}
		if (yes != 0)
			return false;
		return true;
	}
	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << set[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	int size1;
	cout << "Enter Size of SET 1 :" << endl;
	cin >> size1;
	cout << "Enter Elements of Set 1 :" << endl;
	Set A(size1);
	cout << "Set 1 is:" << endl;
	A.print();

	int size2;
	cout << "Enter Size of SET 2 :" << endl;
	cin >> size2;
	cout << "Enter Elements of Set 2 :" << endl;
	Set B(size2);
	cout << "Set 2 is:" << endl;
	B.print();

	cout << "Union of Given Sets is :" << endl;
	Set UNION(A.unionn(B));
	UNION.print();

	cout << "INTERSECTION OF GIVEN SET IS" << endl;
	Set INTERSECTION(A.intersection(B));
	INTERSECTION.print();

	if (A.isEqualTo(B))
		cout << "Both Sets are Equal." << endl;
	else
		cout << "Both Sets are NOT Equal." << endl;

	return 0;
};
