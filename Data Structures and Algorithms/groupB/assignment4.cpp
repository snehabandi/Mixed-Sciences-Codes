//============================================================================
// Name        : singly_linked_list.cpp
// Author      : Sneha Bandi
// Roll No;    : 2401
// Description : Singly Linked List preparation:president,member,secretary;
//		 deletion,insertion,count,reverse;
//============================================================================

#include <iostream>
#include<string.h>
using namespace std;

class node {
	friend class list;		//MAKE LIST AS FRIEND CLASS
	int prnno;
	char name[10];
	node* next;
public:
//DEFAULT CONSTRUCTOR OF LIST
	node()
	{
		prnno = 0;
		next = NULL;
	}
	node(int, char*);
};

class list {
	node* start;
public:	
	void create_record();
	void display();
	void insert_p();
	void insert_s();
	void insert_m();
	void delete_rec();
	void count();
	void reverse(node* s);//s?
	void reverse_rec()
	{
	  reverse(start);		//we have passed start as in recursion LIFO
	}
	void concat(list,list);
//DEFAULT CONSTRUCTOR OF LIST
	list()
	{start=NULL;}

};
//PARAMETERISED CONSTRUCTOR OF NODE
node::node(int d, char* s)
{
	prnno = d;
	strcpy(name,s);

}
void list::create_record()
{
	int n1;
	char ch;
 cout<<"\n______________________________________________________________\n";
	do{
	cout << "Enter your choice for the record\n";
	cout << "1 for president\n";
	cout << "2 for members\n";
	cout << "3 for secretary\n";
	cin >> n1;
	switch (n1)
	{
	case 1:
		insert_p();
		break;
	case 2:
	    insert_m();
		break;
	case 3:
		insert_s();
		break;

	}
	cout<<"\nDo you want to enter another record (y/n)?\t";
	cin>>ch;
 cout<<"______________________________________________________________\n";
	}while(ch=='y'||ch=='Y');

}

void list::insert_p()
{
	int p;
	char n[10];
	cout<<"Enter the prn number\n";
	cin>>p;
	cout<<"Enter the name\n";
	cin>>n;
	node* temp = new node(p,n);
	if(start==NULL)
		start = temp;
	else
	{
	  temp->next=start;
	  start=temp;
	}

}
void list::insert_m()
{
	int p;
	char ch;
	char n[10];
	node *ptr;
	do{
	cout<<"Enter the prn number\n";
	cin>>p;
	cout<<"Enter the name\n";
	cin>>n;
	node* temp = new node(p,n);
	if(start==NULL)
		start = temp;
	else
	{
		ptr = start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
	cout<<"\nDo you want to enter another member's record\n";
	cin>>ch;
	}while(ch=='y' || ch=='Y');

}

void list::insert_s()
{
	int p;
	char ch;
	char n[10];
	node *ptr;
	cout<<"Enter the prn number\n";
	cin>>p;
	cout<<"Enter the name\n";
	cin>>n;
	node* temp = new node(p,n);
	if(start==NULL)
		start = temp;

	else{
	ptr = start;
	while(ptr->next!=NULL)
	  {
		ptr=ptr->next;
	  }
		ptr->next=temp;
	}
}

void list::display()
{
	node*ptr;
	ptr = start;
	while(ptr!=NULL)
	{

		cout<<"\nPRN No. : "<<ptr->prnno;
		cout<<"\nName: "<<ptr->name;
		ptr = ptr->next;
	}

}
void list::delete_rec()
{
	node *ptr,*prev;
	int p;
	cout<<"\nEnter the record to be deleted i.e. PRN No. : ";
	cin>>p;
	ptr=start;
//DELETE PRESIDENT
	if(start->prnno==p)
	{
		prev=ptr;
		ptr=ptr->next;
		delete prev;
		start=ptr;
		cout<<"\nrecord is deleted\n";
			
	}
//DELETE MEMBER & SECRETARY
	else{
	while(ptr->next!=NULL)
	{
	  prev=ptr;
	  ptr=ptr->next;					
	  if(ptr->prnno==p)
	   {
		delete ptr;
		prev->next=ptr->next;			//PREV->NEXT=PTR->NEXT NOT PTR
		break;
		
	   }
	}
	if(ptr==NULL)
	{
	  cout<<"\nRecord not found\n";
	}
	}

}
void list::count()
{
	node *ptr;
	int count=0;
	ptr=start;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->next;
	}
	cout<<"\nTotal records in list are : "<<count<<endl;
}


void list::reverse(node* ptr)
{
	if(ptr==NULL)
	  return;
	else
	  reverse(ptr->next);

	  cout<<"\nPRN No. : "<<ptr->prnno;
	  cout<<"\nName: "<<ptr->name;
}

void list::concat(list sll1,list sll2)
{
	node *ptr;
	ptr=sll1.start;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=sll2.start;
	cout<<"\nThe concated list is\n";
	sll1.display();
}


