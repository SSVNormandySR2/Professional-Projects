// Assignment #: 11
// Name: Vincent Latona
// Description: Assignment 11 class displays a menu of choices to a user
//      and performs the chosen task. It will keep asking a user to
//      enter the next choice until the choice of 'Q' (Quit) is entered.

import java.io.*;

public class Assignment11
 {
  public static void main (String[] args) throws IOException
   {
       char input1;
       String line = new String();

       printMenu();

       InputStreamReader isr = new InputStreamReader(System.in);
       BufferedReader stdin = new BufferedReader(isr);
       boolean setUpDoctors = false;
       PatientManagement management1 = null;
       
       //The following part is to get a valid number of available doctors from a user
       //in order to instantiate an object of PatientManagement class
       do
       {
         System.out.print("Please specify how many doctors will be available:\n");
         try
          {
           int numOfDoctors = Integer.parseInt(stdin.readLine().trim());
           
           if (numOfDoctors > 0 )
           {
               //Create a patient management object
               management1 = new PatientManagement(numOfDoctors);
               setUpDoctors = true;
           }
           else
           {
               System.out.print("Please enter a positive integer\n");
           }
          }
         catch(NumberFormatException ex)
          {
           System.out.print("Please enter a valid number\n");
          }
        } while (setUpDoctors == false);


       
       do  // will ask for user input
        {
         System.out.println("What action would you like to perform?");
         line = stdin.readLine();
         input1 = line.charAt(0);
         input1 = Character.toUpperCase(input1);

         if (line.length() == 1)
          {
           // matches one of the case statements
           switch (input1)
            {
             case 'A':   //Add a Patient
               try
                {
                 System.out.print("Please add the patient ID of a patient to add to a queue:\n");
                 int id = Integer.parseInt(stdin.readLine().trim());

                 System.out.print("Please specify the condition of the patient (High Priority, Intermediate, Delayed Care):\n");
                 String conditionLevel = stdin.readLine().trim();

                 boolean added = management1.addPatient(id, conditionLevel);
                 if (added)
                 {
                     System.out.println("The patient with id " + id + " and the condition " + conditionLevel
                                        + " was added\n");
                 }
                 else
                 {
                     System.out.println("The patient with id " + id + " and the condition " + conditionLevel
                                        + " was not added\n");
                 }

                }
               catch(NumberFormatException ex)
                {
                    System.out.print("Please enter a valid number\n");
                }
               break;
             case 'C':   //Check Out a Patient
                Patient patient1 = management1.checkOutPatient();
                    
                if (patient1 == null)
                  {
                    System.out.print("No patient was checked out\n");
                  }
                else
                  {
                    System.out.print("Patient " + patient1.toString() + " checked out\n");
                  }
                break;
             case 'L':   //List queues
                management1.printPatientQueues();
                break;
             case 'Q':   //Quit
               break;
             case 'R':  //Release Patient From its Doctor
                try
                {
                    System.out.print("Which doctor is releasing a patient? Enter its doctor number:\n");
                    int doctorNum = Integer.parseInt(stdin.readLine().trim());
                    
                    Patient releasedPatient = management1.releasePatientFromDoctorToCheckOutQueue(doctorNum);
                    if (releasedPatient == null)
                    {
                        System.out.print("No patient was released\n");
                    }
                    else
                    {
                        System.out.print("Patient " + releasedPatient.toString() + " was released for a check out\n");
                    }
                }
                catch(NumberFormatException ex)
                {
                    System.out.print("Please enter a valid number\n");
                }
               break;
             case 'S':   //Assign a Patient to a Doctor
                    Patient patient2 = management1.assignPatientToDoctor();
                    
                    if (patient2 == null)
                    {
                        System.out.print("No patient was assigned to a doctor\n");
                    }
                    else
                    {
                        System.out.print("Patient " + patient2.toString() + " was assigned to a doctor\n");
                    }
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


  /** The method printMenu displays the menu to a user**/
  public static void printMenu()
   {
     System.out.print("Choice\t\tAction\n" +
                      "------\t\t------\n" +
                      "A\t\tAdd Patient\n" +
                      "C\t\tCheck Out Patient\n" +
                      "L\t\tList Patient Queues\n" +
                      "Q\t\tQuit\n" +
                      "R\t\tRelease Patient From Doctor\n" +
                      "S\t\tAssign Patient To Doctor\n" +
                      "?\t\tDisplay Help\n\n");
  }
}