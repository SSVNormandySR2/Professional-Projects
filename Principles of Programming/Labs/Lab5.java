/*-------------------------------------------------------------------------
//AUTHOR: Vincent Latona
//FILENAME: Lab5.java
//SPECIFICATION: Options for display of numbers between 2 integers and printing a triangle
//TIME SPENT: 30 minutes
//-----------------------------------------------------------*/

//Must import needed packages
import java.util.Scanner;

//Class must match the filename
public class Lab5 
{
	
	//Main method required to run a java program
	public static void main(String[] args)
	{
		
		//Declaration of variables
		Scanner in = new Scanner (System.in);
		int input = 0;
		boolean done = false;
		int firstInt = 0;
		int secondInt = 0;
		int triangleHeight = 0;
		
		//While loop that iterates until sentinel made true
		while (!done)
		{
			
			//User options
			System.out.println("Please choose from the following menu: ");
			System.out.println("1) Print all integer numbers between 2 given integers.");
			System.out.println("2) Display a right triangular pattern of stars.");
			System.out.println("3) Quit.");	
			
			//User option choice input
			input = in.nextInt();
			
			//Switch statement for functions
			switch (input)
			{
			
			//Case 1 for printing all integers between 2 integers
			case 1:
				
				//Prompting for start integer and acceptance of user input
				System.out.println("Please enter the start integer: ");
				firstInt = in.nextInt();
				
				//Prompting for last integer and acceptance of user input
				System.out.println("Please enter the last integer: ");
				secondInt = in.nextInt();
				
				//For loop to count all values between first and last integers
				for (int i = firstInt; i <= secondInt; i++)
				{
					
					//Printing of integers between first and last
					System.out.print(i);
				
				}//End of counting loop
				
				//Creating a space, so the output does not overlap with the options prompt
				System.out.println();
				
				break;//End of case 1
			
			//Case 2 for printing a triangle
			case 2:
				
				//Prompting for triangle height and acceptance of user input
				System.out.println("Please enter the desired height of the triangle: ");
				triangleHeight = in.nextInt();
				
				//Outer For loop for number or rows within the triangle
				for (int a = 1; a <= triangleHeight; a++)
				{
					
					//Nested For loop for number of stars within each row
					for (int b = 1; b <= a; b++)
					{
						
						//Printing of stars at each row
						System.out.print("*");
						
					}//End of nested/star loop
					
					//Creating a new row
					System.out.println();
					
				}//End of outer row for loop
				
				break;//End of case 2
			
			//Case 3 for ending the program
			case 3:
				
				//Goodbye message
				System.out.println("Goodbye!");
				
				//Conversion of sentinel for ending the loop
				done = true;
				
				break;//End of case 3
			
			}//End of Switch
		
		}//End of While loop
	
	}//End of Main method
	
}//End of Lab5 class
