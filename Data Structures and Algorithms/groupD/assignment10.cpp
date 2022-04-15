//============================================================================
// Name        : pizza_parlour.cpp
// Author      : Sneha Bandi
// Roll No.    : 2401
// Description : Pizza Parlour implementation using circular queue !
//============================================================================

#include <iostream>
#include<string.h>
#define MAX 4
using namespace std;
//PIZZA CLASS
class pizza
{
	friend class queue;
	char name[30];			//NAME F CUSTOMER
	int order_no;			//ORDER NO
	char str[50];			//TYPE OF PIZZA
public:
	void accept();
	void display()
	{
		cout<<"\n\t"<<name<<"\t\t"<<order_no<<"\t\t\t"<<str;
	}
};

//CLASS CIRCULAR QUEUE
class cqueue
{
	pizza q[MAX];
	int rear,front;
public:
	cqueue()
	{
		front=0;
		rear=0;
	}
	void order();
	int qfull();
	int qempty();
	void serve();
	void display_list();

};

//ORDER ACCEPTED
void pizza::accept()
{
	int order;
	cout<<"\n\tEnter name : ";
	cin>>name;
	cout<<"\n\tEnter order no. : ";
	cin>>order_no;
	cout<<"\n\tEnter your pizza choice (1/2/3/4/5):\n";
	cout<<"\n\t1. Tomato-onion pizza";
	cout<<"\n\t2. Capsicum-Onion-cheese pizza";
	cout<<"\n\t3. Veg double cheese pizza";
	cout<<"\n\t4. Capsicum-olive-mushroom pizza";
	cout<<"\n\t5. Veg cheeze paneer pizza\n\nORDER : ";
	cin>>order;
	switch(order)
	{
	 case 1:
		strcpy(str,"Tomato-onion pizza");
	 	break;
	 case 2:
		strcpy(str,"Capsicum-Onion-cheese pizza");
	 	break;
	 case 3:
		strcpy(str,"Veg double cheese pizza");
	 	break;
	 case 4:
		strcpy(str,"Capsicum-olive-mushroom pizza");
	 	break;
	 case 5:
		strcpy(str,"Veg cheeze paneer pizza");
	 	break;
	
	}
}

//CHECKING IF QUEUE IS EMPTY
int cqueue::qempty()
{
  if(rear==front)
	return 1;
  else
	return 0;

}
//CHECKING IF QUEUE IS FULL
int cqueue::qfull()
{
  if(front==(rear+1)%MAX)
	return 1;
  else
	return 0;

}
//ORDER INSERTED IN QUEUE
void cqueue::order()
{
	pizza p;
	char ans;

 	do{
	 if(qfull()==1)
		 cout<<"\n\t* SORRY! your order cannot be placed!\n\tThe counter is busy.";
	 else	
	 {	
		p.accept();
		q[rear]= p;
		rear=(rear+1)%MAX;

	  }
	cout<<"\n<--------------------------------------------------------->";
	 cout<<"\nWould you like to place another order (y/n)?\t";
	 cin>>ans;
	cout<<"<--------------------------------------------------------->\n";
	 }while(ans=='y'||ans=='Y');
}

//ORDER SERVED
void cqueue::serve()
{
	pizza p;
	int temp;
	if(qempty()==1)
		cout<<"\nAll the orders are served!";
	else{
		cout<<"\n\t<-------------------------------------------->\n";
		cout<<"\n\tFollowing order is served\n\n\tName:\t\tOrder No:\t\tOrder\n";
		p=q[front];
		front=(front+1)%MAX;
		p.display();
		cout<<"\n\t<-------------------------------------------->\n";
	}
}

