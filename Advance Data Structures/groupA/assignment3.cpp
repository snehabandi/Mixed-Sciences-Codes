//============================================================================
// Name        : assignment3.cpp
// Author      : Sneha Bandi
// Roll No.    : 2401
// Copyright   : Your copyright notice
// Description : Binary tree to threaded binary tree conversion
//============================================================================

#include<iostream>
using namespace std;

//'node' class for linked list
class node
{
	friend class tree;
	node* left;
	node* right;
	int data,lflag,rflag;
public:
	node()
	{
		data = 0;
		left = right =NULL;
		lflag = 0;
		rflag = 0;
	}
	node(int d)
	{
		data = d;
		left =NULL;
		right = NULL;
		lflag = 0;
		rflag = 0;
	}
};

//tree class
class tree
{
	node* root;
	node* datanode[30];
	node* head;
	int cnt;
public:
	tree()
	{
		cnt=0;
		root = NULL;
		head = NULL;
		for(int i=0;i<30;i++)
			datanode[i]=NULL;

	}
	void create_BT();
	void inorder_rec_BT()
	{inorder_BT(root);}
	void inorder_BT(node*);
	void array_display();
	void create_TBT();
	void display_TBT(node*);
	void display_rec_TBT()
	{
		display_TBT(root);
	}
	node* findleft(node* ptr);
	void count(int);



};

//CREATION OF BINARY TREE
void tree::create_BT()
{
 node *temp,*ptr;
 int d;
 char ans,direction;
 do{
	 cout<<"\nEnter data : ";
     cin>>d;
     temp = new node(d);

     if(root==NULL)
    	 root=temp;
     else
     {
	   ptr=root;
	   while(1)
	   {
		 cout<<"\nEnter direction (l/r) : ";
		 cin>>direction;

		 if(direction=='l')
		 {
			 if(ptr->left==NULL)
			 {
			  ptr->left=temp;
			  break;
			 }
			 else
				 ptr=ptr->left;
		 }
		 else
		 {
			 if(ptr->right==NULL)
			 {
				 ptr->right=temp;
				 break;
			 }
			 else
				 ptr=ptr->right;
		 }
	   }
      }
     cout<<"\nEnter another data (y/n) ?\t";
     cin>>ans;
	 }while(ans=='y'||ans=='Y');
}
//TRAVERSE BINARY TREE INORDER AND STORE THE DATA IN AN ARRAY 'datanode'
//NOTE: No display while traversal
void tree::inorder_BT(node* ptr)
{
	static int i;
	 if(ptr==NULL)
		 return;
	 else
	 {
	   inorder_BT(ptr->left);
	   datanode[i] = ptr;
	   i++;
  	   //cout<<ptr->data<<"\t";
	   inorder_BT(ptr->right);
	 }
}
//DISPLAY ARRAY OF NODES : 'datanode'
void tree::array_display()
{
	int i=0;
 while(datanode[i]!=NULL)
 {
 	 cout<<datanode[i]->data<<"\t";
 	 i++;
 }
 count(i);
}
//COUNT OF NODES IN BINARY TREE
void tree::count(int c)
{
 cnt = c;
 cout<<"\n\tNo. of elements :"<<cnt;
}

//CREATION OF TBT FROM BINARY TREE
void tree::create_TBT()
{
	head = new node();			//Dynamically allocated memory to head
	head->left = root;
	head->right = head;
	int i=0;
	while(datanode[i]!=NULL)
	{
		if(datanode[i]->left==NULL)
		{
			if(i==0)
				datanode[i]->left = head;
			else
				datanode[i]->left = datanode[i-1];
			datanode[i]->lflag= 1;					//flag=1 means thread
		}
		if(datanode[i]->right==NULL)
		{
			if(datanode[i+1]==NULL)
				datanode[i]->right = head;
			else
				datanode[i]->right = datanode[i+1];
			datanode[i]->rflag= 1;
		}
		//cout<<"\n\tdata : "<<datanode[i]->data;
		i++;

	}

}

//TBT INORDER DISPLAY
void tree::display_TBT(node* ptr)
{
	node *current;
	current = new node();
	current = findleft(ptr);

	while(current!=head)
	{
	 cout<<current->data<<"\t";
	 if(current->rflag==0)				// 0 means child and 1 means thread
		 current = findleft(current->right);
	 else
		 current = current->right;
	}
}

