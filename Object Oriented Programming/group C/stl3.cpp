//============================================================================
// Name        : stl3.cpp
// Author      : Sneha Bandi
// Roll No     : 2401
// Description : Stack and Queue using SLL template
//============================================================================

#include <iostream>
#include<string.h>
#include<list>
using namespace std;
//CLASS STACK STARTS
class Stack
{
public:
	int a;
	list<int> s;
	list<int>::iterator itr;
	void push()		//STACK OPERATION:PUSH() 
	{
		cout<<"\nEnter a number : ";
		cin>>a;
		s.push_back(a);

	}
	void display_stack()
	{
		cout<<"\nThe elements of stack are : ";
		for(itr=s.begin();itr!=s.end();itr++)
			cout<<"\t"<<*itr;
	}
	void pop()		//STACK OPERATION POP()
	{
		itr=s.end();
		itr--;
		s.pop_back();
		cout<<"\nThe elements popped out are : "<<*itr;
	}
};
//STACK CLASS ENDS

//QUEUE CLASS STARTS
class Queue
{
public:
	int a;
	list<int> s;
	list<int>::iterator itr;
	void push()			//QUEUE OPERATION:PUSH()
	{
		cout<<"\nEnter a number : ";
		cin>>a;
		s.push_back(a);

	}
	void display_queue()
	{
		cout<<"\nThe elements of queue are : ";
		for(itr=s.begin();itr!=s.end();itr++)
			cout<<"\t"<<*itr;
	}
	void pop()			//QUEUE OPERATION:POP()
	{
		itr=s.begin();
		s.pop_front();
		cout<<"\nThe elements popped out are : "<<*itr;
	}
};
//QUEUE CLASS ENDS

