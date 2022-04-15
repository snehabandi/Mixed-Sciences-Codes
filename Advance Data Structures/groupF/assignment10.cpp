//============================================================================
// Name        : assignment3.cpp
// Author      : Sneha Bandi
// Roll No.    : 2401
// Description : Sequential files and its operations on student data
//============================================================================

#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>
using namespace std;
#define max 30
class data
{
	char name[max];
	char address[max];
	int roll;;
	char division;
	friend class student;
};
class student
{
public:
	data obj;
	void create();
	void add();
	void remov();
	void search();
	void view();
	void display();

};
void student::create()
{
	cout<<"\n\t\t    Name : ";
	cin>>obj.name;
	cout<<"\n\t\t  Address : ";
	cin>>obj.address;
	cout<<"\n\t\tDivision : ";
	cin>>obj.division;
	cout<<"\n\t\tRoll No. : ";
	cin>>obj.roll;
}
void student::view()
{
	cout<<"\n\n\t\t    Name : "<<obj.name;
	cout<<"\n\n\t\t Address : "<<obj.address;
	cout<<"\n\n\t\tDivision : "<<obj.division;
	cout<<"\n\n\t\tRoll No. : "<<obj.roll;

}
void student::add()
{
	fstream f;
	ifstream in;
	ofstream out;
	create();
	char ch;
	cin.get(ch);
	out.open("student_Data.dat",ios::out|ios::binary|ios::app);
	out.write((char *)&obj, sizeof(obj));
	out.close();
}
void student::remov(){
	fstream f;
	ifstream in;
	ofstream out;
	char n[max];
	cout<<"\n\n\t\t\tEnter Student Name to delete record ! !";
	cout<<"\n\n\t\t\tStudent Name : ";
		cin>>n;
		f.open("student_Data.dat",ios::in|ios::binary);
		while(f.read((char *)&obj, sizeof(obj))){
			if(strcmp(n,obj.name)!=0){
				out.open("temp.dat",ios::out|ios::binary|ios::app);
				out.write((char *)&obj, sizeof(obj));
				out.close();
			}
		}
		f.close();
		remove("student_Data.dat");
		rename("temp.dat", "student_Data.dat");
		cout<<"\n\n\t\t\t Record Deleted ! !";
}

void student::search(){
	    char n[max];
	    int flag = 0;
		fstream f;
		ifstream in;
		ofstream out;
		cout<<"\n\t\tEnter name to search in record : ";
		cin>>n;
		f.open("student_Data.dat",ios::ate|ios::in|ios::out|ios::binary);
		f.seekg(0, ios::beg);
		while(f.read((char *)&obj,sizeof(obj))){
			if(strcmp(n,obj.name)==0){
				cout<<"\n\t\tRecord Found!!";
										view();
										flag = 1;
									}
		}
		f.close();
		if(flag == 0){
			cout<<"\n\t\tRecord not found!!";
		}

}
void student::display(){
	fstream f;
	ifstream in;
	ofstream out;
	f.open("student_Data.dat",ios::ate|ios::in|ios::out|ios::binary);
	f.seekg(0, ios::beg);
	cout<<"\n\t\t"<<setfill('=')<<setw(53)<<"=";
	cout<<"\n\t\t"<<setfill(' ')<<setw(1)<<"|"<<setw(51)<<left<<"RECORD"<<setw(1)<<"|";
	cout<<"\n\t\t"<<setfill('=')<<setw(53)<<"=";
	while(f.read((char *)&obj,sizeof(obj))){
	cout<<"\n\t\t"<<setfill(' ')<<setw(1)<< "|"<<setw(10)<<left<<"Name"<<setw(1)<< " : "<<setw(15)<<left<<obj.name<< setw(1)<< "|"<<setw(12)<<left<<"Roll No."<<setw(1)<<" : "<<setw(7)<<left<<obj.roll<<setw(1)<< "|";
	cout<<"\n\t\t"<<setfill('-')<<setw(53)<<"-";
	cout<<"\n\t\t"<<setfill(' ')<<setw(1)<< "|"<<setw(10)<<left<<"Address"<<setw(1)<< " : "<<setw(15)<<left<<obj.address<< setw(1)<< "|"<<setw(12)<<left<<"Division"<<setw(1)<<" : "<<setw(7)<<left<<obj.division<<setw(1)<< "|";
	cout<<"\n\t\t"<<setfill('=')<<setw(53)<<"=";
	}
	f.close();

}

