//============================================================================
// Name        : stl_stack.cpp
// Author      : Sneha Bandi 
// Roll No.    : 2401
// Description : THIS PROGRAM PERFORMS ADDITION OF TWO BINARY NUMBERS 
//			USING STL OF STACK!
//============================================================================

#include <iostream>
#include<stack>
using namespace std;
stack<int>read()
{
 stack<int>s;
 int x,n,i;					//X CORRESPONDS TO SINGLE BIT-PUSHED IN STACK
 int A[30];					//ARRAY FOR STORING BINARY NUMBER
 cout<<"\n\tEnter the no. of bits : ";
 cin>>n;
 cout<<"\n\tEnter the binary number : ";
 for(int i=0;i<n;i++)
 {
	 cin>>x;
	 s.push(x);				//ONE BIT PUSHED INTO STACK
	 A[i]=x;				//NORMAL ARRAY TO STORE AND DISPLAY THE ENTERED BINARY NUMBER
 }
 cout<<"\n\tEntered binary number is : ";
 for(int i=0;i<n;i++)
 	cout<<A[i];
 return s;
}

//DISPLAYING ADDITION BIT BY BIT BY POPPING ELEMENTS
void display(stack<int>&s)
{
	cout<<"";
    while(!s.empty())
    {
    	cout<<s.top()<<"";
    	s.pop();		//REVERSE LIST IS DISPLAYED AS ADDITION FROM L.S.B TO M.S.B
    }
}

//ADDITION OF TWO BINARY NUMBERS
stack<int>add(stack<int>&s1,stack<int>&s2)
{
stack<int>s;
int sum,carry=0,b1,b2;			//b1,b2 TO STORE EACH BIT POPPED
while(!s1.empty())
{
 b1=b2=0;
 if(!s1.empty())			//POP 1; STORED IN b1
 {
	 b1=s1.top();
	 s1.pop();
 }
 if(!s2.empty())			//POP 2; STORED IN b2
 {
	 b2=s2.top();
	 s2.pop();
 }
 sum=(b1+b2+carry)%2;
 carry=(b1+b2+carry)/2;
 s.push(sum);
}
if(carry==1)
	s.push(1);			//IF EXTRA CARRY GENERATED IT IS PUSHED IN STACK
return s;
}

//main()
int main()
{
  stack<int>s1,s2,s3;
  int ch;
	
	cout<<"\n\t\t* THIS PROGRAM PERFORMS ADDITION OF TWO BINARY NUMBERS ! *\n\n";
  //do-while BEGINS
	do{
	cout<<"\n************************ MENU *************************\n\tPRESS:\n";
	cout<<"\n\t1. Read first";
	cout<<"\n\t2. Read second";
	cout<<"\n\t3. Addition of two numbers.";
	cout<<"\n\t4. Exit";
	cout<<"\n\nCHOICE : ";
	cin>>ch;
	cout<<"<---------------------------------------------------------------------->\n";
	//SWITCH CASE BEGINS
	switch(ch)
	{
	 case 1:
		s1=read();
		break;
	 case 2:
		s2=read();
		break;
	 case 3:
		cout<<"\n\tThe Addition is : ";
		s3=add(s1,s2);
		display(s3);
		break;
	 case 4:
		break;
	 default :
		cout<<"\n\t!! ENTER VALID CHOICE !!\n";
	}
	//SWITCH CASE ENDS
		cout<<"\n\n<---------------------------------------------------------------------->\n";
	}while(ch!=4);
	//do-while ENDS

	return 0;
}
//PROGRAM ENDS

//<----------------------------------------OUTPUT-------------------------------------------->
/*
		* THIS PROGRAM PERFORMS ADDITION OF TWO BINARY NUMBERS ! *


************************ MENU *************************
	PRESS:

	1. Read first
	2. Read second
	3. Addition of two numbers.
	4. Exit

CHOICE : 1
<---------------------------------------------------------------------->

	Enter the no. of bits : 4

	Enter the binary number : 1	0	1	0

	Entered binary number is : 1010

<---------------------------------------------------------------------->

************************ MENU *************************
	PRESS:

	1. Read first
	2. Read second
	3. Addition of two numbers.
	4. Exit

CHOICE : 2
<---------------------------------------------------------------------->

	Enter the no. of bits : 4

	Enter the binary number : 0	1	0	1

	Entered binary number is : 0101

<---------------------------------------------------------------------->

************************ MENU *************************
	PRESS:

	1. Read first
	2. Read second
	3. Addition of two numbers.
	4. Exit

CHOICE : 3
<---------------------------------------------------------------------->

	The Addition is : 1111

<---------------------------------------------------------------------->

************************ MENU *************************
	PRESS:

	1. Read first
	2. Read second
	3. Addition of two numbers.
	4. Exit

CHOICE : 4
<---------------------------------------------------------------------->

*/
