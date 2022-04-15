//============================================================================
// Name        : search.cpp
// Author      : Sneha Bandi
// Roll No.    : 2401
// Description : Quick sort of First year percentages
//============================================================================
#include <iostream>
using namespace std;
//SORTING CLASS
class sorting
{
 int size;
 float a[20];
 float start,end;
public:
 int accept();
 void display();
 void display_top();
 void display_low();
 void quick_sort(int,int);
 void quick_sort_d(int,int);
};
//ACCEPTANCE OF PERCENTAGES
int sorting::accept()
 {
	 cout<<"\nEnter size of array : ";
	 cin>>size;
	 cout<<"Enter percentages of array : ";
	 for(int i=0;i<size;i++)
	 {
		 cin>>a[i];
	 }
	 return size;
 } void display_top();
//DISPLAY OF ENTIRE LIST OF PERCENTAGES
void sorting::display()
{
	 cout<<endl;

	 for(int i=0;i<size;i++)
		 cout<<"\t"<<a[i];
	 cout<<endl;
}
//DISPLAY OF TOP 5 SCORES
void sorting::display_top()
{
	 for(int i=0;i<5;i++)
		 cout<<"\t"<<a[i];
	 cout<<endl;
}
//DISPLAY OF LOWEST 5 SCORES
void sorting::display_low()
{
	 cout<<endl;
	 for(int i=0;i<5;i++)
		 cout<<"\t"<<a[i];
	 cout<<endl;
}
void sorting::quick_sort(int start,int end)
{
	float temp,temp1;
	int pivot,i,j;
	//start=start-1;
	if(start<end)
	{
	  pivot=start;
	  i=start;
	  j=end;
	  while(i<j)
	  {
	    while(a[i]<=a[pivot])
		i++;
	    while(a[j]>a[pivot])
		j--;
	//SWAP ith and jth ELEMENTS
	    if(i<=j)	
	    {
		  temp=a[i];
		  a[i]=a[j];
		  a[j]=temp;
	    }
	//DISPLAYING INTERNAL PASS ITERATIONS
//	cout<<"\n\t\t\t";
//	display();

	}
	 //SWAP PIVOT ELEMENT AND jth ELEMENT
	 temp1=a[pivot];
	 a[pivot]=a[j];
	 a[j]=temp1;
	//DISPLAY PASS
	cout<<"\npass :";
	for(int k=0;k<size;k++)
	   cout<<"\t"<<a[k];
//RECURSIVE CALLS	
     quick_sort(start,j-1);
     quick_sort(j+1,end);
  }
}
void sorting::quick_sort_d(int start,int end)
{
 float temp,temp1;
 int pivot,i,j;
 if(start>=end)
 {
   pivot=start;
   i=start;
   j=end;
   while(i>j)
   {
    while(a[i]<a[pivot])
	i--;
    while(a[j]>=a[pivot])
	j++;
   //SWAP ith and jth ELEMENTS
     if(i>=j)
     {
      temp=a[i];
      a[i]=a[j];
      a[j]=temp;
     }
	//DISPLAYING INTERNAL PASS ITERATIONS
//	cout<<"\n\t\t\t";
//	display();
   }
	 //SWAP PIVOT ELEMENT AND ith ELEMENT
   temp1=a[pivot];
   a[pivot]=a[i];
   a[i]=temp1;
  //DISPLAY PASS
  cout<<"\n pass :";
   for(int k=0;k<size;k++)
	 cout<<"\t"<<a[k];
  //RECURSIVE CALLS	
	quick_sort_d(i-1,end);
	quick_sort_d(start,i+1);
	}
}
int main() {
	sorting s1,s2;
	int s=0,e,n;
	char ans;
	cout<<"=============================================\n";
	cout<<"\n\t\t\tPROGRAM FOR FIRST YEAR PERCENTAGES \n";
	do{
		cout<<"\n\t\t\t\tMENU";
	   cout<<"\n\t1.Top 5 percentages (ascending sorted list)";
	   cout<<"\n\t2.Lowest 5 percentages (descending sorted list)\nCHOICE : ";
	   cin>>n;
	   switch(n)
	   {
	    case 1:
	//ASCENDING ORDER OF PERCENTAGES
		e=s1.accept();
		cout<<"\nArray : ";
		s1.display();
		s1.quick_sort(s,e-1);
		cout<<"\n\nThe sorted array is : ";
		s1.display();
		s1.quick_sort_d(e-1,s);//DESCENDING QUICK SORT : TO DISPLAY TOP 5 PERCENTAGES
		cout<<"\n\nThe top 5 percentages are : ";
		s1.display_top();
		break;
	//DESCENDING ORDER OF PERCENTAGES
	    case 2:
		e=s2.accept();
		cout<<"\nArray : ";
		s2.display();
		s2.quick_sort_d(e-1,s);
		cout<<"\n\nThe sorted array is : ";
		s2.display();
		s2.quick_sort(s,e-1);//ASCENDING QUICK SORT : TO DISPLAY LOWEST 5 PERCENTAGES
		cout<<"\n\nThe lowest 5 percentages are : ";
		s2.display_low();
	   }
		cout<<"\nDo you want to continue (y/n)?\t";
		cin>>ans;
		cout<<"\n\n=============================================\n";
	}while(ans=='y');
  return 0;
}
//PROGRAM ENDS
//------------------------------------------- OUTPUT --------------------------------------->
/*
=============================================

			PROGRAM FOR FIRST YEAR PERCENTAGES 

				MENU
	1.Top 5 percentages (ascending sorted list)
	2.Lowest 5 percentages (descending sorted list)
CHOICE : 1

Enter size of array : 7
Enter percentages of array : 65.56	75.29	80.02	63.29	61.27	55.55	90.27

Array : 
	65.56	75.29	80.02	63.29	61.27	55.55	90.27

pass :	63.29	55.55	61.27	65.56	80.02	75.29	90.27
pass :	61.27	55.55	63.29	65.56	80.02	75.29	90.27
pass :	55.55	61.27	63.29	65.56	80.02	75.29	90.27
pass :	55.55	61.27	63.29	65.56	75.29	80.02	90.27

The sorted array is : 
	55.55	61.27	63.29	65.56	75.29	80.02	90.27

 pass :	90.27	61.27	63.29	65.56	75.29	80.02	55.55
 pass :	90.27	80.02	63.29	65.56	75.29	61.27	55.55
 pass :	90.27	80.02	75.29	65.56	63.29	61.27	55.55
 pass :	90.27	80.02	75.29	65.56	63.29	61.27	55.55
 pass :	90.27	80.02	75.29	65.56	63.29	61.27	55.55
 pass :	90.27	80.02	75.29	65.56	63.29	61.27	55.55
 pass :	90.27	80.02	75.29	65.56	63.29	61.27	55.55

The top 5 percentages are : 	90.27	80.02	75.29	65.56	63.29

Do you want to continue (y/n)?	y


=============================================

				MENU
	1.Top 5 percentages (ascending sorted list)
	2.Lowest 5 percentages (descending sorted list)
CHOICE : 2

Enter size of array : 7
Enter percentages of array : 65.56	75.29	80.02	63.29	61.27	55.55	90.27

Array : 
	65.56	75.29	80.02	63.29	61.27	55.55	90.27

 pass :	90.27	75.29	80.02	65.56	63.29	61.27	55.55
 pass :	90.27	75.29	80.02	65.56	63.29	61.27	55.55
 pass :	90.27	75.29	80.02	65.56	63.29	61.27	55.55
 pass :	90.27	75.29	80.02	65.56	63.29	61.27	55.55
 pass :	90.27	80.02	75.29	65.56	63.29	61.27	55.55
 pass :	90.27	80.02	75.29	65.56	63.29	61.27	55.55
 pass :	90.27	80.02	75.29	65.56	63.29	61.27	55.55

The sorted array is : 
	90.27	80.02	75.29	65.56	63.29	61.27	55.55

pass :	55.55	80.02	75.29	65.56	63.29	61.27	90.27
pass :	55.55	80.02	75.29	65.56	63.29	61.27	90.27
pass :	55.55	61.27	75.29	65.56	63.29	80.02	90.27
pass :	55.55	61.27	75.29	65.56	63.29	80.02	90.27
pass :	55.55	61.27	63.29	65.56	75.29	80.02	90.27
pass :	55.55	61.27	63.29	65.56	75.29	80.02	90.27

The lowest 5 percentages are : 
	55.55	61.27	63.29	65.56	75.29

Do you want to continue (y/n)?	n


=============================================

*/
