// Assignment #: 8
//         Name: Vincent Latona
//		Time took you to complete the assignment: 23 minutes
//		Description: This class compares the names of clubs, 
//				assisting in sorting as well

//Package import for Comparator
import java.util.*;

//The ClubNameComparator class implements the Comparator interface
public class ClubNameComparator implements Comparator<Club>
{
	
	/**
	 * This method compares the names of clubs, assisting other classes
	 */
	public int compare(Club first, Club second)
	{
		
		//Return variable
		int result;
		
		//Equal case
		if (first.getClubName().compareTo(second.getClubName()) == 0)
		{
			
			//Return 0 when the same
			result = 0;
	
		}//End of equal case
		
		//Larger case
		else if (first.getClubName().compareTo(second.getClubName()) > 0)
		{
			
			//Assign result the value from the comparison
			result = first.getClubName().compareTo(second.getClubName());
			
		}//End of larger case
		
		//Smaller case
		else
		{
			
			//Assign result the value from the comparison
			result = first.getClubName().compareTo(second.getClubName());
			
		}//End of smaller case
		
		//Return value
		return result;
		
	}//End of compare method
	
}//End of ClubNameComparator class