/*-------------------------------------------------------------------------
// AUTHOR: Vincent Latona
// FILENAME: Lab4.java
// SPECIFICATION: Calculator that prompts to calculate until told to stop
// TIME SPENT: 1 hour and 5 minutes
//-----------------------------------------------------------*/

//Must import packages before programming
import java.util.Scanner;

//Class name must match the filename.
public class Lab4 
{
	
	//Main method required to run a java program
	public static void main(String[] args)
	{
		//Declaration of boolean and variables used throughout the program
		boolean done = false;
		int choice = 0;
		Scanner in = new Scanner(System.in);
		
		//While loop that iterates until done is made true
		while (!done)
		{
			
		//Display of calculation options
		System.out.println("Please choose from the following menu:");
		System.out.println("1) Calculate the sum of integers from 1 to m");
		System.out.println("2) Calculate the factorial of a given number");
		System.out.println("3) Display the leftmost digit of a given number");
		System.out.println("4) Quit");
		
		//Input of function choice
		choice = in.nextInt();
			
			//Switch statement for functions
			switch (choice)
			{
			
			//Case 1 for summation
			case 1: 
				System.out.println("Please enter a number to find out the sum from 1 to that number: ");
				
				//Declaration of variables used in calculation
				int total = 0;
				int sum = 0;
				int i = 1;
				int m = 0;
				
				//Input of last value of summation
				m = in.nextInt();
				
				//Actual calculation
				while (i <= m)
				{
					
					sum = i;
					total = total + sum;
					i++;
				
				}
				
				//Display of answer
				System.out.println("The sum from 1 to " + m + " is " + total);
				
				break;//End of case 1
			
			//Case 2 for factorial
			case 2: 
				System.out.println("Please enter a number to find the factorial of that number: ");
				
				//Declaration of variables used in calculation
				int factorial = 1;
				int number = 0;
				int x = 1;
				int y = 0;
				
				//Input of factorial
				y = in.nextInt();
				
				//Factorial calculation
				while (x <= y)
				{
					
					number = x;
					factorial = number * factorial;
					x++;
				
				}
				
				//Display of answer
				System.out.println("The factorial of " + y + " is " + factorial);
				
				break;//End of case 2
				
			//Case 3 for leftmost digit
			case 3:
				System.out.println("Please enter a number to find out the leftmost digit: ");
				
				//Variable declaration
				String leftmost = new String("");
				
				//User input
				leftmost = in.next();
				
				//Display of answer
				System.out.println(leftmost.substring(0,1));
				
				break;//End of case 3
				
			//Case 4 for ending the loop
			case 4:
				System.out.println("Goodbye!"); 
				done = true; 
				
				break;//End of case 4
				
			}//End of Switch statement
		
		}//End of while loop
		
	}//End of main method

}//End of class
