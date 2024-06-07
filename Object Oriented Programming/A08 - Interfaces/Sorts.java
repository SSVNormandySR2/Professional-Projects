// Assignment #: 8
//         Name: Vincent Latona
//		Time took you to complete the assignment: 29 minutes
//		Description: This class sorts an array of clubs using the method of 
//				the comparator parameter

//Import necessary packages
import java.util.*;

//The Sorts class is a utility for sorting the club array
public class Sorts 
{
	
	/**
	 * This method sorts the array of clubs using the selection method
	 */
	public static void sort(Club[] clubList, int size, Comparator<Club> comparator)
	{
		
		//Variable for the index of the smallest element
		int min;
		
		//Outer sorting loop
		for(int a = 0; a < size-1; a++)
		{
			
			//Default smallest element for later comparison
			min = a;
			
			//Inner sorting loop
			for(int b = a+1; b < size; b++)
			{
				
				//Smallest element case
				if(comparator.compare(clubList[b], clubList[min]) < 0)
				{
					
					//New smallest element
					min = b;
					
				}//End of smallest element case
				
			}//End of inner sorting loop
			
			//Element swapping
			Club temp = clubList[a];
			clubList[a] = clubList[min];
			clubList[min] = temp;
			
		}//End of outer sorting loop
		
	}//End of sort method
	
}//End of Sorts class