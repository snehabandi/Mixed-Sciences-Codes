//============================================================================
// Name        : integer_array.cpp
// Author      : Sneha Bandi
// Roll No.    : 2401
// Description : To accept and display integer array using 'cin' & 'cout'
//	       : To assign one array to another by assignment operator(=)
//	       : To support a function that returns the size of the array
//	       : To perform range checking 
//============================================================================
//copy constructor and defult constructor added
#include<iostream>
using namespace std;
//cpparray class
class cpparray
{
  int A[30];							//DATA MEMBER: ARRAY AND ITS SIZE
  int size;
 public:
   cpparray()
   {  	
        size=1;
   	A[0]=0;
   }
   cpparray(cpparray&);
   friend istream& operator>>(istream& in,cpparray& a);   	//EXTRACTION OPERATOR OVERLOADING
   friend ostream& operator<<(ostream& out,cpparray& a);	//INSERTION OPERATOR OVERLOADING
   
   void operator=(cpparray& a);
   int operator[](int);
   
   int length(cpparray&);
   int range(cpparray&);   

};
//cpparray CLASS ENDS
cpparray::cpparray(cpparray& a)
{
  for(int i=0;i<this->size;i++)
  {
    this->A[i]=a.A[i];
  }
}

istream& operator>>(istream& in,cpparray& a)			//DEFINITION OF EXTRACTION OPERATOR OVERLOADING
{
  a.size=0;
  int i=0;
  char ch;

  //******************* METHOD I ********************

do{  	
    //RANGE CHECKING STARTS
 	 if(a.range(a)==1)
 	 {
		cout<<"\n! ARRAY OUT OF BOUND\n";
		break;
	 }
    //RANGE CHECKING ENDS

	cout<<"Enter element: ";
      	in>>a.A[i];
      	i++;
      	a.size++;
      	cout<<"Enter another element (y/n)? ";
      	cin>>ch;
      }while(ch=='y'||ch=='Y');    


  //******************* METHOD II ********************
/*
  cout<<"\nEnter the size of array: ";
  in>>a.size;
  cout<<"\nEnter the integeral elements:";
  for(int i=0;i<a.size;i++)
  {
    //RANGE CHECKING STARTS
 	 if(a.range(a)==1)
 	 {
		cout<<"\n! ARRAY OUT OF BOUND\n";
		break;
	 }
    //RANGE CHECKING ENDS
    in>>a.A[i];							
  }
 */
  return in;
}   
ostream& operator<<(ostream& out,cpparray& a)				//DEFINITION OF INSERTION OPERATOR OVERLOADING
{
  cout<<"\nArray is: | ";
  for(int i=0;i<a.size;i++)
  {
    out<<a.A[i];							//DISPLAYING ARRAY
    cout<<" | ";
  }
  cout<<"\n";
  return out;
}
void cpparray::operator=(cpparray& a)
{
  for(int i=0;i<this->size;i++)
  {
    this->A[i]=a.A[i];
  }
}

int cpparray::range(cpparray& a)					//RANGE CHECKING
{
  if(a.size<0||a.size>10)
     return 1;
  else
     return 0;
}

int cpparray::length(cpparray& a)					//CALCULATION OF LENGTH OF ARRAY
{
  return a.size;
}

int main()
{
  cpparray a1,a2,a3,a4,a5,a6;
  int n,len;
  char choice;

	//COPY CONSTRUCTOR
  	cpparray a7=a6;
  
     //DO-WHILE STARTS
  do{  
  	cout<<"\n\n********************* MENU *********************\n";
	cout<<"\n\t1. To accept and display integer array";
	cout<<"\n\t2. To make *default* array";
	cout<<"\n\t3. To assign one array to another pre-existing array";
	cout<<"\n\t4. To find size of the array";
	cout<<"\n\t5. To perform range checking ";
	cout<<"\n\nCHOICE: ";
	cin>>n;
   cout<<"________________________________________________________________\n";	
	//SWITCH CASE STARTS
	switch(n)
	{
	  case 1:
	  	cin>>a1;		//ACCEPT-DISPLAY
	  	cout<<a1;
	  	break;
	  case 2:
	  	cout<<"a6:";
	  	cout<<a6;
		cout<<"\nNEW:";		//copy default values to an object in switch case by COPY CONSTRUCTOR
	  	cout<<a7;
	  	break;
	  case 3:
	  	cout<<"\t\tEnter SOURCE arrays\n";
	  	cin>>a2;
	  	cout<<a2;
	  	cout<<"\n\t\tEnter DESTINATION arrays\n";
	  	cin>>a3;
	  	cout<<a3;
		cout<<"\n-------------------- OLD: --------------------\n\t";
	  	cout<<a3;
	  	a3=a2;	  		//copying using '=' operator	  		
		cout<<"\n-------------------- NEW: --------------------\n\t";
	  	cout<<a3;
	  	break;
	  case 4:
	  	cin>>a4;		//LENGTH CALCULATION
	  	cout<<a4;
	  	len=a4.length(a4);
	  	cout<<"\nThe length of array is: "<<len;
	  	break;
	  case 5:
	  	cin>>a5;		//RANGE OUT OF BOUND ON ENTRY OF 10 ELEMENTS
	  	cout<<a5;
	  	break;
	  default:
	  	break;	  		  		  		
	}
	//SWITCH CASE ENDS
   cout<<"\n==========================================================="; 
	cout<<"\nDo you want to continue (y/n)? ";
	cin>>choice;
   cout<<"==========================================================="; 
     }while(choice=='y'||choice=='Y');
     //DO-WHILE ENDS
     cout<<endl;
  return 0;
}

