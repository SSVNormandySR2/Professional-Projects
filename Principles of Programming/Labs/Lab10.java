/*-------------------------------------------------------------
// AUTHOR: Vincent Latona
// FILENAME: Lab10.java
// SPECIFICATION: This program allows a user to create an array, removes the smallest element, and allows a user to remove another
// TIME SPENT: 2 hours 30 minutes
//----------------------------------------------------------- */

//Import necessary packages
import java.util.Scanner;

//Class name must match the filename
public class Lab10 
{
	
	public static void main(String[] args)
	{
		
		//Variable declaration
		int arraySize, temp;
		Scanner in = new Scanner(System.in);
		
		//Prompt and input for array-size
		System.out.println("How many elements in the array?");
		arraySize = in.nextInt();
		
		//Array declaration
		int[] array = new int[arraySize];
		
		//Loop to fill the array
		for (int i = 0; i < array.length; i++)
		{
			
			System.out.println("Please enter the next value: ");
			array[i] = in.nextInt();
			
		}//End of filling loop
		
		//Variable to store the index of the smallest element
		int min;
		
		//Outer loop to evaluate one index against the rest for sorting
		for (int index = 0; index < array.length-1; index++)
		{
			//Set first index as the smallest
			min = index; 
			
			//Inner loop to evaluate the rest of the unsorted array
			for (int scan = index+1; scan < array.length; scan++)
			{
				
				//Smaller-than condition
				if (array[scan] < array[min])
				{
					
					//Set new smallest
					min = scan;  
					
				}//End of smaller condition
				
			}//End of inner loop
			        
			//Swapping the values        
			temp = array[min];         
			array[min] = array[index];         
			array[index] = temp;     
		
		}//End of selection sort
		
		//Variables to display the array
		String start = "{";
		String center = "";
		String end = "";
		
		//Array body for display
		for (int i = 0; i < array.length-1; i++)
		{
			
			center = center + array[i] + ", ";
			
		}//End of central display
		
		end = end + array[array.length-1] + "}";
		
		//Display of the array
		System.out.println("The array after sorting");
		System.out.println(start + center + end);
		
		//Set initial smallest values
		int smallest = array[0];
		int smallestIndex = 0;
		
		//Finding the smallest element
		for (int i = 1; i < array.length; i++)
		{
			
			//Smaller condition
			if (array[i] < smallest)
			{
				
				//Set new smallest value
				smallest = array[i];
				smallestIndex = i;
				
			}//End of smaller condition
			
		}//End of smallest finder
		
		//Smallest removal
		for (int i = smallestIndex+1; i < array.length; i++)
		{
			
			array[i - 1] = array[i];
			
		}//End of smallest removal
		
		array[array.length-1] = 0;
		
		//Variables to display the array
		start = "{";
		center = "";
		end = "";
				
		//Array body for display
		for (int i = 0; i < array.length-1; i++)
		{
					
			center = center + array[i] + ", ";
					
		}//End of central display
				
		end = end + array[array.length-1] + "}";
				
		//Display of the array
		System.out.println("The array with the minimum removed");
		System.out.println(start + center + end);
		
		System.out.println("Enter the value to search and remove: ");
		int numRemove = in.nextInt();
		
		//Variable for the search
		boolean found = false;
		int foundIndex = 0;
		
		//Loop to search for the number to remove
		for(int i = 0; i < array.length; i++)
		{
			
			if (array[i] == numRemove)
			{
				
				foundIndex = i;
				found = true;
				
			}//End of found condition
			
		}//End of search
		
		//Condition to shift values to the left
		if (found)
		{
			
			//Display of found
			System.out.println("Search element found");
			
			//Actual shift
			for (int i = foundIndex+1; i < array.length; i++)
			{
				
				//Shift all values left by one unit
				array[i - 1] = array[i];
				
			}//End of array shift
			
			//Set second to last value to 0 after the shift
			array[array.length-1] = 0;
			
		}//End of shift condition
		
		//Number to be removed not found
		else
		{
			
			//Display of inconclusive search
			System.out.println("Search element NOT found");
			
		}//End of number not found
		
		//Variables to display the array
		start = "{";
		center = "";
		end = "";
						
		//Array body for display
		for (int i = 0; i < array.length-1; i++)
		{
							
			center = center + array[i] + ", ";
							
		}//End of central display
						
		end = end + array[array.length-1] + "}";
						
		//Display of the array
		System.out.println("The final array");
		System.out.println(start + center + end);
		
	}//End of main method
	
}//End of Lab10 class