// Assignment #: 8
//         Name: Vincent Latona
//		Time took you to complete the assignment: 21 minutes
//		Description: This class compares the names of current club presidents, 
//				assisting in sorting as well

//Package import for Comparator
import java.util.*;

//The CurrentPresidentComparator class implements the Comparator interface
public class CurrentPresidentComparator implements Comparator<Club>
{
	
	/**
	 * This method compares current presidents of clubs, assisting other classes
	 */
	public int compare(Club first, Club second)
	{
		
		//Return variable
		int result;
		
		//Same last name case
		if (first.getCurrentPresident().getLastName().compareTo(second.getCurrentPresident().getLastName()) == 0)
		{
			
			//Same first name case
			if (first.getCurrentPresident().getFirstName()
					.compareTo(second.getCurrentPresident().getFirstName()) == 0)
			{
				
				//Return 0 when the same
				result = 0;
				
			}//End of same first name case
			
			//Larger first name case
			else if (first.getCurrentPresident().getFirstName()
					.compareTo(second.getCurrentPresident().getFirstName()) > 0)
			{
				
				//Assign the result the value from the comparison
				result = first.getCurrentPresident().getFirstName().compareTo(second.getCurrentPresident().getFirstName());
				
			}//End of larger first name case
			
			//Smaller first name case
			else
			{
				
				//Assign the result the value from the comparison
				result = first.getCurrentPresident().getFirstName().compareTo(second.getCurrentPresident().getFirstName());
				
			}//End of smaller first name case
			
		}//End of same last name case
		
		//Larger last name case
		else if (first.getCurrentPresident().getLastName().compareTo(second.getCurrentPresident().getLastName()) > 0)
		{
			
			//Assign result the value from the comparison
			result = first.getCurrentPresident().getLastName().compareTo(second.getCurrentPresident().getLastName());
			
		}//End of larger last name case
		
		//Smaller last name case
		else
		{
			
			//Assign result the value from the comparison
			result = first.getCurrentPresident().getLastName().compareTo(second.getCurrentPresident().getLastName());
			
		}//End of smaller last name case
		
		//Return value
		return result;
		
	}//End of compare method
	
}//End of CurrentPresidentComparator class