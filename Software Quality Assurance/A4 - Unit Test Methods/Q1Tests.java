/*
 * Vincent Latona
 */

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class Q1Tests 
{
	public static int[] bubbleSortEfficient(int[] A, int size)
	{
		int temp;
		boolean exchanged = true;
		for(int i = 0; i < size && exchanged; i++)
		{
			exchanged = false;
			for(int j = size - 1; j >= i + 1; j--)
			{
				if(A[j] < A[j-1])
				{
					temp = A[j];
					A[j] = A[j-1];
					A[j-1] = temp;
					exchanged = true;
				}
			}
		}
		return A;
	}
	
	/*
	 * This method tests Path 1 of the Control Flow Graph (1,2,3,4,13)
	 */
	@Test
	void Path1() 
	{
		int[] expected = {};
		int[] test = {};
		assertArrayEquals(expected, bubbleSortEfficient(test, 0));
	}
	
	/*
	 * This method tests Path 3 of the Control Flow Graph (1,2,3,4,5,7,8,9,6,4,13)
	 */
	@Test
	void Path3()
	{
		int[] expected = {5};
		int[] test = {5};
		assertArrayEquals(expected, bubbleSortEfficient(test, 1));
	}
	
	/*
	 * This method tests Path 4 of the Control Flow Graph (1,2,3,4,5,7,8,9,11,10,9,6,4,13)
	 */
	@Test
	void Path4()
	{
		int[] expected = {4, 5};
		int[] test = {4, 5};
		assertArrayEquals(expected, bubbleSortEfficient(test, 2));
	}
	
	/*
	 * This method tests Path 5 of the Control Flow Graph (1,2,3,4,5,7,8,9,11,12,10,9,6,4,13)
	 */
	@Test
	void Path5()
	{
		int[] expected = {4, 5};
		int[] test = {5, 4};
		assertArrayEquals(expected, bubbleSortEfficient(test, 2));
	}
}
