//============================================================================
// Name        : search.cpp
// Author      : Sneha Bandi
// Roll No.    : 2401
// Description : Searching technique implementation 
//			(linear,sentinel,binar,Fibonacci)
//============================================================================
#include <iostream>
using namespace std;
//class search
class search
{
 int low,high,mid;
 int key,size;
 int a[20];
public:
 search()
{
	 low=0;
}
 void accept();
 void display();
 void linear_search();
 void sentinel_search();
 int binary_search();
 int fibo(int);
 int fibonacci_search();
 void bubble_sort();
};
//Array acceptance
void search::accept()
 {
	 cout<<"\nEnter size of array : ";
	 cin>>size;
	 cout<<"Enter elements of array : ";
	 for(int i=0;i<size;i++)
		 cin>>a[i];

 }
//Array displayed
void search::display()
{
	 for(int i=0;i<size;i++)
		 cout<<a[i]<<"\t";
}
//linear search
void search::linear_search()
 {
	 int flag=0,i=0;
	 cout<<"\nEnter the element to be searched : ";
	 cin>>key;
	 for(i=0;i<size;i++)
	 {
		 if(a[i]==key)
		 {
			 flag=1;	//flag set to 1 if key matches
			 break;
		 }
	 }
if(flag==1)
	cout<<"\nElement FOUND !!\nAT position "<<i;
else
	cout<<"\nElement NOT found !!\n";
 }
//sentinel search
void search::sentinel_search()
 {
	 int flag=0,i=0;
	 cout<<"\nEnter the element to be searched : ";
	 cin>>key;
	 a[size]=key;			//element first added at the beginning
	while(key!=a[i] && i!=size)
	{
	  i++;
	}
  if(i==size)
  {
	cout<<"\n\nElement NOT found !! \n(NOTE : Element is added at the end)\n";
	size=size+1;
  }
   else
	cout<<"\n\nElement FOUND !!\nAT position "<<i<<endl;
}
//binary search
 int search::binary_search()
 {
	 //high=x.size;
	 high=(size-1);
	cout<<"\nsize:"<<size;
	 cout<<"\nEnter the element to be searched : ";
	 cin>>key;
	 while(low<=high)
	 {
	 mid=(low+high)/2;
	 if(a[mid]==key)
	 {
		 cout<<"\nElement found";
	  return mid;
	 }
	 else if(key<a[mid])		//key is in left half
		 high=mid-1;
	 else if(key>a[mid])		//key is in right half
		 low=mid+1;
	 }
	 return -1;
 }
