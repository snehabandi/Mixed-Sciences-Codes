//============================================================================
// Name        : mini_project.cpp
// Author      : Sneha bandi
// Roll No.    : 2401,2406,2408,2410,2413
// Description : The following number system conversions are done by our program:
		//1. Binary to gray";
		//2. Gray to binary
		//3. Binary to decimal to BCD
		//4. BCD to decimal to binary
		//5. Binary to decimal
		//6. Decimal to binary
		//7. Binary Adder
		//8. BCD Adder
		//9. Help:If you need information about any number system
//============================================================================
#include <iostream>
#include<string.h>
#include<math.h>
using namespace std;

class node {
	friend class list;
	int data;
	node*prev;
	node* next;
public:
	node()
	{
		//data=0;
		prev = NULL;
		next = NULL;
	}
	;
	node(int d)
	{
		data=d;
		prev = NULL;
		next = NULL;
	}
};

class list {
	node* start;
public:
	void accept();
	void display();
	int  count();
	void binary_gray();
	void gray_binary();
	void binary_bcd();
	void bcd_binary();
	void decimal_binary(int dec);
	int binary_decimal();
	list binary_adder(list,list);
	list binary_six();
	list bcd_adder(list,list);
	list()
	{start=NULL;}

};

void list::accept()		//ACCEPTING NO. IN BINARY FORMAT (BIT BY BIT)
{
	node *temp,*ptr;
	int s,d;
	char c;

    cout<<"\n\t\tNOTE: ENTER BIT BY BIT........!!";
	do
	{
    		cout<<"\nEnter bit: ";
		cin>>d;
		temp = new node(d);
		if(start==NULL)
			start=temp;
	    else
	    {
		 ptr=start;
		 while(ptr->next!=NULL)
		  {
			ptr=ptr->next;
	     	  }

		  ptr->next = temp;
		  temp->prev=ptr;
	    }
	cout<<"Do you want to enter another bit (y/n)?\t:";
		cin>>c;
	}while(c=='y'||c=='Y');
}
void list::display()			//DISPLAYING ENTERED BINARY NO.
{
	node *ptr;
		ptr=start;
		while(ptr!=NULL)
		{
			cout<<ptr->data;
			ptr=ptr->next;

		}

}

void list::binary_gray()		//BINARY TO GRAY
{
  node *ptr,*trav,*temp;
  list t;
  trav=t.start;
  ptr=start;
int i=0;
  while(ptr!=NULL)
  {
    temp= new node();
    if(t.start==NULL)
    {
      t.start=temp;
      t.start->data=start->data;
    }
    else
    {
    	trav=t.start;
    	while(trav->next!=NULL)
    	{
    	  trav=trav->next;
    	}
    	temp->data=(ptr->prev->data)^(ptr->data);
    	trav->next=temp;
    	temp->prev=trav;
    }
     ptr=ptr->next;
   }
//DISPLAY
    trav=t.start;
	while(trav!=NULL)
	{
  	  cout<<trav->data;
	  trav=trav->next;
	}
    cout<<"\n";

}
void list::gray_binary()		//GRAY TO BINARY
{
  node *ptr,*trav,*temp;
  list t;
  trav=t.start;
  ptr=start;
int i=0;
  while(ptr!=NULL)
  {
    temp= new node();
    if(t.start==NULL)
    {
      t.start=temp;
      t.start->data=start->data;
    }
    else
    {
    	trav=t.start;
    	while(trav->next!=NULL)
    	{
    	  trav=trav->next;
    	}
    	temp->data=(trav->data)^(ptr->data);
    	trav->next=temp;
    	temp->prev=trav;
    }
     ptr=ptr->next;
   }
    //DISPLAY
    trav=t.start;
	while(trav!=NULL)
	{
	  cout<<trav->data;
	  trav=trav->next;

	}
    cout<<"\n";

}

void list::binary_bcd()			//BINARY TO BCD
{
  node *ptr,*trav,*temp;
  list t;
  int digit,num;
  //BCD no. is from 0-9
  num=binary_decimal();
   if(num<10)
   {
    display();
    cout<"\n";
   }
   else
   {
     while(num!=0)
     {

      //start separating digits from L.S.B bit
      digit=num%10;
      num=num/10;
      //now convert each digit to binary
      t.decimal_binary(digit);
      }
      	cout<<"\n\tThe BCD no. is: ";
            t.display();
    }
}

