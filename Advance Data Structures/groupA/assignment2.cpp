//============================================================================
// Name        : assignment2.cpp
// Author      : Sneha Bandi
// Roll No.    : 2401
// Description : Binary search tree create,display
//============================================================================

#include<iostream>
#include<math.h>
#include<queue>
using namespace std;
//NODE CLASS
class node
{
	friend class tree;
	int data;
	node* left;
	node* right;
public:
	node()
	{
		data = 0;
		left = NULL;
		right = NULL;
	}
	node(int d)
    {
	 data=d;
	 left = NULL;
	 right = NULL;
    }
};

//TREE CLASS
class tree
{
	node* root;
public:
	tree()
	{
		root = NULL;
	}
	 void inorder_rec()
	 {
		 inorder(root);
	 }
	void inorder(node*);
	void create();
	node* insert(node*,int);
	void min_rec()
	{
		int x;
		x = min_(root);
		cout<<"\n The minimum value is : "<<x;
	}
	int min_(node*);
	void max_rec()
	{
		int x;
		x = max_(root);
		cout<<"\n The maximum value is : "<<x;
	}
	int max_(node*);
	void search_rec()
	{
		int k,x;
		cout<<"\nEnter the key to be searched : ";
		cin>>k;
		x = search(root,k);
		if(x==1)
			cout<<"\nElement found !!";
		else
			cout<<"\nElement NOT found !!";
	}
	int search(node*,int);
	void mirror_rec()
	{
		mirror(root);
	}
	void mirror(node*);
	void height_rec()
	{
		int h;
		h = height(root);
		cout<<"\n Height of the tree is : "<<h;
	}
	int height(node*);

	void mirror_non_rec();
};

void tree::create()
{
	int d;
	char ans;
	tree t;
	do
	{
	 cout<<"\nEnter the data : ";
	 cin>>d;
	 root = insert(root,d);
	 cout<<"\nDo you want to continue (y/n) ?\t";
	 cin>>ans;
	}while(ans == 'y'||ans == 'Y');
}
//BINARY SEARCH TREE CREATION
node* tree::insert(node* ptr,int d)
{
 if(ptr==NULL)
 {
	 node *temp;
	 temp = new node(d);
	 temp->data = d;
	 temp->left=NULL;
	 temp->right=NULL;
	 return temp;
 }
 if(d>ptr->data)
	 ptr->right = insert(ptr->right,d);
 else if(d<ptr->data)
	 ptr->left = insert(ptr->left,d);

 return ptr;

}
//INORDER DISPLAY
void tree::inorder(node* ptr)
{
 if(ptr==NULL)
	 return;
 else
 {
  inorder(ptr->left);
  cout<<ptr->data<<"\t";
  inorder(ptr->right);
 }
}

int tree::min_(node* ptr)
{
 if(ptr->left==NULL)
	 return (ptr->data);
 else
	 return min_(ptr->left);
}
int tree::max_(node* ptr)
{
	 if(ptr->right==NULL)
		 return (ptr->data);
	 else
		 return max_(ptr->right);
}
int tree::search(node* ptr,int key)
{
 if(ptr==NULL)
		return 0;
 if(key>ptr->data)
	 return search(ptr->right,key);
 else if(key<ptr->data)
	 return search(ptr->left,key);
 else
	 return 1;
}

