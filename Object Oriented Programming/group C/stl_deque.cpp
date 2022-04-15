//============================================================================
// Name        : dqueue.cpp
// Author      : Sneha Bandi
// Roll No     : 2401
// Description : STL deque
//============================================================================

#include<iostream>
#include<deque>			//STANDARD TEMPLATE OF DEQUE INCLUDED	
#include<string>
#include<cstdlib>
using namespace std;
//main
int main() {
	deque<int>dq;
	deque<int>::iterator it;
	int choice,item;
	cout<<"\n------------------------"<<endl;
	cout<<"deque implemenation in STL"<<endl;
	cout<<"\n------------------------"<<endl;
	while(1)
	{
		cout<<"\n\t1. Insert element at the end";
		cout<<"\n\t2. Insert element at the front";
		cout<<"\n\t3. Delete element at end";
		cout<<"\n\t4. Delete element at the front";
		cout<<"\n\t5. Front element at the deque";
		cout<<"\n\t6. Last element at deque";
		cout<<"\n\t7. Size of the deque";
		cout<<"\n\t8. Display deque";
		cout<<"\n\t9. Exit"<<endl;
		cout<<"enter your choice:";
		cin>>choice;
		cout<<"\n====================================================";
		//SWITCH CASE STARTS
		switch(choice)
		{
		//INSERT ELEMENT AT THE END OF QUEUE
		case 1:
			cout<<"\nEnter value to be inserted at the end";
			cin>>item;
			dq.push_back(item);
			break;
		//INSERT ELEMENT AT THE FRONT OF QUEUE			
		case 2:
			cout<<"\nEnter value to be inserted at the front";
			cin>>item;
			dq.push_front(item);
			break;
		//DELETE ELEMENT FROM THE END OF QUEUE			
		case 3:
			item=dq.back();
			dq.pop_back();
			cout<<"\nElement "<<item<<" deleted "<<endl;
			break;
		//DELETE ELEMENT FROM THE FRONT OF QUEUE						
		case 4:
			item=dq.back();
			dq.pop_front();
			cout<<"\nElement "<<item<<" deleted "<<endl;
			break;
		//DISPLAY FRONT ELEMENT OF THE QUEUE						
		case 5:
			cout<<"\nFront element of the deque";
			cout<<dq.front()<<endl;
			break;
		//DISPLAY END ELEMENT OF THE QUEUE									
		case 6:
			cout<<"\nBack element of the deque";
			cout<<dq.back()<<endl;
			break;
		//DISPLAY NO. OF ELEMENTS IN THE QUEUE									
		case 7:
			cout<<"\nSize of the deque "<<dq.size()<<endl;
			break;
		//DISPLAY ALL ELEMENTS IN THE QUEUE												
		case 8:
			cout<<"\nElements of deque ";
			for(it=dq.begin();it!=dq.end();it++)
				cout<<*it<<" ";
			cout<<endl;
			break;
		//EXIT THE CASE			
		case 9:
			exit(1);
			break;
		default:
			cout<<"\nWRONG CHOICE:"<<endl;

		}
		cout<<"\n====================================================";
		//SWITCH CASE ENDS

	}
	return 0;
}
/*
 *------------------------
deque implemenation in STL

------------------------

	1. Insert element at the end
	2. Insert element at the front
	3. Delete element at end
	4. Delete element at the front
	5. Front element at the deque
	6. Last element at deque
	7. Size of the deque
	8. Display deque
	9. Exit
enter your choice:1

====================================================
Enter value to be inserted at the end8

====================================================

	1. Insert element at the end
	2. Insert element at the front
	3. Delete element at end
	4. Delete element at the front
	5. Front element at the deque
	6. Last element at deque
	7. Size of the deque
	8. Display deque
	9. Exit
enter your choice:2

====================================================
Enter value to be inserted at the front9

====================================================

	1. Insert element at the end
	2. Insert element at the front
	3. Delete element at end
	4. Delete element at the front
	5. Front element at the deque
	6. Last element at deque
	7. Size of the deque
	8. Display deque
	9. Exit
enter your choice:1

====================================================
Enter value to be inserted at the end3

====================================================

	1. Insert element at the end
	2. Insert element at the front
	3. Delete element at end
	4. Delete element at the front
	5. Front element at the deque
	6. Last element at deque
	7. Size of the deque
	8. Display deque
	9. Exit
enter your choice:8

====================================================
Elements of deque 9 8 3

====================================================

	1. Insert element at the end
	2. Insert element at the front
	3. Delete element at end
	4. Delete element at the front
	5. Front element at the deque
	6. Last element at deque
	7. Size of the deque
	8. Display deque
	9. Exit
enter your choice:5

====================================================
Front element of the deque9

====================================================

	1. Insert element at the end
	2. Insert element at the front
	3. Delete element at end
	4. Delete element at the front
	5. Front element at the deque
	6. Last element at deque
	7. Size of the deque
	8. Display deque
	9. Exit
enter your choice:6

====================================================
Back element of the deque3

====================================================

	1. Insert element at the end
	2. Insert element at the front
	3. Delete element at end
	4. Delete element at the front
	5. Front element at the deque
	6. Last element at deque
	7. Size of the deque
	8. Display deque
	9. Exit
enter your choice:7

====================================================
Size of the deque 3

====================================================

	1. Insert element at the end
	2. Insert element at the front
	3. Delete element at end
	4. Delete element at the front
	5. Front element at the deque
	6. Last element at deque
	7. Size of the deque
	8. Display deque
	9. Exit
enter your choice:3

====================================================
Element 3 deleted

====================================================

	1. Insert element at the end
	2. Insert element at the front
	3. Delete element at end
	4. Delete element at the front
	5. Front element at the deque
	6. Last element at deque
	7. Size of the deque
	8. Display deque
	9. Exit
enter your choice:4

====================================================
Element 8 deleted

====================================================

	1. Insert element at the end
	2. Insert element at the front
	3. Delete element at end
	4. Delete element at the front
	5. Front element at the deque
	6. Last element at deque
	7. Size of the deque
	8. Display deque
	9. Exit
enter your choice:8

====================================================
Elements of deque 8

====================================================

	1. Insert element at the end
	2. Insert element at the front
	3. Delete element at end
	4. Delete element at the front
	5. Front element at the deque
	6. Last element at deque
	7. Size of the deque
	8. Display deque
	9. Exit
enter your choice:9

====================================================
 
 */

