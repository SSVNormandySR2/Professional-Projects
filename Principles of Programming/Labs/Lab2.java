/*-------------------------------------------------------------
// AUTHOR: Vincent Latona
// FILENAME: ​Lab2.java
// SPECIFICATION: This program takes first and last name inputs and concatenates them. Strings are also compared.
// TIME SPENT: 70 minutes
//-----------------------------------------------------------*/

//The scanner package must be imported before creating the class
import java.util.Scanner;

//The class name must match the filename
public class Lab2 
{
	
	//There must be a main method to run the program
	public static void main(String[] args)
	{
		//Declaration of variables
		Scanner in = new Scanner(System.in);
		int nameLength = 0;
		String firstName = "";
		String lastName = "";
		String fullName = "";
		
		//Allow input for first names
		System.out.println("Please enter your first name: ");
		firstName = in.nextLine();
		
		//Allow input for last names
		System.out.println("Please enter your last name: ");
		lastName = in.nextLine();
		
		//Concatenation of first and last names (space included)
		fullName = firstName + " " + lastName;
		
		//Conversion of full name to upper case
		fullName = fullName.toUpperCase();
		
		//Calculation of length of the full name string length
		nameLength = fullName.length();
		
		//Output of concatenation and string length
		System.out.println("Your full name in capital letters is: " + fullName);
		System.out.println("The length of your full name is: " + nameLength);
		
		//Creation of new strings to be compared
		String title1 = new String("cse110");
		String title2 = "cse110";
		
		//If-else statements regarding use of "==" relational operator
		if (title1 == title2)
		{
			//Output if "==" works
			System.out.println("String comparison using \"==\" sign works.");
		}//End of first if decision
		else
		{
			//Output if "==" doesn't work
			System.out.println("String comparison using \"==\" sign does NOT work.");
		}//End of first else decision
			
			//If-else statements regarding use of ".equals" method
			if (title1.equals(title2))
			{
				//Output if ".equals" method works
				System.out.println("String comparison using \"equals\" method works.");
			}//End of second if decision
			else
			{
				//Output if ".equals" method doesn't work
				System.out.println("String comparison using \"equals\" method does NOT work.");
			}//End of second else decision
	}//End of Main method
}//End of Class Lab2