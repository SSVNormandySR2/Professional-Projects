/* Name: Vincent Latona
//Title: Assignment1.java
//Author: Vincent Latona
//Description: Program calculates distances of a thrown javelin in different units of measure.
//Time Spent: 1 hour and 29 minutes.
//Date: 9/12/2019
 */
/*
//a - a (20) is post-incremented, resulting in the initial value of 20.
//b - a (21) is post-decremented, resulting in the previously incremented value of 21.
//c - The sum of the decremented value of a (20) and 1 is 21.
//d - a (20) is pre-incremented, resulting in 21.
//e - a (21) is pre-decremented, resulting in 20.
//f - The remainder of the quotient of d (17) and c (7) is 3.
//g - d (17) is divided by c (7) and the quotient is rounded to the whole number 2.
//h - a (20) is divided by d (17), then the quotient is added to b (25) and d (17) and rounded to 43. 
//i - a (20) and d (17) are added; b (25) and d (17) are added; finally, both sums are divided and the quotient is rounded to 0.
//j - The square root of a (20) multiplied by itself results in 20.0.
//k - a (20) is squared, resulting in 400.0.
//l - The larger of a (20) and b (25) is b (25).
 */

//Must import the scanner package before creating class
import java.util.Scanner;

//Class Assignment1 matches Assignment1.java file
public class Assignment1 
{
	
	//Program requires Main method to operate
	public static void main(String[] args)
	{
		
		//Declaration of variables
		Scanner in = new Scanner(System.in);
		String firstName = "";
		String lastName = "";
		String fullName = "";
		
		final double M_CM = 100.00;//Conversion rate of Centimeters per Meters
		final double M_YD = 1.093;//Conversion rate of Yards per Meter
		final double YD_FT = 3.00;//Conversion rate of Feet per Yard
		final double FT_IN = 12.00;//Conversion rate of Inches per Foot
		
		//Initialization of throws in Meters
		double throw1M = 0.0;
		double throw2M = 0.0;
		double throw3M = 0.0;
		double throw4M = 0.0;
		
		//Input of first name
		System.out.println("Please enter your first name: ");
		firstName = in.nextLine();
		
		//Input for last name
		System.out.println("Please enter your last name: ");
		lastName = in.nextLine();
		
		//Concatenation
		fullName = firstName + " " + lastName;
		
		//Input for throws in Meters
		System.out.println("Please enter the distances, in meters for " + fullName);
		
		System.out.println("Distance of throw 1, in meters: ");
		throw1M = in.nextDouble();
		
		System.out.println("Distance of throw 2, in meters: ");
		throw2M = in.nextDouble();
		
		System.out.println("Distance of throw 3, in meters: ");
		throw3M = in.nextDouble();
		
		System.out.println("Distance of throw 4, in meters: ");
		throw4M = in.nextDouble();
		
		//Operations to get units in Centimeters
		double throw1Cm = M_CM * throw1M;
		double throw2Cm = M_CM * throw2M;
		double throw3Cm = M_CM * throw3M;
		double throw4Cm = M_CM * throw4M;
		
		//Operations to get units in Yards
		double throw1Yd = M_YD * throw1M;
		double throw2Yd = M_YD * throw2M;
		double throw3Yd = M_YD * throw3M;
		double throw4Yd = M_YD * throw4M;
		
		//Operations to get units in Feet
		double throw1Ft = throw1Yd * YD_FT;
		double throw2Ft = throw2Yd * YD_FT;
		double throw3Ft = throw3Yd * YD_FT;
		double throw4Ft = throw4Yd * YD_FT;
		
		//Operations to get units in Inches
		double throw1In = throw1Ft * FT_IN;
		double throw2In = throw2Ft * FT_IN;
		double throw3In = throw3Ft * FT_IN;
		double throw4In = throw4Ft * FT_IN;
		
		//Output of each throw in each unit
		System.out.printf("%n%nCentimeters");
		System.out.printf("%nDistance of throw 1: %.2f", throw1Cm);
		System.out.printf("%nDistance of throw 2: %.2f", throw2Cm);
		System.out.printf("%nDistance of throw 3: %.2f", throw3Cm);
		System.out.printf("%nDistance of throw 4: %.2f", throw4Cm);
		
		System.out.printf("%n%nInches");
		System.out.printf("%nDistance of throw 1: %.2f", throw1In);
		System.out.printf("%nDistance of throw 2: %.2f", throw2In);
		System.out.printf("%nDistance of throw 3: %.2f", throw3In);
		System.out.printf("%nDistance of throw 4: %.2f", throw4In);
		
		System.out.printf("%n%nFeet");
		System.out.printf("%nDistance of throw 1: %.2f", throw1Ft);
		System.out.printf("%nDistance of throw 2: %.2f", throw2Ft);
		System.out.printf("%nDistance of throw 3: %.2f", throw3Ft);
		System.out.printf("%nDistance of throw 4: %.2f", throw4Ft);
		
		System.out.printf("%n%nYards");
		System.out.printf("%nDistance of throw 1: %.2f", throw1Yd);
		System.out.printf("%nDistance of throw 2: %.2f", throw2Yd);
		System.out.printf("%nDistance of throw 3: %.2f", throw3Yd);
		System.out.printf("%nDistance of throw 4: %.2f", throw4Yd);
	}//End of Main method
}//End of Assignment1 class
