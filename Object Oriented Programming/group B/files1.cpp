//============================================================================
// Name        : files.cpp
// Author      : Sneha Bandi
// Roll No.    : 2401
// Description : File operations on student data:
//			create a file,store data in it and acces the data!
//============================================================================

#include<iostream>
#include<fstream>
#include<string.h>
//FOR STRCPY IN CONSTRUCTOR
using namespace std;
class student
{
//PRIVATE DATA MEMBERS:
	 char name[30];
	 int roll;
	 char s_class[3];
	 char div;
	 int dob[3];
	 char bld_grp[3];
	 long long int contact_no;
	 static int count;
//PUBLIC MEMBER FUNCTIONS
public:
	 student();
	 void accept();
	 void display();
	 void create();
	 void read();
};//CLASS ENDS

//SETTING STATIC COUNTER TO ZERO!
//NOTE:DONE OUTSIDE CLASS AS STATIC COUNTERS CANNOT BE INITIALIZED INSIDE THE CLASS!!!
int student::count=0;

//DEFAULT CONSTRUCTOR: TO INTITIALIZE ALL 'FIELD' WITH DEFAULT VALUES
student::student()
{
	strcpy(name,"Default");
	roll = 0;
	strcpy(s_class,"FE");
	div = 'A';
	for(int i=0;i<3;i++)
	dob[i]=0;
	strcpy(bld_grp,"B+");
	contact_no = 1;


}

//ACCEPT FUNCTION: TO ACCEPT RECORDS FROM USER THROUGH 'CONSOLE'
void student::accept()
{
	cout<<"\tEnter the name              : ";
	cin>>name;
	cout<<"\tEnter the roll no           : ";
	cin>>roll;
	cout<<"\tEnter the class             : ";
	cin>>s_class;
	cout<<"\tEnter the division          : ";
	cin>>div;
	cout<<"\tEnter the DOB as dd/mm/yyyy : ";
	for(int i=0;i<3;i++)
	cin>>dob[i];
	cout<<"\tEnter the blood group       : ";
	cin>>bld_grp;
	cout<<"\tEnter the contact no        : ";
	cin>>contact_no;
}

//DISPLAY FUNCTION : TO DISPLAY ENTERED RECORDS ON 'CONSOLE'
void student::display()
{
	
	cout<<"\nName         : "<<name;
	cout<<"\nRoll No.     : "<<roll;
	cout<<"\nClass        : "<<s_class;
	cout<<"\nDivision     : "<<div;
	cout<<"\nDOB          : ";
	for(int i=0;i<3;i++)
	{
	  cout<<dob[i]<<".";
	}
	cout<<"\nBlood group  : "<<bld_grp;
	cout<<"\nContact no   : "<<contact_no;
}

//CREATE FUNCTION : TO INSERT RECORD INTO FILE! 
void student::create()
{
	char ch;
	student s;
	fstream f;
	f.open("student.txt",ios::out);					//OPENED IN WRITE MODE ONLY
	do{
			cout<<"================> ENTER RECORD "<<count<<": <==================\n\n";
		s.accept();									//ACCEPT FUNCTION IS CALLED
		f.seekp(count*sizeof(s),ios::beg);			//PUT POINTER SET COUNT*SIZEOF(S) BITS FROM BEGINING
		f.write((char*)&s,sizeof(s));
		count++;
		cout<<"\nDo you want to enter another record (y/n)?\t";
		cin>>ch;
		cout<<"__________________________________________________\n";
		
	}while(ch=='y'||ch=='Y');
f.close();											//CLOSING OF FILE
}//CREATE ENDS

//READ FUNCTION : TO READ RECORDS FROM FILE!
void student::read()
{
	char ch;
	student s;
	fstream f;
	cout<<"\n\t\tTHE ENTERED RECORD ARE:"<<endl;
	f.open("student.txt",ios::in);					//OPENED IN READ MODE ONLY
	for(int i=0;i<count;i++)
	{
		f.seekg(i*sizeof(s),ios::beg);
		f.read((char*)&s,sizeof(s));				//GET POINTER SET 'i'*SIZEOF(S) BITS FROM BEGINING
		cout<<"\n================> RECORD "<<i<<" <==================\n";
		s.display();								//DISPLAY FUNCTION IS CALLED
		cout<<"\n===================================================\n";
	}
f.close();											//CLOSING OF FILE
cout<<"\n";
}//READ ENDS