int tree::height(node* ptr)
{
 if(ptr==NULL)
	 return 0;
 else
 {
	 int val;
	val = max(height(ptr->left),height(ptr->right));
	return (val+1);
 }
}
void tree::mirror(node* ptr)
{
	if(ptr==NULL)
		return;
	else
	{
		node* temp;
		mirror(ptr->left);
		mirror(ptr->right);
		temp = ptr->left;
		ptr->left=ptr->right;
		ptr->right =temp;
	}

}
void tree::mirror_non_rec()
{
	node *ptr,*temp;
 queue<node*> q;
 ptr=root;
 q.push(ptr);
 while(!q.empty())
 {
	 ptr = q.front();
	 q.pop();
	 temp =ptr->left;
	 ptr->left = ptr->right;
	 ptr->right =temp;
	 if(ptr->left!=NULL)
		 q.push(ptr->left);
	 if(ptr->right!=NULL)
		 q.push(ptr->right);
 }
}
//MAIN
int main()
{
	tree t1,t2;
	char ans1;
	int choice;
	do
	{
		cout<<"\n\t\t\t\tMENU";
		cout<<"\nPress:";
		cout<<"\n\t1. Create tree";
		cout<<"\n\t2. Inorder display";
		cout<<"\n\t3. Mininmum Value";
		cout<<"\n\t4. Maximum value";
		cout<<"\n\t5. Search";
		cout<<"\n\t6. Height of tree";
		cout<<"\n\t7. Mirror display";
		cout<<"\n\t8. Mirror display (non-recursive)";
		cout<<"\nCHOICE : ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			t1.create();
			break;
		case 2:
			t1.inorder_rec();
			break;
		case 3:
			t1.min_rec();
			break;
		case 4:
			t1.max_rec();
			break;
		case 5:
			t1.search_rec();
			break;
		case 6:
			t1.height_rec();
			break;
		case 7:
			t1.mirror_rec();
			t1.inorder_rec();
			break;
		case 8:
			t1.mirror_non_rec();
			t1.inorder_rec();
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
	1. Create tree
	2. Inorder display
	3. Mininmum Value
	4. Maximum value
	5. Search
	6. Height of tree
	7. Mirror display
	8. Mirror display (non-recursive)
CHOICE : 1

Enter the data : 40

Do you want to continue (y/n) ?	y

Enter the data : 20

Do you want to continue (y/n) ?	y

Enter the data : 60

Do you want to continue (y/n) ?	y

Enter the data : 10

Do you want to continue (y/n) ?	y

Enter the data : 30

Do you want to continue (y/n) ?	y

Enter the data : 50

Do you want to continue (y/n) ?	y

Enter the data : 70

Do you want to continue (y/n) ?	n

===================================================
Do you want to continue (y/n) ? : y
===================================================

				MENU
Press:
	1. Create tree
	2. Inorder display
	3. Mininmum Value
	4. Maximum value
	5. Search
	6. Height of tree
	7. Mirror display
	8. Mirror display (non-recursive)
CHOICE : 2
10	20	30	40	50	60	70	
===================================================
Do you want to continue (y/n) ? : y
===================================================

				MENU
Press:
	1. Create tree
	2. Inorder display
	3. Mininmum Value
	4. Maximum value
	5. Search
	6. Height of tree
	7. Mirror display
	8. Mirror display (non-recursive)
CHOICE : 3

 The minimum value is : 10
===================================================
Do you want to continue (y/n) ? : y
===================================================

				MENU
Press:
	1. Create tree
	2. Inorder display
	3. Mininmum Value
	4. Maximum value
	5. Search
	6. Height of tree
	7. Mirror display
	8. Mirror display (non-recursive)
CHOICE : 4

 The maximum value is : 70
===================================================
Do you want to continue (y/n) ? : y
===================================================

				MENU
Press:
	1. Create tree
	2. Inorder display
	3. Mininmum Value
	4. Maximum value
	5. Search
	6. Height of tree
	7. Mirror display
	8. Mirror display (non-recursive)
CHOICE : 5

Enter the key to be searched : 80

Element NOT found !!
===================================================
Do you want to continue (y/n) ? : y
===================================================
				MENU
Press:
	1. Create tree
	2. Inorder display
	3. Mininmum Value
	4. Maximum value
	5. Search
	6. Height of tree
	7. Mirror display
	8. Mirror display (non-recursive)
CHOICE : 5

Enter the key to be searched : 50

Element found !!
===================================================
Do you want to continue (y/n) ? : y
===================================================

				MENU
Press:
	1. Create tree
	2. Inorder display
	3. Mininmum Value
	4. Maximum value
	5. Search
	6. Height of tree
	7. Mirror display
	8. Mirror display (non-recursive)
CHOICE : 6

 Height of the tree is : 3
===================================================
Do you want to continue (y/n) ? : y
===================================================

				MENU
Press:
	1. Create tree
	2. Inorder display
	3. Mininmum Value
	4. Maximum value
	5. Search
	6. Height of tree
	7. Mirror display
	8. Mirror display (non-recursive)
CHOICE : 7
70	60	50	40	30	20	10			//mirror of original binary tree
===================================================
Do you want to continue (y/n) ? : y
===================================================

				MENU
Press:
	1. Create tree
	2. Inorder display
	3. Mininmum Value
	4. Maximum value
	5. Search
	6. Height of tree
	7. Mirror display
	8. Mirror display (non-recursive)
CHOICE : 8
10	20	30	40	50	60	70			//mirror of mirror thus original binary tree	
===================================================
Do you want to continue (y/n) ? : y
===================================================

*/

