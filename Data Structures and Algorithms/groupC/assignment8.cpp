//============================================================================
// Name        : parenthesis.cpp
// Author      : Sneha Bandi
// Roll No.    : 2401
// Description : To check if the entered expression is well parenthesized
//			expression or not
//============================================================================

#include <iostream>
using namespace std;
#include<string.h>
#define MAX 30
//CLASS STACK
class stack
{
  friend class strings;
	char stk[MAX];
	int top;
public:
	stack()
	{
		top=-1;
	}
	void push(char);
	char pop();
	int isempty();
	int isfull();
};
//DECLARATION OF CLASSES IN THIS ORDER IS MANDATORY
//DUE TO FRIEND FUNCTION
//CLASS STRINGS
class strings
{
stack s;
	char str[MAX];
	char str1[MAX];
	char str2[MAX];
public:
	stack accept();
	void display();
    void check();

};
//CHECKING IF STACK IS EMPTY OR NOT
int stack::isempty()
{
  if(top==-1)
	return 1;
  else
	return 0;

}
//CHECKING IF STACK IS FULL OR NOT
int stack::isfull()
{
  if(top==MAX)
	return 1;
  else
	return 0;

}
//PUSH FUNCTION
void stack::push(char c)
{
	if(isfull()==1)
		cout<<"\nSTACK OVERFLOW!\n";
	else
		stk[++top]=c;

}
//POP FUNCTION
char stack::pop()
{
  int x;
  if(isempty()==1)
	cout<<"\nSTACK IS EMPTY!\n";
  else
	x=stk[top--];

	return x;


}
stack strings::accept()
{
	int j=0;
	cout<<"Enter a string: ";
	cin>>str;

	for(int i=0;i<strlen(str);i++)
	{
//ONLY OPENING BRACKETS PUSHED IN THE STACK
	  if(str[i]=='('||str[i]=='{'||str[i]=='[')
	   {
	 	str1[j]=str[i];
	 	s.push(str1[i]);
	 	j++;
	   }
	}
}
//DISPLAY OF STACK AS WELL AS THE EXPRESSION
void strings::display()
{
	int ch;
	cout<<"Menu:\n\t1.to print expression\n\t2.To print brackets only\t";
	cin>>ch;
	switch(ch)
	{
//DISPLAY OF COMPLETE EXPRESSION WITH VARIABLES ALSO
	case 1:
		cout<<"\nThe entered expression is: "<<str<<endl;
		break;
//DISPLAY OF ONLY THE BRACKETS PUSHED INTO THE STACK
	case 2:
		cout<<"\nBracket string:: "<<str1<<endl;
		break;
	}

}
//CHECKING IF WELL FORMED PARENTHESIZED EXPRESSION OR NOT
void strings::check()
{
	int flag=0;
	for(int i=0;i<strlen(str);i++)
	{

      if(str[i]==']')
      {
	  if(s.pop()!='[')
	  {
		  cout<<"\nUNBALANCED!!\n";
		  flag =1;
		  break;
	  }
      }


      if(str[i]==')')
      {
	  if(s.pop()!='(')
	  {
		  cout<<"\n UNBALANCED!!\n";
		  flag =1;
		  break;
	  }
      }
      if(str[i]=='}')
      {
	  if(s.pop()!='{')
	  {
		  cout<<"\n UNBALANCED!!\n";
		  flag =1;
		  break;
	  }
      }
	}
    if(flag==0)
    {
    	if(s.isempty()==1)

		  cout<<"\nBALANCED!!\n";
    else
		  cout<<"\n UNBALANCED!!\n";
    }
}
//MAIN
int main() {
	strings r;
	int t;
	char ch;
	cout<<"=============================================\n";
//DO-WHILE STARTS
	do{
	cout<<"Enter your choice\n";
	cout<<"\t1.Accept\n\t2.display\n\t3.check\n";
	cout<<"CHOICE: ";
	cin>>t;
	//SWITCH STARTS
	switch(t)
	{
	case 1:
		r.accept();
		break;
	case 2:
		r.display();

		break;
	case 3:
		r.check();
		break;
	default:
		cout<<"\nENTER VALID CHOICE!\n";

	}
	//SWITCH ENDS
	cout<<"Do you want to continue (y/n)?  ";
	cin>>ch;
	cout<<"=============================================\n";
	}while(ch=='y'||ch=='Y');
//DO-WHILE ENDS
	return 0;
}
//PROGRAM ENDS
//<------------------------ OUTPUT -------------------------->
/*
//--------------------------------------------------- > > [{()}]
=============================================
Enter your choice
	1.Accept
	2.display
	3.check
CHOICE: 1
Enter a string: a/b-[c*d{e+(f+g)}*a]
Do you want to continue (y/n)?  y
=============================================
Enter your choice
	1.Accept
	2.display
	3.check
CHOICE: 2
Menu:
	1.to print expression
	2.To print brackets only	1

The entered expression is: a/b-[c*d{e+(f+g)}*a]
Do you want to continue (y/n)?  y
=============================================
Enter your choice
	1.Accept
	2.display
	3.check
CHOICE: 2
Menu:
	1.to print expression
	2.To print brackets only	2

Bracket string:: [{(
Do you want to continue (y/n)?  y
=============================================
Enter your choice
	1.Accept
	2.display
	3.check
CHOICE: 3

 BALANCED!!
Do you want to continue (y/n)?  n
=============================================

//------------------------------------------------ > > [{()}
=============================================
Enter your choice
	1.Accept
	2.display
	3.check
CHOICE: 1
Enter a string: a/b-[c*d{e+(f+g)}*a 
Do you want to continue (y/n)?  y
=============================================
Enter your choice
	1.Accept
	2.display
	3.check
CHOICE: 2
Menu:
	1.to print expression
	2.To print brackets only	1

The entered expression is: a/b-[c*d{e+(f+g)}*a
Do you want to continue (y/n)?  y
=============================================
Enter your choice
	1.Accept
	2.display
	3.check
CHOICE: 2
Menu:
	1.to print expression
	2.To print brackets only	2

Bracket string:: [{(
Do you want to continue (y/n)?  y
=============================================
Enter your choice
	1.Accept
	2.display
	3.check
CHOICE: 3

 UNBALANCED!!
Do you want to continue (y/n)?  n
=============================================

//-------------------------------------------------- > > {()}]
=============================================
Enter your choice
	1.Accept
	2.display
	3.check
CHOICE: 1
Enter a string: a/b-{c*(d-e)+f}/f]     
Do you want to continue (y/n)?  y
=============================================
Enter your choice
	1.Accept
	2.display
	3.check
CHOICE: 2
Menu:
	1.to print expression
	2.To print brackets only	1

The entered expression is: a/b-{c*(d-e)+f}/f]
Do you want to continue (y/n)?  y
=============================================
Enter your choice
	1.Accept
	2.display
	3.check
CHOICE: 2
Menu:
	1.to print expression
	2.To print brackets only	2

Bracket string:: {(
Do you want to continue (y/n)?  y
=============================================
Enter your choice
	1.Accept
	2.display
	3.check
CHOICE: 3

 UNBALANCED!!
Do you want to continue (y/n)?  n
=============================================

*/
