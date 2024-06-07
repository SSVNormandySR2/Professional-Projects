// Assignment #: 5
// Name: Vincent Latona
//  Time took you to complete the assignment: 53 minutes
// Description: This class is a utility class for parsing inputs from
//				the Assignment5 class, used for creating children of
//				the SummerCamp class

//This class is a utility for the Assignment5 class
public class SummerCampParser 
{
	
	public static SummerCamp parseStringToSummerCamp(String lineToParse)
	{
		
		//Array for parsed string
		String[] list = new String[7];
		
		//String parsing and array assignment
		list = lineToParse.split(":");
		
		//Type conversion
		double rate = Double.parseDouble(list[3]);
		int weeks = Integer.parseInt(list[4]);
		
		//DebateCamp case
		if(list[0].equalsIgnoreCase("debatecamp"))
		{
			
			//Type conversion
			double mFee = Double.parseDouble(list[5]);
			
			//DebateCamp creation and return
			SummerCamp debate = new DebateCamp(list[1], list[2], rate, weeks, mFee, list[6]);
			return debate;
			
		}//End of DebateCamp case
		
		//RoboticsCamp case
		else if(list[0].equalsIgnoreCase("roboticscamp"))
		{
			
			//Type conversion
			double facilityFee = Double.parseDouble(list[5]);
			double compFee = Double.parseDouble(list[6]);
			
			//RoboticsCamp creation and return
			SummerCamp robotics = new RoboticsCamp(list[1], list[2], rate, weeks, facilityFee, compFee);
			return robotics;
			
		}//End of RoboticsCamp case
		
		//MathCamp case
		else if(list[0].equalsIgnoreCase("mathcamp"))
		{
			
			//MathCamp creation and return
			SummerCamp math = new MathCamp(list[1], list[2], rate, weeks, list[5]);
			return math;
			
		}//End of MathCamp case
		
		//Default case
		else
		{
			
			//Make math default
			SummerCamp summerCamp = new MathCamp(list[1], list[2], rate, weeks, list[5]);
			return summerCamp;
			
		}//End of default case
		
	}//End of parseStringToSummerCamp method
	
}//End of SummerCampParser class