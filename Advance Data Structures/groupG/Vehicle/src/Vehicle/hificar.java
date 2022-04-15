package Vehicle;
//hificar class is subclass of car and implements fly and possys

public class hificar extends car implements fly
{
	int price;
 hificar()				//default constructor
 {
	 super();
	 price=100000;
 }
 hificar(int p)				//default constructor
 {
	 super();
	 price=p;
 }
 public void start()				//Override function of abstract class
 {
	 System.out.println("\nstart() of hificar class is invoked !\n");
 }
 public void stop()				//Override function of abstract class
 {
	 System.out.println("\nstop() of hificar class is invoked !\n");
 }
 public void showrdahead()			//Override function of possys
 {
	 System.out.println("\nshowrdahead() of hificar class is invoked !\n");
 }
 public void searchloc(String place)		//Override function of possys
 {
	 System.out.println("\nsearchloc() of hificar class is invoked !\n");
 }
 public void flycar()					//Override function of fly interface
 {
	 System.out.println("\nflycar() of hificar class is invoked !\n");
 }
 public void flyfast()				//Override function of fly interface
 {
	 System.out.println("\nflyfast() of hificar class is invoked !\n");
 }
 public void flyslow()				//Override function of fly interface
 {
	 System.out.println("\nflyfast() of hificar class is invoked !\n");
 }
 public void ferrari()			//member function of hificar
 {
	 System.out.println("\nFerrari() of hificar class is invoked !\n");
 }
@Override
public void fast(int speed) {
	// TODO Auto-generated method stub
	
}
@Override
public void flyslow(int speed) {
	// TODO Auto-generated method stub
	
}
 }
