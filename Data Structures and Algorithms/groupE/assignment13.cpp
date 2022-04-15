//============================================================================
// Name        : search.cpp
// Author      : Sneha Bandi
// Roll No.    : 2401
// Description : Insertion sort and Shell sort of second year percentages
//============================================================================
#include <iostream>
using namespace std;
class sorting
{
 int size;
 float a[20];
public:
 void accept();
 void display();
 void display_top();
 void shell_sort();			//ASCENDING SHELL SORT
 void insertion_sort();			//ASCENDING INSERTION SORT
 void shell_sort_d();			//DESCENDING SHELL SORT
 void insertion_sort_d();		//DESCENDING INSERTION SORT
};

//ACCEPTANCE OF PERCENTAGES
void sorting::accept()
 {
	 cout<<"\nEnter size of array : ";
	 cin>>size;
	 cout<<"Enter percentages of array : ";
	 for(int i=0;i<size;i++)
	 {
		 cin>>a[i];
	 }
 }
//DISPLAYING THE PERCENTAGES
void sorting::display()
{
	 for(int i=0;i<size;i++)
		 cout<<"\t"<<a[i];
}
void sorting::display_top()
{
	 for(int i=(size-1);i>(size-6);i--)
		 cout<<a[i]<<"\t";
}
//INSERTION SORT IN ASCENDING ORDER
void sorting::insertion_sort()
{
 int i,j;
 float temp;
 for(i=0;i<(size-1);i++)
 {
	 temp=a[i];
	 j=i-1;
	 while((j>=0)&&(a[j]>temp))
	 {
		 a[j+1]=a[j];
		 j--;
	 }
	a[j+1]=temp;
	cout<<"\nPass "<<i<<" : ";
	 for(int p=0;p<size;p++)
		 cout<<"\t"<<a[p];
 }
}
//SHELL SORT IN ASCENDING ORDER
void sorting::shell_sort()
{
int i,j,k;
float temp;
for(i=(size/2);i>=1;i=i/2)
{
	for(j=i;j<=(size-1);j++)			//INSERTION SORT APPLIED ON EACH SHELL OF ELEMENTS
	{
		temp=a[j];
		k=j-i;
		while((k>=0) && (a[k]>temp))
		{
			a[k+i]=a[k];
			k=k-i;

		}
		a[k+i]=temp;			//INSERTION SORT ENDS
	}
	cout<<"\nPass : ";			//PASS DISPLAYED
	 for(int p=0;p<size;p++)
		 cout<<"\t"<<a[p];
}
}
//INSERTION SORT IN DESCENDING ORDER
void sorting::insertion_sort_d()
{
 int i,j;
 float temp;
 for(i=0;i<(size-1);i++)
 {
	 temp=a[i];
	 j=i-1;
	 while((j>=0)&&(a[j]<temp))
	 {
		 a[j+1]=a[j];
		 j--;
	 }
	a[j+1]=temp;
 }
 for(int p=0;p<5;p++)
	 cout<<"\t"<<a[p];
}
//SHELL SORT IN DESCENDING ORDER
void sorting::shell_sort_d()
{
int i,j,k;
float temp;
for(i=(size/2);i>=1;i=i/2)
{
	for(j=i;j<=(size-1);j++)			//INSERTION SORT APPLIED ON EACH SHELL OF ELEMENTS
	{
		temp=a[j];
		k=j-i;
		while((k>=0) && (a[k]<temp))
		{
			a[k+i]=a[k];
			k=k-i;

		}
		a[k+i]=temp;
	}						//INSERTION SORT ENDS
}
for(int p=0;p<5;p++)
	 cout<<"\t"<<a[p];				//PASS DISPLAYED
}
//MAIN
int main() 
{
  sorting s1,s2,s3;
  int n;
  char choice;
	cout<<"=============================================\n";
//DO-WHILE BEGINS
	do{
		cout<<"\n\t\t\tMENU\n";
		cout<<"\n1.Accept-Display\n2.Insertion Sort\n3.Shell Sort\nCHOICE: ";
		cin>>n;
	//SWITCH CASE STARTS
		switch(n)
		{
		case 1:
			s1.accept();
			cout<<"\nArray : ";
			s1.display();
			break;
		case 2:
			s2.accept();
			cout<<"\nArray : ";
			s2.display();
			s2.insertion_sort();
			cout<<"\n\nThe sorted array is : ";
			s2.display();
			cout<<"\n\nThe top 5 percentages are : ";
			//s2.display_top();
			s2.insertion_sort_d();			//LIST SORTED IN DESCENDING ORDDER AND TOP FIVE DISPLAYED
			break;
		case 3:
			s3.accept();
			cout<<"\nArray : ";
			s3.display();
			s3.shell_sort();
			cout<<"\n\nThe sorted array is : ";
			s3.display();
			cout<<"\n\nThe top 5 percentages are : ";
			//s3.display_top();
			s3.shell_sort_d();			//LIST SORTED IN DESCENDING ORDDER AND TOP FIVE DISPLAYED
			break;
		}
	//SWITCH CASE ENDS
		cout<<"\n\nDo you want to continue (y/n)? ";
		cin>>choice;
		cout<<"=============================================\n";
	}while(choice=='y'||choice=='Y');
//DO-WHILE ENDS
  return 0;
}
//<---------------------------------------- OUTPUT ---------------------------------------------->
/*
 =============================================

			MENU

1.Accept-Display
2.Insertion Sort
3.Shell Sort
CHOICE: 2

Enter size of array : 7
Enter percentages of array : 90.25	82.23	70.599	88.86	55.24	72.19	22.24

Array : 	90.25	82.23	70.599	88.86	55.24	72.19	22.24
Pass 0 : 	90.25	82.23	70.599	88.86	55.24	72.19	22.24
Pass 1 : 	82.23	90.25	70.599	88.86	55.24	72.19	22.24
Pass 2 : 	70.599	82.23	90.25	88.86	55.24	72.19	22.24
Pass 3 : 	70.599	82.23	88.86	90.25	55.24	72.19	22.24
Pass 4 : 	55.24	70.599	82.23	88.86	90.25	72.19	22.24
Pass 5 : 	55.24	70.599	72.19	82.23	88.86	90.25	22.24

The sorted array is : 	55.24	70.599	72.19	82.23	88.86	90.25	22.24

The top 5 percentages are : 22.24	90.25	88.86	82.23	72.19

Do you want to continue (y/n)? y
=============================================

			MENU

1.Accept-Display
2.Insertion Sort
3.Shell Sort
CHOICE: 3

Enter size of array : 7
Enter percentages of array : 90.25	82.23	70.599	88.86	55.24	72.19	22.24

Array : 	90.25	82.23	70.599	88.86	55.24	72.19	22.24
Pass 1 : 	22.24	55.24	70.599	88.86	82.23	72.19	90.25
Pass 2 : 	22.24	55.24	70.599	72.19	82.23	88.86	90.25

The sorted array is : 	22.24	55.24	70.599	72.19	82.23	88.86	90.25

The top 5 percentages are : 90.25	88.86	82.23	72.19	70.599

Do you want to continue (y/n)? n
=============================================

 */
