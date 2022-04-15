//============================================================================
// Name        : stack_palindrome.cpp
// Author      : Sneha Bandi
// Roll No.    : 2401
// Description : To check if the entered string is a palindrome or not!
//============================================================================

#include <iostream>
using namespace std;
#include<string.h>
#define MAX 30
//CLASS STACK
class stack
{
  friend class strings;			//NOW PRIVATE MEMBERS OF STRINGS CLASS CAN BE ACCESSED BY STACK CLASS MEMBERS
	char stk[MAX];
	int top;			//TOP
public:
	stack()				//DEFAULT CONSTRUCTOR
	{
		top=-1;
	}
	void push(char);
	char pop();
	int isempty();
	int isfull();
};
//STRING CLASS
class strings
{
stack s;
	char str[MAX];			//NORMAL ACCEPTED STRING
	char str1[MAX];			//STRING AFTER REMOVAL OF SPECIAL CHARACTERS
	char str2[MAX];			//REVERSE OF STRING STR1
public:
	void accept();
	void display();
	void reverse();			//TO REVERSE THE STRING
	void palindrome();		//TO CHECK IF ACCEPTED STRING IS A PALINDROME
};
//TO CHECK IF STACK IS EMPTY OR NOT
int stack::isempty()
{
  if(top==-1)
	return 1;
  else
	return 0;

}
//TO CHECK IF STACK IS FULL OR NOT
int stack::isfull()
{
  if(top==MAX)
	return 1;
  else
	return 0;

}
//TO PUSH ELEMENT IN STACK
void stack::push(char c)
{
	if(isfull()==1)
		cout<<"\nSTACK OVERFLOW!\n";
	else
		stk[++top]=c;
		
}
//TO POP ELEMENT FROM STACK
char stack::pop()
{
  char x;
  if(isempty()==1)
	cout<<"\nSTACK IS EMPTY!\n";
  else
	x=stk[top--];
	
	return x;
	

}
//STRING ACCEPTANCE
void strings::accept()
{
	int j=0;
	cout<<"\nEnter a string (terminate with '.'): ";
	cin.ignore();
	cin.getline(str,30,'.');

		for(int i=0;i<strlen(str);i++)
		{//checking for special characters
			if(str[i]!=' '&& str[i]!='\n'&& str[i]!='\t'&& ispunct(str[i])==0)
			{//if ispunct()==0 means its NOT a punctuation

				str1[j]=tolower(str[i]);
				s.push(str1[j]);
				j++;
			}
		}
		str1[j]='\0';
		cout<<"\nThe entered string is: "<<str;
		cout<<"\n The altered string is: ";
		if(s.isempty()==1)
			cout<<"______\n(NOTE : No characters are in the stack !!)\n";
		else
			cout<<str;

} 
//TO REVERSE A STRING 
void strings::reverse()
{
	   int i=0;
  if(s.isempty()==1)
	cout<<"\nSTACK IS EMPTY!\n";
  else{
	while(s.top!=-1)
	{
		str2[i]=s.pop();
		i++;
	}
	str2[i]='\0';
	cout<<"\nThe reversed string is: "<<str2;
     }

}
//TO CHECK IF ENTERED STRING IS A PALINDROME OR NOT 
void strings::palindrome()
{
  if(s.isempty()==1)
	cout<<"\nSTACK IS EMPTY!\n(NOTE : please enter minimum one character other than special characters)\n";
  else{

	if((strcmp(str1,str2))==0)
		cout<<"\n\tIT IS A PALINDROME!\n";
	else
		cout<<"\n\tIT IS NOT A PALINDROME!\n";


	cout<<"\n\tORIGINAL STRING : "<<str1;
	cout<<"\n\tREVERSED STRING : "<<str2;
    }
}
//MAIN
int main() 
{
	strings r;
	int t;
	char ch;
//DO-WHILE STARTS
cout<<"\n\t\t\tTHIS PROGRAM IS TO CHECK IF THE ENTERED STRING IS A PALINDROME OR NOT !!\n";
cout<<"_____________________________________________________________________________________\n";
	do{
	cout<<"\n\t\t\t\tMENU\n";
	cout<<"\tPRESS:";
	cout<<"\n\t1.Accept\n\t2.reverse\n\t3.palindrome\n";
	cout<<"CHOICE: ";
	cin>>t;
//SWITCH CASE BEGINS
	switch(t)
	{
	case 1:
		r.accept();
		break;
	case 2:
		r.reverse();
		break;
	case 3:
		r.palindrome();
		break;
	default:
		cout<<"\nENTER VALID CHOICE!\n";

	}
//SWITCH CASE ENDS
	cout<<"\n=============================================\n";
	cout<<"\nDo you want to continue (y/n)?  ";
	cin>>ch;
	cout<<"=============================================\n";
	}while(ch=='y'||ch=='Y');
//DO-WHILE ENDS
	return 0;
}
//PROGRAM ENDS
//<---------------------------------------- OUTPUT --------------------------------------->
/*

//-------------------------> > TEST case : single word is a palindrome


			THIS PROGRAM IS TO CHECK IF THE ENTERED STRING IS A PALINDROME OR NOT !!
_____________________________________________________________________________________

				MENU
	PRESS:
	1.Accept
	2.reverse
	3.palindrome
CHOICE: 1

Enter a string (terminate with '.'): !	,	@"
".

The entered string is: !	,	@"
"
 The altered string is: ______
(NOTE : No characters are in the stack !!)

=============================================

Do you want to continue (y/n)?  y
=============================================

				MENU
	PRESS:
	1.Accept
	2.reverse
	3.palindrome
CHOICE: 2

STACK IS EMPTY!

=============================================

Do you want to continue (y/n)?  y
=============================================

				MENU
	PRESS:
	1.Accept
	2.reverse
	3.palindrome
CHOICE: 3

STACK IS EMPTY!
(NOTE : please enter minimum one character other than special characters)

=============================================

Do you want to continue (y/n)?  n
=============================================
				MENU
	PRESS:
	1.Accept
	2.reverse
	3.palindrome
CHOICE: 3

STACK IS EMPTY!
(NOTE : please enter minimum one character other than special characters)

=============================================

Do you want to continue (y/n)?  n
=============================================

//-------------------------> > case 1 : single word is a palindrome

			THIS PROGRAM IS TO CHECK IF THE ENTERED STRING IS A PALINDROME OR NOT !!
_____________________________________________________________________________________

				MENU
	PRESS:
	1.Accept
	2.reverse
	3.palindrome
CHOICE: 1

Enter a string (terminate with '.'): MaLayaLam.

The entered string is: MaLayaLam
 The altered string is: malayalam
=============================================

Do you want to continue (y/n)?  y
=============================================

				MENU
	PRESS:
	1.Accept
	2.reverse
	3.palindrome
CHOICE: 2

The reversed string is: malayalam
=============================================

Do you want to continue (y/n)?  y
=============================================

				MENU
	PRESS:
	1.Accept
	2.reverse
	3.palindrome
CHOICE: 3

	IT IS A PALINDROME!

	ORIGINAL STRING : malayalam
	REVERSED STRING : malayalam
=============================================

Do you want to continue (y/n)?  n
=============================================

//-------------------------> > case 2 : single word is NOT a palindrome

			THIS PROGRAM IS TO CHECK IF THE ENTERED STRING IS A PALINDROME OR NOT !!
_____________________________________________________________________________________

				MENU
	PRESS:
	1.Accept
	2.reverse
	3.palindrome
CHOICE: 1

Enter a string (terminate with '.'): EnGLisH.

The entered string is: EnGLisH
 The altered string is: english
=============================================

Do you want to continue (y/n)?  y
=============================================

				MENU
	PRESS:
	1.Accept
	2.reverse
	3.palindrome
CHOICE: 2

The reversed string is: hsilgne
=============================================

Do you want to continue (y/n)?  y
=============================================

				MENU
	PRESS:
	1.Accept
	2.reverse
	3.palindrome
CHOICE: 3

	IT IS NOT A PALINDROME!

	ORIGINAL STRING : english
	REVERSED STRING : hsilgne
=============================================

Do you want to continue (y/n)?  n
=============================================


//-------------------------> > case 3 : Multi-word string is a palindrome


			THIS PROGRAM IS TO CHECK IF THE ENTERED STRING IS A PALINDROME OR NOT !!
_____________________________________________________________________________________

				MENU
	PRESS:
	1.Accept
	2.reverse
	3.palindrome
CHOICE: 1

Enter a string (terminate with '.'): Poor Dan,is in a   Droop!!. 

The entered string is: Poor Dan,is in a 	Droop!!
 The altered string is: poordanisinadroop
=============================================

Do you want to continue (y/n)?  y
=============================================

				MENU
	PRESS:
	1.Accept
	2.reverse
	3.palindrome
CHOICE: 2

The reversed string is: poordanisinadroop
=============================================

Do you want to continue (y/n)?  y
=============================================

				MENU
	PRESS:
	1.Accept
	2.reverse
	3.palindrome
CHOICE: 3

	IT IS A PALINDROME!

	ORIGINAL STRING : poordanisinadroop
	REVERSED STRING : poordanisinadroop
=============================================

Do you want to continue (y/n)?  n
=============================================

//-------------------------> > case 4 : Multi-word string is NOT a palindrome

			THIS PROGRAM IS TO CHECK IF THE ENTERED STRING IS A PALINDROME OR NOT !!
_____________________________________________________________________________________

				MENU
	PRESS:
	1.Accept
	2.reverse
	3.palindrome
CHOICE: 1

Enter a string (terminate with '.'): Dan is not in a DRoop,
!! ".

The entered string is: Dan is not in a DRoop,
!! "
 The altered string is: danisnotinadroop
=============================================

Do you want to continue (y/n)?  y
=============================================

				MENU
	PRESS:
	1.Accept
	2.reverse
	3.palindrome
CHOICE: 2

The reversed string is: poordanitonsinad
=============================================

Do you want to continue (y/n)?  y
=============================================

				MENU
	PRESS:
	1.Accept
	2.reverse
	3.palindrome
CHOICE: 3

	IT IS NOT A PALINDROME!

	ORIGINAL STRING : danisnotinadroop
	REVERSED STRING : poordanitonsinad
=============================================

Do you want to continue (y/n)?  n
=============================================

//-------------------------> > case 4 : Multi-word string is NOT a palindrome

	
*/ 









