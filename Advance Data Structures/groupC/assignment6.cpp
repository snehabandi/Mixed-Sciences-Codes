//============================================================================
// Name        : assignment6.cpp
// Author      : Sneha Bandi
// Roll No.    : 2401
// Description : To create,display,insert,search record from a hash table using open
//					addressing ;h(x)=x%10;Hash table size 10;
//					Hashing to be done on client ID;
//============================================================================

#include <iostream>
using namespace std;
#define MAX 10
class list
{
	friend class hashing;
 list* next;
 int client_id;
 long long int phone_no;
public:
 list()
 {
	 next=NULL;
	 client_id=0;
	 phone_no=0;
 }
};
class hashing
{
	 list hash_list[MAX];
	 static int count;
public:
	 void create();
	 void display();
	 void insert(int,int);
	 void search_id();
	 void search_phone_no();

};
int hashing::count=0;
void hashing::create()
{
	char ans;
	int id,num;
do{
 cout<<"\nEnter client id : ";
 cin>>id;
 cout<<"\nEnter client phone no. : ";
 cin>>num;
 insert(id,num);
 cout<<"\nEnter another record (y/n) ?\t";
 cin>>ans;
 hashing::count++;
}while(ans=='y'||ans=='Y');
}
void hashing::insert(int id,int num)
{
	int i;
	i=id%10;
	list* ptr,*temp;
	ptr=&hash_list[i];
	temp = new list();
	temp->client_id=id;
	temp->phone_no=num;
	if(ptr->next==NULL)
		ptr->next=temp;
	else
	{
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=temp;
	}
}
void hashing::display()
{

	cout<<"\n\nThe record in hash table are : ";
	cout<<"\n\nSr No.\t\t\t\t[CLIENT ID,PHONE NO.] \n";
	list* ptr;
	for(int i=0;i<10;i++)
	{
		ptr=&hash_list[i];
		cout<<i<<"\t\t\t\t";
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
			cout<<"[ "<<ptr->client_id<<" ,"<<ptr->phone_no<<" ]  ";
		}
		cout<<endl;
	}
}

void hashing::search_id()
{
 int key,i=0,flag=0;
 cout<<"\nEnter client ID to be searched : ";
 cin>>key;
 i = key%10;
 list *ptr;
 ptr=&hash_list[i];
 while(ptr!=NULL)
 {
	 if(ptr->client_id==key)
	 {
		 flag=1;
		 cout<<"\n\tRecord FOUND !!";
			cout<<"\n\nCLIENT ID :\t\t\tCLIENT PHONE NO. :\n";
			cout<<ptr->client_id<<"\t\t\t\t"<<ptr->phone_no<<endl;
		 break;
	 }
	 ptr=ptr->next;
 }
 if(flag==0)
	 cout<<"Record NOT found !!";

}
void hashing::search_phone_no()
{
 int key,i=0,flag=0;
 cout<<"\nEnter phone no. to be searched : ";
 cin>>key;
 list *ptr;
 for(int i=0;i<10;i++)
 {
	 ptr=&hash_list[i];
	 while(ptr!=NULL)
	 {
		 if(ptr->phone_no==key)
		 {
			 flag=1;
			 cout<<"\n\tRecord FOUND !!";
			cout<<"\n\nCLIENT ID :\t\t\tCLIENT PHONE NO. :\n";
			cout<<ptr->client_id<<"\t\t\t\t"<<ptr->phone_no<<endl;
			break;
		 }
	 ptr=ptr->next;
	 }
  }
 if(flag==0)
	 cout<<"Record NOT found !!";
}
int main() {
	cout<<"\t THIS PROGRAM IS TO PERFORM THE SET OPERATIONS ON THE STUDENT DATA"<<endl;
	int n=0,x=0;
	hashing h;
	char choice;
	cout<<"\n===========================================================================";
//DO-WHILE STARTS
    do{
	cout<<"\n\n***************************** MENU *****************************"<<endl<<"Press"<<endl;
	cout<<"\n\t1. Create";
	cout<<"\n\t2. Display ";
	cout<<"\n\t3. Insert";
	cout<<"\n\t4. Search";
	cout<<"\nCHOICE: ";
		cin>>n;
//SWITCH CASE STARTS
    switch(n)
	{
	 case 1:
		 h.create();
		break;
	 case 2:
		 h.display();
		 break;
	 case 3:
		 h.create();
		break;
	 case 4:
		 cout<<"\n\t1.ID\t\t2.Phone No. ?\t";
		 cin>>x;
		 if(x==1)
			 h.search_id();
		 else
			 h.search_phone_no();
		break;
	 case 5:
		break;
	default:
	        cout<<"Invalid choice"<<endl;
	}//SWITCH CASE ENDS
		cout<<"\n===========================================================================";
		cout<<"\nDo you want to continue (y/n)?\t";
		cin>>choice;
		cout<<"===========================================================================\n";
  }while(choice=='y' || choice=='Y');
//DO-WHILE ENDS
	cout<<endl;
	return 0;
}
//PROGRAM ENDS

