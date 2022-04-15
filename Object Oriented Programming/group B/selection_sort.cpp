//============================================================================
// Name        : selection_sort.cpp
// Author      : Sneha Bandi
// Roll No.    : 2401
// Description : Selection sort for integer and float array using template
//============================================================================

#include <iostream>
using namespace std;
//SORTING BY METHOD 1
//TEMPLATIZED FUNCTION (GLOBALLY DEFINED)
template <class T>
void sort(T a[],int n)
{
	int loc;
	T min;
	T temp;
	for(int i=0;i<n;i++)
	{
		min=a[i];
		loc=i;
	  for(int j=(i+1);j<n;j++)
		{
		 if(min>a[j])
		 {
			 min=a[j];
			 loc=j;
		 }
		}
//SWAPPING
	     temp=a[i];
	     a[i]=a[loc];
	     a[loc]=temp;


	}

}

//SORTING BY METHOD 2
//TEMPLATIZED FUNCTION (GLOBALLY DEFINED)
template <class T>
void sort_(T a[],int n)
{
	int small;
	T temp;
	for(int i=0;i<n;i++)
	{
		small=i;
	  for(int j=(i+1);j<n;j++)
		{
		 if(a[small]>a[j])
		 {
			 small=j;
		 }
		}
//SWAPPING
	     temp=a[i];
	     a[i]=a[small];
	     a[small]=temp;


	}
}


//main
int main() 
{
	int n,m,p,q,t;
	char choice;
	
	cout<<"\n\tTHIS PROGRAM IS TO PERFORM SORTING OF INTEGER & FLOAT ARRAYS!\n";
	
	//do-while loop
	do{
	cout<<"Select the method to performing sorting!\n  PRESS:\n\t1.for Method 1\n\t2.for Method 2\n";
	cin>>t;
	//SWITCH CASE FOR METHOD 1 OR 2
	switch(t)
	{
	//METHOD 1
	case 1:
		cout<<"\n\tMETHOD 1:\n";
		cout<<"==============================================================\n";
		//ACCEPTING INPUT FOR INTEGER ARRAY 
		cout<<"************************** INTEGER **************************\n";
		cout<<"Enter number of elements to be sorted: ";
		cin>>n;
		int A[30];
		cout<<"\nEnter the (integer)numbers for sorting:\n";
		for(int i=0;i<n;i++)
		{
		  cin>>A[i];
		}
		sort_(A,n);
		//DISPLAYING INTEGER SORTED ARRAY;
		cout<<"\nSorted list is:\n";
		for(int i=0;i<n;i++)
		{
		  cout<<A[i]<<"\t";
		}
		cout<<"\n";

		//ACCEPTING INPUT FOR FLOAT ARRAY 
		cout<<"************************** FLOAT **************************\n";
		cout<<"Enter number of elements to be sorted: ";
		cin>>m;
		float B[30];
		cout<<"\nEnter the (float)numbers for sorting:\n";
		for(int i=0;i<m;i++)
		{
		  cin>>B[i];
		}
		sort(B,m);
		//DISPLAYING FLOAT SORTED ARRAY;
		cout<<"\nSorted list is:\n";
		for(int i=0;i<m;i++)
		{
		  cout<<B[i]<<"\t";
		}
		cout<<"\n";
		cout<<"==============================================================\n";
		break;
	//METHOD 2
	case 2:
		cout<<"\n\tMETHOD 2:\n";
		//ACCEPTING INPUT FOR INTEGER ARRAY 
		cout<<"************************** INTEGER **************************\n";
		cout<<"Enter number of elements to be sorted: ";
		cin>>p;
		int C[30];
		cout<<"\nEnter the (integer)numbers for sorting:\n";
		for(int i=0;i<p;i++)
		{
		  cin>>C[i];
		}
		sort_(C,p);
		//DISPLAYING INTEGER SORTED ARRAY;
		cout<<"\nSorted list is:\n";
		for(int i=0;i<p;i++)
		{
		  cout<<C[i]<<"\t";
		}
		cout<<"\n";

		//ACCEPTING INPUT FOR FLOAT ARRAY 
		cout<<"************************** FLOAT **************************\n";
		cout<<"Enter number of elements to be sorted: ";
		cin>>q;
		float D[30];
		cout<<"\nEnter the (float)numbers for sorting:\n";
		for(int i=0;i<q;i++)
		{
		  cin>>D[i];
		}
		sort(D,q);
		//DISPLAYING FLOAT SORTED ARRAY;
		cout<<"\nSorted list is:\n";
		for(int i=0;i<q;i++)
		{
		  cout<<D[i]<<"\t";
		}
		cout<<"\n==============================================================\n";
		break;
	default :
		cout<<"\n!ENTER VALID CHOICE!\n";
		break;
			
	}
	//SWITCH CASE ENDS!
	cout<<"\nDo you want to continue (y/n)?\t";
	cin>>choice;
	cout<<"==============================================================\n";
	}while(choice=='Y'||choice=='y');
	
	return 0;
}

//PROGRAM ENDS
//<-------------------------------------- OUTPUT ----------------------------------------->
/*

	THIS PROGRAM IS TO PERFORM SORTING OF INTEGER & FLOAT ARRAYS!
Select the method to performing sorting!
  PRESS:
	1.for Method 1
	2.for Method 2
1

	METHOD 1:
==============================================================
************************** INTEGER **************************
Enter number of elements to be sorted: 8

Enter the (integer)numbers for sorting:
1	3	7	9	8	6	6	4

Sorted list is:
1	3	4	6	6	7	8	9	
************************** FLOAT **************************
Enter number of elements to be sorted: 6

Enter the (float)numbers for sorting:
9.26	3.54	8.19	5.22	5.19	6.20

Sorted list is:
3.54	5.19	5.22	6.2	8.19	9.26	
==============================================================

Do you want to continue (y/n)?	y
==============================================================
Select the method to performing sorting!
  PRESS:
	1.for Method 1
	2.for Method 2
2

	METHOD 2:
************************** INTEGER **************************
Enter number of elements to be sorted: 8

Enter the (integer)numbers for sorting:
1	6	8	4	3	5	9	2

Sorted list is:
1	2	3	4	5	6	8	9	
************************** FLOAT **************************
Enter number of elements to be sorted: 7

Enter the (float)numbers for sorting:
1.19	2.19	2.26	2.15	2.15	4.89	0.25

Sorted list is:
0.25	1.19	2.15	2.15	2.19	2.26	4.89	
==============================================================

Do you want to continue (y/n)?	n
==============================================================
*/

