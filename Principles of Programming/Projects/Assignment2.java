/*-------------------------------------------------------------------------
// AUTHOR: Vincent Latona
// FILENAME: Assignment2.java
// SPECIFICATION: Rock, Paper, and Lizards simulation game
// TIME SPENT: 1 hour and 37 minutes
//1. System.out.println(myString.length());
//2. System.out.println(myString.indexOf('m'));
//3. System.out.println(myString.toUpperCase());
//4. System.out.println(myString.substring(15, 22));
//5a. True
//5b. True
//5c. False
//5d. True
//6."Je"
//----------------------------------------------------------------------*/ 

//Must import packages before programming
import java.util.Scanner;

//Class name must match the source file
public class Assignment2 
{
	
	//Main method required to run programs
	public static void main(String[] args)
	{
		
		//Declaration of strings and variables
		String player1Input = "";
		String player2Input = "";
		String rock = "rock";
		String lizards = "lizards";
		String paper = "paper";
		Scanner in = new Scanner(System.in);
		
		//Input for Player 1
		System.out.println("Player 1: Choose rock, lizards, or paper: ");
		player1Input = in.next();
		
		//Input for Player 2
		System.out.println("Player 2: Choose rock, lizards, or paper: ");
		player2Input = in.next();
		
		//Input validation for rock, paper, and lizards
		if ((rock.equalsIgnoreCase(player1Input) || lizards.equalsIgnoreCase(player1Input) || paper.equalsIgnoreCase(player1Input)) && (rock.equalsIgnoreCase(player2Input) || lizards.equalsIgnoreCase(player2Input) || paper.equalsIgnoreCase(player2Input)))
		{
			
			//All winning conditions for Player 1
			if ((rock.equalsIgnoreCase(player1Input) && lizards.equalsIgnoreCase(player2Input)) || (paper.equalsIgnoreCase(player1Input) && rock.equalsIgnoreCase(player2Input)) || (lizards.equalsIgnoreCase(player1Input) && paper.equalsIgnoreCase(player2Input)))
			{
				
				System.out.println("Player 1 wins!");
			
			}//End of Player 1 winning conditions
			
			//All winning conditions for Player 2
			else if ((rock.equalsIgnoreCase(player2Input) && lizards.equalsIgnoreCase(player1Input)) || (paper.equalsIgnoreCase(player2Input) && rock.equalsIgnoreCase(player1Input)) || (lizards.equalsIgnoreCase(player2Input) && paper.equalsIgnoreCase(player1Input)))
			{
				
				System.out.println("Player 2 wins!");
			
			}//End of Player 2 winning conditions
			
			//Tie condition
			else
			{
				
				System.out.println("It's a tie!");
			
			}//End of tie condition
			
		}//End of true input validation
		
		//Input validation false condition
		else
		{
			
			System.out.println("Invalid input!");
		
		}//End of false input validation
			
	}//End of Main method

}//End of class