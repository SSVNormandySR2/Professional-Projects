/*
 * Vincent Latona
 */

import java.util.Scanner; //Import needed library

/*
 * This class is the main application
 */
public class Main 
{
	/*
	 * This method runs the application
	 */
	public static void main(String[] args)
	{
		int input = 0; //Initialize input variable
		Scanner scan = new Scanner(System.in); //Define input scanner
		ConcussionAssessmentSystem app = new ConcussionAssessmentSystem(); //Create app object
		System.out.println("Welcome to the Sport Concussion Assessment System\n"
				         + "=================================================\n"); //Display welcome message
		boolean complete = false; //Define sentinel for runtime
		while(!complete) //Run until quit condition
		{
			app.printMenu(); //Display menu
			input = scan.nextInt(); //Take input
			switch(input) //Switch on menu input
			{
				case 1: //Assessment case
					app.takeAssessment(); //Run assessment method
					break; //Do not fall through
				case 2:
					app.printSummaries(); //Print stored summaries
					break; //Do not fall through
				case 3: 
					app.assessRisk(); //Display risk condition
					break; //Do not fall through
				case 4:
					complete = true; //Signal sentinel
					break; //Do not fall through
				default: //Input error case
					System.out.println("Invalid input detected, please enter a number 1-4"); //Print error message
					break; //Do not fall through
			}
		}
	}
}
