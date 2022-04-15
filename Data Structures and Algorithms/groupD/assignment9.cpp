//============================================================================
// Name        : job_queue.cpp
// Author      : Sneha Bandi
// Roll No.    : 2401
// Topic       : Job queue implementation using PRIORITY queue
//============================================================================

#include <iostream>
#define MAX 30
using namespace std;
//job class
class job
{
	friend class queue;
	int id,priority;		//ID AND PRIORITY AS MEMBERS
public:
	void accept()			//ACCEPT FUNCTION
	{
		cout<<"\nEnter ID: ";
		cin>>id;
		cout<<"\nEnter priority : ";
		cin>>priority;
	}
	void display()			//DISPLAY FUNCTION
	{
		cout<<id<<"\t"<<priority<<"\n";

	}
	void sort();			//SORTING OF PRIORITIES BY INSERTION SORT
};
//CLASS QUEUE
class queue
{
	job q[MAX];
	int rear,front;			//REAR AND FRONT POINTERS
public:
	queue()
	{
		front=0;
		rear=-1;
	}
	void enqueue();			//ENQUEUE WITHOUT SORTING
	void enqueue_insertion();	//ENQUEUE WITH SORTING
	int qfull();
	int qempty();
	void dequeue();

};
int queue::qempty()			//QUEUE EMPTY OR NOT
{
  if(rear==front==-1||rear==front)
	return 1;
  else
	return 0;

}
int queue::qfull()			//QUEUE FULL OR NOT
{
  if(rear==MAX-1)
	return 1;
  else
	return 0;

}
void queue::enqueue()			//INSERTION OF ELEMENTS IN JOB QUEUE
{
	job j;
	char ans;
 do{
 if(qfull()==1)
	 cout<<"\nQueue is FULL";
 else
 {
	j.accept();
	rear++;
	q[rear]= j;
 }
 cout<<"\nDo you want to enter another record (y/n)?\t";
 cin>>ans;
 }while(ans=='y'||ans=='Y');
}
void queue::enqueue_insertion()
{
	job j;
	int i=0;
	char ans;
 do{					//INSERTION SORT
 if(qfull()==1)
	 cout<<"\nQueue is FULL";
 else
 {
		j.accept();
	i=rear;
	while(i>=front&&q[i].priority>j.priority)
	{
		q[i+1]=q[i];
		i--;
	}
	q[i+1]=j;
	rear++;
	//q[rear]= j;
 }
 cout<<"\nDo you want to enter another record (y/n)?\t";
 cin>>ans;
 }while(ans=='y'||ans=='Y');
}
void queue::dequeue()
{				//DEQUEUE OF ALL THE ELEMENTS FROM JOB QUEUE
	int temp;
	cout<<"ID:\tPRIORITY:\n";
	if(qempty()==1)
		cout<<"\nQueue is EMPTY!";
	else{
//bubble sort can be done here!
	while((rear+1)!=front)
	{
		job j;
		j=q[front];
		front++;
		j.display();
	}
	}
}
//MAIN
int main()
{
	queue r,r1;
	int t;
		char ch;
		cout<<"=============================================\n";
	//DO-WHILE STARTS
	do{
	   cout<<"Enter your choice\n";
	   cout<<"\t1.Accept-display\n\t2.accept and insertion sort\n";
	   cout<<"CHOICE: ";
	   cin>>t;
	     //SWITCH CASE STARTS
		switch(t)
		{
		case 1:
		//ENQUEUE WTIH SORTING
			r.enqueue();
			r.dequeue();
			break;
		case 2:
		//ENQUEUE WITHOUT SORTING
			r1.enqueue_insertion();
			r1.dequeue();
			break;
		default:
			cout<<"\nENTER VALID CHOICE!\n";

		}
	     //SWITCH CASE ENDS
   	  cout<<"\nDo you want to continue (y/n)?  ";
	  cin>>ch;
	  cout<<"=============================================\n";
	}while(ch=='y'||ch=='Y');
	//DO-WHILE ENDS
  return 0;
}
//PROGRAM ENDS
/*
=============================================
Enter your choice
	1.Accept-display
	2.accept and insertion sort
CHOICE: 1

Enter ID: 1

Enter priority : 3

Do you want to enter another record (y/n)?	y

Enter ID: 2

Enter priority : 1

Do you want to enter another record (y/n)?	y

Enter ID: 3

Enter priority : 5

Do you want to enter another record (y/n)?	n
ID:	PRIORITY:
1	3
2	1
3	5

Do you want to continue (y/n)?  y
=============================================
Enter your choice
	1.Accept-display
	2.accept and insertion sort
CHOICE: 2

Enter ID: 1

Enter priority : 3

Do you want to enter another record (y/n)?	y

Enter ID: 2

Enter priority : 5

Do you want to enter another record (y/n)?	y

Enter ID: 3

Enter priority : 1

Do you want to enter another record (y/n)?	y

Enter ID: 4

Enter priority : 4

Do you want to enter another record (y/n)?	n
ID:	PRIORITY:
3	1
1	3
4	4
2	5

Do you want to continue (y/n)?  n
=============================================

//-------------------------------------------------> > TEST CASE: IF TWO ID'S HAVE SAME PRIORITY THEN DISPLAY THE ONE ENTERING FIRST

Enter your choice
	1.Accept-display
	2.accept and insertion sort
CHOICE: 2

Enter ID: 1

Enter priority : 5

Do you want to enter another record (y/n)?	y

Enter ID: 2

Enter priority : 2

Do you want to enter another record (y/n)?	y

Enter ID: 3

Enter priority : 1

Do you want to enter another record (y/n)?	y

Enter ID: 4

Enter priority : 2

Do you want to enter another record (y/n)?	y

Enter ID: 5

Enter priority : 4

Do you want to enter another record (y/n)?	n
ID:	PRIORITY:
3	1
2	2
4	2
5	4
1	5

Do you want to continue (y/n)?  n
=============================================


*/
