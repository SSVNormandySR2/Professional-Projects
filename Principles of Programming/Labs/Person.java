/*-------------------------------------------------------------------------
// AUTHOR: Vincent Latona
// FILENAME: Lab6.java
// SPECIFICATION: Prints the name and age of a person in a certain year
// used in Lab6.java
// TIME SPENT: 50 minutes total.
//-----------------------------------------------------------*/

//Class name must match filename
public class Person 
{
	
	//Declaration of instance variables
	private String firstname;
	private String lastname;
	private int birthYear;
		
	//Constructor for objects
	public Person (String fname, String lname, int year)
	{
		
		//Binding of instance variables to object variables
		firstname = fname;
		lastname = lname;
		birthYear = year;
		
	}//End of constructor
	
	//First name accessor
	public String getFirstName()
	{
		
		//Return of first name
		return firstname;
		
	}//End of getFirstName
	
	//Last name accessor
	public String getLastName()
	{
		
		//Return of last name
		return lastname;
		
	}//End of getLastName
	
	//Method to tell age
	public int getAge(int currentYear)
	{
		
		//Specification for determining age
		int age = currentYear - birthYear;
		
		//Return of age
		return age;
		
	}//End of getAge
	
}//End of Person class
