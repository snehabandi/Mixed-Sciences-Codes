
//============================================================================
// Name        : assignment4.cpp
// Author      : Sneha Bandi
// Roll No.    : 2401
// Description : Graph creation,BFS and DFS traversal
//============================================================================

#include <iostream>
#include<stack>
#include<queue>
using namespace std;
#define MAX 12	
class list
{
public:
	list* next;
	int data;
	list()
	{
		data=0;
		next = NULL;
	}
	void addatend();			//Adds the node at the end of the list
	void display();				//Display List
};
class graph
{
	 int admatrix[MAX][MAX],edges,vertices,visited[MAX];
	 list adlist[MAX];
public:
	 graph();
	 //graph(int size);
	 void read_graph();			//To read edges from user
	 void insert_matrix(int r,int c);	//To insert element in the matrix
	 void insert_list(int r,int c);		//To insert element in the list
	 void display_matrix();			//Display matrix
	 void display_list();			//Display list
	 void BFS_list();			//BFS traversal non-recursive using adjacency list
	 void BFS_matrix();			//BFS traversal non-recursive using adjacency matrix
	 void DFS_list();			//DFS traversal non-recursive using adjacency list
	 void DFS_matrix();			//DFS traversal non-recursive using adjacency matrix
	 
};
graph::graph()
{

 edges = 0;
 vertices =0;
 for(int i=0;i<MAX;i++)
	 visited[i] = 0;
 for(int i=0;i<MAX;i++)
 {
  for(int j=0;j<MAX;j++)
 	 admatrix[i][j] = 0;
 }

}
/*graph::graph(int size)
{
	 for(int i=0;i<size;i++)
	 {
	  for(int j=0;j<size;j++)
	 	 admatrix[i][j] = {0};
	 }
}*/
void graph::read_graph()
{
	int s,e;
 cout<<"\nEnter no. of vertices : ";
 cin>>vertices;
 cout<<"\nEnter no. of edges : ";
 cin>>edges;
 //graph g(vertices);
 for(int i=1;i<=edges;i++)
 {
	 cout<<"\nVertex "<<i<<" :";
	 cout<<"\n\tStarting vertex : ";
	 cin>>s;
	 cout<<"\n\tEnding vertex : ";
	 cin>>e;
	 insert_matrix(s,e);
	 insert_list(s,e);
	 insert_list(e,s);

 }
//return g;
}
void graph::insert_matrix(int r,int c)				//Display matrix
{
 admatrix[r][c]=1;
 admatrix[c][r]=1;
}
void graph::insert_list(int r,int c)		//To insert element in the list
{						//r is starting vertex & s is ending
	list* ptr,*temp;
	ptr=&adlist[r];
	temp = new list();
	temp->data=c;
	if(ptr->next==NULL)
		ptr->next=temp;
	else
	{
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=temp;
	}
}

//Display martix
void graph::display_matrix()
{
	 for(int i=0;i<vertices;i++)
	 {
	  cout<<"\n";
	  for(int j=0;j<vertices;j++)
	  {
	 	 cout<<"\t"<<admatrix[i][j];
	  }
	 }
}

//Display list
void graph::display_list()
{
	cout<<"\n\nThe list data is : \n";
	list* ptr;
	for(int i=0;i<vertices;i++)
	{
		cout<<"\n\t node "<<i<<" : { ";
	 ptr=&adlist[i];
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
			cout<<ptr->data<<" ";
		}
		cout<<"}";
	}
}

//DFS traversal using adjacency list
void graph::DFS_list()
{
 //Making visited array zero as it might be already used by BFS
  for(int i=0;i<MAX;i++)
	 visited[i] = 0;
	
	list* ptr;
	stack<list*> s;
	ptr=&adlist[0];
	visited[0]=1;
	s.push(ptr);
	cout<<"\nThe DFS traversal is :\n\t"<<ptr->data<<"\t";
	while(!s.empty())							//s.empty() returns 1 if empty
	{

		ptr=&adlist[ptr->data];
			ptr=ptr->next;
			while(visited[ptr->data]!=0 && ptr->next!=NULL)
				ptr=ptr->next;
			if(visited[ptr->data]!=1 )				//not visited
			{
				s.push(ptr);
				cout<<ptr->data<<"\t";
				visited[ptr->data]=1;				//1 means visited
			}
			else
			{
				ptr = s.top();
				s.pop();
			}

	}

}

