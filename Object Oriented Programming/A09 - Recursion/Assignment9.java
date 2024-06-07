// Assignment #: 9
//         Name: Vincent Latona
//		Time took you to complete the assignment: 3 hours 34 minutes
// 		Description: This program creates an array of user inputs and calculates the minimum element, 
//				number of odd elements, the largest even element, 
//				and the sum of elements larger than the first of the collection

//Import necessary packages
import java.io.*;

//Assignment9 class for recursive interaction with arrays
public class Assignment9 
{
	
	//Main method required for driver
	public static void main(String[] args)
	{
		
		try
		{
			
			//Input reading objects
			InputStreamReader isr = new InputStreamReader(System.in);
			BufferedReader br = new BufferedReader(isr);
			
			//Array and element counter
			int[] elements = new int[100];
			int elementCount = 0;
			
			//Boolean for stopping the loop
			boolean done = false;
			
			//Loop to read inputs and array population
			while(!done && elementCount < elements.length)
			{
				
				//Input reading
				String str = br.readLine();
				
				//Element addition and counter incrementation
				elements[elementCount] = Integer.parseInt(str);
				elementCount++;
				
				//Loop-ending case
				if(Integer.parseInt(str) == 0)
				{
					
					//Boolean conversion
					done = true;
					
				}//End of loop-ender
				
			}//End of input loop
			
			//Final calculation and result display
			if(done == true)
			{
				
				//Output display
				System.out.print("The minimum number is " + findMin(elements, 0, elementCount-1) + "\n"
						+ "The count of odd integers in the sequence is " + countOddNumbers(elements, 0, elementCount-1) + "\n"
						+ "The largest even integer in the sequence is " + computeLargestEven(elements, 0, elementCount-1) + "\n"
						+ "The sum of numbers larger than the first is " + sumOfNumbersLargerThanFirst(elements, 0, elementCount-1, elements[0]) + "\n");
				
			}//End of calculation and result display
			
		}//End of error-causing lines
		
		//Array exception handling
		catch(ArrayIndexOutOfBoundsException ex)
		{
			
		}//End of array exception handling
		
		//Input/Output exception handling
		catch(IOException e)
		{
			
		}//End of input/output exception handling
		
	}//End of main method
	
	/**
	 * This method finds the smallest number in an array using recursion
	 */
	public static int findMin(int[] elements, int startIndex, int endIndex)
	{
		
		//Return variable
		int variable = 0;
		
		//Base case
		if(startIndex == endIndex)
		{
			
			variable = elements[startIndex];
			
		}//End of base case
		
		//Recursive case check
		else if(startIndex < endIndex)
		{
			
			//Non-recursive call case
			if(startIndex+1 > endIndex-1)
			{
				
				//Initial minimum
				int key = elements[startIndex];
				
				//Local minimum case
				if(key > elements[endIndex])
				{
					
					//Smallest local element
					key = elements[endIndex];
					
				}//End of local minimum case
				
				//Minimum overall
				variable = key;
				
			}//End of non-recursive call case
				
			//Recursive call case
			else
			{
				
				//Variables to be compared recursively
				int key = elements[startIndex];
				int check = findMin(elements, startIndex+1, endIndex-1);
				
				//Local minimum case
				if(key > elements[endIndex])
				{
					
					//Smallest local element
					key = elements[endIndex];
					
				}//End of local minimum case
				
				//Recursive comparison
				//Smaller recursive result case
				if(key > check)
				{
					
					//Minimum overall
					variable = check;
					
				}//End of smaller recursive result case
				
				//Smaller local result case
				else
				{
					
					//Minimum overall
					variable = key;
					
				}//End of smaller local result case
				
			}//End of recursive call case
			
		}//End of recursive check case
		
		//Variable return
		return variable;
		
	}//End of findMin method
	
