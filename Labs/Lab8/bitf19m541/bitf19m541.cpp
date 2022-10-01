/*
Written By: Naveed Amjad
Roll No: BITF19M541
*/
#include<iostream>
#include <string>
#include <iomanip>
using namespace std;
class package
{
protected:
	string sname;
	string saddress;
	string scity;
	string sstate;
	int szip;
	string rname;
	string raddress;
	string rcity;
	string rstate;
	int rzip;
	double weight;
	double cost;
public:
	package()
	{
		sname = "";
		saddress = "";
		scity = "";
		sstate = "";
		szip = 0;
		rname = "";
		raddress = "";
		rcity = "";
		rstate = "";
		rzip = 0;
		weight = 0.0;
		cost = 0.0;
	}
	package(string sn, string sadd, string sci, string ss, int sz, string rn, string radd, string rci, string rs, int rz, double w, double co)
	{
		sname = sn;
		saddress = sadd;
		scity = sci;
		sstate = ss;
		szip = sz;
		rname = rn;
		raddress = radd;
		rcity = rci;
		rstate = rs;
		rzip = rz;
		if(w>0)
		{
			weight = w;
		}
		else
		{
			cout << "YOU ENTERED AN INVALID NUMBER . WEIGHT HAS BEEN SET TO A DEFAULT VALUE \n";
			weight = 0;
		}
		
		if (co > 0)
		{
			cost = co;
		}
		else
		{
			cout << "YOU ENTERED AN INVALID NUMBER . COST HAS BEEN SET TO A DEFAULT VALUE \n";
			cost = 0;
		}
	}
	double calculateCost()
	{
		return  weight * cost;
	}

};
class TwoDayPackage: public package
{
	double twodayfee;
public:
	TwoDayPackage()
	{
		twodayfee = 0.0;
	}
	TwoDayPackage(string sn, string sadd, string sci, string ss, int sz, string rn, string radd, string rci, string rs, int rz, double w, double co, double f) :package(sn, sadd, sci, ss, sz, rn, radd, rci, rs, rz, w, co)
	{
		if(f>0)
		{
			twodayfee = f;
		}
		else
		{
			cout << "YOU ENTERED AN INVALID NUMBER . FLAT FEE HAS BEEN SET TO A DEFAULT VALUE \n";
			twodayfee = 0;
		}
		
	}
	double calculateCost()
	{
		return package::calculateCost() + twodayfee;
	}
};
class OvernightPackage:public package
{
	double overnightfee;
public:
	OvernightPackage()
	{
		overnightfee = 0.0;
	}
	OvernightPackage(string sn, string sadd, string sci, string ss, int sz, string rn, string radd, string rci, string rs, int rz, double w, double co,double f):package(sn,sadd,sci,ss,sz,rn,radd,rci,rs,rz,w,co)
	{
		if (f > 0)
		{
			overnightfee = f;
		}
		else
		{
			cout << "YOU ENTERED AN INVALID NUMBER . OVERNIGHT FEE HAS BEEN SET TO A DEFAULT VALUE \n";
			overnightfee = 0;
		}
	}
	double calculateCost()
	{
		return (overnightfee+cost)*weight;
	}
};
int main()
{
	package p1("Lou Brown", "1 Main St", "Boston", "MA", 11111,
		"Mary Smith", "7 Elm St", "New York", "NY", 22222, 8.5, .5);
	cout << "TOTAL COST FOR PACKAGE 1 :" << p1.calculateCost() << endl;
	TwoDayPackage p2("Lisa Klein", "5 Broadway", "Somerville",
		"MA", 33333, "Bob George", "21 Pine Rd", "Cambridge", "MA", 44444,
		10.5, .65, 2.0);
	cout << "TOTAL COST FOR PACKAGE 2 :" << p2.calculateCost() << endl;
	OvernightPackage p3("Ed Lewis", "2 Oak St", "Boston", "MA",
		55555, "Don Kelly", "9 Main", "Denver", "CO", 66666, 12.25, .7, .25);
	cout << "TOTAL COST FOR PACKAGE 3 :" << p3.calculateCost() << endl;
}