//binary and Fibonacci search require sorted inputs
void search::bubble_sort()
{
	//BUBBLE SORT
	int temp;
	for(int i=0;i<size-1;i++)
	{
		for(int j=0;j<size-i-1;j++)
		{
			if(a[j+1]<a[j])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}

		}
	}
	//BUBBLE SORT ENDS

}
//Fibonacci series generation
int search::fibo(int n)
{
if(n==0||n==1)
	return 1;
else
	return (fibo(n-1)+fibo(n-2));
}
//Fibonacci search
int search::fibonacci_search()
{
	cout<<"\nEnter the key to be searched : ";
	cin>>key;
	int f,f1,f2,t,mid,j;
	j=1;
	while(fibo(j)<size)
		j++;

	f=fibo(j);
	f1=fibo(j-2);
	f2=fibo(j-3);
	mid=size-f1+1;

	while(key!=a[mid])
	{
		if(mid<0||key>a[mid])
		{
			if(f1==1)
				return -1;
			mid=mid+f2;
			f1=f1-f2;
			f2=f2-f1;
		}
		else
		{
			if(f2==0)
				return -1;
			mid=mid-f2;
			t=f1-f2;
			f1=f2;
			f2=t;
		}

	}
return mid;
}
//main
int main() {
	search s1,s2,s3,s4;
	int x,n,y;
	char choice;
	cout<<"=============================================\n";
//do-while starts
	do{
		cout<<"\n\t\t\tMENU\nPRESS : \n";
		cout<<"\n\t1.Linear Search\n\t2.Sentinel Search\n\t3.Binary Search\n\t4.Fibonacci Search\nCHOICE: ";
		cin>>n;
cout<<"_____________________________________________________________\n";
//switch starts
		switch(n)
		{
		case 1:
			s1.accept();
			cout<<"The entered array is : ";
			s1.display();
			s1.linear_search();
			break;
		case 2:
			s2.accept();
			cout<<"\nThe entered array is : ";
			s2.display();
			s2.sentinel_search();
			cout<<"\nThe array after search is : ";
			s2.display();
			break;
		case 3:
			s3.accept();
			cout<<"The entered array is : ";
			s3.display();
			s3.bubble_sort();
			cout<<"\nThe sorted array is : ";
			s3.display();
			x=s3.binary_search();
			if(x==-1)
				 cout<<"\nElement NOT found !!\n";
			else
				cout<<" at position "<<x<<endl;
			break;
		case 4:
			s4.accept();
			cout<<"The entered array is : ";
			s4.display();
			s4.bubble_sort();
			cout<<"\nThe sorted array is : ";
			s4.display();
			y=s4.fibonacci_search();
			if(y==-1)
				 cout<<"\nElement NOT found !!\n";
			else
				cout<<" at position "<<y<<endl;
		}
//switch ends
		cout<<"\n=============================================";
		cout<<"\nDo you want to continue (y/n)? ";
		cin>>choice;
		cout<<"=============================================\n";

	}while(choice=='y'||choice=='Y');
//do-while ends
	return 0;
}
//<-------------------------------- OUTPUT ----------------------------------->
/*
=============================================

			MENU
PRESS : 

	1.Linear Search
	2.Sentinel Search
	3.Binary Search
	4.Fibonacci Search
CHOICE: 1
_____________________________________________________________-

Enter size of array : 5
Enter elements of array : 1	3	5	2	4
The entered array is : 1	3	5	2	4	
Enter the element to be searched : 2

Element FOUND !!
AT position 3
=============================================
Do you want to continue (y/n)? y
=============================================

			MENU
PRESS : 

	1.Linear Search
	2.Sentinel Search
	3.Binary Search
	4.Fibonacci Search
CHOICE: 
1
_____________________________________________________________-

Enter size of array : 5
Enter elements of array : 1	3	5	2	4
The entered array is : 1	3	5	2	4	
Enter the element to be searched : 6

Element NOT found !!

=============================================
Do you want to continue (y/n)? y
=============================================

			MENU
PRESS : 

	1.Linear Search
	2.Sentinel Search
	3.Binary Search
	4.Fibonacci Search
CHOICE: 2
_____________________________________________________________-

Enter size of array : 5	 	 	 	
Enter elements of array : 1	3	5	2	4

The entered array is : 1	3	5	2	4	
Enter the element to be searched : 4


Element FOUND !!
AT position 4

The array after search is : 1	3	5	2	4	
=============================================
Do you want to continue (y/n)? y
=============================================

			MENU
PRESS : 

	1.Linear Search
	2.Sentinel Search
	3.Binary Search
	4.Fibonacci Search
CHOICE: 2
_____________________________________________________________-

Enter size of array : 5
Enter elements of array : 1	3	5	2	4

The entered array is : 1	3	5	2	4	
Enter the element to be searched : 6


Element NOT found !! 
(NOTE : Element is added at the end)

The array after search is : 1	3	5	2	4	6	
=============================================
Do you want to continue (y/n)? y
=============================================

			MENU
PRESS : 

	1.Linear Search
	2.Sentinel Search
	3.Binary Search
	4.Fibonacci Search
CHOICE: 3
_____________________________________________________________-

Enter size of array : 6	 
Enter elements of array : 1	3	5	2	4	0
The entered array is : 1	3	5	2	4	0	
The sorted array is : 0	1	2	3	4	5	
size:6
Enter the element to be searched : 3

Element found at position 3

=============================================
Do you want to continue (y/n)? y
=============================================

			MENU
PRESS : 

	1.Linear Search
	2.Sentinel Search
	3.Binary Search
	4.Fibonacci Search
CHOICE: 3
_____________________________________________________________-

Enter size of array : 6
Enter elements of array : 1	3	5	2	4	0
The entered array is : 1	3	5	2	4	0	
The sorted array is : 0	1	2	3	4	5	
size:6
Enter the element to be searched : 7

Element NOT found !!

=============================================
Do you want to continue (y/n)? y
=============================================

			MENU
PRESS : 

	1.Linear Search
	2.Sentinel Search
	3.Binary Search
	4.Fibonacci Search
CHOICE: 4
_____________________________________________________________-

Enter size of array : 7
Enter elements of array : 1	3	8	2	4	5	0
The entered array is : 1	3	8	2	4	5	0	
The sorted array is : 0	1	2	3	4	5	8	
Enter the key to be searched : 4
Element found !!
 at position 4

=============================================
Do you want to continue (y/n)? y
=============================================

			MENU
PRESS : 

	1.Linear Search
	2.Sentinel Search
	3.Binary Search
	4.Fibonacci Search
CHOICE: 4
_____________________________________________________________-

Enter size of array : 5
Enter elements of array : 1	3	5	2	4
The entered array is : 1	3	5	2	4	
The sorted array is : 1	2	3	4	5	
Enter the key to be searched : 6

Element NOT found !!

=============================================
Do you want to continue (y/n)? n
=============================================

*/