void list::bcd_binary()				//BCD TO BINARY
{
  node *ptr,*temp,*trav;
  int sum;
  list t;
 //traversal till end of list
  ptr=start;
  while(ptr->next!=NULL)
  {
    ptr=ptr->next;
  }
  //till list one ends
  while(ptr!=NULL)
  {
    sum=0;
    //taking 4 bits at a time from L.S.B;converting to decimal
    for(int i=0;i<4;i++)
      {
    	sum=sum+(pow(2,i))*(ptr->data);
    	ptr=ptr->prev;
      }
      //creating list to store each digit;forward traversal
      temp = new node(sum);
      	if(t.start==NULL)
      	    t.start=temp;
      	else
      	{
      	  t.start->prev=temp;
      	  temp->next=t.start;
      	  t.start=t.start->prev;
      	}
   }
       //display
    cout<<"\nThe decimal no. is: ";
    trav=t.start;
	while(trav!=NULL)
	{
	  cout<<trav->data;
	  trav=trav->next;

	}
    cout<<"\n";


}

int list::binary_decimal()			//BINARY TO DECIMAL
{
    node *temp,*ptr;
    int sum=0,c;
    c=count();
    ptr=start;
      for(int i=(c-1);i>=0;i--)
      {
    	sum=sum+(pow(2,i))*(ptr->data);
    	ptr=ptr->next;
      }
	return sum;
}
void list::decimal_binary(int dec)		//ACCEPTING NO. IN DECIMAL FORM
{
    node *temp;
    int n;
    while(dec!=0)
    {
    	n = dec % 2;
    	dec=dec/2;
		temp = new node(n);
		if(start==NULL)
			start=temp;
	    else			//LIST FORMATION IS IN REVERSE ORDER
	    {
		 temp->next=start;
		 start->prev=temp;
		 start=start->prev;

	    }

    }

}

list list::binary_adder(list d1,list d2)			//ADDITION OF TWO BINARY NO.'s
{
    list d;
	node *ptr1,*ptr2,*sum,*temp,*temp1;
	int s=0,carry=0;

//TRAVERSING BOTH THE LIST TILL END
	ptr1=d1.start;
	ptr2=d2.start;
	while(ptr1->next!=NULL)
	{
		ptr1=ptr1->next;
	}
	while(ptr2->next!=NULL)
	{
		ptr2=ptr2->next;
	}
//WHILE LOOP TILL BOTH THE LIST END
   while(ptr1!=NULL||ptr2!=NULL)
   {
//ADDITION STARTING FROM LSB
//SUM BY EXOR
	s=(ptr1->data)^(ptr2->data)^(carry);
//CARRY
	if((ptr1->data==1 && ptr2->data==1)||(ptr1->data==1 && carry==1)||(ptr2->data==1 && carry==1))
		carry=1;
	else
	     carry=0;

//MAKING 3rd LIST 'sum' TO STORE ADDITION OF LISTS d1 AND d2
		temp=new node(s);
	if(d.start==NULL)
		d.start=temp;
	else
	{
	  sum=d.start;
		while(sum->prev!=NULL)
		{
		  sum=sum->prev;
		}
	  temp->next=sum;
	  sum->prev=temp;
	  d.start=temp;
	}
//APPENDING CARRY BIT EXPLICITLY
    if(ptr1->prev==NULL||ptr2->prev==NULL)
     {
	if(carry==1)
	{
		temp1=new node(1);
		temp1->next=d.start;
		temp->prev=temp1;
		d.start=temp1;
	}
     }

//INCREMENTING POINTERS OF BOTH THE LIST
	ptr1=ptr1->prev;
	ptr2=ptr2->prev;

   }
return d;
}

list list::bcd_adder(list d1,list d2)			//BCD ADDER:ADDITION OF TWO BCD NUMBERS
{
  node* temp;
  list t,s,i;
  int dec;
  //BINARY SIX CREATION
  s=binary_six();
  //ADDITION OF ACCEPTED NO (INVALID OR VALID YET TO BE DETERMINED;NORMAL ADDITION)
  t=binary_adder(d1,d2);
  dec=t.binary_decimal();
    //CASE I OF OF INVALID BCD: CARRY BIT GENERATION
  if(t.count()==5)
  {
    cout<<"\n\tInvalid BCD addition!! ";
    t.display();
    cout<<"\nREASON : As carry bit generated at M.S.B it is no longer 4-bit BCD No.!\n\n";
    cout<<"------------------------------->ON VALIDATING BCD ADDITION!\n\n\tValid BCD Addition is : ";
    temp = new node(0);		//to make 0110 as 5 bit i.e. 00110
    temp->next=s.start;		//we need to make it 5 bit as now the invalid BCD is 5-bit
    s.start->prev=temp;
    s.start=temp;
    i=binary_adder(t,s);
    i.display();
  }
    //CASE II OF INVALID BCD: ADDITION > 9
  else if(dec>9 && dec<16)
  {
    cout<<"\n\tInvalid BCD addition!! ";
        t.display();
    cout<<"\nREASON : As addition is greater than 9 and 4-bit BCD no's range fron 0-9 !\n\n";
    cout<<"------------------------------->ON VALIDATING BCD ADDITION!\n\n\tValid BCD Addition is : ";
    i=binary_adder(t,s);
    i.display();
  }
  else
  {
   cout<<"\n\tThe BCD addition is:";
   t.display();
  }
  cout<<"\n\tThe binary six is : ";
  s.display();
  cout<<"\n";
}

