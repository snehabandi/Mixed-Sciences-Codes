//============================================================================
// Name        : assignement1.cpp
// Author      : Sneha Bandi
// Copyright   : Your copyright notice
// Description : Set Operations: accept,display,union,intersection,difference,none,
//============================================================================
#include <iostream>
using namespace std;
class set
{
        int cricket[20];
        int badminton[20];
        int result[20];
        int universal[40];
        int countc;
        int countb;
        int countr;
        int countu;

public:
        void accept();
        void display();
        void intersect();
        void union_set();
        void difference_cb();
        void difference_bc();
        void none_bc();
        void display_result();
};
void set::accept()											//Accept Function
{
        cout<<"Enter the no. of students playing cricket : ";
        cin>>countc;
        cout<<"Enter the no. of students playing badminton : ";
        cin>>countb;
        cout<<"Enter the roll no. of students playing cricket"<<endl;
        for(int i=0;i<countc;i++)
        {
                cin>>cricket[i];
//validation code cricket array acceptance
                int valid=cricket[i];
                for(int j=0;j<i;j++)
                     {
                        if(valid==cricket[j])
                         {
                        	cout<<"Donot enter same numbers"<<endl;
                        	i--;					//*remember i--; as same value occupied at i(now):overwrite it
                                break;
                         }
                      }
        }
 		cout<<endl;
        cout<<"Enter the roll no. of students playing badminton"<<endl;
        for(int i=0;i<countb;i++)
                {
                        cin>>badminton[i];
//validation code badminton array acceptance
                int valid=badminton[i];
                for(int j=0;j<i;j++)
                	{
                       if(valid==badminton[j])
                         {
                           cout<<"Donot enter same numbers"<<endl;
                        	i--;					//*remember i--; as same value occupied at i(now):overwrite it
                                   break;
                         }
                    }
                }
                        cout<<endl;
}
void set::display()											//Display Function
{
        cout<<"Entered roll no.s of students playing cricket are :\n\t{ ";
        for(int i=0;i<countc;i++)
        {
                cout<<cricket[i];
		if(i!=(countc-1))
                cout<<" , ";
        }
	cout<<"}\n";
        cout<<"Entered roll no.s of students playing badminton :\n\t{";
        for(int i=0;i<countb;i++)
                {
                        cout<<badminton[i];
		  if(i!=(countb-1))
                        cout<<" , ";
                }
        cout<<"}\n";
}
void set::intersect()									//Intersection Function
{
	        countr=0;
        cout<<"The intersection of students playing cricket and badminton is"<<endl;
        for(int i=0;i<countc;i++)
        {
                int flag=0;
                for(int j=0;j<countb;j++)
                {
                        if(cricket[i]==badminton[j])
                        {
                                flag=1;
                                break;
                        }
                }
                if(flag==1)
                {
                  result[countr]=cricket[i];
                  countr++;
                }
        }
}
void set::union_set()									//Union Function
{
        countr=0;
        cout<<"The union of students playing cricket and badminton is"<<endl;
        for(int i=0;i<countc;i++)
                {
                        result[countr]=cricket[i];
                        countr++;
                }
        for(int i=0;i<countb;i++)
        {
                int flag=0;
                for(int j=0;j<countc;j++)
                {
                        if(cricket[j]==badminton[i])
                        {
                                flag=1;
                                break;
                        }
                }
                if(flag==0)
                {
                  result[countr]=badminton[i];
                  countr++;
                }
        }
}
void set::difference_cb()								//Difference(C-B) Function
{
        countr=0;
        cout<<"The roll no's of students playing only cricket are"<<endl;
        for(int i=0;i<countc;i++)
        {
                int flag=0;
                for(int j=0;j<countb;j++)
                {
                        if(cricket[i]==badminton[j])
                        {
                                flag=1;
                                break;
                        }
                }
                if(flag==0)
                {
                  result[countr]=cricket[i];
                  countr++;
                }
        }
}
void set::difference_bc()								//Difference(B-C) Function
{
        countr=0;
        cout<<"The roll no's of students playing only badminton are"<<endl;
        for(int i=0;i<countb;i++)
        {
                int flag=0;
                for(int j=0;j<countc;j++)
                {
                        if(badminton[i]==cricket[j])
                        {
                                flag=1;
                                break;
                        }
                }
                if(flag==0)
                {
                   result[countr]=badminton[i];
                   countr++;
                }
        }
}
void set::none_bc()									//none_bc(function: none of the games played)
{
	countr=0;
	countu=0;
	int res=0;
	cout<<"Enter the total no. of students in the class"<<endl;
	cin>>countu;
	cout<<"Enter the roll no. of all the students"<<endl;

	for(int i=0;i<countu;i++)
	{
		cin>>universal[i];
		cout<<"\t";
//validation code for universal array acceptance
                int valid=universal[i];
                for(int j=0;j<i;j++)
                     {
                        if(valid==universal[j])
                         {
                        	cout<<"Donot enter same numbers"<<endl;
                                break;
                         }
                      }

	}
	cout<<"\n";
	union_set();
	display_result();
	cout<<"\n";
	res= countu-countr;
	cout<<"The no. of students playing neither of the games is:"<<res<<endl;
}

