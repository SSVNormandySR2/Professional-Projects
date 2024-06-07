/*-------------------------------------------------------------------------
// FILENAME: Assignment5.java
// SPECIFICATION: this program checks the methods in class Geek, it is a test driver for class Geek
//----------------------------------------------------------------------*/

//import Scanner class
import java.util.*;

public class Assignment5 {

   public static void main (String[] args) {

      	 Scanner console = new Scanner (System.in);

      	 String choice;
	  	 char command;
       	// call the method to print the menu
		printMenu();//print the menu, a static method
		//instantiate an object of type Geek
		Geek myGeek = new Geek("Eisenstein");

		do
		{
		           // ask a user to choose a command
		           System.out.println("\nPlease enter a command or type ?");
		           choice = console.next().toLowerCase();
	               command = choice.charAt(0);

		           switch (command)
		            {
		                 case 'a'://print the name
		                      System.out.println(myGeek.getName());
		                      break;
		                 case 'b': //print number of questions asked so far
		                      System.out.println(myGeek.getNumberOfQuestions());

		                      break;
		                 case 'c': //find out if the number is even
							  System.out.print("Enter a number: ");
							  int num1 = console.nextInt();
							  if (myGeek.isEven(num1))
							  		System.out.println(num1 + " is even");
							  else
							        System.out.println(num1 + " is not even");
		                      break;
		                 case 'd': //multi concat
							  System.out.print("Enter a string: ");
							  String input = console.next();
							  System.out.print("Enter an integer: ");
							  num1 = console.nextInt();
							  System.out.println(myGeek.multiConcat(input, num1));
		                      break;
		                 case 'e': //sum the numbers between two numbers entered by user
                              System.out.print("Enter the first number: ");
							  num1 = console.nextInt();
							  System.out.print("Enter the second number: ");
							  int num2 = console.nextInt();
							  int total = myGeek.sumRange(num1, num2);
							  System.out.println("Sum of inegers "+ num1 + " and " +num2 + " is " + total);
		                      break;
		                 case 'f': //find if the numbers are sorted
                              System.out.println("Enter three integers: ");
                              int n1  = console.nextInt();
                              int n2 = console.nextInt();
                              int n3 = console.nextInt();
                              if (myGeek.sorted(n1, n2, n3))
                              		System.out.println("It is sorted!");
                              else
                              		System.out.println("Not sorted!");
		                      break;
		                 case 'g'://find out the number of a(s) in the input string
		                 	  System.out.print("Enter a string: ");
		                 	  input = console.next();
		                 	  System.out.println("The string \"" + input + "\" has " + myGeek.countA(input) +" a(s)");
                              break;

		              	 case 'h'://count the digits
		              	 		System.out.print("Enter an integer: ");
		              	 		num1 = console.nextInt();
		              	 		System.out.println("Number of digits in " + num1 + " is " + myGeek.countDigits(num1));
		              	 		break;
		              	 case 'i':
		              	 		 System.out.print("Enter a number: ");
								 num1 = console.nextInt();
								 if (myGeek.isPrime(num1))
										System.out.println(num1 + " is prime");
								 else
										System.out.println(num1 + " is not prime");
		                      break;
		              	 case '?'://print the menu
		                      printMenu();
		                      break;
		                 case 'q'://quit
		                      break;

		                 default://invalid choice
		                       System.out.println("Invalid input");

		            }

		        } while (command != 'q');

		    }  //end of the main method


		  public static void printMenu()
		   {
		    System.out.print("\nCommand Options\n"
		                   + "-----------------------------------\n"
		                   + "a: Get name\n"
		                   + "b: Num of questions asked\n"
		                   + "c: Is it even\n"
		                   + "d: Multi concat\n"
		                   + "e: Range between two integers\n"
		                   + "f: Is sorted\n"
		                   + "g: Count a\n"
		                   + "h: Count digits\n"
		                   + "i: Is it prime\n"
		                   + "?: Display\n"
		                   + "q: Quit\n\n");

		    } // end of the printMenu method


}