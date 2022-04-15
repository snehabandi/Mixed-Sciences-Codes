//============================================================================
// Name          : Sneha Bandi
// Roll No       : 2401
// Assignment 8  : AVL Trees and its operations : Insert,delete,search,modify
//============================================================================

#include <iostream>
using namespace std;
#include <string.h>
#define MAX 30
class node
{
	node *right;
	node *left;
	int height;
	char keyword[10];
	char meaning[30];
public:
	node(char k[], char m[])
	{
		right=NULL;
		left=NULL;
		strcpy(keyword,k);
		strcpy(meaning,m);
		height =0;
	}
	friend class avl;
};

class avl
{
	node *root1;
public:
	avl(){
			root1=NULL;
		}
	void switchmenu();
	void insert1();
	node* insert(node* root, char[], char[]);
	int getht(node*);
	int bfactor(node*);
	node* LL(node*);
	node* LR(node*);
	node* RL(node*);
	node* RR(node*);
	node* rotateleft(node*);
	node* rotateright(node*);
	void inorder(node*);
	void descending(node*);
	void search(char[]);
	void modify(char[]);
	node* delete1(node*, char[]);
};
void avl::switchmenu(){
	char key[MAX];
	int n,x;
	char ans;
	do{
		cout<<"\n<----------------------------- Dictionary Menu ---------------------------------->\n";
		cout<<"\nPress :";
		cout<<"\n\t1.Insert";
		cout<<"\n\t2.Display";
		cout<<"\n\t3.Search";
		cout<<"\n\t4.Modify";
		cout<<"\n\t5.Delete";
		cout<<"\n\tChoice : ";
		cin>>n;
	switch(n){
	case 1:
		insert1();
		break;
	case 2:
		cout<<"\n\t1.Ascending\t\t2.Descending \n";
		cin>>x;
		cout<<"\n\t1.Word\t\t\t\t2.Meaning \n";
		if(x==1)
			inorder(root1);
		else
			descending(root1);
		break;
	case 3:
		cout<<"\nEnter the word for search : ";
		cin>>key;
		search(key);
		break;
	case 4:
		cout<<"\nEnter the word for search : ";
		cin>>key;
		modify(key);
		break;
	case 5:
		cout<<"\nEnter the word to delete : ";
		cin>>key;
		root1=delete1(root1, key);
		break;
	default:
		cout<<"\nInvalid";
		break;
	}
	cout<<"\n==================================================================";
	cout<<"\nDo you want to continue (y/n)?\t ";
	cin>>ans;
	cout<<"==================================================================\n";
	cout<<endl;
	}while(ans=='y' || ans =='Y');
}
void avl::insert1()
{
	char ans1;
	do{
	char k[MAX], m[MAX];
	cout<<"\n\tEnter word : ";
	cin>>k;
	cout<<"\tEnter meaning : ";
	cin.ignore();
	cin.getline(m,30);
	root1=insert(root1,k,m);
	cout<<"\nDo you want to enter another record (y/n)?\t";
	cin>>ans1;
	}while(ans1=='y'||ans1=='Y');
}

node* avl::insert(node* root,char k[], char m[])
{
	node* temp;
	if(root==NULL){
		temp = new node(k,m);
		root=temp;
		return root;
	}
	else if(strcmp(k,root->keyword)<0)
	{
			root->left = insert(root->left,k,m);
			if(bfactor(root)==2)
			{
				if(strcmp(k,root->left->keyword)<0)
					root=LL(root);
				else
					root=LR(root);
			}
	}
	else if(strcmp(k,root->keyword)>0)
	{
		root->right = insert(root->right,k,m);
		if(bfactor(root)==-2)
		{
			if(strcmp(k,root->right->keyword)>0)
						root=RR(root);
			else
						root=RL(root);
		}
	 }
	 root->height = getht(root);
	 return root;
}

int avl::getht(node *root)
{
	int lh, rh;
	if(root==NULL)
		return 0;
	if(root->left==NULL)
		lh=0;
	 	else
		lh=1+root->left->height;
	if(root->right==NULL)
			rh=0;
		else
			rh=1+root->right->height;
	if(lh>rh)
		return lh;
	else
		return rh;
}
int avl::bfactor(node *root)
{
	int lh, rh;
		if(root==NULL)
			return 0;
		if(root->left==NULL)
			lh=0;
		 	else
			lh=1+root->left->height;
		if(root->right==NULL)
				rh=0;
			else
				rh=1+root->right->height;

			return (lh-rh);
	}
