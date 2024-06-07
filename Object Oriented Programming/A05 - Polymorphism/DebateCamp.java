// Assignment #: 5
// Name: Vincent Latona
//  Time took you to complete the assignment: 47 minutes
// Description: This is the child class of SummerCamp parent, inheriting 
//				the parent methods and variables for use in DebateCamp

//This class is the child of the SummerCamp class,
//specifically for RoboticsCamp
public class DebateCamp extends SummerCamp
{
	
	//Instance variable declaration
	private double materialFee;
	private boolean groupDiscount;
	
	/**
	 This constructor provides access to the parent constructor and initializes its instance variables
	 */
	public DebateCamp(String title, String location, double rate, int weeks, double fee, String discount)
	{
		
		//Instance variable initialization and parent parameter passing
		super(title, location, rate, weeks);
		materialFee = fee;
		
		//Convert discount to lower-case
		discount = discount.toLowerCase();
		
		//Verification of discount
		if (discount.equals("yes"))
		{
			
			groupDiscount = true;
			
		}//End of true case
		else
		{
			
			groupDiscount = false;
		
		}//End of false case
		
	}//End of constructor
	
	/**
	 This method implements the computeTotalCost method of its parent class for the DebateCamp
	 */
	public void computeTotalCost()
	{
		
		//Total cost calculation
		totalCost = weeklyRate * numberOfWeeks;
		
		//Discount calculation
		if (groupDiscount == true)
		{
			
			//Discount application
			totalCost = totalCost * 0.9;
			
		}//End of discount check
		
		totalCost = totalCost + materialFee;
		
	}//End of computeTotalCost method
	
	/**
	 This method provides additional formatting for DebateCamp objects
	 */
	public String toString()
	{
		
		//String for discount state
		String str1 = "no";
		
		//Group discount state
		if(groupDiscount == true)
		{
			
			//String conversion
			str1 = "yes";
			
		}//End of true
		
		//Parent method call and class variable addition
		return "\nDebate Camp:" + super.toString() 
				+ "Material Fee:\t\t" + fmt.format(materialFee)
				+ "\nGroup Discount:\t\t" + str1 + "\n\n";
		
		
	}//End of toString method
	
}//End of DebateCamp class