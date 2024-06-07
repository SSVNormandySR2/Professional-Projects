// Assignment #: 5
// Name: Vincent Latona
//  Time took you to complete the assignment: 27 minutes
// Description: This is the child class of SummerCamp parent, inheriting 
//				the parent methods and variables for use in RoboticsCamp

//This class is the child of the SummerCamp class,
//specifically for the RoboticsCamp
public class RoboticsCamp extends SummerCamp
{
	
	//Instance variable declaration
	private double facilityFee;
	private double competitionFee;
	
	/**
	 This constructor provides access to the parent constructor and initializes its instance variables
	 */
	public RoboticsCamp(String title, String location, double rate, int weeks, double facilityFee, double compFee)
	{
		
		//Instance variable initialization and parent parameter passing
		super(title, location, rate, weeks);
		this.facilityFee = facilityFee;
		competitionFee = compFee;
		
	}//End of constructor
	
	/**
	 This method implements the computeTotalCost method of its parent class for the RoboticsCamp
	 */
	public void computeTotalCost()
	{
		
		//Total cost calculation
		totalCost = (weeklyRate * numberOfWeeks) + facilityFee + competitionFee;
		
	}//End of computeTotalCost method
	
	/**
	 This method provides additional formatting for RoboticsCamp objects
	 */
	public String toString()
	{
		
		//Parent method call and class variable addition
		return "\nRobotics Camp:" + super.toString()
				+ "Facility Fee:\t\t" + fmt.format(facilityFee)
				+ "\nCompetition Fee:\t" + fmt.format(competitionFee) + "\n\n";
		
	}//End of toString method
	
}//End of RoboticsCamp class