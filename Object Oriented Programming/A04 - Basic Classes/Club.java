// Assignment #: 4
//  Name: Vincent Latona
//  Time took you to complete the assignment: 40 minutes
//  Description: This is the Club class, providing
//				 methods for club objects and the 
//				 Assignment4 driver program

//Club class name must match filename
public class Club 
{
	
	//Instance variable declaration
	private String clubName;
	private int numberOfMembers;
	private String university;
	private President currentPresident;
	
	/**
	 This is the default constructor for the Club class
	 */
	public Club()
	{
		
		//Instance variable initialization
		clubName = "?";
		numberOfMembers = 0;
		university = "?";
		currentPresident = new President();
		
	}//End of Club constructor
	
	/**
	 This method retrieves the club name of the object
	 */
	public String getClubName()
	{
		
		//Returns the club name of the object
		return clubName;
		
	}//End of getClubName method
	
	/**
	 This method retrieves the number of members of the object
	 */
	public int getNumberOfMembers()
	{
		
		//Returns number of members of the object
		return numberOfMembers;
		
	}//End of getNumberOfMembers method
	
	/**
	 This method retrieves the university of the object
	 */
	public String getUniversity()
	{
		
		//Returns university
		return university;
		
	}//End of getUniversity method
	
	/**
	 This method sets the club name of the object
	 */
	public void setClubName(String str)
	{
		
		//Variable mutation
		clubName = str;
		
	}//End of setClubName method
	
	/**
	 This method sets the number of members of the object
	 */
	public void setNumberOfMembers(int num)
	{
		
		//Variable mutation
		numberOfMembers = num;
		
	}//End of setNumberOfMembers method
	
	/**
	 This method sets the university of the object
	 */
	public void setUniversity(String str)
	{
		
		//Variable mutation
		university = str;
		
	}//End of setUniversity method
	
	/**
	 This method fills the parameters of the president object
	 */
	public void setCurrentPresident(String fName, String lName, String level)
	{
		
		//Object parameter filling
		currentPresident.setFirstName(fName);
		currentPresident.setLastName(lName);
		currentPresident.setAcademicLevel(level);
		
	}//End of setCurrentPresident method
	
	/**
	 This method formats the display of the object
	 */
	public String toString()
	{
		
		//Variable creation and return of the method
		String str = "\nClub Name:\t\t" + clubName + "\nNumber Of Members:\t" + numberOfMembers 
				+ "\nUniversity:\t\t" + university + "\nPresident:\t\t" + currentPresident.toString()
				+ "\n\n";
		
		return str;
		
	}//End of toString method
	
}//End of Club class