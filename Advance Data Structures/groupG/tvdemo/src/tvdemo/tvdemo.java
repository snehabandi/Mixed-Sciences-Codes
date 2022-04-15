package tvdemo;
import java.util.Scanner;
class tvdemo
{
	public static void main(String[] args)
	{
		String s1=new String ("Wrong Model_no.");
		String s2=new String ("Wrong size.");
		String s3=new String ("Wrong price.");
		Television ob =new Television();
		Scanner scan=new Scanner(System.in);
		//1st try block
			try
			{
				System.out.println("Enter the Model no.");
				ob.setmodelno(scan.nextInt());
				if(ob.getmodelno()<=1000||ob.getmodelno()>=9999)
				{
				 throw new MyException(s1);
				}
			    else
			    {
				 System.out.println("Model Number is correct");
			    }
			}
			catch(MyException exc)
			{
				System.out.println(exc);
			}
		//2nd try block
			try
			{
			System.out.println("Enter the Size");
			ob.setsize(scan.nextInt());
			if(ob.getsize()<12||ob.getsize()>70)
			{
				throw new MyException(s2);
			}
			else
			{
				System.out.println("Size is correct");
			}
			}
			catch(MyException exc)
			{
				System.out.println(exc);
			}
		//3rd try block
			try
			{
				System.out.println("Enter the Price");
				ob.setmodelno(scan.nextInt());
			if(ob.getprice()<500||ob.getprice()>5000)
			{
				throw new MyException(s3);
			}
			else
			{
				System.out.println("Price is correct");
			}
			}
			catch(MyException exc)
			{
				System.out.println(exc);
			}
			
			finally
			{
				scan.close();
			}
	}
}