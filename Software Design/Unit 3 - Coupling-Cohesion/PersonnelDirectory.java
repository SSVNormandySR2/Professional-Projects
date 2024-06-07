/*
 * Vincent Latona
 */

import java.util.Scanner; //Import scanner

/*
 * This class runs the program
 */
public class PersonnelDirectory
{
	/*
	 * This method runs the program
	 */
	public static void main(String[] args)
	{
		Personnel per = new Personnel(); //Initialize main program variable
		
		//Declare input variables
		Scanner scan = new Scanner(System.in);
		String firstN, lastN, middleN;
		int empID;
		double salary;
        int choice = -1;
        
        boolean finished = false; //Declare runtime sentinel
        
        while(!finished) //Iterate until finished
        {
        	//Print menu
        	System.out.println("Welcome to the Personnel Directory Management System");
            System.out.println("====================================================");
            System.out.println("\n\n\t 1. Add Personel");
            System.out.println("\n\t 2. Find Personel");
            System.out.println("\n\t 3. Print Names");
            System.out.println("\n\t 4. Number of Entries in the Directory");
            System.out.println("\n\t 5. Quit");
            System.out.println("\n\t Select one of the options above (1, 2, 3, 4, 5)");
            
            //Take menu input
            choice = scan.nextInt();
            scan.nextLine();

            switch(choice) //Switch on menu input
            {
            	case 1: //Add employee case
  				  	//Take first, last, middle inputs
  				  	System.out.println("Enter first name: ");
  				  	firstN = scan.nextLine();
  				  	System.out.println("Enter last name: ");
  				  	lastN = scan.nextLine();
  				  	System.out.println("Enter middle name: ");
  				  	middleN = scan.nextLine();

  				  	//Take id and salary
  				  	System.out.println("Enter employee id : ");
  				  	empID = scan.nextInt();
  				  	System.out.println("Enter base salary" );
  				  	salary = scan.nextDouble();
  				  	scan.nextLine();
  				  
  				  	per.addPersonnel(lastN, firstN, middleN, empID, salary); //Add new employee
  				  	break; //Do not fall through
  				  	
  			  	case 2: //Search case
  			  		//Take first and last inputs
  			  		System.out.println("Enter first name : ");
  			  		firstN = scan.nextLine();
  			  		System.out.println("Enter last name : ");
  			  		lastN = scan.nextLine();

  			  		per.search(firstN, lastN); //Search first and last
  			  		break; //Do not fall through
  			  		
  			  	case 3: //Name print case
  			  		System.out.println("Enter the order 0: first, middle,  last, 1: first, last, middle, 2: last, first , middle ");
  			  		int order = scan.nextInt();
  			  		if(order == 0) //First, middle, last case
  			  		{
  			  			per.printNamesFML(); //Print all names
  			  		}
  			  		else if(order == 1) //Last, middle, first case
  			  		{
  			  			per.printNamesLMF(); //Print all names
  			  		}
  			  		else if(order == 2) //Last, first, middle case
  			  		{
  			  			per.printNamesLFM(); //Print all names
  			  		}
  			  		else //Error case
  			  		{
  			  			System.out.println("Please enter an option between 0 and 2.\n"); //Print error message
  			  		}
  			  		break; //Do not fall through
  			  		
  			  case 4:
  				  System.out.println("Total Entries : " + per.getTotalObjects() + "\n"); //Print total objects
  				  break; //Do not fall through
  				  
  			  case 5: //Quit case
  				  finished = true; //Set sentinel
  				  break; //Do not fall through
  				  
  			  default: //Error case
  				  System.out.println("Please select an option between 1 and 5.\n"); //Print error message
  				  break; //Do not fall through
  		  }
        }
  }
}