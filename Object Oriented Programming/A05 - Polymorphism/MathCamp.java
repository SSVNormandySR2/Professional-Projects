// Assignment #: 5
// Name: Vincent Latona
//  Time took you to complete the assignment: 28 minutes
// Description: This is the child class of SummerCamp parent, inheriting 
//				the parent methods and variables for use in MathCamp

//This class is the child of the SummerCamp class,
//specifically for the MathCamp
public class MathCamp extends SummerCamp
{
	
	//Instance variable declaration
	private boolean testTaking;
	
	/**
	 This constructor provides access to the parent constructor and initializes its instance variables
	 */
	public MathCamp(String title, String location, double rate, int weeks, String tTaking)
	{
		
		//Parent parameter passing
		super(title, location, rate, weeks);
		
		//Convert to lower-case
		tTaking = tTaking.toLowerCase();
		
		//Verification of test taking
		if (tTaking.equals("yes"))
		{
					
			testTaking = true;
					
		}//End of true case
		else
		{
					
			testTaking = false;
				
		}//End of false case
		
	}//End of constructor
	
	/**
	 This method implements the computeTotalCost method of its parent class for the MathCamp
	 */
	public void computeTotalCost()
	{
		
		//Total cost calculation
		totalCost = weeklyRate * numberOfWeeks;
		
		//Test taking fee addition
		if(testTaking == true)
		{
			
			//Test fee addition
			totalCost = totalCost + 25;
			
		}//End of true condition
		
	}//End of computeTotalCost method
	
	/**
	 This method provides additional formatting for MathCamp objects
	 */
	public String toString()
	{
		//String for 
		String str1 = "no";
				
		//Test taking state
		if(testTaking == true)
		{
					
			//String conversion
			str1 = "yes";
					
		}//End of true
		
		//Parent method call and class variable addition
		return "\nMath Camp:" + super.toString()
				+ "Test Taking:\t\t" + str1 + "\n\n";
		
	}//End of toString method
	
}//End of MathCamp class