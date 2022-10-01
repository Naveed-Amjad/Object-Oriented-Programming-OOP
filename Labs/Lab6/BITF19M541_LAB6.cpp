/*
FileName: Lab6.cpp
Written By: Naveed Amjad
Student ID: BITF19M541
Date: 7 November, 2020
Description:  to create a class called as Date having day, month and year
represented by integers and default values as 1,1 and 1900 respectively.
*/

#include <iostream>
using namespace std;

class Date
{
private:
	   int day;
	   int month;
	   int year;
	   static const int daysinmonth[13];
public:
	Date() :day(1), month(1), year(1900)
	{

	}
	
	Date(int d, int m, int y) :day(d), month(m), year(y)
	{

	}
	Date(const Date& d) :day(d.day), month(d.month), year(d.year)
	{

	}
	
	bool operator>=(Date& d)
	{
		if(year>d.year)
		{
			return true;
		}
		else if(year==d.year&&month>d.month)
		{
			return true;
		}
		else if(year==d.year&&month==d.month)
		{
			if(day>d.day)
			{
				return true;
			}
		}
		else if(month<d.month)
		{
			return false;
		}
		else if(year==d.year && month==d.month&&day==d.day)
		{
			return true;
		}
		else if(day<d.day)
		{
			return false;
		}
		else
			return false;
		
	}
	int operator-(Date& d)
	{
		int nod1,nod2,no_of_days;
		nod1 = year * 365 + day;
		for (int i = 1; i < month; i++)
			nod1 += d.daysinmonth[i];

		nod2 = d.year * 365 + d.day;
		for (int i = 1; i < d.month; i++)
			nod2 += d.daysinmonth[i];

		no_of_days = nod1 - nod2;
		return no_of_days;
		
	}
	Date operator+(int days)
	{
		Date d3;
		while(days>365)
		{
		year++;
		days-=365;
		}
		while(days>30)
		{
		if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
	    {
	      days-=31;
	      month++;
	    }
	    else if(month==2)
	    {
	      days-=28;
	      month++;
	    }
	    else
	    {
	      days-=30;
	      month++;
	    }
	    if(month>12)
	    {
	      year++;
	      month=1;
	    }
		}
		day=day+days;
		if(day>30)
		  {
		    if(month==4||month==6||month==9||month==11)
		    {
		      month++;
		      day-=30;
		    }
		    else if(month==2)
		    {
		      month++;
		      day-=28;
		    }
		    else if(day>31)
		    {
		      month++;
		      day-=31;
		    }
		    if(month>12)
		    {
		      year++;
		      month=1;
		    }
		  }
		  d3.day=day;
		  d3.month=month;
		  d3.year=year;
		  return d3;
		  
	}
	Date operator ++()
	{
		
			if (this->day != daysinmonth[this->month])
				++(this->day);
			else
				if (this->month < 12) 
				{
					++(this->month); 
					this->day = 1; 
				}
				else 
				{
					++(this->year);
					this->month = 1; 
					this->day = 1; 
				} 
		

     return *this;
		
	}
	Date operator --()
	{
		if (this->day != daysinmonth[this->month])
			--(this->day);
		else
		{
			if (this->month == 1)
			{
				this->month = 12;
				this->day = daysinmonth[this->month];
			}
			else
			{
				--(this->year);
				this->month = 12;
				this->day = daysinmonth[this->month];
			}
		}
		return *this;
		
	}
	Date operator++(int)
	{
		Date temp=*this;
			if (this->day != daysinmonth[this->month])
				++(this->day);
			else
				if (this->month < 12) 
				{
					++(this->month); 
					this->day = 1; 
				}
				else 
				{
					++(this->year);
					this->month = 1; 
					this->day = 1; 
				} 
		return temp;
	}
	Date operator--(int)
	{
		Date temp=*this;
		if (this->day != daysinmonth[this->month])
			--(this->day);
		else
		{
			if (this->month == 1)
			{
				this->month = 12;
				this->day = daysinmonth[this->month];
			}
			else
			{
				--(this->year);
				this->month = 12;
				this->day = daysinmonth[this->month];
			}
		}
		
		return temp;
	}
	
	
	friend istream& operator>>(istream&in, Date& d);
	friend ostream& operator<<(ostream& out,Date& d);
};
const int Date::daysinmonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

istream& operator>>(istream&in, Date& d)
{
	
	START:
	cout<<"Enter date in format dd/mm/yyyy: ";
	cin>>d.day;
	cin.get();
	cin>>d.month;
	cin.get();
	cin>>d.year;
	cin.get();
	while (d.year < 1900 || d.year > 2100)
	{
			cout<<"Invalid year, please enter again"<<endl;
			goto START;
	}
	
	while (d.month < 1 || d.month > 12)
	{
		cout<<"Invalid month,please enter again"<<endl;
		goto START;
		
	}
	
	while (d.day < 1 || d.day > d.daysinmonth[d.month])
	{
		cout<<"Invalid days,please enter again"<<endl;
		goto START;
	}
	
    return in;
}

ostream& operator<<(ostream& out,Date& d)
{

	cout << d.day << "/" << d.month << "/" << d.year << endl;
	return out;
}


int main ()
{
	int days;
	int no_of_days;
	Date d1;
	cin >> d1;
	
	cout<<"Date 1: ";
	cout<<d1;
	
	Date d2;
	cin >> d2;
	cout<<"Date 2: ";
	cout<<d2;
	  if(d1>=d2)
	  {
	    cout<<"No. of days between two days: "<<d1-d2<<endl;
	    no_of_days=d1-d2;
	  }
	else 
	{
	cout<<"Difference not possible,date 1 should not be less than date 2"<<endl;
	}
	cout<<"Enter no. of days you want to add in date 1: ";
	cin>>days;
	d2=d1+days;
	
	cout<<"New date is: "<<d2;
	cout<<"After pre-increment: ";
	++d1;
	
	cout<<d1;
	cout<<"After pre-decrement: ";
	--d1;
	
	cout<<d1;
	cout<<"After post-increment: ";
	d1++;
	
	cout<<d1;
	cout<<"After post-decrement : ";
	d1--;
	cout<<d1;


   return 0;
   	
}