//----------------------------->> OUTPUT <<------------------------------
/*
	 THIS PROGRAM IS TO PERFORM THE SET OPERATIONS ON THE STUDENT DATA

===========================================================================

***************************** MENU *****************************
Press

	1. Create
	2. Display
	3. Insert
	4. Search
CHOICE: 1

Enter client id : 23

Enter client phone no. : 123456

Enter another record (y/n) ?	y

Enter client id : 10

Enter client phone no. : 5464647

Enter another record (y/n) ?	y

Enter client id : 25

Enter client phone no. : 5468786

Enter another record (y/n) ?	y

Enter client id : 63

Enter client phone no. : 898988

Enter another record (y/n) ?	y

Enter client id : 5

Enter client phone no. : 5467787

Enter another record (y/n) ?	y

Enter client id : 28

Enter client phone no. : 646464

Enter another record (y/n) ?	y

Enter client id : 83

Enter client phone no. : 2497444

Enter another record (y/n) ?	y

Enter client id : 16

Enter client phone no. : 2034566

Enter another record (y/n) ?	n

===========================================================================
Do you want to continue (y/n)?	y
===========================================================================


***************************** MENU *****************************
Press

	1. Create
	2. Display
	3. Insert
	4. Search
CHOICE: 2


The record in hash table are :

Sr No.				[CLIENT ID,PHONE NO.]
0				[ 10 ,5464647 ]
1
2
3				[ 23 ,123456 ]  [ 63 ,898988 ]  [ 83 ,2497444 ]
4
5				[ 25 ,5468786 ]  [ 5 ,5467787 ]
6				[ 16 ,2034566 ]
7
8				[ 28 ,646464 ]
9

===========================================================================
Do you want to continue (y/n)?	y
===========================================================================


***************************** MENU *****************************
Press

	1. Create
	2. Display
	3. Insert
	4. Search
CHOICE: 3

Enter client id : 1

Enter client phone no. : 1111111

Enter another record (y/n) ?	y

Enter client id : 45

Enter client phone no. : 5555555

Enter another record (y/n) ?	n

===========================================================================
Do you want to continue (y/n)?	y
===========================================================================


***************************** MENU *****************************
Press

	1. Create
	2. Display
	3. Insert
	4. Search
CHOICE: 2


The record in hash table are :

Sr No.				[CLIENT ID,PHONE NO.]
0				[ 10 ,5464647 ]
1				[ 1 ,1111111 ]
2
3				[ 23 ,123456 ]  [ 63 ,898988 ]  [ 83 ,2497444 ]
4
5				[ 25 ,5468786 ]  [ 5 ,5467787 ]  [ 45 ,5555555 ]
6				[ 16 ,2034566 ]
7
8				[ 28 ,646464 ]
9

===========================================================================
Do you want to continue (y/n)?	y
===========================================================================


***************************** MENU *****************************
Press

	1. Create
	2. Display
	3. Insert
	4. Search
CHOICE: 4

	1.ID		2.Phone No. ?	1

Enter client ID to be searched : 63

	Record FOUND !!

CLIENT ID :			CLIENT PHONE NO. :
63				898988

===========================================================================
Do you want to continue (y/n)?	y
===========================================================================


***************************** MENU *****************************
Press

	1. Create
	2. Display
	3. Insert
	4. Search
CHOICE: 4

	1.ID		2.Phone No. ?	2

Enter phone no. to be searched : 2497444

	Record FOUND !!

CLIENT ID :			CLIENT PHONE NO. :
83				2497444

===========================================================================
Do you want to continue (y/n)?	y
===========================================================================


***************************** MENU *****************************
Press

	1. Create
	2. Display
	3. Insert
	4. Search
CHOICE: 4

	1.ID		2.Phone No. ?	1

Enter client ID to be searched : 55
Record NOT found !!
===========================================================================
Do you want to continue (y/n)?	y
===========================================================================


***************************** MENU *****************************
Press

	1. Create
	2. Display
	3. Insert
	4. Search
CHOICE: 4

	1.ID		2.Phone No. ?	2

Enter phone no. to be searched : 249744
Record NOT found !!
===========================================================================
Do you want to continue (y/n)?	n
===========================================================================
 */
