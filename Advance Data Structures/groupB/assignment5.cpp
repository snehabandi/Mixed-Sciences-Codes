
//============================================================================
// Name        : assignment5.cpp
// Author      : Sneha Bandi
// Roll No.    : 2401
// Description : Graph creation,Prim's algorithm (using Matrix and list)
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
	int weight;
	list()
	{
		data=0;
		weight=0;
		next = NULL;
	}
	void addatend();			//Adds the node at the end of the list
	void display();				//Display List
};
class graph
{
	 int admatrix[MAX][MAX],edges,vertices,visited[MAX],cost[MAX][MAX];
	 list adlist[MAX];
public:
	 graph();
	 //graph(int size);
	 void read_graph();			//To read edges from user
	 void insert_matrix(int,int,int);	//To insert element in the matrix
	 void insert_list(int,int,int);		//To insert element in the list
	 void display_matrix();			//Display matrix
	 void display_list();			//Display list
	 void display_cost_matrix();		//Display matrix
	 void prims_matrix();
	 void prims_list();
	 int all_visit();
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
  {
 	 admatrix[i][j] = 0;
	 cost[i][j]=0;
  }
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
	int s,e,wt;
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
	 cout<<"\n\tWeight : ";
	 cin>>wt;
	 insert_matrix(s,e,wt);
	 insert_list(s,e,wt);
	 insert_list(e,s,wt);

 }
//return g;
}
void graph::insert_matrix(int r,int c,int w)				//Display matrix
{
 admatrix[r][c]=w;
 admatrix[c][r]=w;
}
void graph::insert_list(int r,int c,int w)		//To insert element in the list
{						//r is starting vertex & s is ending
	list* ptr,*temp;
	ptr=&adlist[r];
	temp = new list();
	temp->data=c;
	temp->weight=w;
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
void graph::display_cost_matrix()
{
	cout<<"\n____________________________________________________________________________	\n";
	cout<<"\n\t\t\tThe cost matrix is :\n";
	 for(int i=0;i<vertices;i++)
	 {
	  cout<<"\n";
	  for(int j=0;j<vertices;j++)
	  {
	 	 cout<<"\t"<<cost[i][j];
	  }
	 }
	cout<<"\n____________________________________________________________________________	\n";

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
			cout<<ptr->data<<"("<<ptr->weight<<") ";
		}
		cout<<"}";
	}
}
int graph::all_visit()
{
	cout<<"\n\tThe visited array is : ";
 	for(int i=0;i<vertices;i++)
 		cout<<visited[i];	
	int flag=0;
 	for(int i=0;i<vertices;i++)
 	{
 		if(visited[i]==0)
 		{
 			flag=1;
 			break;
 		}
 	}
 	if(flag==0)
 		return 1;		//flag =  0 means all the vertices are visited
 	else
 		return 0;		//flag =  1 means NOT all the vertices are visited

 }

void graph::prims_matrix()
{
 int j,min=999,u,v;
 for(int i=0;i<MAX;i++)
 	visited[i] = 0;
//Visit First node
 visited[0]=1;
//Prim's Algorithm begins
 while(all_visit()!=1)
 {	 min=999;
  for(int i=0;i<vertices;i++)				//Matrix row-wise traversal
  {
     if(visited[i]==1)					//Find min. wt of edge connected to already visited nodes only
     {		
      for(j=0;j<vertices;j++)				//Matrix column-wise traversal
      {
	 if(admatrix[i][j]!=0 && visited[j]==0)		//The element of matrix must be !=0
	 {
	  if(min>admatrix[i][j])
	  {
	   min=admatrix[i][j];
	   u=i;v=j;
	  }
	 }
      }//End of inner for loop
    }
 } //End of outer for loop

 visited[v]=1;
 cost[u][v]=min;		 		//u and v are indices of the minimum element in the complete matrix
 cout<<"\n\tThe minimum internal cost is : "<<cost[u][v]<<endl;
}
//End of Prim's Algorithm

	//Final cost calculaton
	int cs=0;
	for(int i=0;i<vertices;i++)
	{
	 for(int j=0;j<vertices;j++)
	 	 cs=cs+cost[i][j];

	}
	cout<<"\n\n\tTHE TOTAL MINIMUM COST IS : "<<cs<<endl;

}

