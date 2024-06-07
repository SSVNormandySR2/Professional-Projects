// Assignment #: 8
//         Name: Vincent Latona
//		Time took you to complete the assignment: 9 minutes
//		Description: This class compares the member count of clubs, 
//				assisting in sorting as well

//Package import for Comparator
import java.util.*;

//The MemberNumberComparator class implements the Comparator interface
public class MemberNumberComparator implements Comparator<Club>
{
	
	/**
	 * This method compares the number of club members of clubs, assisting other classes
	 */
	public int compare(Club first, Club second)
	{
		
		//Return variable
		int result;
		
		//Equal case
		if (first.getNumberOfMembers() == second.getNumberOfMembers())
		{
			
			//Return 0 when the same
			result = 0;
			
		}//End of equal case
		
		//Larger case
		else if (first.getNumberOfMembers() > second.getNumberOfMembers())
		{
			
			//Return 1 when larger
			result = 1;
			
		}//End of larger case
		
		//Smaller case
		else
		{
			
			//Return -1 if smaller
			result = -1;
			
		}//End of smaller case
		
		//Return the value
		return result;
		
	}//End of compare method
	
}//End of MemberNumberComparator class