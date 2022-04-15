//============================================================================
// Name        : files2.cpp
// Author      : Sneha Bandi
// Roll No.   : 2401
// Description : phone book creation;search name;search phone no.;modification;
//============================================================================
#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;
class person
{
//PUBLIC DATA MEMBERS:
public:
	 char name[30];
	 long long int phno;
	 static int count;
//PUBLIC MEMBER FUNCTIONS
	 void accept()
	 {
		cout<<"\tEnter the name              : ";
		cin>>name;
		cout<<"\tEnter the contact no        : ";
		cin>>phno;

	 }
	 void display()
	 {
	   cout<<"\t\t\t"<<name<<"\t\t"<<phno<<"\n";


	 }
};//CLASS ENDS
int main() {
	person p;
	fstream f;
	ifstream in;
	ofstream out;
	char name[30];
	char ans,ans1;
	int choice;
	int phno,pos,i,offset;
	do{
		cout<<"\n*********************** MENU ***********************\n";
		cout<<"Press:\n\t1.Write\n\t2.Read\n\t3.Search name by phone no.\n\t4.Search phone no. by name\n\t5.Update phone no.\nCHOICE: ";
		cin>>choice;
		switch(choice)
		{
		//WRITING INTO THE FILE
		case 1:
			do{							//DO-WHILE FOR ASKING FOR ENTRY OF MULTIPLE RECORDS
			p.accept();						//ACCEPT FUNCTION CALLED
			char ch;
			cin.get(ch);
			out.open("text.dat",ios::out|ios::app|ios::binary);	//APP AND BINARY MODE
			out.write((char*)&p,sizeof(p));
			out.close();
			cout<<"\tEnter another record (y/n)?  ";
			cin>>ans1;
			cout<<"\n\t<------------------------------------------->\n";
			}while(ans1=='y'||ans1=='Y');
			break;
		case 2:
			//DISPLAYING THE PHONE BOOK
			in.open("text.dat",ios::in|ios::binary);	//OPENING OF FILE
			cout<<"\n\t\t<----------------- PHONE BOOK --------------------->\n";	
			cout<<"\n\t\t\tNAME\t\tPHONE NO.\n";
			while(in.read((char*)&p,sizeof(p)))		//LOOP TILL FILE ENDS
				p.display();
			in.close();
			cout<<"\n\t\t<--------------------------------------------------->\n";
			break;
		case 3:
		       //SEARCHING NAME VIA PHONE NUMBER
			cout<<"\nEnter the phone no. to be searched : ";
			cin>>phno;
			f.open("text.dat",ios::in|ios::out|ios::ate|ios::binary);
			f.seekg(0,ios::beg);
			pos=-1;
			i=0;
			while(f.read((char*)&p,sizeof(p)))
			{
				if(phno==p.phno)			//MATCHING PHONE NUMBERS
				{
					pos=i;
					break;
				}
				i++;
			}
			//offset=pos*sizeof(p);
			f.seekp((pos)*sizeof(p));			//POINTER SET TO DETECTED LOCATION 
			in.read((char*)&p,sizeof(p));			//READING FROM DETECTED LOCATION
			cout<<"\tName:"<<p.name;
			f.close();
			break;
		case 4:
			cout<<"\nEnter the name to be searched: ";
			cin>>name;
			f.open("text.dat",ios::in|ios::out|ios::ate|ios::binary);
			f.seekg(0,ios::beg);
			pos=-1;
			i=0;
			while(f.read((char*)&p,sizeof(p)))
			{
			  if(strcmp(name,p.name)==0)			//MATCHING NAMES
			  {
			 	pos=i;
				break;
			  }
			  i++;
			}
			f.seekp(pos*sizeof(p));				//POINTER SET TO DETECTED LOCATION
			in.read((char*)&p,sizeof(p));			//READING FROM DETECTED LOCATION
			cout<<"\tPhone No. : "<<p.phno;
			f.close();
			break;
		case 5:
			cout<<"\nEnter the record name to be updated: ";
			cin>>name;
			f.open("text.dat",ios::in|ios::out|ios::ate|ios::binary);
			f.seekg(0,ios::beg);
			pos=-1;
			i=0;
			while(f.read((char*)&p,sizeof(p)))
			{
			  if(strcmp(name,p.name)==0)				//MATCHING NAMES
			  {
				pos=i;
				break;
			  }
			  i++;
			}
			f.seekp(pos*sizeof(p));					//POINTER SET TO DETECTED LOCATION
			in.read((char*)&p,sizeof(p));				//READING FROM DETECTED LOCATION
			cout<<"\nCurrent Phone No. is : "<<p.phno;
			cout<<"\nEnter new phone no: ";
			cin>>phno;						//ACCEPTING NEW PHONE NUMBER
			p.phno=phno;
			f.write((char*)&p,sizeof(p));				//WRITING NEW RECORD INTO THE FILE
			cout<<"\nRecord updated";
			f.seekg(0);						//DISPLAY OF RECORDS FROM THE BEGINNING OF THE FILE 
			cout<<"\n\t\t<----------------- PHONE BOOK --------------------->\n";
			cout<<"\n\t\t\tNAME\t\tPHONE NO.\n";
			while(f.read((char*)&p,sizeof(p)))
			p.display();
			f.close();
			cout<<"\n\t\t<--------------------------------------------------->\n";
			break;

		}
		  cout<<"\nDo you want to continue (y/n)?\t ";
		  cin>>ans;
		  cout<<"__________________________________________________\n";
	}while(ans=='y'||ans=='Y');
	return 0;
}

