//============================================================================
// Name        : assignment1.cpp
// Author      : Sneha Bandi
// Roll No.    : 2401
// Description : Create tree,inorder,preorder,postorder traversal,copy,erase
//				(recursive and non-recursive)
//============================================================================

#include<iostream>
#include<queue>
using namespace std;
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
		data = d;
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

 void create();
 void inorder(node*);
 void preorder(node*);
 void postorder(node*);

 void inorder_rec()
 {
	 inorder(root);
 }
 void preorder_rec()
 {
	 preorder(root);
 }
 void postorder_rec()
 {
	postorder(root) ;
 }
 //tree* operator=(tree*);
 	node* clone(node*);
	tree *operator =(tree&);
	node * copy_(node *);

 void copy_rec(tree&);

 void copy_non_rec(tree&);

 void erase(node*);
 void erase_rec()
 {
	 erase(root);
 }
};

void tree::create()
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
			 if(ptr->right==NULL){
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

void tree::inorder(node* ptr)
{
 if(ptr==NULL)
	 return;
 else
 {
  inorder(ptr->left);	//1
  cout<<ptr->data<<"\t";//2
  inorder(ptr->right);//3
 }

}
void tree::preorder(node* ptr)
{
 if(ptr==NULL)
	 return;
 else
 {
  cout<<ptr->data<<"\t";
  preorder(ptr->left);
  preorder(ptr->right);
 }
}
void tree::postorder(node* ptr)
{
	if(ptr==NULL)
		 return;
	 else
	 {
	  postorder(ptr->left);
	  postorder(ptr->right);
	  cout<<ptr->data<<"\t";
	 }
}

/*tree* tree::operator=(tree* s)
{
	 node *ptr;
	 tree* t;				//pointer to new tree
	 ptr=s->root;
	 if(ptr==NULL)
		 return NULL;
	 else
	 {
	  t->root=clone(s->root);
	  return t;
	 }

}
*/
node* tree::clone(node* p)
{
	 //p is pointer to old tree
	 node *new_temp;	//new node's temp
	 if(p==NULL)
		 return NULL;
	 else
	 {
	  new_temp = new node(p->data);
	  new_temp->left = clone(p->left);
	  new_temp->right = clone(p->right);
	  return new_temp;
	 }
}

tree* tree::operator=(tree& src)
{
	tree *old=&src;
	node *r=new node();
	r->data=old->root->data;
	root=r;
	root=copy_(old->root);
}
node* tree::copy_(node *temproot)
{
	if(temproot==NULL)
	{
		return NULL;
	}
	else
	{
		node *newnode;
		newnode=new node();
		newnode->left=copy_(temproot->left);
		newnode->right=copy_(temproot->right);
		newnode->data=temproot->data;
		return newnode;
	}
}
void tree::copy_rec(tree& t)
{
	 node *ptr;
	 ptr=root;
	 if(ptr==NULL)
		 return;
	 else
	  t.root=clone(root);

}
void tree::erase(node* p)		//Erase using post order traversal
{
//if(root->left==NULL && root->right==NULL)
	//root->data=0;//root=NULL;

	if(p->left!=NULL)			//Left
	{
		erase(p->left);
		p->left=NULL;
		if(root->left==NULL && root->right==NULL)
		{
		root=NULL;
		cout<<"\nThe tree is deleted!";
		}
	}
	if(p->right!=NULL)			//Right
	{
		erase(p->right);
		p->right=NULL;
		if(root->left==NULL && root->right==NULL)
		{
		root=NULL;
		cout<<"\nThe tree is deleted!";
		}
	}
	//make p = NULL if we donot want to display anything after the tree is deleted
	delete p;					//Node
}
void tree::copy_non_rec(tree& t2)
{
 queue<node*> q1,q2;
 node *ptr1,*ptr2,*temp2;
//second tree object t2

  q1.push(root);
  ptr1 = root;

  ptr2 = new node(root->data);				//temp2 is new node of tree2
  t2.root=ptr2;
  q2.push(ptr2);

  while(!q1.empty())
  {
	 ptr1 = q1.front();
	 q1.pop();
	 ptr2 = q2.front();
	 q2.pop();
	 if(ptr1->left!=NULL)
	 {
		 q1.push(ptr1->left);
		 temp2 = new node(ptr1->left->data);
		 ptr2->left = temp2;
		 q2.push(temp2);
	 }
	 if(ptr1->right!=NULL)
	 {
		 q1.push(ptr1->right);
		 temp2 = new node(ptr1->right->data);
		 ptr2->right=temp2;
		 q2.push(temp2);
	 }

  }
}

int main() {
	tree t1,t2;
	tree *b1,*b2;
	char ans1;
	int choice;
	do
	{
		cout<<"\n\t\t\t\tMENU";
		cout<<"\nPress:";
		cout<<"\n\t1. Create tree";
		cout<<"\n\t2. Inorder display (recursive)";
		cout<<"\n\t3. Preorder display (recursive)";
		cout<<"\n\t4. Postorder display (recursive)";
		cout<<"\n\t5. Copy tree (recursive) using assignment operator overloading";
		cout<<"\n\t6. Copy tree (recursive) without assignment operator overloading";
		cout<<"\n\t7. Copy tree (non-recursive)";
		cout<<"\n\t8. Erase tree";
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
			t1.preorder_rec();
			break;
		case 4:
			t1.postorder_rec();
			break;
		case 5:
//			t2 = t1;
//			t2.inorder_rec();
			b1=new tree();
			tree *newnode;
			newnode=new tree();
			b1->create();
			//b1->display_inorder();
			b2=new tree();
			*b2=*b1;
			delete b1;
			cout<<"Original tree deleted!\n";
			b2->inorder_rec();
			break;
		case 6:
			t1.copy_rec(t2);
			t2.inorder_rec();
			break;
		case 7:
			t1.copy_non_rec(t2);
			t2.inorder_rec();
			break;
		case 8:
			t1.erase_rec();
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
/*


				MENU
Press:
	1. Create tree
	2. Inorder display (recursive)
	3. Preorder display (recursive)
	4. Postorder display (recursive)
	5. Copy tree (recursive) using assignment operator overloading
	6. Copy tree (recursive) without assignment operator overloading
	7. Copy tree (non-recursive)
	8. Erase tree
CHOICE : 1

Enter data : 10

Enter another data (y/n) ?	y

Enter data : 20

Enter direction (l/r) : l

Enter another data (y/n) ?	y

Enter data : 30

Enter direction (l/r) : r

Enter another data (y/n) ?	y

Enter data : 40

Enter direction (l/r) : l

Enter direction (l/r) : l

Enter another data (y/n) ?	y

Enter data : 50

Enter direction (l/r) : l

Enter direction (l/r) : r

Enter another data (y/n) ?	y

Enter data : 60

Enter direction (l/r) : r

Enter direction (l/r) : l

Enter another data (y/n) ?	y

Enter data : 70

Enter direction (l/r) : r

Enter direction (l/r) : r

Enter another data (y/n) ?	n

===================================================
Do you want to continue (y/n) ? : y
===================================================

				MENU
Press:
	1. Create tree
	2. Inorder display (recursive)
	3. Preorder display (recursive)
	4. Postorder display (recursive)
	5. Copy tree (recursive) using assignment operator overloading
	6. Copy tree (recursive) without assignment operator overloading
	7. Copy tree (non-recursive)
	8. Erase tree
CHOICE : 2
40	20	50	10	60	30	70
===================================================
Do you want to continue (y/n) ? : y
===================================================

				MENU
Press:
	1. Create tree
	2. Inorder display (recursive)
	3. Preorder display (recursive)
	4. Postorder display (recursive)
	5. Copy tree (recursive) using assignment operator overloading
	6. Copy tree (recursive) without assignment operator overloading
	7. Copy tree (non-recursive)
	8. Erase tree
CHOICE : 3
10	20	40	50	30	60	70
===================================================
Do you want to continue (y/n) ? : y
===================================================

				MENU
Press:
	1. Create tree
	2. Inorder display (recursive)
	3. Preorder display (recursive)
	4. Postorder display (recursive)
	5. Copy tree (recursive) using assignment operator overloading
	6. Copy tree (recursive) without assignment operator overloading
	7. Copy tree (non-recursive)
	8. Erase tree
CHOICE : 4
40	50	20	60	70	30	10
===================================================
Do you want to continue (y/n) ? : y
===================================================

				MENU
Press:
	1. Create tree
	2. Inorder display (recursive)
	3. Preorder display (recursive)
	4. Postorder display (recursive)
	5. Copy tree (recursive) using assignment operator overloading
	6. Copy tree (recursive) without assignment operator overloading
	7. Copy tree (non-recursive)
	8. Erase tree
CHOICE : 5
40	20	50	10	60	30	70
===================================================
Do you want to continue (y/n) ? : y
===================================================

				MENU
Press:
	1. Create tree
	2. Inorder display (recursive)
	3. Preorder display (recursive)
	4. Postorder display (recursive)
	5. Copy tree (recursive) using assignment operator overloading
	6. Copy tree (recursive) without assignment operator overloading
	7. Copy tree (non-recursive)
	8. Erase tree
CHOICE : 6
40	20	50	10	60	30	70
===================================================
Do you want to continue (y/n) ? : y
===================================================

				MENU
Press:
	1. Create tree
	2. Inorder display (recursive)
	3. Preorder display (recursive)
	4. Postorder display (recursive)
	5. Copy tree (recursive) using assignment operator overloading
	6. Copy tree (recursive) without assignment operator overloading
	7. Copy tree (non-recursive)
	8. Erase tree
CHOICE : 7
40	20	50	10	60	30	70
===================================================
Do you want to continue (y/n) ? : y
===================================================

				MENU
Press:
	1. Create tree
	2. Inorder display (recursive)
	3. Preorder display (recursive)
	4. Postorder display (recursive)
	5. Copy tree (recursive) using assignment operator overloading
	6. Copy tree (recursive) without assignment operator overloading
	7. Copy tree (non-recursive)
	8. Erase tree
CHOICE : 8
		0
===================================================
Do you want to continue (y/n) ? : n
===================================================


*/
