/*-------------------------------------------------------------------------
// AUTHOR: Vincent Latona
// FILENAME: Lab6.java
// SPECIFICATION: Prints the name and age of a person in a certain year
// TIME SPENT: 50 minutes total.
//-----------------------------------------------------------*/

//Must import packages before programming
import java.util.Scanner;

//Class name must match the filename.
public class Lab6 
{
	
	//Java programs use a main method to run.
	public static void main(String[] args)
	{
		
		//Variable declaration
		Scanner in = new Scanner(System.in);
		int birth_Year = 0;
		String firstName = "";
		String lastName = "";
		
		//Prompting for user input
		System.out.println("Please enter your first name: ");
		firstName = in.nextLine();
		System.out.println("Please enter your last name: ");
		lastName = in.nextLine();
		System.out.println("Please enter your birth year: ");
		birth_Year = in.nextInt();
		
		//Person object 
		Person person = new Person(firstName, lastName, birth_Year);
		
		//Print of results from calling the methods on the object
		System.out.println("" + person.getFirstName() + " " + person.getLastName() + " is " + person.getAge(2016) + " years old in 2016 and will be " + person.getAge(2026) + " in ten years.");
		
	}//End of main method

}//End of Lab6 class
