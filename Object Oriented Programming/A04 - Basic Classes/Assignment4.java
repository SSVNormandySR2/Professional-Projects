// Assignment #: 4
// Name: Vincent Latona
// Description: Assignment 4 class displays a menu of choices to a user
//        and performs the chosen task. It will keep asking a user to
//        enter the next choice until the choice of 'Q' (Quit) is entered.

import java.util.*;

public class Assignment4
 {
  public static void main (String[] args)
   {
       // local variables, can be accessed anywhere from the main method
       char input1 = 'Z';
       String inputInfo;
       String clubName, university, firstName, lastName, academicLevel, numOfMembersStr;
       int numOfMembers;
       String line = new String();

       // instantiate a Club object
       Club club1 = new Club();

       printMenu();

       //Create a Scanner object to read user input
       Scanner scan = new Scanner(System.in);

       do  // will ask for user input
        {
            System.out.println("What action would you like to perform?");
            line = scan.nextLine();
            
            if (line.length() == 1)
            {
                input1 = line.charAt(0);
                input1 = Character.toUpperCase(input1);

                // matches one of the case statement
                switch (input1)
                {
                    case 'A':   //Add Club
                        System.out.print("Please enter the Club information:\n");
                        System.out.print("Enter its name:\n");
                        clubName = scan.nextLine();
                        club1.setClubName(clubName);

                        System.out.print("Enter its number of members:\n");
                        numOfMembersStr = scan.nextLine();
                        numOfMembers = Integer.parseInt(numOfMembersStr);
                        club1.setNumberOfMembers(numOfMembers);
                    
                        System.out.print("Enter its university:\n");
                        university = scan.nextLine();
                        club1.setUniversity(university);
                        
                        System.out.print("Enter its president's first name:\n");
                        firstName = scan.nextLine();
                        System.out.print("Enter its president's last name:\n");
                        lastName = scan.nextLine();
                        System.out.print("Enter its president's academic level:\n");
                        academicLevel = scan.nextLine();
                        club1.setCurrentPresident(firstName, lastName, academicLevel);
                        break;
                    case 'D':   //Display Club
                        System.out.print(club1);
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
        } while (input1 != 'Q' || line.length() != 1);
   }

  /** The method printMenu displays the menu to a user **/
  public static void printMenu()
   {
     System.out.print("Choice\t\tAction\n" +
                        "------\t\t------\n" +
                        "A\t\tAdd Club\n" +
                        "D\t\tDisplay Club\n" +
                        "Q\t\tQuit\n" +
                        "?\t\tDisplay Help\n\n");
  }
}