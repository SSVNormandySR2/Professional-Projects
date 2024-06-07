/*------------------------------------------------------------------------- 
// AUTHOR: Vincent Latona
// FILENAME: Assignment4.java
// SPECIFICATION: A program that accepts integer inputs and displays calculations applied to the range of inputs
// TIME SPENT: 3 hours and 26 minutes
//----------------------------------------------------------------------*/

//Must import needed packages before the class
import java.util.Scanner;

//Class name must match filename
public class Assignment4 
{
	
	//Main method required to run a java program
	public static void main(String[] args)
	{
		
		//Variable declaration
		int input = 0;
		double prime = 0;
		double largest = 0;
		double smallest = 1000000;
		double sum = 0;
		double count = 0;
		double average = 0;
		Scanner in = new Scanner(System.in);
		boolean done = false;
		
		//Loop to calculate the average and display all calculations
		while (!done)
		{
			
			//Loop to evaluate prime, sum, count, max, and min conditions
			while (!done)
			{
				
				//Prompt and acceptance of user input
				System.out.println("Please enter a positive integer. Enter -1 to quit.");
				input = in.nextInt();
				
				//Condition that ends the loop
				if (input == -1)
				{
					
					//Conversion of boolean value
					done = true;
					
				}//End of loop-ender
				
				//Evaluation of core prime numbers that are factors of all other numbers
				else if (input == 2 || input == 3 || input == 5 || input == 7)
				{
					
					//Output for primes and increment of prime counter
					System.out.println("The number " + input + " is a prime number.");
					prime++;
					
				}//End of core primes
				
				//Evaluation if the number is divisible by values other than itself and 1
				else if (input % 2 != 0 && input % 3 != 0 && input % 5 != 0 && input % 7 != 0)
				{
					
					//Output of primes and increment of prime counter
					System.out.println("The number " + input + " is a prime number.");
					prime++;
					
				}//End of primes by calculation
				
				//Non-prime number condition
				else
				{
					
					//Output of non-primes
					System.out.println("The number " + input + " is not a prime number.");
					
				}//End of non-primes
				
				//Evaluation for max
				if (input > -1 && input > largest)
				{
					
					//Conversion to largest
					largest = input;
					
				}//End of max
				
				//Evaluation for min
				if (input > -1 && input < smallest)
				{
					
					//Conversion to smallest
					smallest = input;
					
				}//End of min
				
				//Sum calculation
				if (input > 0)
				{
					//Calculation of the sum and the total number of entries
					sum = input + sum;
					count++;
					
				}//End of sum
				
			}//End of max, min, sum, count, prime, and non-prime calculation loop
			
			//Average calculation
			average = sum / count;
			
			if (sum > 0)
			{
				//Display of calculations to the entered values
				System.out.printf("\nThe maximum positive number entered is: %.0f" , largest);
				System.out.printf("\nThe minimum positive number entered is: %.0f" , smallest);
				System.out.printf("\nThe sum of all entered values is: %.0f" , sum);
				System.out.printf("\nThe number of prime numbers within the range of values entered is: %.0f" , prime);
				System.out.printf("\nThe total number of values entered is: %.0f" , count);
				System.out.printf("\nThe average of all entered values is: %.2f" , average);
			}
			
		}//End of average calculation and display loop
		
	}//End of Main method
	
}//End of Assignment4 class