void set::display_result()								//Display_result function:to display results
{
	cout<<"{";
	 for(int i=0;i<countr;i++)
		{
	                cout<<result[i];
			if(i!=(countr-1))
	        	cout<<" , ";
		}
		cout<<"}\n";
}
//MAIN
int main()
{
	cout<<"\t THIS PROGRAM IS TO PERFORM THE SET OPERATIONS ON THE STUDENT DATA"<<endl;
	int n=0;
	char choice;
	set s;		//Object creation
	s.accept();
	s.display();
		cout<<"\n===========================================================================";
//DO-WHILE STARTS
    do{
	cout<<"\n\n***************************** MENU *****************************"<<endl<<"Press"<<endl;
	cout<<"\n\t1 for students playing both cricket and badminton both";
	cout<<"\n\t2 for students playing either cricket or badminton or both ";
	cout<<"\n\t3 for students playing only cricket";
	cout<<"\n\t4 for students playing only badminton";
	cout<<"\n\t5 for no. of students who donot play any of the games"<<endl<<"CHOICE: ";
		cin>>n;
//SWITCH CASE STARTS
    switch(n)
	{
	 case 1:
		s.intersect();
        s.display_result();
		break;
	 case 2:
		s.union_set();
        s.display_result();
		break;
	 case 3:
		s.difference_cb();
		s.display_result();
		break;
	 case 4:
		s.difference_bc();
		s.display_result();
		break;
	 case 5:
		s.none_bc();
		break;
	 default:
	        cout<<"Invalid choice"<<endl;
	}//SWITCH CASE ENDS

		cout<<endl<<"Do you want to continue (y/n)?\t";
		cin>>choice;
		cout<<"\n===========================================================================";
  }while(choice=='y' || choice=='Y');
//DO-WHILE ENDS
	cout<<endl;
	return 0;
}
//PROGRAM ENDS

//------------------------------------------------ OUTPUT ------------------------------------------------

/*
	 THIS PROGRAM IS TO PERFORM THE SET OPERATIONS ON THE STUDENT DATA
Enter the no. of students playing cricket : 7
Enter the no. of students playing badminton : 5
Enter the roll no. of students playing cricket
1	2	4	6	7	11	14

Enter the roll no. of students playing badminton
2	3	5       7       8

Entered roll no.s of students playing cricket are :
	{ 1 , 2 , 4 , 6 , 7 , 11 , 14}
Entered roll no.s of students playing badminton :
	{2 , 3 , 5 , 7 , 8}

===========================================================================

***************************** MENU *****************************
Press

	1 for students playing both cricket and badminton both
	2 for students playing either cricket or badminton or both 
	3 for students playing only cricket
	4 for students playing only badminton
	5 for no. of students who donot play any of the games
CHOICE: 1
The intersection of students playing cricket and badminton is
{2 , 7}

Do you want to continue (y/n)?	y

===========================================================================

***************************** MENU *****************************
Press

	1 for students playing both cricket and badminton both
	2 for students playing either cricket or badminton or both 
	3 for students playing only cricket
	4 for students playing only badminton
	5 for no. of students who donot play any of the games
CHOICE: 2
The union of students playing cricket and badminton is
{1 , 2 , 4 , 6 , 7 , 11 , 14 , 3 , 5 , 8 }

Do you want to continue (y/n)?	y

===========================================================================

***************************** MENU *****************************
Press

	1 for students playing both cricket and badminton both
	2 for students playing either cricket or badminton or both 
	3 for students playing only cricket
	4 for students playing only badminton
	5 for no. of students who donot play any of the games
CHOICE: 3
The roll no's of students playing only cricket are
{1 , 4 , 6 , 11 , 14 }

Do you want to continue (y/n)?	y

===========================================================================

***************************** MENU *****************************
Press

	1 for students playing both cricket and badminton both
	2 for students playing either cricket or badminton or both 
	3 for students playing only cricket
	4 for students playing only badminton
	5 for no. of students who donot play any of the games
CHOICE: 4
The roll no's of students playing only badminton are
{3 , 5 , 8 }

Do you want to continue (y/n)?	y

===========================================================================

***************************** MENU *****************************
Press

	1 for students playing both cricket and badminton both
	2 for students playing either cricket or badminton or both 
	3 for students playing only cricket
	4 for students playing only badminton
	5 for no. of students who donot play any of the games
CHOICE: 5
Enter the total no. of students in the class
15
Enter the roll no. of all the students
1	2	3	4	5	6	7	8	9	10	11	12	13	14	15
															
The union of students playing cricket and badminton is
{1 , 2 , 4 , 6 , 7 , 11 , 14 , 3 , 5 , 8 }

The no. of students playing neither of the games is:5

Do you want to continue (y/n)?	n

===========================================================================

//***************************** TEST CASE: REPETITION OF ROLL NUMBERS *****************************
Enter the no. of students playing cricket : 4
Enter the no. of students playing badminton : 3
Enter the roll no. of students playing cricket
1
1
Donot enter same numbers
2
3
4

Enter the roll no. of students playing badminton
5
6
7

Entered roll no.s of students playing cricket are :
	{ 1 , 2 , 3 , 4}
Entered roll no.s of students playing badminton :
	{2 , 3 , 4}


*/
