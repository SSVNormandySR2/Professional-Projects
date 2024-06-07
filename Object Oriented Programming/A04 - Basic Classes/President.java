// Assignment #: 4
//  Name: Vincent Latona
//  Time took you to complete the assignment: 45 minutes
//  Description: This is the President class, providing
//				 methods for president objects, the Club class,
//				 and the Assignment4 driver program

//President class name must match filename
public class President 
{
	
	//Instance variable declaration
	private String firstName;
	private String lastName;
	private String academicLevel;
	
	/**
	 This is the default Constructor for the President class
	 */
	public President()
	{
		
		//Instance variable initialization
		firstName = "?";
		lastName = "?";
		academicLevel = "?";
		
	}//End of President constructor
	
	/**
	 This method retrieves the first name of the object
	 */
	public String getFirstName()
	{
		
		//Returns the first name of the object
		return firstName;
		
	}//End of getFirstName method
	
	/**
	 This method retrieves the last name of the object
	 */
	public String getLastName()
	{
		
		//Returns the last name of the object
		return lastName;
		
	}//End of getLastName method
	
	/**
	 This method retrieves the academic level of the object
	 */
	public String getAcademicLevel()
	{
		
		//Returns academic level of the object
		return academicLevel;
		
	}//End of getAcademicLevel method
	
	/**
	 This method sets the first name of the object
	 */
	public void setFirstName(String str)
	{
		
		//Variable mutation
		firstName = str;
		
	}//End of setFirstName method
	
	/**
	 This method sets the last name of the object
	 */
	public void setLastName(String str)
	{
		
		//Variable mutation
		lastName = str;
		
	}//End of setLastName method
	
	/**
	 This method sets the academic level of the object
	 */
	public void setAcademicLevel(String str)
	{
		
		//Variable mutation
		academicLevel = str;
		
	}//End of setAcademicLevel method
	
	/**
	 This method formats the display of the object
	 */
	public String toString()
	{
		
		//Variable creation and its return
		String str = "" + lastName + "," + firstName + "(" + academicLevel + ")";
		return str;
		
	}//End of toString method
	
}//End of President class