node* avl::LL(node *root){
	root=rotateright(root);
	return (root);
 	 }
node* avl::RR(node *root){
	root=rotateleft(root);
	return (root);
	}
node* avl::RL(node *root){
	root->right=rotateright(root->right);
	root=rotateleft(root);
	return(root);
}
node* avl::LR(node *root){
	root->left=rotateleft(root->left);
	root=rotateright(root);
	return(root);
}
node* avl::rotateleft(node *root)
{
		node *temp;
		temp=root->right;
		root->right=temp->left;
		temp->left=root;
		root->height=getht(root);
		temp->height=getht(temp);
		return temp;
}
node* avl::rotateright(node *root)
{
		node *temp;
		temp=root->left;
		root->left=temp->right;
		temp->right=root;
		root->height=getht(root);
		temp->height=getht(temp);
		return temp;
}
void avl::inorder(node *t)
{
	if(t!=NULL){
		inorder(t->left);
		cout<<"\t"<<t->keyword<<"\t\t\t\t\t"<<t->meaning<<"\n";
		inorder(t->right);
	}
}
void avl::descending(node *t)
{
	if(t!=NULL){
		descending(t->right);
		cout<<"\t"<<t->keyword<<"\t\t\t\t\t"<<t->meaning<<"\n";
		descending(t->left);
	}
}
void avl::search(char k[])
{
	int flag =0;
	node *ptr;
	ptr = root1;
	while(ptr!=NULL)
	{
		if(strcmp(k,ptr->keyword)==0)
		{
			flag = 1;
			cout<<"\n\tWord Found !!";
			cout<<"\n\t"<<ptr->keyword<<"\t\t\t\t\t"<<ptr->meaning<<"\n";
			break;
		}
		else if(strcmp(k,ptr->keyword)<0)
		{
			ptr = ptr->left;
		}
		else if(strcmp(k,ptr->keyword)>0)
		{
			ptr = ptr->right;
		}
	}
	if(flag==0)
		cout<<"\n\tWord NOT Found !!";
}
void avl::modify(char k[])
{
	int flag =0;
	node *ptr;
	ptr = root1;
	char m[MAX];
	while(ptr!=NULL)
	{
		if(strcmp(k,ptr->keyword)==0)
		{
			flag = 1;
			break;
		}
		else if(strcmp(k,ptr->keyword)<0)
		{
			ptr = ptr->left;
		}
		else if(strcmp(k,ptr->keyword)>0)
		{
			ptr = ptr->right;
		}
	}
	if (flag==1)
	{
		cout<<"\nCurrent meaning : "<<ptr->meaning;
		cout<<"\nEnter new meaning : ";
		cin.ignore();
		cin.getline(m,30);
		strcpy(ptr->meaning,m);
		cout<<"\n\t\tMeaning modified !! ";
	}
	else
		cout<<"\n\t\tWord is NOT present !!!";
}
node* avl::delete1(node* root,char k[])
{
	node* temp;
	if(root==NULL)
		return NULL;
	else if(strcmp(k,root->keyword)<0)
	{
			root->left = delete1(root->left,k);
			if(bfactor(root)==-2)
			{
				if(bfactor(root->right)<=0)
					root=RR(root);
				else
					root=RL(root);
			}
	}
	else if(strcmp(k,root->keyword)>0)
	{
			root->right = delete1(root->right,k);
				if(bfactor(root)==2)
			{
					if(bfactor(root->left)>=0)
						root=LL(root);
					else
						root=LR(root);
			}
	}
	else
	{
		if(root->right!=NULL)
		{
			temp = root->right;
			while(temp->left!=NULL)
				temp = temp->left;

			strcpy(root->keyword,temp->keyword);
			strcpy(root->meaning,temp->meaning);
			root->right = delete1(root->right, temp->keyword);
			if(bfactor(root)==2)
			{
				if(bfactor(root->left)>=0)
						root = LL(root);
				else
						root = LR(root);
			}
		}
		else
			return (root->left);
		}

			root->height = getht(root);
			return(root);
	}
