//============================================================================
// Name        : string.cpp
// Author      : Sneha Bandi
// Roll No.    : 2401
// Description : Accept-Display a string
//		 Find length of string
//		 Reverse a string
//		 Concatenate a string
// 		 Copy one string into other
//		 Compare two strings
//		 Finding a substring in an existing string
//============================================================================

#include<iostream>
using namespace std;
class strings
{
  char str[30];
  char str1[30];
public:
  void accept();
  void display();
  int length();
  void reverse();
  void concat(strings&,strings&);
  void copying();
  void compare(strings&,strings&);
  void substring();
};

void strings::accept()
{
   cin>>str;
}

void strings::display()
{
  cout<<str;
}

int strings::length()				//FIND LENGTH OF STRING
{
  int len=0;
  while(str[len]!='\0')
  {
   len++;
  }
  return len;
}

void strings::reverse()				//REVERSE A STRING
{
  int l=length();
  int j=0;
  for(int i=l-1;i>=0;i--)
  {
    str1[j]=str[i];
    j++;
  }
  str1[j]='\0';
    cout<<"\nThe reversed string is: "<<str1;
}

void strings::concat(strings& t1,strings& t2)		//CONCATENATE TWO STRINGS
{ 
  int len=t1.length();
  int i=0;
  while(t2.str[i]!='\0')
  {
    t1.str[len]=t2.str[i];
    len++;
    i++;
  }
  t1.str[len]='\0';
  cout<<"\nThe concatenated list is: "<<t1.str;

}

void strings::copying()			//COPY ONE STRING INTO OTHER
{
  int l=length();
  int j=0;
  for(int i=0;i<l;i++)
  {
    str1[j]=str[i];
    j++;
  }
  str1[j]='\0';
    cout<<"\nThe copied string is: "<<str1;
}
void strings::compare(strings& t1,strings& t2)		//COMPARING TWO STRINGS
{ 
  int l=t1.length();
  int i=0,flag=0;
  for(int i=0;i<l;i++)
  {
    if(t1.str[i]!=t2.str[i])
    {
	flag=1;
	break;
    }
  }
  if(flag==1)
	cout<<"\nThe strings donot match!\n";
  else
	cout<<"\nThe strings match completely!\n";
}
						//TO FIND A SUBSTRING IN A GIVEN STRING
void strings::substring()
{
  int j=0,flag=0;
  char s[15];
  int l=length();
  cout<<"Enter the substring: ";
  cin>>s;
  cout<<"\nString: "<<str<<"\tSubstring: "<<s<<"\n";
  for(int i=0;i<l;i++)
  {
    if(str[i]==s[j])
    {
      j++;
      if(s[j]=='\0')
      {
	flag=1;
        break;
      }
    }
    else if(str[i]!=s[j]&&j>0)
    {
      j=0;
      i--;
    }
  }
  if(flag==1)
          cout<<"\nSubstring Found!\n";
  else
          cout<<"\nSubstring not Found!\n";

}
//MAIN
int main()
{
  strings s1,s2,s3,s4,s5,s6,s7,s8,s9,ss,s10;
  int n,x;
  char ch;
	cout<<"\n\t\t\tTHIS PROGRAM IS TO PERFORM STRING OPERATIONS!!!\n";

  do{
	cout<<"\n*********************** MENU ***********************\n";
	cout<<"\tPRESS:";
	cout<<"\n\t1. to accept and display";
	cout<<"\n\t2. to find length of string";
	cout<<"\n\t3. to reverse a string";
	cout<<"\n\t4. to concatenate two strings";
	cout<<"\n\t5. to copy one string into another";
	cout<<"\n\t6. to compare two strings";
	cout<<"\n\t7. to find substring\nCHOICE: ";
	cin>>n;

	switch(n)
	{
	  case 1:
	  	cout<<"\nEnter the string: ";
		s1.accept();
		cout<<"The entered string is:";
		s1.display();
		break;
	  case 2:
	  	cout<<"\nEnter the string: ";
		s2.accept();
		cout<<"The entered string is:";
		s2.display();
		x=s2.length();
		cout<<"\nThe length of string is:"<<x;
		break;
	  case 3:
	  	cout<<"\nEnter the string: ";
		s3.accept();
		cout<<"The entered string is:";		
		s3.display();
	        s3.reverse();
		break;
	  case 4:
	  	cout<<"\nEnter the first string: ";	  
		s4.accept();
	  	cout<<"Enter the second string: ";		
		s5.accept();
		cout<<"\n1st string:";
		s4.display();
		cout<<"\t\t2nd string:";
		s5.display();
	  	s6.concat(s4,s5);
		break;
	  case 5:
	  	cout<<"\nEnter the string: ";
		s7.accept();
		cout<<"The entered string is:";		
		s7.display();
	        s7.copying();
		break;
	  case 6:
	  	cout<<"\nEnter the first string: ";	  
		s8.accept();
	  	cout<<"Enter the second string: ";		
		s9.accept();
		cout<<"\n1st string:";
		s8.display();
		cout<<"\t\t2nd string:";
		s9.display();
	  	ss.compare(s8,s9);
		break;
	  case 7:
	  	cout<<"Enter the string: ";
	  	s10.accept();
	  	s10.substring();
	  	break;
	  default:
		cout<<"\nINVALID CHOICE!!\n";
		break;

	}
        cout<<"\n========================================================";
	cout<<"\nDo you want to continue (y/n)?\t";
	cin>>ch;
        cout<<"\n========================================================";
      }while(ch=='y'||ch=='Y');
	cout<<"\n";
  return 0; 
}
//PROGRAM ENDS

