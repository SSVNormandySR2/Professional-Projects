/*-------------------------------------------------------------------------
// AUTHOR: Vincent Latona
// FILENAME: Lab1.java
// SPECIFICATION: This program finds the average of Jenny's test scores.
// TIME SPENT: 22 minutes
//-----------------------------------------------------------*/
import java.util.Scanner;

public class Lab1 
{
	
	public static void main(String[] args) 
	{
		
		Scanner in = new Scanner(System.in);
		
		final int NUM_TESTS = 3;
		
		System.out.print("Please enter the grade received on the first test: ");//Input for First Test
		int test1 = in.nextInt();
		
		System.out.print("Please enter the grade received on the second test: ");//Input for Second Test
		int test2 = in.nextInt();
				
		System.out.print("Please enter the grade received on the thrid test: ");//Input for Thrid Test
		int test3 = in.nextInt();
		
		double average = (double)(test1 + test2 + test3) / NUM_TESTS;
		System.out.println("The Averaeg score of your tests is: " + average);
	}//Method Main
}//Class Lab1
