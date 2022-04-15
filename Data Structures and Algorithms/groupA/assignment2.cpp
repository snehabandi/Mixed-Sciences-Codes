
//============================================================================
// Name        : matrix.cpp
// Author      : Sneha Bandi
// Roll No     : 2401
// Description : Matrix Operations:accept,display,upper triangular,transpose,
//			add,subtract,multiply
//============================================================================

#include <iostream>
using namespace std;

class matrix
{
	int A[20][20],B[20][20],C[20][20];
	int row1,col1,row2,col2,row,col;

public:
	void accept_A();
	void accept_B();
	void display_A();
	void display_B();
	void upper();
	void sum_diagonal();
	void transpose();
	void add_AB();
	void subtract_AB();
	void multiply_AB();


};

void matrix::accept_A()
{
	//Accepting row and column sizes of A
	cout<<"Enter the row size of matrix A : ";
	cin>>row1;
	cout<<"Enter the column size of matrix A : ";
	cin>>col1;

	//Accepting matrix A
	cout<<"Enter the elements of A matrix"<<endl;
	for(int i=0;i<row1;i++)
	{
		for(int j=0;j<col1;j++)
		{
			cin>>A[i][j];
		}

	}

}
void matrix::accept_B()
{
	//Accepting row and column sizes of B
	cout<<"Enter the row size of matrix B :";
	cin>>row2;
	cout<<"Enter the column size of matrix B :";
	cin>>col2;

	//Accepting matrix B
	cout<<"Enter the elements of A matrix"<<endl;
	for(int i=0;i<row2;i++)
	{
		for(int j=0;j<col2;j++)
		{
			cin>>B[i][j];
		}

	}
}
void matrix::display_A()
{
	//Displaying matrix A
		cout<<"the matrix A is"<<endl;
		for(int i=0;i<row1;i++)
		{
			for(int j=0;j<col1;j++)
			{
				cout<<"\t"<<A[i][j];
			}
			cout<<endl;

		}
}
void matrix::display_B()
{
	//Displaying matrix B
		cout<<"The matrix B is"<<endl;
		for(int i=0;i<row2;i++)
		{
			for(int j=0;j<col2;j++)
			{
				cout<<"\t"<<B[i][j];
			}
			cout<<endl;

		}
}
void matrix::upper()
{int flag=0;
//Checking if A is upper triangular matrix
		for(int i=0;i<row1;i++)
			{
			 for(int j=0;j<col1;j++)
				{
				 if((j<i && A[i][j]!=0) )
					 {
					 	 flag=1;
					 	 break;
					  }
				}

			}
		if(flag==1 )
			cout<<"The matrix is not an upper major triangular matrix"<<endl;
		else
			cout<<"The matrix is upper major triangular matrix"<<endl;
//Checking if A is upper triangular matrix
				for(int i=0;i<row1;i++)
					{
					 for(int j=0;j<col1;j++)
						{
						 if((i+j>=row1 && A[i][j]!=0) )
							 {
							 	 flag=2;
							 	 break;
							 }
						}

					}


		if(flag==2)
			cout<<"The matrix is not an upper minor triangular matrix"<<endl;
		else
			cout<<"The matrix is upper minor triangular matrix"<<endl;
}
void matrix::sum_diagonal()
{
	int sum_major=0,sum_minor=0;
  if(row1==col1)
    {
	for(int i=0;i<row1;i++)
			{
				for(int j=0;j<col1;j++)
				{
//Sum of major diagonal elements
					if(i==j)
						sum_major=sum_major+A[i][j];
//Sum of minor diagonal elements
					if(j==col1-i-1)
						sum_minor=sum_minor+A[i][j];
    }			}
			}
		cout<<"The sum of major diagonal elements is: "<<sum_major<<endl;
		cout<<"The sum of minor diagonal elements is: "<<sum_minor<<endl;
}

void matrix::transpose()
{	int temp=0;

//Transpose of matrix A if rows=columns
	if(row1==col1)
	{

		for(int i=0;i<row1;i++)
		{
			for(int j=0;j<col1;j++)
			{
				if(i<j)
				{
				 temp=A[i][j];
				 A[i][j]=A[j][i];
				 A[j][i]=temp;
				}
			}
		}
		cout<<"The transpose of";
		display_A();
	}
	//Transpose of matrix A if rows!=columns
	else if(row1!=col1)
	{
			cout<<"The transpose of"<<endl;

			for(int i=0;i<col1;i++)
			{
				for(int j=0;j<row1;j++)
				{
					cout<<A[j][i]<<"\t";
				}
				cout<<endl;
			}

	}
}