int main() {
	avl obj;
	obj.switchmenu();
	return 0;
}
//----------------------------->> OUTPUT <<------------------------------
/*
<----------------------------- Dictionary Menu ---------------------------------->

Press :
	1.Insert
	2.Display
	3.Search
	4.Modify
	5.Delete
	Choice : 1

	Enter word : do
	Enter meaning : loop statement

Do you want to enter another record (y/n)?	y

	Enter word : if
	Enter meaning : conditional statement

Do you want to enter another record (y/n)?	y

	Enter word : while
	Enter meaning : loop statement

Do you want to enter another record (y/n)?	y

	Enter word : break
	Enter meaning : conditional jump

Do you want to enter another record (y/n)?	y

	Enter word : for
	Enter meaning : loop statement

Do you want to enter another record (y/n)?	y

	Enter word : continue
	Enter meaning : unconditional jump

Do you want to enter another record (y/n)?	n

==================================================================
Do you want to continue (y/n)?	 y
==================================================================


<----------------------------- Dictionary Menu ---------------------------------->

Press :
	1.Insert
	2.Display
	3.Search
	4.Modify
	5.Delete
	Choice : 2

	1.Ascending		2.Descending
choice : 1

	1.Word				2.Meaning

	break				conditional jump
	continue			unconditional jump
	do				loop statement
	for				loop statement
	if				conditional statement
	while				loop statement

==================================================================
Do you want to continue (y/n)?	 y
==================================================================


<----------------------------- Dictionary Menu ---------------------------------->

Press :
	1.Insert
	2.Display
	3.Search
	4.Modify
	5.Delete
	Choice : 2

	1.Ascending		2.Descending
choice : 2

	1.Word				2.Meaning

	while				loop statement
	if				conditional statement
	for				loop statement
	do				loop statement
	continue			unconditional jump
	break				conditional jump

==================================================================
Do you want to continue (y/n)?	 y
==================================================================


<----------------------------- Dictionary Menu ---------------------------------->

Press :
	1.Insert
	2.Display
	3.Search
	4.Modify
	5.Delete
	Choice : 3

Enter the word for search : for

	Word Found !!
	for					loop statement

==================================================================
Do you want to continue (y/n)?	 y
==================================================================


<----------------------------- Dictionary Menu ---------------------------------->

Press :
	1.Insert
	2.Display
	3.Search
	4.Modify
	5.Delete
	Choice : 3

Enter the word for search : else

	Word NOT Found !!
==================================================================
Do you want to continue (y/n)?	 y
==================================================================


<----------------------------- Dictionary Menu ---------------------------------->

Press :
	1.Insert
	2.Display
	3.Search
	4.Modify
	5.Delete
	Choice : 4

Enter the word for search : break

Current meaning : conditional jump
Enter new meaning : unconditional jump

		Meaning modified !!
==================================================================
Do you want to continue (y/n)?	 y
==================================================================


<----------------------------- Dictionary Menu ---------------------------------->

Press :
	1.Insert
	2.Display
	3.Search
	4.Modify
	5.Delete
	Choice : 2

	1.Ascending		2.Descending
choice : 1

	1.Word				2.Meaning

	break				unconditional jump
	continue			unconditional jump
	do				loop statement
	for				loop statement
	if				conditional statement
	while				loop statement

==================================================================
Do you want to continue (y/n)?	 y
==================================================================


<----------------------------- Dictionary Menu ---------------------------------->

Press :
	1.Insert
	2.Display
	3.Search
	4.Modify
	5.Delete
	Choice : 5

Enter the word to delete : do
Record Deleted !!!
==================================================================
Do you want to continue (y/n)?	 y
==================================================================


<----------------------------- Dictionary Menu ---------------------------------->

Press :
	1.Insert
	2.Display
	3.Search
	4.Modify
	5.Delete
	Choice : 2

	1.Ascending			2.Descending
choice: 1

	1.Word				2.Meaning
		
	break				unconditional jump
	continue			unconditional jump
	for				loop statement
	if				conditional statement
	while				loop statement

==================================================================
Do you want to continue (y/n)?	 n
==================================================================
 */