list list::binary_six()				//CREATION FOR BINARY SIX TO ADD IN INVALID BCD NO.
{
	node *ptr1,*temp,*temp1;
	int x;
	list d;
	for(int i=0;i<4;i++)
	{
	//SETTING X AS '1' FOR 2ND N 3RD NODE AS 6 IS 0110
	  if(i==1||i==2)
	    x=1;
	  else
	    x=0;
	//CREATION OF NEW NODE WITH DATA AS X
	  temp = new node(x);
	  if(d.start==NULL)
		{
		  d.start=temp;
		}
	  else
	   {
		ptr1=d.start;
	    while(ptr1->next!=NULL)
	     {
		ptr1=ptr1->next;
	     }
	    ptr1->next=temp;
	    temp->prev=ptr1;
	   }
	}
return d;
}

int list::count()		//COUNT FUNCTION FOR COUNTING NODES
{
	node *ptr;
	int count=0;
	ptr=start;
	while(ptr!=NULL)
	{
		ptr=ptr->next;
		count++;

	}

	return count;
}
//main function
int main()
{
	int n,n1,x;
	char choice,choice1;
	list l1,l2,l3,l4,l5,l6,l7,l8,l9,lba,l10,l11,l12,l13;
	cout<<"\n=========================================================\n";
	do{

		cout<<"\n******************** MENU ********************\n\n\tPRESS:";
		cout<<"\n\t1. Binary to gray";
		cout<<"\n\t2. Gray to binary";
		cout<<"\n\t3. Binary to decimal to BCD";
		cout<<"\n\t4. BCD to decimal to binary ";
		cout<<"\n\t5. Binary to decimal";
		cout<<"\n\t6. Decimal to binary";
		cout<<"\n\t7. Binary Adder";
		cout<<"\n\t8. BCD Adder";
		cout<<"\n\t9. Help\n\t\tNOTE : If you need information about any number system select 'HELP'";
		cout<<"\n\n\tCHOICE: ";
		cin>>n;
	switch(n)
	{
	case 1:
		 l1.accept();
		 cout<<"\n******************** BINARY CONVERTED TO GRAY ********************\n";
		 cout<<"\n\tBinary No: ";
		 l1.display();
		 cout<<"\n\tGray No: ";
		 l1.binary_gray();

		break;
	case 2:
		 l2.accept();
		 cout<<"\n******************** GRAY CONVERTED TO BINARY ********************\n";
		 cout<<"\n\tGray No: ";
		 l2.display();
		 cout<<"\n\tBinary No: ";
		 l2.gray_binary();
		break;
	case 3:
		 l3.accept();
		 cout<<"\n******************** BINARY CONVERTED TO BCD ********************\n";
		 cout<<"\n\tBinary No: ";
		 l3.display();
		 cout<<"\n\tBCD No: ";
		 l3.binary_bcd();

		break;
	case 4:
		 l4.accept();
		 cout<<"\n******************** BCD CONVERTED TO BINARY ********************\n";
		 cout<<"\n\tBCD No: ";
		 l4.display();
		 cout<<"\n\tBinary No: ";
		 l4.bcd_binary();
		break;
	case 5:
		 l6.accept();
 		 cout<<"\n******************** BINARY CONVERTED TO DECIMAL ********************\n";
		 cout<<"\n\tBinary No: ";
		 l6.display();
		 x=l6.binary_decimal();
		   cout<<"\n\tDecimal No: "<<x;
		break;
	case 6:
		 cout<<"\nEnter the decimal number: ";
		 cin>>x;
		 l5.decimal_binary(x);
		 cout<<"\n******************** DECIMAL CONVERTED TO BINARY ********************\n";
		 cout<<"\n\tDecimal No: ";
		 cout<<x;
		 cout<<"\n\tBinary No: ";
		 l5.display();
		break;
	case 7:
		cout<<"\nEnter the first Binary no. :\n";
		 l7.accept();
		cout<<"\nEnter the first Binary no. :\n";
		 l8.accept();
		cout<<"\n\tFirst No. : ";
		 l7.display();
		cout<<"\n\tSecond No. : ";
		 l8.display();
		 cout<<"\n******************** BCD ADDITION ********************\n";
		cout<<"\nThe Binary addition is : ";
		 lba=l9.binary_adder(l7,l8);
		 lba.display();
		break;
	case 8:
		cout<<"\nEnter the first BCD no. :\n";
		 l10.accept();
		cout<<"\nEnter the first BCD no. :\n";
		 l11.accept();
		cout<<"\n\tFirst No. : ";
		 l10.display();
		cout<<"\n\tSecond No. : ";
		 l11.display();
		 cout<<"\n******************** BCD ADDITION ********************\n";
		 l12.bcd_adder(l10,l11);
		break;
	//****************** HELP! *********************
	case 9:

		cout<<"\n\t<-------------------------------------------------------------------->\n";
		do{
		cout<<"\n\t<-------------------- INFORMATION MENU -------------------->\n\n\tPRESS:";
		cout<<"\n\t\t1. Binary to gray";
		cout<<"\n\t\t2. Gray to binary";
		cout<<"\n\t\t3. Binary to BCD";
		cout<<"\n\t\t4. BCD to binary ";
		cout<<"\n\t\t5. Binary to decimal";
		cout<<"\n\t\t6. Decimal to binary";
                              cout<<"\n\t\t7. BCD Adder";

		cout<<"\n\nCHOICE:";
		cin>>n1;
		switch(n1)
		{
		case 1:
			/*Convertion of Binary to Gray number.*/
			cout<<"Convertion of Binary to Gray code.\n";
			cout<<"\n The MSB of the binary number is kept as it is and every next digit";
			cout<<" and its successive digit of the binary number perform EX-OR operation ";
			cout<<"to convert d binary number to the equivalent Gray code\n";
			cout<<"e.g.\n";
			cout<<"\n  = 01001 ==> 01101\n";
			break;
		case 2:
			/* Convertion of Gray to binary number.*/
			cout<<"Conversion of Gray to binary number.";
			cout<<"\n The MSB of the Gray number is kept as it is and this digit of the binary number performs";
			cout<<"EX-OR operation with the next digit of the gray code to give the next binary number ";
			cout<<"and this process continues till the last Gray digit.\n";
			cout<<"e.g.\n";
			cout<<"\n 01101 ==> 01001\n ";
			break;
		case 3:
			/*Convertion of Binary to BCD number.*/
			cout<<"Convertion of Binary to BCD number.\n";
			cout<<"\n BCD involves turning each decimal digit in a number into its";
			cout<<"binary equivalent and concatenating the results.\n";
			cout<<"e.g.\n";
			cout<<"\n94 = 1001 0100 = = > 10010100 \n ";
			break;
		case 4:
			/* Convertion of BCD to binary number.*/
			cout<<"Convertion of BCD to binary number.\n";
			cout<<"\n Each decimal digit requires 4 bits to represent in binary.";
			cout<<"\n The process for conversion from a BCD number back to decimal .";
			cout<<"\n Starting from the right hand side, take successive groups of ";
			cout<<"4 bits and convert them from binary to decimal.\n";
			cout<<"e.g.\n";
			cout<<"\n010110010001 ==> 0101 1001 0001 ==> 591\n";
			break;
		case 5: cout<<"Binary to Decimal"<<endl;
            /*Basic information about binary and decimal numbers */
             cout<<"\n Binary numbers are the one with base-2.\n This system uses only two digits i.e. 0 and 1.\n\n Whereas the decimal numbers have base 10.\n This system uses the numbers from 0 to 9."<<endl;

			break;
case 6:	 cout<<"Conversion from binary to decimal"<<endl;
cout<<"\n e.g.\n (10011)2=(19)10 \n "<<endl;
cout<<"Conversion from decimal to binary"<<endl;
cout<<"\n e.g.\n 0000=0 \n 0001=1 \n 0010=2 \n ..."<<endl;
break;
		case 7: cout<<" BCD ADDER"<<endl;
                cout<<"1)BCD adder adds two BCD digits but its addition cannot be greater than 9."<<endl;
              cout<<"2)If sum is less than or equal to 9 and carry =0,then the sum is in the true BCD form."<<endl;
            cout<<"3)If sum is invalid BCD or carry=1,then the result is wrong ,so six i.e 0110    is added to it to make it valid."<<endl;
         	break;
	 	default:
			cout<<"\nEnter valid choice!\n";
			break;
		}
		cout<<"\n\t<-------------------------------------------------------------------->\n";
		cout<<"\n\tDo you want any other information (y/n)? ";
		cout<<"\n\t<-------------------------------------------------------------------->\n";
		}while(choice1=='y'||choice1=='Y');

		break;
	  default:
		cout<<"\nEnter valid choice!\n";
		break;
	}
	cout<<"\n=========================================================\n";
	cout<<"\nDo yo want to continue (y/n)?\t";
	cin>>choice;
	cout<<"==========================================================\n";
	}while(choice=='y'||choice=='Y');

	return 0;


}
