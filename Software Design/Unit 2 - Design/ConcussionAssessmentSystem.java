/*
 * Vincent Latona
 */

import java.util.Scanner; //Import needed libraries

/*
 * This class runs the concussion assessment system
 */
public class ConcussionAssessmentSystem 
{
	private SymptomSummary[] summaries = new SymptomSummary[5]; //Define summary array
	private int currentIndex = -1; //Define array pointer
	private Scanner scan = new Scanner(System.in); //Define input scanner
	private String[] assessment = {
			"Please enter your score for Headache (none (0), mild (1-2), moderate (3-4), severe (5-6)): ",
			"Please enter your score for Pressure in Head (none (0), mild (1-2), moderate (3-4), severe (5-6)): ",
			"Please enter your score for Neck Pain none (0), mild (1-2), moderate (3-4), severe (5-6)): ",
			"Please enter your score for Nausea or Vomiting (none (0), mild (1-2), moderate (3-4), severe (5-6)): ",
			"Please enter your score for Dizziness (none (0), mild (1-2), moderate (3-4), severe (5-6)): ",
			"Please enter your score for Blurred Vision (none (0), mild (1-2), moderate (3-4), severe (5-6)): ",
			"Please enter your score for Balance Problems (none (0), mild (1-2), moderate (3-4), severe (5-6)): ",
			"Please enter your score for Sensitivity to Light (none (0), mild (1-2), moderate (3-4), severe (5-6)): ",
			"Please enter your score for Sensitivity to Noise (none (0), mild (1-2), moderate (3-4), severe (5-6)): ",
			"Please enter your score for Feeling Slowed Down (none (0), mild (1-2), moderate (3-4), severe (5-6)): ",
			"Please enter your score for Feeling Like You're in a Fog (none (0), mild (1-2), moderate (3-4), severe (5-6)): ",
			"Please enter your score for Don't Feel Right (none (0), mild (1-2), moderate (3-4), severe (5-6)): ",
			"Please enter your score for Difficulty Concentrating (none (0), mild (1-2), moderate (3-4), severe (5-6)): ",
			"Please enter your score for Difficulty Remembering (none (0), mild (1-2), moderate (3-4), severe (5-6)): ",
			"Please enter your score for Fatigue or Low Energy (none (0), mild (1-2), moderate (3-4), severe (5-6)): ",
			"Please enter your score for Confusion (none (0), mild (1-2), moderate (3-4), severe (5-6)): ",
			"Please enter your score for Drowsiness (none (0), mild (1-2), moderate (3-4), severe (5-6)): ",
			"Please enter your score for Trouble Falling Asleep (none (0), mild (1-2), moderate (3-4), severe (5-6)): ",
			"Please enter your score for More Emotional (none (0), mild (1-2), moderate (3-4), severe (5-6)): ",
			"Please enter your score for Irritability (none (0), mild (1-2), moderate (3-4), severe (5-6)): ",
			"Please enter your score for Sadness (none (0), mild (1-2), moderate (3-4), severe (5-6)): ",
			"Please enter your score for Nervous or Anxious (none (0), mild (1-2), moderate (3-4), severe (5-6)): "
	}; //Define assessment questions array
	
	/*
	 * This method prints the main menu
	 */
	public void printMenu()
	{
		//Print application menu
		System.out.println("Please select one of the following options:\n");
		System.out.println("\t1. Enter Symptoms");
		System.out.println("\t2. Display Symptoms Summary");
		System.out.println("\t3. Am I at Risk?");
		System.out.println("\t4. Exit");
	}
	
	/*
	 * This method displays the assessment questions and adds summaries to the array
	 */
	public void takeAssessment()
	{
		//Initialize summary variables
		int symptomTotal = 0;
		int symptomSeverity = 0;
		int inputScore = 0;
		
		for(String question : assessment) //Conduct assessment
		{
			System.out.print(question); //Print question
			inputScore = scan.nextInt(); //Take input
			if(inputScore > 0) //Symptom case
			{
				symptomTotal++; //Increment symptom total
				symptomSeverity += inputScore; //Add severity score
			}
		}
		System.out.println(); //Newline for menu
		
		addSummary(symptomTotal, symptomSeverity); //Add summary to array
	}
	
	/*
	 * This method generates a summary for each assessment
	 */
	public void addSummary(int symptomTotal, int symptomSeverity)
	{
		if(currentIndex == -1) //Empty array case
		{
			currentIndex++; //Increment index
			SymptomSummary summary = new SymptomSummary(symptomTotal, symptomSeverity, "No Difference"); //Define summary
			summaries[currentIndex] = summary; //Store summary
		}
		else //Comparison case
		{
			if(currentIndex == 4) //End array case
			{
				for(int a = 0; a < 4; a++) //Condense array
				{
					summaries[a] = summaries[a+1]; //Replace each element with the next
				}
			}
			else //Middle array case
			{
				currentIndex++;
			}
			
			if((symptomTotal-summaries[currentIndex-1].getSymptomTotal() > 2) | symptomSeverity > 14) //Very Different case
			{
				SymptomSummary summary = new SymptomSummary(symptomTotal, symptomSeverity, "Very Different"); //Define summary
				summaries[currentIndex] = summary; //Store summary
			}
			else if((symptomTotal-summaries[currentIndex-1].getSymptomTotal()) < 3 & symptomSeverity > 9) //Unsure case
			{
				SymptomSummary summary = new SymptomSummary(symptomTotal, symptomSeverity, "Unsure"); //Define summary
				summaries[currentIndex] = summary; //Store summary
			}
			else //No difference case
			{
				SymptomSummary summary = new SymptomSummary(symptomTotal, symptomSeverity, "No Difference"); //Define summary
				summaries[currentIndex] = summary; //Store summary
			}
		}
	}
	
	/*
	 * This method prints all stored summaries
	 */
	public void printSummaries()
	{
		if(currentIndex == -1) //No summaries case
		{
			System.out.println("Please take at least one symptoms assessment to view summaries.\n"); //Print error message
		}
		else //Print case
		{
			for(int a = 0; a < currentIndex+1; a++) //Iterate over current contents
			{
				System.out.println("Game " + (a+1)); //Print game title
				summaries[a].printSummary(); //Print summary
				System.out.println(); //Newline for next summary
			}
			System.out.println(); //Newline for menu
		}
	}
	
	/*
	 * This method prints the risk condition indicator
	 */
	public void assessRisk()
	{
		if(currentIndex < 1) //Not enough summaries case
		{
			System.out.println("Please take at least two symptoms assessments to get a risk condition indicator.\n"); //Print error message
		}
		else //Evaluate case
		{
			switch(summaries[currentIndex].getOverallRating()) //Switch on overall rating of latest game
			{
				case "No Difference": //Minimal risk case
					System.out.println("Current Risk Condition: Low Risk\n"); //Print low risk
					break; //Do not fall through
				case "Unsure":
					System.out.println("Current Risk Condition: Medium Risk\n"); //Print medium risk
					break; //Do not fall through
				case "Very Different":
					System.out.println("Current Risk Condition: High Risk\n"); //Print high risk
					break; //Do not fall through
			}
		}
	}
}