//------------------------------------------------ OUTPUT ------------------------------------------------

/*
			THIS PROGRAM IS TO PERFORM STRING OPERATIONS!!!

*********************** MENU ***********************
	PRESS:
	1. to accept and display
	2. to find length of string
	3. to reverse a string
	4. to concatenate two strings
	5. to copy one string into another
	6. to compare two strings
	7. to find substring
CHOICE: 1

Enter the string: synchronize
The entered string is:synchronize
========================================================
Do you want to continue (y/n)?	y
========================================================
*********************** MENU ***********************
	PRESS:
	1. to accept and display
	2. to find length of string
	3. to reverse a string
	4. to concatenate two strings
	5. to copy one string into another
	6. to compare two strings
	7. to find substring
CHOICE: 2

Enter the string: asymmetric
The entered string is:asymmetric
The length of string is:10
========================================================
Do you want to continue (y/n)?	y
========================================================
*********************** MENU ***********************
	PRESS:
	1. to accept and display
	2. to find length of string
	3. to reverse a string
	4. to concatenate two strings
	5. to copy one string into another
	6. to compare two strings
	7. to find substring
CHOICE: 3

Enter the string: tranquility
The entered string is:tranquility
The reversed string is: ytiliuqnart
========================================================
Do you want to continue (y/n)?	y
========================================================
*********************** MENU ***********************
	PRESS:
	1. to accept and display
	2. to find length of string
	3. to reverse a string
	4. to concatenate two strings
	5. to copy one string into another
	6. to compare two strings
	7. to find substring
CHOICE: 4

Enter the first string: excel
Enter the second string: lent

1st string:excel		2nd string:lent
The concatenated list is: excellent
========================================================
Do you want to continue (y/n)?	y
========================================================
*********************** MENU ***********************
	PRESS:
	1. to accept and display
	2. to find length of string
	3. to reverse a string
	4. to concatenate two strings
	5. to copy one string into another
	6. to compare two strings
	7. to find substring
CHOICE: 5

Enter the string: synthetic
The entered string is:synthetic
The copied string is: synthetic
========================================================
Do you want to continue (y/n)?	y
========================================================
*********************** MENU ***********************
	PRESS:
	1. to accept and display
	2. to find length of string
	3. to reverse a string
	4. to concatenate two strings
	5. to copy one string into another
	6. to compare two strings
	7. to find substring
CHOICE: 6

Enter the first string: indonasia
Enter the second string: india

1st string:indonasia		2nd string:india
The strings donot match!

========================================================
Do you want to continue (y/n)?	y

========================================================
*********************** MENU ***********************
	PRESS:
	1. to accept and display
	2. to find length of string
	3. to reverse a string
	4. to concatenate two strings
	5. to copy one string into another
	6. to compare two strings
	7. to find substring
CHOICE: 6

Enter the first string: Indian
Enter the second string: Indian

1st string:Indian		2nd string:Indian
The strings match completely!

========================================================
Do you want to continue (y/n)?	y
========================================================
*********************** MENU ***********************
	PRESS:
	1. to accept and display
	2. to find length of string
	3. to reverse a string
	4. to concatenate two strings
	5. to copy one string into another
	6. to compare two strings
	7. to find substring
CHOICE: 7
Enter the string: mississippi
Enter the substring: sip

String: mississippi	Substring: sip

Substring Found!

========================================================
Do you want to continue (y/n)?	y

========================================================
*********************** MENU ***********************
	PRESS:
	1. to accept and display
	2. to find length of string
	3. to reverse a string
	4. to concatenate two strings
	5. to copy one string into another
	6. to compare two strings
	7. to find substring
CHOICE: 7
Enter the string: mississippi
Enter the substring: sips

String: mississippi	Substring: sips

Substring not Found!

========================================================
Do you want to continue (y/n)?	n

========================================================

*/
