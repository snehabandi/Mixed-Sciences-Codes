package Vehicle;
//car class is subclass of vehicle class
public class car extends Vehicle
{
 int no_gears;
 String make;
 car()									//use super
 {
	 super();
  no_gears=0;
 // make.copyValueOf(null);
 }
 car(int r,int w,float c,int g,String d)					//use super
 {
	 super(r,w,c);
  no_gears=0;
  make = d;
 }
 public void start()				//override start function
 {
	 System.out.println("\nstart() of car class invoked\n");
 }
 public void stop()					//override stop function
 {
	 System.out.println("\nstop() of car class invoked\n");

 }
 public void start(int a)				//overload start function of car
 {
	 System.out.println("\nstart(int) of car class invoked\n");

 }
 public void stop(int a)				//overload stop function of car
 {
	 System.out.println("\nstop(int) of car class invoked\n");

 }
 public void reverse()				//member function of car
 {
	 System.out.println("\nreverse() of car class invoked\n");

 }
}
