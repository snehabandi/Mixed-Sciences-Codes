//============================================================================
// Name        : assignment9.cpp
// Author      : Sneha Bandi
// Roll No     : 2401
// Copyright   : Your copyright notice
// Description : ADT sets
//		Set Operations: accept,display,union,intersection,difference,
//		remove,add,search,subset
//============================================================================

#include <iostream>
using namespace std;
#define MAX 30
class array_structure
{
	friend class set;
	int array[30];
	int size;
public:
	array_structure()
	{
		size=0;
	}
};
class set
{
	array_structure a;
	int count;
	int result[MAX];
	int res_size;
public:
        void accept();
        void display();

        void search();
        void add();
        void remove();

        void intersect(set&,set&);
        void subset(set&,set&);
        void union_set(set&,set&);
        void difference_AB(set&,set&);
        void display_result();
}setA,setB;
void set::accept()											//Accept Function
{
        cout<<"Enter the size of set : ";
        cin>>a.size;
        cout<<"Enter the elements : ";
        for(int i=0;i<a.size;i++)
        {
                cin>>a.array[i];
//validation code setA array acceptance
                int valid=a.array[i];
                for(int j=0;j<i;j++)
                     {
                        if(valid==a.array[j])
                         {
                        	cout<<"Donot enter same numbers"<<endl;
                        	i--;					//*remember i--; as same value occupied at i(now):overwrite it
                                break;
                         }
                      }
        }
 		cout<<endl;
}
void set::display()											//Display Function
{
	cout<<"{ ";
        for(int i=0;i<a.size;i++)
        {
                cout<<a.array[i];
		if(i!=(a.size-1))
                cout<<" , ";
        }
	cout<<"}\n";
}
void set::display_result()								//Display_result function:to display results
{
	cout<<"{";
	 for(int i=0;i<res_size;i++)
		{
	                cout<<result[i];
			if(i!=(res_size-1))
	        	cout<<" , ";
		}
		cout<<"}\n";
}

