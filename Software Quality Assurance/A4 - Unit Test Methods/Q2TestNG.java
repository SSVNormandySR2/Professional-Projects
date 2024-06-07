/*
 * Vincent Latona
 */

import org.testng.annotations.Test;
import static org.testng.AssertJUnit.assertEquals;

public class Q2TestNG 
{
	public static String sortStr(String str)
	{
		char char_array[] = str.toCharArray();
		char temp; 
		
		int i = 0;
		while(i < char_array.length)
		{
			int j = i + 1;
			while(j < char_array.length)
			{
				if(char_array[j] < char_array[i])
				{
					temp = char_array[i];
					char_array[i] = char_array[j];
					char_array[j] = temp;
				}
				j += 1;
			}
			i += 1;
		}
		String returnStr = String.valueOf(char_array);
		return returnStr;
	}
	
	/*
	 * Multithreaded method to test Path 1 of the Control Flow Graph (1,2,3,4,11)
	 */
	@Test
	public void P1()
	{
		assertEquals("", sortStr(""));
		long id = Thread.currentThread().getId();
		System.out.println("Path 1 Thread ID: " + id);
	}
	
	/*
	 * Multithreaded method to test Path 2 of the Control Flow Graph (1,2,3,4,5,6,10,4,11)
	 */
	@Test
	public void P2()
	{
		assertEquals("i", sortStr("i"));
		long id = Thread.currentThread().getId();
		System.out.println("Path 2 Thread ID: " + id);
	}
	
	/*
	 * Multithreaded method to test Path 3 of the Control Flow Graph (1,2,3,4,5,6,7,9,6,10,4,11)
	 */
	@Test
	public void P3()
	{
		assertEquals("ij", sortStr("ij"));
		long id = Thread.currentThread().getId();
		System.out.println("Path 3 Thread ID: " + id);
	}
	
	/*
	 * Multithreaded method to test Path 4 of the Control Flow Graph (1,2,3,4,5,6,7,8,9,6,10,4,11)
	 */
	@Test
	public void P4()
	{
		assertEquals("ij", sortStr("ji"));
		long id = Thread.currentThread().getId();
		System.out.println("Path 4 Thread ID: " + id);
	}
}
