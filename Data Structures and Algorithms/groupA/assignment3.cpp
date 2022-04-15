//============================================================================
// Name        : polynomial.cpp
// Author      : Sneha Bandi 
// Roll No.    : 2401
// Description : Polynomial operations: Accept,Display,Addition,Multiplication
//			evaluation
//============================================================================

#include<iostream>
#include<math.h>		//for 'pow' function
using namespace std;
class poly;
class term
{
public:
   int deg;
   int coeff;

};
class poly
{
	   int n;				//no. of terms in the polynomial
	 term t[30];			//object array of term class whose each index stores coefficient and power corresponding to each term
 public:
     friend istream& operator >> (istream& in,poly& p);	//operator overloading
     friend ostream& operator << (ostream& out,poly& p);
     void eval();
     void display();
     friend poly add(poly,poly);
     friend poly multiply(poly,poly);


};

istream& operator >> (istream& in,poly& p)				//Object of iostream is 'in' and obj of poly class 'p' is passed
{
  cout<<"________________________________________________________\n";
  cout<<"Enter number of terms in the polynomial : ";
  in>>p.n;
      for(int i=0;i<p.n;i++)
	{
	  cout<<"Enter the exponential power of 'x':";
	  in>>p.t[i].deg;
	  cout<<"Enter the coefficient of x^"<<p.t[i].deg<<" is:";
	  in>>p.t[i].coeff;
	}

      return in;							//Neccesary or else warning of return type
}
ostream& operator << (ostream& out,poly& p)
{
	for(int i=0;i<p.n;i++)
	{
	  out<<p.t[i].coeff;
	  cout<<"(x^";
	  out<<p.t[i].deg;
	  cout<<")";
	  if(i!=p.n-1)
	  cout<<"+";

	}
	cout<<endl;
      return out;
  cout<<"\n________________________________________________________\n";
}

poly add(poly p1,poly p2)
{
	poly p3;
	int i=0,j=0,k=0;
	  while(i<p1.n && j<p2.n)
	  {
	   if(p1.t[i].deg==p2.t[j].deg)
            {
			p3.t[k].coeff = p1.t[i].coeff + p2.t[j].coeff;
			p3.t[k].deg = p1.t[i].deg;
			i++;
			j++;
			k++;	
            }
	   else if(p1.t[i].deg>p2.t[j].deg)
	    {
		   p3.t[k].coeff = p1.t[i].coeff;
		   p3.t[k].deg = p1.t[i].deg;
			i++;
			k++;
	    }
	   else 
	    {
		   p3.t[k].coeff = p2.t[i].coeff;
		   p3.t[k].deg = p2.t[i].deg;
			i++;
			k++;
	    }
	  }
	while(i<p1.n)
	    {
		   p3.t[k].coeff = p1.t[i].coeff;
		   p3.t[k].deg = p1.t[i].deg;
			i++;
			k++;
	    }
	while(j<p2.n)
	    {
		   p3.t[k].coeff = p2.t[j].coeff;
		   p3.t[k].deg = p2.t[j].deg;
			j++;
			k++;
	    }


	  cout<<"\nThe sum of polynomials is:\n";
			p3.n=k;
	    return p3;
}
poly multiply(poly p1,poly p2)
{

	poly p3,a;
	int i=0,j,k;
	int c=0,d=0,flag;
	a.n=0;
       while(i<p1.n)
	{j=0;
	 while(j<p2.n)
	  {
		c = p1.t[i].coeff * p2.t[j].coeff;
		d = p1.t[i].deg + p2.t[j].deg;
		k=0;
		flag=0;
		while(k<a.n && flag==0)
		{
			if(p3.t[k].deg==d)
			{
			flag=1;
			break;
			}
			k++;
		}
		if(flag==1)
		{
		p3.t[k].coeff=p3.t[k].coeff+c;
		p3.t[k].deg=d;
		}
		else
		{
		p3.t[a.n].coeff=c;
		p3.t[a.n].deg=d;
		a.n++;
		}
		j++;
	  }
		i++;
	}
	cout<<"\nThe multiplication of poynomial is:\n";
		p3.n=(k+1);
 return p3;
}

void poly::eval()
{
	int val=0;
	int x;
	cout<<endl<<"Enter value of x"<<endl;
	cin>>x;
	for(int i=0;i<n;i++)
	{
	 val= val + t[i].coeff*(pow(x,t[i].deg));
	}
	cout<<"On evaluation of polynomial at x="<<x<<"the value ="<<val<<endl;
}

int main()
{
	poly p1,p2,sum,multi;
	char choice;
	int c;
	cout<<"Enter the first polynomial\n";
	cin>>p1;
	cout<<"Entered polynomial is:"<<endl;
	cout<<p1;
	cout<<"Enter the second polynomial"<<endl;
	cin>>p2;
	cout<<"Entered polynomial is:"<<endl;
	cout<<p2;
		cout<<"\n===========================================================================";
	do{
		cout<<"\n***MENU***\n";
		cout<<"Enter you choice\n";
		cout<<"Press:\n";
		cout<<"\t1. for evaluation of polynomial\n";
		cout<<"\t2. for addition of two polynomials\n";
		cout<<"\t3. for multiplication of two polynomials\n";
		cin>>c;
	switch(c)
	 {
	  case 1:		
		p1.eval();
		break;
	  case 2:		
		sum = add(p1,p2);
		cout<<sum;
		break;
	  case 3:		
		multi = multiply(p1,p2);
		cout<<multi;
		break;	
	  default:
		cout<<"\nENTER VALID CHOICE\n";
		break;
	 }
	  cout<<"\nDo you want to continue (y/n)?\n";
	  cin>>choice;
		cout<<"\n===========================================================================";
	}while(choice=='y' || choice=='Y');

	return 0;
}
//PROGRAM ENDS

//------------------------------------------------ OUTPUT ------------------------------------------------

/*
Enter the first polynomial
________________________________________________________
Enter number of terms in the polynomial : 3
Enter the exponential power of 'x':3
Enter the coefficient of x^3 is:2
Enter the exponential power of 'x':2
Enter the coefficient of x^2 is:1
Enter the exponential power of 'x':1
Enter the coefficient of x^1 is:4
Entered polynomial is:
2(x^3)+1(x^2)+4(x^1)
Enter the second polynomial
________________________________________________________
Enter number of terms in the polynomial : 2
Enter the exponential power of 'x':1
Enter the coefficient of x^1 is:1
Enter the exponential power of 'x':0
Enter the coefficient of x^0 is:2
Entered polynomial is:
1(x^1)+2(x^0)

===========================================================================
***MENU***
Enter you choice
Press:
	1. for evaluation of polynomial
	2. for addition of two polynomials
	3. for multiplication of two polynomials
1

Enter value of x
1
On evaluation of polynomial at x=1the value =7

Do you want to continue (y/n)?
y

===========================================================================
***MENU***
Enter you choice
Press:
	1. for evaluation of polynomial
	2. for addition of two polynomials
	3. for multiplication of two polynomials
2

The sum of polynomials is:
2(x^3)+1(x^2)+5(x^1)+2(x^0)

Do you want to continue (y/n)?
y

===========================================================================
***MENU***
Enter you choice
Press:
	1. for evaluation of polynomial
	2. for addition of two polynomials
	3. for multiplication of two polynomials
3

The multiplication of poynomial is:
2(x^4)+5(x^3)+6(x^2)+8(x^1)

Do you want to continue (y/n)?
n

===========================================================================

*/






