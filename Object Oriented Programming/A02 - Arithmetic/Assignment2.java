// Assignment #: 2
//         Name: Vincent Latona
//  Description: This program reads integers and performs calculations on them

//Import needed packages
import java.util.Scanner;

//Assignment2 class must match 
public class Assignment2 
{

	//Main method required for a java program
	public static void main(String[] args)
	{
		
		//Variable declaration
		boolean done = false;
		int input;
		int min = 0;
		int odd = 0;
		int largestEven = 0;
		int sum = 0;
		Scanner in = new Scanner(System.in);
		
		while (!done)
		{
			
			//User input
			input = in.nextInt();
			
			//Loop ending statement
			if (input == 0)
			{
				
				//Boolean conversion
				done = true;
				
			}//End of loop ender
			
			//Minimum calculation
			if (input < min)
			{
				
				//New minimum
				min = input;
				
			}//End of minimum calculation
			
			//Odd counter
			if (input%2 != 0)
			{
				
				//Increment odd counter
				odd = odd + 1;
				
			}//End of odd counter
			
			//Largest even calculator
			if (input%2 == 0 && input > largestEven)
			{
				
				//New largest even number
				largestEven = input;
				
			}//End of largest even calculation
			
			//Positive sum calculation
			if (input >= 0)
			{
				
				//Sum update
				sum = sum + input;
				
			}//End of positive sum calculator
			
		}//End of calculations loop
		
		//Formatted output
		System.out.println("The minimum integer is " + min);
		System.out.println("The count of odd integers in the sequence is " + odd);
		System.out.println("The largest even integer in the sequence is " + largestEven);
		System.out.print("The sum of positive integers is " + sum);
		
	}//End of main method
	
}//End of Assignment2 class