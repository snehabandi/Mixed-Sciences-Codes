//============================================================================
// Name        : complex_no.cpp
// Author      : Sneha Bandi
// Roll No.    : 2401
// Description : To add and multiply two complex numbers by insertion,extraction,
//			addition and multiplication operator overloading
//============================================================================

#include<iostream>
using namespace std;
class complex
{
	float real,img;
public:
	complex();				//default constructor
	complex(int,int);		//parameterised constructor
	void accept();
	void display();

	friend istream& operator>>(istream& in,complex& c);	//as 'img' and 'real' are private members to 
	friend ostream& operator<<(ostream& out,complex& c);    //ostream class thus friend function is needed

	complex operator + (complex);
	complex operator * (complex);

};

istream& operator >> (istream& in,complex& c)
{
	cout<<"Enter real part : ";
	in>>c.real;
	cout<<"Enter imaginary part : ";
	in>>c.img;
	return in;
}
ostream& operator << (ostream& out,complex& c)		//extraction operator overloading;out is obj. of ostream class 
{
	out<<c.real<<"+"<<c.img<<"i"<<endl;
	return out;
}
complex::complex()			//Default constructor definition
{
	real=img=0;
}
complex::complex(int r,int i)		//parameterized constructor definition
{
	real=r;
	img=i;
}

complex complex::operator+(complex c2)		//+ operator overloaded
{
	complex temp;
	temp.real = real+c2.real;
	temp.img = img + c2.img;
		return temp;
}

complex complex::operator *(complex c2)		//* operator overloaded
{
	complex temp;
	temp.real = (real * c2.real)-(img * c2.img);
	temp.img = (real * c2.img)+(img * c2.real);
		return temp;
}
int main()
{
	complex c1,c2,c3;
	int n;
	char choice;
	cout<<"\n\t\t\tTHIS PROGRAM IS TO PERFORM OPERATIONS ON COMPLEX NUMBERS\n\n";
	do
	{
		cout << "Enter the first complex number\n";
		cin>>c1;
		cout << "Enter the second complex number\n";
		cin>>c2;
		cout<<"_______________________________\n";
		cout<<"\n\tThe first complex no. is: "<<c1;
		cout<<"\n\tThe second complex no. is: "<<c2;
		cout<<"\n_______________________________\n";
		cout<<"Enter your choice of operation\n";
		cout<<"press:\n1. for addition\n2. for multiplication\n";
		cin>>n;
		//SWITCH CASE 
		switch(n)
		{
		 case 1:
			cout<<"\nDefault constructor value : ";
			cout<<c3;
			//Default constructor call that shows 0+0i
			c3=c1+c2;
			cout<<"Addition of two complex numbers is : ";
			cout<<c3;
			break;

		 case 2:

			c3=c1*c2;
			cout<<"Multiplication of two complex numbers is : ";
			cout<<c3;
			break;
		}
		//SWITCH CASE ENDS
		cout<<"\n========================================";
		cout<<"\nDo you want to continue (y/n)?\t";
		cin>>choice;
		cout<<"========================================\n";

	}while(choice=='y' || choice=='Y');

	return 0;
}
//PROGRAM ENDS
//<-------------------------------------- OUTPUT ----------------------------------------->
/*

			THIS PROGRAM IS TO PERFORM OPERATIONS ON COMPLEX NUMBERS

Enter the first complex number
Enter real part : 12
Enter imaginary part : 3
Enter the second complex number
Enter real part : 11
Enter imaginary part : 5
_______________________________

	The first complex no. is: 12+3i

	The second complex no. is: 11+5i

_______________________________
Enter your choice of operation
press:
1. for addition
2. for multiplication
1

Default constructor value : 0+0i
Addition of two complex numbers is : 23+8i

========================================
Do you want to continue (y/n)?	y
========================================
Enter the first complex number
Enter real part : 3
Enter imaginary part : 2
Enter the second complex number
Enter real part : 1
Enter imaginary part : 1
_______________________________

	The first complex no. is: 3+2i

	The second complex no. is: 1+1i

_______________________________
Enter your choice of operation
press:
1. for addition
2. for multiplication
2
Multiplication of two complex numbers is : 1+5i

========================================
Do you want to continue (y/n)?	n
========================================

*/
