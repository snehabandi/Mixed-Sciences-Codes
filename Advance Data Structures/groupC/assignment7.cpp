//============================================================================
// Name        : assignment7.cpp
// Author      : Sneha Bandi
// Roll No.    : 2401
// Copyright   : Your copyright notice
// Description : Symbol Table : Accept,Display,search,retrieve,delete,modify 
//============================================================================

#include <iostream>
#include<string.h>
#define MAX 15
using namespace std;
class array
{
friend class table;
char name[20];
char datatype[20];
char scope[20];
char value[10];
int line[10],l;
public:
};
class table
{
	array t[MAX];
public:
    static int cnt;
    static int count();
    void accept(int);
    void display(int);
    void display_all();
    void accept_all();
    void search();
    void retrieve();
    void modify();
    void insert();
    void delete_();

};

int table::cnt=0;
int table::count()
{
	cnt--;
	return cnt;
}
void table::accept(int i)		//ACCEPT DATA FOR SYMBOL TABLE
{
		int n;
		int x=0;
		x=i;
		cout<<"\nEntry no:-\t"<<x+1<<endl;
		cout<<"\nName : ";
		cin>>t[x].name;
		cout<<"\nDatatype : ";
		cin>>t[x].datatype;
		cout<<"\nValue : ";
		cin>>t[x].value;
		cout<<"\nScope : ";
		cin>>t[x].scope;
		cout<<"\nNumber of lines in which "<<t[x].name<<" is used : ";
		cin>>t[x].l;
		cout<<"\nLine numbers :\n ";
		for(int i=0;i<t[x].l;i++)
		{
			cin>>n;
			t[x].line[i]=n;
		}

}
void table::display(int i)
{
	cout<<"\t\tSR.NO\t\tNAME\t\tVALUE\t\tTYPE\t\tSCOPE\t\tLINE NO\n";
	cout<<"\t\t"<<i+1<<"\t\t"<<t[i].name<<"\t\t"<<t[i].value<<"\t\t"<<t[i].datatype<<"\t\t"<<t[i].scope<<"\t\t";

}
void table::accept_all()		//ACCEPT DATA FOR SYMBOL TABLE
{
		int n;
		int x=0;
		char ans;
		do
		{
		cout<<"\nEntry no:-\t"<<x+1<<endl;
		cout<<"\nName : ";
		cin>>t[x].name;
		cout<<"\nDatatype : ";
		cin>>t[x].datatype;
		cout<<"\nValue : ";
		cin>>t[x].value;
		cout<<"\nScope : ";
		cin>>t[x].scope;
		cout<<"\nNumber of lines in which "<<t[x].name<<" is used : ";
		cin>>t[x].l;
		cout<<"\nLine numbers :\n ";
		for(int i=0;i<t[x].l;i++)
		{
			cin>>n;
			t[x].line[i]=n;
		}
		x++;
		table::cnt++;

		cout<<"\nDo you want to enter another data (y/n) ?\t";
		cin>>ans;
		}while(ans=='y'||ans=='Y');

}
void table::display_all()			//DISPLAY OF SYMBOL TABLE
{		cout<<"\nSYMBOL TABLE IS\n\n";
cout<<"\t\tSR.NO\t\tNAME\t\tVALUE\t\tTYPE\t\tSCOPE\t\tLINE NO\n";
cout<<endl;
for(int x=0;x<table::cnt;x++)
{
	cout<<"\t\t"<<x+1;
	cout<<"\t\t"<<t[x].name<<"\t\t"<<t[x].value<<"\t\t"<<t[x].datatype<<"\t\t"<<t[x].scope<<"\t\t";
	cout<<"[ ";
	cout<<t[x].line[0];
	for(int i=1;i<t[x].l;i++)
	{
		cout<<","<<t[x].line[i];
	}
	cout<<" ]";
	cout<<endl;
}
}
void table::search()
{
	int flag=0;
	char n[20];
	cout<<"\nEnter the name of the variable to be searched : ";
	cin>>n;
	for(int i=0;i<table::cnt;i++)
	{
		if(strcmp(t[i].name,n)==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"\nVariable does NOT exist !!\n";
	}
	else
		cout<<"\nvariable "<<n<<" exists !!";
}
void table::retrieve()
{
	int flag=0;
	char n[20];
	int i;
	cout<<"\nEnter the variable whose record is to be searched : ";
	cin>>n;
	for(i=0;i<table::cnt;i++)
	{
		if(strcmp(t[i].name,n)==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"\nVariable does NOT exist !!";
	}
	else
	{
		cout<<"\nVariable exists\n\n";
		display(i);

	}
}
void table::modify()
{
	int i=0;			//MODIFY A VARIABLE
	int flag=0;
	char n[20];
	cout<<"\nEnter the variable to be modified\t";
	cin>>n;
	for(i=0;i<table::cnt;i++)
	{
		if(strcmp(t[i].name,n)==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"\nVariable does NOT exist !!";
	}
	else
	{
		cout<<"\nRequired variable exists";
		cout<<"\nEnter the new values\n";
		accept(i);
	}
}
void table::insert()
{
	int pos,no,temp;
		cout<<"\nEnter POSITION to be inserted\n";
		cin>>pos;
		table::cnt++;
		pos=pos-1;
		for(int i=table::cnt;i>=pos;i--)
		{
			temp=pos;
			t[i+1]=t[i];
		}
		accept(temp);
}
void table::delete_()
{
	int pos,no,temp;
	int ct;
	cout<<"\nenter POSITION to be deleted\n";
	cin>>pos;
	pos=pos-1;
	for(int i=pos;i<table::cnt;i++)
	{
		temp=pos;
		t[i]=t[i+1];
	}
	cout<<"\nTHE RECORD IS DELETED\n";
	ct=table::count();
	cout<<"\nnumber of enteries remaining \t"<<ct;
}
int main()
{

	int ch;
	char answer;
	table s;
	do						//DO-WHILE LOOP
	{
	cout<<"\n\t\t\t\tMENU\nPRESS :";
	cout<<"\n\t1.Accept data";
	cout<<"\n\t2.Display data";
	cout<<"\n\t3.Search for the variable";
	cout<<"\n\t4.Search and retrieve data of the varaible";
	cout<<"\n\t5.Modify the data of a variable";
	cout<<"\n\t6.Insert a variable";
	cout<<"\n\t7.Delete a variable";
	cout<<"\nCHOICE : ";
	cin>>ch;
	switch(ch)			//SWITCH CASE
	{
	case 1:				//ENTRY IN SYMBOL TABLE
		s.accept_all();
		break;
	case 2:					//DISPLAY OF SYMBOL TABLE
		s.display_all();
		break;
	case 3:				//CHECK IF A VARIABLE EXISTS
		s.search();
		break;
	case 4:				//CHECK AND RETRIVE A VARIABLE
		s.retrieve();
		break;
	case 5:
		s.modify();
		break;
	case 6:					//INSERT A VARIABLE
		s.insert();
		break;
	case 7:					//DELETE A VARIABLE
		s.delete_();
		break;
	default:
		cout<<"\nEnter valid input !!!\n";
		break;

	}							//END OF SWITCH CASE
	cout<<"\n=======================================================";
	cout<<"\nDo you want to continue (y/n) ?\t";
	cin>>answer;
	cout<<"\n=======================================================";
	}while(answer=='y' || answer=='Y');			//END OF DO WHILE LOOP

	return 0;
}
//----------------------------->> OUTPUT <<------------------------------
/*

				MENU
PRESS :
	1.Accept data
	2.Display data
	3.Search for the variable
	4.Search and retrieve data of the varaible
	5.Modify the data of a variable
	6.Insert a variable
	7.Delete a variable
CHOICE : 1

Entry no:-	1

Name : a

Datatype : int

Value : 4

Scope : local

Number of lines in which a is used : 3

Line numbers :
 1	2	3

=======================================================
Do you want to continue (y/n) ?	y

=======================================================
				MENU
PRESS :
	1.Accept data
	2.Display data
	3.Search for the variable
	4.Search and retrieve data of the variable
	5.Modify the data of a variable
	6.Insert a varaible
	7.Delete a variable
CHOICE : 1

Entry no:-	2

Name : b

Datatype : float

Value : 6

Scope : global

Number of lines in which b is used : 4

Line numbers :
 3	5	6	7

=======================================================
Do you want to continue (y/n) ?	y

=======================================================
				MENU
PRESS :
	1.Accept data
	2.Display data
	3.Search for the variable
	4.Search and retrieve data of the variable
	5.Modify the data of a variable
	6.Insert a variable
	7.Delete a variable
CHOICE : 2

SYMBOL TABLE IS

		SR.NO		NAME		VALUE		TYPE		SCOPE		LINE NO

		1		a		4		int		local		[ 1,2,3 ]
		2		b		6		float		global		[ 3,5,6,7 ]

=======================================================
Do you want to continue (y/n) ?	y

=======================================================
				MENU
PRESS :
	1.Accept data
	2.Display data
	3.Search for the variable
	4.Search and retrieve data of the variable
	5.Modify the data of a variable
	6.Insert a varaible
	7.Delete a variable
CHOICE : 3

Enter the name of the variable to be searched : a

variable a exists !!
=======================================================
Do you want to continue (y/n) ?	y

=======================================================
				MENU
PRESS :
	1.Accept data
	2.Display data
	3.Search for the variable
	4.Search and retrieve data of the variable
	5.Modify the data of a variable
	6.Insert a variable
	7.Delete a variable
CHOICE : 3

Enter the name of the variable to be searched : c

Variable does NOT exist !!

=======================================================
Do you want to continue (y/n) ?	y

=======================================================
				MENU
PRESS :
	1.Accept data
	2.Display data
	3.Search for the variable
	4.Search and retrieve data of the variable
	5.Modify the data of a variable
	6.Insert a variable
	7.Delete a variable
CHOICE : 4

Enter the variable whose record is to be searched : b

Variable exists

		SR.NO		NAME		VALUE		TYPE		SCOPE		LINE NO
		2		b		6		float		global		[ 3,5,6,7 ]

=======================================================
Do you want to continue (y/n) ?	y

=======================================================
				MENU
PRESS :
	1.Accept data
	2.Display data
	3.Search for the variable
	4.Search and retrieve data of the variable
	5.Modify the data of a variable
	6.Insert a variable
	7.Delete a variable
CHOICE : 5

Enter the variable to be modified	b

Required variable exists
Enter the new values

Name : c

Datatype : char

Value : 2

Scope : local

Number of lines in which c is used : 2

Line numbers :
 2	4

=======================================================
Do you want to continue (y/n) ?	y

=======================================================
				MENU
PRESS :
	1.Accept data
	2.Display data
	3.Search for the variable
	4.Search and retrieve data of the variable
	5.Modify the data of a variable
	6.Insert a variable
	7.Delete a variable
CHOICE : 2

SYMBOL TABLE IS

		SR.NO		NAME		VALUE		TYPE		SCOPE		LINE NO

		1		a		4		int		local		[ 1,2,3 ]
		2		c		2		char		local		[ 2,4 ]

=======================================================
Do you want to continue (y/n) ?	y

=======================================================
				MENU
PRESS :
	1.Accept data
	2.Display data
	3.Search for the variable
	4.Search and retrieve data of the variable
	5.Modify the data of a variable
	6.Insert a variable
	7.Delete a variable
CHOICE : 6

Enter POSITION to be inserted
2

Name : d

Datatype : double

Value : 7

Scope : global

Number of lines in which d is used : 3

Line numbers :
 5	6	8

=======================================================
Do you want to continue (y/n) ?	y

=======================================================
				MENU
PRESS :
	1.Accept data
	2.Display data
	3.Search for the variable
	4.Search and retrieve data of the varaible
	5.Modify the data of a variable
	6.Insert a varaible
	7.Delete a variable
CHOICE : 2

SYMBOL TABLE IS

		SR.NO		NAME		VALUE		TYPE		SCOPE		LINE NO

		1		a		4		int		local		[ 1,2,3 ]
		2		d		7		double		global		[ 5,6,8 ]
		3		c		2		char		local		[ 2,4 ]

=======================================================
Do you want to continue (y/n) ?	y

=======================================================
				MENU
PRESS :
	1.Accept data
	2.Display data
	3.Search for the variable
	4.Search and retrieve data of the varaible
	5.Modify the data of a variable
	6.Insert a varaible
	7.Delete a variable
CHOICE : 7

enter POSITION to be deleted
2

THE RECORD IS DELETED

number of enteries remaining 	2
=======================================================
Do you want to continue (y/n) ?	y

=======================================================
				MENU
PRESS :
	1.Accept data
	2.Display data
	3.Search for the variable
	4.Search and retrieve data of the varaible
	5.Modify the data of a variable
	6.Insert a varaible
	7.Delete a variable
CHOICE : 2

SYMBOL TABLE IS

		SR.NO		NAME		VALUE		TYPE		SCOPE		LINE NO

		1		a		4		int		local		[ 1,2,3 ]
		2		c		2		char		local		[ 2,4 ]

=======================================================
Do you want to continue (y/n) ?	n

=======================================================
 */
