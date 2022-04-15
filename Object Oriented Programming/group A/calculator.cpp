//============================================================================
// Name        : calculator.cpp
// Author      : Sneha Bandi
// Roll No.    : 2401
// Description : Calculator program in c++ using operator overloading
// 			 and basic concepts of oops
//============================================================================
///
#include <iostream>
using namespace std;
class calculator
{
	//private:
		float val;
	public:
		calculator()	//constructor to initialize to zero
		{
			val=0;
		}

		void getdata()		//Accept data function
		{
			cout<<"Enter the number: ";
			cin>>val;
		}

		void showdata()		//Display data function
		{
			cout<<val<<endl;
		}

	//Operator Overloading
		calculator operator + (calculator)const;	//operator overloading
		calculator operator - (calculator)const;	//calculator return type and passed means that obj is passed and returned 
		calculator operator * (calculator)const;
		calculator operator / (calculator)const;
};

//Function definition for addition
calculator calculator :: operator + (calculator argnt)const
{
	calculator temp;
	temp.val = val +argnt.val;
	return temp;
}

//Function definition for subtraction
calculator calculator :: operator - (calculator argnt)const
{
	calculator temp;
	temp.val = val - argnt.val;
	return temp;
}

//Function definition for multiplication
calculator calculator :: operator * (calculator argnt)const
{
	calculator temp;
	temp.val = val * argnt.val;
	return temp;
}

//Function definition for divide
calculator calculator :: operator / (calculator argnt)const
{
	calculator temp;
	temp.val = val / argnt.val;
	return temp;
}

int main()
{
	calculator obj1,obj2,obj3;
	int choice;
	char ch,n;
	cout<<"\n\t\t\tTHIS IS A CALCULATOR PROGRAM !!\n";
	do{
//ACCEPTING NUMBERS
		obj1.getdata();
		obj2.getdata();
//DISPLAYING NUMBERS
		cout<<"_______________________________\n";
		cout<<"\n\tFirst value :";
		obj1.showdata();
		cout<<"\n\tSecond value :";
		obj2.showdata();
		cout<<"\n_______________________________\n";
		cout<<"Input choice as integer"<<endl<<"\tPress:"<<endl<<"\t1. to Add"<<endl;
		cout<<"\t2. to Subtract "<<endl<<"\t3. to Multiply"<<endl<<"\t4. to Divide"<<endl;
		cin>>choice;
		cout<<endl;

		//Switch case
		switch(choice)
		{
		case 1:
			obj3 = obj1 + obj2;
				break;
		case 2:
			obj3 = obj1 - obj2;
					break;
		case 3:
			obj3 = obj1 * obj2;
					break;
		case 4:
			obj3 = obj1 / obj2;
					break;

		default:
			cout<<"\nEnter valid choice !!\n"<<endl;
		}

		//Result
		cout<<"The result is:";
		obj3.showdata();
		cout<<"\n========================================";
		cout<<"\nDo you want to continue (y/n)?\t";
		cin>>ch;
		cout<<"========================================\n";

	}while(ch=='y' || ch=='Y');

	return 0;
}
//PROGRAM ENDS
//<-------------------------------------- OUTPUT ----------------------------------------->
/*
			THIS IS A CALCULATOR PROGRAM !!
Enter the number: 15
Enter the number: 7
_______________________________

	First value :15

	Second value :7

_______________________________
Input choice as integer
	Press:
	1. to Add
	2. to Subtract 
	3. to Multiply
	4. to Divide
1

The result is:22

========================================
Do you want to continue (y/n)?	y
========================================
Enter the number: 10
Enter the number: 3
_______________________________

	First value :10

	Second value :3

_______________________________
Input choice as integer
	Press:
	1. to Add
	2. to Subtract 
	3. to Multiply
	4. to Divide
2

The result is:7

========================================
Do you want to continue (y/n)?	y
========================================
Enter the number: 14
Enter the number: 2
_______________________________

	First value :14

	Second value :2

_______________________________
Input choice as integer
	Press:
	1. to Add
	2. to Subtract 
	3. to Multiply
	4. to Divide
3

The result is:28

========================================
Do you want to continue (y/n)?	y
========================================
Enter the number: 56
Enter the number: 8
_______________________________

	First value :56

	Second value :8

_______________________________
Input choice as integer
	Press:
	1. to Add
	2. to Subtract 
	3. to Multiply
	4. to Divide
4

The result is:7

========================================
Do you want to continue (y/n)?	y
========================================
Enter the number: 56
Enter the number: 13
_______________________________

	First value :56

	Second value :13

_______________________________
Input choice as integer
	Press:
	1. to Add
	2. to Subtract 
	3. to Multiply
	4. to Divide
5

Enter valid choice !!
========================================
Do you want to continue (y/n)?	n
========================================
*/
