//============================================================================
// Name        : Assignment5_DLL.cpp
// Author      : Sneha bandi
// Roll No.    :2401
// Description : Doubly Linked List :Accept-Display binary No.;
//			once complement,two's complement,binary addition
//============================================================================
#include <iostream>
#include<string.h>
using namespace std;

class node {
	friend class list;
	int data;
	node*prev;
	node* next;
public:
	node()
	{
		//data=0;
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
	void accept_d();
	void accept_b();
	void display();
	int count();
	list once_complement();
	void twos_complement(list);
	list binary_one();
	void add(list,list);
	list()
	{start=NULL;}

};
void list::accept_d()		//ACCEPTING NO. IN DECIMAL FORM
{
	node *temp;
	int dec=0,n;
	//char c;
	cout<<"Enter the decimal number : ";
    cin>>dec;
    while(dec!=0)
    {
    	n = dec % 2;
    	dec=dec/2;
		temp = new node(n);
		if(start==NULL)
			start=temp;
	    else			//LIST FORMATION IS IN REVERSE ORDER
	    {
		 temp->next=start;
		 start->prev=temp;
		 start=start->prev;

	    }

    }

}
void list::accept_b()		//ACCEPTING NO. IN BINARY FORMAT (BIT BY BIT)
{
	node *temp,*ptr;
	int s,d;
	char c;

    cout<<"\nEnter bit by bit\n";
	do
	{
    		cout<<"\nEnter bit: ";
		cin>>d;
		temp = new node(d);
		if(start==NULL)
			start=temp;
	    else
	    {
		 ptr=start;
		 while(ptr->next!=NULL)
		  {
			ptr=ptr->next;
	     	  }

		  ptr->next = temp;
		  temp->prev=ptr;
	    }
	cout<<"Do you want to enter another bit (y/n)?\t:";
		cin>>c;
	}while(c=='y'||c=='Y');
}
void list::display()			//DISPLAYING ENTERED BINARY NO.
{
	node *ptr;
		ptr=start;
		while(ptr!=NULL)
		{
			cout<<ptr->data;
			ptr=ptr->next;

		}

}
int list::count()		//COUNT FUNCTION FOR COUNTING NODES 
{				//TO CREATE BINARY ONE
	node *ptr;
	int count=0;
	ptr=start;
	while(ptr!=NULL)
	{
		ptr=ptr->next;
		count++;

	}
	return count;
}
list list::once_complement()		//ONCE COMPLEMENT + STORAGE IN NEW NODE
{
	node *ptr,*trav,*temp;
    list t;
    ptr=start;

	while(ptr!=NULL)
	{
	 temp = new node();
	 if(ptr->data==1)
		 {temp->data=0;}
	 else
		 {temp->data=1;}

	 if(t.start==NULL)
	   t.start=temp;
	 else
	   {
		trav=t.start;
   	     while(trav->next!=NULL)
		{
		  trav=trav->next;
		}
		  trav->next=temp;
		  temp->prev=trav;
	   }
	  ptr=ptr->next;
	 }
	 //Display
	cout<<"\nOnce complement is: ";
	 return t;
}

list list::binary_one()				//CREATION FOR BINARY ONE TO ADD IN ONCE	
{						//COMPLEMENT TO OBTAIN TWOS COMPLEMENT
	node *ptr1,*temp,*temp1;
	int c;
	c=count();
	list d;
	for(int i=1;i<c;i++)
	{

	  temp = new node(0);
	  if(d.start==NULL)
		{
		  d.start=temp;
		}
	  else
	   {
		ptr1=d.start;
	    while(ptr1->next!=NULL)
	     {
		ptr1=ptr1->next;
	     }
	    ptr1->next=temp;
	    temp->prev=ptr1;
	   }
	}

	temp1 = new node(1);
	temp->next = temp1;
	temp1->prev=temp;
//DISPLAY IN SWITCH
return d;
}

void list::twos_complement(list d1)		//TWOS COMPLEMENT:CALL ONCE COMP.,BINARY_ONE,ADD FUNCTIONS
{
	list d2,d3,d4;
	d2=d1.once_complement();
	d2.display();
	d3=d1.binary_one();
	cout<<"\nBinary one for two's complement is: ";
	d3.display();
	cout<<"\nTwo's complement is:";
	d4.add(d2,d3);

}

void list::add(list d1,list d2)			//ADDITION OF TWO BINARY NO.'s
{
    list d;
	node *ptr1,*ptr2,*sum,*temp,*temp1;
	int s=0,carry=0;

//TRAVERSING BOTH THE LIST TILL END
	ptr1=d1.start;
	ptr2=d2.start;
	while(ptr1->next!=NULL)
	{
		ptr1=ptr1->next;
	}
	while(ptr2->next!=NULL)
	{
		ptr2=ptr2->next;
	}
//WHILE LOOP TILL BOTH THE LIST END
   while(ptr1!=NULL||ptr2!=NULL)
   {
//ADDITION STARTING FROM LSB
//SUM BY EXOR
	s=(ptr1->data)^(ptr2->data)^(carry);
//CARRY
	if((ptr1->data==1 && ptr2->data==1)||(ptr1->data==1 && carry==1)||(ptr2->data==1 && carry==1))
		carry=1;
	else
	     carry=0;

//MAKING 3rd LIST 'sum' TO STORE ADDITION OF LISTS d1 AND d2
		temp=new node(s);
	if(d.start==NULL)
		d.start=temp;
	else
	{
	  sum=d.start;
		while(sum->prev!=NULL)
		{
		  sum=sum->prev;
		}
	  temp->next=sum;
	  sum->prev=temp;
	  d.start=temp;
	}
//APPENDING CARRY BIT EXPLICITLY
    if(ptr1->prev==NULL||ptr2->prev==NULL)
     {
	if(carry==1)
	{
		temp1=new node(1);
		temp1->next=d.start;
		temp->prev=temp1;
		d.start=temp1;
	}
     }

//INCREMENTING POINTERS OF BOTH THE LIST
	ptr1=ptr1->prev;
	ptr2=ptr2->prev;

   }
//WHILE ENDS
//DISPLAYING SUM i.e. list 'SUM'
	    sum=d.start;
	 	while(sum!=NULL)
	 	{
	  	  cout<<sum->data;
	 	  sum=sum->next;

	 	}
	cout<<"\n";
}
					//main function
int main() {
	int n=0,n1=0;
	char choice;
	list ll,l,l1,l2,l3,l4,l5,l6;
	do{
		cout<<"\n*******************  MENU  *********************\n";
		cout<<"1. to find once complement\n";
		cout<<"2. to find two's complement\n";
		cout<<"3. to add two binary numbers\n";
		cin>>n1;
		
		//switch caseII for operations
		switch(n1)
		{
		  case 1:
			cout<<"\n\tPress:\n";
			cout<<"\t1. To accept decimal number\n";
			cout<<"\t2. to accept binary number(bit by bit) \n";
			cin>>n;
			//switch caseI for decimal or binary acceptance 
			switch(n)
			{
			  case 1:
				l1.accept_d();
				cout<<"Entered number (in binary) is: ";
				l1.display();
				break;
			  case 2:
				l1.accept_b();
				cout<<"Binary number entered is: ";
				l1.display();
				break;
			}
			l2=l1.once_complement();
			l2.display();
			break;
		  case 2:
			cout<<"\n\tPress:\n";
			cout<<"\t1. To accept decimal number\n";
			cout<<"\t2. to accept binary number(bit by bit) \n";
			cin>>n;

			//switch caseI for decimal or binary acceptance 
			switch(n)
			{
			  case 1:
				l3.accept_d();
				cout<<"Entered number (in binary) is: ";
				l3.display();
				break;
			  case 2:
				l3.accept_b();
				cout<<"Binary number entered is: ";
				l3.display();
				break;
			}
			ll.twos_complement(l3);
			break;
		  case 3:
		  	//Decimal/Binary
			cout<<"\n\tPress:\n";
			cout<<"\t1. To accept decimal number\n";
			cout<<"\t2. to accept binary number(bit by bit) \n";
			cin>>n;
			cout<<"____________________________________________________\n";
			//switch caseI for decimal or binary acceptance 
			switch(n)
			{
			  case 1:
				cout<<"\n1st no.:\n\t";
				l4.accept_d();
				cout<<"2nd no:\n\t";
				l5.accept_d();
				cout<<"The numbers are\n\tFirst: ";
				l4.display();
				cout<<"\tSecond: ";
				l5.display();
				break;
			  case 2:
				cout<<"\n1st no.:\n\t";
				l4.accept_b();
				cout<<"2nd no:\n\t";
				l5.accept_b();
				cout<<"The numbers are\n\tFirst: ";
				l4.display();
				cout<<"\tSecond: ";
				l5.display();
				break;
			}
			cout<<"\n____________________________________________________\n";
			cout<<"\nBinary addition is:";
			l6.add(l4,l5);
			break;
		  default:
			cout<<"\nEnter valid choice!\n";
			break;
		}	

	cout<<"\n=========================================================\n";
	cout<<"\nDo yo want to continue (y/n)?\t";
	cin>>choice;
	cout<<"==========================================================\n";
	}while(choice=='y'||choice=='Y');

	return 0;
}
//PROGRAM ENDS

//------------------------------------------------ OUTPUT ------------------------------------------------

/*

*******************  MENU  *********************
1. to find once complement
2. to find two's complement
3. to add two binary numbers
1

	Press:
	1. To accept decimal number
	2. to accept binary number(bit by bit) 
1
Enter the decimal number : 6
Entered number (in binary) is: 110
Once complement is: 001
=========================================================

Do yo want to continue (y/n)?	y
==========================================================

*******************  MENU  *********************
1. to find once complement
2. to find two's complement
3. to add two binary numbers
2

	Press:
	1. To accept decimal number
	2. to accept binary number(bit by bit) 
1
Enter the decimal number : 12
Entered number (in binary) is: 1100
Once complement is: 0011
Binary one for two's complement is: 0001
Two's complement is:0100

=========================================================

Do yo want to continue (y/n)?	y
==========================================================

*******************  MENU  *********************
1. to find once complement
2. to find two's complement
3. to add two binary numbers
3

	Press:
	1. To accept decimal number
	2. to accept binary number(bit by bit) 
1
____________________________________________________

1st no.:
	Enter the decimal number : 4
2nd no:
	Enter the decimal number : 5
The numbers are
	First: 100	Second: 101
____________________________________________________

Binary addition is:1001

=========================================================

Do yo want to continue (y/n)?	n
==========================================================

------------------------------------------- BINARY FORM OF INPUT -------------------------------------------

*******************  MENU  *********************
1. to find once complement
2. to find two's complement
3. to add two binary numbers
1

	Press:
	1. To accept decimal number
	2. to accept binary number(bit by bit) 
2

Enter bit by bit

Enter bit: 1
Do you want to enter another bit (y/n)?	:y

Enter bit: 0
Do you want to enter another bit (y/n)?	:y

Enter bit: 1
Do you want to enter another bit (y/n)?	:y

Enter bit: 0
Do you want to enter another bit (y/n)?	:n
Binary number entered is: 1010
Once complement is: 0101
=========================================================

Do yo want to continue (y/n)?	y
==========================================================

*******************  MENU  *********************
1. to find once complement
2. to find two's complement
3. to add two binary numbers
2

	Press:
	1. To accept decimal number
	2. to accept binary number(bit by bit) 
2

Enter bit by bit

Enter bit: 1
Do you want to enter another bit (y/n)?	:y

Enter bit: 1
Do you want to enter another bit (y/n)?	:y

Enter bit: 1
Do you want to enter another bit (y/n)?	:y

Enter bit: 0
Do you want to enter another bit (y/n)?	:n
Binary number entered is: 1110
Once complement is: 0001
Binary one for two's complement is: 0001
Two's complement is:0010

=========================================================

Do yo want to continue (y/n)?	y
==========================================================

*******************  MENU  *********************
1. to find once complement
2. to find two's complement
3. to add two binary numbers
3

	Press:
	1. To accept decimal number
	2. to accept binary number(bit by bit) 
2
____________________________________________________

1st no.:
	
Enter bit by bit

Enter bit: 1
Do you want to enter another bit (y/n)?	:y

Enter bit: 0
Do you want to enter another bit (y/n)?	:y

Enter bit: 0
Do you want to enter another bit (y/n)?	:n
2nd no:
	
Enter bit by bit

Enter bit: 1
Do you want to enter another bit (y/n)?	:y

Enter bit: 0
Do you want to enter another bit (y/n)?	:y

Enter bit: 1
Do you want to enter another bit (y/n)?	:n
The numbers are
	First: 100	Second: 101
____________________________________________________

Binary addition is:1001

=========================================================

Do yo want to continue (y/n)?	n
==========================================================

*/
