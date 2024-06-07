/*------------------------------------------------------------------------- 
// AUTHOR: Vincent Latona
// FILENAME: Assignment3.java
// SPECIFICATION: Options that manipulate strings that are input by users
// TIME SPENT: 1 hour
//----------------------------------------------------------------------*/
/*
1. if (score >= 95)
	{
		grade = 'A';
   	}
   	else if (score >= 85 && score < 95)
   	{
   		grade = 'B';
   	}
   	else if (score >= 75 && score < 85)
   	{
   		grade = 'C';
   	}
   	else if (score >= 65 && score < 75)
   	{
   		grade = 'D';
   	}
   	else if (score < 65)
   	{
   		grade = 'F';
   	}

2. switch (letter)
   {
   case 'A':
   		System.out.println("Excellent");
   		break;
   case 'a':
   		System.out.println("Excellent");
   		break;
   case 'B':
   		System.out.println("You can do better");
   		break;
   case 'b':
   		System.out.println("You can do better");
   		break;
   case 'C':
   		System.out.println("Try harder");
   		break;
   case 'c':
   		System.out.println("Try harder");
   		break;
   case 'D':
   		System.out.println("Try much harder");
   		break;
   case 'd':
   		System.out.println("Try much harder");
   		break;
   default:
   		System.out.println("Try another major! ");
   }
*/

//Must import java packages before the class
import java.util.Scanner;

//Class name must match filename
public class Assignment3 
{
	
	//Main method required to run a java program
	public static void main(String[] args)
	{
		
		//Variable initialization
		Scanner in = new Scanner (System.in);
		String str1 = "";
		String str2 = "";
		boolean done = false;
		String input = "";
		
		//Prompting and acceptance of strings
		System.out.println("Please enter a string: ");
		str1 = in.nextLine();
		System.out.println("Please enter another string: ");
		str2 = in.nextLine();
		
		//Display of command options
		System.out.println("Command Options:");
		System.out.println("a: Print the first character of each string.");
		System.out.println("b: Concatenate the two strings.");
		System.out.println("c: Print both strings in upper-case.");
		System.out.println("d: Find out if the lengths of the strings are equal.");
		System.out.println("e: Find out if the strings are the same.");
		System.out.println("f: Find out if which string is lexically larger.");
		System.out.println("g: Print both strings in lower-case.");
		System.out.println("q: Quit this program.");
		
		//While loop to prompt for input of options
		while (!done)
		{
			
			//Prompt for user input and acceptance of input
			System.out.println("Please choose one of the command options: ");
			input = in.next();
			
			//Conversion to lower-case to ensure the switch is executed
			input = input.toLowerCase();
			
			//Switch for execution of options
			switch (input)
			{
			
			//Case "a" for finding the first character of the strings
			case "a":
				
				//Finding the first character of the strings
				System.out.println("The first character of the first string is: "+str1.charAt(0));
				System.out.println("The first character of the first string is: "+str2.charAt(0));
				
				break;//End of case "a"
				
			//Case "b" for concatenation	
			case "b":
				
				//Concatenation
				System.out.println("The concatenation of both strings is \""+str1+str2+"\"");
				
				break;//End of case "b"
				
			//Case "c" for upper-case conversion	
			case "c":
				
				//Conversion of strings to upper-case and print
				System.out.println("The first string in upper-case letters is: "+str1.toUpperCase());
				System.out.println("The second string in upper-case letters is: "+str2.toUpperCase());
				
				break;//End of case "c"
			
			//Case "d" for string length comparison
			case "d":
				
				//True condition of string length comparison
				if (str1.length() == str2.length())
				{
					
					//Print of true condition
					System.out.println("The string lengths are the same.");
				
				}//End of true
				
				//False condition of string length comparison
				else
				{
					
					//Print of false condition
					System.out.println("The string lengths are not the same.");
				
				}//End of false
				
				break;//End of case "d"
			
			//Case "e" for string contents comparison
			case "e":
				
				//True condition of string contents
				if (str1.equals(str2))
				{
					
					//Print of same string contents
					System.out.println("The two strings are the same");
				
				}//End of true
				
				//False condition of string contents
				else
				{
					
					//Print of different string contents
					System.out.println("The two strings are different.");
				
				}//End of false
				
				break;//End of case "e"
				
			//Case "f" for unicode value string comparisons	
			case "f":
				
				//Lexically same strings
				if (str1.compareTo(str2) == 0)
				{
					
					//Print of lexically same
					System.out.println("The strings are lexically the same.");
				
				}//End of lexically same
				
				//Second string is lexically larger
				else if (str1.compareTo(str2) < 0)
				{
					
					//Print of string 2 lexically larger
					System.out.println("The second string is lexically larger.");
				
				}//End of string 2 lexically larger
				
				//First string lexically larger
				else if (str1.compareTo(str2) > 0)
				{
					
					//Print of string 1 lexically larger
					System.out.println("The first string is lexically larger.");
				
				}//End of string 1 lexically larger
				
				break;//End of case "f"
				
			//Case "g" for lower-case conversion	
			case "g":
				
				//Conversion of strings to lower-case and print
				System.out.println("The first string in lowercase letters is: "+str1.toLowerCase());
				System.out.println("The second string in lowercase letters is: "+str2.toLowerCase());
				
				break;//End of case "g"
			
			//Case "q" for termination
			case "q":
				
				//Goodbye message
				System.out.println("Goodbye!");
				
				//Conversion to "true" to terminate the loop
				done = true;
				
				break;//End of case "q"
			
			}//End of switch
			
		}//End of while loop
		
	}//End of Main method
	
}//End of Assignment3 class
