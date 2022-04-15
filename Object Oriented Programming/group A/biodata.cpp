//============================================================================
// Name        : biodata.cpp
// Author      : Sneha Bandi
// Description : Biodata implementation using inheritance
//============================================================================

#include <iostream>
#include<string.h>
using namespace std;
//PERSONAL CLASS
class personal
{
 protected:			//members are inherited thus protected
	 char name[20];
	 char address[30];
	 int dob[3];
	 long long int contact_no;
	 char bld_grp[3];
	 char marital_status[10];

public:
	 personal();
	 personal(personal&);
	 void accept()			//ACCEPT FUNCTION OF PERSONAL CLASS 
	 {
	 	cout<<"\nEnter the name: ";
		cin.getline(name,20,'#');
	 	cout<<"\nEnter the address:";
		cin.getline(address,30,'#');
	 	cout<<"\nEnter the date of birth as dd/mm/yyyy:";
	 	for(int i=0;i<3;i++)
	 	cin>>dob[i];

	 	cout<<"\nEnter the blood group: ";
	 	cin>>bld_grp;
		cout<<"\nEnter marital status (married/unmarried): ";
		cin>>marital_status;
	 }
	 void display()			//DISPLAY FUNCTION OF PERSONAL CLASS 
	 {
	 	cout<<"\n\nName: "<<name;
	 	cout<<"\nAddress: "<<address;
	 	cout<<"\n\nDate of birth: ";
	 	for(int i=0;i<3;i++)
	 	{
	 	  cout<<"."<<dob[i];
	 	}
	 	cout<<"\n\nContact no:"<<contact_no;
	 	cout<<"\n\nBlood group: "<<bld_grp;
		cout<<"\n\nMarital status:"<<marital_status;
	 }

};

personal::personal()			//DEFAULT CONSTRUCTOR
{
	strcpy(name,"Default");
	strcpy(address,"Default");
	contact_no = 0;
	strcpy(bld_grp,"B+");
	strcpy(marital_status,"Unmarried");

}
personal::personal(personal& p)		//COPY CONSTRUCTOR
{
 strcpy(name,p.name);
 strcpy(address,p.address);
 for(int i=0;i<3;i++)
{
 dob[i] =p.dob[i];
}
 contact_no = p.contact_no;
 strcpy (bld_grp,p.bld_grp);
 strcpy (marital_status,p.marital_status);
}
//PROFESSIONAL CLASS
class professional
{
	int id;
	char dept[15];
	int experience;
public:
	void accept()			//ACCEPT FUNCTION OF PROFESSIONAL CLASS 
	{
		cout <<"\nEnter the employee ID: ";
		cin>>id;
		cout<<"\nEnter the department: ";
		cin>>dept;
		cout<<"\nEnter the experience (in years): ";
		cin>>experience;
	}
	void display()			//DISPLAY FUNCTION OF PROFESSIONAL CLASS 
	{
		cout <<"\n\nEmployee ID: "<<id;
		cout<<"\n\nDepartment: "<<dept;
		cout<<"\n\nExperience (in years): "<<experience<<" years";

	}
};
//ACADEMICS CLASS
class academics
{
	float HSC_per;
	float grad_per;
	float SSC_per;
public:
	void accept()					//ACCEPT FUNCTION OF ACADEMICS CLASS 
	{
		cout<<"\nEnter SSC percentage: ";
		cin>>SSC_per;
		cout<<"\nEnter HSC percentage: ";
		cin>>HSC_per;
		cout<<"\nEnter graduation percentage: ";
		cin>>grad_per;

	}
	void display()				//DISPLAY FUNCTION OF ACADEMICS CLASS 
	{
		cout<<"\n\nSSC percentage: "<<SSC_per;
		cout<<"\n\nHSC percentage:"<<HSC_per;
		cout<<"\n\nGraduation percentage:"<<grad_per;

	}
};
//BIODATA CLASS INHERITED FROM PERSONAL,PROFESSIONAL,ACADEMICS CLASS
class biodata:public personal,public professional,public academics
{
public:
	void accept()				//ACCEPT FUNCTION OF BIODATA CLASS 
	{
		cout<<"Enter the employee biodata";
		cout<<"\n\t\tPERSONAL DATA:";
		personal::accept();
		cout<<"\n\n\t\tPROFESSIONAL DATA:\n";
		professional::accept();
		cout<<"\n\n\t\tACADEMIC DATA:\n";
		academics::accept();

	}
	void display()			//DISPLAY FUNCTION OF BIODATA CLASS
	{
		cout<<"___________________________________________";
		cout<<"\n\nTHE EMPLOYEE BIODATA IS:\n";
		personal::display();
		professional::display();
		academics::display();
		cout<<"\n";
		cout<<"___________________________________________";
	}
};
int main()
{
	int n=0;
	char choice;
	biodata b;
	do{
	cout<<"********************* MENU *********************\n";
	cout<<"\nEnter your choice:\n\t1.Accept\n\t2.Display\n";
	cin>>n;
	switch(n)
	{
	case 1:
		b.accept();
		break;
	case 2:
		b.display();
		break;
	default:
		cout<<"\nEnter valid choice\n";
		break;
	}
	cout<<"\n===================================";
	cout<<"\nDo you want to continue (y/n)?  ";
	cin>>choice;
	cout<<"===================================\n";
	}while(choice=='y'||choice=='Y');
return 0;
}
//PROGRAM ENDS
//<-------------------------------------- OUTPUT ----------------------------------------->
/*
********************* MENU *********************

Enter your choice:
	1.Accept
	2.Display
1
Enter the employee biodata
		PERSONAL DATA:
Enter the name: Sneha Bandi#

Enter the address:Baya Karve Hostel Complex#

Enter the date of birth as dd/mm/yyyy:16	09	1997

Enter the blood group: B+

Enter marital status (married/unmarried): unmarried


		PROFESSIONAL DATA:

Enter the employee ID: 2401

Enter the department: Management

Enter the experience (in years): 6 


		ACADEMIC DATA:

Enter SSC percentage: 95

Enter HSC percentage: 91.40

Enter graduation percentage: 85.26

===================================
Do you want to continue (y/n)?  y
===================================
********************* MENU *********************

Enter your choice:
	1.Accept
	2.Display
2
___________________________________________

THE EMPLOYEE BIODATA IS:


Name		: Sneha Bandi

Address 	: Baya Karve Hostel Complex

Date of birth	: .16.9.1997

Contact no	: 8989064848

Blood group	: B+

Marital status	: unmarried

Employee ID	: 2401

Department	: Management

Experience 	: 6 years

SSC percentage	: 95

HSC percentage	: 91.4

Graduation percentage: 85.26
___________________________________________
===================================
Do you want to continue (y/n)?  n
===================================
*/