void matrix::add_AB()
{
//Addition of matrix A and B
		if(row1==row2 && col1==col2)
		{
			cout<<"The addition of matrix is"<<endl;
			for(int i=0;i<row2;i++)
			{
			 for(int j=0;j<col2;j++)
				{
				 	 C[i][j]=A[i][j]+B[i][j];
					cout<<"\t"<<C[i][j];
				}
			  cout<<endl;
			}
		}
		else
		cout<<"The addition is not possible"<<endl;
}
void matrix::subtract_AB()
{
//subtraction of matrix A and B
		if(row1==row2 && col1==col2)
		{
			cout<<"The subtraction of matrix is"<<endl;
			for(int i=0;i<row2;i++)
			{
			 for(int j=0;j<col2;j++)
				{
				 	 C[i][j]=A[i][j]-B[i][j];
					cout<<"\t"<<C[i][j];
				}
			  cout<<endl;
			}
		}
		else
		cout<<"The subtraction is not possible"<<endl;
}

void matrix::multiply_AB()
{
	int sum;
//To multiply matrices
	if(row2==col1)
	{
		cout<<"The multiplication matrix is:"<<endl;
	  for(int i=0;i<row1;i++)
		{
			for(int j=0;j<col2;j++)
			{
				 sum=0;
				for(int k=0;k<row2;k++)
				{
					sum = sum + (A[i][k]*B[k][j]);
				}
				C[i][j]= sum;
				cout<<C[i][j]<<"\t";
			}
			cout<<endl;
		}
	}
	else
	cout<<"Multiplication not possible!";
}

//main function

int main()
{
	cout<<"\t\tTHIS PROGRAM IS TO PERFORM VARIOUS MATRIX OPERATIONS"<<endl<<endl;

	matrix m;
	int n=0,p=0;
	char choice,choice1;
		cout<<"\n===========================================================================";
	do{
	cout<<"\nEnter the matrix operation you would like to be perform:"<<endl<<"Press:"<<endl;
	cout<<"\n\t1. To check if a matrix is a upper triangular matrix";
	cout<<"\n\t2. To compute summation of diagonal elements";
	cout<<"\n\t3. To compute transpose of matrix";
	cout<<"\n\t4. To perform addition or subtraction or multiplication of two matrices"<<endl<<"CHOICE : ";

	cin>>n;
	//switch case I
	switch(n)
	{
	case 1:
	m.accept_A();
	m.display_A();
	m.upper();
	break;


	case 2:
	m.accept_A();
	m.display_A();
	m.sum_diagonal();	
	break;
	case 3:
	m.accept_A();
	m.display_A();
	m.transpose();
	break;

	case 4:
	m.accept_A();
	m.display_A();
	m.accept_B();
	m.display_B();

	//To select the operation to be performed on the two matrices i.e addition or subtraction or multiplication
	cout<<"\n____________________________________________________________________________________";
	 do{
		cout<<endl<<"Select the operation to be performed::"<<endl<<"Press:"<<endl;
		cout<<"\n\t1 for addition";
		cout<<"\n\t2 for subtraction";
		cout<<"\n\t3 for multipliction";
		cout<<"\nNOTE: MATRIX DIVISION IS INVALID OPERATION AND NOT POSSIBLE!"<<endl;
		cin>>p;

	//switch case II
		switch(p)
		{
		  case 1:
		    m.add_AB();
		    break;
		  case 2:
		   m.subtract_AB();
		    break;
		  case 3:
		    m.multiply_AB();
		    break;
		  default:
		    cout<<"Invalid choice"<<endl;
		}
		cout<<endl<<"Do you want to perform any other operation on entered matrix i.e.addition,subtraction,multiplication (y/n)?\t";
			cin>>choice1;
	cout<<"\n____________________________________________________________________________________";
		}while(choice1=='y' || choice1=='Y');
	//switch case II ends

	break;

	default:
		cout<<"Invalid choice"<<endl;
		break;
}
		cout<<"\n===========================================================================";
cout<<endl<<"Do you want to perform any other matrix operations (y/n)?\t";
cin>>choice;
		cout<<"\n===========================================================================";
}while(choice=='y' || choice=='Y');

//Switch case I ends
	return 0;
}
//PROGRAM ENDS

