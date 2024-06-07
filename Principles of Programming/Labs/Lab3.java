/*
AUTHOR: Vincent Latona
FILENAME: Lab3.java
SPECIFICATION: Final Grade Calculator
TIME SPENT: 1 hour and 15 minutes
*/

//Must import packages before declaring a class
import java.util.Scanner;

//Class must match filename
public class Lab3 
{
	
	//Program requires main method
	public static void main(String[] args)
	{
		
		//Declaration of variables, strings, and characters
		Scanner in = new Scanner(System.in);
		double finalExamGrade = 0.0;
		double midtermGrade = 0.0;
		double homeworkGrade = 0.0;
		double finalGrade = 0.0;
		char letterGrade = ' ';
		final double midtermWeight = 0.25;
		final double homeworkWeight = 0.25;
		
		//Gather user input
		System.out.println("Please enter your grade for homework (0-100): ");
		homeworkGrade = in.nextDouble();
		
		System.out.println("Please enter your grade for the midterm (0-100): ");
		midtermGrade = in.nextDouble();
		
		System.out.println("Please enter your grade for the final exam (0-200): ");
		finalExamGrade = in.nextDouble();
		
		//Correct input value and calculation of final grade
		if (homeworkGrade >= 0 && homeworkGrade <= 100 && midtermGrade >= 0 && midtermGrade <= 100 && finalExamGrade >= 0 && finalExamGrade <= 200)
		{
			
			//Calculation of final grade
			finalGrade = (((finalExamGrade / 200) * 50) + (midtermGrade * midtermWeight) + (homeworkGrade * homeworkWeight));
			
			//Passing letter grade
			if (finalGrade >= 50)
			{
				
				//Passing grade
				letterGrade = 'P';
				
			}//End of passing letter grade
			
			//Failing letter grade
			else
			{
				//Failing grade
				letterGrade = 'F';
			
			}//End of failing grade
			
				//Output of pass/fail
				if (letterGrade == 'P')
				{
					
					//Student passes
					System.out.println("Student passed the class.");
					
				}//End of pass
				
				else
				{
					
					//Student fails
					System.out.println("Student failed the class.");
					
				}//End of fail 
				
		}//End of correct input and calculation
		
		//Output for error in input value
		else
		{
		
			//Display error message
			System.out.println("Input error: Homework and Midterm grades must be between 0 and 100. Final Exam grade must be between 0 and 200.");
			
		}//End of error message
		
	}//End of main method
	
}//End of class Lab3
