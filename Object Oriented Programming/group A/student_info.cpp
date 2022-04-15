//============================================================================
// Name        : student_info.cpp
// Author      : Sneha Bandi
// Roll No.    : 2401
// Description : Student database creation
//============================================================================

#include<iostream>
#include<string.h>
using namespace std;
class info
{
public:
	 char name[30];
	 int roll;
	 char s_class[3];
	 char div;
	 int dob[3];
	 char bld_grp[3];
	 long long int contact_no;
	 char address[60];
	 int driv_lic;
	 float ht,wt;
	 static int cnt;

	 info();		//DEFAULT CONSTRUCTOR
	 info(info &);		//COPY CONSTRUCTOR
	 void accept();
	 void display();
	 static int count();

};
info::info()			//DEFAULT CONSTRUCTOR DEFINITION
{
	strcpy(name,"Default");
	roll = 0;
	strcpy(s_class,"FE");
	div = 'A';
	strcpy(bld_grp,"B+");
	contact_no = 1;
	strcpy(address,"Default");
	driv_lic = 1;
	ht=0;
	wt=50;

}
info::info(info& p)		//COPY CONSTRUCTOR DEFINITION;OBJECT IS PASSED BY REFERENCE
{
 strcpy(name,p.name);
 roll = p.roll;
 strcpy(s_class,p.s_class);
 div =p.div;
 for(int i=0;i<3;i++)
{
 dob[i] =p.dob[i];
}
 strcpy (bld_grp,p.bld_grp);
 contact_no = p.contact_no;
 strcpy(address,p.address);
 driv_lic = p.driv_lic;
 ht=p.ht;
 wt=p.wt;

}
void info::accept()			//ACCEPTANCE OF STUDENT RECORD
{
	cout<<"\nEnter the name : ";
	 cin>>name;
	cout<<"\nEnter the roll no. : ";
	 cin>>roll;
	cout<<"\nEnter the class : ";
	 cin>>s_class;
	cout<<"\nEnter the division : ";
	cin>>div;
	cout<<"\nEnter the date of birth as dd/mm/yyyy : ";	//DATE STORED IN ARRAY
	for(int i=0;i<3;i++)
	cin>>dob[i];
	cout<<"\nEnter the blood group : ";
	cin>>bld_grp;
	cout<<"\nEnter the contact no : ";
	cin>>contact_no;
	cout<<"\nEnter the address : ";
	cin>>address;
	cout<<"\nEnter the driving licence number : ";
	cin>>driv_lic;
	cout<<"\nEnter the height in cm : ";
	cin>>ht;
	cout<<"\nEnter the weight in kg : ";
	cin>>wt;
}
void info::display()	//DISPLAYING RECORD USING THIS POINTER
{
	cout<<"\n\nTHE ENTERED RECORD IS:"<<endl;
	cout<<"\nName           : "<<this->name;
	cout<<"\nRoll no.       : "<<this->roll;
	cout<<"\nClass          : "<<s_class;
	cout<<"\nDivision       : "<<this->div;
	cout<<"\nDate of birth  : ";
	for(int i=0;i<3;i++)
	{
	  cout<<"."<<this->dob[i];
	}
	cout<<"\nBlood group    : "<<this->bld_grp;
	cout<<"\nContact no     : "<<this->contact_no;
	cout<<"\nAddress        : "<<this->address;
	cout<<"\nlicence number : "<<this->driv_lic;
	cout<<"\nHeight(cm)     : "<<this->ht;
	cout<<"\nWeight(kg)     : "<<this->wt;
	cout<<"\n\t___________________________________________\n";
}
int info::cnt=0;		//INITIALISATION OF STATIC MEMBER CNT
int info::count()
{
	cnt=cnt+1;
	return(cnt);
}
int main()			//MAIN
{
	int ch,ch1,n,pos,temp,flag=0;
	info o[50];
	char name[12];
	char ch2;
	cout<<"\n\t\t\tTHIS PROGRAM IS TO IMPLEMENT STUDENT DATABASE !!\n\n";
//DO-WHILE STARTS
	do
	{

			cout<<"\n\t\t\t******************** MENU ********************\n";
	cout<<"\t1. Accept\n";
	cout<<"\t2. Display\n";
	cout<<"\t3. Insert record\n";
	cout<<"\t4. Search\n";
	cout<<"\t5. Delete\n";
	cout<<"\t6. Exit\n";
	cout<<"\nCHOICE : ";
	cin>>ch;

	 switch(ch)
	 {
	//SWITCH CASE I STARTS
	 case 1:
		cout<<"\n\tMENU\n";
		cout<<"1. Inbuilt record\n";
		cout<<"2. New Record\n";
		cout<<"\nCHOICE : ";
		cin>>ch1;
		//SWITCH CASE II STARTS
		switch(ch1)
		{
		case 1:
				info a1(info o1);		//copy constructor
				cout<<"\n Default value is initialised !\n";
				n=info::count();
				break;
		case 2:
				o[n].accept();
				n=info::count();
				break;
		}
		break;
		//SWITCH CASE II ENDS
	  case 2:
		  for(int i=0;i<n;i++)
		  {
		   o[i].display();
		  }
		  break;
	  case 3:
		  cout<<"\n Enter the position to insert record\n";
		  cin>>pos;
		  n=info::count();
		  pos--;
		  for(int i=n;i>=pos;i--)
		  {
			 temp=pos;
			 o[i+1]=o[i];
		  }
		  o[temp].accept();
		  break;
	  case 4:
		  cout<<"Enter the name to be searched\n";
		  cin>>name;
		  for(int i=0;i<n;i++)
		  {
			  if(strcmp(name,o[i].name)==0)
			  {
				  flag=1;
				  o[i].display();
				  break;
			  }
		  }
		  if(flag==0)
			  cout<<"Record not found\n";

		  	  break;
			
	  case 5:
		  cout<<"\nEnter the position to delete record";
		  cin>>pos;
		pos--;
		  for(int i=pos;i<n;i++)
		  {
			 temp=pos;
			 o[i]=o[i+1];
		  }
		  cout<<"\nThe record is deleted";
		  n=info::cnt-1;
		  break;
	  case 6:
		break;

	   default:
		cout<<"\nEnter the valid choice\n";
		   break;

	 }
	//SWITCH CASE I ENDS
	if(ch!=6)
	{
	cout<<"\nDo you want to continue (y/n)?\t";
	cin>>ch2;
	}	
	}while(ch==6 || ch2=='y');
//DO-WHILE ENDS
	return 0;
}
//PROGRAM ENDS
//<-------------------------------------- OUTPUT ----------------------------------------->
/*
			THIS PROGRAM IS TO IMPLEMENT STUDENT DATABASE !!



			THIS PROGRAM IS TO IMPLEMENT STUNT DATABASE !!


			******************** MENU ********************
	1. Accept
	2. Display
	3. Insert record
	4. Search
	5. Delete
	6. Exit

CHOICE : 1

	MENU
1. Inbuilt record
2. New Record

CHOICE : 2    

Enter the name : Sneha

Enter the roll no. : 2401

Enter the class : SE

Enter the division : B

Enter the date of birth as dd/mm/yyyy : 16      09	1997

Enter the blood group : B+

Enter the contact no : 8989064848

Enter the address : BAYA_KARVE_HOSTEL_COMPLEX

Enter the driving licence number : 584646  

Enter the height in cm : 153

Enter the weight in kg : 55

Do you want to continue (y/n)?	y

			******************** MENU ********************
	1. Accept
	2. Display
	3. Insert record
	4. Search
	5. Delete
	6. Exit

CHOICE : 2


THE ENTERED RECORD IS:

Name           : Sneha
Roll no.       : 2401
Class          : SE
Division       : B
Date of birth  : .16.9.1997
Blood group    : B+
Contact no     : 8989064848
Address        : BAYA_KARVE_HOSTEL_COMPLEX
licence number : 584646
Height(cm)     : 153
Weight(kg)     : 55
	___________________________________________

Do you want to continue (y/n)?	y


			******************** MENU ********************
	1. Accept
	2. Display
	3. Insert record
	4. Search
	5. Delete
	6. Exit

CHOICE : 1

	MENU
1. Inbuilt record
2. New Record

CHOICE : 1

 Default value is initialised!

Do you want to continue (y/n)?	y

			******************** MENU ********************
	1. Accept
	2. Display
	3. Insert record
	4. Search
	5. Delete
	6. Exit

CHOICE : 2


THE ENTERED RECORD IS:

Name           : Sneha
Roll no.       : 2401
Class          : SE
Division       : B
Date of birth  : .16.9.1997
Blood group    : B+
Contact no     : 8989064848
Address        : BAYA_KARVE_HOSTEL_COMPLEX
licence number : 584646
Height(cm)     : 153
Weight(kg)     : 55
	___________________________________________


THE ENTERED RECORD IS:

Name           : Default
Roll no.       : 0
Class          : FE
Division       : A
Date of birth  : .0.0.0
Blood group    : B+
Contact no     : 1
Address        : Default
licence number : 1
Height(cm)     : 0
Weight(kg)     : 50
	___________________________________________

Do you want to continue (y/n)?	y

			******************** MENU ********************
	1. Accept
	2. Display
	3. Insert record
	4. Search
	5. Delete
	6. Exit

CHOICE : 3

 Enter the position to insert record
2

Enter the name : Saloni

Enter the roll no. : 2444

Enter the class : SE

Enter the division : B

Enter the date of birth as dd/mm/yyyy : 15	03	1997

Enter the blood group : A-

Enter the contact no : 7897987998

Enter the address : SAHELI_HOMES

Enter the driving licence number : 898468   

Enter the height in cm : 168

Enter the weight in kg : 55

Do you want to continue (y/n)?	y

			******************** MENU ********************
	1. Accept
	2. Display
	3. Insert record
	4. Search
	5. Delete
	6. Exit

CHOICE : 2


THE ENTERED RECORD IS:

Name           : Sneha
Roll no.       : 2401
Class          : SE
Division       : B
Date of birth  : .16.9.1997
Blood group    : B+
Contact no     : 8989064848
Address        : BAYA_KARVE_HOSTEL_COMPLEX
licence number : 8897894
Height(cm)     : 153
Weight(kg)     : 55
	___________________________________________


THE ENTERED RECORD IS:

Name           : Saloni
Roll no.       : 2444
Class          : SE
Division       : B
Date of birth  : .15.3.1997
Blood group    : A-
Contact no     : 7897987998
Address        : SAHELI_HOMES
licence number : 898468
Height(cm)     : 168
Weight(kg)     : 55
	___________________________________________

Do you want to continue (y/n)?	y

			******************** MENU ********************
	1. Accept
	2. Display
	3. Insert record
	4. Search
	5. Delete
	6. Exit

CHOICE : 4
Enter the name to be searched
Saloni


THE ENTERED RECORD IS:

Name           : Saloni
Roll no.       : 2444
Class          : SE
Division       : B
Date of birth  : .15.3.1997
Blood group    : A-
Contact no     : 7897987998
Address        : SAHELI_HOMES
licence number : 898468
Height(cm)     : 168
Weight(kg)     : 55
	___________________________________________

Do you want to continue (y/n)?	y

			******************** MENU ********************
	1. Accept
	2. Display
	3. Insert record
	4. Search
	5. Delete
	6. Exit

CHOICE : 5

Enter the position to delete record1

The record is deleted
Do you want to continue (y/n)?	y

			******************** MENU ********************
	1. Accept
	2. Display
	3. Insert record
	4. Search
	5. Delete
	6. Exit

CHOICE : 2


THE ENTERED RECORD IS:

Name           : Saloni
Roll no.       : 2444
Class          : SE
Division       : B
Date of birth  : .15.3.1997
Blood group    : A-
Contact no     : 7897987998
Address        : SAHELI_HOMES
licence number : 898468
Height(cm)     : 168
Weight(kg)     : 55
	___________________________________________

Do you want to continue (y/n)?	y

			******************** MENU ********************
	1. Accept
	2. Display
	3. Insert record
	4. Search
	5. Delete
	6. Exit

CHOICE : 6
*/