	/**
	 * This method counts the odd numbers in an array using recursion
	 */
	public static int countOddNumbers(int[] elements, int startIndex, int endIndex)
	{
		
		//Return variable
		int variable = 0;
		
		//Base case
		if(startIndex == endIndex)
		{
			//Odd case
			if((elements[startIndex] % 2) != 0)
			{
				
				//Variable manipulation
				variable = 1;
				
			}//End of odd case
			
			//Even case
			else
			{
				
				//Variable manipulation
				variable = 0;
				
			}//End of even case
			
		}//End of base case
		
		//Recursive case
		else if(startIndex < endIndex)
		{
			
			//Odd case
			if((elements[startIndex] % 2) != 0)
			{
				
				//Variable mainpulation
				variable = 1;
				
			}//End of odd case
			
			//Total of odd elements
			variable += countOddNumbers(elements, startIndex+1, endIndex);
			
		}//End of recursive case
		
		//Variable return
		return variable;
		
	}//End of countOddNumbers method
	
	/**
	 * This method finds the largest even number in an array using recursion
	 */
	public static int computeLargestEven(int[] elements, int startIndex, int endIndex)
	{
		
		//Return variable
		int variable = 0;
		
		//Base case
		if(startIndex == endIndex)
		{
			
			//Even case
			if((elements[startIndex] % 2) == 0)
			{
				
				//Return the element
				variable = elements[startIndex];
				
			}//End of even case
			
			//Odd case
			else
			{
				
				//Return -1 for odd
				variable = -1;
				
			}//End of odd case
			
		}//End of base case
		
		//Recursive case
		else if(startIndex < endIndex)
		{
			
			//Recursion
			int check = computeLargestEven(elements, startIndex+1, endIndex);
			
			//Only even case
			if(check == -1 && ((elements[startIndex] % 2) == 0))
			{
				
				//Make the even result the largest
				variable = elements[startIndex];
				
			}//End of only even case
			
			//Both even case
			else if(((elements[startIndex] % 2) == 0) && ((check % 2) == 0))
			{
				
				//Larger recursive result
				if(check > elements[startIndex])
				{
					
					//Make the recursive result the largest
					variable = check;
					
				}//End of larger recursive result case
				
				//Larger local result case
				else
				{
					
					//Make the local result the largest
					variable = elements[startIndex];
					
				}//End of larger local result case
				
			}//End of both even case
			
			//Only local result even
			else if(((elements[startIndex] % 2) == 0))
			{
				
				//Make the local result the largest
				variable = elements[startIndex];
				
			}//End of only local result even case
			
			//Only recursive result even
			else if(((check % 2) == 0))
			{
				
				//Make the recursive result the largest
				variable = check;
				
			}//End of only recursive result even case
			
			//Both odd case
			else
			{
				
				//Return -1 for both odd
				variable = -1;
				
			}//End of both odd case
			
		}//End of recursive case

		//Variable return
		return variable;
		
	}//End of computeLargestEven method
	
	/**
	 * This method computes the sum of numbers larger than the first number in an array using recursion
	 */
	public static int sumOfNumbersLargerThanFirst(int[] elements, int startIndex, int endIndex, int firstNumber)
	{
		
		//Return variable
		int variable = 0;
		
		//Base case
		if(startIndex == endIndex)
		{
			
			//Larger case
			if(elements[startIndex] > firstNumber)
			{
				
				//Increase sum
				variable = elements[startIndex];
				
			}//End of larger case
			
		}//End of base case
		
		//Recursive case
		else if(startIndex < endIndex)
		{
			
			//Larger case
			if(elements[startIndex] > firstNumber)
			{
				
				//Increase sum
				variable = elements[startIndex];
				
			}//End of larger case
			
			//Sum calculation
			variable += sumOfNumbersLargerThanFirst(elements, startIndex+1, endIndex, firstNumber);
			
		}//End of recursive case
		
		//Variable return
		return variable;
		
	}//End of sumOfNumbersLargerThanFirst method
	
}//End of Assignment9 class