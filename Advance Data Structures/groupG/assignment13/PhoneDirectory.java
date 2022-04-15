package stl;

public class PhoneDirectory 
{
	public int id;
	public int no;
	
	PhoneDirectory(int i,int n)
	{
		id=i;
		no=n;
	}
	
	public String toString()
	{
		return id+" : "+no;
		
	}
}
