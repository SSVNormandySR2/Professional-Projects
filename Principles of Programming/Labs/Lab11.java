/*-------------------------------------------------------------------------
// AUTHOR: Vincent Latona
// FILENAME: Lab11.java
// SPECIFICATION: This program allows a user to create a 2-Dimensional array, fill it, and calculates the sum of the elements in each row
// TIME SPENT: 1 hour
//----------------------------------------------------------------------*/

//Import necessary packages before programming
import java.util.Scanner;
import java.util.Arrays;

//Class name must match filename
public class Lab11 
{
	
	public static void main(String[] args)
	{
		
		//Variable declaration
		Scanner in = new Scanner(System.in);
		int rowNum, columnNum, sum;
		String disp = "";
		
		//Prompting and accepting of rows and columns for the array
		System.out.println("Please enter the number of rows in the array: ");
		rowNum = in.nextInt();
		System.out.println("Please enter the number of columns in the array: ");
		columnNum = in.nextInt();
		
		//2-D array declaration
		int[][] array2D = new int[rowNum][columnNum];
		
		//Nested loops to fill the array
		//Outer loop to enter rows
		for (int i = 0; i<rowNum; i++)
		{
			
			//Loop to fill individual array elements
			for (int j = 0; j<columnNum; j++)
			{
				
				System.out.println("Please enter a value: ");
				array2D[i][j] = in.nextInt();
				
			}//End of element array
			
		}//End of loop to enter rows
		
		//Nested loops to display the array contents
		//Outer loop to enter rows
		for (int i = 0; i<rowNum; i++)
		{
					
			//Loop to display elements
			for (int j = 0; j<columnNum; j++)
			{
						
				//Create a string to display the contents of the row
				disp = disp + array2D[i][j] + " ";
				
				//Newline creator and display of array
				if (j == columnNum - 1)
				{
					
					//Display of row and start newline
					System.out.println(disp);
					
					//Clear the display to display the next line
					disp = "";
					
				}//End of newline printer
						
			}//End of element array
					
		}//End of loop to enter rows
		
		sum = 0;
		
		//Sum display loops
		for (int i = 0; i<rowNum; i++)
		{
			
			//Loop to calculate sum of rows
			for (int j = 0; j<columnNum; j++)
			{
				
				sum = sum + array2D[i][j];
				
				//Display sum of elements of the row
				if (j == columnNum - 1)
				{
					
					//Display of sum of elements in the row
					System.out.println("Sum of elements of row " + i + " is: " + sum);
					
					//Clear sum for new calculation of next row
					sum = 0;
					
				}//End of sum display
				
			}//End of sum calculation
			
		}//End of sum display loops
		
	}//End of main method

}//End of Lab11 class