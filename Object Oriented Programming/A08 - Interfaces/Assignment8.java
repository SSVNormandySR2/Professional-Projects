// Assignment #: 8
//         Name: Vincent Latona
//		Time took you to complete the assignment: 1 hour 8 minutes
//  	Description: The Assignment 8 class displays a menu of choices to a user
//               and performs the chosen task. It will keep asking a user to
//               enter the next choice until the choice of 'Q' (Quit) is
//               entered.

import java.io.*;

public class Assignment8
 {
  public static void main (String[] args)
   {
       char input1;
       String clubName, numOfMembersStr, university, firstName, lastName, academicLevel;
       int numOfMembers;

       boolean operation = false;
       int operation2 = 0;
       String line;
       String filename;
       
       PrintWriter outFile = null;
       BufferedReader inFile = null;
       ObjectOutputStream objectOutput = null;
       ObjectInputStream objectInput = null;

       // create a ClubManagement object. This is used throughout this class.
       ClubManagement clubManage1 = null;

       try
       {
           // print out the menu
           printMenu();

           // create a BufferedReader object to read input from a keyboard
           InputStreamReader isr = new InputStreamReader (System.in);
           BufferedReader stdin = new BufferedReader (isr);

           System.out.print("Please enter a maximum number of clubs\n");
           String maxStr = stdin.readLine().trim(); //read in the max number as a string
           int max = Integer.parseInt(maxStr);
           clubManage1 = new ClubManagement(max);

           do
           {
               System.out.print("What action would you like to perform?\n");
               line = stdin.readLine().trim();  //read a line
               input1 = line.charAt(0);
               input1 = Character.toUpperCase(input1);

               if (line.length() == 1)          //check if a user entered only one character
               {
                   switch (input1)
                   {
                       case 'A':   //Add Club
                           System.out.print("Please enter the Club information:\n");
                           System.out.print("Enter its name:\n");
                           clubName = stdin.readLine().trim();
                           System.out.print("Enter its number of members:\n");
                           numOfMembersStr = stdin.readLine().trim();
                           numOfMembers = Integer.parseInt(numOfMembersStr);
                           System.out.print("Enter its university:\n");
                           university = stdin.readLine().trim();
                           System.out.print("Enter its president first name:\n");
                           firstName = stdin.readLine().trim();
                           System.out.print("Enter its president last name:\n");
                           lastName = stdin.readLine().trim();
                           System.out.print("Enter its president academic level:\n");
                           academicLevel = stdin.readLine().trim();

                           operation = clubManage1.addClub(clubName, numOfMembers, university, firstName, lastName, academicLevel);
                           if (operation == true)
                               System.out.print("club added\n");
                           else
                               System.out.print("club not added\n");
                           break;
                       case 'C':  //Create a new club management
                           System.out.print("Please enter a new maximum number of clubs:\n");
                           maxStr = stdin.readLine().trim(); //read in the max number as a string
                           max = Integer.parseInt(maxStr);
                           clubManage1 = new ClubManagement(max);
                           break;
                       case 'D':  //Search by club
                           System.out.print("Please enter club name to search:\n");
                           clubName = stdin.readLine().trim();
                           System.out.print("Please enter club university to search:\n");
                           university = stdin.readLine().trim();
                           operation2=clubManage1.clubExists(clubName, university);

                           if (operation2 > -1)
                               System.out.print("Club: " + clubName + " at " + university + " found\n");
                           else
                               System.out.print("Club: " + clubName + " at " + university + " not found\n");
                           break;
                       case 'E':  //Search by production
                           System.out.print("Please enter the first name of a club president to search:\n");
                           firstName = stdin.readLine().trim();
                           System.out.print("Please enter the last name of a club president to search:\n");
                           lastName = stdin.readLine().trim();
                           System.out.print("Please enter the academic level of a club president to search:\n");
                           academicLevel = stdin.readLine().trim();

                           operation2=clubManage1.currentPresidentExists(firstName, lastName, academicLevel);

                           if (operation2 > -1)
                           {
                               System.out.print("President: "  + lastName + "," + firstName
                                              + "(" + academicLevel + ")" + " found\n");
                           }
                           else
                           {
                               System.out.print("President: "  + lastName + "," + firstName
                                              + "(" + academicLevel + ")" + " not found\n");
                           }
                           break;
                       case 'L':   //List clubs
                           System.out.print(clubManage1.listClubs());
                           break;
                       case 'N':  // Sort by club names
                           clubManage1.sortByClubNames();
                           System.out.print("sorted by club names\n");
                           break;
                       case 'O':  // Sort by club years
                           clubManage1.sortByMemberNumbers();
                           System.out.print("sorted by numbers of members\n");
                           break;
                       case 'P':  // Sort by Current Presidents
                           clubManage1.sortByCurrentPresidents();
                           System.out.print("sorted by current presidents\n");
                           break;
                       case 'Q':   //Quit
                           break;
                       case 'R':  //Remove by club
                           System.out.print("Please enter club name to remove:\n");
                           clubName = stdin.readLine().trim();
                           System.out.print("Please enter club university to remove:\n");
                           university = stdin.readLine().trim();
                           operation = clubManage1.removeClub(clubName, university);
                           if (operation == true)
                               System.out.print("Club: " + clubName + " at " + university + " removed\n");
                           else
                               System.out.print("Club: " + clubName + " at " + university + " not removed\n");

                           break;
                       case 'T':  //Close ClubManagement
                           clubManage1.closeClubManagement();
                           System.out.print("club management system closed\n");
                           break;
                       case 'U':  //Write Text to a File
                           System.out.print("Please enter a file name to write:\n");
                           filename = stdin.readLine().trim();
                           
                           //File writing
                           try
                           {
                        	   
                        	   //File Writing objects
                        	   FileWriter fw = new FileWriter(filename);
                        	   BufferedWriter bw = new BufferedWriter(fw);
                        	   outFile = new PrintWriter(bw);
                        	   
                        	   //User input for the file
                        	   System.out.print("Please enter a string to write in the file:\n");
                        	   String input = stdin.readLine().trim() + "\n";
                        	   
                        	   //File input
                        	   outFile.print(input);
                        	   
                        	   //Successful input
                        	   System.out.print(filename + " was written\n");
                        	   
                        	   //Close the file
                        	   outFile.close();
                        	   
                           }//End of error-creating lines
                           
                           //Exception to be caught
                           catch(IOException e)
                           {
                        	   
                           }//End of exception catch
                           
                           break;
                       case 'V':  //Read Text from a File
                           System.out.print("Please enter a file name to read:\n");
                           filename = stdin.readLine().trim();
                           
                           //File reading
                           try
                           {
                        	   
                        	   //File reading objects
                        	   FileReader fr = new FileReader(filename);
                        	   inFile = new BufferedReader(fr);
                        	   
                        	   //Successful file reading
                        	   System.out.print(filename + " was read\n");
                        	   
                        	   //File content display
                        	   System.out.print("The first line of the file is:\n");
                        	   System.out.print(inFile.readLine() + "\n");
                        	   
                        	   //Close the file
                        	   inFile.close();
                        	   
                           }//End of error-creating lines
                           
                           //File finding error
                           catch(FileNotFoundException e)
                           {
                        	   
                        	   System.out.print(filename + " was not found\n");
                        	   
                           }//End of file error
                           
                           //Exceptions to be caught
                           catch(IOException e)
                           {  
                        	   
                           }//End of exception catch
                           
                           break;
                   case 'W':  //Serialize ClubManagement to a File
                           System.out.print("Please enter a file name to write:\n");
                           filename = stdin.readLine().trim();
                           
                           //Serialization to file
                           try
                           {
                        	   
                        	   //Serialization to file objects
                        	   FileOutputStream outputStream = new FileOutputStream(filename);
                        	   objectOutput = new ObjectOutputStream(outputStream);
                        	   
                        	   //Serialization to file
                        	   objectOutput.writeObject(clubManage1);
                        	   
                        	   //Successful serialization
                        	   System.out.print(filename + " was written\n");
                        	   
                        	   //File close
                        	   objectOutput.close();
                        	   
                           }//End of error-creating lines
                           
                           //Non-serializable exception
                           catch(NotSerializableException e)
                           {
                        	   
                           }//End of non-serializable exception catch
                           
                           //Exceptions to be caught
                           catch(IOException e)
                           {
                        	   
                           }//End of exception catch
                           
                           break;
                       case 'X':  //Deserialize ClubManagement from a File
                           System.out.print("Please enter a file name to read:\n");
                           filename = stdin.readLine().trim();
                           
                           //Serialization from file
                           try
                           {
                        	   
                        	   //Serialzation from file objects
                        	   FileInputStream inputStream = new FileInputStream(filename);
                        	   objectInput = new ObjectInputStream(inputStream);
                        	   
                        	   //Object read and assignment
                        	   Object read = objectInput.readObject();
                        	   clubManage1 = (ClubManagement) read;
                        	   
                        	   //Successful serialization
                        	   System.out.print(filename + " was read\n");
                        	   
                        	   //File close
                        	   objectInput.close();
                        	   
                           }//End of error-creating lines
                           
                           //Class conversion error
                           catch(ClassNotFoundException e)
                           {
                        	   
                           }//End of class conversion error
                           
                           //File finding error
                           catch(FileNotFoundException e)
                           {
                        	   
                        	   System.out.print(filename + " was not found\n");
                        	   
                           }//End of file error
                           
                           //Exceptions to be caught
                           catch(IOException e)
                           {
                        	   
                           }//End of exception catch
                           
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
    catch (IOException exception)
       {
           System.out.print("IO Exception\n");
       }
   }

  /** The method printMenu displays the menu to a user **/
  public static void printMenu()
   {
     System.out.print("Choice\t\tAction\n" +
                      "------\t\t------\n" +
                      "A\t\tAdd Club\n" +
                      "C\t\tCreate ClubManagement\n" +
                      "D\t\tSearch by Club\n" +
                      "E\t\tSearch by Current President\n" +
                      "L\t\tList Clubs\n" +
                      "N\t\tSort by Club Names\n" +
                      "O\t\tSort by Club Member Numbers\n" +
                      "P\t\tSort by Current Presidents\n" +
                      "Q\t\tQuit\n" +
                      "R\t\tRemove by Club\n" +
                      "T\t\tClose ClubManagement\n" +
                      "U\t\tWrite Text to File\n" +
                      "V\t\tRead Text from File\n" +
                      "W\t\tSerialize ClubManagement to File\n" +
                      "X\t\tDeserialize ClubManagement from File\n" +
                      "?\t\tDisplay Help\n\n");
  }
}
