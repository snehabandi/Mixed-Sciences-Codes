//============================================================================
// Name        : converter.cpp
// Author      : Sneha Bandi
// Roll no.    : 2401
// Description : converter
//============================================================================

#include <iostream>
using namespace std;
class convert
{
protected:
		double val1,val2;
public:
	convert(double i)
	{
		val1 = i;
	}
	double getconv()
	{
		return val2;
	}
	double getinit()
	{
		return val1;
	}
virtual void compute()=0;			//runtime polymorphism(rtp), retuns 0 by default ;pure virtual function

};
//litres to gallon
class l_g:public convert
{
public:
	l_g(double i):convert(i){}		//{} is constructor body here and this is a parameterised constructor

	void compute()
	{
	  val2 = val1/3.7854;
	}
};
//fahrenheit to celcius
class f_c:public convert
{
public:
	f_c(double i):convert(i){}

	void compute()
	{
	  val2 = (val1-32)/1.8;
	}
};
//km/hr to m/s
class k_m:public convert
{
public:
	k_m(double i):convert(i){}		//{} is constructor body here and this is a parameterised constructor

	void compute()
	{
	  val2 = (val1*5)/18;
	}
};
int main()
{
  convert *p;		//ptr to base class
  int r,q,n;
  cout<<"\n\t\t\tThis program can perform following conversions:\n\n";

  cout<<"\n1. Conversion of litre to gallon\n";
  //litres to gallon
  cout<<"\nEnter the value in litres to convert to gallon : ";
  cin>>r;
  l_g obj_lg(r);
  //using virtual function mechanism to convert

  p = &obj_lg;
  cout<<p->getinit()<<" litres = ";	//litres accepted
  p->compute();
  cout<<p->getconv()<<" gallons\n";	//l to g convert
  cout<<"\n______________________________________________________\n";

  //Fahrenheit to celcius	
  cout<<"\n\n2. Conversion of fahrenheit to celcius\n";
  cout<<"\nEnter the value in fahrenheit to convert to celcius : ";
  cin>>q;
  f_c obj_fc(q);
  p = &obj_fc;
  cout<<p->getinit()<<" fahrenheit = ";	//fahrenheit accepted
  p->compute();
  cout<<p->getconv()<<" celcius\n";	//f to c convert
  cout<<"\n______________________________________________________\n";

  //km/hr to m/s
  cout<<"\n\n3. Conversion of km/hr to m/s \n";
  cout<<"\nEnter the value in km/hr to convert to m/s : ";
  cin>>q;
  k_m obj_km(q);
  p = &obj_km;
  cout<<p->getinit()<<" km/hr = ";	//km/hr accepted
  p->compute();
  cout<<p->getconv()<<" m/s\n";	//km/hr to m/s convert
  cout<<"\n______________________________________________________\n";
	
  return 0;
}
//PROGRAM ENDS
//<-------------------------------------- OUTPUT ----------------------------------------->
/*
		This program can perform following conversions:

1. Conversion of litre to gallon

Enter the value in litres to convert to gallon : 4
4 litres = 1.05669 gallons

______________________________________________________


2. Conversion of fahrenheit to celcius

Enter the value in fahrenheit to convert to celcius : 70
70 fahrenheit = 21.1111 celcius

______________________________________________________


3. Conversion of km/hr to m/s 

Enter the value in km/hr to convert to m/s : 72
72 km/hr = 20 m/s

______________________________________________________

*/