int main() {
	int t=0;
	char choice;
	list l,l1,l2,l3;
		cout<<"\n===========================================================================";
	do{
	 cout<<"***MENU***\n";
	 cout<<"Press"<<endl;
	 cout<<"\t1 to create new record\n";
	 cout<<"\t2 to display record\n";
	 cout<<"\t3 to delete existing record\n";
	 cout<<"\t4 to count the existing records\n";
	 cout<<"\t5 to reverse the list\n";
	 cout<<"\t6 to concat record\n";

	 cin>>t;

	 switch(t)
	 {
	 case 1:
		l.create_record();
		break;
	 case 2:
		l.display();
		 break;
	 case 3:
		l.delete_rec();
		 break;
	 case 4:
		l.count();
		 break;
	 case 5:
		cout<<"\nThe reversed list is\n";
		l.reverse_rec();
		//l.display();
		 break;
	 case 6:
		cout<<"\nEnter the first list\n";
		l1.create_record();
		cout<<"\nEnter the second list\n";
		l2.create_record();
		l3.concat(l1,l2);
		 break;


	 }
	cout<<"\nDo you want to continue (y/n) ?\n";
	cin>>choice;
		cout<<"\n===========================================================================";
	 }while(choice=='y');

	return 0;
}
//PROGRAM ENDS

//------------------------------------------------ OUTPUT ------------------------------------------------

/* 
===========================================================================
***MENU***
Press
	1 to create new record
	2 to display record
	3 to delete existing record
	4 to count the existing records
	5 to reverse the list
	6 to concat record
1
Enter your choice for the record
1 for president
2 for members
3 for secretary
1
Enter the prn number : 1
Enter the name : president
______________________________________________________________
Do you want to enter another record (y/n)?	y
Enter your choice for the record
1 for president
2 for members
3 for secretary
2
Enter the prn number : 2
Enter the name : member_one
______________________________________________________________
Do you want to enter another member's record?	y   
Enter the prn number
3
Enter the name
member_two
______________________________________________________________
Do you want to enter another member's record?	y
Enter the prn number
4
Enter the name
member_three
______________________________________________________________
Do you want to enter another member's record	n
______________________________________________________________
Do you want to enter another record (y/n)?	y
Enter your choice for the record
1 for president
2 for members
3 for secretary
3
Enter the prn number : 5
Enter the name:	secretary

Do you want to enter another record (y/n)?	n
______________________________________________________________
Do you want to continue (y/n) ?	y

===========================================================================
***MENU***
Press
	1 to create new record
	2 to display record
	3 to delete existing record
	4 to count the existing records
	5 to reverse the list
	6 to concat record
2

PRN No. : 1
Name: president
PRN No. : 2
Name: member_one
PRN No. : 3
Name: member_two
PRN No. : 4
Name: member_three
PRN No. : 5
Name: secretary
Do you want to continue (y/n) ?
y

===========================================================================
***MENU***
Press
	1 to create new record
	2 to display record
	3 to delete existing record
	4 to count the existing records
	5 to reverse the list
	6 to concat record
3

Enter the record to be deleted i.e. PRN No. : 3

Do you want to continue (y/n) ?
y

===========================================================================
***MENU***
Press
	1 to create new record
	2 to display record
	3 to delete existing record
	4 to count the existing records
	5 to reverse the list
	6 to concat record
2

PRN No. : 1
Name: president
PRN No. : 2
Name: member_one
PRN No. : 4
Name: member_three
PRN No. : 5
Name: secretary
Do you want to continue (y/n) ?
y

===========================================================================
***MENU***
Press
	1 to create new record
	2 to display record
	3 to delete existing record
	4 to count the existing records
	5 to reverse the list
	6 to concat record
4

Total records in list are : 4

Do you want to continue (y/n) ?	y

===========================================================================
***MENU***
Press
	1 to create new record
	2 to display record
	3 to delete existing record
	4 to count the existing records
	5 to reverse the list
	6 to concat record
5

The reversed list is

PRN No. : 5
Name: secretary
PRN No. : 4
Name: member_three���
PRN No. : 2
Name: member_one
PRN No. : 1
Name: president
Do you want to continue (y/n) ?	y

==========================================================================
***MENU***
Press
	1 to create new record
	2 to display record
	3 to delete existing record
	4 to count the existing records
	5 to reverse the list
	6 to concat record
3

Enter the record to be deleted i.e. PRN No. : 5

Do you want to continue (y/n) ?	y
===========================================================================
***MENU***
Press
	1 to create new record
	2 to display record
	3 to delete existing record
	4 to count the existing records
	5 to reverse the list
	6 to concat record
2

PRN No. : 1
Name: president
PRN No. : 2
Name: member_one
PRN No. : 4
Name: member_three
Do you want to continue (y/n) ?	n
===========================================================================
*/


