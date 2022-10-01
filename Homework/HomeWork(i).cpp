/*
File Name       : BITF19M541.cpp
Name : Naveed Amjad
Date            : 2020-10-18
Description     : This is Program related to Functions and Arrays.
*/
#include <iostream>
#include <string>
using namespace std;

void Login(string** lab)
{
	int user_id, lab_no, computer_no ;
	cout << "Enter User ID : "<<endl;
	cin>> user_id;
	cout << "Enter Lab Number : "<<endl;
	cin >> lab_no;
	cout << "Enter Computer Number : "<<endl;
	cin >> computer_no;
	for (int i=0; i<4;i++)
	{
		for (int j=0;j<6 ;j++)
		{
			if (lab[i+1][j+1]=="empty")
			{
				lab[i+1][j+1]=user_id;
	        }
		}
		}
	
	
}
void LogOFF(string** lab)
{
    string user_id, lab_no, computer_no ;
	cout << "Enter User ID : "<<endl;
	cin>> user_id;
	cout << "Enter Lab Number : "<<endl;
	cin >> lab_no;
	cout << "Enter Computer Number : "<<endl;
	cin >> computer_no;
	for (int i=0; i<4;i++)
	{
		for (int j=0;j<5 ;j++)
		{
			if (lab[i+1][j+1]==user_id)
			{
				lab[i][j]="Empty";}
				else		
				cout <<"Invalid User ID or This User is NOT Logged in at any of Labs." <<endl;

		
			}
	   }
	 }


void Search(string** array)
{
	string user_id, lab_no, computer_no ;
	int search=0;
	cout << "Enter User ID : "<<endl;
	cin>> user_id;
	cout << "Enter Lab Number : "<<endl;
	cin >> lab_no;
	cout << "Enter Computer Number : "<<endl;
	cin >> computer_no;
	for (int i=0; i<4;i++)
	{
		for (int j=0;j<5 ;j++)
		{
			if (array[i][j]==user_id)
			{
				cout <<"User of ID :" <<user_id << " is Logged-in at Lab Number " <<i+1 <<" and Computer Number " << j+1 <<" ." <<endl;
				search++;
			}
		}
	}
	if(search==0)
	{
		cout <<"User of ID :" <<user_id << " is NOT Logged-in at any Lab" <<endl;
	}
}
void display (string** array)
{
	cout << "Lab Number\t\t\tComputer Stations" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << i + 1 << "\t\t\t";
		for (int j = 0; j < 6; j++)
		{
			if (i == 0 && j == 5)
				break;
			else if (i == 2 && (j == 4 || j == 5))
				break;
			else if (i == 3 && (j == 3 || j == 4 || j == 5))
				break;
			else
			{
				cout << j + 1 << " ";
				if (array[i][j] != "empty")
					cout << array[i][j] << " ";
				else
					cout << "empty ";
			}
		}
		cout << endl;
	}
}

int main()
{
	string** Labs = NULL;
	Labs = new string* [4];
	Labs[0] = new string[5];
	Labs[1] = new string[6];
	Labs[2] = new string[4];
	Labs[3] = new string[3];	
	
		for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (i == 0 && j == 5)
				break;
			else if (i == 2 && (j == 4 || j == 5))
				break;
			else if (i == 3 && (j == 3 || j == 4 || j == 5))
				break;
			else
			{
				Labs[i][j] = "empty";
			}
		}
	}
	int choice;
do
{
	cout <<"\t \t \t Main Menu"  << endl;
	cout << "1: Simulate Log-IN " << endl;
	cout << "2: Simulate Log-Off" << endl;
	cout << "3: Search " << endl;
	cout << "4: Display " << endl;
	cout << "5: Quit" << endl;
	cin >> choice;
	switch(choice)
	{
     	case 1 :
			Login(Labs);
			break;
		case 2 :
			LogOFF(Labs);
			break;
		case 3 :
			Search(Labs);
			break;
		case 4 :
			display(Labs);
			break;
	
 	}

}
    while(choice!=5);
    return 0;
}

	
	
