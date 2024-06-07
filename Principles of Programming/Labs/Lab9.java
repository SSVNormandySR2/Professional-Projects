/*-------------------------------------------------------------------------
// AUTHOR: Vincent Latona
// FILENAME: Lab9.java
// SPECIFICATION: This program computes the sum and displays elements of an array created by the user
// TIME SPENT: 1 hour
//-----------------------------------------------------------*/

//Must import packages before programming
import java.util.Scanner;
import java.util.Arrays;

//Class name must match the filename
public class Lab9 
{
	
	//Main method required for java program
	public static void main(String[] args)
	{
		
		//Variable declaration
		int arrayLength = 0;
		int j = 0;
		double currentElement = 0;
		double sumElements = 0;
		Scanner in = new Scanner(System.in);
		
		//Prompt and input of array length
		System.out.println("How many elements in the array?");
		arrayLength = in.nextInt();
		
		//Creation of array
		double[] doubleArray = new double[arrayLength];
		
		//Loop to fill the array
		for (int i = 0; i < arrayLength; i++)
		{
			
			//Prompt and input of array elements
			System.out.println("Please enter the next value: ");
			doubleArray[i] = in.nextDouble();
			
		}//End of filling loop
		
		//Loop to display array elements
		for (int i = (arrayLength - 1); i >= 0; i--)
		{
			
			//Newline for 8th element
			if (j % 8 == 0)
			{
				
				//Creation of newline
				System.out.println();
				
			}//End of newline condition
			
			//Display of elements
			System.out.print(doubleArray[i] + " ");
			
			//Summation of array elements
			sumElements = sumElements + doubleArray[i];
			
			//element counter for newline
			j++;
			
		}//End of display loop
		
		//Display of sum of elements
		System.out.println("\nThe sum of array elements is: " + sumElements);
		
	}//End of main method

}//End of Lab9 class
