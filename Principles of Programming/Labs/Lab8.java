/*-------------------------------------------------------------------------
// AUTHOR: Vincent Latona
// FILENAME: Lab8.java
// SPECIFICATION: This program accepts user inputs and displays that information using objects and provides additional functions.
// TIME SPENT: 2 hours and 15 minutes total
//-----------------------------------------------------------*/

//Import needed packages before programming
import java.util.Scanner;

//Class name must match filename
public class Lab8 
{
	
	//Main method needed to run a java program
	public static void main(String[] args)
	{
		
		//Variable declaration
		Scanner in = new Scanner(System.in);
		String fName = "";
		String lName = "";
		String major = "";
		int points;
		int credits;
		
		//Prompt and input for student 1 information 
		System.out.println("STUDENT 1 INFORMATION");
		System.out.println("Please enter student first name: ");
		fName = in.nextLine();
		System.out.println("Please enter student last name: ");
		lName = in.nextLine();
		
		//Creation of student 1 object using Constructor 1
		Student s1 = new Student(fName, lName);
		
		//Display of Student 1 information
		System.out.println("FIRST STUDENT INFORMATION");
		System.out.println("Student name: " + s1.getFullName());
		System.out.println("Student major: " + s1.getMajor());
		System.out.println("Student points: " + s1.getGradePoints());
		System.out.println("Student credits: " + s1.getCredits());
		
		//Change of student 1's major
		s1.changeMajor("International Affairs");
		
		//Display of major changed message
		System.out.println(s1.getFullName() + " has changed their major to " + s1.getMajor());
		
		//Prompt and input for student 2 information 
		System.out.println("STUDENT 2 INFORMATION");
		System.out.println("Please enter student first name: ");
		fName = in.nextLine();
		System.out.println("Please enter student last name: ");
		lName = in.nextLine();
		System.out.println("Please enter student major: ");
		major = in.nextLine();
		System.out.println("Please enter the number of student points: ");
		points = in.nextInt();
		System.out.println("Please enter the number of student credits: ");
		credits = in.nextInt();
				
		//Creation of student 2 object using Constructor 2
		Student s2 = new Student(fName, lName, major, credits, points);
		
		//Display of Student 2 information
		System.out.println("SECOND STUDENT INFORMATION");
		System.out.println("Student name: " + s2.getFullName());
		System.out.println("Student major: " + s2.getMajor());
		System.out.println("Student points: " + s2.getGradePoints());
		System.out.println("Student credits: " + s2.getCredits());
		
		//Student Helper Functions
		System.out.println("STUDENT HELPER FUNCTIONS");
		System.out.println("Iterate from 1 till 30 with 3 steps and find sum");
		s1.loopHelper(1, 30, 3);
		System.out.println("Iterate from 5 till 28 with 2 steps and find sum");
		s1.loopHelper(5, 28, 2);
		
	}//End of main method
	
}//End of Lab8 class