//TO FIND LEFTMOST CHILD OF RIGHT CHILD OF CURRENT
node* tree::findleft(node* ptr)
{
	//we cannot write till ptr->left!=NULL as it will go on inf. due to thread
 if(ptr==NULL)
	return ptr;
 else
 {
  while(ptr->lflag==0)					//0 means child
	 ptr=ptr->left;
  return ptr;
 }

}
//MAIN
int main()
{
	tree t1;
	char ans1;
	int choice;
	do
	{
		cout<<"\n\t\t\t\tMENU";
		cout<<"\nPress:";
		cout<<"\n\t1. Create Binary tree";
		cout<<"\n\t2. Create Threaded binary tree";
		cout<<"\n\t3. Display Threaded Binary tree";
		cout<<"\n\t4. Display inorder array";
		cout<<"\n\tCHOICE : ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			t1.create_BT();
			cout<<"\nBinary Tree created !!\n";
			t1.inorder_rec_BT();
			cout<<"\n\tThe Binary tree elements are :\n\t\t";
			t1.array_display();
			break;
		case 2:
			t1.create_TBT();
			cout<<"\n\tTBT created !!\n";
			break;
		case 3:
			cout<<"\n\tThe TBT elements are :\n\t\t";
			t1.display_rec_TBT();
			break;
		case 4:
			cout<<"\n\tThe inorder array elements are :\n\t\t";
			t1.array_display();
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
	1. Create Binary tree
	2. Create Threaded binary tree
	3. Display Threaded Binary tree
	4. Display inorder array
	CHOICE : 1

Enter data : 1

Enter another data (y/n) ?	y

Enter data : 2

Enter direction (l/r) : l

Enter another data (y/n) ?	y

Enter data : 3

Enter direction (l/r) : r

Enter another data (y/n) ?	y

Enter data : 4

Enter direction (l/r) : l

Enter direction (l/r) : l

Enter another data (y/n) ?	y

Enter data : 5

Enter direction (l/r) : l

Enter direction (l/r) : r

Enter another data (y/n) ?	y

Enter data : 6

Enter direction (l/r) : r

Enter direction (l/r) : r

Enter another data (y/n) ?	n

Binary Tree created !!

	The Binary tree elements are :
		4	2	5	1	3	6
	No. of elements :6
===================================================
Do you want to continue (y/n) ? : y
===================================================

				MENU
Press:
	1. Create Binary tree
	2. Create Threaded binary tree
	3. Display Threaded Binary tree
	4. Display inorder array
	CHOICE : 2

	TBT created !!

===================================================
Do you want to continue (y/n) ? : y
===================================================

				MENU
Press:
	1. Create Binary tree
	2. Create Threaded binary tree
	3. Display Threaded Binary tree
	4. Display inorder array
	CHOICE : 3

	The TBT elements are :
		4	2	5	1	3	6
===================================================
Do you want to continue (y/n) ? : y
===================================================

				MENU
Press:
	1. Create Binary tree
	2. Create Threaded binary tree
	3. Display Threaded Binary tree
	4. Display inorder array
	CHOICE : 4

	The inorder array elements are :
		4	2	5	1	3	6
	No. of elements :6
===================================================
Do you want to continue (y/n) ? : n
===================================================
 */



//Alternate function for TBT craetion
/*
void tree::create_TBT()
{
	node* temp;
	head = new node();								//Dynamically allocated memory to head
	head->left = root;
	head->right = head;
	 cout<<"\n\t\tcount:"<<cnt;

	for(int i=0;i<cnt;i++)
 	{
		temp = datanode[i];
		cout<<"\n\tdata : "<<temp->data;
		if(temp->left==NULL)						//Checking for left child
		{
			if(temp==datanode[0])
				temp->left = head;					//first element has no inorder predecessor
			else
				temp->left = datanode[i-1];
			temp->lflag= 1;							//flag=1 means thread
		}
		if(temp->right==NULL)
		{
			if(datanode[i+1]==NULL)
				temp->right = head;					//last child has no inorder successor
			else
				temp->right = datanode[i+1];
			temp->rflag= 1;
		}


	}

}
*/
