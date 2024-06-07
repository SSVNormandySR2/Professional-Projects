// Assignment #: 5
// Name: Vincent Latona
//  Time took you to complete the assignment: 49 minutes
// Description: This is the parent class that is abstract, providing a means
//				of inheritance for derivative camps

//Import necessary packages
import java.text.NumberFormat;
import java.util.Locale;

//This class is an abstract parent to specific camps
public abstract class SummerCamp 
{
	
	//Instance variable and object declaration
	protected String title;
	protected String location;
	protected double weeklyRate;
	protected int numberOfWeeks;
	protected double totalCost;
	protected Locale usMoney;
	protected NumberFormat fmt;
	
	/**
	 This constructor provides a means to initialize the variables
	 */
	public SummerCamp(String someTitle, String someLocation, double someWeeklyRate, int someNumberOfWeeks)
	{
		
		//Instance variable initialization
		title = someTitle;
		location = someLocation;
		weeklyRate = someWeeklyRate;
		numberOfWeeks = someNumberOfWeeks;
		totalCost = 0.0;
		
		//Formatting object instantiation
		usMoney = new Locale("en", "US");
		fmt = NumberFormat.getCurrencyInstance(usMoney);
		
	}//End of constructor
	
	/**
	 This method retrieves the camp title
	 */
	public String getCampTitle()
	{
		
		//Return of title
		return title;
		
	}//End of getCampTitle method
	
	/**
	 This method is abstract, which will be implemented by child classes
	 */
	public abstract void computeTotalCost();
	
	/**
	 This method provides formatting for output of SummerCamp and child objects
	 */
	public String toString()
	{
		
		//Format and return
		return "\nCamp Title:\t\t" + title
				+ "\nLocation:\t\t" + location
				+ "\nWeekly Rate:\t\t" + fmt.format(weeklyRate)
				+ "\nWeeks:\t\t\t" + numberOfWeeks
				+ "\nTotal Cost:\t\t" + fmt.format(totalCost) + "\n";
		
		
	}//End of toString method
	
}//End of abstract class SummerCamp