//PROGRAM ENDS

//<----------------------------------OUTPUT----------------------------------->
/*

********************* MENU *********************

	1. To accept and display integer array
	2. To make *default* array
	3. To assign one array to another pre-existing array
	4. To find size of the array
	5. To perform range checking 

CHOICE: 1
________________________________________________________________
Enter element: 1
Enter another element (y/n)? y
Enter element: 2
Enter another element (y/n)? y
Enter element: 3
Enter another element (y/n)? y
Enter element: 4
Enter another element (y/n)? n

Array is: | 1 | 2 | 3 | 4 | 

===========================================================
Do you want to continue (y/n)? y
===========================================================

********************* MENU *********************

	1. To accept and display integer array
	2. To make *default* array
	3. To assign one array to another pre-existing array
	4. To find size of the array
	5. To perform range checking 

CHOICE: 2
________________________________________________________________
a6:
Array is: | 0 | 

NEW:
Array is: | 0 | 

===========================================================
Do you want to continue (y/n)? y
===========================================================

********************* MENU *********************

	1. To accept and display integer array
	2. To make *default* array
	3. To assign one array to another pre-existing array
	4. To find size of the array
	5. To perform range checking 

CHOICE: 3
________________________________________________________________
		Enter SOURCE arrays
Enter element: 1
Enter another element (y/n)? y
Enter element: 2
Enter another element (y/n)? y
Enter element: 3
Enter another element (y/n)? y
Enter element: 4
Enter another element (y/n)? n

Array is: | 1 | 2 | 3 | 4 | 

		Enter DESTINATION arrays
Enter element: 11
Enter another element (y/n)? y
Enter element: 22
Enter another element (y/n)? y
Enter element: 33
Enter another element (y/n)? y
Enter element: 44
Enter another element (y/n)? n

Array is: | 11 | 22 | 33 | 44 | 

-------------------- OLD: --------------------
	
Array is: | 11 | 22 | 33 | 44 | 

-------------------- NEW: --------------------
	
Array is: | 1 | 2 | 3 | 4 | 

===========================================================
Do you want to continue (y/n)? y
===========================================================

********************* MENU *********************

	1. To accept and display integer array
	2. To make *default* array
	3. To assign one array to another pre-existing array
	4. To find size of the array
	5. To perform range checking 

CHOICE: 4
________________________________________________________________
Enter element: 23
Enter another element (y/n)? y
Enter element: 5
Enter another element (y/n)? y
Enter element: 58
Enter another element (y/n)? y
Enter element: 14 
Enter another element (y/n)? y 
Enter element: 13
Enter another element (y/n)? n

Array is: | 23 | 5 | 58 | 14 | 13 | 

The length of array is: 5
===========================================================
Do you want to continue (y/n)? y
===========================================================

********************* MENU *********************

	1. To accept and display integer array
	2. To make *default* array
	3. To assign one array to another pre-existing array
	4. To find size of the array
	5. To perform range checking 

CHOICE: 5
________________________________________________________________
Enter element: 1
Enter another element (y/n)? y
Enter element: 2
Enter another element (y/n)? y
Enter element: 3
Enter another element (y/n)? y
Enter element: 4
Enter another element (y/n)? y
Enter element: 5
Enter another element (y/n)? y
Enter element: 6
Enter another element (y/n)? y
Enter element: 7
Enter another element (y/n)? y
Enter element: 8
Enter another element (y/n)? y
Enter element: 9
Enter another element (y/n)? y
Enter element: 10
Enter another element (y/n)? y
Enter element: 11
Enter another element (y/n)? y

! ARRAY OUT OF BOUND

Array is: | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 

===========================================================
Do you want to continue (y/n)? n
===========================================================

*/



/*int cpparray::operator[](int i)					//SUBSCRIPT OPERATOR OVERLOADING
{
  if(i>=0 && i<3)
    return i;
  else
     return 0;
}*/





