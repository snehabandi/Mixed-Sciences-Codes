//============================================================================
// Name        : assignment6_merging.cpp
// Author      : Sneha Bandi
// Roll No.    : 2401
// Description : Accept-Display 2 DLL STRICTLY in ascending order 
//		sort and merge them (without new list creation) 
//============================================================================


#include <iostream>
using namespace std;

class node {
	friend class list;
	int data;
	node*prev;
	node* next;
public:
	node()
	{
		data=0;
		prev = NULL;
		next = NULL;
	}
	;
	node(int d)
	{
		data=d;
		prev = NULL;
		next = NULL;
	}
};

class list {
	//friend class node;
	node* start;
public:
	void create();
	void display();
	void merge(list,list);
	list()
	{start=NULL;}

};
void list::create()					//CREATE LIST FUNCTION: TO CREATE A DLL 
{
	node *ptr,*temp;
	int d;
	char ch;
	do
	{
		cout<<"Enter data: ";
	 cin>>d;
	 temp=new node(d);
	 if(start==NULL)
		start=temp;
	 else
	 {
		ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
		temp->prev=ptr;
	 }
	cout<<"Do you want to enter another data (y/n)?\t";
	cin>>ch;
	}while(ch=='y'||ch=='Y');
}
void list::display()				//DISPLAY FUNCTION TO DISPLAY DLL
{
	node*ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		cout<<ptr->data<<"\t";
		ptr=ptr->next;
	}

}
void list::merge(list l1,list l2)		//MERGING OF LIST 1 AND 2
{
	node *ptr,*ptr1,*ptr2;
	ptr=start;
	ptr1=l1.start;
	ptr2=l2.start;
	while(ptr1!=NULL && ptr2!=NULL)
	{
	if(ptr1->data<ptr2->data)
	{
		if(start==NULL)
			{
			 start=ptr1;
		     ptr=ptr1;
			}
		else
		{
			ptr->next=ptr1;
			ptr->prev=ptr;
			ptr=ptr->next;
		}
		ptr1=ptr1->next;
	}

	if(ptr1->data>ptr2->data)
		{
			if(start==NULL)
				{
				 start=ptr2;
			     ptr=ptr2;
				}
			else
			{
				ptr->next=ptr2;
				ptr->prev=ptr;
				ptr=ptr->next;
			}
			ptr2=ptr2->next;
		}
//APPENDING EXTRA ELEMENTS FROM LIST 1
	if(ptr1!=NULL)
	{
		ptr->next=ptr1;

	}
//APPENDING EXTRA ELEMENTS FROM LIST 2
	if(ptr2!=NULL)
		{
			ptr->next=ptr2;

		}
   }

	//display
	cout<<"\nThe entered list is: ";
	ptr=start;
		while(ptr!=NULL)
		{
			cout<<ptr->data<<"\t";
			ptr=ptr->next;
		}
		cout<<"\n";
}
//MAIN
int main()
{
	list ll1,ll2,ll3;
	int n;
	char ans;
	do{
	cout<<"\t\tMENU\nPRESS:\n\t1. To accept the lists";
	cout<<"\n\t2. To display the lists";
	cout<<"\n\t3. To merge the lists\nCHOICE: ";
	cin>>n;

	switch(n)
	{
	case 1:
		//list 1 acceptance
		cout<<"\nEnter first list\n";
		cout<<"NOTE: ENTER NUMBERS IN ASCENDING ORDER ONLY !!!\n";
		ll1.create();

		//list 2 acceptance
		cout<<"\nEnter SECOND list\n";
		cout<<"NOTE: ENTER NUMBERS IN ASCENDING ORDER ONLY !!!\n";
		ll2.create();
		break;
	case 2:
		cout<<"\nThe list 1 is:\t";
		ll1.display();
		cout<<"\nThe list 2 is:\t";
		ll2.display();
			break;

	case 3:
		cout<<"\nThe merged list is:\n";
		ll3.merge(ll1,ll2);
		break;
	default:
		cout<<"\nEnter valid choice!\n";
	}
	cout<<"\nDo you want to continue (y/n)?";
	cin>>ans;
	cout<<"\n_________________________________________________\n";
	}while(ans=='y'||ans=='Y');
return 0;

}
//PROGRAM ENDS

//------------------------------------------------ OUTPUT ------------------------------------------------

/*
		MENU
PRESS:
	1. To accept the lists
	2. To display the lists
	3. To merge the lists
CHOICE: 1

Enter first list
NOTE: ENTER NUMBERS IN ASCENDING ORDER ONLY !!!

Enter data: 1
Do you want to enter another data (y/n)?	y
Enter data: 4
Do you want to enter another data (y/n)?	y
Enter data: 6
Do you want to enter another data (y/n)?	y
Enter data: 9
Do you want to enter another data (y/n)?	y
Enter data: 11 
Do you want to enter another data (y/n)?	n

Enter SECOND list
NOTE: ENTER NUMBERS IN ASCENDING ORDER ONLY !!!

Enter data: 2
Do you want to enter another data (y/n)?	y
Enter data: 3
Do you want to enter another data (y/n)?	y
Enter data: 5
Do you want to enter another data (y/n)?	y
Enter data: 7
Do you want to enter another data (y/n)?	n
_________________________________________________
Do you want to continue (y/n)?y
_________________________________________________
		MENU
PRESS:
	1. To accept the lists
	2. To display the lists
	3. To merge the lists
CHOICE: 2

The list 1 is:	1	4	6	9	11	
The list 2 is:	2	3	5	7	
_________________________________________________
Do you want to continue (y/n)?	y
_________________________________________________
		MENU
PRESS:
	1. To accept the lists
	2. To display the lists
	3. To merge the lists
CHOICE: 3

The merged list is:

The entered list is: 1	2	3	4	5	6	7	9	11	
_________________________________________________
Do you want to continue (y/n)?	n
_________________________________________________


*/