//DFS traversal using adjacency matrix
void graph::DFS_matrix()
{
  //Making visited array zero as it might be already used by BFS
  for(int i=0;i<MAX;i++)
	 visited[i] = 0;
	 	cout<<"\n\n\tvertices"<<vertices;
	int r=0,c=0;			 	//r is row counter c is column counter
	stack<int> s;
	visited[c]=1;
	s.push(c); 
	cout<<"\nThe DFS traversal of given matrix is :\n\t"<<c<<"\t";	
	while(!s.empty())
	{
	  while((admatrix[r][c]!=1 || visited[c]!=0) && c<(vertices-1))
	  	c++;
	  if(visited[c]!=1)			//not visited
	  {
	   s.push(c);
 	   cout<<c<<"\t";	   
	   visited[c]=1;			//1 means visited
	   r=c;c=0;
	  }
	  else
	  {
	   r=s.top();
	   s.pop();
	  }
	
	}


}

//BFS traversal using adjacency list
void graph::BFS_list()
{
  list *ptr;
  queue<list*> q;
 
  //Making visited array zero as it might be already used by BFS
  for(int i=0;i<MAX;i++)
	 visited[i] = 0;
	  
   ptr=&adlist[0];
   q.push(ptr);   
   visited[ptr->data]=1;
   int i=0;
   cout<<"\nThe BFS traversal of given list is :\n\t"<<ptr->data;
   while(!q.empty())				//q.empty() returns 1 if empty
   {
   	ptr=&adlist[q.front()->data];		//we cannot write ptr=q.front as it points to one of the nodes
   						//of adlist but instead points to individual lists of adlist nodes			
   	q.pop();				//pop a vertex to traverse its adjacent vertices	
   	while(ptr->next!=NULL)
   	{
    	  ptr=ptr->next;
    	  if(visited[ptr->data]==0)		//if vertex is not visited only then push
    	  {
    	    q.push(ptr);    	  
    	    visited[ptr->data]=1;
    	    cout<<"\t"<<ptr->data;
    	  }
   	}    	
   }
cout<<endl;
}

