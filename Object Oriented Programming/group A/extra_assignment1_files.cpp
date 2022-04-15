//============================================================================
// Name        : files.cpp
// Author      : Sneha Bandi
// Roll No.    : 2401
// Description : create a file,store story lines in it,access those lines &
//							  display the ones starting with A/a
// Sample lines: A jar is kept in the box
//						 : Jar contains jam,
//						 : which is put on the bread
//						 : A fly sits on the jam
//						 : A rat eats the fly
//						 : The cat catches rat 
//						 : as they have a chase!
//						 : Cat eats rat
//						 : and it ends!
//============================================================================
#include<iostream>
#include<fstream>
using namespace std;
//CLASS STORY
class story
{
  char str[60];
  static int count;
public:
  void accept();
  void display();
  void create();
  void read();
  void search();
};//CLASS ENDS

//SETTING STATIC COUNTER TO ZERO!
//NOTE:DONE OUTSIDE CLASS AS STATIC COUNTERS CANNOT BE INITIALIZED INSIDE THE CLASS!!!
int story::count=0;

//ACCEPT FUNCTION: TO ACCEPT LINES FROM USER THROUGH 'CONSOLE'
void story::accept()
{
  	cout<<"Enter the line: ";
  	//cin>>str;
  	cin.getline(str,30,'#');
}

//DISPLAY FUNCTION : TO DISPLAY ENTERED RECORDS ON 'CONSOLE'
void story::display()
{
	cout<<"\n\t"<<str;
}
//CREATE FUNCTION : TO INSERT RECORD INTO FILE! 
void story::create()
{
  char ch;
  story s;
  fstream f;
  f.open("story.txt",ios::out);					//OPENED IN WRITE MODE ONLY
  do
  {
	   s.accept();													//ACCEPT FUNCTION IS CALLED
	   f.seekp(count*sizeof(s),ios::beg);  
   	 f.write((char*)&s,sizeof(s));				//PUT POINTER SET COUNT*SIZEOF(S) BITS FROM BEGINING
  	 count++;
	   cout<<"Do you want to enter another line (y/n)? ";
	   cin>>ch;
	   cout<<"_______________________________________________\n";
  }while(ch=='y'||ch=='Y');
f.close();							//CLOSING OF FILE
}//CREATE ENDS

//READ FUNCTION : TO READ RECORDS FROM FILE!
void story::read()
{
  story s;
  fstream f;
  cout<<"\n==========> THE ENTERED LINES ARE: <==========";
  f.open("story.txt",ios::in);						//OPENED IN READ MODE ONLY
	for(int i=0;i<count;i++)
	{
	  f.seekg(i*sizeof(s),ios::beg);  			//GET POINTER SET i*SIZEOF(S) BITS FROM BEGINING
  	f.read((char*)&s,sizeof(s));
  	s.display();													//DISPLAY FUNCTION IS CALLLED
  }
  
  f.close();															//CLOSING THE FILE
cout<<"\n";
}//READ ENDS

//SEARCH FUNCTION: TO SEARCH FO LINES STARTING WITH a/A
void story::search()
{
  story s;
  fstream f;
  cout<<"\nTHE LINES STARTING WITH 'a' OR 'A' ARE: \n";
  f.open("story.txt",ios::in|ios::out);
	for(int i=0;i<count;i++)
	{
		  f.seekg(i*sizeof(s),ios::beg);  			//GET POINTER SET i*SIZEOF(S) BITS FROM BEGINING
		  f.read((char*)&s,sizeof(s));
		  if(s.str[1]!='a'&& s.str[1]!='A')			//COMPARING FIRST CHARACTER OF EVERY LINE IF (A/a)
		  			s.display();
	}

}//SEARCH ENDS

//MAIN FUNCTION
int main()
{
 story s1;
char ans;
int choice;
	//DO-WHILE FOR MENU DRIVEN PROGRAM
	  cout<<"============================================================\n";
	do
	{
		
		cout<<"\n********************* MENU *********************\n";	
		cout<<"\tPRESS:";
		cout<<"\n\t1. To insert line into file";
		cout<<"\n\t2. To read lines from file";
		cout<<"\n\t3. To display lines not starting with 'A' or 'a'\nCHOICE : ";
		cin>>choice;
		cout<<"__________________________________________________\n\n";
	//SWITCH CASE I STARTS
	switch(choice)
	{
	 case 1:
					s1.create();
	 		break;
	 case 2:
					s1.read();
	 		break;
	 case 3:
					s1.search();
	 		break;
	 default:
	 		cout<<"\nENTER VALID CHOICE!\n";
	 		break;
	 }
	 //SWITCH CASE ENDS
	  cout<<"\n============================================================";
	  cout<<"\nDo you want to continue (y/n)?\t ";
	  cin>>ans;
	  cout<<"============================================================\n";
	}while(ans=='Y'||ans=='y');
	//D0-WHILE LOOP ENDS
return 0;

}
//PROGRAM ENDS

//<-------------------------------OUTPUT--------------------------------->

/*
============================================================
********************* MENU *********************
	PRESS:
	1. To insert line into file
	2. To read lines from file
	3. To display lines not starting with 'A' or 'a'
CHOICE : 1
__________________________________________________

Enter the line: A jar is kept in the box#
Do you want to enter another line (y/n)? y
_______________________________________________
Enter the line: Jar contains jam,#
Do you want to enter another line (y/n)? y
_______________________________________________
Enter the line: jam is put on the bread#
Do you want to enter another line (y/n)? y
_______________________________________________
Enter the line: A fly sits on the jam#
Do you want to enter another line (y/n)? y
_______________________________________________
Enter the line: A rat eats the fly#
Do you want to enter another line (y/n)? y
_______________________________________________
Enter the line: The cat catches rat#
Do you want to enter another line (y/n)? y
_______________________________________________
Enter the line:  as they have a chase!#
Do you want to enter another line (y/n)? y
_______________________________________________
Enter the line: Cat eats rat#
Do you want to enter another line (y/n)? y
_______________________________________________
Enter the line: and it ends!
#
Do you want to enter another line (y/n)? n
============================================================
Do you want to continue (y/n)?	 y
============================================================

********************* MENU *********************
	PRESS:
	1. To insert line into file
	2. To read lines from file
	3. To display lines not starting with 'A' or 'a'
CHOICE : 2
__________________________________________________


==========> THE ENTERED LINES ARE: <==========
	
A jar is kept in the box
	
Jar contains jam,
	
jam is put on the bread
	
A fly sits on the jam
	
A rat eats the fly
	
The cat catches rat
	
as they have a chase!
	
Cat eats rat
	
and it ends!

============================================================
Do you want to continue (y/n)?	 y
============================================================

********************* MENU *********************
	PRESS:
	1. To insert line into file
	2. To read lines from file
	3. To display lines not starting with 'A' or 'a'
CHOICE : 3
__________________________________________________


THE LINES STARTING WITH 'a' OR 'A' ARE: 

	
Jar contains jam,
	
which is put on the bread
	
The cat catches rat
	
Cat eats rat
============================================================
Do you want to continue (y/n)?	 n
============================================================

*/





