//------------------------------------------------ OUTPUT ------------------------------------------------

/*
		THIS PROGRAM IS TO PERFORM VARIOUS MATRIX OPERATIONS


===========================================================================
Enter the matrix operation you would like to be perform:
Press:

	1. To check if a matrix is a upper triangular matrix
	2. To compute summation of diagonal elements
	3. To compute transpose of matrix
	4. To perform addition or subtraction or multiplication of two matrices
CHOICE : 1
Enter the row size of matrix A : 3
Enter the column size of matrix A : 3
Enter the elements of A matrix
1	2	3	0	5	6	0	0	9
the matrix A is
	1	2	3
	0	5	6
	0	0	9
The matrix is upper major triangular matrix
The matrix is not an upper minor triangular matrix

===========================================================================
Do you want to perform any other matrix operations (y/n)?	y

Enter the matrix operation you would like to be perform:
Press:

	1. To check if a matrix is a upper triangular matrix
	2. To compute summation of diagonal elements
	3. To compute transpose of matrix
	4. To perform addition or subtraction or multiplication of two matrices
CHOICE : 1
Enter the row size of matrix A : 3
Enter the column size of matrix A : 3
Enter the elements of A matrix
1	2	3	4	5	0	7	0       0
the matrix A is
	1	2	3
	4	5	0
	7	0	0
The matrix is not an upper major triangular matrix
The matrix is upper minor triangular matrix

===========================================================================
Do you want to perform any other matrix operations (y/n)?	y

===========================================================================
Enter the matrix operation you would like to be perform:
Press:

	1. To check if a matrix is a upper triangular matrix
	2. To compute summation of diagonal elements
	3. To compute transpose of matrix
	4. To perform addition or subtraction or multiplication of two matrices
CHOICE : 2
Enter the row size of matrix A : 4
Enter the column size of matrix A : 4
Enter the elements of A matrix
1	2	3	4	5	6	7	8	9	10	11	12	13	0	0	16	 
the matrix A is
	1	2	3	4
	5	6	7	8
	9	10	11	12
	13	0	0	16
The sum of major diagonal elements is: 34
The sum of minor diagonal elements is: 34

===========================================================================
Do you want to perform any other matrix operations (y/n)?	y

Enter the matrix operation you would like to be perform:
Press:

	1. To check if a matrix is a upper triangular matrix
	2. To compute summation of diagonal elements
	3. To compute transpose of matrix
	4. To perform addition or subtraction or multiplication of two matrices
CHOICE : 3
Enter the row size of matrix A : 3
Enter the column size of matrix A : 3
Enter the elements of A matrix
1	2	3	4	5	6	7	8	9
the matrix A is
	1	2	3
	4	5	6
	7	8	9
The transpose ofthe matrix A is
	1	4	7
	2	5	8
	3	6	9

===========================================================================
Do you want to perform any other matrix operations (y/n)?	y

Enter the matrix operation you would like to be perform:
Press:

	1. To check if a matrix is a upper triangular matrix
	2. To compute summation of diagonal elements
	3. To compute transpose of matrix
	4. To perform addition or subtraction or multiplication of two matrices
CHOICE : 3
Enter the row size of matrix A : 2
Enter the column size of matrix A : 3
Enter the elements of A matrix
1	2	3	4	5	6
the matrix A is
	1	2	3
	4	5	6
The transpose of
1	4	
2	5	
3	6	

===========================================================================
Do you want to perform any other matrix operations (y/n)?	y
===========================================================================
Enter the matrix operation you would like to be perform:
Press:

	1. To check if a matrix is a upper triangular matrix
	2. To compute summation of diagonal elements
	3. To compute transpose of matrix
	4. To perform addition or subtraction or multiplication of two matrices
CHOICE : 4
Enter the row size of matrix A : 3
Enter the column size of matrix A : 3
Enter the elements of A matrix
1	2	3	4	5	6	7	8	9
the matrix A is
	1	2	3
	4	5	6
	7	8	9
Enter the row size of matrix B :3
Enter the column size of matrix B :3
Enter the elements of A matrix
1	0	0	1	2	3	0       4	5
The matrix B is
	1	0	0
	1	2	3
	0	4	5

____________________________________________________________________________________
Select the operation to be performed::
Press:

	1 for addition
	2 for subtraction
	3 for multipliction
	NOTE: MATRIX DIVISION IS INVALID OPERATION AND NOT POSSIBLE!
1
The addition of matrix is
	2	2	3
	5	7	9
	7	12	14

Do you want to perform any other operation on entered matrix i.e. 							addition,subtraction,multiplication (y/n)?	y

____________________________________________________________________________________
Select the operation to be performed::
Press:

	1 for addition
	2 for subtraction
	3 for multipliction
	NOTE: MATRIX DIVISION IS INVALID OPERATION AND NOT POSSIBLE!
2
The subtraction of matrix is
	0	2	3
	3	3	3
	7	4	4

Do you want to perform any other operation on entered matrix i.e.addition,subtraction,multiplication (y/n)?	y

____________________________________________________________________________________
Select the operation to be performed::
Press:

	1 for addition
	2 for subtraction
	3 for multipliction
	NOTE: MATRIX DIVISION IS INVALID OPERATION AND NOT POSSIBLE!
3
The multiplication matrix is:
3	16	21	
9	34	45	
15	52	69	

Do you want to perform any other operation on entered matrix i.e.addition,subtraction,multiplication (y/n)?	n

____________________________________________________________________________________
===========================================================================
Do you want to perform any other matrix operations (y/n)?	y
===========================================================================
Enter the matrix operation you would like to be perform:
Press:

	1. To check if a matrix is a upper triangular matrix
	2. To compute summation of diagonal elements
	3. To compute transpose of matrix
	4. To perform addition or subtraction or multiplication of two matrices
CHOICE : 4
Enter the row size of matrix A : 2
Enter the column size of matrix A : 3
Enter the elements of A matrix
1	2	3	4	5	6
the matrix A is
	1	2	3
	4	5	6
Enter the row size of matrix B :2
Enter the column size of matrix B :3
Enter the elements of A matrix
1	2	3	4	5	6
The matrix B is
	1	2	3
	4	5	6

____________________________________________________________________________________
Select the operation to be performed::
Press:

	1 for addition
	2 for subtraction
	3 for multipliction
NOTE: MATRIX DIVISION IS INVALID OPERATION AND NOT POSSIBLE!
1
The addition of matrix is
	2	4	6
	8	10	12

Do you want to perform any other operation on entered matrix i.e.addition,subtraction,multiplication (y/n)?	y

____________________________________________________________________________________
Select the operation to be performed::
Press:

	1 for addition
	2 for subtraction
	3 for multipliction
NOTE: MATRIX DIVISION IS INVALID OPERATION AND NOT POSSIBLE!
2
The subtraction of matrix is
	0	0	0
	0	0	0

Do you want to perform any other operation on entered matrix i.e.addition,subtraction,multiplication (y/n)?	n

____________________________________________________________________________________

===========================================================================

//***************************** TEST CASE: Addition and multiplication of pxq and rxs matrices is not possible *****************************

===========================================================================
Enter the matrix operation you would like to be perform:
Press:

	1. To check if a matrix is a upper triangular matrix
	2. To compute summation of diagonal elements
	3. To compute transpose of matrix
	4. To perform addition or subtraction or multiplication of two matrices
CHOICE : 4
Enter the row size of matrix A : 2
Enter the column size of matrix A : 3
Enter the elements of A matrix
1	2	3	4	5	6
the matrix A is
	1	2	3
	4	5	6
Enter the row size of matrix B :2
Enter the column size of matrix B :1
Enter the elements of A matrix
8	9
The matrix B is
	8
	9

____________________________________________________________________________________
Select the operation to be performed::
Press:

	1 for addition
	2 for subtraction
	3 for multipliction
NOTE: MATRIX DIVISION IS INVALID OPERATION AND NOT POSSIBLE!
1
The addition is not possible

Do you want to perform any other operation on entered matrix i.e.addition,subtraction,multiplication (y/n)?	y

____________________________________________________________________________________
Select the operation to be performed::
Press:

	1 for addition
	2 for subtraction
	3 for multipliction
NOTE: MATRIX DIVISION IS INVALID OPERATION AND NOT POSSIBLE!
3
Multiplication not possible!
Do you want to perform any other operation on entered matrix i.e.addition,subtraction,multiplication (y/n)?	n

____________________________________________________________________________________
===========================================================================
Do you want to perform any other matrix operations (y/n)?	n

===========================================================================

*/
