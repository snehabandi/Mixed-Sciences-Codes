package Vehicle;

abstract class Vehicle 
{
 int reg_no;
 int no_wheels;
 double cost;
 Vehicle()
 {
	 reg_no=0;
	 no_wheels=0;
	 cost =0.0f; 
 }
 Vehicle(int r,int w,float c)
 {
	 reg_no=r;
	 no_wheels=w;
	 cost =c; 
 }
 abstract void start();				//abstract function
 abstract void stop();				//abstract function
 void start(int a)			//overloaded start function
 {
	 System.out.println("\nstart(int) of Vehicle class is invoked and a="+a+"\n");
 }
 void stop(int a)			//overloaded stop function
 {
	 System.out.println("\nstop(int) of Vehicle class is invoked and a="+a+"\n");

 }

}