int main() {
	student o;
	int choice;
	do{
		cout<<"\n\n\t\t\t==============";
		cout<<"\n\t\t\tMAIN MENU";
		cout<<"\n\t\t\t==============";
		cout<<"\n\n\t\t\t PRESS";
		cout<<"\n\t\t\t1. ADD RECORD";
		cout<<"\n\t\t\t2. REMOVE RECORD";
		cout<<"\n\t\t\t3. DISPLAY";
		cout<<"\n\t\t\t4. SEARCH";
		cout<<"\n\t\t\t5. EXIT"<<endl;
		cout<<"\t\t\t";
		cin>>choice;
		switch(choice){
		case 1:
			  o.add();
			break;
		case 2:
			o.remov();
			break;

		case 3:
			o.display();
			break;
		case 4:
			o.search();
			break;
		case 5:
			cout<<"\n\t\tThanks for using!!!";
			break;
		default :
			cout<<"\n\n\t\t\tInvalid selection !";
			break;
		}
		}while(choice!=5);
	return 0;
}
//---------------------------->> OUTPUT <<----------------------------------
/*


			==============
			MAIN MENU
			==============

			 PRESS
			1. ADD RECORD
			2. REMOVE RECORD
			3. DISPLAY
			4. SEARCH
			5. EXIT
			1

		    Name : Sneha

		  Address : Baya_karve

		Division : B

		Roll No. : 2401


			==============
			MAIN MENU
			==============

			 PRESS
			1. ADD RECORD
			2. REMOVE RECORD
			3. DISPLAY
			4. SEARCH
			5. EXIT
			1

		    Name : Saloni

		  Address : Saheli_homes

		Division : B

		Roll No. : 2444


			==============
			MAIN MENU
			==============

			 PRESS
			1. ADD RECORD
			2. REMOVE RECORD
			3. DISPLAY
			4. SEARCH
			5. EXIT
			3

		=====================================================
		|RECORD                                             |
		=====================================================
		|Name       : Sneha          |Roll No.     : 2401   |
		-----------------------------------------------------
		|Address    : Baya_karve     |Division     : B      |
		=====================================================
		|Name       : Saloni         |Roll No.     : 2444   |
		-----------------------------------------------------
		|Address    : Saheli_homes   |Division     : B      |
		=====================================================

			==============
			MAIN MENU
			==============

			 PRESS
			1. ADD RECORD
			2. REMOVE RECORD
			3. DISPLAY
			4. SEARCH
			5. EXIT
			4

		Enter name to search in record : Saloni

		Record Found!!

		    Name : Saloni

		 Address : Saheli_homes

		Division : B

		Roll No. : 2444

			==============
			MAIN MENU
			==============

			 PRESS
			1. ADD RECORD
			2. REMOVE RECORD
			3. DISPLAY
			4. SEARCH
			5. EXIT
			2


			Enter Student Name to delete record ! !

			Student Name : Saloni


			 Record Deleted ! !

			==============
			MAIN MENU
			==============

			 PRESS
			1. ADD RECORD
			2. REMOVE RECORD
			3. DISPLAY
			4. SEARCH
			5. EXIT
			3

		=====================================================
		|RECORD                                             |
		=====================================================
		|Name       : Sneha          |Roll No.     : 2401   |
		-----------------------------------------------------
		|Address    : Baya_karve     |Division     : B      |
		=====================================================

			==============
			MAIN MENU
			==============

			 PRESS
			1. ADD RECORD
			2. REMOVE RECORD
			3. DISPLAY
			4. SEARCH
			5. EXIT
			5

		Thanks for using!!!
*/

