// Assignment #: 5
//         Name: Vincent Latona
//  Description: The Assignment 5 class displays a menu of choices
//               (add summer camp, search summer camp title,
//               list summer camps, quit, display menu) to a user
//               and performs the chosen task. It will keep asking a user to
//               enter the next choice until the choice of 'Q' (Quit) is
//               entered.

import java.io.*;         //to use InputStreamReader and BufferedReader
import java.util.*;       //to use ArrayList

public class Assignment5
 {
  public static void main (String[] args)
   {
     char input1;
     String inputInfo = new String();
     String line = new String();
     boolean operation;

     // ArrayList object is used to store SummerCamp objects
     ArrayList<SummerCamp> summerCampList = new ArrayList<SummerCamp>();

     try
      {
       printMenu();     // print out menu

       // create a BufferedReader object to read input from a keyboard
       InputStreamReader isr = new InputStreamReader (System.in);
       BufferedReader stdin = new BufferedReader (isr);

       do
        {
         System.out.println("What action would you like to perform?");
         line = stdin.readLine().trim();
         input1 = line.charAt(0);
         input1 = Character.toUpperCase(input1);

         if (line.length() == 1)
          {
           switch (input1)
            {
             case 'A':   //Add SummerCamp
               System.out.print("Please enter some summer camp information to add:\n");
               inputInfo = stdin.readLine().trim();
               
               //Camp creation and addition to local array list
               summerCampList.add(SummerCampParser.parseStringToSummerCamp(inputInfo));
               
               break;
             case 'C':   //Compute Total Costs for all camps
            	 
            	 //Loop to calculate totals for each camp
            	 for(int i = 0; i < summerCampList.size(); i++)
            	 {
            		 
            		 summerCampList.get(i).computeTotalCost();
            		 
            	 }//End of totals computation
            	 
                System.out.print("total costs computed\n");
               break;
             case 'D':   //Search for SummerCamp
               System.out.print("Please enter a summer camp title to search:\n");
               inputInfo = stdin.readLine().trim();
               operation = false;
               
               //Loop to search for camp
                for(int i = 0; i < summerCampList.size(); i++)
                {
                	//Found condition
                	if (inputInfo.equals(summerCampList.get(i).getCampTitle()))
                	{
                		
                		operation = true;
                		break;
                		
                	}//End of found condition
                	
                }//End of search loop
                if (operation == true)
                 System.out.print("SummerCamp found\n");
                else
                 System.out.print("SummerCamp not found\n");
               break;
             case 'L':   //List SummerCamps
            	 
            	 //Empty condition
            	 if(summerCampList.isEmpty() == true)
            	 {
            		 
            		 System.out.print("no summer camp\n");
            		 
            	 }//End of empty condition
            	 
            	 //Full condition and display
            	 else
            	 {
            		 
            		 //Display loop
            		 for(int i = 0; i < summerCampList.size(); i++)
            		 {
            			 
            			 System.out.print(summerCampList.get(i).toString());
            			 
            		 }//End of display loop
            		 
            	 }//End of full condition
            			 
            	 
               break;
             case 'Q':   //Quit
               break;
             case '?':   //Display Menu
               printMenu();
               break;
             default:
               System.out.print("Unknown action\n");
               break;
            }
         }
        else
         {
           System.out.print("Unknown action\n");
          }
        } while (input1 != 'Q'); // stop the loop when Q is read
      }
     catch (IOException exception)
      {
        System.out.println("IO Exception");
      }
  }

  /** The method printMenu displays the menu to a user **/
  public static void printMenu()
   {
     System.out.print("Choice\t\tAction\n" +
                      "------\t\t------\n" +
                      "A\t\tAdd SummerCamp\n" +
                      "C\t\tCompute Total Costs\n" +
                      "D\t\tSearch for SummerCamp\n" +
                      "L\t\tList SummerCamps\n" +
                      "Q\t\tQuit\n" +
                      "?\t\tDisplay Help\n\n");
  }
}