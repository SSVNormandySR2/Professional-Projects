// Assignment #: 8
//         Name: Vincent Latona
//		Time took you to complete the assignment: 2 hours 11 minutes
// 		Description: This class provides methods that may be used to 
//				modify the array of clubs

//Package import for Serializable
import java.io.*;

//The ClubManagement class implements the serializable interface
public class ClubManagement implements Serializable
{
	
	//Instance variable creation
	private Club[] clubList;
	private int numberOfClubs;
	private int maxSize;
	
	/**
	 * This is the constructor for the ClubManagment class, used for instance
	 * variable initialization
	 */
	public ClubManagement(int maximumSize)
	{
		
		//Instance variable initialization
		maxSize = maximumSize;
		numberOfClubs = 0;
		clubList = new Club[maxSize];
		
		//Loop to initialize each element to null
		for(int i = 0; i < clubList.length; i++)
		{
			
			clubList[i] = null;
					
		}//End of initializor loop
		
	}//End of constructor
	
	/**
	 * This method searches for a club using the club name and university
	 */
	public int clubExists(String clubName, String university)
	{
		
		//Variable to return
		int result = -1;
		
		//Searching loop
		for(int i = 0; i < numberOfClubs; i++)
		{
			
			//Found condition
			if (clubList[i].getClubName().equals(clubName) && clubList[i].getUniversity().equals(university))
			{
				
				//Return the index
				result = i;
				break;
				
			}//End of found condition
			
		}//End of searching loop
		
		//Variable return
		return result;
		
	}//End of clubExists method
	
	/**
	 * This method searches for a president using the president attributes
	 */
	public int currentPresidentExists(String firstName, String lastName, String academicLevel)
	{
		
		//Variable to return
		int result = -1;
		
		//Searching loop
		for(int i = 0; i < numberOfClubs; i++)
		{
			
			//Found condition
			if (clubList[i].getCurrentPresident().getFirstName().equals(firstName)
					&& clubList[i].getCurrentPresident().getLastName().equals(lastName)
					&& clubList[i].getCurrentPresident().getAcademicLevel().equals(academicLevel))
			{
				
				//Return the index
				result = i;
				break;
				
			}//End of found condition
			
		}//End of searching loop
		
		//Variable return
		return result;
		
	}//End of currentPresidentExists method
	
	/**
	 * This method checks whether a club with the passed attributes exists, if not,
	 * it is created and added to the list
	 */
	public boolean addClub(String clubName, int numberOfMembers, String university, String firstName, String lastName, String academicLevel)
	{
		
		//Variable to return
		boolean result = true;
		
		//Maximum size reached case
		if (numberOfClubs == maxSize)
		{
			
			result = false;
			
		}//End of max size case
		
		//Within range case
		else
		{
			
			//Loop to verify whether a duplicate club exists
			for(int i = 0; i < numberOfClubs; i++)
			{
				
				//Duplicate case
				if (clubList[i].getClubName().equals(clubName) 
						&& clubList[i].getNumberOfMembers() == numberOfMembers
						&& clubList[i].getUniversity().equals(university) 
						&& clubList[i].getCurrentPresident().getFirstName().equals(firstName)
						&& clubList[i].getCurrentPresident().getLastName().equals(lastName)
						&& clubList[i].getCurrentPresident().getAcademicLevel().equals(academicLevel))
				{
					
					result = false;
					break;
					
				}//End of duplicate case
				
			}//End of verification loop
			
			//Addition case
			if (result != false)
			{
				
				//Create the new club
				Club club = new Club();
				club.setClubName(clubName);
				club.setNumberOfMembers(numberOfMembers);
				club.setUniversity(university);
				club.setCurrentPresident(firstName, lastName, academicLevel);
				
				//Add the new club to the array
				clubList[numberOfClubs] = club;
				
				//Increment the club counter
				numberOfClubs++;
				
			}//End of addition case
			
		}//End of within range case
		
		//Variable return
		return result;
		
	}//End of addClub method
	
	/**
	 * This method checks whether the indicated club exists, if so, the club is
	 * removed
	 */
	public boolean removeClub(String clubName, String university)
	{
		
		// Variable to return
		boolean result = false;
		
		//Index to remove
		int remove = 0;

		// Searching loop
		for (int i = 0; i < numberOfClubs; i++) 
		{

			// Found condition
			if (clubList[i].getClubName().equals(clubName) && clubList[i].getUniversity().equals(university)) 
			{

				// Return the index
				result = true;
				remove = i;
				break;

			} // End of found condition

		} // End of searching loop
		
		//Removal case
		if (result == true)
		{
			
			//Removal loop
			for(int i = remove; i < numberOfClubs-1; i++)
			{
				
				//Removal of indicated element and array shift
				clubList[i] = clubList[i+1];
				
			}//End of removal loop
			
			//Decrement the club counter
			numberOfClubs--;
			
		}//End of removal case

		// Variable return
		return result;
		
	}//End of removeClub method
	
	/**
	 * This method is used to sort the array by club name
	 */
	public void sortByClubNames()
	{
		
		//Comparator to pass to the sorting class
		ClubNameComparator nameComparator = new ClubNameComparator();
		
		//Array sorting call
		Sorts.sort(clubList, numberOfClubs, nameComparator);
		
	}//End of sortByClubNames method
	
	/**
	 * This method is used to sort the array by member count
	 */
	public void sortByMemberNumbers()
	{
		
		//Comparator to pass to the sorting class
		MemberNumberComparator numberComparator = new MemberNumberComparator();
		
		//Array sorting call
		Sorts.sort(clubList, numberOfClubs, numberComparator);
		
	}//End of sortByMemberNumbers
	
	/**
	 * This method is used to sort the array by current president
	 */
	public void sortByCurrentPresidents()
	{
		
		//Comparator to pass to the sorting class
		CurrentPresidentComparator presidentComparator = new CurrentPresidentComparator();
		
		//Array sorting call
		Sorts.sort(clubList, numberOfClubs, presidentComparator);
		
	}//End of sortByCurrentPresident
	
	/**
	 * This method displays club information
	 */
	public String listClubs()
	{
		
		//Variable to return
		String result = "\n";
		
		//No club case
		if (numberOfClubs == 0)
		{
			
			result = "\nno club\n\n";
			
		}//End of no club case
		
		//String concatenation case
		else
		{
			
			//Display loop
			for(int i = 0; i < numberOfClubs; i++)
			{
				
				result += clubList[i].toString();
				
			}//End of display loop
			
			result += "\n";
			
		}//End of string concatenation case
		
		//Variable return
		return result;
		
	}//End of listClubs method
	
	/**
	 * This method clears the array and resets the club counter to 0
	 */
	public void closeClubManagement()
	{
		
		//Clearing loop
		for(int i = 0; i < clubList.length; i++)
		{
			
			clubList[i] = null;
			
		}//End of clearing loop
		
		//Reset club counter
		numberOfClubs = 0;
		
	}//End of closeClubManagement method
	
}//End of ClubManagement class