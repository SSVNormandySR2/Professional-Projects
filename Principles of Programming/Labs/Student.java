/*-------------------------------------------------------------------------
// AUTHOR: Vincent Latona
// FILENAME: Student.java
// SPECIFICATION: This is a defined class to provide services to the driver program Lab8.
// TIME SPENT: 2 hours and 15 minutes total
//-----------------------------------------------------------*/

//Class name must match filename
public class Student 
{
	
	//Declaration of instance variables
	private String firstName;
	private String lastName;
	private String studentMajor;
	private int studentCredits;
	private int studentPoints;
	
	//Constructor 1 - Name only
	public Student(String fName, String lName)
	{
		
		//Data member assignment to input data
		this.firstName = fName;
		this.lastName = lName;
		this.studentMajor = "General Studies";
		this.studentCredits = 0;
		this.studentPoints = 0;
		
	}//End of Constructor 1
	
	//Constructor 2 - All input data
	public Student(String fName, String lName, String major, int credits, int points)
	{
		
		//Data member assignment to input data
		this.firstName = fName;
		this.lastName = lName;
		this.studentMajor = major;
		this.studentCredits = credits;
		this.studentPoints = points;
		
	}//End of constructor 2
	
	/**
	 This method obtains the student object's major
	 */
	public String getMajor()
	{
		//Returns student major
		return studentMajor;
		
	}//End of getMajor method
	
	/**
	 This method returns the number of gradepoints of the student object
	 */
	public int getGradePoints()
	{
		//Returns student points
		return studentPoints;
		
	}//End of getGradePoints method
	
	/**
	 This method returns the number of credits of the student object
	 */
	public int getCredits()
	{
		
		//Returns student credits
		return studentCredits;
		
	}//End of getCrdits method
	
	/**
	 This method returns the name of the student object
	 */
	public String getFullName()
	{
		
		//String to concatenate names and contain the full name
		String fullName = firstName + " " + lastName;
		
		//Returns fullName string
		return fullName;
		
	}//End of getName method
	
	/**
	 This method will change the major of the student object
	 */
	public void changeMajor(String newMajor)
	{
		
		//Changes studentMajor to new major that was input
		studentMajor = newMajor;
		
	}//End of changeMajor method
	
	/**
	 This method will accept parameters to run a loop for summation and display of values
	 */
	public void loopHelper(int start, int end, int incBy)
	{
		
		//Variable to store the sum of numbers produced by the value loop
		int sum = 0;
		
		//Loop to display values between 2 numbers
		while (start <= end)
		{
			
			//Display of numbers
			System.out.print(start);
			
			//Sum calculation
			sum = sum + start;
			
			//Incrementation of the start by incBy
			start = start + incBy;
			
		}//End of values loop
		
		//Display of sum of values produced by loop
		System.out.println();
		System.out.println("Sum is: " + sum);
		
	}//End of loopHelper method

}//End of Student class