void graph::prims_list()
{
 int min=999,u,v;
 list *ptr;
 for(int i=0;i<MAX;i++)
 	visited[i] = 0;
//Visit First node
 visited[0]=1;
//Prim's Algorithm begins
 while(all_visit()!=1)
 {	 min=999;
  for(int i=0;i<vertices;i++)				//Matrix row-wise traversal
  {
     ptr=&adlist[i];
     if(visited[i]==1)					//Find min. wt of edge connected to already visited nodes only
     {		
      while(ptr!=NULL)				//Matrix column-wise traversal
      {
	 if(visited[ptr->data]==0)				//The element of list must not be visited
	 {
	  if(min>ptr->weight)
	  {
	   u=i;v=ptr->data;
	   min=ptr->weight;	   
	  }
	 }
	 ptr=ptr->next;
      }//End of inner for loop
    }
 } //End of outer for loop

 visited[v]=1;
 cost[u][v]=min;		 		//u and v are indices of the minimum element in the complete matrix
 cout<<"\n\tThe minimum internal cost is : "<<cost[u][v]<<endl;
}
//End of Prim's Algorithm

	//Final cost calculaton
	int cs=0;
	for(int i=0;i<vertices;i++)
	{
	 for(int j=0;j<vertices;j++)
	 	 cs=cs+cost[i][j];

	}
	cout<<"\n\n\tTHE TOTAL MINIMUM COST IS : "<<cs<<endl;


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
   cout<<"\n\t3. MST display using Prims algorithm (MATRIX)";
   cout<<"\n\t4. MST display using Prims algorithm (LIST)";
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
	  g1.prims_matrix();
	  g1.display_cost_matrix();
	  break;
    case 4:
	  g1.prims_list();
	  g1.display_cost_matrix();	  
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
	3. MST display using Prims algorithm (MATRIX)
	4. MST display using Prims algorithm (LIST)
CHOICE : 1

Enter no. of vertices : 7 

Enter no. of edges : 11

Vertex 1 :
	Starting vertex : 0

	Ending vertex : 1

	Weight : 2

Vertex 2 :
	Starting vertex : 0

	Ending vertex : 2

	Weight : 4

Vertex 3 :
	Starting vertex : 0

	Ending vertex : 3

	Weight : 1

Vertex 4 :
	Starting vertex : 1

	Ending vertex : 3

	Weight : 3

Vertex 5 :
	Starting vertex : 1

	Ending vertex : 4

	Weight : 10

Vertex 6 :
	Starting vertex : 2

	Ending vertex : 3

	Weight : 2

Vertex 7 :
	Starting vertex : 2

	Ending vertex : 5

	Weight : 5

Vertex 8 :
	Starting vertex : 3

	Ending vertex : 5

	Weight : 3

Vertex 9 :
	Starting vertex : 3

	Ending vertex : 6

	Weight : 4

Vertex 10 :
	Starting vertex : 4

	Ending vertex : 6

	Weight : 6

Vertex 11 :
	Starting vertex : 5

	Ending vertex : 6

	Weight : 1

===================================================
Do you want to continue (y/n) ? : y
===================================================

				MENU
Press:
	1. Create graph
	2. Display (adjacency LIST and MATRIX)
	3. MST display using Prims algorithm (MATRIX)
	4. MST display using Prims algorithm (LIST)
CHOICE : 2

	0	2	4	1	0	0	0
	2	0	0	3	10	0	0
	4	0	0	2	0	5	0
	1	3	2	0	0	3	4
	0	10	0	0	0	0	6
	0	0	5	3	0	0	1
	0	0	0	4	6	1	0

The list data is : 

	 node 0 : { 1(2) 2(4) 3(1) }
	 node 1 : { 0(2) 3(3) 4(10) }
	 node 2 : { 0(4) 3(2) 5(5) }
	 node 3 : { 0(1) 1(3) 2(2) 5(3) 6(4) }
	 node 4 : { 1(10) 6(6) }
	 node 5 : { 2(5) 3(3) 6(1) }
	 node 6 : { 3(4) 4(6) 5(1) }
===================================================
Do you want to continue (y/n) ? : y
===================================================

				MENU
Press:
	1. Create graph
	2. Display (adjacency LIST and MATRIX)
	3. MST display using Prims algorithm (MATRIX)
	4. MST display using Prims algorithm (LIST)
CHOICE : 3

	The visited array is : 1000000
	The minimum internal cost is : 1

	The visited array is : 1001000
	The minimum internal cost is : 2

	The visited array is : 1101000
	The minimum internal cost is : 2

	The visited array is : 1111000
	The minimum internal cost is : 3

	The visited array is : 1111010
	The minimum internal cost is : 1

	The visited array is : 1111011
	The minimum internal cost is : 6

	The visited array is : 1111111

	THE TOTAL MINIMUM COST IS : 15

____________________________________________________________________________	

			The cost matrix is :

	0	2	0	1	0	0	0
	0	0	0	0	0	0	0
	0	0	0	0	0	0	0
	0	0	2	0	0	3	0
	0	0	0	0	0	0	0
	0	0	0	0	0	0	1
	0	0	0	0	6	0	0
____________________________________________________________________________	

===================================================
Do you want to continue (y/n) ? : y
===================================================

				MENU
Press:
	1. Create graph
	2. Display (adjacency LIST and MATRIX)
	3. MST display using Prims algorithm (MATRIX)
	4. MST display using Prims algorithm (LIST)
CHOICE : 4

	The visited array is : 1000000
	The minimum internal cost is : 1

	The visited array is : 1001000
	The minimum internal cost is : 2

	The visited array is : 1101000
	The minimum internal cost is : 2

	The visited array is : 1111000
	The minimum internal cost is : 3

	The visited array is : 1111010
	The minimum internal cost is : 1

	The visited array is : 1111011
	The minimum internal cost is : 6

	The visited array is : 1111111

	THE TOTAL MINIMUM COST IS : 15

____________________________________________________________________________	

			The cost matrix is :

	0	2	0	1	0	0	0
	0	0	0	0	0	0	0
	0	0	0	0	0	0	0
	0	0	2	0	0	3	0
	0	0	0	0	0	0	0
	0	0	0	0	0	0	1
	0	0	0	0	6	0	0
____________________________________________________________________________	


===================================================
Do you want to continue (y/n) ? : n
===================================================

*/