//main
int main() {
	Stack s;
	Queue q;
	int n,n1,n2;
	char choice,choice1,choice2;

	cout<<"\n\t\t\tTHIS PROGRAM IS TO PERFORM STACK & QUEUE OPERATION USING SLL STL !!\n";
	//DO-WHILE 1
	do{
	cout<<"Select the data structure :\n\t1. STACK\t2. QUEUE\nCHOICE : ";
	cin>>n;
//SWITCH CASE I STARTS
	switch(n)
	{
	//CASE 1 : STACK OPERATIONS
	case 1:
		//DO-WHILE II STARTS
		do{
		cout<<"\n******************* MENU ******************\n\tPRESS:";
		cout<<"\n\t1. Add elements\n\t2. Remove elements\n\t3. Display elements\nCHOICE : ";
		cin>>n1;
		switch(n1)
		{
		case 1:
			s.push();
			break;
		case 2:
			s.pop();
			break;
		case 3:
			s.display_stack();
			break;
		}
		cout<<"\n======================================================";
		cout<<"\nDo you want to perform any other stack operations (y/n)?\t";
		cin>>choice1;
		cout<<"======================================================\n";
		}while(choice1=='y'||choice1=='Y');
		//DO-WHILE II ENDS	
	break;
	//CASE 2: QUEUE OPERATIONS
	case 2:
		//DO-WHILE III STARTS
		do{
		cout<<"\n******************* MENU ******************\n\tPRESS:";
		cout<<"\n\t1. Add elements\n\t2. Remove elements\n\t3. Display elements\nCHOICE : ";
		cin>>n2;
		switch(n2)
		{
		case 1:
			q.push();
			break;
		case 2:
			q.pop();
			break;
		case 3:
			q.display_queue();
			break;
		}
		cout<<"\n======================================================";
		cout<<"\nDo you want to perform any other queue operations (y/n)?\t";
		cin>>choice2;
		cout<<"======================================================\n";
		}while(choice2=='y'||choice2=='Y');
		//DO-WHILE III ENDS

	break;
	}
	//SWITCH CASE I ENDS
	cout<<"\n======================================================";
	cout<<"\nDo you want to select other data structure (y/n)?\t";
	cin>>choice;
	cout<<"======================================================\n";
	}while(choice=='y'||choice=='Y');
//DO-WHILE I ENDS
	return 0;
}
//PROGRAM ENDS
//<-------------------------------------- OUTPUT ----------------------------------------->
/*
			THIS PROGRAM IS TO PERFORM STACK & QUEUE OPERATION USING SLL STL !!
Select the data structure :
	1. STACK	2. QUEUE
CHOICE : 1

******************* MENU ******************
	PRESS:
	1. Add elements
	2. Remove elements
	3. Display elements
CHOICE : 1

Enter a number : 8

======================================================
Do you want to perform any other stack operations (y/n)?	y
======================================================

******************* MENU ******************
	PRESS:
	1. Add elements
	2. Remove elements
	3. Display elements
CHOICE : 1

Enter a number : 5

======================================================
Do you want to perform any other stack operations (y/n)?	y
======================================================

******************* MENU ******************
	PRESS:
	1. Add elements
	2. Remove elements
	3. Display elements
CHOICE : 1

Enter a number : 3

======================================================
Do you want to perform any other stack operations (y/n)?	y
======================================================

******************* MENU ******************
	PRESS:
	1. Add elements
	2. Remove elements
	3. Display elements
CHOICE : 3

The elements of stack are : 	8	5	3
======================================================
Do you want to perform any other stack operations (y/n)?	y
======================================================

******************* MENU ******************
	PRESS:
	1. Add elements
	2. Remove elements
	3. Display elements
CHOICE : 2

The elements popped out are : 3
======================================================
Do you want to perform any other stack operations (y/n)?	y
======================================================

******************* MENU ******************
	PRESS:
	1. Add elements
	2. Remove elements
	3. Display elements
CHOICE : 3

The elements of stack are : 	8	5
======================================================
Do you want to perform any other stack operations (y/n)?	y
======================================================

******************* MENU ******************
	PRESS:
	1. Add elements
	2. Remove elements
	3. Display elements
CHOICE : 2

The elements popped out are : 5
======================================================
Do you want to perform any other stack operations (y/n)?	y
======================================================

******************* MENU ******************
	PRESS:
	1. Add elements
	2. Remove elements
	3. Display elements
CHOICE : 3

The elements of stack are : 	8
======================================================
Do you want to perform any other stack operations (y/n)?	y
======================================================

******************* MENU ******************
	PRESS:
	1. Add elements
	2. Remove elements
	3. Display elements
CHOICE : 2

The elements popped out are : 8
======================================================
Do you want to perform any other stack operations (y/n)?	n
======================================================

======================================================
Do you want to select other data structure (y/n)?	y
======================================================
Select the data structure :
	1. STACK	2. QUEUE
CHOICE : 2

******************* MENU ******************
	PRESS:
	1. Add elements
	2. Remove elements
	3. Display elements
CHOICE : 1

Enter a number : 2

======================================================
Do you want to perform any other queue operations (y/n)?	y
======================================================

******************* MENU ******************
	PRESS:
	1. Add elements
	2. Remove elements
	3. Display elements
CHOICE : 1

Enter a number : 3

======================================================
Do you want to perform any other queue operations (y/n)?	y
======================================================

******************* MENU ******************
	PRESS:
	1. Add elements
	2. Remove elements
	3. Display elements
CHOICE : 1

Enter a number : 5

======================================================
Do you want to perform any other queue operations (y/n)?	y
======================================================

******************* MENU ******************
	PRESS:
	1. Add elements
	2. Remove elements
	3. Display elements
CHOICE : 3

The elements of queue are : 	2	3	5
======================================================
Do you want to perform any other queue operations (y/n)?	y
======================================================

******************* MENU ******************
	PRESS:
	1. Add elements
	2. Remove elements
	3. Display elements
CHOICE : 2

The elements popped out are : 2
======================================================
Do you want to perform any other queue operations (y/n)?	y
======================================================

******************* MENU ******************
	PRESS:
	1. Add elements
	2. Remove elements
	3. Display elements
CHOICE : 3

The elements of queue are : 	3	5
======================================================
Do you want to perform any other queue operations (y/n)?	y
======================================================

******************* MENU ******************
	PRESS:
	1. Add elements
	2. Remove elements
	3. Display elements
CHOICE : 2

The elements popped out are : 3
======================================================
Do you want to perform any other queue operations (y/n)?	y
======================================================

******************* MENU ******************
	PRESS:
	1. Add elements
	2. Remove elements
	3. Display elements
CHOICE : 3

The elements of queue are : 	5
======================================================
Do you want to perform any other queue operations (y/n)?	y
======================================================

******************* MENU ******************
	PRESS:
	1. Add elements
	2. Remove elements
	3. Display elements
CHOICE : 2

The elements popped out are : 5
======================================================
Do you want to perform any other queue operations (y/n)?	n
======================================================

======================================================
Do you want to select other data structure (y/n)?	n
======================================================

*/