//BFS traversal using adjacency matrix
void graph::BFS_matrix()
{
  int r=0,c=0;
  queue<int> q;
 
  //Making visited array zero as it might be already used by BFS
  for(int i=0;i<MAX;i++)
	 visited[i] = 0;
	  
   q.push(c);   
   visited[c]=1;
   int i=0;
   cout<<"\nThe BFS traversal of given list is :\n\t"<<c;
   while(!q.empty())				//q.empty() returns 1 if empty
   {
	r=q.front();
	//cout<<"\n\t\tfront element : "<<r;
   	q.pop();
   	c=0;				//pop a vertex to traverse its adjacent vertices	
   	while(c<(vertices-1))
   	{
	  c++;
	//cout<<"\n\t\t c++ element : "<<c;	  
    	  if(visited[c]==0 && admatrix[r][c]==1)		//if vertex is not visited only then push
    	  {
    	    q.push(c);    	  
    	    visited[c]=1;
    	    cout<<"\t"<<c;
    	  }
   	}    	
   }
cout<<endl;

}
int main()
{
  graph g1;
  char ans1;
  int choice;
  do
  {
   cout<<"\n\t\t\t\tMENU";
   cout<<"\nPress:";
   cout<<"\n\t1. Create graph";
   cout<<"\n\t2. Display (adjacency LIST and MATRIX)";
   cout<<"\n\t3. DFS traversal using adjacency LIST (non-recursive)";
   cout<<"\n\t4. DFS traversal using adjacency MATRIX (non-recursive)";
   cout<<"\n\t5. BFS traversal using adjacency LIST (non-recursive)";
   cout<<"\n\t6. BFS traversal using adjacency MATRIX (non-recursive)";		
   cout<<"\nCHOICE : ";
   cin>>choice;
   switch(choice)
   {
    case 1:
	   g1.read_graph();
	   break;
    case 2:
	  g1.display_matrix();
	  g1.display_list();
	  break;
    case 3:
	  g1.DFS_list();
	  break;
    case 4:
	  g1.DFS_matrix();
	  break;
    case 5:
	   g1.BFS_list();
	   break;
    case 6:
	   g1.BFS_matrix();
	   break;
    default:
            cout<<"\nEnter valid choice !!\n";
	    break;
   }
	cout<<"\n===================================================";
	cout<<"\nDo you want to continue (y/n) ? : ";
	cin>>ans1;
	cout<<"===================================================\n";

  }while(ans1=='y'||ans1=='Y');

return 0;
}
//----------------------------->> OUTPUT <<------------------------------
/*
				MENU
Press:
	1. Create graph
	2. Display (adjacency LIST and MATRIX)
	3. DFS traversal using adjacency LIST (non-recursive)
	4. DFS traversal using adjacency MATRIX (non-recursive)
	5. BFS traversal using adjacency LIST (non-recursive)
	6. BFS traversal using adjacency MATRIX (non-recursive)
CHOICE : 1

Enter no. of vertices : 8

Enter no. of edges : 10

Vertex 1 :
	Starting vertex : 0

	Ending vertex : 1

Vertex 2 :
	Starting vertex : 0

	Ending vertex : 2

Vertex 3 :
	Starting vertex : 0

	Ending vertex : 3

Vertex 4 :
	Starting vertex : 0

	Ending vertex : 4

Vertex 5 :
	Starting vertex : 1

	Ending vertex : 5

Vertex 6 :
	Starting vertex : 2

	Ending vertex : 5

Vertex 7 :
	Starting vertex : 3

	Ending vertex : 6

Vertex 8 :
	Starting vertex : 4

	Ending vertex : 6

Vertex 9 :
	Starting vertex : 5

	Ending vertex : 7

Vertex 10 :
	Starting vertex : 6

	Ending vertex : 7

===================================================
Do you want to continue (y/n) ? : y
===================================================

				MENU
Press:
	1. Create graph
	2. Display (adjacency LIST and MATRIX)
	3. DFS traversal using adjacency LIST (non-recursive)
	4. DFS traversal using adjacency MATRIX (non-recursive)
	5. BFS traversal using adjacency LIST (non-recursive)
	6. BFS traversal using adjacency MATRIX (non-recursive)
CHOICE : 2

	0	1	1	1	1	0	0	0
	1	0	0	0	0	1	0	0
	1	0	0	0	0	1	0	0
	1	0	0	0	0	0	1	0
	1	0	0	0	0	0	1	0
	0	1	1	0	0	0	0	1
	0	0	0	1	1	0	0	1
	0	0	0	0	0	1	1	0

The list data is : 

	 node 0 : { 1 2 3 4 }
	 node 1 : { 0 5 }
	 node 2 : { 0 5 }
	 node 3 : { 0 6 }
	 node 4 : { 0 6 }
	 node 5 : { 1 2 7 }
	 node 6 : { 3 4 7 }
	 node 7 : { 5 6 }
===================================================
Do you want to continue (y/n) ? : y
===================================================

				MENU
Press:
	1. Create graph
	2. Display (adjacency LIST and MATRIX)
	3. DFS traversal using adjacency LIST (non-recursive)
	4. DFS traversal using adjacency MATRIX (non-recursive)
	5. BFS traversal using adjacency LIST (non-recursive)
	6. BFS traversal using adjacency MATRIX (non-recursive)
CHOICE : 3

The DFS traversal is :
	0	1	5	2	7	6	3	4	
===================================================
Do you want to continue (y/n) ? : y
===================================================

				MENU
Press:
	1. Create graph
	2. Display (adjacency LIST and MATRIX)
	3. DFS traversal using adjacency LIST (non-recursive)
	4. DFS traversal using adjacency MATRIX (non-recursive)
	5. BFS traversal using adjacency LIST (non-recursive)
	6. BFS traversal using adjacency MATRIX (non-recursive)
CHOICE : 4


	vertices8
The DFS traversal of given matrix is :
	0	1	5	2	7	6	3	
===================================================
Do you want to continue (y/n) ? : y
===================================================

				MENU
Press:
	1. Create graph
	2. Display (adjacency LIST and MATRIX)
	3. DFS traversal using adjacency LIST (non-recursive)
	4. DFS traversal using adjacency MATRIX (non-recursive)
	5. BFS traversal using adjacency LIST (non-recursive)
	6. BFS traversal using adjacency MATRIX (non-recursive)
CHOICE : 5

The BFS traversal of given list is :
	0	1	2	3	4	5	6	7

===================================================
Do you want to continue (y/n) ? : y
===================================================

				MENU
Press:
	1. Create graph
	2. Display (adjacency LIST and MATRIX)
	3. DFS traversal using adjacency LIST (non-recursive)
	4. DFS traversal using adjacency MATRIX (non-recursive)
	5. BFS traversal using adjacency LIST (non-recursive)
	6. BFS traversal using adjacency MATRIX (non-recursive)
CHOICE : 6

The BFS traversal of given list is :
	0	1	2	3	4	5	6	7

===================================================
Do you want to continue (y/n) ? : n
===================================================

*/