//MAIN FUNCTION
int main() {
student s1,s2;
char ans;
int choice;
	//DO-WHILE FOR MENU DRIVEN PROGRAM
	do
	{
		
		cout<<"\n//********************* MENU *********************//\n";	
		cout<<"\tPRESS:";
		cout<<"\n\t1. To print default values";
		cout<<"\n\t2. To insert records into file";
		cout<<"\n\t3. To read records from file\nCHOICE: ";
		cin>>choice;
		cout<<"__________________________________________________\n\n";
	//SWITCH CASE I STARTS
	switch(choice)
	{
	 case 1:
	 		s1.display();
	 		break;
	 case 2:
	 		s2.create();
	 		break;
	 case 3:
	 		s2.read();
	 		break;
	 default:
	 		cout<<"\nENTER VALID CHOICE!\n";
	 		break;
	 }
	 //SWITCH CASE ENDS
	  cout<<"\n__________________________________________________";
	  cout<<"\nDo you want to continue (y/n)?\t ";
	  cin>>ans;
	  cout<<"__________________________________________________\n";
	}while(ans=='Y'||ans=='y');
	//D0-WHILE LOOP ENDS
	return 0;
}
//PROGRAM ENDS
//<--------------------------------- OUTPUT --------------------------------------->
/*
********************* MENU *********************
	PRESS:
	1. To print default values
	2. To insert records into file
	3. To read records from file
CHOICE: 1
__________________________________________________


Name         : Default
Roll No.     : 0
Class        : FE
Division     : A
DOB          : 0.0.0.
Blood group  : B+
Contact no   : 1
__________________________________________________
Do you want to continue (y/n)?	 y
__________________________________________________

********************* MENU *********************
	PRESS:
	1. To print default values
	2. To insert records into file
	3. To read records from file
CHOICE: 2
__________________________________________________

================> ENTER RECORD 0: <==================

	Enter the name              : Sneha
	Enter the roll no           : 2401
	Enter the class             : SE
	Enter the division          : B
	Enter the DOB as dd/mm/yyyy : 16	09	1997
	Enter the blood group       : B+
	Enter the contact no        : 8989064848

Do you want to enter another record (y/n)?	y
__________________________________________________
================> ENTER RECORD 1: <==================

	Enter the name              : Saloni
	Enter the roll no           : 2444
	Enter the class             : SE
	Enter the division          : B
	Enter the DOB as dd/mm/yyyy : 15	03	1997
	Enter the blood group       : B+
	Enter the contact no        : 7898565650  

Do you want to enter another record (y/n)?	y
__________________________________________________
================> ENTER RECORD 2: <==================

	Enter the name              : Shambhavi
	Enter the roll no           : 2449
	Enter the class             : SE
	Enter the division          : D
	Enter the DOB as dd/mm/yyyy : 07	07	1997
	Enter the blood group       : A-
	Enter the contact no        : 8945456464 

Do you want to enter another record (y/n)?	n
__________________________________________________

__________________________________________________
Do you want to continue (y/n)?	 y
__________________________________________________

********************* MENU *********************
	PRESS:
	1. To print default values
	2. To insert records into file
	3. To read records from file
CHOICE: 3
__________________________________________________


		THE ENTERED RECORD ARE:

================> RECORD 0 <==================

Name         : Sneha
Roll No.     : 2401
Class        : SE
Division     : B
DOB          : 16.9.1997.
Blood group  : B+
Contact no   : 8989064848
===================================================

================> RECORD 1 <==================

Name         : Saloni
Roll No.     : 2444
Class        : SE
Division     : B
DOB          : 15.3.1997.
Blood group  : B+
Contact no   : 7898565650
===================================================

================> RECORD 2 <==================

Name         : Shambhavi
Roll No.     : 2449
Class        : SE
Division     : D
DOB          : 7.7.1997.
Blood group  : A-
Contact no   : 8945456464
===================================================


__________________________________________________
Do you want to continue (y/n)?	 n
__________________________________________________

*/
