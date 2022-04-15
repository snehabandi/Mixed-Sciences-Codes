//============================================================================
// Name        : reservation.cpp
// Author      : Group 1 (Roll no.1-6)
// Batch       : B1
// Roll No.    : 1,3,4,5,6
// Description : (ARRAY OF OBJECTS USED FOR READING AND WRITING FILE ONLY)
//                 Accept-Display done!
//                 Read-Write is done!
//                 Search (name/seat no.) is done!
//                 Modify by name is done!
//                 Delete record by setting flag is done!
//                 Passenger sort(Detailed and short) is done!
//                 Try-catch done(age,gender,src-destination,fare,
//			       seat already booked is not available )
//                 fare speciality
//****************************************************************************
#include <iostream>
#include<fstream>
#include<string.h>
#define MAX 3
using namespace std;

class reserve
{
        int dflag;                                                  //For deletion of record;means 1 if deleted
        int age;                                                    //dest=destination,ddate=departure date,adate=arrival date
        char gender;                                                //tagc=travel agency,dtime=departure time
        char name[30],src[10],dest[10];
        int ddate[10];
        char dtime[10];
        char bus_class[15];
        long ph_no,aadhar_no,ticket_no;
        int seat_no;
        static int s[20];
        static int cnt;
        int fare;
        int ex,chx;
public:
        reserve();                                                  //default constructor
        void accept();
        void display();
        void write();
        void read();
        void search_name();
        void search_num();
        void modify();
        void deletion();
        void read_sort();
        void read_sort_detailed();
        static int count();
};
//default constructor
reserve::reserve()
{
    dflag=0;
    strcpy(name,"Default");
    strcpy(src,"Default");
    strcpy(dtime,"Default");
    age=0;
    gender='g';
    ph_no=0;
    aadhar_no=0;
    fare=1000;
}
int reserve::s[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int reserve::cnt=0;
int reserve::count()
{
        cnt=cnt+1;
        return(cnt);
}

//ACCEPT
void reserve::accept()
{
        cout<<"\nEnter name of the ticket holder (end with '.'): ";
        cin.ignore();
        cin.getline(name,30,'.');
        cout<<"\nEnter age : ";
        cin>>age;
        cout<<"\nEnter gender (M/F) : ";
        cin>>gender;
        try{                                                                // Exception Handling 1
    		if(gender!='M' && gender!='m' && gender!='F'&& gender!='f')
	    	       throw chx;
        }
        catch(int chx)
        {
        
    		cout<<"\n\tEnter valid inputs !!\n";
        	cout<<"\nEnter gender (M/F) : ";
       		cin>>gender;        
        }

        cout<<"\nEnter phone number : ";
        cin>>ph_no;
        cout<<"\nEnter Aadhar card  number : ";
        cin>>aadhar_no;
        cout<<"\nEnter starting place of journey : ";
        cin>>src;
        cout<<"\nEnter destination : ";
        cin>>dest;
    	try{                                                                    // Exception Handling 2
    		if(strcmp(src,dest)==0)
    		       throw chx;

        }
        catch(int chx)
        {
        
    		cout<<"\n\tSource and destinaton cannot be same !!\n";
  	   	cout<<"\nEnter destination : ";
       		cin>>dest;        
        }
        cout<<"\nEnter departure date (dd/mm/yyyy): ";
        for(int i=0;i<3;i++)
          cin>>ddate[i];

//SEAT DISPLAY START
        cout<<"\nFollowing is the seat display (0 means booked): \n\n";
        for(int i=0;i<20;i++)
        {
                cout<<"\t"<<s[i];
                if(i==9)
                cout<<"\n\n\n";
        }
//SEAT DISPLAY
        cout<<"\n\nEnter the seat no : ";
        cin>>seat_no;
         if(seat_no>20 || seat_no<0)
         {
          cout<<"\n\t\tEnter valid seat no. !!!";
	  cout<<"\n\nEnter the seat no : ";
          cin>>seat_no;
          cout<<"\n";
         }
        for(int i=0;i<20;i++)
        {
         if(s[i]==0 && seat_no==(i+1))
         {
          cout<<"\n\t\tSeat is already booked !!!";
	  cout<<"\n\nEnter the seat no : ";
          cin>>seat_no;
          cout<<"\n";
         }
        }
//Modification in array
        s[seat_no-1]=0;
        
        cout<<"\nEnter time of departure : ";
        cout<<"\n\n\tFollowing are the available departure timings- ";
        cout<<"\n\t6:00 am\n\t8:00 am\n\t1:00 pm\n\t4:00pm\n\t7:00 pm\n\t10:30 pm\n\ntime : ";
        cin.ignore();
        cin.getline(dtime,10);
        cout<<"\nEnter the bus class :\n NON-AC\t AC\t VOLVO\nClass : ";
        cin.getline(bus_class,15);

}
//DISPLAY
void reserve::display()
{
        if(dflag==0){
        cout<<"\n\n\t\t<--------------------------------------------------->\n";
        cout<<"\n\tTicket No            : #"<<name[0]<<src[0]<<seat_no;
        cout<<"\n\tName                 : "<<name;
        cout<<"\n\tAge                  : "<<age;
        cout<<"\n\tGender               : "<<gender;
        cout<<"\n\tSource               : "<<src;
        cout<<"\n\tDestination          : "<<dest;
        cout<<"\n\tDate of departure    : ";
        for(int i=0;i<3;i++)
        {
           cout<<ddate[i];
          if(i!=2)
            cout<<"/";
        }
        cout<<"\n\tTime of departure    : "<<dtime;
        cout<<"\n\tPhone number         : "<<ph_no;
        cout<<"\n\tAadhar number        : "<<aadhar_no;
        cout<<"\n\tBus class            : "<<bus_class;
        cout<<"\n\tSeat No              : "<<seat_no;
        try                                                                               // Exception Handling 3
                {
                        if(age>5 && age<65)
			{
			    cout<<"\n\tFare                 : Rs. "<<fare;
			}
			else
                                throw ex;

                }
                catch (int ex)
                {
                        if(age<6)
                        {
                        fare=fare/2;
			cout<<"\n\tFare                 : Rs. "<<fare;                        
                        cout<<"\n\t(Half ticket applicable)";
                        }
                        else if(age>64)
                        {
                        fare =0.6* fare;
			cout<<"\n\tFare                 : Rs. "<<fare;                                                
                        cout<<"\n\t(Senior citizen applicable)";
                	}
        }
        cout<<endl;
        }
}
void reserve::write()
{
 reserve p;
 fstream f;
 ifstream in;
 ofstream out;
 char ans1;
        do{                                                                                   //DO-WHILE FOR ASKING FOR ENTRY OF MULTIPLE RECORDS
        p.accept();                                                                           //ACCEPT FUNCTION CALLED
        char ch;
        cin.get(ch);
        out.open("text.dat",ios::out|ios::app|ios::binary);                                   //APP AND BINARY MODE
        out.write((char*)&p,sizeof(p));
        cnt++;
        out.close();
        cout<<"\n\tDo you want to book another ticket (y/n)?  ";
        cin>>ans1;
        cout<<"\n\t<------------------------------------------->\n";
        }while(ans1=='y'||ans1=='Y');

}
void reserve::read()
{
 reserve p;
 int i=0;
 fstream f;
 ifstream in;
 ofstream out;
        in.open("text.dat",ios::in|ios::binary);                                                //OPENING OF FILE
        cout<<"\n\tRecord"<<cnt<<"\n\n";
        while(in.read((char*)&p,sizeof(p)))                                                     //LOOP TILL FILE ENDS
        {
                 p.display();
        }
        in.close();
        cout<<"\n\t\t<--------------------------------------------------->\n";

}

//sorting and only passenger list printed
void reserve::read_sort()
{
 int pos=0,i=0,flag;
  fstream f;
  ifstream in;
  reserve q;
        cout<<"\n\t\tTHE SEAT WISE SORTED LIST ARE:\n";
        cout<<"\n\t\tName :\t\t\t\t\tSeat No. :"<<endl;
        for(int j=0;j<20;j++)
        {
        flag=0;
        f.open("text.dat",ios::in|ios::out|ios::ate|ios::binary);
        f.seekg(0,ios::beg);
        pos=0;
        i=0;
        while(f.read((char*)&q,sizeof(q)))
        {
                  if(j==q.seat_no){
                pos=i;
                flag=1;
                break;
                }

          i++;
        }
        if(flag==1){
                f.seekp(pos*sizeof(q));                                                          //POINTER SET TO DETECTED LOCATION
                in.read((char*)&q,sizeof(q));                                                    //READING FROM DETECTED LOCATION
                if(dflag==0)
                cout<<"\n\t\t"<<q.name<<"\t\t\t\t\t"<<q.seat_no<<endl;
        }
        f.close();
        }
        cout<<"\n\t\t<--------------------------------------------------->\n";

}
//sorting and detailed passenger list printed
void reserve::read_sort_detailed()
{
 int pos=0,i=0,flag;
  fstream f;
  ifstream in;
  reserve q;
        cout<<"\n\t\t<--------------------------------------------------->\n";
        cout<<"\n\t\tTHE SEAT WISE SORTED LIST ARE:"<<endl;
        for(int j=0;j<20;j++)
        {
        flag=0;
        f.open("text.dat",ios::in|ios::out|ios::ate|ios::binary);
        f.seekg(0,ios::beg);
        pos=0;
        i=0;
        while(f.read((char*)&q,sizeof(q)))
        {
                  if(j==q.seat_no){
                pos=i;
                flag=1;
                break;
                }

          i++;
        }
        if(flag==1){
                f.seekp(pos*sizeof(q));                                                          //POINTER SET TO DETECTED LOCATION
                in.read((char*)&q,sizeof(q));                                                    //READING FROM DETECTED LOCATION
                cout<<"\n\t================> RECORD "<<" <==================\n";
                q.display();                                                                     //DISPLAY FUNCTION IS CALLED
                cout<<"\n\t===================================================\n";

        }
        f.close();
        }
        cout<<"\n\t\t<--------------------------------------------------->\n";
}

void reserve::search_name()	//searching the passenger details by name
{
 int pos=0,i=0,flag=0;
  fstream f;
  ifstream in;
  reserve q;
  char name[30];
        cout<<"\nEnter the name to be searched: ";
        cin>>name;
        f.open("text.dat",ios::in|ios::out|ios::ate|ios::binary);
        f.seekg(0,ios::beg);
        pos=-1;
        i=0;
        while(f.read((char*)&q,sizeof(q)))
        {
          if(strcmp(name,q.name)==0)                        //MATCHING NAMES
         {
                pos=i;
                flag=1;
                break;
          }
          i++;
        }
        if(flag==1){
                cout<<"\nDETAILS FOUND!";
                f.seekp(pos*sizeof(q));                                //POINTER SET TO DETECTED LOCATION
                in.read((char*)&q,sizeof(q));                        //READING FROM DETECTED LOCATION
                q.display();
        }
        else
                cout<<"\nDETAILS NOT FOUND!";

        f.close();
}
void reserve::search_num()//searching passenger details by seat number
{
int seat_no;
reserve p;
 int pos=0,i=0,flag=0;
  fstream f;
  ifstream in;
  reserve q;

        cout<<"\nEnter the Seat No. to be searched : ";
        cin>>seat_no;
        f.open("text.dat",ios::in|ios::out|ios::ate|ios::binary);
        f.seekg(0,ios::beg);
        pos=-1;
        i=0;
        while(f.read((char*)&p,sizeof(p)))
        {
          if(seat_no==p.seat_no)                        //MATCHING PHONE NUMBERS
          {
           pos=i;
           flag=1;
           break;
          }
         i++;
        }
        if(flag==1)
        {
          cout<<"\nDETAILS FOUND !!\n";
          //offset=pos*sizeof(p);
          f.seekp((pos)*sizeof(p));                        //POINTER SET TO DETECTED LOCATION
          in.read((char*)&p,sizeof(p));                        //READING FROM DETECTED LOCATION
          cout<<"\tThe passenger details are:\n";
          p.display();
        }
        else
          cout<<"\nDETAILS NOT FOUND !!\n";
          f.close();

}
void reserve::modify()	//Modifying passenger’s details 
{
 int pos=0,i=0,flag=0;
  fstream f;
  ifstream in;
  reserve q;
  char name[30];
        cout<<"\nEnter the name to be searched: ";
        cin>>name;
        f.open("text.dat",ios::in|ios::out|ios::ate|ios::binary);
        f.seekg(0,ios::beg);
        pos=-1;
        i=0;
        while(f.read((char*)&q,sizeof(q)))
        {
          if(strcmp(name,q.name)==0)                        //MATCHING NAMES
         {
                pos=i;
                flag=1;
                break;
          }
          i++;
        }
        if(flag==1){
                cout<<"\nDETAILS FOUND!";
                f.seekp(pos*sizeof(q));                                //PUT POINTER SET TO DETECTED LOCATION
                in.read((char*)&q,sizeof(q));                        //READING FROM DETECTED LOCATION
                q.display();
                cout<<"\nEnter the new passenger details : \n";
                q.accept();
                q.fare=1000;
                f.seekg(pos*sizeof(q));                                //GET POINTER SET TO DETECTED LOCATION
                f.write((char*)&q,sizeof(q));                                //WRITING NEW RECORD INTO THE FILE
                cout<<"\nRecord updated";
        }
        else
                cout<<"\nDETAILS NOT FOUND!";

        f.close();


}
//Deletion
void reserve::deletion()
{
 int pos=0,i=0,flag=0;
  fstream f;
  ifstream in;
  reserve q;
  char name[30];
  int seat_no;
        cout<<"\nEnter the name whose ticket is to be cancelled: ";
        cin>>name;
        cout<<"Enter seat no. : ";
        cin>>seat_no;
        f.open("text.dat",ios::in|ios::out|ios::ate|ios::binary);
        f.seekg(0,ios::beg);
        pos=-1;
        i=0;
        while(f.read((char*)&q,sizeof(q)))
        {
          if(strcmp(name,q.name)==0 && seat_no==q.seat_no)                        //MATCHING NAMES
         {
                pos=i;
                flag=1;
                break;
          }
          i++;
        }
        if(flag==1){
                cout<<"\nDETAILS FOUND!";
                f.seekp(pos*sizeof(q));                                          //POINTER SET TO DETECTED LOCATION
                cout<<"\nFollowing ticket is cancelled:\n";
                in.read((char*)&q,sizeof(q));                                    //READING FROM DETECTED LOCATION
                q.display();
                q.dflag=1;
                s[q.seat_no-1]=q.seat_no;
                f.write((char*)&q,sizeof(q));                                    //writing i.e changing the dflag in file also
        }
        else
                cout<<"\nDETAILS NOT FOUND!";

        f.close();
}


int main()
{
  reserve r;
  char ans;
  int choice,choice1;
    cout<<"\n|---------------------------------------------------|\n|            WELCOME TO RESERVATION DESK            |\n|---------------------------------------------------|\n";
        do{
                cout<<"\n*********************** MENU ***********************\n";
                cout<<"Press:";
                cout<<"\n\t1.Book tickets .";
                cout<<"\n\t2.Show ticket details .";
                cout<<"\n\t3.Search by name/Seat no.";
                cout<<"\n\t4.Update ticket details .";
                cout<<"\n\t5.Cancellation of ticket .";                              //Deletion of record
                cout<<"\n\t6.Display sorted data (by seat No.)";
                
                cout<<"\nCHOICE : ";
                cin>>choice;
                //SWITCH CASE I STARTS
                switch(choice)
                {
                 case 1:
                         r.write();
                        cout<<"\n\n\tTICKET HAS BEEN BOOKED SUCCESSFULLY\n\tHAVE A SAFE JOURNEY !!!";
                         break;
                 case 2:
                         r.read();
                         break;
                 case 3:
                        //SWITCH CASE II STARTS
                        cout<<"\n\tPRESS :\n\t\t1.To search by Name";
                        cout<<"\n\t\t2.To search by seat No.\nCHOICE : ";
                        cin>>choice1;
                        switch(choice1)
                        {
                        case 1:
                                r.search_name();
                                break;
                        case 2:
                                r.search_num();
                                break;
                        }
                        //SWITCH CASE II ENDS
                         break;
                 case 4:
                         r.modify();
                         break;
                 case 5:
	                 r.deletion();
	                  break;
                 
                 case 6:
                        //SWITCH CASE II STARTS
                        cout<<"\n\tPRESS :\n\t\t1.To display short passenger list";
                        cout<<"\n\t\t2.To display detailed list\nCHOICE : ";
                        cin>>choice1;
                        switch(choice1)
                        {
                        case 1:
                                 r.read_sort();
                                break;
                        case 2:
                                 r.read_sort_detailed();
                                break;
                        }
                        //SWITCH CASE II ENDS

                         break;
                 default:
                         cout<<"\nENTER VALID CHOICE!\n";
                         break;
                 }
                 //SWITCH CASE ENDS
          cout<<"\nDo you want to continue (y/n)?\t ";
          cin>>ans;
          cout<<"__________________________________________________\n";
        }while(ans=='Y'||ans=='y');
        //D0-WHILE LOOP ENDS

cout<<"\n";
        return 0;
}
//PROGRAM ENDS
//-------------------------------OUTPUT-----------------------------------------
/*
|---------------------------------------------------|
|            WELCOME TO RESERVATION DESK            |
|---------------------------------------------------|

*********************** MENU ***********************
Press:
	1.Book tickets .
	2.Show ticket details .
	3.Search by name/Seat no.
	4.Update ticket details .
	5.Cancellation of ticket .
	6.Display sorted data (by seat No.)
CHOICE : 1

Enter name of the ticket holder (end with '.'): Sneha.

Enter age : 69

Enter gender (M/F) : a

	Enter valid inputs !!

Enter gender (M/F) : F

Enter phone number : 8989064848

Enter Aadhar card  number : 24568756

Enter starting place of journey : Pune

Enter destination : Pune

	Source and destinaton cannot be same !!

Enter destination : Mumbai

Enter departure date (dd/mm/yyyy): 10	10	2016

Following is the seat display (0 means booked): 

	1	2	3	4	5	6	7	8	9	10


	11	12	13	14	15	16	17	18	19	20

Enter the seat no : 15

Enter time of departure : 

	Following are the available departure timings- 
	6:00 am
	8:00 am
	1:00 pm
	4:00pm
	7:00 pm
	10:30 pm

time : 10.30 pm

Enter the bus class :
 NON-AC	 AC	 VOLVO
Class : AC


	Do you want to book another ticket (y/n)?  y

	<------------------------------------------->

Enter name of the ticket holder (end with '.'): Nivedita.

Enter age : 4

Enter gender (M/F) : F

Enter phone number : 9425064878

Enter Aadhar card  number : 5487646

Enter starting place of journey : Banglore

Enter destination : Chennai

Enter departure date (dd/mm/yyyy): 05	11	2016

Following is the seat display (0 means booked): 

	1	2	3	4	5	6	7	8	9	10


	11	12	13	14	0	16	17	18	19	20

Enter the seat no : 15

		Seat is already booked !!!

Enter the seat no : 5


Enter time of departure : 

	Following are the available departure timings- 
	6:00 am
	8:00 am
	1:00 pm
	4:00pm
	7:00 pm
	10:30 pm

time : 7.00 pm

Enter the bus class :
 NON-AC	 AC	 VOLVO
Class : VOLVO


	Do you want to book another ticket (y/n)?  y

	<------------------------------------------->

Enter name of the ticket holder (end with '.'): Sameera.

Enter age : 19

Enter gender (M/F) : F

Enter phone number : 8979787876

Enter Aadhar card  number : 65646546

Enter starting place of journey : Pune

Enter destination : Surat

Enter departure date (dd/mm/yyyy): 05	10	2016

Following is the seat display (0 means booked): 

	1	2	3	4	0	6	7	8	9	10


	11	12	13	14	0	16	17	18	19	20

Enter the seat no : 9

Enter time of departure : 

	Following are the available departure timings- 
	6:00 am
	8:00 am
	1:00 pm
	4:00pm
	7:00 pm
	10:30 pm

time : 4.00 pm

Enter the bus class :
 NON-AC	 AC	 VOLVO
Class : NON-AC


	Do you want to book another ticket (y/n)?  n

	<------------------------------------------->


	TICKET HAS BEEN BOOKED SUCCESSFULLY
	HAVE A SAFE JOURNEY !!!
Do you want to continue (y/n)?	 y
__________________________________________________

*********************** MENU ***********************
Press:
	1.Book tickets .
	2.Show ticket details .
	3.Search by name/Seat no.
	4.Update ticket details .
	5.Cancellation of ticket .
	6.Display sorted data (by seat No.)
CHOICE : 2

	Record3



		<--------------------------------------------------->

	Ticket No            : #SP15
	Name                 : Sneha
	Age                  : 69
	Gender               : F
	Source               : Pune
	Destination          : Mumbai
	Date of departure    : 10/10/2016
	Time of departure    : 10.30 pm
	Phone number         : 8989064848
	Aadhar number        : 24568756
	Bus class            : AC
	Seat No              : 15
	Fare                 : Rs. 600
	(Senior citizen applicable)


		<--------------------------------------------------->

	Ticket No            : #NB5
	Name                 : Nivedita
	Age                  : 4
	Gender               : F
	Source               : Banglore
	Destination          : Chennai
	Date of departure    : 5/11/2016
	Time of departure    : 7.00 pm
	Phone number         : 9425064878
	Aadhar number        : 5487646
	Bus class            : VOLVO
	Seat No              : 5
	Fare                 : Rs. 500
	(Half ticket applicable)


		<--------------------------------------------------->

	Ticket No            : #SP9
	Name                 : Sameera
	Age                  : 19
	Gender               : F
	Source               : Pune
	Destination          : Surat
	Date of departure    : 5/10/2016
	Time of departure    : 4.00 pm
	Phone number         : 8979787876
	Aadhar number        : 65646546
	Bus class            : NON-AC
	Seat No              : 9
	Fare                 : Rs. 1000

		<--------------------------------------------------->

Do you want to continue (y/n)?	 y
__________________________________________________

*********************** MENU ***********************
Press:
	1.Book tickets .
	2.Show ticket details .
	3.Search by name/Seat no.
	4.Update ticket details .
	5.Cancellation of ticket .
	6.Display sorted data (by seat No.)
CHOICE : 3

	PRESS :
		1.To search by Name
		2.To search by seat No.
CHOICE : 1

Enter the name to be searched: Mansee

--------------------------DETAILS NOT FOUND!-----------------------------

Do you want to continue (y/n)?	 y
__________________________________________________

*********************** MENU ***********************
Press:
	1.Book tickets .
	2.Show ticket details .
	3.Search by name/Seat no.
	4.Update ticket details .
	5.Cancellation of ticket .
	6.Display sorted data (by seat No.)
CHOICE : 3

	PRESS :
		1.To search by Name
		2.To search by seat No.
CHOICE : 1

Enter the name to be searched: Sameera

DETAILS FOUND!

		<--------------------------------------------------->

			Ticket No            : #SP9
			Name                 : Sameera
			Age                  : 19
			Gender               : F
			Source               : Pune
			Destination          : Surat
			Date of departure    : 5/10/2016
			Time of departure    : 4.00 pm
			Phone number         : 8979787876
			Aadhar number        : 65646546
			Bus class            : NON-AC
			Seat No              : 9
			Fare                 : Rs. 1000
		<--------------------------------------------------->

Do you want to continue (y/n)?	 y
__________________________________________________

*********************** MENU ***********************
Press:
	1.Book tickets .
	2.Show ticket details .
	3.Search by name/Seat no.
	4.Update ticket details .
	5.Cancellation of ticket .
	6.Display sorted data (by seat No.)
CHOICE : 3

	PRESS :
		1.To search by Name
		2.To search by seat No.
CHOICE : 2

Enter the Seat No. to be searched : 5

DETAILS FOUND !!

	The passenger details are:


		<--------------------------------------------------->

	Ticket No            : #NB5
	Name                 : Nivedita
	Age                  : 4
	Gender               : F
	Source               : Banglore
	Destination          : Chennai
	Date of departure    : 5/11/2016
	Time of departure    : 7.00 pm
	Phone number         : 9425064878
	Aadhar number        : 5487646
	Bus class            : VOLVO
	Seat No              : 5
	Fare                 : Rs. 500
	(Half ticket applicable)

		<--------------------------------------------------->

Do you want to continue (y/n)?	 y
__________________________________________________

*********************** MENU ***********************
Press:
	1.Book tickets .
	2.Show ticket details .
	3.Search by name/Seat no.
	4.Update ticket details .
	5.Cancellation of ticket .
	6.Display sorted data (by seat No.)
CHOICE : 4

Enter the name to be searched: Sameera

DETAILS FOUND!

		<--------------------------------------------------->

	Ticket No            : #SP9
	Name                 : Sameera
	Age                  : 19
	Gender               : F
	Source               : Pune
	Destination          : Surat
	Date of departure    : 5/10/2016
	Time of departure    : 4.00 pm
	Phone number         : 8979787876
	Aadhar number        : 65646546
	Bus class            : NON-AC
	Seat No              : 9
	Fare                 : Rs. 1000

Enter the new passenger details : 

Enter name of the ticket holder (end with '.'): Nistha.

Enter age : 24

Enter gender (M/F) : F

Enter phone number : 9425608468 

Enter Aadhar card  number : 5486464

Enter starting place of journey : Jaipur

Enter destination : Pune

Enter departure date (dd/mm/yyyy): 14	11	2016

Following is the seat display (0 means booked): 

	1	2	3	4	0	6	7	8	0	10


	11	12	13	14	0	16	17	18	19	20

Enter the seat no : 2

Enter time of departure : 

	Following are the available departure timings- 
	6:00 am
	8:00 am
	1:00 pm
	4:00pm
	7:00 pm
	10:30 pm

time : 4.00 pm

Enter the bus class :
 NON-AC	 AC	 VOLVO
Class : AC

Record updated
Do you want to continue (y/n)?	 y
__________________________________________________

*********************** MENU ***********************
Press:
	1.Book tickets .
	2.Show ticket details .
	3.Search by name/Seat no.
	4.Update ticket details .
	5.Cancellation of ticket .
	6.Display sorted data (by seat No.)
CHOICE : 2

	Record3



		<--------------------------------------------------->

	Ticket No            : #SP15
	Name                 : Sneha
	Age                  : 69
	Gender               : F
	Source               : Pune
	Destination          : Mumbai
	Date of departure    : 10/10/2016
	Time of departure    : 10.30 pm
	Phone number         : 8989064848
	Aadhar number        : 24568756
	Bus class            : AC
	Seat No              : 15
	Fare                 : Rs. 600
	(Senior citizen applicable)


		<--------------------------------------------------->

	Ticket No            : #NB5
	Name                 : Nivedita
	Age                  : 4
	Gender               : F
	Source               : Banglore
	Destination          : Chennai
	Date of departure    : 5/11/2016
	Time of departure    : 7.00 pm
	Phone number         : 9425064878
	Aadhar number        : 5487646
	Bus class            : VOLVO
	Seat No              : 5
	Fare                 : Rs. 500
	(Half ticket applicable)


		<--------------------------------------------------->

	Ticket No            : #NJ2
	Name                 : Nistha
	Age                  : 24
	Gender               : F
	Source               : Jaipur
	Destination          : Pune
	Date of departure    : 14/11/2016
	Time of departure    : 4.00 pm
	Phone number         : 9425608468
	Aadhar number        : 5486464
	Bus class            : AC
	Seat No              : 2
	Fare                 : Rs. 1000

		<--------------------------------------------------->

Do you want to continue (y/n)?	 y
__________________________________________________

*********************** MENU ***********************
Press:
	1.Book tickets .
	2.Show ticket details .
	3.Search by name/Seat no.
	4.Update ticket details .
	5.Cancellation of ticket .
	6.Display sorted data (by seat No.)
CHOICE : 6

	PRESS :
		1.To display short passenger list
		2.To display detailed list
CHOICE : 1

		THE SEAT WISE SORTED LIST ARE:

		Name :					Seat No. :

		Nistha					2

		Nivedita				5

		Sneha					15

		<--------------------------------------------------->

Do you want to continue (y/n)?	 y
__________________________________________________

*********************** MENU ***********************
Press:
	1.Book tickets .
	2.Show ticket details .
	3.Search by name/Seat no.
	4.Update ticket details .
	5.Cancellation of ticket .
	6.Display sorted data (by seat No.)
CHOICE : 6

	PRESS :
		1.To display short passenger list
		2.To display detailed list
CHOICE : 2

		<--------------------------------------------------->

		THE SEAT WISE SORTED LIST ARE:

	================> RECORD  <==================

	Ticket No            : #NJ2
	Name                 : Nistha
	Age                  : 24
	Gender               : F
	Source               : Jaipur
	Destination          : Pune
	Date of departure    : 14/11/2016
	Time of departure    : 4.00 pm
	Phone number         : 9425608468
	Aadhar number        : 5486464
	Bus class            : AC
	Seat No              : 2
	Fare                 : Rs. 1000

	================> RECORD  <==================

	Ticket No            : #NB5
	Name                 : Nivedita

	Age                  : 4
	Gender               : F
	Source               : Banglore
	Destination          : Chennai
	Date of departure    : 5/11/2016
	Time of departure    : 7.00 pm
	Phone number         : 9425064878
	Aadhar number        : 5487646
	Bus class            : VOLVO
	Seat No              : 5
	Fare                 : Rs. 500
	(Half ticket applicable)

	================> RECORD  <==================

	Ticket No            : #SP15
	Name                 : Sneha
	Age                  : 69
	Gender               : F
	Source               : Pune
	Destination          : Mumbai
	Date of departure    : 10/10/2016
	Time of departure    : 10.30 pm
	Phone number         : 8989064848
	Aadhar number        : 24568756
	Bus class            : AC
	Seat No              : 15
	Fare                 : Rs. 600
	(Senior citizen applicable)

	===================================================

Do you want to continue (y/n)?	 y
__________________________________________________

*********************** MENU ***********************
Press:
	1.Book tickets .
	2.Show ticket details .
	3.Search by name/Seat no.
	4.Update ticket details .
	5.Cancellation of ticket .
	6.Display sorted data (by seat No.)
CHOICE : 5

Enter the name whose ticket is to be cancelled: Sneha
Enter seat no. : 6

DETAILS NOT FOUND!

Do you want to continue (y/n)?	 Y
__________________________________________________

*********************** MENU ***********************
Press:
	1.Book tickets .
	2.Show ticket details .
	3.Search by name/Seat no.
	4.Update ticket details .
	5.Cancellation of ticket .
	6.Display sorted data (by seat No.)
CHOICE : 5

Enter the name whose ticket is to be cancelled: Sneha
Enter seat no. : 15

DETAILS FOUND!
Following ticket is cancelled:


		<--------------------------------------------------->

	Ticket No            : #SP15
	Name                 : Sneha
	Age                  : 69
	Gender               : F
	Source               : Pune
	Destination          : Mumbai
	Date of departure    : 10/10/2016
	Time of departure    : 10.30 pm
	Phone number         : 8989064848
	Aadhar number        : 24568756
	Bus class            : AC
	Seat No              : 15
	Fare                 : Rs. 600
	(Senior citizen applicable)

		<--------------------------------------------------->

Do you want to continue (y/n)?	 y
__________________________________________________

*********************** MENU ***********************
Press:
	1.Book tickets .
	2.Show ticket details .
	3.Search by name/Seat no.
	4.Update ticket details .
	5.Cancellation of ticket .
	6.Display sorted data (by seat No.)
CHOICE : 2

		<--------------------------------------------------->

	Ticket No            : #NB5
	Name                 : Nivedita

	Age                  : 4
	Gender               : F
	Source               : Banglore
	Destination          : Chennai
	Date of departure    : 5/11/2016
	Time of departure    : 7.00 pm
	Phone number         : 9425064878
	Aadhar number        : 5487646
	Bus class            : VOLVO
	Seat No              : 5
	Fare                 : Rs. 500
	(Half ticket applicable)


		<--------------------------------------------------->

	Ticket No            : #NJ2
	Name                 : Nistha
	Age                  : 24
	Gender               : F
	Source               : Jaipur
	Destination          : Pune
	Date of departure    : 14/11/2016
	Time of departure    : 4.00 pm
	Phone number         : 9425608468
	Aadhar number        : 5486464
	Bus class            : AC
	Seat No              : 2
	Fare                 : Rs. 1000

		<--------------------------------------------------->

Do you want to continue (y/n)?	 y
__________________________________________________

*********************** MENU ***********************
Press:
	1.Book tickets .
	2.Show ticket details .
	3.Search by name/Seat no.
	4.Update ticket details .
	5.Cancellation of ticket .
	6.Display sorted data (by seat No.)
CHOICE : 1

Enter name of the ticket holder (end with '.'): Mansee
.

Enter age : 35

Enter gender (M/F) : F

Enter phone number : 9886533535

Enter Aadhar card  number : 5468768 

Enter starting place of journey : Kolkata

Enter destination : Delhi

Enter departure date (dd/mm/yyyy): 15	11	2016

Following is the seat display (0 means booked): 

	1	0	3	4	0	6	7	8	0	10


	11	12	13	14	15	16	17	18	19	20

Enter the seat no : 15

Enter time of departure : 

	Following are the available departure timings- 
	6:00 am
	8:00 am
	1:00 pm
	4:00pm
	7:00 pm
	10:30 pm

time : 10.30 pm

Enter the bus class :
 NON-AC	 AC	 VOLVO
Class : VOLVO


	Do you want to book another ticket (y/n)?  n

	<------------------------------------------->


	TICKET HAS BEEN BOOKED SUCCESSFULLY
	HAVE A SAFE JOURNEY !!!
Do you want to continue (y/n)?	 y
__________________________________________________

*********************** MENU ***********************
Press:
	1.Book tickets .
	2.Show ticket details .
	3.Search by name/Seat no.
	4.Update ticket details .
	5.Cancellation of ticket .
	6.Display sorted data (by seat No.)
CHOICE : 2 
		<--------------------------------------------------->

	Ticket No            : #NB5
	Name                 : Nivedita
	Age                  : 4
	Gender               : F
	Source               : Banglore
	Destination          : Chennai
	Date of departure    : 5/11/2016
	Time of departure    : 7.00 pm
	Phone number         : 9425064878
	Aadhar number        : 5487646
	Bus class            : VOLVO
	Seat No              : 5
	Fare                 : Rs. 500
	(Half ticket applicable)


		<--------------------------------------------------->

	Ticket No            : #NJ2
	Name                 : Nistha
	Age                  : 24
	Gender               : F
	Source               : Jaipur
	Destination          : Pune
	Date of departure    : 14/11/2016
	Time of departure    : 4.00 pm
	Phone number         : 9425608468
	Aadhar number        : 5486464
	Bus class            : AC
	Seat No              : 2
	Fare                 : Rs. 1000

		<--------------------------------------------------->
	Ticket No            : #MK15
	Name                 : Mansee
	Age                  : 35
	Gender               : F
	Source               : Kolkata
	Destination          : Delhi
	Date of departure    : 15/11/2016
	Time of departure    : 10.30 pm
	Phone number         : 9886533535
	Aadhar number        : 5468768
	Bus class            : VOLVO
	Seat No              : 15
	Fare                 : Rs. 1000

		<--------------------------------------------------->


Do you want to continue (y/n)?	 y
__________________________________________________

Do you want to continue (y/n)?	 y
__________________________________________________
*/




