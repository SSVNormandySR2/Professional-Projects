/*-------------------------------------------------------------------------
// AUTHOR: Vincent Latona
// FILENAME: Lab7.java
// SPECIFICATION: Takes input of a builder to create rows and pyramids.
// TIME SPENT: 3 hours total
//-----------------------------------------------------------*/

//Import necessary supporting classes from packages
import java.util.Scanner;

//Class name must match filename
public class Lab7 
{
	
	//Main method needed to run program
	public static void main(String[] args)
	{
		//Variable declaration
		
		//Scanner object for input
		Scanner in = new Scanner(System.in);
		
		//String to store the name
		String builderName = "";
		
		//String to aid in the row creation
		String b = ""; 
		
		//String for character used in row
		String s = "*"; 
		
		//String for character used in pyramid
		String z = "*"; 
		
		//Variable for number of characters in row
		int n = 0; 
		
		//Variable for number of characters in bottom row of pyramid
		int p = 0; 
		
		//Prompt and input of builder name
		System.out.println("Please enter the builder name: ");
		builderName = in.nextLine();
		
		//Builder object created to be manipulated
		Builder builder = new Builder(builderName);
		
		//Display of builder name
		System.out.println("Builder name: " + builder.getName());
		
		//Prompt and input of number of characters in the row
		System.out.println("Please enter a positive integer: ");
		n = in.nextInt();
		
		//Loop for creating "="s to enclose the row of characters
		for (int i = 0; i < n; i++)
		{
			
			//Creation of row enclosers
			b = b + "="; 
			
		}//End of row loop
		
		//Method call to create row with help from the loop
		System.out.println(b + builder.makeRow(n, s) + b);
		
		//Prompt and input of number of characters in the base of the pyramid
		System.out.println("Please enter an odd integer representing the number of characters in the base of the pyramd: ");
		p = in.nextInt();
		
		//Method call to create the pyramid
		builder.makePyramid(p, z);
	
	}//End of main method

}//End of Lab7 class
