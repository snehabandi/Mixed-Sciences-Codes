
//NAME : RUCHA NARKHEDE
//ROLL NO.: 2423


package stl;
import java.util.*;
public class STL {

	
	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
	//======================================================================
		System.out.println(" Link list operations ");
		
		LinkedList<PhoneDirectory>
		tlist = new LinkedList<PhoneDirectory>(); 
		tlist.add(new PhoneDirectory(23,455));
		tlist.add(new PhoneDirectory(34,2345));
		tlist.add(new PhoneDirectory(54,245));
		tlist.add(new PhoneDirectory(74,9045));
		System.out.println("List "+ tlist);
	  tlist.remove(1);
	   System.out.println("List "+ tlist);

	   //=====================================================================
	   System.out.println("\n stack operations ");
	   
	   Stack<PhoneDirectory>
	   st =new Stack<PhoneDirectory>();
	   st.push(new PhoneDirectory(23,455));
		st.push(new PhoneDirectory(34,2345));
		st.push(new PhoneDirectory(54,245));
		st.push(new PhoneDirectory(74,9045));
		System.out.println("Stack" + st);
	   st.pop();
	   System.out.println("Stack "+ st);
	   
	   //====================================================================
	   
 System.out.println("\n Hash set operations ");
	   
	   HashSet<PhoneDirectory>
	   hs =new HashSet<PhoneDirectory>();
	   hs.add(new PhoneDirectory(23,455));
		hs.add(new PhoneDirectory(34,2345));
		hs.add(new PhoneDirectory(58,245));
		hs.add(new PhoneDirectory(75,9045));
		System.out.println("Hash set" + hs);
	  
		//===================================================================
		
		 System.out.println("\n Dictionary operations ");
		 Dictionary dict = new Hashtable();
		    
		    //you add elements to dictionary using put method
		 
		   //put(key, value)
		   
		 dict.put(1, "Java");
		    
		dict.put(2, ".NET");
		   
		 dict.put(3, "Javascript");
		   
		 dict.put(4, "HTML");
		    
		System.out.println( "Items in the dictionary..." + dict );

	
		//=====================================================
			TreeSet<String> tset = new TreeSet<String>();
			System.out.println("\n tree set is ");
	         // Adding elements to TreeSet<String>
	         tset.add("ABC");
	         tset.add("String");
	         tset.add("Test");
	         tset.add("Pen");
	         tset.add("Ink");
	         tset.add("Jack");

	         //Displaying TreeSet
	         System.out.println(tset);
	         
	     //=====================================================
	         System.out.println("\n Dictionary operations ");
			 Dictionary d = new Hashtable();
			    
			    //you add elements to dictionary using put method
			 
			   //put(key, value)
			 PhoneDirectory p=new PhoneDirectory(2,33333);
			 d.put(p.id,p.no);
			 PhoneDirectory p2=new PhoneDirectory(1,33423);
			d.put(p2.id,p2.no);
			PhoneDirectory p3=new PhoneDirectory(3,32223);
			d.put(p3.id,p3.no);
			
			   
			// d.put(3, "Javascript");
			   
			// d.put(4, "HTML");
			    
			System.out.println( "Items in the dictionary..." + d );
	   
	}

}


/************OUTPUT***************
 *   
Link list operations 
List [23 : 455, 34 : 2345, 54 : 245, 74 : 9045]
List [23 : 455, 54 : 245, 74 : 9045]

 stack operations 
Stack[23 : 455, 34 : 2345, 54 : 245, 74 : 9045]
Stack [23 : 455, 34 : 2345, 54 : 245]

 Hash set operations 
Hash set[23 : 455, 58 : 245, 75 : 9045, 34 : 2345]

 Dictionary operations 
Items in the dictionary...{4=HTML, 3=Javascript, 2=.NET, 1=Java}

 tree set is 
[ABC, Ink, Jack, Pen, String, Test]

 Dictionary operations 
Items in the dictionary...{3=32223, 2=33333, 1=33423}*/
