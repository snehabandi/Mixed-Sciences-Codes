//============================================================================
// Name        : search.cpp
// Author      : Sneha Bandi
// Roll No.    : 2401
// Description : Bubble sort and Selection Sort of first year percentages
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
 void bubble_sort();
 void selection_sort();
 void bubble_sort_d();
 void selection_sort_d();
};
void sorting::accept()
 {
	 cout<<"\nEnter size of array : ";
	 cin>>size;
	 cout<<"Enter percentages of array : ";
	 for(int i=0;i<size;i++)
	 {
//		 cout<<"\nPercent "<<(i+1)<<" : ";
		 cin>>a[i];
	 }
 }
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
void sorting::bubble_sort()
{
	//BUBBLE SORT
	float temp;
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
		cout<<"\nPass "<<i<<" : ";
		 for(int p=0;p<size;p++)
			 cout<<"\t"<<a[p];
	}
	//BUBBLE SORT ENDS

}
void sorting::selection_sort()
{
//SELECTION SORT
int small=0;
float temp;
for(int i=0;i<size;i++)
{
	small=i;
	for(int j=(i+1);j<size;j++)
	{
		if(a[small]>a[j])
		{
			small=j;
		}
		temp=a[small];
		a[small]=a[i];
		a[i]=temp;
	}
}
 for(int p=0;p<size;p++)
	 cout<<"\t"<<a[p];
//SELECTION ENDS
}
void sorting::bubble_sort_d()
{
	//BUBBLE SORT
	float temp;
	for(int i=0;i<size-1;i++)
	{
		for(int j=0;j<size-i-1;j++)
		{
			if(a[j+1]>a[j])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}

		}
	}
	 for(int p=0;p<5;p++)
		 cout<<"\t"<<a[p];
	//BUBBLE SORT ENDS

}
void sorting::selection_sort_d()
{
//SELECTION SORT
int small=0;
float temp;
for(int i=0;i<size;i++)
{
	small=i;
	for(int j=(i+1);j<size;j++)
	{
		if(a[small]>a[j])
		{
			small=j;
		}
		temp=a[small];
		a[small]=a[i];
		a[i]=temp;
	}
	cout<<"\nPass "<<i<<" : ";
	 for(int p=0;p<5;p++)
		 cout<<"\t"<<a[p];
}
//SELECTION ENDS
}

int main() {
	sorting s1,s2,s3,s4;
	int x,n,y;
	char choice;
	cout<<"=============================================\n";

	do{
		cout<<"\n\t\t\tMENU\n";
		cout<<"\n1.Accept-Display\n2.Bubble Sort\n3.Selection Sort\nCHOICE: ";
		cin>>n;
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
			s2.bubble_sort();
			cout<<"\n\nThe sorted array is : ";
			s2.display();
			cout<<"\n\nThe top 5 percentages are : ";
			//s2.display_top();
			s2.bubble_sort_d();
			break;
		case 3:
			s3.accept();
			cout<<"\nArray : ";
			s3.display();
			s3.selection_sort();
			cout<<"\n\nThe sorted array is : ";
			s3.display();
			cout<<"\n\nThe top 5 percentages are : ";
			//s3.display_top();
			s3.selection_sort_d();
			s3.display();
			break;
		}
		cout<<"\n\nDo you want to continue (y/n)? ";
		cin>>choice;
		cout<<"=============================================\n";

	}while(choice=='y'||choice=='Y');
	return 0;
}
/*
=============================================

			MENU

1.Accept-Display
2.Bubble Sort
3.Selection Sort
CHOICE: 3

Enter size of array : 7
Enter percentages of array : 90.25	82.23	70.599	88.86	55.24	72.19	22.24

Array : 	90.25	82.23	70.599	88.86	55.24	72.19	22.24
Pass 0 : 	22.24	90.25	70.599	88.86	82.23	55.24	72.19
Pass 1 : 	22.24	70.599	90.25	88.86	82.23	55.24	72.19
Pass 2 : 	22.24	70.599	72.19	90.25	88.86	82.23	55.24
Pass 3 : 	22.24	70.599	72.19	55.24	90.25	88.86	82.23
Pass 4 : 	22.24	70.599	72.19	55.24	82.23	90.25	88.86
Pass 5 : 	22.24	70.599	72.19	55.24	82.23	88.86	90.25
Pass 6 : 	22.24	70.599	72.19	55.24	82.23	88.86	90.25

The sorted array is : 	22.24	70.599	72.19	55.24	82.23	88.86	90.25

The top 5 percentages are : 90.25	88.86	82.23	55.24	72.19

Do you want to continue (y/n)? y
=============================================

			MENU

1.Accept-Display
2.Bubble Sort
3.Selection Sort
CHOICE: 2

Enter size of array : 7
Enter percentages of array : 90.25	82.23	70.599	88.86	55.24	72.19	22.24

Array : 	90.25	82.23	70.599	88.86	55.24	72.19	22.24
Pass 0 : 	82.23	70.599	88.86	55.24	72.19	22.24	90.25
Pass 1 : 	70.599	82.23	55.24	72.19	22.24	88.86	90.25
Pass 2 : 	70.599	55.24	72.19	22.24	82.23	88.86	90.25
Pass 3 : 	55.24	70.599	22.24	72.19	82.23	88.86	90.25
Pass 4 : 	55.24	22.24	70.599	72.19	82.23	88.86	90.25
Pass 5 : 	22.24	55.24	70.599	72.19	82.23	88.86	90.25

The sorted array is : 	22.24	55.24	70.599	72.19	82.23	88.86	90.25

The top 5 percentages are : 90.25	88.86	82.23	72.19	70.599

Do you want to continue (y/n)? n
=============================================

 */