void set::add()
{
	int new_element;
	cout<<"\nEnter element to be added : ";
	cin>>new_element;
	a.array[a.size]=new_element;
	a.size++;
}
void set::search()
{
	int key,flag=0;
	cout<<"\nEnter element to be searched : ";
	cin>>key;
	for(int i=0;i<a.size;i++)
	{
		if(a.array[i]==key)
		{
			cout<<"\nSet contains "<<key<<" as an element !!\n";
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\nSet DOES NOT contain "<<key<<" as an element !!\n";

}
void set::remove()
{
	int key,flag=0;
	cout<<"\The requested set is : ";
	display();
	cout<<"\nEnter element to be removed : ";
	cin>>key;
	for(int i=0;i<a.size;i++)
	{
		if(a.array[i]==key)
		{
			flag=1;
			for(int j=i;j<(a.size-1);j++)
				a.array[j]=a.array[j+1];
			a.size--;
			cout<<"\nElement "<<key<<" successfully removed !!\n";
			break;
		}
	}
	if(flag==0)
		cout<<"\nSet DOES NOT contain "<<key<<" as an element !!\n";
}
void set::intersect(set& sA,set& sB)									//Intersection Function
{
	res_size=0;
	cout<<"The intersection setA and setB is : "<<endl;
        for(int i=0;i<sA.a.size;i++)
        {
                int flag=0;
                for(int j=0;j<sB.a.size;j++)
                {
                        if(sA.a.array[i]==sB.a.array[j])
                        {
                                flag=1;
                                break;
                        }
                }
                if(flag==1)
                {
                  result[res_size]=sA.a.array[i];
                  res_size++;
                }
        }
        display_result();
}
void set::union_set(set& sA,set& sB)									//Union Function
{
	res_size=0;
	cout<<"The intersection setA and setB is : "<<endl;
        for(int i=0;i<sA.a.size;i++)
        {
                int flag=0;
                for(int j=0;j<sB.a.size;j++)
                {
                        if(sA.a.array[i]==sB.a.array[j])
                        {
                                flag=1;
                                break;
                        }
                }
                if(flag==1)
                {
                  result[res_size]=sA.a.array[i];
                  res_size++;
                }
        }
        int res_flag;
        for(int i=0;i<sA.a.size;i++)
        {
        	res_flag=0;
        	for(int j=0;j<res_size;j++)
        	{
        		if(sA.a.array[i]==result[j])
        		{
        			res_flag=1;
        			break;
        		}
        	}
        	if(res_flag==0)
        	{
        		result[res_size]=sA.a.array[i];
        		res_size++;
        	}
        }
        display_result();
}
void set::difference_AB(set& sA,set& sB)								//Difference(C-B) Function
{
        res_size=0;
        cout<<"The roll no's of students playing only setA are"<<endl;
        for(int i=0;i<sB.a.size;i++)
        {
                int flag=0;
                for(int j=0;j<sA.a.size;j++)
                {
                        if(sA.a.array[i]==sB.a.array[j])
                        {
                                flag=1;
                                break;
                        }
                }
                if(flag==0)
                {
                  result[res_size]=sA.a.array[i];
                  res_size++;
                }
        }
        display_result();
}
void set::subset(set& sA,set& sB)
{
	int flag_AB,flag_BA;
//For B is a subset of A every element of B is checked if contained in A
//even if one element mismatches (flag_BA = 0) the subset condition FAILS !!
	for(int i=0;i<sB.a.size;i++)
	{
		flag_BA=0;					//B is a subset of A
		for(int j=0;j<sA.a.size;j++)
		{
			if(sB.a.array[i]==sA.a.array[j])
			{
				flag_BA=1;
				break;			//From inner loop
			}
		}
		if(flag_BA==0)
			break;		//From outer loop also
	}
	for(int i=0;i<sA.a.size;i++)
	{
		flag_AB=0;					//A is a subset of B
		for(int j=0;j<sB.a.size;j++)
		{
			if(sA.a.array[i]==sB.a.array[j])
			{
				flag_AB=1;
				break;			//From inner loop
			}
		}
		if(flag_AB==0)
			break;		//From outer loop also

	}
	if(flag_AB!=0 && flag_BA!=0)
		cout<<"\n\t\t1. B is a subset of A; and\n\t\t2. A is a subset of B\n\tThus they are equal sets !!!\n";
	else if(flag_BA!=0)
		cout<<"\n\tB is a subset of A";
	else if(flag_AB!=0)
		cout<<"\n\tA is a subset of B";
	else
		cout<<"\n\t\t1. B is NOT a subset of A; and\n\t\t2. A is NOT a subset of B\n\tThus they are DISJOINT sets !!!\n";

}

//MAIN
int main()
{
	cout<<"\t THIS PROGRAM IS TO PERFORM THE SET OPERATIONS ON THE STUDENT DATA"<<endl;
	int n=0,x=0;
	set s;
	char choice;
	cout<<"\n===========================================================================";
//DO-WHILE STARTS
    do{
	cout<<"\n\n***************************** MENU *****************************"<<endl<<"Press"<<endl;
	cout<<"\n\t1. Accept a set";
	cout<<"\n\t2. Display the set ";
	cout<<"\n\t3. Intersection";
	cout<<"\n\t4. Union ";
	cout<<"\n\t5. Difference";
	cout<<"\n\t6. Subset";
	cout<<"\n\t7. Add an element";
	cout<<"\n\t8. Find if an element exists";
	cout<<"\n\t9. Remove an element";

	cout<<"\nCHOICE: ";
		cin>>n;
//SWITCH CASE STARTS
    switch(n)
	{
	 case 1:
		setA.accept();
        setB.accept();
		 cout<<"\n--------------------------> SET A : ";
       setA.display();
		 cout<<"\n--------------------------> SET B : ";
       setB.display();
		break;
	 case 2:
		 cout<<"\n--------------------------> SET A : ";
       setA.display();
		 cout<<"\n--------------------------> SET B : ";
       setB.display();
		 break;
	 case 3:
		 cout<<"\n--------------------------> SET A : ";
       setA.display();
		 cout<<"\n--------------------------> SET B : ";
       setB.display();
		 s.intersect(setA,setB);
		break;
	 case 4:
		 cout<<"\n--------------------------> SET A : ";
       setA.display();
		 cout<<"\n--------------------------> SET B : ";
       setB.display();
		 s.union_set(setA,setB);
		break;
	 case 5:
		 cout<<"\n--------------------------> SET A : ";
       setA.display();
		 cout<<"\n--------------------------> SET B : ";
       setB.display();
		 s.difference_AB(setA,setB);
		break;
	 case 6:
		 cout<<"\n--------------------------> SET A : ";
       setA.display();
		 cout<<"\n--------------------------> SET B : ";
       setB.display();
			s.subset(setA,setB);
		break;
	 case 7:
		 cout<<"\n--------------------------> SET A : ";
       setA.display();
		 cout<<"\n--------------------------> SET B : ";
       setB.display();
		 cout<<"\n1. SET A\t\t2. SET B ?\t";
		 cin>>x;
		 if(x==1)
		 {
			 setA.add();
			 setA.display();
		 }
		 else
		 {
			 setB.add();
			 setB.display();
		 }
		break;
	 case 8:
		 cout<<"\n1. SET A\t\t2. SET B ?\t";
		 cin>>x;
		 if(x==1)
		 {
			 setA.search();
			 setA.display();
		 }
		 else
		 {
			 setB.search();
			 setB.display();
		 }
		break;
	 case 9:
		 cout<<"\n--------------------------> SET A : ";
       setA.display();
		 cout<<"\n--------------------------> SET B : ";
       setB.display();
		 cout<<"\n\n1. SET A\t\t2. SET B ?\t";
		 cin>>x;
		 if(x==1)
		 {
			 setA.remove();
			 setA.display();
		 }
		 else
		 {
			 setB.remove();
			 setB.display();
		 }
		 break;

	 default:
	        cout<<"Invalid choice"<<endl;
	}//SWITCH CASE ENDS
		cout<<"\n===========================================================================";
		cout<<"\nDo you want to continue (y/n)?\t";
		cin>>choice;
		cout<<"===========================================================================\n";
  }while(choice=='y' || choice=='Y');
//DO-WHILE ENDS
	cout<<endl;
	return 0;
}
//PROGRAM ENDS

//----------------------------->> OUTPUT <<------------------------------
/*
	 	 THIS PROGRAM IS TO PERFORM THE SET OPERATIONS ON THE STUDENT DATA

===========================================================================

***************************** MENU *****************************
Press

	1. Accept a set
	2. Display the set
	3. Intersection
	4. Union
	5. Difference
	6. Subset
	7. Add an element
	8. Find if an element exists
	9. Remove an element
CHOICE: 1
Enter the size of set : 5
Enter the elements : 0	1	2	3	4

Enter the size of set : 4
Enter the elements : 0	2	4	5


--------------------------> SET A : { 0 , 1 , 2 , 3 , 4}

--------------------------> SET B : { 0 , 2 , 4 , 5}

===========================================================================
Do you want to continue (y/n)?	y
===========================================================================


***************************** MENU *****************************
Press

	1. Accept a set
	2. Display the set
	3. Intersection
	4. Union
	5. Difference
	6. Subset
	7. Add an element
	8. Find if an element exists
	9. Remove an element
CHOICE: 2

--------------------------> SET A : { 0 , 1 , 2 , 3 , 4}

--------------------------> SET B : { 0 , 2 , 4 , 5}

===========================================================================
Do you want to continue (y/n)?	y
===========================================================================


***************************** MENU *****************************
Press

	1. Accept a set
	2. Display the set
	3. Intersection
	4. Union
	5. Difference
	6. Subset
	7. Add an element
	8. Find if an element exists
	9. Remove an element
CHOICE: 3

--------------------------> SET A : { 0 , 1 , 2 , 3 , 4}

--------------------------> SET B : { 0 , 2 , 4 , 5}
The intersection setA and setB is :
{0 , 2 , 4}

===========================================================================
Do you want to continue (y/n)?	y
===========================================================================


***************************** MENU *****************************
Press

	1. Accept a set
	2. Display the set
	3. Intersection
	4. Union
	5. Difference
	6. Subset
	7. Add an element
	8. Find if an element exists
	9. Remove an element
CHOICE: 4

--------------------------> SET A : { 0 , 1 , 2 , 3 , 4}

--------------------------> SET B : { 0 , 2 , 4 , 5}
The intersection setA and setB is :
{0 , 2 , 4 , 1 , 3}

===========================================================================
Do you want to continue (y/n)?	y
===========================================================================


***************************** MENU *****************************
Press

	1. Accept a set
	2. Display the set
	3. Intersection
	4. Union
	5. Difference
	6. Subset
	7. Add an element
	8. Find if an element exists
	9. Remove an element
CHOICE: 5

--------------------------> SET A : { 0 , 1 , 2 , 3 , 4}

--------------------------> SET B : { 0 , 2 , 4 , 5}
The roll no's of students playing only setA are
{1 , 3}

===========================================================================
Do you want to continue (y/n)?	y
===========================================================================


***************************** MENU *****************************
Press

	1. Accept a set
	2. Display the set
	3. Intersection
	4. Union
	5. Difference
	6. Subset
	7. Add an element
	8. Find if an element exists
	9. Remove an element
CHOICE: 6

--------------------------> SET A : { 0 , 1 , 2 , 3 , 4}

--------------------------> SET B : { 0 , 2 , 4 , 5}

		1. B is NOT a subset of A; and
		2. A is NOT a subset of B
	Thus they are DISJOINT sets !!!

===========================================================================
Do you want to continue (y/n)?	y
===========================================================================


***************************** MENU *****************************
Press

	1. Accept a set
	2. Display the set
	3. Intersection
	4. Union
	5. Difference
	6. Subset
	7. Add an element
	8. Find if an element exists
	9. Remove an element
CHOICE: 7

1. SET A		2. SET B ?	1

Enter element to be added : 5
{ 0 , 1 , 2 , 3 , 4 , 5}

===========================================================================
Do you want to continue (y/n)?	y
===========================================================================


***************************** MENU *****************************
Press

	1. Accept a set
	2. Display the set
	3. Intersection
	4. Union
	5. Difference
	6. Subset
	7. Add an element
	8. Find if an element exists
	9. Remove an element
CHOICE: 7

1. SET A		2. SET B ?	2

Enter element to be added : 1
{ 0 , 2 , 4 , 5 , 1}

===========================================================================
Do you want to continue (y/n)?	y
===========================================================================


***************************** MENU *****************************
Press

	1. Accept a set
	2. Display the set
	3. Intersection
	4. Union
	5. Difference
	6. Subset
	7. Add an element
	8. Find if an element exists
	9. Remove an element
CHOICE: 8

1. SET A		2. SET B ?	1

Enter element to be searched : 8

Set DOES NOT contain 8 as an element !!
{ 0 , 1 , 2 , 3 , 4 , 5}

===========================================================================
Do you want to continue (y/n)?	y
===========================================================================


***************************** MENU *****************************
Press

	1. Accept a set
	2. Display the set
	3. Intersection
	4. Union
	5. Difference
	6. Subset
	7. Add an element
	8. Find if an element exists
	9. Remove an element
CHOICE: 8

1. SET A		2. SET B ?	2

Enter element to be searched : 5

Set contains 5 as an element !!
{ 0 , 2 , 4 , 5 , 1}

===========================================================================
Do you want to continue (y/n)?	y
===========================================================================


***************************** MENU *****************************
Press

	1. Accept a set
	2. Display the set
	3. Intersection
	4. Union
	5. Difference
	6. Subset
	7. Add an element
	8. Find if an element exists
	9. Remove an element
CHOICE: 9

--------------------------> SET A : { 0 , 1 , 2 , 3 , 4 , 5}

--------------------------> SET B : { 0 , 2 , 4 , 5 , 1}


1. SET A		2. SET B ?	1
The requested set is : { 0 , 1 , 2 , 3 , 4 , 5}

Enter element to be removed : 3

Element 3 successfully removed !!
{ 0 , 1 , 2 , 4 , 5}

===========================================================================
Do you want to continue (y/n)?	y
===========================================================================


***************************** MENU *****************************
Press

	1. Accept a set
	2. Display the set
	3. Intersection
	4. Union
	5. Difference
	6. Subset
	7. Add an element
	8. Find if an element exists
	9. Remove an element
CHOICE: 6

--------------------------> SET A : { 0 , 1 , 2 , 4 , 5}

--------------------------> SET B : { 0 , 2 , 4 , 5 , 1}

		1. B is a subset of A; and
		2. A is a subset of B
	Thus they are equal sets !!!

===========================================================================
Do you want to continue (y/n)?	y
===========================================================================


***************************** MENU *****************************
Press

	1. Accept a set
	2. Display the set
	3. Intersection
	4. Union
	5. Difference
	6. Subset
	7. Add an element
	8. Find if an element exists
	9. Remove an element
CHOICE: 7

1. SET A		2. SET B ?	1

Enter element to be added : 10
{ 0 , 1 , 2 , 4 , 5 , 10}

===========================================================================
Do you want to continue (y/n)?	y
===========================================================================


***************************** MENU *****************************
Press

	1. Accept a set
	2. Display the set
	3. Intersection
	4. Union
	5. Difference
	6. Subset
	7. Add an element
	8. Find if an element exists
	9. Remove an element
CHOICE: 6

--------------------------> SET A : { 0 , 1 , 2 , 4 , 5 , 10}

--------------------------> SET B : { 0 , 2 , 4 , 5 , 1}

	B is a subset of A
===========================================================================
Do you want to continue (y/n)?	n
===========================================================================

 */