//PRINTING COMPLETE ORDER QUEUE
void cqueue::display_list()
{
	int i=front;
	pizza p[MAX];
	cout<<"\n\tName:\t\tOrder No:\t\tOrder:\n";
	while(i<rear)
	{
		p[i]=q[i];
		p[i].display();
		i=(i+1)%MAX;
	}
}
//MAIN
int main()
{
	cqueue r;
	int t;
	char ch;
	cout<<"\t\t\tWELCOME TO THE PIZZA PALOUR !!!\n\n";
//DO-WHILE STARTS
	do{
	cout<<"Enter the task\n";
	cout<<"\t1.To order a pizza\n\t2.Display order list\n\t3.To serve the order\n\n";
	cout<<"CHOICE: ";
	cin>>t;
	switch(t)
	{
	case 1:
		r.order();
		break;
	case 2:
		r.display_list();
		break;
	case 3:
		r.serve();
		break;
	default:
		cout<<"\nENTER VALID CHOICE!\n";
	}
	cout<<"\n==================================================";
	cout<<"\nDo you want to continue (y/n)?  ";
	cin>>ch;
	cout<<"==================================================\n";
	}while(ch=='y'||ch=='Y');
//DO-WHILE ENDS
	return 0;
}
//PROGRAM ENDS
//-----------------------------OUTPUT-------------------------------------

/*
			WELCOME TO THE PIZZA PALOUR !!!

Enter the task
	1.To order a pizza
	2.Display order list
	3.To serve the order

CHOICE: 1

	Enter name : Sneha

	Enter order no. : 1

	Enter your pizza choice (1/2/3/4/5):

	1. Tomato-onion pizza
	2. Capsicum-Onion-cheese pizza
	3. Veg double cheese pizza
	4. Capsicum-olive-mushroom pizza
	5. Veg cheeze paneer pizza

ORDER : 2

<--------------------------------------------------------->
Would you like to place another order (y/n)?	y
<--------------------------------------------------------->

	Enter name : ABC

	Enter order no. : 2

	Enter your pizza choice (1/2/3/4/5):

	1. Tomato-onion pizza
	2. Capsicum-Onion-cheese pizza
	3. Veg double cheese pizza
	4. Capsicum-olive-mushroom pizza
	5. Veg cheeze paneer pizza

ORDER : 3

<--------------------------------------------------------->
Would you like to place another order (y/n)?	y
<--------------------------------------------------------->

	Enter name : XYZ

	Enter order no. : 3

	Enter your pizza choice (1/2/3/4/5):

	1. Tomato-onion pizza
	2. Capsicum-Onion-cheese pizza
	3. Veg double cheese pizza
	4. Capsicum-olive-mushroom pizza
	5. Veg cheeze paneer pizza

ORDER : 5

<--------------------------------------------------------->
Would you like to place another order (y/n)?	y
<--------------------------------------------------------->

	* SORRY! your order cannot be placed!
	The counter is busy.
<--------------------------------------------------------->
Would you like to place another order (y/n)?	n
<--------------------------------------------------------->

==================================================
Do you want to continue (y/n)?  y
==================================================
Enter the task
	1.To order a pizza
	2.Display order list
	3.To serve the order

CHOICE: 2

	Name:		Order No:		Order:

	Sneha		1			Capsicum-Onion-cheese pizza
	ABC		2			Veg double cheese pizza
	XYZ		3			Veg cheeze paneer pizza
==================================================
Do you want to continue (y/n)?  y
==================================================
Enter the task
	1.To order a pizza
	2.Display order list
	3.To serve the order

CHOICE: 3

	<-------------------------------------------->

	Following order is served

	Name:		Order No:		Order

	Sneha		1			Capsicum-Onion-cheese pizza
	<-------------------------------------------->

==================================================
Do you want to continue (y/n)?  y
==================================================
Enter the task
	1.To order a pizza
	2.Display order list
	3.To serve the order

CHOICE: 3

	<-------------------------------------------->

	Following order is served

	Name:		Order No:		Order

	ABC		2			Veg double cheese pizza
	<-------------------------------------------->

==================================================
Do you want to continue (y/n)?  y
==================================================
Enter the task
	1.To order a pizza
	2.Display order list
	3.To serve the order

CHOICE: 3

	<-------------------------------------------->

	Following order is served

	Name:		Order No:		Order

	XYZ		3			Veg cheeze paneer pizza
	<-------------------------------------------->

==================================================
Do you want to continue (y/n)?  y
==================================================
Enter the task
	1.To order a pizza
	2.Display order list
	3.To serve the order

CHOICE: 3

All the orders are served!
==================================================
Do you want to continue (y/n)?  n
==================================================

*/

