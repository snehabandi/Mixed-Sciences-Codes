//============================================================================
// Name        : exception_handling.cpp
// Author      : Sneha Bandi
// Roll no.    : 2401
// Description : try-catch implementation on age,income,city,vehicle criterions
//============================================================================

#include <iostream>
using namespace std;
#include<string.h>				//INCLUDED AS STRCMP USED IN COMPARING STRING
class check
{
	int ex;			//ch i.e different variable:as it handles errors related 
	int ch;			//to strings as additionally string.h is included
	int age,income;
	char city[15];
	char vehicle[6];
public:
	void accept();
	void display();

};

		//ACCEPT FUNCTION
void check::accept()
{
	cout<<"Enter your age : ";
	cin>>age;
	cout<<"Enter your income : ";
	cin>>income;
	cout<<"Enter your city:\n1. mumbai\t2. pune \t 3. bangalore \t4. chennai\n";
	cin>>city;
	cout<<"Enter vehicle (e.g. two,four)wheeler : ";
	cin>>vehicle;
}

		//DISPLAY FUNCTION
void check::display()
{
	cout<<"===============================================================================\n";

	//TRY N CATCH BLOCK OF AGE
	try
	{
		if(age<=55 && age>=18)
			cout<<"\nAge: "<<age<<" years";
		else
			throw ex;
	}
	catch(int ex)
	{
		cout<<"\nAge:";
		cout<<"\t*****Entered age is INVALID !!!*****\n";
	}

	//TRY N CATCH BLOCK OF INCOME
	try{
		if(income<=100000 && income>=50000)
			cout<<"\n\nIncome: "<<income;
		else
			throw ex;
	}
	catch(int ex)
	{
		cout<<"\nIncome:";
		cout<<"\t*****Entered income is INVALID !!!*****\n";
	}

	//TRY N CATCH BLOCK OF CITY
	try
	{
		if(strcmp(city,"pune")==0 || strcmp(city,"mumbai")==0
				|| strcmp(city,"bangalore")==0 || strcmp(city,"chennai")==0)
			cout<<"\n\nCity: "<<city;
		else
			throw ch;	//HERE ANOTHER VARIABLE 'ch' IS TAKEN AS WE ARE 
	}
	catch(int ch)
	{
		cout<<"\nCity:";
		cout<<"\t*****Entered city is INVALID !!!******\n";
	}

		//TRY N CATCH BLOCK OF VEHICLE
	try
	{
		if(strcmp(vehicle,"four")==0)
		cout<<"\n\nVehicle: "<<vehicle<<" wheeler\n";
		else
  		  throw ch;
	}
	catch(int ch)
	{
		cout<<"\nVehicle:";
		cout<<" *****Entered vehicle is INVALID !!!*****\n";
	}

		cout<<"===============================================================================\n";


}

//MAIN FUNCTION
int main() {
	char choice;
	cout<<"\n\tTHIS PROGRAM IS TO CHECK AGE,INCOME,CITY,VEHICLE CRITERIONS!\n\n";
	cout<<"===============================================================================\n";
	check c;
//do-while starts
	do{
	    c.accept();
	    c.display();
	    cout<<"\nDo you want to verify other records (y/n)?\n";
		cin>>choice;
	}while(choice=='y'||choice=='Y');
	cout<<"===============================================================================\n";
//do-while ends
return 0;
}
//PROGRAM ENDS
//<-------------------------------------- OUTPUT ----------------------------------------->
/*

	THIS PROGRAM IS TO CHECK AGE,INCOME,CITY,VEHICLE CRITERIONS!

===============================================================================
Enter your age : 19
Enter your income : 60000
Enter your city:
1. mumbai	2. pune 	 3. bangalore 	4. chennai
pune
Enter vehicle (e.g. two,four)wheeler : four
===============================================================================

Age: 19 years

Income: 60000

City: pune

Vehicle: four wheeler
===============================================================================

Do you want to verify other records (y/n)?
y
Enter your age : 67
Enter your income : 110000
Enter your city:
1. mumbai	2. pune 	 3. bangalore 	4. chennai
Indore
Enter vehicle (e.g. two,four)wheeler : two
===============================================================================

Age:	*****Entered age is INVALID !!!*****

Income:	*****Entered income is INVALID !!!*****

City:	*****Entered city is INVALID !!!******

Vehicle: *****Entered vehicle is INVALID !!!*****
===============================================================================

Do you want to verify other records (y/n)?
n
===============================================================================

*/














