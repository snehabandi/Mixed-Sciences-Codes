package tvdemo;
public class MyException extends Exception
{
	
	private String exe;
	MyException(String s)
	{
		exe=s;
	}
	public void ToString()
	{
		System.out.println("wrong");
	}

}