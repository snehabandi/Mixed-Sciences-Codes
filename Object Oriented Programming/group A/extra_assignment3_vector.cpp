//============================================================================
// Name        : VECTOR.cpp
// Author      : Sneha Bandi
// Roll No.    : 2401
// Description : USING GENERALISED PROGRAMMING i.e. TEMPLATES
//	       : To create vector
//	       : To modify the value of a given element
//	       : To multiply by a scalar value
//	       : To display vector in the form of (10,20,30...)
//============================================================================
#include<iostream>
using namespace std;

//TEMPLATISED CLASS 'VECTOR'
template<class T>
class vector
{
 T *a;                        //POINTER FOR INTEGER ARRAY
 int n;                         //SIZE OF ARRAY
public:
 void create();
 void modify();
 void multiply();
 void display();
};
//CLASS ENDS

//CREATION OF VECTOR i.e DYNAMIC ARRAY CREATION
template<class T>
void vector<T>::create()
{
 cout<<"\nEnter the size of the vector: ";			//SIZE ACCEPTED FROM USER
 cin>>n;
 a = new T[n];                                                //DYNAMIC ALLOCATION TO ARRAY
 cout<<"\nEnter integeral elements: ";				
 for(int i=0;i<n;i++)
  cin>>a[i];

}

//DISPLAYING VECTOR ELEMENTS
template<class T>
void vector<T>::display()
{
  cout<<"(";
   for(int i=0;i<n;i++)
   {
     cout<<a[i];
     if(i!=(n-1)) 
      cout<<" , ";
   }
  cout<<")\n";
}

//TO MODIFY VECTOR ELEMENTS
template<class T>
void vector<T>::modify()
{
  T temp;
  int i=0;
  cout<<"\nEnter the value to be modified : ";
  cin>>temp;
  for(i=0;i<n;i++)
  {
    if(a[i]==temp)
    {
      cout<<"\n----------VALUE FOUND!--------------";
      cout<<"\n\nEnter new value : ";
      cin>>a[i];
      break;
    }
  }
  if(i==(n+1))
      cout<<"\n----------VALUE NOT FOUND!--------------";

}

//TO MULTIPLY VECTOR BY A SCALAR VALUE
template<class T>
void vector<T>::multiply()
{
	int k;
	cout<<"\nEnter the scalar to be multiplied : ";
	cin>>k;
	for(int i=0;i<n;i++)
	{
         a[i]=k*a[i];                   //MULTIPLIED BY CONSTANT K
	}
}
//MAIN()
int main()
{
 vector<int> vi;
 vector<float> vf;
 char ans;
 int choice;
   cout<<"\n==========================================================="; 
    //DO-WHILE STARTS
 do
 {
   cout<<"\n\n********************* MENU *********************\n";
   cout<<"\n\tPRESS:n\n\t1. To create a vector";
   cout<<"\n\t2. To modify vector elements";
   cout<<"\n\t3. To multiply vector by a scalar value";
   cout<<"\n\nCHOICE : ";
   cin>>choice;
   cout<<"________________________________________________________________\n";
   //SWITCH CASE STARTS
   switch(choice)
   {
    case 1:
    	  //ACCEPT-DISPLAY OF INTEGER VECTOR
    	  cout<<"\n<----------------------- INTEGER ----------------------->\n";
    	   vi.create();
    	   cout<<"\nVECTOR : ";
    	   vi.display();
    	  cout<<"\n<----------------------- FLOAT ----------------------->\n";           
    	  //ACCEPT-DISPLAY OF FLOAT VECTOR
    	   vf.create();
    	   cout<<"\nVECTOR : ";
    	   vf.display();
    	   break;
    case 2:
    	  cout<<"\n<----------------------- INTEGER ----------------------->\n";    
           //MODIFICATION OF VALUES IN INTEGER VECTOR
    	   vi.modify();
    	   cout<<"\nThe MODIFIED vector : ";
    	   vi.display();
    	  cout<<"\n<----------------------- FLOAT ----------------------->\n";           
           //MODIFICATION OF VALUES IN FLOAT VECTOR
    	   vf.modify();
    	   cout<<"\nThe MODIFIED vector : ";
    	   vf.display();
    	   break;   
    case 3:
    	  cout<<"\n<----------------------- INTEGER ----------------------->\n";    
           //MULTIPLYING CONSTANT TO A INTEGER VECTOR
    	   vi.multiply();
    	   cout<<"\nThe new vector is :";
    	   vi.display();
           //MULTIPLYING CONSTANT TO A FLOAT VECTOR
    	  cout<<"\n<----------------------- FLOAT ----------------------->\n";           
    	   vf.multiply();
    	   cout<<"\nThe new vector is :";
    	   vf.display();
    	   break;
    default:
           cout<<"\nINVALID CHOICE !!!\n";
    	   break;    	       	   
    }
    //SWITCH CASE ENDS
   cout<<"\n==========================================================="; 
   cout<<"\nDo you want to continue (y/n)?\t";
   cin>>ans;
   cout<<"==========================================================="; 
 }while(ans=='Y'||ans=='y');
 //DO-WHILE ENDS
 cout<<endl;
 return 0;
}
//PROGRAM ENDS


//<----------------------------------OUTPUT----------------------------------->
/*

===========================================================

********************* MENU *********************

	PRESS:n
	1. To create a vector
	2. To modify vector elements
	3. To multiply vector by a scalar value

CHOICE : 1
________________________________________________________________

<----------------------- INTEGER ----------------------->

Enter the size of the vector: 4

Enter integeral elements: 1	2	3	4

VECTOR : (1 , 2 , 3 , 4)

<----------------------- FLOAT ----------------------->

Enter the size of the vector: 3

Enter integeral elements: 1.125
2.235
6.12305

VECTOR : (1.125 , 2.235 , 6.12305)

===========================================================
Do you want to continue (y/n)?	y
===========================================================

********************* MENU *********************

	PRESS:n
	1. To create a vector
	2. To modify vector elements
	3. To multiply vector by a scalar value

CHOICE : 2
________________________________________________________________

<----------------------- INTEGER ----------------------->

Enter the value to be modified : 2

----------VALUE FOUND!--------------

Enter new value : 89

The MODIFIED vector : (1 , 89 , 3 , 4)

<----------------------- FLOAT ----------------------->

Enter the value to be modified : 2.235

----------VALUE FOUND!--------------

Enter new value : 1000.02

The MODIFIED vector : (1.125 , 1000.02 , 6.12305)

===========================================================
Do you want to continue (y/n)?	y
===========================================================

********************* MENU *********************

	PRESS:n
	1. To create a vector
	2. To modify vector elements
	3. To multiply vector by a scalar value

CHOICE : 3
________________________________________________________________

<----------------------- INTEGER ----------------------->

Enter the scalar to be multiplied : 10

The new vector is :(10 , 890 , 30 , 40)

<----------------------- FLOAT ----------------------->

Enter the scalar to be multiplied : 10

The new vector is :(11.25 , 10000.2 , 61.2305)

===========================================================
Do you want to continue (y/n)?	n
===========================================================

*/