//<--------------------------OUTPUT---------------------------->
/*

*********************** MENU ***********************
Press:
	1.Write
	2.Read
	3.Search name by phone no.
	4.Search phone no. by name
	5.Update phone no.
CHOICE: 1
	Enter the name              : a
	Enter the contact no        : 1
	Enter another record (y/n)?  y

	<------------------------------------------->
	Enter the name              : b
	Enter the contact no        : 2
	Enter another record (y/n)?  y

	<------------------------------------------->
	Enter the name              : c
	Enter the contact no        : 3
	Enter another record (y/n)?  y

	<------------------------------------------->
	Enter the name              : d
	Enter the contact no        : 4
	Enter another record (y/n)?  y

	<------------------------------------------->
	Enter the name              : e
	Enter the contact no        : 5
	Enter another record (y/n)?  n

	<------------------------------------------->

Do you want to continue (y/n)?	 y
__________________________________________________

*********************** MENU ***********************
Press:
	1.Write
	2.Read
	3.Search name by phone no.
	4.Search phone no. by name
	5.Update phone no.
CHOICE: 2

		<----------------- PHONE BOOK --------------------->

			NAME		PHONE NO.
			a		1
			b		2
			c		3
			d		4
			e		5

		<--------------------------------------------------->

Do you want to continue (y/n)?	 y
__________________________________________________

*********************** MENU ***********************
Press:
	1.Write
	2.Read
	3.Search name by phone no.
	4.Search phone no. by name
	5.Update phone no.
CHOICE: 3

Enter the phone no. to be searched : 1
	Name:a
Do you want to continue (y/n)?	 y
__________________________________________________

*********************** MENU ***********************
Press:
	1.Write
	2.Read
	3.Search name by phone no.
	4.Search phone no. by name
	5.Update phone no.
CHOICE: 4

Enter the name to be searched: b
	Phone No. : 2
Do you want to continue (y/n)?	 y
__________________________________________________

*********************** MENU ***********************
Press:
	1.Write
	2.Read
	3.Search name by phone no.
	4.Search phone no. by name
	5.Update phone no.
CHOICE: 5

Enter the record name to be updated: c

Current Phone No. is : 3
Enter new phone no: 8989

Record updated
		<----------------- PHONE BOOK --------------------->

			NAME		PHONE NO.
			a		1
			b		2
			c		8989
			d		4
			e		5

		<--------------------------------------------------->

Do you want to continue (y/n)?	 n
__________________________________________________

*/
